PLATFORMS = ssv6x5x

KBUILD_TOP := $(PWD)

INST_DIR = /lib/modules/$(KVERS)/misc

ifeq ($(KERNELRELEASE),)

KVERS_UNAME ?= $(shell uname -r)
KVERS_ARCH ?= $(shell arch)

KBUILD ?= $(shell readlink -f /lib/modules/$(KVERS_UNAME)/build)

ifeq (,$(KBUILD))
$(error kernel build tree not found - set KBUILD to configured kernel)
endif

#KCONFIG := $(KBUILD)/config
#ifeq (,$(wildcard $(KCONFIG)))
#$(error No .config found in $(KBUILD), set KBUILD to configured kernel)
#endif

ifneq (,$(wildcard $(KBUILD)/include/linux/version.h))
ifneq (,$(wildcard $(KBUILD)/include/generated/uapi/linux/version.h))
$(error Multiple copied of version.h found, clean build tree)
endif
endif

# Kernel Makefile doesn't always know the exact kernel version, so we
# get it from the kernel headers instead and pass it to make.
VERSION_H := $(KBUILD)/include/generated/utsrelease.h
ifeq (,$(wildcard $(VERSION_H)))
VERSION_H := $(KBUILD)/include/linux/utsrelease.h
endif
ifeq (,$(wildcard $(VERSION_H)))
VERSION_H := $(KBUILD)/include/linux/version.h
endif
ifeq (,$(wildcard $(VERSION_H)))
$(error Please run 'make modules_prepare' in $(KBUILD))
endif

KVERS := $(shell sed -ne 's/"//g;s/^\#define UTS_RELEASE //p' $(VERSION_H))

ifeq (,$(KVERS))
$(error Cannot find UTS_RELEASE in $(VERSION_H), please report)
endif

INST_DIR = /lib/modules/$(KVERS)/misc

#include $(KCONFIG)

endif

#KBUILD_TOP := /mnt/nfsroot/weiguang.ruan/o-amlogic-mr1/hardware/wifi/icomm/drivers/ssv6xxx/ssv6x5x
include $(KBUILD_TOP)/$(PLATFORMS).cfg
include $(KBUILD_TOP)/platform-config.mak

PWD := $(shell pwd)

ifeq ($(findstring -DSSV_SUPPORT_HAL, $(ccflags-y)), -DSSV_SUPPORT_HAL)
KMODULE_NAME=ssv6x5x
else
KMODULE_NAME=ssv6051
endif
EXTRA_CFLAGS := -I$(KBUILD_TOP) -I$(KBUILD_TOP)/include

DEF_PARSER_H = $(KBUILD_TOP)/include/ssv_conf_parser.h
$(shell env ccflags="$(ccflags-y)" $(KBUILD_TOP)/parser-conf.sh $(DEF_PARSER_H))

KERN_SRCS := ssvdevice/ssvdevice.c
KERN_SRCS += ssvdevice/ssv_cmd.c

KERN_SRCS += hci/ssv_hci.c

KERN_SRCS += smac/init.c
KERN_SRCS += smac/ssv_skb.c
KERN_SRCS += smac/dev.c
KERN_SRCS += smac/ssv_rc.c
KERN_SRCS += smac/ssv_ht_rc.c
KERN_SRCS += smac/ssv_rc_minstrel.c
KERN_SRCS += smac/ssv_rc_minstrel_ht.c
KERN_SRCS += smac/ap.c
KERN_SRCS += smac/ampdu.c
KERN_SRCS += smac/ssv6xxx_debugfs.c
#KERN_SRCS += smac/sec_ccmp.c
#KERN_SRCS += smac/sec_tkip.c
#KERN_SRCS += smac/sec_wep.c
#KERN_SRCS += smac/wapi_sms4.c
#KERN_SRCS += smac/sec_wpi.c
KERN_SRCS += smac/efuse.c
KERN_SRCS += smac/ssv_pm.c
KERN_SRCS += smac/ssv_skb.c
ifeq ($(findstring -DCONFIG_SMARTLINK, $(ccflags-y)), -DCONFIG_SMARTLINK)
KERN_SRCS += smac/ksmartlink.c
endif
ifeq ($(findstring -DCONFIG_SSV_SMARTLINK, $(ccflags-y)), -DCONFIG_SSV_SMARTLINK)
KERN_SRCS += smac/kssvsmart.c
endif

ifeq ($(findstring -DSSV_SUPPORT_HAL, $(ccflags-y)), -DSSV_SUPPORT_HAL)
KERN_SRCS += smac/hal/hal.c
#KERN_SRCS += smac/hal/ssv6051/ssv6051_mac.c
#KERN_SRCS += smac/hal/ssv6051/ssv6051_phy.c
#KERN_SRCS += smac/hal/ssv6051/ssv6051_cabrioA.c
#KERN_SRCS += smac/hal/ssv6051/ssv6051_cabrioE.c
ifeq ($(findstring -DSSV_SUPPORT_SSV6006, $(ccflags-y)), -DSSV_SUPPORT_SSV6006)
KERN_SRCS += smac/hal/ssv6006c/ssv6006_common.c
KERN_SRCS += smac/hal/ssv6006c/ssv6006C_mac.c
KERN_SRCS += smac/hal/ssv6006c/ssv6006_phy.c
#KERN_SRCS += smac/hal/ssv6006c/turismoC_rf_reg.c
#KERN_SRCS += smac/hal/ssv6006c/turismoC_wifi_phy_reg.c
KERN_SRCS += smac/hal/ssv6006c/ssv6006_turismoC.c
KERN_SRCS += hwif/usb/usb.c
endif
endif

KERN_SRCS += hwif/sdio/sdio.c
#KERNEL_MODULES += crypto

ifeq ($(findstring -DCONFIG_SSV_SUPPORT_AES_ASM, $(ccflags-y)), -DCONFIG_SSV_SUPPORT_AES_ASM)
KERN_SRCS += crypto/aes_glue.c
KERN_SRCS += crypto/sha1_glue.c
KERN_SRCS_S := crypto/aes-armv4.S
KERN_SRCS_S += crypto/sha1-armv4-large.S
endif


#KERN_SRCS += $(PLATFORMS)-generic-wlan.c

$(KMODULE_NAME)-y += $(KERN_SRCS_S:.S=.o)
$(KMODULE_NAME)-y += $(KERN_SRCS:.c=.o)

obj-$(CONFIG_SSV6200_CORE) += $(KMODULE_NAME).o

all: module

module:
	ARCH=arm $(MAKE) -C $(KBUILD) M=$(KBUILD_TOP)

install:
	mkdir -p -m 755 $(DESTDIR)$(INST_DIR)
	install -m 0644 $(KMODULE_NAME).ko $(DESTDIR)$(INST_DIR)
	depmod -a 

uninstall:
	rm -f $(KMODDESTDIR)/$(KMODULE_NAME).ko
    
strip:
	cp platforms/$(PLATFORMS)-wifi.cfg image/$(KMODULE_NAME)-wifi.cfg
	cp $(KMODULE_NAME).ko image/$(KMODULE_NAME).ko
	cp platforms/cli image
ifneq ($(SSV_STRIP),)
	cp $(KMODULE_NAME).ko image/$(KMODULE_NAME)_ori.ko
	$(SSV_STRIP) --strip-unneeded image/$(KMODULE_NAME).ko
	#$(SSV_STRIP) --strip-debug image/$(KMODULE_NAME).ko
endif

clean:
	ARCH=arm $(MAKE) -C $(KBUILD) M=$(KBUILD_TOP) clean

