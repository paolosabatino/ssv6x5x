ifeq ($(KBUILD_TOP),)
    ifneq ($(KBUILD_EXTMOD),)
    KBUILD_DIR := $(KBUILD_EXTMOD)
    else
    KBUILD_DIR := $(PWD)
    endif
KBUILD_TOP := $(KBUILD_DIR)/../
endif

include $(KBUILD_TOP)/config.mak


KBUILD_EXTRA_SYMBOLS += $(KBUILD_TOP)/ssvdevice/Module.symvers
KBUILD_EXTRA_SYMBOLS += $(KBUILD_TOP)/hci/Module.symvers

KMODULE_NAME=ssv6200s_core
KERN_SRCS := init.c
KERN_SRCS += dev.c
KERN_SRCS += ssv_rc.c
KERN_SRCS += ssv_ht_rc.c
KERN_SRCS += ssv_rc_minstrel.c
KERN_SRCS += ssv_rc_minstrel_ht.c
KERN_SRCS += lib.c
KERN_SRCS += ap.c
KERN_SRCS += ampdu.c
KERN_SRCS += ssv6xxx_debugfs.c
KERN_SRCS += sec_ccmp.c
KERN_SRCS += sec_tkip.c
KERN_SRCS += sec_wep.c
KERN_SRCS += wapi_sms4.c
KERN_SRCS += sec_wpi.c
KERN_SRCS += efuse.c
KERN_SRCS += p2p.c
KERN_SRCS += ssv_skb.c
ifeq ($(findstring -DCONFIG_SMARTLINK, $(ccflags-y)), -DCONFIG_SMARTLINK)
KERN_SRCS += ksmartlink.c
ifeq ($(findstring -DCONFIG_SSV_SMARTLINK, $(ccflags-y)), -DCONFIG_SSV_SMARTLINK)
KERN_SRCS += kssvsmart.c
endif
endif

ifeq ($(findstring -DSSV_SUPPORT_HAL, $(ccflags-y)), -DSSV_SUPPORT_HAL)
KERN_SRCS += hal/hal.c
KERN_SRCS += hal/ssv6051/ssv6051_mac.c
KERN_SRCS += hal/ssv6051/ssv6051_phy.c
KERN_SRCS += hal/ssv6051/ssv6051_cabrioA.c
KERN_SRCS += hal/ssv6051/ssv6051_cabrioE.c
ifeq ($(findstring -DSSV_SUPPORT_SSV6006, $(ccflags-y)), -DSSV_SUPPORT_SSV6006)
KERN_SRCS += hal/ssv6006/ssv6006_common.c
KERN_SRCS += hal/ssv6006/ssv6006_mac.c
KERN_SRCS += hal/ssv6006/ssv6006C_mac.c
KERN_SRCS += hal/ssv6006/ssv6006_phy.c
KERN_SRCS += hal/ssv6006/ssv6006_cabrioA.c
KERN_SRCS += hal/ssv6006/ssv6006_geminiA.c
KERN_SRCS += hal/ssv6006/ssv6006_turismoA.c
KERN_SRCS += hal/ssv6006/ssv6006_turismoB.c
KERN_SRCS += hal/ssv6006/ssv6006_turismoC.c
endif
endif

include $(KBUILD_TOP)/rules.mak
