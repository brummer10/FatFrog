// generated from file './/FatFrog.dsp' by dsp2cc:
// Code generated with Faust 2.37.3 (https://faust.grame.fr)

#include "fatfrog_p1_table.h"
#include "fatfrog_power_neg_table.h"
#include "fatfrog_power_table.h"

namespace FatFrog {

class Dsp: public PluginLV2 {
private:
	uint32_t fSampleRate;
	double fConst0;
	double fConst3;
	double fConst6;
	double fConst8;
	double fConst11;
	double fConst13;
	FAUSTFLOAT fVslider0;
	FAUSTFLOAT	*fVslider0_;
	double fRec3[2];
	FAUSTFLOAT fVslider1;
	FAUSTFLOAT	*fVslider1_;
	double fRec5[2];
	double fConst16;
	double fConst17;
	FAUSTFLOAT fCheckbox0;
	FAUSTFLOAT	*fCheckbox0_;
	double fRec7[2];
	double fConst18;
	FAUSTFLOAT fCheckbox1;
	FAUSTFLOAT	*fCheckbox1_;
	double fRec9[2];
	double fConst21;
	double fConst22;
	double fConst24;
	double fConst26;
	double fConst28;
	double fConst29;
	double fConst30;
	double fRec11[4];
	double fConst31;
	double fConst32;
	double fConst33;
	double fRec10[3];
	double fConst34;
	double fConst35;
	double fConst37;
	double fConst38;
	double fConst39;
	double fRec8[4];
	double fConst40;
	double fConst41;
	double fConst42;
	double fRec12[2];
	double fConst44;
	double fConst46;
	double fConst47;
	double fConst48;
	double fConst49;
	double fConst50;
	double fConst51;
	double fConst53;
	double fConst54;
	double fConst55;
	double fConst56;
	double fConst57;
	double fRec6[4];
	double fConst59;
	double fConst60;
	double fConst62;
	double fConst63;
	double fConst64;
	double fConst65;
	double fConst66;
	double fConst67;
	double fConst69;
	FAUSTFLOAT fVslider2;
	FAUSTFLOAT	*fVslider2_;
	double fRec13[2];
	double fConst71;
	double fConst73;
	FAUSTFLOAT fVslider3;
	FAUSTFLOAT	*fVslider3_;
	double fRec14[2];
	double fConst75;
	double fConst77;
	FAUSTFLOAT fVslider4;
	FAUSTFLOAT	*fVslider4_;
	double fRec15[2];
	double fConst79;
	double fConst81;
	double fConst83;
	double fConst85;
	double fConst87;
	double fConst89;
	double fConst91;
	double fConst92;
	double fConst94;
	double fConst95;
	double fConst96;
	double fConst97;
	double fConst98;
	double fConst99;
	double fConst100;
	double fConst101;
	double fConst102;
	double fConst103;
	double fConst104;
	double fConst105;
	double fConst106;
	double fConst107;
	double fConst108;
	double fConst110;
	double fConst112;
	double fConst114;
	double fConst116;
	double fConst118;
	double fConst120;
	double fConst122;
	double fConst124;
	double fConst126;
	double fConst128;
	double fConst130;
	double fConst132;
	double fConst133;
	double fConst135;
	double fConst136;
	double fConst137;
	double fConst138;
	double fConst139;
	double fConst140;
	double fConst141;
	double fConst142;
	double fConst143;
	double fConst144;
	double fConst145;
	double fConst146;
	double fConst147;
	double fConst148;
	double fConst149;
	double fRec4[4];
	double fConst151;
	double fConst153;
	double fConst155;
	double fConst157;
	double fConst158;
	double fConst160;
	double fConst161;
	double fConst162;
	double fConst164;
	double fConst166;
	double fConst167;
	double fConst169;
	double fConst170;
	double fConst171;
	double fConst172;
	double fConst173;
	double fConst174;
	double fConst175;
	double fConst176;
	double fConst177;
	double fConst178;
	double fConst179;
	double fConst180;
	double fConst181;
	double fConst182;
	double fConst184;
	double fConst185;
	double fConst186;
	double fConst187;
	double fRec2[5];
	double fConst189;
	double fConst190;
	double fConst191;
	double fConst192;
	double fConst193;
	double fConst195;
	double fConst197;
	double fConst199;
	double fConst200;
	double fConst201;
	double fConst202;
	double fConst203;
	double fRec1[8];
	double fConst205;
	double fConst207;
	double fConst209;
	double fConst210;
	double fConst211;
	double fConst212;
	double fConst213;
	double fConst214;
	double fConst216;
	double fConst217;
	double fConst218;
	double fConst219;
	double fRec0[5];

	void connect(uint32_t port,void* data);
	void clear_state_f();
	void init(uint32_t sample_rate);
	void compute(int count, FAUSTFLOAT *input0, FAUSTFLOAT *output0);

	static void clear_state_f_static(PluginLV2*);
	static void init_static(uint32_t sample_rate, PluginLV2*);
	static void compute_static(int count, FAUSTFLOAT *input0, FAUSTFLOAT *output0, PluginLV2*);
	static void del_instance(PluginLV2 *p);
	static void connect_static(uint32_t port,void* data, PluginLV2 *p);
public:
	Dsp();
	~Dsp();
};



Dsp::Dsp()
	: PluginLV2() {
	version = PLUGINLV2_VERSION;
	id = "fatfrog";
	name = N_("FatFrog");
	mono_audio = compute_static;
	stereo_audio = 0;
	set_samplerate = init_static;
	activate_plugin = 0;
	connect_ports = connect_static;
	clear_state = clear_state_f_static;
	delete_instance = del_instance;
}

Dsp::~Dsp() {
}

inline void Dsp::clear_state_f()
{
	for (int l0 = 0; (l0 < 2); l0 = (l0 + 1)) fRec3[l0] = 0.0;
	for (int l1 = 0; (l1 < 2); l1 = (l1 + 1)) fRec5[l1] = 0.0;
	for (int l2 = 0; (l2 < 2); l2 = (l2 + 1)) fRec7[l2] = 0.0;
	for (int l3 = 0; (l3 < 2); l3 = (l3 + 1)) fRec9[l3] = 0.0;
	for (int l4 = 0; (l4 < 4); l4 = (l4 + 1)) fRec11[l4] = 0.0;
	for (int l5 = 0; (l5 < 3); l5 = (l5 + 1)) fRec10[l5] = 0.0;
	for (int l6 = 0; (l6 < 4); l6 = (l6 + 1)) fRec8[l6] = 0.0;
	for (int l7 = 0; (l7 < 2); l7 = (l7 + 1)) fRec12[l7] = 0.0;
	for (int l8 = 0; (l8 < 4); l8 = (l8 + 1)) fRec6[l8] = 0.0;
	for (int l9 = 0; (l9 < 2); l9 = (l9 + 1)) fRec13[l9] = 0.0;
	for (int l10 = 0; (l10 < 2); l10 = (l10 + 1)) fRec14[l10] = 0.0;
	for (int l11 = 0; (l11 < 2); l11 = (l11 + 1)) fRec15[l11] = 0.0;
	for (int l12 = 0; (l12 < 4); l12 = (l12 + 1)) fRec4[l12] = 0.0;
	for (int l13 = 0; (l13 < 5); l13 = (l13 + 1)) fRec2[l13] = 0.0;
	for (int l14 = 0; (l14 < 8); l14 = (l14 + 1)) fRec1[l14] = 0.0;
	for (int l15 = 0; (l15 < 5); l15 = (l15 + 1)) fRec0[l15] = 0.0;
}

void Dsp::clear_state_f_static(PluginLV2 *p)
{
	static_cast<Dsp*>(p)->clear_state_f();
}

inline void Dsp::init(uint32_t sample_rate)
{
	fSampleRate = sample_rate;
	fConst0 = std::min<double>(192000.0, std::max<double>(1.0, double(fSampleRate)));
	double fConst1 = (7.6956605842654503e-20 * fConst0);
	double fConst2 = ((fConst0 * ((fConst0 * ((fConst0 * (fConst1 + 3.5103312778178298e-15)) + 6.8732774111386296e-11)) + 8.3038402982682201e-07)) + 0.0050490205784081204);
	fConst3 = (0.55500000000000005 / fConst2);
	double fConst4 = (5.4148975598687601e-34 * fConst0);
	double fConst5 = ((fConst0 * ((fConst0 * ((fConst0 * ((fConst0 * ((fConst0 * ((fConst0 * (fConst4 + 5.09078733178756e-29)) + 2.3025222604676198e-25)) + 1.5019000587363801e-22)) + 7.8255134361101697e-20)) + 2.17831661090841e-17)) + 4.2337864478419199e-15)) + 1.61880500310045e-13);
	fConst6 = (0.55500000000000005 * (mydsp_faustpower3_f(fConst0) / fConst5));
	double fConst7 = (5.4147892635420098e-34 * fConst0);
	fConst8 = ((fConst0 * ((fConst0 * ((fConst0 * (fConst7 + 9.8982396822551705e-29)) + 2.2138982037106902e-25)) + 8.2706263330291999e-23)) + 3.0585292098345298e-20);
	double fConst9 = (1.8269373389389401e-19 * fConst0);
	double fConst10 = ((fConst0 * ((fConst0 * ((fConst0 * (fConst9 + 2.7124352361658701e-16)) + 8.16290535602033e-14)) + 4.6414729817426102e-12)) + 4.0015810287500304e-12);
	fConst11 = (fConst0 / fConst10);
	double fConst12 = (3.87560926163844e-19 * fConst0);
	fConst13 = ((fConst0 * ((fConst0 * (fConst12 + 4.3080090312012499e-16)) + 3.1750970560917398e-17)) + 5.3495467261266997e-19);
	double fConst14 = (8.3567458483100697e-15 * fConst0);
	double fConst15 = ((fConst0 * ((fConst0 * (fConst14 + 3.2771646352937702e-11)) + 6.3496219488757201e-09)) + 1.08092978787959e-07);
	fConst16 = (fConst0 / fConst15);
	fConst17 = (10.0 / fConst0);
	fConst18 = ((fConst0 * (fConst14 + -3.3006826444263599e-10)) + -5.0080147826549199e-09);
	double fConst19 = (4.3233611633741399e-10 * fConst0);
	double fConst20 = ((fConst0 * (fConst19 + 8.1164477410027694e-08)) + 1.6930429163543501e-06);
	fConst21 = (2.0 / fConst20);
	fConst22 = mydsp_faustpower2_f(fConst0);
	double fConst23 = (8.6467223267482797e-10 * fConst22);
	fConst24 = (0.0 - fConst23);
	double fConst25 = (2.41640879369625e-15 * fConst0);
	fConst26 = (1.0 / ((fConst0 * ((fConst0 * (fConst25 + 2.1575078515145099e-10)) + 4.6232311103882397e-06)) + 0.013759616399964999));
	double fConst27 = (7.2492263810887601e-15 * fConst0);
	fConst28 = ((fConst0 * ((fConst0 * (-2.1575078515145099e-10 - fConst27)) + 4.6232311103882397e-06)) + 0.041278849199895003);
	fConst29 = ((fConst0 * ((fConst0 * (fConst27 + -2.1575078515145099e-10)) + -4.6232311103882397e-06)) + 0.041278849199895003);
	fConst30 = ((fConst0 * ((fConst0 * (2.1575078515145099e-10 - fConst25)) + -4.6232311103882397e-06)) + 0.013759616399964999);
	fConst31 = (1.0 / fConst20);
	fConst32 = (3.3860858327087098e-06 - fConst23);
	fConst33 = ((fConst0 * (fConst19 + -8.1164477410027694e-08)) + 1.6930429163543501e-06);
	fConst34 = (4.3233611633741399e-10 * fConst22);
	fConst35 = (1.0 / fConst15);
	double fConst36 = (2.50702375449302e-14 * fConst0);
	fConst37 = ((fConst0 * ((fConst0 * (-3.2771646352937702e-11 - fConst36)) + 6.3496219488757201e-09)) + 3.2427893636387698e-07);
	fConst38 = ((fConst0 * ((fConst0 * (fConst36 + -3.2771646352937702e-11)) + -6.3496219488757201e-09)) + 3.2427893636387698e-07);
	fConst39 = ((fConst0 * ((fConst0 * (3.2771646352937702e-11 - fConst14)) + -6.3496219488757201e-09)) + 1.08092978787959e-07);
	fConst40 = ((fConst0 * (3.3006826444263599e-10 - fConst36)) + -5.0080147826549199e-09);
	fConst41 = ((fConst0 * (fConst36 + 3.3006826444263599e-10)) + 5.0080147826549199e-09);
	fConst42 = ((fConst0 * (-3.3006826444263599e-10 - fConst14)) + 5.0080147826549199e-09);
	double fConst43 = (4.9766123364011799e-11 * fConst0);
	fConst44 = (5.4040604393438301e-08 - fConst43);
	double fConst45 = (9.5469706045247205e-14 * fConst0);
	fConst46 = ((fConst0 * (-3.8878428749257203e-11 - fConst45)) + 8.4223126462355801e-10);
	fConst47 = ((fConst0 * (fConst45 + 7.2732934439061102e-11)) + -1.5891155936293501e-09);
	fConst48 = (-5.4040604393438301e-08 - fConst43);
	fConst49 = ((fConst0 * (fConst45 + -3.8878428749257203e-11)) + -8.4223126462355801e-10);
	fConst50 = ((fConst0 * (7.2732934439061102e-11 - fConst45)) + 1.5891155936293501e-09);
	fConst51 = (fConst43 + -5.4040604393438301e-08);
	double fConst52 = (3.1823235348415699e-14 * fConst0);
	fConst53 = ((fConst0 * (3.8878428749257203e-11 - fConst52)) + -8.4223126462355801e-10);
	fConst54 = ((fConst0 * (fConst52 + -7.2732934439061102e-11)) + 1.5891155936293501e-09);
	fConst55 = (fConst43 + 5.4040604393438301e-08);
	fConst56 = ((fConst0 * (fConst52 + 3.8878428749257203e-11)) + 8.4223126462355801e-10);
	fConst57 = ((fConst0 * (-7.2732934439061102e-11 - fConst52)) + -1.5891155936293501e-09);
	double fConst58 = (1.12794330933527e-13 * fConst0);
	fConst59 = ((fConst0 * (-3.1170348265446602e-10 - fConst58)) + -1.2765315859385099e-07);
	fConst60 = (fConst0 * (fConst58 + 2.55306317187702e-10));
	double fConst61 = (3.3838299280058001e-13 * fConst0);
	fConst62 = ((fConst0 * (fConst61 + 3.1170348265446602e-10)) + -1.2765315859385099e-07);
	fConst63 = (fConst0 * (-2.55306317187702e-10 - fConst61));
	fConst64 = ((fConst0 * (3.1170348265446602e-10 - fConst61)) + 1.2765315859385099e-07);
	fConst65 = (fConst0 * (fConst61 + -2.55306317187702e-10));
	fConst66 = ((fConst0 * (fConst58 + -3.1170348265446602e-10)) + 1.2765315859385099e-07);
	fConst67 = (fConst0 * (2.55306317187702e-10 - fConst58));
	double fConst68 = (7.1565690576060296e-16 * fConst0);
	fConst69 = ((fConst0 * (-1.8664355075711301e-12 - fConst68)) + 3.4042042573363099e-09);
	double fConst70 = (1.5829715839271501e-16 * fConst0);
	fConst71 = ((fConst0 * (fConst70 + 1.8543597157675099e-13)) + 8.0148764028779601e-10);
	double fConst72 = (5.5735974736788699e-16 * fConst0);
	fConst73 = ((fConst0 * (fConst72 + 8.0426630381222205e-13)) + -1.7253158597193301e-11);
	double fConst74 = (3.2529859352754699e-14 * fConst0);
	fConst75 = ((fConst0 * (-6.2434493214145894e-11 - fConst74)) + 3.8955749672774597e-08);
	double fConst76 = (2.5334533971267599e-14 * fConst0);
	fConst77 = ((fConst0 * (-3.6557559264191898e-11 - fConst76)) + 7.84234481690603e-10);
	double fConst78 = (1.5744451926733301e-16 * fConst0);
	fConst79 = ((fConst0 * (-3.8670132871364101e-13 - fConst78)) + 7.2922479210574596e-10);
	double fConst80 = (7.15656905760603e-15 * fConst0);
	fConst81 = ((fConst0 * (-1.26485665547481e-11 - fConst80)) + 7.6748038139993995e-09);
	double fConst82 = (4.0032434880433103e-15 * fConst0);
	fConst83 = (fConst0 * (-7.4292100919514196e-12 - fConst82));
	double fConst84 = (6.9373162530379703e-17 * fConst0);
	fConst85 = ((fConst0 * (fConst84 + 5.41706378172345e-14)) + 1.7253158597193301e-10);
	double fConst86 = (8.80713567369529e-17 * fConst0);
	fConst87 = (fConst0 * (fConst86 + 1.6344262202293099e-13));
	double fConst88 = (1.5718045692383299e-16 * fConst0);
	fConst89 = ((fConst0 * (fConst88 + 1.4393053537006501e-13)) + -3.6859020639458298e-11);
	double fConst90 = (7.1445662238106099e-15 * fConst0);
	fConst91 = (fConst90 + 1.62179690813617e-12);
	fConst92 = (4.70969822122743e-15 * fConst0);
	double fConst93 = (5.3567096056829898e-17 * fConst0);
	fConst94 = (3.5679531978995703e-14 - fConst93);
	fConst95 = ((fConst0 * (fConst68 + -1.8664355075711301e-12)) + -3.4042042573363099e-09);
	fConst96 = ((fConst0 * (1.8543597157675099e-13 - fConst70)) + -8.0148764028779601e-10);
	fConst97 = ((fConst0 * (8.0426630381222205e-13 - fConst72)) + 1.7253158597193301e-11);
	fConst98 = ((fConst0 * (fConst74 + -6.2434493214145894e-11)) + -3.8955749672774597e-08);
	fConst99 = ((fConst0 * (fConst76 + -3.6557559264191898e-11)) + -7.84234481690603e-10);
	fConst100 = ((fConst0 * (fConst78 + -3.8670132871364101e-13)) + -7.2922479210574596e-10);
	fConst101 = ((fConst0 * (fConst80 + -1.26485665547481e-11)) + -7.6748038139993995e-09);
	fConst102 = (fConst0 * (fConst82 + -7.4292100919514196e-12));
	fConst103 = ((fConst0 * (5.41706378172345e-14 - fConst84)) + -1.7253158597193301e-10);
	fConst104 = (fConst0 * (1.6344262202293099e-13 - fConst86));
	fConst105 = ((fConst0 * (1.4393053537006501e-13 - fConst88)) + 3.6859020639458298e-11);
	fConst106 = (1.62179690813617e-12 - fConst90);
	fConst107 = (fConst93 + 3.5679531978995703e-14);
	fConst108 = (1.03613360867003e-16 * fConst0);
	double fConst109 = (2.3855230192020102e-16 * fConst0);
	fConst110 = ((fConst0 * (1.8664355075711301e-12 - fConst109)) + -3.4042042573363099e-09);
	double fConst111 = (5.2765719464238398e-17 * fConst0);
	fConst112 = ((fConst0 * (fConst111 + -1.8543597157675099e-13)) + -8.0148764028779601e-10);
	double fConst113 = (1.8578658245596199e-16 * fConst0);
	fConst114 = ((fConst0 * (fConst113 + -8.0426630381222205e-13)) + 1.7253158597193301e-11);
	double fConst115 = (1.08432864509182e-14 * fConst0);
	fConst116 = ((fConst0 * (6.2434493214145894e-11 - fConst115)) + -3.8955749672774597e-08);
	double fConst117 = (8.4448446570891996e-15 * fConst0);
	fConst118 = ((fConst0 * (3.6557559264191898e-11 - fConst117)) + -7.84234481690603e-10);
	double fConst119 = (5.2481506422444197e-17 * fConst0);
	fConst120 = ((fConst0 * (3.8670132871364101e-13 - fConst119)) + -7.2922479210574596e-10);
	double fConst121 = (2.38552301920201e-15 * fConst0);
	fConst122 = ((fConst0 * (1.26485665547481e-11 - fConst121)) + -7.6748038139993995e-09);
	double fConst123 = (1.3344144960144399e-15 * fConst0);
	fConst124 = (fConst0 * (7.4292100919514196e-12 - fConst123));
	double fConst125 = (2.31243875101266e-17 * fConst0);
	fConst126 = ((fConst0 * (fConst125 + -5.41706378172345e-14)) + -1.7253158597193301e-10);
	double fConst127 = (2.9357118912317603e-17 * fConst0);
	fConst128 = (fConst0 * (fConst127 + -1.6344262202293099e-13));
	double fConst129 = (5.23934856412778e-17 * fConst0);
	fConst130 = ((fConst0 * (fConst129 + -1.4393053537006501e-13)) + 3.6859020639458298e-11);
	double fConst131 = (2.3815220746035399e-15 * fConst0);
	fConst132 = (fConst131 + -1.62179690813617e-12);
	fConst133 = (1.56989940707581e-15 * fConst0);
	double fConst134 = (1.7855698685609999e-17 * fConst0);
	fConst135 = (-3.5679531978995703e-14 - fConst134);
	fConst136 = ((fConst0 * (fConst109 + 1.8664355075711301e-12)) + 3.4042042573363099e-09);
	fConst137 = ((fConst0 * (-1.8543597157675099e-13 - fConst111)) + 8.0148764028779601e-10);
	fConst138 = ((fConst0 * (-8.0426630381222205e-13 - fConst113)) + -1.7253158597193301e-11);
	fConst139 = ((fConst0 * (fConst115 + 6.2434493214145894e-11)) + 3.8955749672774597e-08);
	fConst140 = ((fConst0 * (fConst117 + 3.6557559264191898e-11)) + 7.84234481690603e-10);
	fConst141 = ((fConst0 * (fConst119 + 3.8670132871364101e-13)) + 7.2922479210574596e-10);
	fConst142 = ((fConst0 * (fConst121 + 1.26485665547481e-11)) + 7.6748038139993995e-09);
	fConst143 = (fConst0 * (fConst123 + 7.4292100919514196e-12));
	fConst144 = ((fConst0 * (-5.41706378172345e-14 - fConst125)) + 1.7253158597193301e-10);
	fConst145 = (fConst0 * (-1.6344262202293099e-13 - fConst127));
	fConst146 = ((fConst0 * (-1.4393053537006501e-13 - fConst129)) + -3.6859020639458298e-11);
	fConst147 = (-1.62179690813617e-12 - fConst131);
	fConst148 = (fConst134 + -3.5679531978995703e-14);
	fConst149 = (3.4537786955667801e-17 * fConst0);
	double fConst150 = (8.9449810508017302e-12 * fConst0);
	fConst151 = (-3.3983329762128697e-08 - fConst150);
	double fConst152 = (4.06590047763715e-10 * fConst0);
	fConst153 = (-1.5446968073694899e-06 - fConst152);
	double fConst154 = (3.4816618551582099e-13 * fConst0);
	fConst155 = (fConst0 * (-1.4952665095336601e-09 - fConst154));
	double fConst156 = (7.6596560813480602e-15 * fConst0);
	fConst157 = ((fConst0 * (-3.9776617864203397e-11 - fConst156)) + -3.3272508000303997e-08);
	fConst158 = (fConst0 * (fConst156 + 3.2895863209740602e-11));
	double fConst159 = (9.9908557582800805e-15 * fConst0);
	fConst160 = ((fConst0 * (-2.0642263963388599e-11 - fConst159)) + -7.1082176182467603e-09);
	fConst161 = (fConst150 + -3.3983329762128697e-08);
	fConst162 = (fConst152 + -1.5446968073694899e-06);
	double fConst163 = (1.0444985565474599e-12 * fConst0);
	fConst164 = (fConst0 * (fConst163 + 1.4952665095336601e-09));
	double fConst165 = (2.2978968244044199e-14 * fConst0);
	fConst166 = ((fConst0 * (fConst165 + 3.9776617864203397e-11)) + -3.3272508000303997e-08);
	fConst167 = (fConst0 * (-3.2895863209740602e-11 - fConst165));
	double fConst168 = (2.9972567274840202e-14 * fConst0);
	fConst169 = ((fConst0 * (fConst168 + 2.0642263963388599e-11)) + -7.1082176182467603e-09);
	fConst170 = (fConst150 + 3.3983329762128697e-08);
	fConst171 = (fConst152 + 1.5446968073694899e-06);
	fConst172 = (fConst0 * (1.4952665095336601e-09 - fConst163));
	fConst173 = ((fConst0 * (3.9776617864203397e-11 - fConst165)) + 3.3272508000303997e-08);
	fConst174 = (fConst0 * (fConst165 + -3.2895863209740602e-11));
	fConst175 = ((fConst0 * (2.0642263963388599e-11 - fConst168)) + 7.1082176182467603e-09);
	fConst176 = (3.3983329762128697e-08 - fConst150);
	fConst177 = (1.5446968073694899e-06 - fConst152);
	fConst178 = (fConst0 * (fConst154 + -1.4952665095336601e-09));
	fConst179 = ((fConst0 * (fConst156 + -3.9776617864203397e-11)) + 3.3272508000303997e-08);
	fConst180 = (fConst0 * (3.2895863209740602e-11 - fConst156));
	fConst181 = ((fConst0 * (fConst159 + -2.0642263963388599e-11)) + 7.1082176182467603e-09);
	fConst182 = (1.0 / fConst10);
	double fConst183 = (7.3077493557557401e-19 * fConst0);
	fConst184 = ((fConst0 * ((fConst22 * (-5.4248704723317303e-16 - fConst183)) + 9.2829459634852301e-12)) + 1.6006324115000099e-11);
	fConst185 = ((fConst22 * ((1.0961624033633601e-18 * fConst22) + -1.63258107120407e-13)) + 2.40094861725002e-11);
	fConst186 = ((fConst0 * ((fConst22 * (5.4248704723317303e-16 - fConst183)) + -9.2829459634852301e-12)) + 1.6006324115000099e-11);
	fConst187 = ((fConst0 * ((fConst0 * ((fConst0 * (fConst9 + -2.7124352361658701e-16)) + 8.16290535602033e-14)) + -4.6414729817426102e-12)) + 4.0015810287500304e-12);
	double fConst188 = (1.5502437046553801e-18 * fConst0);
	fConst189 = ((fConst22 * (-8.6160180624025097e-16 - fConst188)) + 1.0699093452253399e-18);
	fConst190 = (fConst0 * ((2.32536555698307e-18 * fConst22) + -6.3501941121834698e-17));
	fConst191 = ((fConst22 * (8.6160180624025097e-16 - fConst188)) + -1.0699093452253399e-18);
	fConst192 = ((fConst0 * ((fConst0 * (fConst12 + -4.3080090312012499e-16)) + 3.1750970560917398e-17)) + -5.3495467261266997e-19);
	fConst193 = (1.0 / fConst5);
	double fConst194 = (3.7904282919081303e-33 * fConst0);
	fConst195 = ((fConst0 * ((fConst0 * ((fConst0 * ((fConst0 * ((fConst0 * ((fConst0 * (-2.5453936658937802e-28 - fConst194)) + -6.9075667814028503e-25)) + -1.5019000587363801e-22)) + 7.8255134361101697e-20)) + 6.5349498327252395e-17)) + 2.1168932239209599e-14)) + 1.1331635021703101e-12);
	double fConst196 = (1.13712848757244e-32 * fConst0);
	fConst197 = ((fConst0 * ((fConst0 * ((fConst0 * ((fConst0 * ((fConst0 * ((fConst0 * (fConst196 + 4.5817085986088096e-28)) + 2.3025222604676198e-25)) + -4.5057001762091297e-22)) + -2.3476540308330498e-19)) + 2.17831661090841e-17)) + 3.8104078030577297e-14)) + 3.3994905065109401e-12);
	double fConst198 = (1.8952141459540699e-32 * fConst0);
	fConst199 = ((fConst0 * ((fConst0 * ((fConst0 * ((fConst0 * ((fConst0 * ((fConst0 * (-2.5453936658937802e-28 - fConst198)) + 1.1512611302338101e-24)) + 4.5057001762091297e-22)) + -2.3476540308330498e-19)) + -1.08915830545421e-16)) + 2.1168932239209599e-14)) + 5.6658175108515603e-12);
	fConst200 = ((fConst0 * ((fConst0 * ((fConst0 * ((fConst0 * ((fConst0 * ((fConst0 * (fConst198 + -2.5453936658937802e-28)) + -1.1512611302338101e-24)) + 4.5057001762091297e-22)) + 2.3476540308330498e-19)) + -1.08915830545421e-16)) + -2.1168932239209599e-14)) + 5.6658175108515603e-12);
	fConst201 = ((fConst0 * ((fConst0 * ((fConst0 * ((fConst0 * ((fConst0 * ((fConst0 * (4.5817085986088096e-28 - fConst196)) + -2.3025222604676198e-25)) + -4.5057001762091297e-22)) + 2.3476540308330498e-19)) + 2.17831661090841e-17)) + -3.8104078030577297e-14)) + 3.3994905065109401e-12);
	fConst202 = ((fConst0 * ((fConst0 * ((fConst0 * ((fConst0 * ((fConst0 * ((fConst0 * (fConst194 + -2.5453936658937802e-28)) + 6.9075667814028503e-25)) + -1.5019000587363801e-22)) + -7.8255134361101697e-20)) + 6.5349498327252395e-17)) + -2.1168932239209599e-14)) + 1.1331635021703101e-12);
	fConst203 = ((fConst0 * ((fConst0 * ((fConst0 * ((fConst0 * ((fConst0 * ((fConst0 * (5.09078733178756e-29 - fConst4)) + -2.3025222604676198e-25)) + 1.5019000587363801e-22)) + -7.8255134361101697e-20)) + 2.17831661090841e-17)) + -4.2337864478419199e-15)) + 1.61880500310045e-13);
	double fConst204 = (3.7903524844794103e-33 * fConst0);
	fConst205 = ((fConst0 * ((fConst0 * ((fConst0 * (-4.9491198411275899e-28 - fConst204)) + -6.6416946111320803e-25)) + -8.2706263330291999e-23)) + 3.0585292098345298e-20);
	double fConst206 = (1.13710574534382e-32 * fConst0);
	fConst207 = ((fConst0 * ((fConst0 * ((fConst0 * (fConst206 + 8.9084157140296594e-28)) + 2.2138982037106902e-25)) + -2.4811878999087601e-22)) + -9.1755876295036001e-20);
	double fConst208 = (1.8951762422397001e-32 * fConst0);
	fConst209 = ((fConst0 * ((fConst0 * ((fConst0 * (-4.9491198411275899e-28 - fConst208)) + 1.10694910185535e-24)) + 2.4811878999087601e-22)) + -9.1755876295036001e-20);
	fConst210 = ((fConst0 * ((fConst0 * ((fConst0 * (fConst208 + -4.9491198411275899e-28)) + -1.10694910185535e-24)) + 2.4811878999087601e-22)) + 9.1755876295036001e-20);
	fConst211 = ((fConst0 * ((fConst0 * ((fConst0 * (8.9084157140296594e-28 - fConst206)) + -2.2138982037106902e-25)) + -2.4811878999087601e-22)) + 9.1755876295036001e-20);
	fConst212 = ((fConst0 * ((fConst0 * ((fConst0 * (fConst204 + -4.9491198411275899e-28)) + 6.6416946111320803e-25)) + -8.2706263330291999e-23)) + -3.0585292098345298e-20);
	fConst213 = ((fConst0 * ((fConst0 * ((fConst0 * (9.8982396822551705e-29 - fConst7)) + -2.2138982037106902e-25)) + 8.2706263330291999e-23)) + -3.0585292098345298e-20);
	fConst214 = (1.0 / fConst2);
	double fConst215 = (3.0782642337061801e-19 * fConst0);
	fConst216 = ((fConst0 * ((fConst22 * (-7.0206625556356597e-15 - fConst215)) + 1.66076805965364e-06)) + 0.020196082313632499);
	fConst217 = ((fConst22 * ((4.6173963505592699e-19 * fConst22) + -1.3746554822277301e-10)) + 0.0302941234704487);
	fConst218 = ((fConst0 * ((fConst22 * (7.0206625556356597e-15 - fConst215)) + -1.66076805965364e-06)) + 0.020196082313632499);
	fConst219 = ((fConst0 * ((fConst0 * ((fConst0 * (fConst1 + -3.5103312778178298e-15)) + 6.8732774111386296e-11)) + -8.3038402982682201e-07)) + 0.0050490205784081204);
	clear_state_f();
}

void Dsp::init_static(uint32_t sample_rate, PluginLV2 *p)
{
	static_cast<Dsp*>(p)->init(sample_rate);
}

void always_inline Dsp::compute(int count, FAUSTFLOAT *input0, FAUSTFLOAT *output0)
{
#define fVslider0 (*fVslider0_)
#define fVslider1 (*fVslider1_)
#define fCheckbox0 (*fCheckbox0_)
#define fCheckbox1 (*fCheckbox1_)
#define fVslider2 (*fVslider2_)
#define fVslider3 (*fVslider3_)
#define fVslider4 (*fVslider4_)
	double fSlow0 = (0.00036676987543879196 * (std::exp((3.0 * double(fVslider0))) + -1.0));
	double fSlow1 = (0.00036676987543879196 * (std::exp((3.0 * double(fVslider1))) + -1.0));
	double fSlow2 = double(fCheckbox0);
	double fSlow3 = (1.0 - double(fCheckbox1));
	double fSlow4 = (1.0 - fSlow2);
	double fSlow5 = (0.0070000000000000062 * double(fVslider2));
	double fSlow6 = (6.3889997725521416e-06 * (std::exp((7.0 * double(fVslider3))) + -1.0));
	double fSlow7 = (0.0070000000000000062 * double(fVslider4));
	for (int i0 = 0; (i0 < count); i0 = (i0 + 1)) {
		fRec3[0] = (fSlow0 + (0.99299999999999999 * fRec3[1]));
		fRec5[0] = (fSlow1 + (0.99299999999999999 * fRec5[1]));
		double fTemp0 = (fConst17 + fRec7[1]);
		double fTemp1 = (fRec7[1] - fConst17);
		double fThen1 = ((fTemp1 > fSlow2) ? fTemp1 : fSlow2);
		fRec7[0] = ((fTemp0 < fSlow2) ? fTemp0 : fThen1);
		double fTemp2 = (1.0 - fRec7[0]);
		double fTemp3 = double(input0[i0]);
		double fTemp4 = (fConst17 + fRec9[1]);
		double fTemp5 = (fRec9[1] - fConst17);
		double fThen3 = ((fTemp5 > fSlow3) ? fTemp5 : fSlow3);
		fRec9[0] = ((fTemp4 < fSlow3) ? fTemp4 : fThen3);
		double fTemp6 = (1.0 - fRec9[0]);
		fRec11[0] = ((fTemp3 * fTemp6) - (fConst26 * (((fConst28 * fRec11[1]) + (fConst29 * fRec11[2])) + (fConst30 * fRec11[3]))));
		fRec10[0] = ((fConst26 * ((((0.013759616399964999 * fRec11[0]) + (0.041278849199895003 * fRec11[1])) + (0.041278849199895003 * fRec11[2])) + (0.013759616399964999 * fRec11[3]))) - (fConst31 * ((fConst32 * fRec10[1]) + (fConst33 * fRec10[2]))));
		double fTemp7 = ((fTemp3 * fRec9[0]) + (fConst21 * (fTemp6 * (((fConst24 * fRec10[1]) + (fConst34 * fRec10[0])) + (fConst34 * fRec10[2])))));
		fRec8[0] = ((1.5 * (fTemp2 * fTemp7)) - (fConst35 * (((fConst37 * fRec8[1]) + (fConst38 * fRec8[2])) + (fConst39 * fRec8[3]))));
		double fTemp8 = (fConst17 + fRec12[1]);
		double fTemp9 = (fRec12[1] - fConst17);
		double fThen5 = ((fTemp9 > fSlow4) ? fTemp9 : fSlow4);
		fRec12[0] = ((fTemp8 < fSlow4) ? fTemp8 : fThen5);
		double fTemp10 = ((fConst0 * (fConst55 + (fRec5[0] * (fConst56 + (fConst57 * fRec5[0]))))) + 1.16799996131758e-06);
		fRec6[0] = ((((fConst16 * (fTemp2 * ((((fConst18 * fRec8[0]) + (fConst40 * fRec8[1])) + (fConst41 * fRec8[2])) + (fConst42 * fRec8[3])))) + (1.5 * (fRec7[0] * fTemp7))) * (fRec12[0] + (4.0 * mydsp_faustpower2_f((1.0 - fRec12[0]))))) - ((((fRec6[1] * ((fConst0 * (fConst44 + (fRec5[0] * (fConst46 + (fConst47 * fRec5[0]))))) + 3.5039998839527299e-06)) + (fRec6[2] * ((fConst0 * (fConst48 + (fRec5[0] * (fConst49 + (fConst50 * fRec5[0]))))) + 3.5039998839527299e-06))) + (fRec6[3] * ((fConst0 * (fConst51 + (fRec5[0] * (fConst53 + (fConst54 * fRec5[0]))))) + 1.16799996131758e-06))) / fTemp10));
		fRec13[0] = (fSlow5 + (0.99299999999999999 * fRec13[1]));
		fRec14[0] = (fSlow6 + (0.99299999999999999 * fRec14[1]));
		fRec15[0] = (fSlow7 + (0.99299999999999999 * fRec15[1]));
		double fTemp11 = (((fConst0 * (fConst136 + (fRec13[0] * (fConst137 + (fConst138 * fRec13[0]))))) + ((fRec14[0] * ((fConst0 * (fConst139 + (fConst140 * fRec13[0]))) + 8.1015958852335004e-07)) + (fRec15[0] * ((fConst0 * (fConst141 + (((fRec14[0] * (fConst142 + (fConst143 * fRec13[0]))) + (fRec13[0] * (fConst144 + (fConst145 * fRec13[0])))) + (fRec15[0] * (fConst146 + (fConst0 * ((fRec14[0] * (fConst147 + (fConst0 * (0.0 - (1.56989940707581e-15 * fRec13[0]))))) + (fRec13[0] * (fConst148 + (fConst149 * fRec13[0])))))))))) + 1.78235109475137e-07)))) + 8.2798309947086397e-07);
		fRec4[0] = (double(fatfrogclip(double((fConst0 * ((fRec5[0] * ((((fRec6[0] * (fConst59 + (fConst60 * fRec5[0]))) + (fRec6[1] * (fConst62 + (fConst63 * fRec5[0])))) + (fRec6[2] * (fConst64 + (fConst65 * fRec5[0])))) + (fRec6[3] * (fConst66 + (fConst67 * fRec5[0]))))) / fTemp10))))) - ((((fRec4[1] * (((fConst0 * (fConst69 + (fRec13[0] * (fConst71 + (fConst73 * fRec13[0]))))) + ((fRec14[0] * ((fConst0 * (fConst75 + (fConst77 * fRec13[0]))) + 2.43047876557005e-06)) + (fRec15[0] * ((fConst0 * (fConst79 + (((fRec14[0] * (fConst81 + (fConst83 * fRec13[0]))) + (fRec13[0] * (fConst85 + (fConst87 * fRec13[0])))) + (fRec15[0] * (fConst89 + (fConst0 * ((fRec14[0] * (fConst91 + (fConst92 * fRec13[0]))) + (fRec13[0] * (fConst94 + (fConst0 * (0.0 - (1.03613360867003e-16 * fRec13[0])))))))))))) + 5.3470532842541096e-07)))) + 2.4839492984125901e-06)) + (fRec4[2] * (((fConst0 * (fConst95 + (fRec13[0] * (fConst96 + (fConst97 * fRec13[0]))))) + ((fRec14[0] * ((fConst0 * (fConst98 + (fConst99 * fRec13[0]))) + 2.43047876557005e-06)) + (fRec15[0] * ((fConst0 * (fConst100 + (((fRec14[0] * (fConst101 + (fConst102 * fRec13[0]))) + (fRec13[0] * (fConst103 + (fConst104 * fRec13[0])))) + (fRec15[0] * (fConst105 + (fConst0 * ((fRec14[0] * (fConst106 + (fConst0 * (0.0 - (4.70969822122743e-15 * fRec13[0]))))) + (fRec13[0] * (fConst107 + (fConst108 * fRec13[0])))))))))) + 5.3470532842541096e-07)))) + 2.4839492984125901e-06))) + (fRec4[3] * (((fConst0 * (fConst110 + (fRec13[0] * (fConst112 + (fConst114 * fRec13[0]))))) + ((fRec14[0] * ((fConst0 * (fConst116 + (fConst118 * fRec13[0]))) + 8.1015958852335004e-07)) + (fRec15[0] * ((fConst0 * (fConst120 + (((fRec14[0] * (fConst122 + (fConst124 * fRec13[0]))) + (fRec13[0] * (fConst126 + (fConst128 * fRec13[0])))) + (fRec15[0] * (fConst130 + (fConst0 * ((fRec14[0] * (fConst132 + (fConst133 * fRec13[0]))) + (fRec13[0] * (fConst135 + (fConst0 * (0.0 - (3.4537786955667801e-17 * fRec13[0])))))))))))) + 1.78235109475137e-07)))) + 8.2798309947086397e-07))) / fTemp11));
		double fTemp12 = (9.9908557582800805e-15 * fRec13[0]);
		double fTemp13 = (4.5412980719454902e-13 * fRec14[0]);
		double fTemp14 = (1.36238942158365e-12 * fRec14[0]);
		double fTemp15 = (2.9972567274840202e-14 * fRec13[0]);
		fRec2[0] = ((fConst0 * ((fRec3[0] * ((((fRec4[0] * (fConst151 + (((fRec14[0] * (fConst153 + (fConst155 * fRec13[0]))) + (fRec13[0] * (fConst157 + (fConst158 * fRec13[0])))) + (fRec15[0] * (fConst160 + (fConst22 * (fTemp12 + (0.0 - fTemp13)))))))) + (fRec4[1] * (fConst161 + (((fRec14[0] * (fConst162 + (fConst164 * fRec13[0]))) + (fRec13[0] * (fConst166 + (fConst167 * fRec13[0])))) + (fRec15[0] * (fConst169 + (fConst22 * (fTemp14 - fTemp15)))))))) + (fRec4[2] * (fConst170 + (((fRec14[0] * (fConst171 + (fConst172 * fRec13[0]))) + (fRec13[0] * (fConst173 + (fConst174 * fRec13[0])))) + (fRec15[0] * (fConst175 + (fConst22 * (fTemp15 + (0.0 - fTemp14))))))))) + (fRec4[3] * (fConst176 + (((fRec14[0] * (fConst177 + (fConst178 * fRec13[0]))) + (fRec13[0] * (fConst179 + (fConst180 * fRec13[0])))) + (fRec15[0] * (fConst181 + (fConst22 * (fTemp13 - fTemp12))))))))) / fTemp11)) - (fConst182 * ((((fConst184 * fRec2[1]) + (fConst185 * fRec2[2])) + (fConst186 * fRec2[3])) + (fConst187 * fRec2[4]))));
		double fTemp16 = (fConst11 * (((((fConst13 * fRec2[0]) + (fConst189 * fRec2[1])) + (fConst190 * fRec2[2])) + (fConst191 * fRec2[3])) + (fConst192 * fRec2[4])));
		double fThen6 = double(fatfrog_powerclip(double(fTemp16)));
		double fElse6 = double(fatfrog_power_negclip(double(fTemp16)));
		fRec1[0] = ((0.66600000000000004 * ((fTemp16 < 0.0) ? fElse6 : fThen6)) - (fConst193 * (((((((fConst195 * fRec1[1]) + (fConst197 * fRec1[2])) + (fConst199 * fRec1[3])) + (fConst200 * fRec1[4])) + (fConst201 * fRec1[5])) + (fConst202 * fRec1[6])) + (fConst203 * fRec1[7]))));
		fRec0[0] = ((fConst6 * ((((((((fConst8 * fRec1[0]) + (fConst205 * fRec1[1])) + (fConst207 * fRec1[2])) + (fConst209 * fRec1[3])) + (fConst210 * fRec1[4])) + (fConst211 * fRec1[5])) + (fConst212 * fRec1[6])) + (fConst213 * fRec1[7]))) - (fConst214 * ((((fConst216 * fRec0[1]) + (fConst217 * fRec0[2])) + (fConst218 * fRec0[3])) + (fConst219 * fRec0[4]))));
		output0[i0] = FAUSTFLOAT((fConst3 * (((((0.0050489195995112399 * fRec0[0]) + (0.020195678398045001 * fRec0[1])) + (0.030293517597067401 * fRec0[2])) + (0.020195678398045001 * fRec0[3])) + (0.0050489195995112399 * fRec0[4]))));
		fRec3[1] = fRec3[0];
		fRec5[1] = fRec5[0];
		fRec7[1] = fRec7[0];
		fRec9[1] = fRec9[0];
		for (int j0 = 3; (j0 > 0); j0 = (j0 - 1)) {
			fRec11[j0] = fRec11[(j0 - 1)];
		}
		fRec10[2] = fRec10[1];
		fRec10[1] = fRec10[0];
		for (int j1 = 3; (j1 > 0); j1 = (j1 - 1)) {
			fRec8[j1] = fRec8[(j1 - 1)];
		}
		fRec12[1] = fRec12[0];
		for (int j2 = 3; (j2 > 0); j2 = (j2 - 1)) {
			fRec6[j2] = fRec6[(j2 - 1)];
		}
		fRec13[1] = fRec13[0];
		fRec14[1] = fRec14[0];
		fRec15[1] = fRec15[0];
		for (int j3 = 3; (j3 > 0); j3 = (j3 - 1)) {
			fRec4[j3] = fRec4[(j3 - 1)];
		}
		for (int j4 = 4; (j4 > 0); j4 = (j4 - 1)) {
			fRec2[j4] = fRec2[(j4 - 1)];
		}
		for (int j5 = 7; (j5 > 0); j5 = (j5 - 1)) {
			fRec1[j5] = fRec1[(j5 - 1)];
		}
		for (int j6 = 4; (j6 > 0); j6 = (j6 - 1)) {
			fRec0[j6] = fRec0[(j6 - 1)];
		}
	}
#undef fVslider0
#undef fVslider1
#undef fCheckbox0
#undef fCheckbox1
#undef fVslider2
#undef fVslider3
#undef fVslider4
}

void __rt_func Dsp::compute_static(int count, FAUSTFLOAT *input0, FAUSTFLOAT *output0, PluginLV2 *p)
{
	static_cast<Dsp*>(p)->compute(count, input0, output0);
}


void Dsp::connect(uint32_t port,void* data)
{
	switch ((PortIndex)port)
	{
	case BRIGHT: 
		fCheckbox0_ = (float*)data; // , 0.0, 0.0, 1.0, 1.0 
		break;
	case NOISEFILTER: 
		fCheckbox1_ = (float*)data; // , 0.0, 0.0, 1.0, 1.0 
		break;
	case BASS: 
		fVslider3_ = (float*)data; // , 0.5, 0.0, 1.0, 0.01 
		break;
	case MASTER: 
		fVslider0_ = (float*)data; // , 0.5, 0.0, 1.0, 0.01 
		break;
	case MIDDLE: 
		fVslider2_ = (float*)data; // , 0.5, 0.0, 1.0, 0.01 
		break;
	case TREBLE: 
		fVslider4_ = (float*)data; // , 0.5, 0.0, 1.0, 0.01 
		break;
	case VOLUME: 
		fVslider1_ = (float*)data; // , 0.5, 0.0, 1.0, 0.01 
		break;
	default:
		break;
	}
}

void Dsp::connect_static(uint32_t port,void* data, PluginLV2 *p)
{
	static_cast<Dsp*>(p)->connect(port, data);
}


PluginLV2 *plugin() {
	return new Dsp();
}

void Dsp::del_instance(PluginLV2 *p)
{
	delete static_cast<Dsp*>(p);
}

/*
typedef enum
{
   BASS, 
   BRIGHT, 
   MASTER, 
   MIDDLE, 
   NOISEFILTER, 
   TREBLE, 
   VOLUME, 
} PortIndex;
*/

} // end namespace FatFrog
