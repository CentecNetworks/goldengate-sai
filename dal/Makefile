KERNEL_SRC ?= /lib/modules/$(shell uname -r)/build

all:
	$(MAKE) -C $(KERNEL_SRC) M=$$PWD modules

modules_install:
	$(MAKE) -C $(KERNEL_SRC) M=$$PWD modules_install

clean:
	$(MAKE) -C $(KERNEL_SRC) M=$$PWD clean
	rm -rf *.o *.mod.* *.ko *.o.p
