obj-m += helloworldmodule.o
BUILD_DIR := build
LIB_DIR := lib

all:
	@echo "[*] Building Module"
	@mkdir -p ../$(BUILD_DIR)
	@mkdir -p ../$(LIB_DIR)
	@make -C /lib/modules/$(shell uname -r)/build M=$(PWD) modules > /dev/null 2>&1
	@mv -f *.ko ../$(BUILD_DIR)/
	@mv -f *.symvers *.mod *.mod.c *.o *.order ../$(LIB_DIR)
	@find . -name '*.cmd' -delete

clean:
	@echo "Cleaning.."
	@make -C /lib/modules/$(shell uname -r)/build M=$(PWD) clean > /dev/null 2>&1
	@rm -rf ../$(BUILD_DIR)
	@rm -rf ../$(LIB_DIR)

test:
	@dmesg -C
	@insmod ../$(BUILD_DIR)/helloworldmodule.ko
	@rmmod helloworldmodule
	@dmesg
