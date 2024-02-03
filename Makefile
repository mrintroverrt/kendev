# Main Makefile

.PHONY: all clean test helloworld charcter dynamicmodule

all:
	@$(MAKE) -C src/characterdevice
	@$(MAKE) -C src/hellowordmodule
	@$(MAKE) -C src/dynamicallocation
	@$(MAKE) -C src/readandwrite

helloworld:
	@$(MAKE) -C src/hellowordmodule
charcter:
	@$(MAKE) -C src/characterdevice
dynamicmodule:
	@$(MAKE) -C src/dynamicallocation
readandwrite:
	@$(MAKE) -C src/readandwrite
clean:
	@$(MAKE) -C src/characterdevice clean
	@$(MAKE) -C src/hellowordmodule clean
	@$(MAKE) -C src/dynamicallocation clean
	@$(MAKE) -C src/readandwrite clean

test:
	@$(MAKE) -C src/characterdevice test
	@$(MAKE) -C src/hellowordmodule test
	@$(MAKE) -C src/dynamicallocation test
	@$(MAKE) -C src/readandwrite test
