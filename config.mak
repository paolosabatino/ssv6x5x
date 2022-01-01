
KVERSION="`uname -r`"
#DRVPATH=/lib/modules/$(KVERSION)/kernel/drivers/net/wireless/ssv6200
DRVPATH=kernel/drivers/net/wireless/ssv6200
KCFLAG += -Werror
EXTRA_CFLAGS := -I$(KBUILD_TOP) -I$(KBUILD_TOP)/include

include $(KBUILD_TOP)/config_common.mak

#ccflags-y += -DMULTI_THREAD_ENCRYPT
ccflags-y += -DKTHREAD_BIND

ccflags-y += -DPLATFORM_FORCE_DISABLE_AMPDU_FLOW_CONTROL


###########################################################
# option to :qswitch driver between relay device and sw mac device
# Enable ->Relay device	(CHAR)
# Disable->SW MAC device(NET)

#DRV_OPT = HUW_DRV
#For HUW to define some resources
ifeq ($(DRV_OPT), HUW_DRV)
ccflags-y += -DHUW_DRV
endif
#
