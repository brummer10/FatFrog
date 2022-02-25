
BLUE = "\033[1;34m"
RED =  "\033[1;31m"
NONE = "\033[0m"

SUBDIR := FatFrog


.PHONY: $(SUBDIR) libxputty  recurse

$(MAKECMDGOALS) recurse: $(SUBDIR)

clean:

$(SUBDIR): 
	@exec $(MAKE) -C $@ $(MAKECMDGOALS)

