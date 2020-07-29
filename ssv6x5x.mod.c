#include <linux/module.h>
#include <linux/vermagic.h>
#include <linux/compiler.h>

MODULE_INFO(vermagic, VERMAGIC_STRING);

__visible struct module __this_module
__attribute__((section(".gnu.linkonce.this_module"))) = {
	.name = KBUILD_MODNAME,
	.init = init_module,
#ifdef CONFIG_MODULE_UNLOAD
	.exit = cleanup_module,
#endif
	.arch = MODULE_ARCH_INIT,
};

#ifdef RETPOLINE
MODULE_INFO(retpoline, "Y");
#endif

static const char __module_depends[]
__used
__attribute__((section(".modinfo"))) =
"depends=";

MODULE_ALIAS("sdio:c*v3030d3030*");
MODULE_ALIAS("platform:SSV6200A");
MODULE_ALIAS("platform:RSV6200A");
MODULE_ALIAS("platform:SSV6006A");
MODULE_ALIAS("platform:SSV6006C");
MODULE_ALIAS("platform:SSV6006D");
MODULE_ALIAS("usb:v8065p6000d*dc*dsc*dp*ic*isc*ip*in*");
