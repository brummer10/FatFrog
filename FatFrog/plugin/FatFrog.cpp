/*
 * Copyright (C) 2014 Guitarix project MOD project
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA 02110-1301 USA.
 * --------------------------------------------------------------------------
 */


#include <cstdlib>
#include <cmath>
#include <iostream>
#include <cstring>
#include <unistd.h>

///////////////////////// DENORMAL PROTECTION WITH SSE /////////////////

#ifdef NOSSE
#undef __SSE__
#endif

#ifdef __SSE__
#include <immintrin.h>
#ifndef _IMMINTRIN_H_INCLUDED
#include <fxsrintrin.h>
#endif
/* On Intel set FZ (Flush to Zero) and DAZ (Denormals Are Zero)
   flags to avoid costly denormals */
#ifdef __SSE3__
#ifndef _PMMINTRIN_H_INCLUDED
#include <pmmintrin.h>
#endif
#else
#ifndef _XMMINTRIN_H_INCLUDED
#include <xmmintrin.h>
#endif
#endif //__SSE3__

#endif //__SSE__

///////////////////////// MACRO SUPPORT ////////////////////////////////

#define __rt_func __attribute__((section(".rt.text")))
#define __rt_data __attribute__((section(".rt.data")))

///////////////////////// FAUST SUPPORT ////////////////////////////////

#define FAUSTFLOAT float
#ifndef N_
#define N_(String) (String)
#endif
#define max(x, y) (((x) > (y)) ? (x) : (y))
#define min(x, y) (((x) < (y)) ? (x) : (y))

#define always_inline inline __attribute__((always_inline))

#ifndef signbit
#define signbit(x) std::signbit(x)
#endif

template<class T> inline T mydsp_faustpower2_f(T x) {return (x * x);}
template<class T> inline T mydsp_faustpower3_f(T x) {return ((x * x) * x);}
template<class T> inline T mydsp_faustpower4_f(T x) {return (((x * x) * x) * x);}
template<class T> inline T mydsp_faustpower5_f(T x) {return ((((x * x) * x) * x) * x);}
template<class T> inline T mydsp_faustpower6_f(T x) {return (((((x * x) * x) * x) * x) * x);}

////////////////////////////// LOCAL INCLUDES //////////////////////////

#include "FatFrog.h"        // define struct PortIndex
#include "pluginlv2.h"   // define struct PluginLV2
#include "FatFrog.cc"    // dsp class generated by faust -> dsp2cc

////////////////////////////// PLUG-IN CLASS ///////////////////////////

namespace FatFrog {

class DenormalProtection
{
private:
#if defined (__SSE__) || (__arm64__) || defined (__aarch64__)
  uint32_t  mxcsr_mask;
  uint32_t  mxcsr;
  uint32_t  old_mxcsr;
#endif

public:
  inline void set_() {
#if defined (__arm64__) || defined (__aarch64__)
    asm volatile("mrs %0, fpcr" : "=r" (old_mxcsr));
    mxcsr = old_mxcsr;
    asm volatile("msr fpcr, %0" : : "ri" (mxcsr | 1 << 24));
#elif defined (__SSE__)
    old_mxcsr = _mm_getcsr();
    mxcsr = old_mxcsr;
    _mm_setcsr((mxcsr | _MM_DENORMALS_ZERO_MASK | _MM_FLUSH_ZERO_MASK) & mxcsr_mask);
#endif
  };
  inline void reset_() {
#if defined (__arm64__) || defined (__aarch64__)
    asm volatile("msr fpcr, %0" : : "ri" (old_mxcsr));
#elif defined (__SSE__)
    _mm_setcsr(old_mxcsr);
#endif
  };

  inline DenormalProtection()
  {
#ifdef __SSE__
    mxcsr_mask = 0xffbf; // Default MXCSR mask
    mxcsr      = 0;
#if defined(__x86_64__) || defined(_M_X64)
    uint8_t fxsave[512] __attribute__ ((aligned (16))); // Structure for storing FPU state with FXSAVE command

    memset(fxsave, 0, sizeof(fxsave));
    __builtin_ia32_fxsave(&fxsave);
    uint32_t mask = *(reinterpret_cast<uint32_t *>(&fxsave[0x1c])); // Obtain the MXCSR mask from FXSAVE structure
    if (mask != 0)
        mxcsr_mask = mask;
#endif
#endif
  };

  inline ~DenormalProtection() {};
};

class FatFrog_
{
private:
  // pointer to buffer
  float*          output;
  float*          input;
  // pointer to dsp class
  PluginLV2*      FatFrog;

  // bypass ramping
  float*          bypass;
  uint32_t        bypass_;
 
  bool            needs_ramp_down;
  bool            needs_ramp_up;
  float           ramp_down;
  float           ramp_up;
  float           ramp_up_step;
  float           ramp_down_step;
  bool            bypassed;
  DenormalProtection MXCSR;

  // private functions
  inline void run_dsp_(uint32_t n_samples);
  inline void connect_(uint32_t port,void* data);
  inline void init_dsp_(uint32_t rate);
  inline void connect_all__ports(uint32_t port, void* data);
  inline void activate_f();
  inline void clean_up();
  inline void deactivate_f();

public:
  // LV2 Descriptor
  static const LV2_Descriptor descriptor;
  // static wrapper to private functions
  static void deactivate(LV2_Handle instance);
  static void cleanup(LV2_Handle instance);
  static void run(LV2_Handle instance, uint32_t n_samples);
  static void activate(LV2_Handle instance);
  static void connect_port(LV2_Handle instance, uint32_t port, void* data);
  static LV2_Handle instantiate(const LV2_Descriptor* descriptor,
                                double rate, const char* bundle_path,
                                const LV2_Feature* const* features);
  FatFrog_();
  ~FatFrog_();
};

// constructor
FatFrog_::FatFrog_() :
  output(NULL),
  input(NULL),
  FatFrog(FatFrog::plugin()),
  bypass(0),
  bypass_(2),
  needs_ramp_down(false),
  needs_ramp_up(false),
  bypassed(false) {};

// destructor
FatFrog_::~FatFrog_()
{
  // just to be sure the plug have given free the allocated mem
  // it didn't hurd if the mem is already given free by clean_up()
  if (FatFrog->activate_plugin !=0)
    FatFrog->activate_plugin(false, FatFrog);
  // delete DSP class
  FatFrog->delete_instance(FatFrog);
};

///////////////////////// PRIVATE CLASS  FUNCTIONS /////////////////////

void FatFrog_::init_dsp_(uint32_t rate)
{
  // set values for internal ramping
  ramp_down_step = 32 * (256 * rate) / 48000; 
  ramp_up_step = ramp_down_step;
  ramp_down = ramp_down_step;
  ramp_up = 0.0;

  FatFrog->set_samplerate(rate, FatFrog); // init the DSP class
}

// connect the Ports used by the plug-in class
void FatFrog_::connect_(uint32_t port,void* data)
{
  switch ((PortIndex)port)
    {
    case EFFECTS_OUTPUT:
      output = static_cast<float*>(data);
      break;
    case EFFECTS_INPUT:
      input = static_cast<float*>(data);
      break;
    case BYPASS: 
      bypass = static_cast<float*>(data); // , 0.0, 0.0, 1.0, 1.0 
      break;
    default:
      break;
    }
}

void FatFrog_::activate_f()
{
  // allocate the internal DSP mem
  if (FatFrog->activate_plugin !=0)
    FatFrog->activate_plugin(true, FatFrog);
}

void FatFrog_::clean_up()
{
  // delete the internal DSP mem
  if (FatFrog->activate_plugin !=0)
    FatFrog->activate_plugin(false, FatFrog);
}

void FatFrog_::deactivate_f()
{
  // delete the internal DSP mem
  if (FatFrog->activate_plugin !=0)
    FatFrog->activate_plugin(false, FatFrog);
}

void FatFrog_::run_dsp_(uint32_t n_samples)
{
  if(n_samples<1) return;
  MXCSR.set_();
  FAUSTFLOAT buf[n_samples];
  // do inplace processing at default
  if (output != input)
    memcpy(output, input, n_samples*sizeof(float));
  // check if bypass is pressed
  if (bypass_ != static_cast<uint32_t>(*(bypass))) {
    bypass_ = static_cast<uint32_t>(*(bypass));
    if (!bypass_) {
      needs_ramp_down = true;
      needs_ramp_up = false;
    } else {
      needs_ramp_down = false;
      needs_ramp_up = true;
      bypassed = false;
    }
  }

  if (needs_ramp_down || needs_ramp_up) {
       memcpy(buf, input, n_samples*sizeof(float));
  }
  
  if (!bypassed) {
     FatFrog->mono_audio(static_cast<int>(n_samples), output, output, FatFrog);
  }

  // check if ramping is needed
  if (needs_ramp_down) {
    float fade = 0;
    for (uint32_t i=0; i<n_samples; i++) {
      if (ramp_down >= 0.0) {
        --ramp_down; 
      }
      fade = max(0.0,ramp_down) /ramp_down_step ;
      output[i] = output[i] * fade + buf[i] * (1.0 - fade);
    }

    if (ramp_down <= 0.0) {
      // when ramped down, clear buffer from FatFrog class
      FatFrog->clear_state(FatFrog);
      needs_ramp_down = false;
      bypassed = true;
      ramp_down = ramp_down_step;
      ramp_up = 0.0;
    } else {
      ramp_up = ramp_down;
    }

  } else if (needs_ramp_up) {
    float fade = 0;
    for (uint32_t i=0; i<n_samples; i++) {
      if (ramp_up < ramp_up_step) {
        ++ramp_up ;
      }
      fade = min(ramp_up_step,ramp_up) /ramp_up_step ;
      output[i] = output[i] * fade + buf[i] * (1.0 - fade);
    }

    if (ramp_up >= ramp_up_step) {
      needs_ramp_up = false;
      ramp_up = 0.0;
      ramp_down = ramp_down_step;
    } else {
      ramp_down = ramp_up;
    }
  }
  MXCSR.reset_();
}

void FatFrog_::connect_all__ports(uint32_t port, void* data)
{
  // connect the Ports used by the plug-in class
  connect_(port,data); 
  // connect the Ports used by the DSP class
  FatFrog->connect_ports(port,  data, FatFrog);
}

////////////////////// STATIC CLASS  FUNCTIONS  ////////////////////////

LV2_Handle 
FatFrog_::instantiate(const LV2_Descriptor* descriptor,
                            double rate, const char* bundle_path,
                            const LV2_Feature* const* features)
{
  // init the plug-in class
  FatFrog_ *self = new FatFrog_();
  if (!self) {
    return NULL;
  }

  self->init_dsp_((uint32_t)rate);

  return (LV2_Handle)self;
}

void FatFrog_::connect_port(LV2_Handle instance, 
                                   uint32_t port, void* data)
{
  // connect all ports
  static_cast<FatFrog_*>(instance)->connect_all__ports(port, data);
}

void FatFrog_::activate(LV2_Handle instance)
{
  // allocate needed mem
  static_cast<FatFrog_*>(instance)->activate_f();
}

void FatFrog_::run(LV2_Handle instance, uint32_t n_samples)
{
  // run dsp
  static_cast<FatFrog_*>(instance)->run_dsp_(n_samples);
}

void FatFrog_::deactivate(LV2_Handle instance)
{
  // free allocated mem
  static_cast<FatFrog_*>(instance)->deactivate_f();
}

void FatFrog_::cleanup(LV2_Handle instance)
{
  // well, clean up after us
  FatFrog_* self = static_cast<FatFrog_*>(instance);
  self->clean_up();
  delete self;
}

const LV2_Descriptor FatFrog_::descriptor =
{
  PLUGIN_URI "#_FatFrog_",
  FatFrog_::instantiate,
  FatFrog_::connect_port,
  FatFrog_::activate,
  FatFrog_::run,
  FatFrog_::deactivate,
  FatFrog_::cleanup,
  NULL
};


} // end namespace FatFrog

////////////////////////// LV2 SYMBOL EXPORT ///////////////////////////

extern "C"
LV2_SYMBOL_EXPORT
const LV2_Descriptor*
lv2_descriptor(uint32_t index)
{
  switch (index)
    {
    case 0:
      return &FatFrog::FatFrog_::descriptor;
    default:
      return NULL;
    }
}

///////////////////////////// FIN //////////////////////////////////////
