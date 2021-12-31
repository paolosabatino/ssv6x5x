/*
 * Copyright (c) 2015 South Silicon Valley Microelectronics Inc.
 * Copyright (c) 2015 iComm Corporation
 *
 * This program is free software: you can redistribute it and/or modify 
 * it under the terms of the GNU General Public License as published by 
 * the Free Software Foundation, either version 3 of the License, or 
 * (at your option) any later version.
 * This program is distributed in the hope that it will be useful, but 
 * WITHOUT ANY WARRANTY; without even the implied warranty of 
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  
 * See the GNU General Public License for more details.
 * You should have received a copy of the GNU General Public License 
 * along with this program. If not, see <http://www.gnu.org/licenses/>.
 */

#include <linux/kernel.h>
#include <linux/version.h>
#include <linux/module.h>
#include <linux/moduleparam.h>
#include <linux/slab.h>
#include <linux/proc_fs.h>
#include <asm/uaccess.h>
#include <linux/errno.h>
#ifdef CONFIG_DEBUG_FS
#include <linux/debugfs.h>
#endif
#include "ssv_cmd.h"
#include "ssv_cfg.h"
#include <linux/fs.h>
#include <asm/uaccess.h>
#include <linux/buffer_head.h>
#include <linux/ctype.h>
#include <ssv6200.h>
#include <hci/hctrl.h>
#include <smac/dev.h>
#if (defined(CONFIG_SSV_SUPPORT_ANDROID)||defined(CONFIG_SSV_BUILD_AS_ONE_KO))
#include <hci/ssv_hci.h>
#include <smac/init.h>
#include <hwif/sdio/sdio.h>
#include <hwif/usb/usb.h>
#endif
MODULE_AUTHOR("iComm Semiconductor Co., Ltd");
MODULE_DESCRIPTION("Shared library for SSV wireless LAN cards.");
MODULE_LICENSE("Dual BSD/GPL");
char *stacfgpath = NULL;
EXPORT_SYMBOL(stacfgpath);
module_param(stacfgpath, charp, 0000);
MODULE_PARM_DESC(stacfgpath, "Get path of sta cfg");
char *cfgfirmwarepath = NULL;
EXPORT_SYMBOL(cfgfirmwarepath);
module_param(cfgfirmwarepath, charp, 0000);
MODULE_PARM_DESC(cfgfirmwarepath, "Get firmware path");
char* ssv_initmac = NULL;
EXPORT_SYMBOL(ssv_initmac);
module_param(ssv_initmac, charp, 0644);
MODULE_PARM_DESC(ssv_initmac, "Wi-Fi MAC address");
int ssv_tx_task_prio = 20;
EXPORT_SYMBOL(ssv_tx_task_prio);
module_param(ssv_tx_task_prio, int, 0644);
MODULE_PARM_DESC(ssv_tx_task_prio, "TX task's RT priority 1 ~ 99");
int ssv_rx_nr_recvbuff = 2;
EXPORT_SYMBOL(ssv_rx_nr_recvbuff);
module_param(ssv_rx_nr_recvbuff, int, 0644);
MODULE_PARM_DESC(ssv_rx_nr_recvbuff, "USB RX buffer 1 ~ MAX_NR_RECVBUFF");
u32 ssv_devicetype = 0;
EXPORT_SYMBOL(ssv_devicetype);
static struct proc_dir_entry *__ssv_procfs;
extern struct ssv6xxx_cfg_cmd_table cfg_cmds[];
extern struct ssv6xxx_cfg ssv_cfg;
#define READ_CHUNK 32
#if LINUX_VERSION_CODE < KERNEL_VERSION(3,10,0)
#define PDE_DATA(inode) ({ \
    struct proc_dir_entry *dp = PDE(inode); \
    data = dp->data; })
#endif

size_t read_line(struct file * fp, char *buf, size_t size)
{
	size_t num_read = 0;
	size_t total_read = 0;
	char *buffer;
	char ch;
	size_t start_ignore = 0;
	if (size <= 0 || buf == NULL) {
		total_read = -EINVAL;
		return -EINVAL;
	}
	buffer = buf;
	for (;;) {
#if LINUX_VERSION_CODE >= KERNEL_VERSION(4,14,0)
		num_read = kernel_read(fp, &ch, 1, &fp->f_pos);
#else
		mm_segment_t fs;
		fs = get_fs();
		set_fs(KERNEL_DS);
		num_read = vfs_read(fp, &ch, 1, &fp->f_pos);
		set_fs(fs);
#endif
		if (num_read < 0) {
			if (num_read == EINTR)
				continue;
			else
				return -1;
		} else if (num_read == 0) {
			if (total_read == 0)
				return 0;
			else
				break;
		} else {
			if (ch == '#')
				start_ignore = 1;
			if (total_read < size - 1) {
				total_read++;
				if (start_ignore)
					*buffer++ = '\0';
				else
					*buffer++ = ch;
			}
			if (ch == '\n')
				break;
		}
	}
	*buffer = '\0';
	return total_read;
}

int ischar(char *c)
{
	int is_char = 1;
	while (*c) {
		if (isalpha(*c) || isdigit(*c) || *c == '_' || *c == ':'
		    || *c == '/' || *c == '.' || *c == '-')
			c++;
		else {
			is_char = 0;
			break;
		}
	}
	return is_char;
}

static void _set_initial_cfg_default(void)
{
    size_t s;
  for(s=0; cfg_cmds[s].cfg_cmd != NULL; s++) {
  if ((cfg_cmds[s].def_val)!= NULL) {
   cfg_cmds[s].translate_func(cfg_cmds[s].def_val,
    cfg_cmds[s].var, cfg_cmds[s].arg);
  }
 }
}
static void _import_default_cfg (char *stacfgpath)
{
 struct file *fp = (struct file *) NULL;
 char buf[MAX_CHARS_PER_LINE], cfg_cmd[32], cfg_value[32];
 size_t s, read_len = 0, is_cmd_support = 0;
 printk("\n*** %s, %s ***\n\n", __func__, stacfgpath);
 if (stacfgpath == NULL)
  return;
 memset(&ssv_cfg, 0, sizeof(ssv_cfg));
 memset(buf, 0, sizeof(buf));
 _set_initial_cfg_default();
 fp = filp_open(stacfgpath, O_RDONLY, 0);
 if (IS_ERR(fp) || fp == NULL) {
  printk("ERROR: filp_open\n");
        WARN_ON(1);
  return;
 }
 if (fp->f_path.dentry == NULL) {
  printk("ERROR: dentry NULL\n");
        WARN_ON(1);
  return;
 }
 do {
  memset(cfg_cmd, '\0', sizeof(cfg_cmd));
  memset(cfg_value, '\0', sizeof(cfg_value));
  read_len = read_line(fp, buf, MAX_CHARS_PER_LINE);
  sscanf(buf, "%s = %s", cfg_cmd, cfg_value);
  if (!ischar(cfg_cmd) || !ischar(cfg_value)) {
   printk("ERORR invalid parameter: %s\n", buf);
   WARN_ON(1);
   continue;
  }
  is_cmd_support = 0;
  for(s=0; cfg_cmds[s].cfg_cmd != NULL; s++) {
   if (strcmp(cfg_cmds[s].cfg_cmd, cfg_cmd)==0) {
    cfg_cmds[s].translate_func(cfg_value,
     cfg_cmds[s].var, cfg_cmds[s].arg);
    is_cmd_support = 1;
    break;
   }
  }
  if (!is_cmd_support && strlen(cfg_cmd) > 0) {
   printk("ERROR Unsupported command: %s", cfg_cmd);
   WARN_ON(1);
  }
 } while (read_len > 0);
 filp_close(fp, NULL);
}
int ssv_init_cli (const char *dev_name, struct ssv_cmd_data *cmd_data)
{
    return 0;
}
EXPORT_SYMBOL(ssv_init_cli);
int ssv_deinit_cli (const char *dev_name, struct ssv_cmd_data *cmd_data)
{
    remove_proc_entry(PROC_SSV_DBG_ENTRY, cmd_data->proc_dev_entry);
    remove_proc_entry(PROC_SSV_CMD_ENTRY, cmd_data->proc_dev_entry);
    remove_proc_entry(dev_name, __ssv_procfs);
    return 0;
}
EXPORT_SYMBOL(ssv_deinit_cli);
#if (defined(CONFIG_SSV_SUPPORT_ANDROID)||defined(CONFIG_SSV_BUILD_AS_ONE_KO))
int ssvdevice_init(void)
#else
static int __init ssvdevice_init(void)
#endif
{
    _import_default_cfg(stacfgpath);
    __ssv_procfs = proc_mkdir(PROC_DIR_ENTRY, NULL);
    if (!__ssv_procfs)
        return -ENOMEM;
#if (defined(CONFIG_SSV_SUPPORT_ANDROID)||defined(CONFIG_SSV_BUILD_AS_ONE_KO))
    {
        int ret;
        ret = ssv6xxx_hci_init();
        if(!ret){
            ret = ssv6xxx_init();
        }if(!ret){
            ret = ssv6xxx_sdio_init();
  #if (defined(SSV_SUPPORT_SSV6006))
            ret = ssv6xxx_usb_init();
  #endif
        }
        return ret;
    }
#endif
    return 0;
}
#if (defined(CONFIG_SSV_SUPPORT_ANDROID)||defined(CONFIG_SSV_BUILD_AS_ONE_KO))
void ssvdevice_exit(void)
#else
static void __exit ssvdevice_exit(void)
#endif
{
#if (defined(CONFIG_SSV_SUPPORT_ANDROID)||defined(CONFIG_SSV_BUILD_AS_ONE_KO))
    ssv6xxx_exit();
    ssv6xxx_hci_exit();
    ssv6xxx_sdio_exit();
#if (defined(SSV_SUPPORT_SSV6006))
    ssv6xxx_usb_exit();
#endif
#endif
    remove_proc_entry(PROC_DIR_ENTRY, NULL);
}
//#if (defined(CONFIG_SSV_SUPPORT_ANDROID)||defined(CONFIG_SSV_BUILD_AS_ONE_KO))
//EXPORT_SYMBOL(ssvdevice_init);
//EXPORT_SYMBOL(ssvdevice_exit);
//#else
module_init(ssvdevice_init);
module_exit(ssvdevice_exit);
module_param_named(devicetype,ssv_devicetype, uint , S_IRUSR | S_IWUSR);
MODULE_PARM_DESC(devicetype, "Enable sdio bridge Mode/Wifi Mode.");
//#endif
