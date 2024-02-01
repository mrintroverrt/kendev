# Main Makefile

.PHONY: all clean test

all:
	@$(MAKE) -C src/characterdevice
	@$(MAKE) -C src/hellowordmodule

clean:
	@$(MAKE) -C src/characterdevice clean
	@$(MAKE) -C src/hellowordmodule clean

test:
	@$(MAKE) -C src/characterdevice test
	@$(MAKE) -C src/hellowordmodule test
