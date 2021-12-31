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

#if ((defined SSV_SUPPORT_HAL) && (defined SSV_SUPPORT_SSV6006))
#include <linux/nl80211.h>
#include <ssv6200.h>
#include "ssv6006B_reg.h"
#include "ssv6006B_aux.h"
#include <smac/dev.h>
#include <hal.h>
#include <ssvdevice/ssv_cmd.h>
#include "ssv6006_priv.h"
#include "ssv6006_priv_normal.h"
#include "geminiA_wifi_phy_reg.c"
#include "geminiA_rf_reg.c"
#include "turismo_common.h"
static bool ssv6006_geminiA_set_rf_enable(struct ssv_hw *sh, bool val);
static const size_t ssv6006_geminiA_phy_tbl_size = sizeof(ssv6006_geminiA_phy_setting);
static void ssv6006_geminiA_load_phy_table(ssv_cabrio_reg **phy_table)
{
    *phy_table = ssv6006_geminiA_phy_setting;
}
static u32 ssv6006_geminiA_get_phy_table_size(struct ssv_hw *sh)
{
    return(u32) ssv6006_geminiA_phy_tbl_size;
}
static const size_t ssv6006_geminiA_rf_tbl_size = sizeof(ssv6006_geminiA_rf_setting);
static void ssv6006_geminiA_load_rf_table(ssv_cabrio_reg **rf_table)
{
    *rf_table = ssv6006_geminiA_rf_setting;
}
static u32 ssv6006_geminiA_get_rf_table_size(struct ssv_hw *sh)
{
    return (u32) ssv6006_geminiA_rf_tbl_size;
}
#define USE_COMMON_MACRO 
static void ssv6006_geminiA_init_PLL(struct ssv_hw *sh)
{
#ifdef USE_COMMON_MACRO
    TU_INIT_PLL;
#else
    u32 regval , count = 0;
    SMAC_REG_WRITE(sh, ADR_PMU_REG_2, 0xa51a8800);
    do
    {
        msleep(1);
        SMAC_REG_READ(sh, ADR_PMU_STATE_REG, &regval);
        count ++ ;
        if (regval == 3)
            break;
        if (count > 100){
            printk(" PLL initial fails \n");
            WARN_ON(1);
            break;
        }
    } while (1);
    msleep(1);
    SMAC_REG_WRITE(sh, ADR_WIFI_PHY_COMMON_SYS_REG, 0x80000000);
    SMAC_REG_WRITE(sh, ADR_CLOCK_SELECTION, 0x00000004);
    msleep(1);
#endif
}
static int ssv6006_geminiA_set_channel(struct ssv_softc *sc, struct ieee80211_channel *chan,
    enum nl80211_channel_type channel_type)
{
    struct ssv_hw *sh = sc->sh;
    int ch;
    const char *ch_type[]={"NL80211_CHAN_NO_HT",
     "NL80211_CHAN_HT20",
     "NL80211_CHAN_HT40MINUS",
     "NL80211_CHAN_HT40PLUS"};
    ch = chan->hw_value;
    printk("%s: ch %d, type %s\n", __func__, ch, ch_type[channel_type]);
#ifdef USE_COMMON_MACRO
    TU_SET_GEMINIA_BW(channel_type);
    TU_SET_CHANNEL(ch);
#else
    switch (channel_type){
        int val;
      case NL80211_CHAN_HT20:
      case NL80211_CHAN_NO_HT:
            SET_MTX_BLOCKTX_IGNORE_TOMAC_CCA_ED_SECONDARY(1);
            SMAC_REG_WRITE(sh, ADR_GEMINIA_WIFI_RX_FILTER_REGISTER, 0x271556db);
            udelay(50);
            SMAC_REG_SET_BITS(sh, ADR_GEMINIA_DIGITAL_ADD_ON_R0,
                (0 << RG_GEMINIA_40M_MODE_SFT) | (0 << RG_GEMINIA_LO_UP_CH_SFT),
                (RG_GEMINIA_LO_UP_CH_MSK | RG_GEMINIA_40M_MODE_MSK));
            udelay(50);
            SMAC_REG_SET_BITS(sh, ADR_WIFI_PHY_COMMON_SYS_REG,
                (0 << RG_SYSTEM_BW_SFT) | (0 << RG_PRIMARY_CH_SIDE_SFT),
                (RG_SYSTEM_BW_MSK | RG_PRIMARY_CH_SIDE_MSK));
            break;
     case NL80211_CHAN_HT40MINUS:
            SET_MTX_BLOCKTX_IGNORE_TOMAC_CCA_ED_SECONDARY(0);
            SMAC_REG_WRITE(sh, ADR_GEMINIA_WIFI_RX_FILTER_REGISTER, 0x2725534d);
            udelay(50);
            SMAC_REG_SET_BITS(sh, ADR_GEMINIA_DIGITAL_ADD_ON_R0,
                (1 << RG_GEMINIA_40M_MODE_SFT) | (0 << RG_GEMINIA_LO_UP_CH_SFT),
                (RG_GEMINIA_LO_UP_CH_MSK | RG_GEMINIA_40M_MODE_MSK));
            udelay(50);
            SMAC_REG_SET_BITS(sh, ADR_WIFI_PHY_COMMON_SYS_REG,
                (1 << RG_SYSTEM_BW_SFT) | (1 << RG_PRIMARY_CH_SIDE_SFT),
                (RG_SYSTEM_BW_MSK | RG_PRIMARY_CH_SIDE_MSK));
         break;
     case NL80211_CHAN_HT40PLUS:
            SET_MTX_BLOCKTX_IGNORE_TOMAC_CCA_ED_SECONDARY(0);
            SMAC_REG_WRITE(sh, ADR_GEMINIA_WIFI_RX_FILTER_REGISTER, 0x2725534d);
            udelay(50);
            SMAC_REG_SET_BITS(sh, ADR_GEMINIA_DIGITAL_ADD_ON_R0,
                (1 << RG_GEMINIA_40M_MODE_SFT) | (1 << RG_GEMINIA_LO_UP_CH_SFT),
                (RG_GEMINIA_LO_UP_CH_MSK | RG_GEMINIA_40M_MODE_MSK));
            udelay(50);
            SMAC_REG_SET_BITS(sh, ADR_WIFI_PHY_COMMON_SYS_REG,
                (1 << RG_SYSTEM_BW_SFT) | (0 << RG_PRIMARY_CH_SIDE_SFT),
                (RG_SYSTEM_BW_MSK | RG_PRIMARY_CH_SIDE_MSK));
            break;
      default:
            break;
    }
    msleep(1);
    SMAC_REG_SET_BITS(sh, ADR_MODE_REGISTER, 1 << RG_MODE_MANUAL_SFT, RG_MODE_MANUAL_MSK);
    msleep(1);
    SMAC_REG_SET_BITS(sh, ADR_SX_2_4GB_5GB_REGISTER_INT3BIT___CH_TABLE,
        1 << RG_SX_RFCH_MAP_EN_SFT, RG_SX_RFCH_MAP_EN_MSK);
    msleep(1);
    SMAC_REG_SET_BITS(sh, ADR_SX_2_4GB_5GB_REGISTER_INT3BIT___CH_TABLE,
    ch << RG_SX_CHANNEL_SFT, RG_SX_CHANNEL_MSK);
    msleep(1);
    SMAC_REG_SET_BITS(sh, ADR_MODE_REGISTER, 0 << RG_MODE_SFT, RG_MODE_MSK);
    msleep(1);
    SMAC_REG_SET_BITS(sh, ADR_MODE_REGISTER, 3 << RG_MODE_SFT, RG_MODE_SFT);
    msleep(1);
    SMAC_REG_SET_BITS(sh, ADR_MODE_REGISTER, 0 << RG_MODE_MANUAL_SFT, RG_MODE_MANUAL_MSK);
    msleep(1);
#endif
    return 0;
}
static void ssv6006_geminiA_init_cali (struct ssv_hw *sh)
{
#ifdef USE_COMMON_MACRO
    TU_INIT_GEMINIA_CAL;
#else
    int i , regval;
    u32 wifi_dc_addr;
    SMAC_REG_SET_BITS(sh, ADR_GEMINIA_3_WIRE_REGISTER,
        0 << RG_GEMINIA_HS_3WIRE_MANUAL_SFT, RG_GEMINIA_HS_3WIRE_MANUAL_MSK);
    udelay(50);
    SMAC_REG_SET_BITS(sh, ADR_GEMINIA_3_WIRE_REGISTER,
        0 << RG_GEMINIA_HW_PINSEL_SFT, RG_GEMINIA_HW_PINSEL_MSK);
    udelay(50);
    SMAC_REG_SET_BITS(sh, ADR_GEMINIA_MANUAL_ENABLE_REGISTER,
        ((1 << RG_GEMINIA_EN_RX_ADC_SFT) | (0 <<RG_GEMINIA_RX_ADC_MANUAL_SFT)),
        (RG_GEMINIA_EN_RX_ADC_MSK | RG_GEMINIA_RX_ADC_MANUAL_MSK));
    udelay(50);
    printk("--------- reset Calibration result----------------");
    for (i = 0; i < 22; i++) {
        if (i %4 == 0)
            printk("\n");
        wifi_dc_addr = (ADR_GEMINIA_WF_DCOC_IDAC_REGISTER1)+ (i << 2);
        SMAC_REG_READ(sh, wifi_dc_addr, &regval);
        printk("addr %x : val %x, ", wifi_dc_addr, regval);
    }
    printk("Start WiFi Rx DC calibration...\n");
    SMAC_REG_SET_BITS(sh, ADR_GEMINIA_3_WIRE_REGISTER,
        1 << RG_GEMINIA_MODE_MANUAL_SFT, RG_GEMINIA_MODE_MANUAL_MSK);
    udelay(50);
    SMAC_REG_SET_BITS(sh, ADR_GEMINIA_3_WIRE_REGISTER,
        6 << RG_GEMINIA_MODE_SFT, RG_GEMINIA_MODE_MSK);
    udelay(50);
    SMAC_REG_SET_BITS(sh, ADR_GEMINIA_3_WIRE_REGISTER,
        1 << RG_GEMINIA_CAL_INDEX_SFT, RG_GEMINIA_CAL_INDEX_MSK);
    msleep(10);
    printk("--------------------------------------------\n");
    printk("--------- Calibration result----------------");
    for (i = 0; i < 22; i++) {
       if (i %4 == 0)
          printk("\n");
       wifi_dc_addr = (ADR_GEMINIA_WF_DCOC_IDAC_REGISTER1)+ (i << 2);
       SMAC_REG_READ(sh, wifi_dc_addr, &regval);
       printk("addr %x : val %x, ", wifi_dc_addr, regval);
    }
    SMAC_REG_SET_BITS(sh, ADR_GEMINIA_3_WIRE_REGISTER,
        0 << RG_GEMINIA_CAL_INDEX_SFT, RG_GEMINIA_CAL_INDEX_MSK);
    udelay(50);
    SMAC_REG_SET_BITS(sh, ADR_GEMINIA_3_WIRE_REGISTER,
        1 << RG_GEMINIA_MODE_SFT, RG_GEMINIA_MODE_MSK);
    udelay(50);
    SMAC_REG_SET_BITS(sh, ADR_GEMINIA_3_WIRE_REGISTER,
        0 << RG_GEMINIA_MODE_MANUAL_SFT, RG_GEMINIA_MODE_MANUAL_MSK);
    udelay(50);
    SMAC_REG_SET_BITS(sh, ADR_GEMINIA_3_WIRE_REGISTER,
        1 << RG_GEMINIA_HS_3WIRE_MANUAL_SFT, RG_GEMINIA_HS_3WIRE_MANUAL_MSK);
    udelay(50);
    SMAC_REG_SET_BITS(sh, ADR_GEMINIA_3_WIRE_REGISTER,
        1 << RG_GEMINIA_HW_PINSEL_SFT, RG_GEMINIA_HW_PINSEL_MSK);
    udelay(50);
    SMAC_REG_SET_BITS(sh, ADR_GEMINIA_MANUAL_ENABLE_REGISTER,
        ((0 << RG_GEMINIA_EN_RX_ADC_SFT) | (1 <<RG_GEMINIA_RX_ADC_MANUAL_SFT)),
        (RG_GEMINIA_EN_RX_ADC_MSK | RG_GEMINIA_RX_ADC_MANUAL_MSK));
    udelay(50);
#endif
}
static void ssv6006_geminiA_init_geminiA_trx(struct ssv_hw *sh)
{
#ifdef USE_COMMON_MACRO
    TU_INIT_GEMINIA_TRX;
#else
    SMAC_REG_SET_BITS(sh, ADR_GEMINIA_PMU_REG_2, 1 << RG_GEMINIA_LOAD_RFTABLE_RDY_SFT,
        RG_GEMINIA_LOAD_RFTABLE_RDY_MSK);
    udelay(50);
    SMAC_REG_SET_BITS(sh, ADR_GEMINIA_3_WIRE_REGISTER,
        1 << RG_GEMINIA_HS_3WIRE_MANUAL_SFT, RG_GEMINIA_HS_3WIRE_MANUAL_MSK);
    udelay(50);
    SMAC_REG_SET_BITS(sh, ADR_GEMINIA_3_WIRE_REGISTER,
        1 << RG_GEMINIA_HW_PINSEL_SFT, RG_GEMINIA_HW_PINSEL_MSK);
    udelay(50);
    SMAC_REG_SET_BITS(sh, ADR_GEMINIA_3_WIRE_REGISTER,
        0 << RG_GEMINIA_TXGAIN_PHYCTRL_SFT, RG_GEMINIA_TXGAIN_PHYCTRL_MSK);
    udelay(50);
    SMAC_REG_SET_BITS(sh, ADR_GEMINIA_3_WIRE_REGISTER,
        3 << RG_GEMINIA_TX_GAIN_SFT, RG_GEMINIA_TX_GAIN_MSK);
    udelay(50);
    SMAC_REG_SET_BITS(sh, ADR_GEMINIA_MANUAL_ENABLE_REGISTER,
        ((0 << RG_GEMINIA_EN_TX_DAC_SFT) | (1 <<RG_GEMINIA_TX_DAC_MANUAL_SFT)),
        (RG_GEMINIA_EN_TX_DAC_MSK | RG_GEMINIA_TX_DAC_MANUAL_MSK));
    udelay(50);
    SMAC_REG_SET_BITS(sh, ADR_GEMINIA_MANUAL_ENABLE_REGISTER,
        ((0 << RG_GEMINIA_EN_RX_ADC_SFT) | (1 <<RG_GEMINIA_RX_ADC_MANUAL_SFT)),
        (RG_GEMINIA_EN_RX_ADC_MSK | RG_GEMINIA_RX_ADC_MANUAL_MSK));
    udelay(50);
    SMAC_REG_SET_BITS(sh, ADR_GEMINIA_CALIBRATION_TEST_REGISTER,
        1 << RG_GEMINIA_EN_TX_VTOI_2ND_SFT, RG_GEMINIA_EN_TX_VTOI_2ND_MSK);
    udelay(50);
    SMAC_REG_SET_BITS(sh, ADR_GEMINIA_CALIBRATION_TEST_REGISTER,
        1 << RG_GEMINIA_EN_RX_PADSW_SFT, RG_GEMINIA_EN_RX_PADSW_MSK);
    udelay(50);
    SMAC_REG_SET_BITS(sh, ADR_GEMINIA_SYN_REGISTER_INT3BIT_CH_TABLE,
        0 << RG_GEMINIA_SX_FREF_DOUB_SFT, RG_GEMINIA_SX_FREF_DOUB_MSK);
    msleep(1);
    SMAC_REG_SET_BITS(sh, ADR_GEMINIA_MCU_REG_0,
        1 << RG_GEMINIA_PAD_MUX_SEL_SFT, RG_GEMINIA_PAD_MUX_SEL_MSK);
    udelay(50);
    SMAC_REG_SET_BITS(sh, ADR_GEMINIA_IO_REG_2,
        (RG_GEMINIA_GPIO07_OE_MSK | RG_GEMINIA_GPIO06_OE_MSK | RG_GEMINIA_GPIO05_OE_MSK | RG_GEMINIA_GPIO04_OE_MSK | RG_GEMINIA_GPIO03_OE_MSK),
        (RG_GEMINIA_GPIO07_OE_MSK | RG_GEMINIA_GPIO06_OE_MSK | RG_GEMINIA_GPIO05_OE_MSK | RG_GEMINIA_GPIO04_OE_MSK | RG_GEMINIA_GPIO03_OE_MSK));
    udelay(50);
    SMAC_REG_SET_BITS(sh, ADR_GEMINIA_IO_REG_0, 1 << RG_GEMINIA_FPGA_CLK_REF_40M_DS_SFT,
        RG_GEMINIA_FPGA_CLK_REF_40M_DS_MSK);
    udelay(50);
    SMAC_REG_SET_BITS(sh, ADR_GEMINIA_IO_REG_0, 1 << RG_GEMINIA_FPGA_CLK_REF_40M_OE_SFT,
        RG_GEMINIA_FPGA_CLK_REF_40M_OE_MSK);
    msleep(1);
#endif
}
static void ssv6006_geminiA_write_rf_table(struct ssv_hw *sh )
{
    u32 i = 0;
    for( i = 0; i < sizeof(ssv6006_geminiA_rf_setting)/sizeof(ssv_cabrio_reg); i++) {
       SMAC_REG_WRITE(sh, ssv6006_geminiA_rf_setting[i].address, ssv6006_geminiA_rf_setting[i].data );
       udelay(50);
    }
}
static int ssv6006_geminiA_set_pll_phy_rf(struct ssv_hw *sh
    , ssv_cabrio_reg *rf_tbl, ssv_cabrio_reg *phy_tbl)
{
    int ret = 0;
    ssv6006_geminiA_write_rf_table(sh);
    ssv6006_geminiA_init_geminiA_trx(sh);
    HAL_INIT_PLL(sh);
    HAL_SET_PHY_MODE(sh, false);
    ret = SSV6XXX_SET_HW_TABLE(sh, ssv6006_geminiA_phy_setting);
    ssv6006_geminiA_init_cali(sh);
    return ret;
}
static bool ssv6006_geminiA_set_rf_enable(struct ssv_hw *sh, bool val)
{
    SMAC_REG_SET_BITS(sh, ADR_MODE_REGISTER, 1 << RG_MODE_MANUAL_SFT, RG_MODE_MANUAL_MSK);
    msleep(1);
    if (val){
        SMAC_REG_SET_BITS(sh, ADR_MODE_REGISTER, 3 << RG_MODE_SFT, RG_MODE_SFT);
 } else {
        SMAC_REG_SET_BITS(sh, ADR_MODE_REGISTER, 0 << RG_MODE_SFT, RG_MODE_MSK);
 }
    msleep(1);
    SMAC_REG_SET_BITS(sh, ADR_MODE_REGISTER, 0 << RG_MODE_MANUAL_SFT, RG_MODE_MANUAL_MSK);
    udelay(50);
 return true;
}
static bool ssv6006_geminiA_dump_phy_reg(struct ssv_hw *sh)
{
    u32 regval;
    int s;
    ssv_cabrio_reg *raw;
    struct ssv_cmd_data *cmd_data = &sh->sc->cmd_data;
    raw = ssv6006_geminiA_phy_setting;
    snprintf_res(cmd_data, ">> PHY Register Table:\n");
    for(s = 0; s < ssv6006_geminiA_phy_tbl_size/sizeof(ssv_cabrio_reg); s++, raw++) {
        SMAC_REG_READ(sh, raw->address, &regval);
        SMAC_REG_READ(sh, raw->address, &regval);
        snprintf_res(cmd_data, "   ADDR[0x%08x] = 0x%08x\n",
            raw->address, regval);
     }
    snprintf_res(cmd_data, ">>PHY Table version: %s\n", SSV6006_GEMINIA_PHY_TABLE_VER);
    snprintf_res(cmd_data, "\n\n");
    return 0;
}
static bool ssv6006_geminiA_dump_rf_reg(struct ssv_hw *sh)
{
    u32 regval;
    int s;
    ssv_cabrio_reg *raw;
    struct ssv_cmd_data *cmd_data = &sh->sc->cmd_data;
    raw = ssv6006_geminiA_rf_setting;
    snprintf_res(cmd_data, ">> RF Register Table:\n");
    for(s = 0; s < ssv6006_geminiA_rf_tbl_size/sizeof(ssv_cabrio_reg); s++, raw++) {
        SMAC_REG_READ(sh, raw->address, &regval);
        snprintf_res(cmd_data, "   ADDR[0x%08x] = 0x%08x\n",
            raw->address, regval);
    }
    snprintf_res(cmd_data, ">>RF Table version: %s\n", SSV6006_GEMINIA_RF_TABLE_VER);
    snprintf_res(cmd_data, "\n\n");
    return 0;
}
static bool ssv6006_geminiA_support_iqk_cmd(struct ssv_hw *sh)
{
    return false;
}
static void ssv6006_cmd_cali(struct ssv_hw *sh, int argc, char *argv[])
{
    struct ssv_cmd_data *cmd_data = &sh->sc->cmd_data;
    if(!strcmp(argv[1], "do")){
        ssv6006_geminiA_init_cali(sh);
        ssv6006_geminiA_init_geminiA_trx(sh);
        snprintf_res(cmd_data,"\n   CALIRATION DONE\n");
    } else if(!strcmp(argv[1], "show")) {
        u32 i, regval = 0, wifi_dc_addr;
        snprintf_res(cmd_data,"--------------------------------------------\n");
        snprintf_res(cmd_data,"--------- Calibration result----------------");
        for (i = 0; i < 22; i++) {
           if (i %4 == 0)
              snprintf_res(cmd_data,"\n");
           wifi_dc_addr = ADR_GEMINIA_WF_DCOC_IDAC_REGISTER1+ (i << 2);
           SMAC_REG_READ(sh, wifi_dc_addr, &regval);
           snprintf_res(cmd_data,"addr %x : val %x, ", wifi_dc_addr, regval);
        }
    } else {
        snprintf_res(cmd_data,"\n cali [do] [show]\n");
    }
}
void ssv_attach_ssv6006_geminiA_BBRF(struct ssv_hal_ops *hal_ops)
{
    hal_ops->load_phy_table = ssv6006_geminiA_load_phy_table;
    hal_ops->get_phy_table_size = ssv6006_geminiA_get_phy_table_size;
    hal_ops->get_rf_table_size = ssv6006_geminiA_get_rf_table_size;
    hal_ops->load_rf_table = ssv6006_geminiA_load_rf_table;
    hal_ops->init_pll = ssv6006_geminiA_init_PLL;
    hal_ops->set_channel = ssv6006_geminiA_set_channel;
    hal_ops->set_pll_phy_rf = ssv6006_geminiA_set_pll_phy_rf;
    hal_ops->set_rf_enable = ssv6006_geminiA_set_rf_enable;
    hal_ops->dump_phy_reg = ssv6006_geminiA_dump_phy_reg;
    hal_ops->dump_rf_reg = ssv6006_geminiA_dump_rf_reg;
    hal_ops->support_iqk_cmd = ssv6006_geminiA_support_iqk_cmd;
    hal_ops->cmd_cali = ssv6006_cmd_cali;
}
#endif
