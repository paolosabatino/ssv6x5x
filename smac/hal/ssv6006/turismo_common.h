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

#ifndef TU_COMMON_H
#define TU_COMMON_H 
#define SSV6006_TURISMOC_COMMON_CODE_VER "1.00"
struct ssv6006_tx_desc
{
    u32 len:16;
    u32 c_type:3;
    u32 f80211:1;
    u32 qos:1;
    u32 ht:1;
    u32 use_4addr:1;
    u32 rvdtx_0:3;
    u32 bc_que:1;
    u32 security:1;
    u32 more_data:1;
    u32 stype_b5b4:2;
    u32 extra_info:1;
    u32 fCmd;
    u32 hdr_offset:8;
    u32 frag:1;
    u32 unicast:1;
    u32 hdr_len:6;
    u32 no_pkt_buf_reduction:1;
    u32 tx_burst_obsolete:1;
    u32 ack_policy_obsolete:2;
    u32 aggr:2;
    u32 rsvdtx_1:1;
    u32 is_rate_stat_sample_pkt:1;
    u32 bssidx:2;
    u32 reason:6;
    u32 payload_offset_obsolete:8;
    u32 tx_pkt_run_no:8;
    u32 fCmdIdx:3;
    u32 wsid:4;
    u32 txq_idx:3;
    u32 TxF_ID:6;
    u32 rateidx1_data_duration:16;
    u32 rateidx2_data_duration:16;
    u32 rateidx3_data_duration:16;
    u32 rsvd_tx05 :2;
    u32 rate_rpt_mode:2;
    u32 ampdu_tx_ssn:12;
    u32 drate_idx0:8;
    u32 crate_idx0:8;
    u32 rts_cts_nav0:16;
    u32 dl_length0:12;
    u32 try_cnt0:4;
    u32 ack_policy0:2;
    u32 do_rts_cts0:2;
    u32 is_last_rate0:1;
    u32 rsvdtx_07b:1;
    u32 rpt_result0:2;
    u32 rpt_trycnt0:4;
    u32 rpt_noctstrycnt0:4;
    u32 drate_idx1:8;
    u32 crate_idx1:8;
    u32 rts_cts_nav1:16;
    u32 dl_length1:12;
    u32 try_cnt1:4;
    u32 ack_policy1:2;
    u32 do_rts_cts1:2;
    u32 is_last_rate1:1;
    u32 rsvdtx_09b:1;
    u32 rpt_result1:2;
    u32 rpt_trycnt1:4;
    u32 rpt_noctstrycnt1:4;
    u32 drate_idx2:8;
    u32 crate_idx2:8;
    u32 rts_cts_nav2:16;
    u32 dl_length2:12;
    u32 try_cnt2:4;
    u32 ack_policy2:2;
    u32 do_rts_cts2:2;
    u32 is_last_rate2:1;
    u32 rsvdtx_11b:1;
    u32 rpt_result2:2;
    u32 rpt_trycnt2:4;
    u32 rpt_noctstrycnt2:4;
    u32 drate_idx3:8;
    u32 crate_idx3:8;
    u32 rts_cts_nav3:16;
    u32 dl_length3:12;
    u32 try_cnt3:4;
    u32 ack_policy3:2;
    u32 do_rts_cts3:2;
    u32 is_last_rate3:1;
    u32 rsvdtx_13b:1;
    u32 rpt_result3:2;
    u32 rpt_trycnt3:4;
    u32 rpt_noctstrycnt3:4;
    u32 ampdu_whole_length:16;
    u32 ampdu_next_pkt:8;
    u32 ampdu_last_pkt:1;
    u32 rsvdtx_14a:3;
    u32 ampdu_dmydelimiter_num:4;
    u32 ampdu_tx_bitmap_lw;
    u32 ampdu_tx_bitmap_hw;
    u32 dummy0;
    u32 dummy1;
    u32 dummy2;
};
struct ssv6006_rx_desc
{
    u32 len:16;
    u32 c_type:3;
    u32 f80211:1;
    u32 qos:1;
    u32 ht:1;
    u32 use_4addr:1;
    u32 rsvdrx0_1:1;
    u32 running_no:4;
    u32 psm:1;
    u32 stype_b5b4:2;
    u32 rsvdrx0_2:1;
    union{
        u32 fCmd;
        u32 edca0_used:4;
        u32 edca1_used:5;
        u32 edca2_used:5;
        u32 edca3_used:5;
        u32 mng_used:4;
        u32 tx_page_used:9;
    };
    u32 hdr_offset:8;
    u32 frag:1;
    u32 unicast:1;
    u32 hdr_len:6;
    u32 RxResult:8;
    u32 bssid:2;
    u32 reason:6;
    u32 channel:8;
    u32 rx_pkt_run_no:8;
    u32 fCmdIdx:3;
    u32 wsid:4;
    u32 tkip_mmic_err:1;
    u32 rsvd_rx_3b:8;
};
struct ssv6006_rxphy_info {
    u32 len:16;
    u32 phy_rate:8;
    u32 smoothing:1;
    u32 no_sounding:1;
    u32 aggregate:1;
    u32 stbc:2;
    u32 fec:1;
    u32 n_ess:2;
    u32 l_length:12;
    u32 l_rate:3;
    u32 mrx_seqn:1;
    u32 rssi:8;
    u32 snr:8;
    u32 rx_freq_offset:16;
    u32 service:16;
    u32 rx_time_stamp;
};
struct ssv6006_patch{
    u16 xtal;
    u16 cpu_clk;
};
#define CLK_32K 1
#define CLK_XTAL 2
#define CLK_40M 4
#define CLK_80M 8
enum {
    XTAL16M = 0,
    XTAL24M,
    XTAL26M,
    XTAL40M,
    XTAL12M,
    XTAL20M,
    XTAL25M,
    XTAL32M,
    XTAL19P2M,
    XTAL38P4M,
    XTAL52M,
    XTALMAX,
};
enum{
    G_BAND_ONLY = 0,
    AG_BAND_BOTH = 1,
};
enum {
    CAL_IDX_NONE,
    CAL_IDX_WIFI2P4G_RXDC,
    CAL_IDX_BT_RXDC,
    CAL_IDX_BW20_RXRC,
    CAL_IDX_WIFI2P4G_TXLO,
    CAL_IDX_WIFI2P4G_TXIQ,
    CAL_IDX_WIFI2P4G_RXIQ,
    CAL_IDX_WIFI2P4G_PADPD,
    CAL_IDX_5G_NONE,
    CAL_IDX_WIFI5G_RXDC,
    CAL_IDX_5G_NONE2,
    CAL_IDX_BW40_RXRC,
    CAL_IDX_WIFI5G_TXLO,
    CAL_IDX_WIFI5G_TXIQ,
    CAL_IDX_WIFI5G_RXIQ,
    CAL_IDX_WIFI5G_PADPD,
};
enum {
    MODE_STANDBY,
    MODE_CALIBRATION,
    MODE_WIFI2P4G_TX,
    MODE_WIFI2P4G_RX,
    MODE_BT_TX,
    MODE_BT_RX,
    MODE_WIFI5G_TX,
    MODE_WIFI5G_RX,
};
enum {
    BAND_2G,
    BAND_5100,
    BAND_5500,
    BAND_5700,
    BAND_5900,
};
#ifndef MAX_PADPD_TONE
#define MAX_PADPD_TONE 26
#endif
struct padpd_table{
    u32 addr;
    u32 mask0;
    u32 mask1;
};
extern int cal_ch_5g[4];
extern struct padpd_table padpd_am_table[];
extern struct padpd_table padpd_pm_table[];
#define TU_SET_CHANNEL(_ch) \
do{ \
                                                                                            \
    SET_RG_MODE_MANUAL(1); \
    MSLEEP(1); \
                                                                                            \
                                                                                            \
    SET_RG_SX_RFCH_MAP_EN(1); \
    MSLEEP(1); \
                                                                                            \
                                                                                            \
    SET_RG_SX_CHANNEL(_ch); \
    MSLEEP(1); \
                                                                                            \
                                                                                            \
    SET_RG_MODE(0); \
    MSLEEP(1); \
                                                                                            \
                                                                                            \
    SET_RG_MODE(3); \
    MSLEEP(1); \
                                                                                            \
                                                                                            \
    SET_RG_MODE_MANUAL(0); \
    MSLEEP(1); \
                                                                                            \
} while(0)
#define TU_SET_GEMINIA_BW(_ch_type) \
do{ \
                                                                                            \
    switch (_ch_type){ \
      case NL80211_CHAN_HT20: \
      case NL80211_CHAN_NO_HT: \
                                                                                            \
            SET_MTX_BLOCKTX_IGNORE_TOMAC_CCA_ED_SECONDARY(1); \
                                                                                            \
            REG32_W(ADR_GEMINIA_WIFI_RX_FILTER_REGISTER, 0x271556db); \
            MSLEEP(1); \
                                                                                            \
            SET_REG(ADR_GEMINIA_DIGITAL_ADD_ON_R0, \
                (0 << RG_GEMINIA_40M_MODE_SFT) | (0 << RG_GEMINIA_LO_UP_CH_SFT), 0, \
                (RG_GEMINIA_LO_UP_CH_I_MSK & RG_GEMINIA_40M_MODE_I_MSK)); \
            MSLEEP(1); \
            SET_REG(ADR_WIFI_PHY_COMMON_SYS_REG, \
                (0 << RG_SYSTEM_BW_SFT) | (0 << RG_PRIMARY_CH_SIDE_SFT), 0, \
                (RG_SYSTEM_BW_I_MSK & RG_PRIMARY_CH_SIDE_I_MSK)); \
                                                                                            \
            break; \
                                                                                            \
   case NL80211_CHAN_HT40MINUS: \
                                                                                            \
            SET_MTX_BLOCKTX_IGNORE_TOMAC_CCA_ED_SECONDARY(0); \
                                                                                            \
            REG32_W(ADR_GEMINIA_WIFI_RX_FILTER_REGISTER, 0x2725534d); \
            UDELAY(50); \
                                                                                            \
            SET_REG(ADR_GEMINIA_DIGITAL_ADD_ON_R0, \
                (1 << RG_GEMINIA_40M_MODE_SFT) | (0 << RG_GEMINIA_LO_UP_CH_SFT), 0, \
                (RG_GEMINIA_LO_UP_CH_I_MSK & RG_GEMINIA_40M_MODE_I_MSK)); \
            UDELAY(50); \
                                                                                            \
            SET_REG(ADR_WIFI_PHY_COMMON_SYS_REG, \
                (1 << RG_SYSTEM_BW_SFT) | (1 << RG_PRIMARY_CH_SIDE_SFT), 0, \
                (RG_SYSTEM_BW_I_MSK & RG_PRIMARY_CH_SIDE_I_MSK)); \
                                                                                            \
         break; \
                                                                                            \
   case NL80211_CHAN_HT40PLUS: \
                                                                                            \
            SET_MTX_BLOCKTX_IGNORE_TOMAC_CCA_ED_SECONDARY(0); \
                                                                                            \
            REG32_W(ADR_GEMINIA_WIFI_RX_FILTER_REGISTER, 0x2725534d); \
            UDELAY(50); \
                                                                                            \
            SET_REG(ADR_GEMINIA_DIGITAL_ADD_ON_R0, \
                (1 << RG_GEMINIA_40M_MODE_SFT) | (1 << RG_GEMINIA_LO_UP_CH_SFT), 0, \
                (RG_GEMINIA_LO_UP_CH_I_MSK & RG_GEMINIA_40M_MODE_I_MSK)); \
            UDELAY(50); \
                                                                                            \
            SET_REG(ADR_WIFI_PHY_COMMON_SYS_REG, \
                (1 << RG_SYSTEM_BW_SFT) | (0 << RG_PRIMARY_CH_SIDE_SFT), 0, \
                (RG_SYSTEM_BW_I_MSK & RG_PRIMARY_CH_SIDE_I_MSK)); \
                                                                                            \
            break; \
      default: \
            break; \
    } \
    MSLEEP(1); \
} while(0)
#define TU_CHANGE_GEMINIA_CHANNEL(_ch,_ch_type) \
do{ \
    const char *chan_type[]={"NL80211_CHAN_NO_HT", \
     "NL80211_CHAN_HT20", \
     "NL80211_CHAN_HT40MINUS", \
     "NL80211_CHAN_HT40PLUS"}; \
                                                                                            \
    PRINT("%s: ch %d, type %s\r\n", __func__, _ch, _chan_type[_ch_type]); \
    TU_SET_GEMINIA_BW(_ch_type) \
    TU_SET_CHANNEL(_ch); \
} while(0)
#define TU_INIT_PLL \
do{ \
    u32 regval , count = 0; \
                                                                                            \
    MSLEEP(1); \
                                                                                            \
    REG32_W(ADR_PMU_REG_2, 0xa51a8800); \
    do \
    { \
        MSLEEP(1); \
        regval = REG32_R(ADR_PMU_STATE_REG); \
        count ++ ; \
        if (regval == 3) \
            break; \
        if (count > 100){ \
            PRINT(" PLL initial fails \r\n"); \
            break; \
        } \
    } while (1); \
                                                                                            \
    MSLEEP(1); \
                                                                                            \
    REG32_W(ADR_WIFI_PHY_COMMON_SYS_REG, 0x80000000); \
                                                                                            \
    REG32_W(ADR_CLOCK_SELECTION, 0x00000004); \
    MSLEEP(1); \
} while(0)
#define TU_INIT_GEMINIA_CAL \
do{ \
    int i ; \
    u32 wifi_dc_addr, reg_val; \
                                                                                            \
                                                                                            \
    SET_RG_GEMINIA_HS_3WIRE_MANUAL(0); \
    UDELAY(50); \
                                                                                            \
                                                                                            \
    SET_RG_GEMINIA_HW_PINSEL(0); \
    UDELAY(50); \
                                                                                            \
                                                                                            \
    SET_REG(ADR_GEMINIA_MANUAL_ENABLE_REGISTER, \
        ((1 << RG_GEMINIA_EN_RX_ADC_SFT) | (0 <<RG_GEMINIA_RX_ADC_MANUAL_SFT)), 0, \
        (RG_GEMINIA_EN_RX_ADC_I_MSK & RG_GEMINIA_RX_ADC_MANUAL_I_MSK)); \
    UDELAY(50); \
                                                                                            \
    PRINT("--------- reset Calibration result----------------"); \
    for (i = 0; i < 22; i++) { \
        if (i %4 == 0) \
            PRINT("\r\n"); \
        wifi_dc_addr = (ADR_GEMINIA_WF_DCOC_IDAC_REGISTER1)+ (i << 2); \
                                                                                            \
        UDELAY(50); \
        reg_val = REG32_R(wifi_dc_addr); \
        PRINT("addr %x : val %x, ", wifi_dc_addr, reg_val); \
    } \
                                                                                            \
    PRINT("\r\nStart WiFi Rx DC calibration...\r\n"); \
                                                                                            \
                                                                                            \
    SET_RG_GEMINIA_MODE_MANUAL(1); \
    UDELAY(50); \
                                                                                            \
                                                                                            \
    SET_RG_GEMINIA_MODE(6); \
    UDELAY(50); \
                                                                                            \
                                                                                            \
    SET_RG_GEMINIA_CAL_INDEX(1); \
                                                                                            \
    MSLEEP(10); \
                                                                                            \
    PRINT("--------------------------------------------\r\n"); \
    PRINT("--------- Calibration result----------------"); \
    for (i = 0; i < 22; i++) { \
       if (i %4 == 0) \
          PRINT("\r\n"); \
       wifi_dc_addr = (ADR_GEMINIA_WF_DCOC_IDAC_REGISTER1)+ (i << 2); \
       PRINT("addr %x : val %x, ", wifi_dc_addr, REG32_R(wifi_dc_addr)); \
    } \
    PRINT("\r\n"); \
                                                                                            \
    SET_RG_GEMINIA_CAL_INDEX(0); \
    UDELAY(50); \
                                                                                            \
                                                                                            \
    SET_RG_GEMINIA_MODE(1); \
    UDELAY(50); \
                                                                                            \
                                                                                            \
    SET_RG_GEMINIA_MODE_MANUAL(0); \
    UDELAY(50); \
                                                                                            \
                                                                                            \
    SET_RG_GEMINIA_HS_3WIRE_MANUAL(1); \
    UDELAY(50); \
                                                                                            \
                                                                                            \
    SET_RG_GEMINIA_HW_PINSEL(1); \
    UDELAY(50); \
                                                                                            \
                                                                                            \
    SET_REG(ADR_GEMINIA_MANUAL_ENABLE_REGISTER, \
        ((0 << RG_GEMINIA_EN_RX_ADC_SFT) | (1 <<RG_GEMINIA_RX_ADC_MANUAL_SFT)), 0, \
        (RG_GEMINIA_EN_RX_ADC_I_MSK & RG_GEMINIA_RX_ADC_MANUAL_I_MSK)); \
    UDELAY(50); \
} while(0)
#define TU_INIT_GEMINIA_TRX \
do{ \
   int val, mask; \
                                                                                            \
    SET_RG_GEMINIA_LOAD_RFTABLE_RDY(1); \
    UDELAY(50); \
                                                                                            \
                                                                                            \
    SET_RG_GEMINIA_HS_3WIRE_MANUAL(1); \
    UDELAY(50); \
                                                                                            \
                                                                                            \
    SET_RG_GEMINIA_HW_PINSEL(1); \
    UDELAY(50); \
                                                                                            \
                                                                                            \
    SET_RG_GEMINIA_TXGAIN_PHYCTRL(0); \
    UDELAY(50); \
                                                                                            \
                                                                                            \
    SET_RG_GEMINIA_TX_GAIN(3); \
    UDELAY(50); \
                                                                                            \
                                                                                            \
    SET_REG(ADR_GEMINIA_MANUAL_ENABLE_REGISTER, \
        ((0 << RG_GEMINIA_EN_TX_DAC_SFT) | (1 <<RG_GEMINIA_TX_DAC_MANUAL_SFT)), 0, \
        (RG_GEMINIA_EN_TX_DAC_I_MSK & RG_GEMINIA_TX_DAC_MANUAL_I_MSK)); \
    UDELAY(50); \
                                                                                            \
                                                                                            \
    SET_REG(ADR_GEMINIA_MANUAL_ENABLE_REGISTER, \
        ((0 << RG_GEMINIA_EN_RX_ADC_SFT) | (1 <<RG_GEMINIA_RX_ADC_MANUAL_SFT)), 0, \
        (RG_GEMINIA_EN_RX_ADC_I_MSK & RG_GEMINIA_RX_ADC_MANUAL_I_MSK)); \
    UDELAY(50); \
                                                                                            \
                                                                                            \
    SET_RG_GEMINIA_EN_TX_VTOI_2ND(1); \
    UDELAY(50); \
                                                                                            \
                                                                                            \
    SET_RG_GEMINIA_EN_RX_PADSW(1); \
    UDELAY(50); \
                                                                                            \
                                                                                            \
    SET_RG_GEMINIA_SX_FREF_DOUB(0); \
                                                                                            \
    MSLEEP(1); \
                                                                                            \
                                                                                            \
    SET_RG_GEMINIA_PAD_MUX_SEL(1); \
    UDELAY(50); \
                                                                                            \
    val = RG_GEMINIA_GPIO07_OE_MSK|RG_GEMINIA_GPIO06_OE_MSK|RG_GEMINIA_GPIO05_OE_MSK \
         |RG_GEMINIA_GPIO04_OE_MSK|RG_GEMINIA_GPIO03_OE_MSK; \
    mask = RG_GEMINIA_GPIO07_OE_I_MSK&RG_GEMINIA_GPIO06_OE_I_MSK&RG_GEMINIA_GPIO05_OE_I_MSK \
         & RG_GEMINIA_GPIO04_OE_I_MSK & RG_GEMINIA_GPIO03_OE_I_MSK; \
    SET_REG(ADR_GEMINIA_IO_REG_2, val, 0, mask); \
    UDELAY(50); \
    SET_RG_GEMINIA_FPGA_CLK_REF_40M_DS(1); \
    UDELAY(50); \
                                                                                            \
    SET_RG_GEMINIA_FPGA_CLK_REF_40M_OE(1); \
    MSLEEP(1); \
} while(0)
#define LOAD_TURISMOA_RF_TABLE \
do{ \
    u32 i = 0; \
                                                                                            \
    for( i = 0; i < sizeof(ssv6006_turismoA_rf_setting)/sizeof(ssv_cabrio_reg); i++) { \
       REG32_W(ssv6006_turismoA_rf_setting[i].address, \
           ssv6006_turismoA_rf_setting[i].data ); \
       UDELAY(50); \
    } \
} while(0)
#define LOAD_TURISMOA_PHY_TABLE \
do{ \
    u32 i = 0; \
                                                                                            \
    for( i = 0; i < sizeof(ssv6006_turismoA_phy_setting)/sizeof(ssv_cabrio_reg); i++) { \
       REG32_W(ssv6006_turismoA_phy_setting[i].address, \
           ssv6006_turismoA_phy_setting[i].data ); \
    } \
} while(0)
#define TU_SET_TURISMOA_BW(_ch_type) \
do{ \
                                                                                            \
    switch (_ch_type){ \
      case NL80211_CHAN_HT20: \
      case NL80211_CHAN_NO_HT: \
                                                                                            \
            SET_MTX_BLOCKTX_IGNORE_TOMAC_CCA_ED_SECONDARY(1); \
                                                                                            \
            SET_REG(ADR_TURISMO_TRX_MODE_REGISTER, \
                (0 << RG_TURISMO_TRX_BW_HT40_SFT) | (1 << RG_TURISMO_TRX_BW_MANUAL_SFT), 0, \
                (RG_TURISMO_TRX_BW_HT40_I_MSK & RG_TURISMO_TRX_BW_MANUAL_I_MSK)); \
            UDELAY(50); \
                                                                                            \
            SET_REG(ADR_TURISMO_TRX_DIGITAL_ADD_ON_0, \
                (0 << RG_TURISMO_TRX_40M_MODE_SFT) | (0 << RG_TURISMO_TRX_LO_UP_CH_SFT), 0, \
                (RG_TURISMO_TRX_LO_UP_CH_I_MSK & RG_TURISMO_TRX_40M_MODE_I_MSK)); \
            UDELAY(50); \
                                                                                            \
            SET_REG(ADR_WIFI_PHY_COMMON_SYS_REG, \
                (0 << RG_SYSTEM_BW_SFT) | (0 << RG_PRIMARY_CH_SIDE_SFT), 0, \
                (RG_SYSTEM_BW_I_MSK & RG_PRIMARY_CH_SIDE_I_MSK)); \
                                                                                            \
            break; \
                                                                                            \
   case NL80211_CHAN_HT40MINUS: \
                                                                                            \
            SET_MTX_BLOCKTX_IGNORE_TOMAC_CCA_ED_SECONDARY(0); \
                                                                                            \
            SET_REG(ADR_TURISMO_TRX_MODE_REGISTER, \
                (1 << RG_TURISMO_TRX_BW_HT40_SFT) | (1 << RG_TURISMO_TRX_BW_MANUAL_SFT), 0, \
                (RG_TURISMO_TRX_BW_HT40_I_MSK & RG_TURISMO_TRX_BW_MANUAL_I_MSK)); \
            UDELAY(50); \
                                                                                            \
            SET_REG(ADR_TURISMO_TRX_DIGITAL_ADD_ON_0, \
                (1 << RG_TURISMO_TRX_40M_MODE_SFT) | (0 << RG_TURISMO_TRX_LO_UP_CH_SFT), 0, \
                (RG_TURISMO_TRX_LO_UP_CH_I_MSK & RG_TURISMO_TRX_40M_MODE_I_MSK)); \
            UDELAY(50); \
                                                                                            \
            SET_REG(ADR_WIFI_PHY_COMMON_SYS_REG, \
                (1 << RG_SYSTEM_BW_SFT) | (1<< RG_PRIMARY_CH_SIDE_SFT), 0, \
                (RG_SYSTEM_BW_I_MSK & RG_PRIMARY_CH_SIDE_I_MSK)); \
                                                                                            \
            break; \
   case NL80211_CHAN_HT40PLUS: \
                                                                                            \
            SET_MTX_BLOCKTX_IGNORE_TOMAC_CCA_ED_SECONDARY(0); \
                                                                                            \
            SET_REG(ADR_TURISMO_TRX_MODE_REGISTER, \
                (1 << RG_TURISMO_TRX_BW_HT40_SFT) | (1 << RG_TURISMO_TRX_BW_MANUAL_SFT), 0, \
                (RG_TURISMO_TRX_BW_HT40_I_MSK & RG_TURISMO_TRX_BW_MANUAL_I_MSK)); \
            UDELAY(50); \
                                                                                            \
            SET_REG(ADR_TURISMO_TRX_DIGITAL_ADD_ON_0, \
                (1 << RG_TURISMO_TRX_40M_MODE_SFT) | (1 << RG_TURISMO_TRX_LO_UP_CH_SFT), 0, \
                (RG_TURISMO_TRX_LO_UP_CH_I_MSK | RG_TURISMO_TRX_40M_MODE_I_MSK)); \
            UDELAY(50); \
                                                                                            \
            SET_REG(ADR_WIFI_PHY_COMMON_SYS_REG, \
                (1 << RG_SYSTEM_BW_SFT) | (0 << RG_PRIMARY_CH_SIDE_SFT), 0, \
                (RG_SYSTEM_BW_I_MSK & RG_PRIMARY_CH_SIDE_I_MSK)); \
            UDELAY(50); \
                                                                                            \
            break; \
      default: \
            break; \
    } \
    UDELAY(50); \
} while(0)
#define TURISMOA_SET_5G_TXPWR(_ch) \
do{ \
                                                                                            \
                                                                                            \
    u8 pwr_paras[3][7] = {{ 7, 8, 7, 7, 7}, \
                           { 4, 8, 4, 4, 7}, \
                           { 3, 8, 3, 3, 3}}; \
    enum band { FRQ5400LO, FRQ5500LO, FRQ5500HI}; \
    int idx; \
                                                                                            \
    if (_ch <=64) { \
        idx = FRQ5400LO; \
    } else if (_ch < 100) { \
        idx = FRQ5500LO; \
    } else { \
        idx = FRQ5500HI; \
    } \
    SET_RG_TURISMO_TRX_TX_GAIN_MANUAL(1); \
    UDELAY(50); \
                                                                                            \
    SET_REG(ADR_TURISMO_TRX_5G_TX_FE_REGISTER, \
        ((1 << RG_TURISMO_TRX_5G_TXPGA_CAPSW_MANUAL_SFT) | \
         (pwr_paras[idx][0] << RG_TURISMO_TRX_5G_TXPGA_CAPSW_SFT) | \
         (pwr_paras[idx][1] << RG_TURISMO_TRX_5G_PABIAS_CTRL_SFT) | \
         (pwr_paras[idx][2] << RG_TURISMO_TRX_5G_TX_PA1_VCAS_SFT) | \
         (pwr_paras[idx][3] << RG_TURISMO_TRX_5G_TX_PA2_VCAS_SFT) | \
         (pwr_paras[idx][4] << RG_TURISMO_TRX_5G_TX_PA3_VCAS_SFT)), 0, \
        (RG_TURISMO_TRX_5G_TXPGA_CAPSW_MANUAL_I_MSK & RG_TURISMO_TRX_5G_TXPGA_CAPSW_I_MSK & \
         RG_TURISMO_TRX_5G_PABIAS_CTRL_I_MSK & RG_TURISMO_TRX_5G_TX_PA1_VCAS_I_MSK & \
         RG_TURISMO_TRX_5G_TX_PA2_VCAS_I_MSK & RG_TURISMO_TRX_5G_TX_PA3_VCAS_I_MSK)); \
    UDELAY(50); \
                                                                                            \
    SET_REG(ADR_TURISMO_TRX_5G_TX_REGISTER, \
        ((0x3f <<RG_TURISMO_TRX_5G_TXPGA_MAIN_SFT) | \
         (0 << RG_TURISMO_TRX_5G_TXPGA_STEER_SFT) | \
         (2 << RG_TURISMO_TRX_5G_TXMOD_GMCELL_SFT) | \
         (3<< RG_TURISMO_TRX_5G_TX_GAIN_SFT)), 0, \
        ( RG_TURISMO_TRX_5G_TXPGA_MAIN_I_MSK & RG_TURISMO_TRX_5G_TXPGA_STEER_I_MSK & \
          RG_TURISMO_TRX_5G_TXMOD_GMCELL_I_MSK & RG_TURISMO_TRX_5G_TX_GAIN_I_MSK)); \
    UDELAY(50); \
                                                                                            \
    SET_RG_TURISMO_TRX_5G_TX_GAIN(3); \
    UDELAY(50); \
                                                                                            \
    SET_REG(ADR_TURISMO_TRX_2_4G_TX_REGISTER, \
        ((0 << RG_TURISMO_TRX_TX_VTOI_CURRENT_SFT | 3 << RG_TURISMO_TRX_TX_VTOI_GM_SFT)), 0,\
        (RG_TURISMO_TRX_TX_VTOI_CURRENT_I_MSK & RG_TURISMO_TRX_TX_VTOI_GM_I_MSK)); \
    UDELAY(50); \
                                                                                            \
    SET_REG(ADR_TURISMO_TRX_5G_TX_DAC_REGISTER, \
        (( 0 << RG_TURISMO_TRX_5G_TX_DACLPF_ICOARSE_SFT \
        | 0xc << RG_TURISMO_TRX_5G_TX_DAC_QOFFSET_SFT \
        |0xc << RG_TURISMO_TRX_5G_TX_DAC_IOFFSET_SFT)), 0, \
        ( RG_TURISMO_TRX_5G_TX_DACLPF_ICOARSE_I_MSK&RG_TURISMO_TRX_5G_TX_DAC_QOFFSET_I_MSK& \
          RG_TURISMO_TRX_5G_TX_DAC_IOFFSET_I_MSK)); \
    UDELAY(50); \
                                                                                            \
} while(0)
#define TURISMOA_SET_5G_CHANNEL(_ch) \
do{ \
                                                                                            \
    TURISMOA_SET_5G_TXPWR(_ch); \
                                                                                            \
    SET_RG_RF_5G_BAND(1); \
                                                                                            \
                                                                                            \
    SET_RG_MODE_MANUAL(1); \
    UDELAY(50); \
                                                                                            \
                                                                                            \
    SET_RG_SX5GB_RFCH_MAP_EN(1); \
    UDELAY(50); \
                                                                                            \
                                                                                            \
    SET_RG_SX5GB_CHANNEL(_ch); \
    UDELAY(50); \
                                                                                            \
                                                                                            \
    SET_RG_MODE(0); \
    UDELAY(50); \
                                                                                            \
                                                                                            \
    SET_RG_MODE(7); \
    UDELAY(50); \
                                                                                            \
                                                                                            \
    SET_RG_MODE_MANUAL(0); \
    UDELAY(50); \
                                                                                            \
} while(0)
#define TURISMOA_SET_2G_TXPWR \
do{ \
    SET_RG_TURISMO_TRX_TX_GAIN_MANUAL(0); \
    UDELAY(50); \
                                                                                            \
    SET_RG_TURISMO_TRX_TX_GAIN(3); \
    UDELAY(50); \
                                                                                            \
    SET_REG(ADR_TURISMO_TRX_2_4G_TX_REGISTER, \
        ((0 << RG_TURISMO_TRX_TX_VTOI_CURRENT_SFT|1 << RG_TURISMO_TRX_TX_VTOI_GM_SFT)), 0, \
        (RG_TURISMO_TRX_TX_VTOI_CURRENT_I_MSK & RG_TURISMO_TRX_TX_VTOI_GM_I_MSK) ); \
    UDELAY(50); \
} while(0)
#define TURISMOA_SET_2G_CHANNEL(_ch) \
do{ \
                                                                                            \
    TURISMOA_SET_2G_TXPWR; \
                                                                                            \
    SET_RG_RF_5G_BAND(0); \
                                                                                            \
                                                                                            \
    SET_RG_MODE_MANUAL(1); \
    UDELAY(50); \
                                                                                            \
                                                                                            \
    SET_RG_SX_RFCH_MAP_EN(1); \
    UDELAY(50); \
                                                                                            \
                                                                                            \
    SET_RG_SX_CHANNEL(_ch); \
    UDELAY(50); \
                                                                                            \
                                                                                            \
    SET_RG_MODE(0); \
    UDELAY(50); \
                                                                                            \
                                                                                            \
    SET_RG_MODE(3); \
    UDELAY(50); \
                                                                                            \
                                                                                            \
    SET_RG_MODE_MANUAL(0); \
    UDELAY(50); \
                                                                                            \
} while(0)
#define TU_CHANGE_TURISMOA_CHANNEL(_ch,_ch_type) \
do{ \
    const char *chan_type[]={"NL80211_CHAN_NO_HT", \
     "NL80211_CHAN_HT20", \
     "NL80211_CHAN_HT40MINUS", \
     "NL80211_CHAN_HT40PLUS"}; \
                                                                                            \
    PRINT("%s: ch %d, type %s\r\n", __func__, _ch, chan_type[_ch_type]); \
    TU_SET_TURISMOA_BW(_ch_type); \
    if ( _ch <=14 && _ch >=1){ \
        SET_MTX_DUR_RSP_SIFS_G(10); \
     SET_MTX_DUR_RSP_SIFS_G(0); \
     SET_TX2TX_SIFS(13); \
        TURISMOA_SET_2G_CHANNEL( _ch); \
    } else if (_ch >=34){ \
     SET_MTX_DUR_RSP_SIFS_G(16); \
     SET_MTX_DUR_RSP_SIFS_G(6); \
     SET_TX2TX_SIFS(19); \
                                                                                            \
                                                                                            \
        if ((_ch_type == NL80211_CHAN_HT40MINUS)||(_ch_type == NL80211_CHAN_HT40PLUS)){ \
                                                                                            \
            SET_REG(ADR_TURISMO_TRX_DIGITAL_ADD_ON_0, \
                (0 << RG_TURISMO_TRX_40M_MODE_SFT) | (0 << RG_TURISMO_TRX_LO_UP_CH_SFT), 0, \
                (RG_TURISMO_TRX_LO_UP_CH_I_MSK & RG_TURISMO_TRX_40M_MODE_I_MSK)); \
            UDELAY(50); \
                                                                                            \
            if (_ch_type == NL80211_CHAN_HT40MINUS) { \
                _ch = _ch - 2; \
            } else { \
                _ch = _ch + 2; \
            } \
        } \
        TURISMOA_SET_5G_CHANNEL(_ch); \
    } else { \
        PRINT("invalid channel %d\r\n", _ch); \
    } \
} while(0)
#define TU_INIT_TURISMOA_CALI \
do{ \
    int i ; \
    u32 wifi_dc_addr; \
                                                                                            \
                                                                                            \
    SET_RG_TURISMO_TRX_HS_3WIRE_MANUAL(0); \
    UDELAY(50); \
                                                                                            \
                                                                                            \
    SET_RG_TURISMO_TRX_MODE_BY_HS_3WIRE(0); \
    UDELAY(50); \
                                                                                            \
                                                                                            \
    SET_RG_TURISMO_TRX_HW_PINSEL(0); \
    UDELAY(50); \
                                                                                            \
                                                                                            \
    SET_REG(ADR_TURISMO_TRX_2_4G_TRX_MANUAL_ENABLE_REGISTER, \
        ((1 << RG_TURISMO_TRX_EN_RX_ADC_SFT) | (0 <<RG_TURISMO_TRX_RX_ADC_MANUAL_SFT)), 0, \
        (RG_TURISMO_TRX_EN_RX_ADC_I_MSK & RG_TURISMO_TRX_RX_ADC_MANUAL_I_MSK)); \
    UDELAY(50); \
                                                                                            \
                                                                                            \
    SET_RG_TURISMO_TRX_MODE_MANUAL(1); \
    UDELAY(50); \
                                                                                            \
                                                                                            \
    SET_RG_TURISMO_TRX_MODE(1); \
    UDELAY(50); \
                                                                                            \
                                                                                            \
    SET_RG_TURISMO_TRX_CAL_INDEX(1); \
                                                                                            \
    MSLEEP(10); \
                                                                                            \
    PRINT("--------------------------------------------\r\n"); \
    PRINT("--------- 2.4 G Calibration result----------------"); \
    for (i = 0; i < 22; i++) { \
       if (i %4 == 0) \
          PRINT("\r\n"); \
       wifi_dc_addr = (ADR_TURISMO_TRX_WF_DCOC_IDAC_REGISTER1)+ (i << 2); \
       PRINT("addr %x : val %x, ", wifi_dc_addr, REG32_R(wifi_dc_addr)); \
    } \
    PRINT("\r\n"); \
                                                                                            \
    SET_RG_TURISMO_TRX_CAL_INDEX(0); \
    UDELAY(50); \
                                                                                            \
                                                                                            \
    SET_RG_TURISMO_TRX_MODE(0); \
    UDELAY(50); \
                                                                                            \
                                                                                            \
    SET_RG_TURISMO_TRX_MODE(1); \
    UDELAY(50); \
                                                                                            \
                                                                                            \
    SET_RG_TURISMO_TRX_CAL_INDEX(9); \
                                                                                            \
    MSLEEP(10); \
                                                                                            \
    PRINT("--------------------------------------------\r\n"); \
    PRINT("--------- 5 G Calibration result----------------"); \
    for (i = 0; i < 21; i++) { \
       if (i %4 == 0) \
          PRINT("\r\n"); \
       wifi_dc_addr = (ADR_TURISMO_TRX_5G_DCOC_IDAC_REGISTER1)+ (i << 2); \
       PRINT("addr %x : val %x, ", wifi_dc_addr, REG32_R(wifi_dc_addr)); \
    } \
    PRINT("\r\n"); \
                                                                                            \
    SET_RG_TURISMO_TRX_CAL_INDEX(0); \
    UDELAY(50); \
                                                                                            \
                                                                                            \
    SET_RG_TURISMO_TRX_MODE(0); \
    UDELAY(50); \
                                                                                            \
                                                                                            \
    SET_RG_TURISMO_TRX_MODE_MANUAL(0); \
    UDELAY(50); \
                                                                                            \
                                                                                            \
    SET_RG_TURISMO_TRX_HS_3WIRE_MANUAL(1); \
    UDELAY(50); \
                                                                                            \
                                                                                            \
    SET_RG_TURISMO_TRX_MODE_BY_HS_3WIRE(1); \
    UDELAY(50); \
                                                                                            \
    SET_RG_TURISMO_TRX_HW_PINSEL(1); \
    UDELAY(50); \
                                                                                            \
                                                                                            \
    SET_REG(ADR_TURISMO_TRX_2_4G_TRX_MANUAL_ENABLE_REGISTER, \
        ((0 << RG_TURISMO_TRX_EN_RX_ADC_SFT) | (1 <<RG_TURISMO_TRX_RX_ADC_MANUAL_SFT)), 0, \
        (RG_TURISMO_TRX_EN_RX_ADC_I_MSK & RG_TURISMO_TRX_RX_ADC_MANUAL_I_MSK)); \
    UDELAY(50); \
} while(0)
#define TU_INIT_TURISMOA_TRX \
do{ \
   int val, mask; \
                                                                                            \
    SET_RG_TURISMO_TRX_LOAD_RFTABLE_RDY(1); \
    UDELAY(50); \
                                                                                            \
                                                                                            \
    SET_RG_TURISMO_TRX_HS_3WIRE_MANUAL(1); \
    UDELAY(50); \
                                                                                            \
                                                                                            \
    SET_RG_TURISMO_TRX_MODE_BY_HS_3WIRE(1); \
    UDELAY(50); \
                                                                                            \
                                                                                            \
    SET_RG_TURISMO_TRX_HW_PINSEL(1); \
    UDELAY(50); \
                                                                                            \
                                                                                            \
    SET_RG_TURISMO_TRX_TXGAIN_PHYCTRL(0); \
    UDELAY(50); \
                                                                                            \
                                                                                            \
    SET_RG_TURISMO_TRX_TX_GAIN(3); \
    UDELAY(50); \
                                                                                            \
                                                                                            \
    SET_REG(ADR_TURISMO_TRX_2_4G_TRX_MANUAL_ENABLE_REGISTER, \
        ((0 << RG_TURISMO_TRX_EN_TX_DAC_SFT) | (1 <<RG_TURISMO_TRX_TX_DAC_MANUAL_SFT)), 0, \
        (RG_TURISMO_TRX_EN_TX_DAC_I_MSK & RG_TURISMO_TRX_TX_DAC_MANUAL_I_MSK)); \
    UDELAY(50); \
                                                                                            \
                                                                                            \
    SET_REG(ADR_TURISMO_TRX_2_4G_TRX_MANUAL_ENABLE_REGISTER, \
        ((0 << RG_TURISMO_TRX_EN_RX_ADC_SFT) | (1 <<RG_TURISMO_TRX_RX_ADC_MANUAL_SFT)), 0, \
        (RG_TURISMO_TRX_EN_RX_ADC_I_MSK & RG_TURISMO_TRX_RX_ADC_MANUAL_I_MSK)); \
    UDELAY(50); \
                                                                                            \
                                                                                            \
    SET_RG_TURISMO_TRX_EN_TX_VTOI_2ND(1); \
    UDELAY(50); \
                                                                                            \
                                                                                            \
    SET_RG_TURISMO_TRX_EN_RX_PADSW(1); \
    UDELAY(50); \
                                                                                            \
                                                                                            \
    SET_RG_TURISMO_TRX_PAD_MUX_SEL(1); \
    UDELAY(50); \
                                                                                            \
                                                                                            \
    val = RG_TURISMO_TRX_GPIO07_OE_MSK|RG_TURISMO_TRX_GPIO06_OE_MSK \
         |RG_TURISMO_TRX_GPIO05_OE_MSK|RG_TURISMO_TRX_GPIO04_OE_MSK \
         |RG_TURISMO_TRX_GPIO03_OE_MSK; \
    mask = RG_TURISMO_TRX_GPIO07_OE_I_MSK&RG_TURISMO_TRX_GPIO06_OE_I_MSK \
         &RG_TURISMO_TRX_GPIO05_OE_I_MSK&RG_TURISMO_TRX_GPIO04_OE_I_MSK \
         &RG_TURISMO_TRX_GPIO03_OE_I_MSK; \
    SET_REG(ADR_TURISMO_TRX_IO_REG_2, val, 0, mask); \
    UDELAY(50); \
                                                                                            \
    SET_RG_TURISMO_TRX_FPGA_CLK_REF_40M_EN(1); \
    UDELAY(50); \
                                                                                            \
    SET_RG_TURISMO_TRX_GPIO17_DS(1); \
    UDELAY(50); \
                                                                                            \
    SET_RG_TURISMO_TRX_GPIO17_OE(1); \
    MSLEEP(1); \
} while(0)
#define INIT_TURISMOA_SYS \
do{ \
    LOAD_TURISMOA_RF_TABLE; \
    TU_INIT_TURISMOA_TRX; \
    TU_INIT_PLL; \
    REG32_W(ADR_WIFI_PHY_COMMON_ENABLE_REG, 0); \
    LOAD_TURISMOA_PHY_TABLE; \
    TU_INIT_TURISMOA_CALI; \
} while(0)
#define TU_INIT_TURISMOB_PLL \
do{ \
    u32 regval , count = 0; \
                                                                                            \
                                                                                            \
    SET_RG_LOAD_RFTABLE_RDY(0x1); \
    do \
    { \
        MSLEEP(1); \
        regval = REG32_R(ADR_PMU_STATE_REG); \
        count ++ ; \
        if (regval == 0x13) \
            break; \
        if (count > 100){ \
            PRINT(" PLL initial fails \r\n"); \
            break; \
        } \
    } while (1); \
                                                                                            \
    MSLEEP(1); \
                                                                                            \
    REG32_W(ADR_WIFI_PHY_COMMON_SYS_REG, 0x80010000); \
                                                                                            \
    REG32_W(ADR_CLOCK_SELECTION, 0x00000004); \
    MSLEEP(1); \
} while(0)
#define TU_INIT_TURISMOB_CALI_ORG \
do{ \
    int i ; \
    u32 wifi_dc_addr; \
                                                                                            \
                                                                                            \
    SET_RG_MODE_MANUAL(1); \
    UDELAY(50); \
                                                                                            \
                                                                                            \
    SET_RG_MODE(1); \
    UDELAY(50); \
                                                                                            \
                                                                                            \
    SET_RG_CAL_INDEX(1); \
                                                                                            \
    MSLEEP(10); \
                                                                                            \
    PRINT("--------------------------------------------\r\n"); \
    PRINT("--------- 2.4 G Rx DC Calibration result----------------"); \
    for (i = 0; i < 22; i++) { \
       if (i %4 == 0) \
          PRINT("\r\n"); \
       wifi_dc_addr = (ADR_WF_DCOC_IDAC_REGISTER1)+ (i << 2); \
       PRINT("addr %x : val %x, ", wifi_dc_addr, REG32_R(wifi_dc_addr)); \
    } \
    PRINT("\r\n"); \
                                                                                            \
    SET_RG_CAL_INDEX(0); \
    UDELAY(50); \
                                                                                            \
                                                                                            \
    SET_RG_MODE(0); \
    UDELAY(50); \
                                                                                            \
                                                                                            \
    SET_RG_MODE(1); \
    UDELAY(50); \
                                                                                            \
                                                                                            \
    SET_RG_CAL_INDEX(9); \
                                                                                            \
    MSLEEP(10); \
                                                                                            \
    PRINT("--------------------------------------------\r\n"); \
    PRINT("--------- 5 G Rx DC Calibration result----------------"); \
    for (i = 0; i < 21; i++) { \
       if (i %4 == 0) \
          PRINT("\r\n"); \
       wifi_dc_addr = (ADR_5G_DCOC_IDAC_REGISTER1)+ (i << 2); \
       PRINT("addr %x : val %x, ", wifi_dc_addr, REG32_R(wifi_dc_addr)); \
    } \
    PRINT("\r\n"); \
                                                                                            \
    SET_RG_CAL_INDEX(0); \
    UDELAY(50); \
                                                                                            \
                                                                                            \
    SET_RG_MODE(0); \
    UDELAY(50); \
                                                                                            \
    SET_RG_MODE_MANUAL(0); \
    UDELAY(50); \
} while(0)
#define TU_INIT_TURISMOB_2G_CALI_ORG \
do{ \
    int i ; \
    u32 wifi_dc_addr; \
                                                                                            \
                                                                                            \
    SET_RG_MODE_MANUAL(1); \
    UDELAY(50); \
                                                                                            \
                                                                                            \
    SET_RG_MODE(1); \
    UDELAY(50); \
                                                                                            \
                                                                                            \
    SET_RG_CAL_INDEX(1); \
                                                                                            \
    MSLEEP(10); \
                                                                                            \
    PRINT("--------------------------------------------\r\n"); \
    PRINT("--------- 2.4 G Rx DC Calibration result----------------"); \
    for (i = 0; i < 22; i++) { \
       if (i %4 == 0) \
          PRINT("\r\n"); \
       wifi_dc_addr = (ADR_WF_DCOC_IDAC_REGISTER1)+ (i << 2); \
       PRINT("addr %x : val %x, ", wifi_dc_addr, REG32_R(wifi_dc_addr)); \
    } \
    PRINT("\r\n"); \
                                                                                            \
                                                                                            \
    SET_RG_CAL_INDEX(0); \
    UDELAY(50); \
                                                                                            \
                                                                                            \
    SET_RG_MODE(0); \
    UDELAY(50); \
                                                                                            \
    SET_RG_MODE_MANUAL(0); \
    UDELAY(50); \
} while(0)
#define TURISMOB_PRE_CAL \
do { \
                                                                                            \
    SET_RG_MODE_MANUAL(1); \
                                                                                            \
                                                                                            \
    SET_RG_MODE(1); \
} while(0)
#define TURISMOB_POST_CAL \
do { \
                                                                                            \
    SET_RG_MODE(0); \
                                                                                            \
                                                                                            \
    SET_RG_MODE_MANUAL(0); \
} while(0)
#define TURISMOB_2P4G_RXDC_CAL \
do { \
    int i ; \
    u32 wifi_dc_addr; \
                                                                                            \
                                                                                            \
                                                                                            \
                                                                                            \
                                                                                            \
    SET_RG_CAL_INDEX(CAL_IDX_WIFI2P4G_RXDC); \
                                                                                            \
    MSLEEP(10); \
                                                                                            \
    PRINT("--------------------------------------------\r\n"); \
    PRINT("--------- 2.4 G Rx DC Calibration result----------------"); \
    for (i = 0; i < 21; i++) { \
       if (i %4 == 0) \
          PRINT("\r\n"); \
       wifi_dc_addr = (ADR_WF_DCOC_IDAC_REGISTER1)+ (i << 2); \
       PRINT("addr %x : val %x, ", wifi_dc_addr, REG32_R(wifi_dc_addr)); \
    } \
    PRINT("\r\n"); \
                                                                                            \
    SET_RG_CAL_INDEX(0); \
                                                                                            \
                                                                                            \
                                                                                            \
} while(0)
#define TURISMOB_5G_RXDC_CAL \
do{ \
    int i ; \
    u32 wifi_dc_addr; \
                                                                                            \
                                                                                            \
                                                                                            \
                                                                                            \
                                                                                            \
    SET_RG_CAL_INDEX(CAL_IDX_WIFI5G_RXDC); \
                                                                                            \
    MSLEEP(10); \
                                                                                            \
    PRINT("--------------------------------------------\r\n"); \
    PRINT("--------- 5 G Rx DC Calibration result----------------"); \
    for (i = 0; i < 21; i++) { \
       if (i %4 == 0) \
          PRINT("\r\n"); \
       wifi_dc_addr = (ADR_5G_DCOC_IDAC_REGISTER1)+ (i << 2); \
       PRINT("addr %x : val %x, ", wifi_dc_addr, REG32_R(wifi_dc_addr)); \
    } \
    PRINT("\r\n"); \
                                                                                            \
                                                                                            \
    SET_RG_CAL_INDEX(0); \
                                                                                            \
                                                                                            \
                                                                                            \
} while(0)
#define TURISMOB_BW20_RXRC_CAL \
do{ \
    int count = 0; \
                                                                                            \
    PRINT("--------------------------------------------\r\n"); \
    PRINT("Before WiFi BW20 RG_WF_RX_ABBCTUNE: %d\r\n", GET_RG_WF_RX_ABBCTUNE); \
                                                                                            \
    SET_RG_RX_RCCAL_DELAY(2); \
                                                                                            \
    SET_REG(ADR_RF_D_CAL_TOP_6, \
        (0xe5 << RG_RX_RCCAL_TARG_SFT) | (0 << RG_RCCAL_POLAR_INV_SFT), 0, \
        (RG_RX_RCCAL_TARG_I_MSK & RG_RCCAL_POLAR_INV_I_MSK)); \
                                                                                            \
    SET_RG_PGAG_RCCAL(3); \
                                                                                            \
    SET_RG_TONE_SCALE(0x80); \
                                                                                            \
                                                                                            \
                                                                                            \
                                                                                            \
                                                                                            \
    SET_RG_CAL_INDEX(CAL_IDX_BW20_RXRC); \
                                                                                            \
    while (GET_RO_RCCAL_DONE == 0){ \
        count ++; \
        if (count >100) { \
            break; \
        } \
        MSLEEP(1); \
    } \
                                                                                            \
    MSLEEP(10); \
    PRINT("--------------------------------------------%d\r\n", count); \
    PRINT("WiFi BW20 RG_WF_RX_ABBCTUNE CAL RESULT: %d\r\n", GET_RG_WF_RX_ABBCTUNE); \
                                                                                            \
                                                                                            \
    SET_RG_CAL_INDEX(0); \
                                                                                            \
} while(0)
#define TURISMOB_BW40_RXRC_CAL \
do { \
    int count = 0; \
                                                                                            \
                                                                                            \
    PRINT("--------------------------------------------\r\n"); \
    PRINT("Before WiFi BW40 RG_WF_RX_N_ABBCTUNE: %d\r\n", GET_RG_WF_N_RX_ABBCTUNE); \
                                                                                            \
    SET_RG_RX_N_RCCAL_DELAY(2); \
                                                                                            \
    SET_RG_PHASE_2P5M(0x800); \
                                                                                            \
    SET_REG(ADR_RF_D_CAL_TOP_6, \
        (0x197 << RG_RX_RCCAL_40M_TARG_SFT) | (0 << RG_RCCAL_POLAR_INV_SFT), 0, \
        (RG_RX_RCCAL_40M_TARG_I_MSK & RG_RCCAL_POLAR_INV_I_MSK)); \
                                                                                            \
    SET_RG_ALPHA_SEL(2); \
                                                                                            \
    SET_RG_PHASE_35M(0x5800); \
                                                                                            \
    SET_RG_PGAG_RCCAL(3); \
                                                                                            \
    SET_RG_TONE_SCALE(0x80); \
                                                                                            \
                                                                                            \
                                                                                            \
                                                                                            \
                                                                                            \
    SET_RG_CAL_INDEX(CAL_IDX_BW40_RXRC); \
                                                                                            \
    while (GET_RO_RCCAL_DONE == 0){ \
        count ++; \
        if (count >100) { \
            break; \
        } \
        MSLEEP(1); \
    } \
                                                                                            \
    MSLEEP(10); \
    PRINT("--------------------------------------------%d\r\n", count); \
    PRINT("WiFi BW40 RG_WF_N_RX_ABBCTUNE CAL RESULT: %d\r\n", GET_RG_WF_N_RX_ABBCTUNE); \
                                                                                            \
                                                                                            \
    SET_RG_CAL_INDEX(0); \
} while(0)
#define TURISMOB_TXDC_CAL \
do { \
    int count = 0; \
                                                                                            \
                                                                                            \
    PRINT("--------------------------------------------\r\n"); \
    PRINT("Before txdc calibration WiFi 2P4G Tx DAC IOFFSET: %d, QOFFSET %d\r\n", \
         GET_RG_WF_TX_DAC_IOFFSET, GET_RG_WF_TX_DAC_QOFFSET); \
                                                                                            \
    SET_RG_TONE_SCALE(0x80); \
                                                                                            \
    SET_REG(ADR_CALIBRATION_GAIN_REGISTER0, \
        (0x6 << RG_TX_GAIN_TXCAL_SFT) | (0x0 << RG_PGAG_TXCAL_SFT), 0, \
        (RG_TX_GAIN_TXCAL_I_MSK & RG_PGAG_TXCAL_I_MSK)); \
                                                                                            \
    SET_RG_PRE_DC_AUTO(1); \
                                                                                            \
    SET_RG_TX_IQCAL_TIME(1); \
                                                                                            \
    SET_RG_PHASE_1M(0x7FF); \
    SET_RG_PHASE_RXIQ_1M(0x7FF); \
                                                                                            \
    SET_RG_ALPHA_SEL(2); \
                                                                                            \
                                                                                            \
                                                                                            \
                                                                                            \
                                                                                            \
    SET_RG_CAL_INDEX(CAL_IDX_WIFI2P4G_TXLO); \
                                                                                            \
    while (GET_RO_TXDC_DONE == 0){ \
        count ++; \
        if (count >100) { \
            break; \
        } \
        MSLEEP(1); \
    } \
                                                                                            \
    MSLEEP(10); \
    PRINT("--------------------------------------------%d\r\n", count); \
    PRINT("After txdc calibration WiFi 2P4G Tx DAC IOFFSET: %d, QOFFSET %d\r\n", \
         GET_RG_WF_TX_DAC_IOFFSET, GET_RG_WF_TX_DAC_QOFFSET); \
                                                                                            \
                                                                                            \
    SET_RG_CAL_INDEX(0); \
} while(0)
#define TURISMOB_TXIQ_CAL \
do { \
    int count = 0; \
                                                                                            \
                                                                                            \
    PRINT("--------------------------------------------\r\n"); \
    PRINT("before tx iq calibration, tx alpha: %d, tx theta %d\r\n", \
         GET_RO_TX_IQ_ALPHA, GET_RO_TX_IQ_THETA); \
                                                                                            \
    SET_RG_TONE_SCALE(0x80); \
                                                                                            \
    SET_REG(ADR_CALIBRATION_GAIN_REGISTER0, \
        (0x6 << RG_TX_GAIN_TXCAL_SFT) | (0x0 << RG_PGAG_TXCAL_SFT), 0, \
        (RG_TX_GAIN_TXCAL_I_MSK & RG_PGAG_TXCAL_I_MSK)); \
                                                                                            \
    SET_RG_PRE_DC_AUTO(1); \
                                                                                            \
    SET_RG_TX_IQCAL_TIME(1); \
                                                                                            \
    SET_RG_PHASE_1M(0x7FF); \
    SET_RG_PHASE_RXIQ_1M(0x7FF); \
                                                                                            \
    SET_RG_ALPHA_SEL(2); \
                                                                                            \
                                                                                            \
                                                                                            \
                                                                                            \
                                                                                            \
    SET_RG_CAL_INDEX(CAL_IDX_WIFI2P4G_TXIQ); \
                                                                                            \
    while (GET_RO_TXIQ_DONE == 0){ \
        count ++; \
        if (count >100) { \
            break; \
        } \
        MSLEEP(1); \
    } \
                                                                                            \
    MSLEEP(10); \
    PRINT("--------------------------------------------%d\r\n", count); \
    PRINT("After tx iq calibration, tx alpha: %d, tx theta %d\r\n", \
         GET_RO_TX_IQ_ALPHA, GET_RO_TX_IQ_THETA); \
                                                                                            \
                                                                                            \
    SET_RG_CAL_INDEX(0); \
                                                                                            \
} while(0)
#define TURISMOB_RXIQ_CAL \
do { \
    int count = 0; \
                                                                                            \
                                                                                            \
    PRINT("--------------------------------------------\r\n"); \
    PRINT("Before rx iq calibration, rx alpha: %d, rx theta %d\r\n", \
         GET_RO_RX_IQ_ALPHA, GET_RO_RX_IQ_THETA); \
                                                                                            \
    SET_RG_RFG_RXIQCAL(0x0); \
                                                                                            \
    SET_RG_PGAG_RXIQCAL(0x3); \
                                                                                            \
    SET_RG_TX_GAIN_RXIQCAL(0x6); \
                                                                                            \
    SET_RG_TONE_SCALE(0x80); \
                                                                                            \
    SET_RG_PRE_DC_AUTO(1); \
                                                                                            \
    SET_RG_TX_IQCAL_TIME(1); \
                                                                                            \
    SET_RG_PHASE_1M(0x7FF); \
    SET_RG_PHASE_RXIQ_1M(0x7FF); \
                                                                                            \
    SET_RG_ALPHA_SEL(2); \
                                                                                            \
                                                                                            \
                                                                                            \
                                                                                            \
                                                                                            \
    SET_RG_CAL_INDEX(CAL_IDX_WIFI2P4G_RXIQ); \
                                                                                            \
    while (GET_RO_RXIQ_DONE == 0){ \
        count ++; \
        if (count >100) { \
            break; \
        } \
        MSLEEP(1); \
    } \
                                                                                            \
    MSLEEP(10); \
    PRINT("--------------------------------------------%d\r\n", count); \
    PRINT("After rx iq calibration, rx alpha: %d, rx theta %d\r\n", \
         GET_RO_RX_IQ_ALPHA, GET_RO_RX_IQ_THETA); \
                                                                                            \
                                                                                            \
    SET_RG_CAL_INDEX(0); \
                                                                                            \
} while(0)
#define TURISMOB_5G_TXDC_CAL \
do { \
    int count = 0; \
                                                                                            \
    PRINT("--------------------------------------------\r\n"); \
    PRINT("Before 5G txdc calibration WiFi 5G Tx DAC IOFFSET: %d, QOFFSET %d\r\n", \
         GET_RG_5G_TX_DAC_IOFFSET, GET_RG_5G_TX_DAC_QOFFSET); \
                                                                                            \
    SET_RG_TONE_SCALE(0x80); \
                                                                                            \
    SET_REG(ADR_5G_CALIBRATION_TIMER_GAIN_REGISTER, \
        (0xe << RG_5G_TX_GAIN_TXCAL_SFT) | (0x3 << RG_5G_PGAG_TXCAL_SFT), 0, \
        (RG_5G_TX_GAIN_TXCAL_I_MSK & RG_5G_PGAG_TXCAL_I_MSK)); \
                                                                                            \
    SET_RG_PRE_DC_AUTO(1); \
                                                                                            \
    SET_RG_TX_IQCAL_TIME(1); \
                                                                                            \
    SET_RG_PHASE_1M(0x7FF); \
    SET_RG_PHASE_RXIQ_1M(0x7FF); \
                                                                                            \
    SET_RG_ALPHA_SEL(2); \
                                                                                            \
                                                                                            \
                                                                                            \
                                                                                            \
                                                                                            \
    SET_RG_CAL_INDEX(CAL_IDX_WIFI5G_TXLO); \
                                                                                            \
    while (GET_RO_5G_TXDC_DONE == 0){ \
        count ++; \
        if (count >100) { \
            break; \
        } \
        MSLEEP(1); \
    } \
                                                                                            \
    MSLEEP(10); \
    PRINT("--------------------------------------------%d\r\n", count); \
    PRINT("After 5G txdc calibration WiFi 5G Tx DAC IOFFSET: %d, QOFFSET %d\r\n", \
         GET_RG_5G_TX_DAC_IOFFSET, GET_RG_5G_TX_DAC_QOFFSET); \
                                                                                            \
                                                                                            \
    SET_RG_CAL_INDEX(0); \
                                                                                            \
} while(0)
#define TURISMOB_5G_TXIQ_CAL \
{ \
    int count = 0; \
                                                                                            \
                                                                                            \
    PRINT("--------------------------------------------\r\n"); \
    PRINT("before 5G tx iq calibration, tx alpha: %d, tx theta %d\r\n", \
         GET_RO_TX_IQ_ALPHA, GET_RO_TX_IQ_THETA); \
                                                                                            \
    SET_RG_TONE_SCALE(0x80); \
                                                                                            \
    SET_REG(ADR_5G_CALIBRATION_TIMER_GAIN_REGISTER, \
        (0xe << RG_5G_TX_GAIN_TXCAL_SFT) | (0x3 << RG_5G_PGAG_TXCAL_SFT), 0, \
        (RG_5G_TX_GAIN_TXCAL_I_MSK & RG_5G_PGAG_TXCAL_I_MSK)); \
                                                                                            \
    SET_RG_PRE_DC_AUTO(1); \
                                                                                            \
    SET_RG_TX_IQCAL_TIME(1); \
                                                                                            \
    SET_RG_PHASE_1M(0x7FF); \
    SET_RG_PHASE_RXIQ_1M(0x7FF); \
                                                                                            \
    SET_RG_ALPHA_SEL(2); \
                                                                                            \
                                                                                            \
                                                                                            \
                                                                                            \
                                                                                            \
    SET_RG_CAL_INDEX(CAL_IDX_WIFI5G_TXIQ); \
                                                                                            \
    while (GET_RO_5G_TXIQ_DONE == 0){ \
        count ++; \
        if (count >100) { \
            break; \
        } \
        MSLEEP(1); \
    } \
                                                                                            \
    MSLEEP(10); \
    PRINT("--------------------------------------------%d\r\n", count); \
    PRINT("After 5G tx iq calibration, tx alpha: %d, tx theta %d\r\n", \
         GET_RO_TX_IQ_ALPHA, GET_RO_TX_IQ_THETA); \
                                                                                            \
                                                                                            \
    SET_RG_CAL_INDEX(0); \
                                                                                            \
} while(0)
#define TURISMOB_5G_RXIQ_CAL \
do { \
    int count = 0; \
                                                                                            \
                                                                                            \
    PRINT("--------------------------------------------\r\n"); \
    PRINT("Before 5G rx iq calibration, rx alpha: %d, rx theta %d\r\n", \
         GET_RO_RX_IQ_ALPHA, GET_RO_RX_IQ_THETA); \
                                                                                            \
    SET_RG_5G_RFG_RXIQCAL(0x0); \
                                                                                            \
    SET_RG_5G_PGAG_RXIQCAL(0x3); \
                                                                                            \
    SET_RG_5G_TX_GAIN_RXIQCAL(0xe); \
                                                                                            \
    SET_RG_TONE_SCALE(0x80); \
                                                                                            \
    SET_RG_PRE_DC_AUTO(1); \
                                                                                            \
    SET_RG_TX_IQCAL_TIME(1); \
                                                                                            \
    SET_RG_PHASE_1M(0x7FF); \
    SET_RG_PHASE_RXIQ_1M(0x7FF); \
                                                                                            \
                                                                                            \
    SET_RG_ALPHA_SEL(2); \
                                                                                            \
                                                                                            \
                                                                                            \
                                                                                            \
                                                                                            \
    SET_RG_CAL_INDEX(CAL_IDX_WIFI5G_RXIQ); \
                                                                                            \
    while (GET_RO_5G_RXIQ_DONE == 0){ \
        count ++; \
        if (count >100) { \
            break; \
        } \
        MSLEEP(1); \
    } \
                                                                                            \
    MSLEEP(10); \
    PRINT("--------------------------------------------%d\r\n", count); \
    PRINT("After 5G rx iq calibration, rx alpha: %d, rx theta %d\r\n", \
         GET_RO_RX_IQ_ALPHA, GET_RO_RX_IQ_THETA); \
                                                                                            \
                                                                                            \
    SET_RG_CAL_INDEX(0); \
                                                                                            \
} while(0)
#define TU_INIT_TURISMOB_CALI \
do{ \
    TURISMOB_PRE_CAL; \
                                                                                            \
    TURISMOB_2P4G_RXDC_CAL; \
                                                                                            \
    TURISMOB_BW20_RXRC_CAL; \
                                                                                            \
    TURISMOB_BW40_RXRC_CAL; \
                                                                                            \
    TURISMOB_TXDC_CAL; \
                                                                                            \
    TURISMOB_TXIQ_CAL; \
                                                                                            \
    TURISMOB_RXIQ_CAL; \
                                                                                            \
    TURISMOB_5G_RXDC_CAL; \
                                                                                            \
    TURISMOB_5G_TXDC_CAL; \
                                                                                            \
    TURISMOB_5G_TXIQ_CAL; \
                                                                                            \
    TURISMOB_5G_RXIQ_CAL; \
                                                                                            \
    TURISMOB_POST_CAL; \
} while(0)
#define TU_INIT_TURISMOB_2G_CALI \
do{ \
    TURISMOB_PRE_CAL; \
                                                                                            \
    TURISMOB_2P4G_RXDC_CAL; \
                                                                                            \
    TURISMOB_BW20_RXRC_CAL; \
                                                                                            \
    TURISMOB_BW40_RXRC_CAL; \
                                                                                            \
    TURISMOB_TXDC_CAL; \
                                                                                            \
    TURISMOB_TXIQ_CAL; \
                                                                                            \
    TURISMOB_RXIQ_CAL; \
                                                                                            \
    TURISMOB_POST_CAL; \
} while(0)
#define LOAD_TURISMOB_RF_TABLE \
do{ \
    u32 i = 0; \
                                                                                            \
    for( i = 0; i < sizeof(ssv6006_turismoB_rf_setting)/sizeof(ssv_cabrio_reg); i++) { \
       REG32_W(ssv6006_turismoB_rf_setting[i].address, \
           ssv6006_turismoB_rf_setting[i].data ); \
       UDELAY(50); \
    } \
} while(0)
#define LOAD_TURISMOB_PHY_TABLE \
do{ \
    u32 i = 0; \
                                                                                            \
    for( i = 0; i < sizeof(ssv6006_turismoB_phy_setting)/sizeof(ssv_cabrio_reg); i++) { \
       REG32_W(ssv6006_turismoB_phy_setting[i].address, \
           ssv6006_turismoB_phy_setting[i].data ); \
    } \
} while(0)
#define INIT_TURISMOB_SYS(_xtal,_band) \
do{ \
    LOAD_TURISMOB_RF_TABLE; \
    if (_xtal != XTAL26M){ \
        SET_RG_DP_XTAL_FREQ(_xtal); \
        SET_RG_SX_XTAL_FREQ(_xtal); \
    } \
    TU_INIT_TURISMOB_PLL; \
    REG32_W(ADR_WIFI_PHY_COMMON_ENABLE_REG, 0); \
    LOAD_TURISMOB_PHY_TABLE; \
    if (_band == G_BAND_ONLY){ \
        TU_INIT_TURISMOB_2G_CALI; \
    } else { \
        TU_INIT_TURISMOB_CALI; \
    } \
} while(0)
#define TU_SET_TURISMOB_BW(_ch_type) \
do{ \
                                                                                            \
    switch (_ch_type){ \
      case NL80211_CHAN_HT20: \
      case NL80211_CHAN_NO_HT: \
                                                                                            \
            SET_MTX_BLOCKTX_IGNORE_TOMAC_CCA_ED_SECONDARY(1); \
                                                                                            \
            SET_REG(ADR_WIFI_PHY_COMMON_SYS_REG, \
                (0 << RG_PRIMARY_CH_SIDE_SFT) | (0 << RG_SYSTEM_BW_SFT), 0, \
                (RG_PRIMARY_CH_SIDE_I_MSK & RG_SYSTEM_BW_I_MSK)); \
            UDELAY(50); \
                                                                                            \
            SET_REG(ADR_DIGITAL_ADD_ON_0, \
                (0 << RG_40M_MODE_SFT) | (0 << RG_LO_UP_CH_SFT), 0, \
                (RG_40M_MODE_I_MSK & RG_LO_UP_CH_I_MSK)); \
            UDELAY(50); \
                                                                                            \
            break; \
                                                                                            \
   case NL80211_CHAN_HT40MINUS: \
                                                                                            \
            SET_MTX_BLOCKTX_IGNORE_TOMAC_CCA_ED_SECONDARY(0); \
                                                                                            \
            SET_REG(ADR_WIFI_PHY_COMMON_SYS_REG, \
                (1 << RG_PRIMARY_CH_SIDE_SFT) | (1 << RG_SYSTEM_BW_SFT), 0, \
                (RG_PRIMARY_CH_SIDE_I_MSK & RG_SYSTEM_BW_I_MSK)); \
            UDELAY(50); \
                                                                                            \
            SET_REG(ADR_DIGITAL_ADD_ON_0, \
                (1 << RG_40M_MODE_SFT) | (0 << RG_LO_UP_CH_SFT), 0, \
                (RG_40M_MODE_I_MSK & RG_LO_UP_CH_I_MSK)); \
            UDELAY(50); \
                                                                                            \
            break; \
   case NL80211_CHAN_HT40PLUS: \
                                                                                            \
            SET_MTX_BLOCKTX_IGNORE_TOMAC_CCA_ED_SECONDARY(0); \
                                                                                            \
            SET_REG(ADR_WIFI_PHY_COMMON_SYS_REG, \
                (0 << RG_PRIMARY_CH_SIDE_SFT) | (1 << RG_SYSTEM_BW_SFT), 0, \
                (RG_PRIMARY_CH_SIDE_I_MSK & RG_SYSTEM_BW_I_MSK)); \
            UDELAY(50); \
                                                                                            \
            SET_REG(ADR_DIGITAL_ADD_ON_0, \
                (1 << RG_40M_MODE_SFT) | (1 << RG_LO_UP_CH_SFT), 0, \
                (RG_40M_MODE_I_MSK & RG_LO_UP_CH_I_MSK)); \
            UDELAY(50); \
                                                                                            \
            break; \
      default: \
            break; \
    } \
} while(0)
#define TURISMOB_SET_5G_CHANNEL(_ch) \
do{ \
                                                                                            \
    SET_RG_RF_5G_BAND(1); \
                                                                                            \
                                                                                            \
    SET_RG_MODE_MANUAL(1); \
                                                                                            \
                                                                                            \
    SET_RG_SX5GB_RFCH_MAP_EN(1); \
                                                                                            \
                                                                                            \
    SET_RG_SX5GB_CHANNEL(_ch); \
                                                                                            \
                                                                                            \
    SET_RG_MODE(0); \
                                                                                            \
                                                                                            \
    SET_RG_MODE(7); \
                                                                                            \
                                                                                            \
    SET_RG_MODE_MANUAL(0); \
                                                                                            \
} while(0)
#define TURISMOB_SET_2G_CHANNEL(_ch) \
do{ \
    SET_RG_RF_5G_BAND(0); \
                                                                                            \
                                                                                            \
    SET_RG_MODE_MANUAL(1); \
                                                                                            \
                                                                                            \
    SET_RG_SX_RFCH_MAP_EN(1); \
                                                                                            \
                                                                                            \
    SET_RG_SX_CHANNEL(_ch); \
                                                                                            \
                                                                                            \
    SET_RG_MODE(0); \
                                                                                            \
                                                                                            \
    SET_RG_MODE(3); \
                                                                                            \
                                                                                            \
    SET_RG_MODE_MANUAL(0); \
                                                                                            \
} while(0)
#define TU_CHANGE_TURISMOB_CHANNEL(_ch,_ch_type) \
do{ \
    const char *chan_type[]={"NL80211_CHAN_NO_HT", \
     "NL80211_CHAN_HT20", \
     "NL80211_CHAN_HT40MINUS", \
     "NL80211_CHAN_HT40PLUS"}; \
                                                                                            \
    PRINT("%s: ch %d, type %s\r\n", __func__, _ch, chan_type[_ch_type]); \
    TU_SET_TURISMOB_BW(_ch_type); \
    if ( _ch <=14 && _ch >=1){ \
        SET_MTX_DUR_RSP_SIFS_G(10); \
     SET_MTX_DUR_RSP_SIFS_G(0); \
     SET_TX2TX_SIFS(13); \
        TURISMOB_SET_2G_CHANNEL( _ch); \
    } else if (_ch >=34){ \
     SET_MTX_DUR_RSP_SIFS_G(16); \
     SET_MTX_DUR_RSP_SIFS_G(6); \
     SET_TX2TX_SIFS(19); \
        TURISMOB_SET_5G_CHANNEL(_ch); \
    } else { \
        PRINT("invalid channel %d\r\n", _ch); \
    } \
} while(0)
#define TU_INIT_TURISMOC_PLL \
do{ \
    u32 regval , count = 0; \
                                                                                            \
                                                                                            \
    SET_RG_LOAD_RFTABLE_RDY(0x1); \
    do \
    { \
        MSLEEP(1); \
        regval = REG32_R(ADR_PMU_STATE_REG); \
        count ++ ; \
        if (regval == 0x13) \
            break; \
        if (count > 100){ \
            PRINT(" PLL initial fails \r\n"); \
            break; \
        } \
    } while (1); \
                                                                                            \
    MSLEEP(1); \
                                                                                            \
    REG32_W(ADR_WIFI_PHY_COMMON_SYS_REG, 0x80010000); \
                                                                                            \
    REG32_W(ADR_CLOCK_SELECTION, 0x00000008); \
    MSLEEP(1); \
} while(0)
#define LOAD_TURISMOC_RF_TABLE \
do{ \
    u32 i = 0; \
                                                                                            \
    for( i = 0; i < sizeof(ssv6006_turismoC_rf_setting)/sizeof(ssv_cabrio_reg); i++) { \
       REG32_W(ssv6006_turismoC_rf_setting[i].address, \
           ssv6006_turismoC_rf_setting[i].data ); \
       UDELAY(50); \
    } \
} while(0)
#define LOAD_TURISMOC_PHY_TABLE \
do{ \
    u32 i = 0; \
                                                                                            \
    for( i = 0; i < sizeof(ssv6006_turismoC_phy_setting)/sizeof(ssv_cabrio_reg); i++) { \
       REG32_W(ssv6006_turismoC_phy_setting[i].address, \
           ssv6006_turismoC_phy_setting[i].data ); \
    } \
} while(0)
#define TURISMOC_2P4G_RXDC_CAL \
do { \
    int i = 0, j ; \
    u32 wifi_dc_addr; \
    int rg_rfg, rg_pgag; \
    int adc_out_sum_i, adc_out_sumQ; \
                                                                                            \
    SET_REG(ADR_SX_2_4GB_5GB_REGISTER_INT3BIT___CH_TABLE, \
        (0x6 << RG_SX_CHANNEL_SFT) | (0x1 << RG_SX_RFCH_MAP_EN_SFT), 0, \
        (RG_SX_CHANNEL_I_MSK & RG_SX_RFCH_MAP_EN_I_MSK)); \
                                                                                            \
    SET_RG_CAL_INDEX(CAL_IDX_WIFI2P4G_RXDC); \
    UDELAY(100); \
    do { \
        if (GET_RO_WF_DCCAL_DONE == 0) \
            break; \
        i ++; \
        UDELAY(100); \
    } while (i < 100); \
                                                                                            \
    PRINT("--------------------------------------------%d\r\n",i); \
    PRINT("--------- 2.4 G Rx DC Calibration result----------------"); \
    for (i = 0; i < 21; i++) { \
       if (i %4 == 0) \
          PRINT("\r\n"); \
       wifi_dc_addr = (ADR_WF_DCOC_IDAC_REGISTER1)+ (i << 2); \
       PRINT("addr %x : val %x, ", wifi_dc_addr, REG32_R(wifi_dc_addr)); \
    } \
    PRINT("\r\n"); \
                                                                                            \
    SET_RG_RX_GAIN_MANUAL(1); \
                                                                                            \
    for(i = 1;i >= 0; i--){ \
        for(j = 15;j >= 0; j--){ \
            rg_rfg = i; \
            rg_pgag = j; \
            SET_RG_RFG(rg_rfg); \
            SET_RG_PGAG(rg_pgag); \
            adc_out_sum_i = GET_RO_DC_CAL_I; \
            if (adc_out_sum_i>63) { \
                adc_out_sum_i -= 128; \
            } \
            adc_out_sumQ = GET_RO_DC_CAL_Q; \
            if(adc_out_sumQ>63){ \
                adc_out_sumQ -= 128; \
            } \
            PRINT("lna gain is %d, pga gain is %d, ADC_OUT_I is %d, ADC_OUT_Q is %d\r\n", \
               rg_rfg, rg_pgag, adc_out_sum_i, adc_out_sumQ); \
        } \
        PRINT("------------------------------------------------------------\r\n"); \
    } \
                                                                                            \
    SET_RG_RX_GAIN_MANUAL(0); \
                                                                                            \
                                                                                            \
    SET_RG_CAL_INDEX(CAL_IDX_NONE); \
                                                                                            \
                                                                                            \
                                                                                            \
} while (0)
#define TURISMOC_5G_RXDC_CAL \
do { \
    int i = 0, j; \
    u32 wifi_dc_addr; \
    int rg_rfg, rg_pgag; \
    int adc_out_sum_i, adc_out_sumQ; \
                                                                                            \
    SET_REG(ADR_SX_5GB_REGISTER_INT3BIT___CH_TABLE, \
        (100 << RG_SX5GB_CHANNEL_SFT) | (0x1 << RG_SX5GB_RFCH_MAP_EN_SFT), 0, \
        (RG_SX5GB_CHANNEL_I_MSK & RG_SX5GB_RFCH_MAP_EN_I_MSK)); \
                                                                                            \
                                                                                            \
    SET_RG_CAL_INDEX(CAL_IDX_WIFI5G_RXDC); \
    UDELAY(100); \
    do { \
        if (GET_RO_5G_DCCAL_DONE == 0) \
            break; \
        i ++; \
        UDELAY(100); \
    } while (i < 100); \
                                                                                            \
    PRINT("--------------------------------------------%d\r\n",i); \
    PRINT("--------- 5 G Rx DC Calibration result----------------"); \
    for (i = 0; i < 21; i++) { \
       if (i %4 == 0) \
          PRINT("\r\n"); \
       wifi_dc_addr = (ADR_5G_DCOC_IDAC_REGISTER1)+ (i << 2); \
       PRINT("addr %x : val %x, ", wifi_dc_addr, REG32_R(wifi_dc_addr)); \
    } \
    PRINT("\r\n"); \
                                                                                            \
    SET_RG_RX_GAIN_MANUAL(1); \
                                                                                            \
    for(i = 1;i >= 0; i--){ \
        for(j = 15;j >= 0; j--){ \
            rg_rfg = i; \
            rg_pgag = j; \
            SET_RG_RFG(rg_rfg); \
            SET_RG_PGAG(rg_pgag); \
            adc_out_sum_i = GET_RO_DC_CAL_I; \
            if (adc_out_sum_i>63) { \
                adc_out_sum_i -= 128; \
            } \
            adc_out_sumQ = GET_RO_DC_CAL_Q; \
            if(adc_out_sumQ>63){ \
                adc_out_sumQ -= 128; \
            } \
            PRINT("lna gain is %d, pga gain is %d, ADC_OUT_I is %d, ADC_OUT_Q is %d\r\n", \
               rg_rfg, rg_pgag, adc_out_sum_i, adc_out_sumQ); \
        } \
        PRINT("------------------------------------------------------------\r\n"); \
    } \
                                                                                            \
    SET_RG_RX_GAIN_MANUAL(0); \
                                                                                            \
                                                                                            \
    SET_RG_CAL_INDEX(CAL_IDX_NONE); \
                                                                                            \
} while (0)
#define TURISMOC_BW20_RXRC_CAL \
do { \
    int count = 0; \
                                                                                            \
    PRINT("--------------------------------------------\r\n"); \
    PRINT("Before WiFi BW20 RG_WF_RX_ABBCTUNE: %d\r\n", GET_RG_WF_RX_ABBCTUNE); \
                                                                                            \
    SET_RG_RX_RCCAL_DELAY(2); \
                                                                                            \
    SET_RG_PHASE_17P5M(0x20d0); \
                                                                                            \
    SET_REG(ADR_RF_D_CAL_TOP_6, \
        (0x22c << RG_RX_RCCAL_TARG_SFT) | (0 << RG_RCCAL_POLAR_INV_SFT), 0, \
        (RG_RX_RCCAL_TARG_I_MSK & RG_RCCAL_POLAR_INV_I_MSK)); \
                                                                                            \
    SET_RG_ALPHA_SEL(2); \
                                                                                            \
    SET_RG_PGAG_RCCAL(3); \
                                                                                            \
    SET_RG_TONE_SCALE(0x80); \
                                                                                            \
    SET_RG_CAL_INDEX(CAL_IDX_BW20_RXRC); \
                                                                                            \
    UDELAY(100); \
                                                                                            \
    while (GET_RO_RCCAL_DONE == 0){ \
        count ++; \
        if (count >1000) { \
            break; \
        } \
        UDELAY(100); \
    } \
                                                                                            \
    PRINT("--------------------------------------------%d\r\n", count); \
    PRINT("WiFi BW20 RG_WF_RX_ABBCTUNE CAL RESULT: %d\r\n", GET_RG_WF_RX_ABBCTUNE); \
                                                                                            \
                                                                                            \
    SET_RG_CAL_INDEX(CAL_IDX_NONE); \
                                                                                            \
} while (0)
#define TURISMOC_BW40_RXRC_CAL \
do { \
    int count = 0; \
                                                                                            \
                                                                                            \
    PRINT("--------------------------------------------\r\n"); \
    PRINT("Before WiFi BW40 RG_WF_RX_N_ABBCTUNE: %d\r\n", GET_RG_WF_N_RX_ABBCTUNE); \
                                                                                            \
    SET_RG_RX_N_RCCAL_DELAY(2); \
                                                                                            \
    SET_RG_PHASE_35M(0x3fff); \
                                                                                            \
                                                                                            \
    SET_REG(ADR_RF_D_CAL_TOP_6, \
        (0x213 << RG_RX_RCCAL_40M_TARG_SFT) | (0 << RG_RCCAL_POLAR_INV_SFT), 0, \
        (RG_RX_RCCAL_40M_TARG_I_MSK & RG_RCCAL_POLAR_INV_I_MSK)); \
                                                                                            \
    SET_RG_ALPHA_SEL(2); \
                                                                                            \
    SET_RG_PGAG_RCCAL(3); \
                                                                                            \
    SET_RG_TONE_SCALE(0x80); \
                                                                                            \
                                                                                            \
    SET_RG_CAL_INDEX(CAL_IDX_BW40_RXRC); \
    UDELAY(100); \
                                                                                            \
    while (GET_RO_RCCAL_DONE == 0){ \
        count ++; \
        if (count >1000) { \
            break; \
        } \
        UDELAY(100); \
    } \
    if (count >= 1000){ \
        PRINT("%s: cal failed\r\n",__func__); \
    } \
    PRINT("--------------------------------------------%d\r\n", count); \
    PRINT("WiFi BW40 RG_WF_N_RX_ABBCTUNE CAL RESULT: %d\r\n", GET_RG_WF_N_RX_ABBCTUNE); \
                                                                                            \
                                                                                            \
    SET_RG_CAL_INDEX(CAL_IDX_NONE); \
                                                                                            \
} while (0)
#define TURISMOC_TXDC_CAL \
do { \
    int count = 0; \
                                                                                        \
    SET_REG(ADR_SX_2_4GB_5GB_REGISTER_INT3BIT___CH_TABLE, \
        (0x6 << RG_SX_CHANNEL_SFT) | (0x1 << RG_SX_RFCH_MAP_EN_SFT), 0, \
        (RG_SX_CHANNEL_I_MSK & RG_SX_RFCH_MAP_EN_I_MSK)); \
                                                                                        \
    PRINT("--------------------------------------------\r\n"); \
    PRINT("Before txdc calibration WiFi 2P4G Tx DAC IOFFSET: %d, QOFFSET %d\r\n", \
         GET_RG_WF_TX_DAC_IOFFSET, GET_RG_WF_TX_DAC_QOFFSET); \
                                                                                        \
    SET_RG_TXGAIN_PHYCTRL(1); \
                                                                                        \
    SET_REG(ADR_CALIBRATION_GAIN_REGISTER0, \
        (0x6 << RG_TX_GAIN_TXCAL_SFT) | (0x3 << RG_PGAG_TXCAL_SFT), 0, \
        (RG_TX_GAIN_TXCAL_I_MSK & RG_PGAG_TXCAL_I_MSK)); \
                                                                                        \
    SET_RG_TONE_SCALE(0x80); \
                                                                                        \
    SET_RG_PRE_DC_AUTO(1); \
                                                                                        \
    SET_RG_TX_IQCAL_TIME(1); \
                                                                                        \
    SET_RG_PHASE_1M(0x0ccc); \
                                                                                        \
    SET_RG_PHASE_RXIQ_1M(0x0ccc); \
                                                                                        \
    SET_RG_ALPHA_SEL(2); \
                                                                                        \
                                                                                        \
    SET_RG_CAL_INDEX(CAL_IDX_WIFI2P4G_TXLO); \
    UDELAY(100); \
    while (GET_RO_TXDC_DONE == 0){ \
        count ++; \
        if (count >1000) { \
            break; \
        } \
        UDELAY(100); \
    } \
                                                                                        \
    PRINT("--------------------------------------------%d\r\n", count); \
    PRINT("After txdc calibration WiFi 2P4G Tx DAC IOFFSET: %d, QOFFSET %d\r\n", \
         GET_RG_WF_TX_DAC_IOFFSET, GET_RG_WF_TX_DAC_QOFFSET); \
                                                                                        \
                                                                                        \
    SET_RG_CAL_INDEX(CAL_IDX_NONE); \
                                                                                        \
} while(0)
#define TURISMOC_TXIQ_CAL \
do { \
    int count = 0; \
                                                                                        \
    SET_REG(ADR_SX_2_4GB_5GB_REGISTER_INT3BIT___CH_TABLE, \
        (0x6 << RG_SX_CHANNEL_SFT) | (0x1 << RG_SX_RFCH_MAP_EN_SFT), 0, \
        (RG_SX_CHANNEL_I_MSK & RG_SX_RFCH_MAP_EN_I_MSK)); \
                                                                                        \
                                                                                        \
    PRINT("--------------------------------------------\r\n"); \
    PRINT("before tx iq 2.4G calibration, tx alpha: %d, tx theta %d\r\n", \
         GET_RG_TX_IQ_2500_ALPHA, GET_RG_TX_IQ_2500_THETA); \
                                                                                        \
    SET_RG_TXGAIN_PHYCTRL(1); \
                                                                                        \
    SET_REG(ADR_CALIBRATION_GAIN_REGISTER0, \
        (0x6 << RG_TX_GAIN_TXCAL_SFT) | (0x3 << RG_PGAG_TXCAL_SFT), 0, \
        (RG_TX_GAIN_TXCAL_I_MSK & RG_PGAG_TXCAL_I_MSK)); \
                                                                                        \
    SET_RG_TONE_SCALE(0x80); \
                                                                                        \
    SET_RG_PRE_DC_AUTO(1); \
                                                                                        \
    SET_RG_TX_IQCAL_TIME(1); \
                                                                                        \
    SET_RG_PHASE_1M(0xccc); \
    SET_RG_PHASE_RXIQ_1M(0xccc); \
                                                                                        \
    SET_RG_ALPHA_SEL(2); \
                                                                                        \
                                                                                        \
    SET_RG_CAL_INDEX(CAL_IDX_WIFI2P4G_TXIQ); \
    UDELAY(100); \
    while (GET_RO_TXIQ_DONE == 0){ \
        count ++; \
        if (count >1000) { \
            break; \
        } \
        UDELAY(100); \
    } \
    PRINT("--------------------------------------------%d\r\n", count); \
    PRINT("After tx iq calibration, tx alpha: %d, tx theta %d\r\n", \
         GET_RG_TX_IQ_2500_ALPHA, GET_RG_TX_IQ_2500_THETA); \
                                                                                        \
                                                                                        \
    SET_RG_CAL_INDEX(CAL_IDX_NONE); \
} while (0)
#define TURISMOC_RXIQ_CAL \
do { \
    int count = 0; \
    u32 regval, regval1; \
                                                                                        \
    SET_REG(ADR_SX_2_4GB_5GB_REGISTER_INT3BIT___CH_TABLE, \
        (0x6 << RG_SX_CHANNEL_SFT) | (0x1 << RG_SX_RFCH_MAP_EN_SFT), 0, \
        (RG_SX_CHANNEL_I_MSK & RG_SX_RFCH_MAP_EN_I_MSK)); \
                                                                                        \
                                                                                        \
    PRINT("--------------------------------------------\r\n"); \
    PRINT("Before rx iq calibration, rx alpha: %d, rx theta %d\r\n", \
         GET_RG_RX_IQ_2500_ALPHA, GET_RG_RX_IQ_2500_THETA); \
                                                                                        \
    SET_RG_TXGAIN_PHYCTRL(1); \
                                                                                        \
    SET_RG_RFG_RXIQCAL(0x0); \
                                                                                        \
    SET_RG_PGAG_RXIQCAL(0x3); \
                                                                                        \
    SET_RG_TX_GAIN_RXIQCAL(0x6); \
                                                                                        \
    SET_RG_TONE_SCALE(0x80); \
                                                                                        \
    SET_RG_PRE_DC_AUTO(1); \
                                                                                        \
    SET_RG_TX_IQCAL_TIME(1); \
                                                                                        \
    SET_RG_PHASE_1M(0xccc); \
    SET_RG_PHASE_RXIQ_1M(0xccc); \
                                                                                        \
    SET_RG_ALPHA_SEL(2); \
                                                                                        \
                                                                                        \
                                                                                        \
    SET_RG_CAL_INDEX(CAL_IDX_WIFI2P4G_RXIQ); \
    UDELAY(100); \
    while (GET_RO_RXIQ_DONE == 0){ \
        count ++; \
        if (count >1000) { \
            break; \
        } \
        UDELAY(100); \
    } \
                                                                                        \
    SET_RG_PHASE_STEP_VALUE(0xccc); \
    SET_RG_SPECTRUM_EN(1); \
                                                                                        \
    SET_REG(ADR_RF_D_CAL_TOP_7, \
        (0x1 << RG_SPECTRUM_PWR_UPDATE_SFT) | (0x1 << RG_SPECTRUM_LO_FIX_SFT), 0, \
        (RG_SPECTRUM_PWR_UPDATE_I_MSK & RG_SPECTRUM_LO_FIX_I_MSK)); \
                                                                                        \
    UDELAY(10000); \
                                                                                        \
    SET_REG(ADR_RF_D_CAL_TOP_7, \
        (0x0 << RG_SPECTRUM_PWR_UPDATE_SFT) | (0x1 << RG_SPECTRUM_LO_FIX_SFT), 0, \
        (RG_SPECTRUM_PWR_UPDATE_I_MSK & RG_SPECTRUM_LO_FIX_I_MSK)); \
                                                                                        \
    regval1 = GET_RG_SPECTRUM_PWR_UPDATE; \
    regval = GET_RO_SPECTRUM_IQ_PWR_31_0; \
    PRINT("The spectrum power is 0x%x, 0x%x, 0x%x, 0x%x, 0x%x, 0x%x, 0x%x, 0x%x, 0x%x, 0x%x\r\n", \
        ((regval1 >> 4) & 0xf), (regval1 & 0xf), ((regval >> 28) & 0xf), ((regval >> 24) & 0xf), \
        ((regval >> 20) & 0xf), ((regval >> 16) & 0xf), ((regval >> 12) & 0xf), ((regval >> 8) & 0xf), \
        ((regval >> 4) & 0xf), (regval & 0xf)); \
                                                                                                        \
    SET_RG_PHASE_STEP_VALUE(0xF334); \
    SET_RG_SPECTRUM_EN(1); \
                                                                                                        \
    SET_REG(ADR_RF_D_CAL_TOP_7, \
        (0x1 << RG_SPECTRUM_PWR_UPDATE_SFT) | (0x1 << RG_SPECTRUM_LO_FIX_SFT), 0, \
        (RG_SPECTRUM_PWR_UPDATE_I_MSK & RG_SPECTRUM_LO_FIX_I_MSK)); \
                                                                                                        \
    UDELAY(10000); \
                                                                                                        \
    SET_REG(ADR_RF_D_CAL_TOP_7, \
        (0x0 << RG_SPECTRUM_PWR_UPDATE_SFT) | (0x1 << RG_SPECTRUM_LO_FIX_SFT), 0, \
        (RG_SPECTRUM_PWR_UPDATE_I_MSK & RG_SPECTRUM_LO_FIX_I_MSK)); \
                                                                                                        \
    regval1 = GET_RG_SPECTRUM_PWR_UPDATE; \
    regval = GET_RO_SPECTRUM_IQ_PWR_31_0; \
    PRINT("The spectrum power is 0x%x, 0x%x, 0x%x, 0x%x, 0x%x, 0x%x, 0x%x, 0x%x, 0x%x, 0x%x\r\n", \
        ((regval1 >> 4) & 0xf), (regval1 & 0xf), ((regval >> 28) & 0xf), ((regval >> 24) & 0xf), \
        ((regval >> 20) & 0xf), ((regval >> 16) & 0xf), ((regval >> 12) & 0xf), ((regval >> 8) & 0xf), \
        ((regval >> 4) & 0xf), (regval & 0xf)); \
                                                                                                        \
    SET_RG_SPECTRUM_EN(0); \
                                                                                                        \
    PRINT("--------------------------------------------%d\r\n", count); \
    PRINT("After rx iq calibration, rx alpha: %d, rx theta %d\r\n", \
         GET_RG_RX_IQ_2500_ALPHA, GET_RG_RX_IQ_2500_THETA); \
                                                                                                        \
                                                                                                        \
    SET_RG_CAL_INDEX(CAL_IDX_NONE); \
} while(0)
#define TURISMOC_5G_TXDC_CAL \
do{ \
    int count = 0; \
                                                                                            \
    SET_REG(ADR_SX_5GB_REGISTER_INT3BIT___CH_TABLE, \
        (100 << RG_SX5GB_CHANNEL_SFT) | (0x1 << RG_SX5GB_RFCH_MAP_EN_SFT), 0, \
        (RG_SX5GB_CHANNEL_I_MSK & RG_SX5GB_RFCH_MAP_EN_I_MSK)); \
                                                                                            \
    PRINT("--------------------------------------------\r\n"); \
    PRINT("Before 5G txdc calibration WiFi 5G Tx DAC IOFFSET: %d, QOFFSET %d\r\n", \
         GET_RG_5G_TX_DAC_IOFFSET, GET_RG_5G_TX_DAC_QOFFSET); \
                                                                                            \
    SET_RG_TXGAIN_PHYCTRL(1); \
                                                                                            \
    SET_RG_TONE_SCALE(0x80); \
                                                                                            \
    SET_REG(ADR_5G_CALIBRATION_TIMER_GAIN_REGISTER, \
        (0x2 << RG_5G_TX_GAIN_TXCAL_SFT) | (0x3 << RG_5G_PGAG_TXCAL_SFT), 0, \
        (RG_5G_TX_GAIN_TXCAL_I_MSK & RG_5G_PGAG_TXCAL_I_MSK)); \
                                                                                            \
    SET_RG_PRE_DC_AUTO(1); \
                                                                                            \
    SET_RG_TX_IQCAL_TIME(1); \
                                                                                            \
    SET_RG_PHASE_1M(0xCCC); \
    SET_RG_PHASE_RXIQ_1M(0xCCC); \
                                                                                            \
    SET_RG_ALPHA_SEL(2); \
                                                                                            \
                                                                                            \
    SET_RG_CAL_INDEX(CAL_IDX_WIFI5G_TXLO); \
    UDELAY(250); \
    while (GET_RO_5G_TXDC_DONE == 0){ \
        count ++; \
        if (count >1000) { \
            break; \
        } \
        UDELAY(100); \
    } \
    PRINT("--------------------------------------------%d\r\n", count); \
    PRINT("After 5G txdc calibration WiFi 5G Tx DAC IOFFSET: %d, QOFFSET %d\r\n", \
         GET_RG_5G_TX_DAC_IOFFSET, GET_RG_5G_TX_DAC_QOFFSET); \
                                                                                            \
                                                                                            \
    SET_RG_CAL_INDEX(CAL_IDX_NONE); \
} while(0)
#define TURISMOC_5G_TXIQ_CAL \
{ \
    int count = 0; \
    int band; \
                                                                                            \
                                                                                            \
    SET_RG_SX5GB_RFCH_MAP_EN(1); \
                                                                                            \
    PRINT("--------------------------------------------\r\n"); \
    PRINT("before 5G tx iq calibration, tx alpha: %d %d %d %d, tx theta %d %d %d %d\r\n", \
         GET_RG_TX_IQ_5100_ALPHA, GET_RG_TX_IQ_5100_THETA, \
         GET_RG_TX_IQ_5500_ALPHA, GET_RG_TX_IQ_5500_THETA, \
         GET_RG_TX_IQ_5700_ALPHA, GET_RG_TX_IQ_5700_THETA, \
         GET_RG_TX_IQ_5900_ALPHA, GET_RG_TX_IQ_5900_THETA); \
                                                                                            \
    SET_RG_TXGAIN_PHYCTRL(1); \
                                                                                            \
    SET_RG_TONE_SCALE(0x80); \
                                                                                            \
    SET_RG_5G_PGAG_TXCAL(0x3); \
                                                                                            \
    SET_RG_PRE_DC_AUTO(1); \
                                                                                            \
    SET_RG_TX_IQCAL_TIME(1); \
                                                                                            \
    SET_RG_PHASE_1M(0xccc); \
    SET_RG_PHASE_RXIQ_1M(0xccc); \
                                                                                            \
    SET_RG_ALPHA_SEL(2); \
                                                                                            \
    for (band = 0; band < 4; band ++){ \
        SET_RG_SX5GB_CHANNEL(cal_ch_5g[band]); \
                                                                                            \
        if( band == 2 ) { \
            SET_RG_5G_TX_GAIN_TXCAL(0x2); \
        } else { \
            SET_RG_5G_TX_GAIN_TXCAL(0x0); \
        } \
        UDELAY(1); \
                                                                                            \
                                                                                            \
        SET_RG_CAL_INDEX(CAL_IDX_WIFI5G_TXIQ); \
        UDELAY(250); \
        while (GET_RO_5G_TXIQ_DONE == 0){ \
            count ++; \
            if (count >1000) { \
                break; \
            } \
            UDELAY(100); \
        } \
                                                                                            \
        SET_RG_CAL_INDEX(CAL_IDX_NONE); \
    } \
                                                                                            \
    PRINT("--------------------------------------------%d\r\n", count); \
    PRINT("after 5G tx iq calibration, tx alpha: %d %d %d %d, tx theta %d %d %d %d\r\n", \
         GET_RG_TX_IQ_5100_ALPHA, GET_RG_TX_IQ_5100_THETA, \
         GET_RG_TX_IQ_5500_ALPHA, GET_RG_TX_IQ_5500_THETA, \
         GET_RG_TX_IQ_5700_ALPHA, GET_RG_TX_IQ_5700_THETA, \
         GET_RG_TX_IQ_5900_ALPHA, GET_RG_TX_IQ_5900_THETA); \
} while(0)
#define TURISMOC_5G_RXIQ_CAL \
do{ \
    int count = 0; \
    int band; \
    int regval, regval1; \
                                                                                            \
    SET_RG_SX5GB_RFCH_MAP_EN(1); \
    PRINT("--------------------------------------------\r\n"); \
    PRINT("before 5G rx iq calibration, rx alpha: %d %d %d %d, rx theta %d %d %d %d\r\n", \
         GET_RG_RX_IQ_5100_ALPHA, GET_RG_RX_IQ_5100_THETA, \
         GET_RG_RX_IQ_5500_ALPHA, GET_RG_RX_IQ_5500_THETA, \
         GET_RG_RX_IQ_5700_ALPHA, GET_RG_RX_IQ_5700_THETA, \
         GET_RG_RX_IQ_5900_ALPHA, GET_RG_RX_IQ_5900_THETA); \
                                                                                            \
    SET_RG_TXGAIN_PHYCTRL(1); \
                                                                                            \
    SET_RG_5G_RFG_RXIQCAL(0x0); \
                                                                                            \
    SET_RG_5G_PGAG_RXIQCAL(0x3); \
                                                                                            \
    SET_RG_TONE_SCALE(0x80); \
                                                                                            \
    SET_RG_PRE_DC_AUTO(1); \
                                                                                            \
    SET_RG_TX_IQCAL_TIME(1); \
                                                                                            \
    SET_RG_PHASE_1M(0xccc); \
    SET_RG_PHASE_RXIQ_1M(0xccc); \
                                                                                            \
                                                                                            \
    SET_RG_ALPHA_SEL(2); \
                                                                                            \
    for (band = 0; band < 4; band ++){ \
        SET_RG_SX5GB_CHANNEL(cal_ch_5g[band]); \
                                                                                            \
        if( band == 2 ) { \
            SET_RG_5G_TX_GAIN_RXIQCAL(0x2); \
        } else { \
            SET_RG_5G_TX_GAIN_RXIQCAL(0x0); \
        } \
        UDELAY(1); \
                                                                                            \
                                                                                            \
        SET_RG_CAL_INDEX(CAL_IDX_WIFI5G_RXIQ); \
        UDELAY(250); \
        while (GET_RO_5G_RXIQ_DONE == 0){ \
            count ++; \
            if (count >1000) { \
                break; \
            } \
            UDELAY(100); \
        } \
                                                                                            \
        SET_RG_PHASE_STEP_VALUE(0xccc); \
        SET_RG_SPECTRUM_EN(1); \
                                                                                            \
        SET_REG(ADR_RF_D_CAL_TOP_7, \
            (0x1 << RG_SPECTRUM_PWR_UPDATE_SFT) | (0x1 << RG_SPECTRUM_LO_FIX_SFT), 0, \
            (RG_SPECTRUM_PWR_UPDATE_I_MSK & RG_SPECTRUM_LO_FIX_I_MSK)); \
                                                                                            \
        UDELAY(10000); \
                                                                                            \
        SET_REG(ADR_RF_D_CAL_TOP_7, \
            (0x0 << RG_SPECTRUM_PWR_UPDATE_SFT) | (0x1 << RG_SPECTRUM_LO_FIX_SFT), 0, \
            (RG_SPECTRUM_PWR_UPDATE_I_MSK & RG_SPECTRUM_LO_FIX_I_MSK)); \
                                                                                            \
        regval1 = GET_RG_SPECTRUM_PWR_UPDATE; \
        regval = GET_RO_SPECTRUM_IQ_PWR_31_0; \
        PRINT("The spectrum power is 0x%x, 0x%x, 0x%x, 0x%x, 0x%x, 0x%x, 0x%x, 0x%x, 0x%x, 0x%x\r\n", \
            ((regval1 >> 4) & 0xf), (regval1 & 0xf), ((regval >> 28) & 0xf), ((regval >> 24) & 0xf), \
            ((regval >> 20) & 0xf), ((regval >> 16) & 0xf), ((regval >> 12) & 0xf), ((regval >> 8) & 0xf), \
            ((regval >> 4) & 0xf), (regval & 0xf)); \
                                                                                                            \
        SET_RG_PHASE_STEP_VALUE(0xF334); \
        SET_RG_SPECTRUM_EN(1); \
                                                                                                            \
        SET_REG(ADR_RF_D_CAL_TOP_7, \
            (0x1 << RG_SPECTRUM_PWR_UPDATE_SFT) | (0x1 << RG_SPECTRUM_LO_FIX_SFT), 0, \
            (RG_SPECTRUM_PWR_UPDATE_I_MSK & RG_SPECTRUM_LO_FIX_I_MSK)); \
                                                                                                            \
        UDELAY(10000); \
                                                                                                            \
        SET_REG(ADR_RF_D_CAL_TOP_7, \
            (0x0 << RG_SPECTRUM_PWR_UPDATE_SFT) | (0x1 << RG_SPECTRUM_LO_FIX_SFT), 0, \
            (RG_SPECTRUM_PWR_UPDATE_I_MSK & RG_SPECTRUM_LO_FIX_I_MSK)); \
                                                                                                            \
        regval1 = GET_RG_SPECTRUM_PWR_UPDATE; \
        regval = GET_RO_SPECTRUM_IQ_PWR_31_0; \
        PRINT("The spectrum power is 0x%x, 0x%x, 0x%x, 0x%x, 0x%x, 0x%x, 0x%x, 0x%x, 0x%x, 0x%x\r\n", \
            ((regval1 >> 4) & 0xf), (regval1 & 0xf), ((regval >> 28) & 0xf), ((regval >> 24) & 0xf), \
            ((regval >> 20) & 0xf), ((regval >> 16) & 0xf), ((regval >> 12) & 0xf), ((regval >> 8) & 0xf), \
            ((regval >> 4) & 0xf), (regval & 0xf)); \
                                                                                                            \
        SET_RG_SPECTRUM_EN(0); \
                                                                                                            \
                                                                                                            \
        SET_RG_CAL_INDEX(CAL_IDX_NONE); \
    } \
    PRINT("--------------------------------------------%d\r\n", count); \
    PRINT("After 5G rx iq calibration, rx alpha: %d %d %d %d, rx theta %d %d %d %d\r\n", \
         GET_RG_RX_IQ_5100_ALPHA, GET_RG_RX_IQ_5100_THETA, \
         GET_RG_RX_IQ_5500_ALPHA, GET_RG_RX_IQ_5500_THETA, \
         GET_RG_RX_IQ_5700_ALPHA, GET_RG_RX_IQ_5700_THETA, \
         GET_RG_RX_IQ_5900_ALPHA, GET_RG_RX_IQ_5900_THETA); \
} while (0)
#define TU_INIT_TURISMOC_CALI \
do{ \
    REG32_W(ADR_WIFI_PADPD_5G_BB_GAIN_REG, 0x80808080); \
                                                                                            \
    TURISMOB_PRE_CAL; \
                                                                                            \
    TURISMOC_2P4G_RXDC_CAL; \
                                                                                            \
    TURISMOC_BW20_RXRC_CAL; \
                                                                                            \
    TURISMOC_BW40_RXRC_CAL; \
                                                                                            \
    TURISMOC_TXDC_CAL; \
                                                                                            \
    TURISMOC_TXIQ_CAL; \
                                                                                            \
    TURISMOC_RXIQ_CAL; \
                                                                                            \
    TURISMOC_5G_RXDC_CAL; \
                                                                                            \
    TURISMOC_5G_TXDC_CAL; \
                                                                                            \
    TURISMOC_5G_TXIQ_CAL; \
                                                                                            \
    TURISMOC_5G_RXIQ_CAL; \
                                                                                            \
    TURISMOB_POST_CAL; \
} while(0)
#define TU_INIT_TURISMOC_2G_CALI \
do{ \
    TURISMOB_PRE_CAL; \
                                                                                            \
    TURISMOC_2P4G_RXDC_CAL; \
                                                                                            \
    TURISMOC_BW20_RXRC_CAL; \
                                                                                            \
    TURISMOC_BW40_RXRC_CAL; \
                                                                                            \
    TURISMOC_TXDC_CAL; \
                                                                                            \
    TURISMOC_TXIQ_CAL; \
                                                                                            \
    TURISMOC_RXIQ_CAL; \
                                                                                            \
    TURISMOB_POST_CAL; \
} while(0)
#define INIT_TURISMOC_SYS(_patch,_band) \
do{ \
    LOAD_TURISMOC_RF_TABLE; \
    SET_RG_EN_IOTADC_160M(0); \
    SET_RG_DP_XTAL_FREQ(_patch.xtal); \
    SET_RG_SX_XTAL_FREQ(_patch.xtal); \
    TU_INIT_TURISMOC_PLL; \
    REG32_W(ADR_WIFI_PHY_COMMON_ENABLE_REG, 0); \
    LOAD_TURISMOC_PHY_TABLE; \
                                                                                            \
    SET_CLK_DIGI_SEL(_patch.cpu_clk); \
    MSLEEP(1); \
    if (_band == G_BAND_ONLY){ \
        TU_INIT_TURISMOC_2G_CALI; \
    } else { \
        TU_INIT_TURISMOC_CALI; \
    } \
} while(0)
#define TU_SET_TURISMOC_BW(_ch_type) \
do{ \
                                                                                            \
    switch (_ch_type){ \
      case NL80211_CHAN_HT20: \
      case NL80211_CHAN_NO_HT: \
                                                                                            \
            SET_MTX_BLOCKTX_IGNORE_TOMAC_CCA_ED_SECONDARY(1); \
                                                                                            \
            SET_REG(ADR_WIFI_PHY_COMMON_SYS_REG, \
                (0 << RG_PRIMARY_CH_SIDE_SFT) | (0 << RG_SYSTEM_BW_SFT), 0, \
                (RG_PRIMARY_CH_SIDE_I_MSK & RG_SYSTEM_BW_I_MSK)); \
                                                                                            \
            SET_REG(ADR_DIGITAL_ADD_ON_0, \
                (0 << RG_40M_MODE_SFT) | (0 << RG_LO_UP_CH_SFT), 0, \
                (RG_40M_MODE_I_MSK & RG_LO_UP_CH_I_MSK)); \
                                                                                            \
            break; \
                                                                                            \
   case NL80211_CHAN_HT40MINUS: \
                                                                                            \
            SET_MTX_BLOCKTX_IGNORE_TOMAC_CCA_ED_SECONDARY(0); \
                                                                                            \
            SET_REG(ADR_WIFI_PHY_COMMON_SYS_REG, \
                (1 << RG_PRIMARY_CH_SIDE_SFT) | (1 << RG_SYSTEM_BW_SFT), 0, \
                (RG_PRIMARY_CH_SIDE_I_MSK & RG_SYSTEM_BW_I_MSK)); \
                                                                                            \
            SET_REG(ADR_DIGITAL_ADD_ON_0, \
                (1 << RG_40M_MODE_SFT) | (0 << RG_LO_UP_CH_SFT), 0, \
                (RG_40M_MODE_I_MSK & RG_LO_UP_CH_I_MSK)); \
                                                                                            \
            break; \
   case NL80211_CHAN_HT40PLUS: \
                                                                                            \
            SET_MTX_BLOCKTX_IGNORE_TOMAC_CCA_ED_SECONDARY(0); \
                                                                                            \
            SET_REG(ADR_WIFI_PHY_COMMON_SYS_REG, \
                (0 << RG_PRIMARY_CH_SIDE_SFT) | (1 << RG_SYSTEM_BW_SFT), 0, \
                (RG_PRIMARY_CH_SIDE_I_MSK & RG_SYSTEM_BW_I_MSK)); \
                                                                                            \
            SET_REG(ADR_DIGITAL_ADD_ON_0, \
                (1 << RG_40M_MODE_SFT) | (1 << RG_LO_UP_CH_SFT), 0, \
                (RG_40M_MODE_I_MSK & RG_LO_UP_CH_I_MSK)); \
                                                                                            \
            break; \
      default: \
            break; \
    } \
} while(0)
#define TURISMOC_SET_5G_CHANNEL(_ch) \
do{ \
                                                                                            \
    SET_RG_RF_5G_BAND(1); \
                                                                                            \
                                                                                            \
    SET_RG_MODE_MANUAL(1); \
                                                                                            \
                                                                                            \
    SET_RG_SX5GB_RFCH_MAP_EN(1); \
                                                                                            \
                                                                                            \
    SET_RG_SX5GB_CHANNEL(_ch); \
                                                                                            \
                                                                                            \
    SET_RG_MODE(0); \
                                                                                            \
                                                                                            \
    SET_RG_MODE(7); \
                                                                                            \
                                                                                            \
    SET_RG_MODE_MANUAL(0); \
    SET_RG_PHY11B_MD_EN(0); \
} while(0)
#define TURISMOC_SET_2G_CHANNEL(_ch) \
do{ \
    SET_RG_RF_5G_BAND(0); \
                                                                                            \
                                                                                            \
    SET_RG_MODE_MANUAL(1); \
                                                                                            \
                                                                                            \
    SET_RG_SX_RFCH_MAP_EN(1); \
                                                                                            \
                                                                                            \
    SET_RG_SX_CHANNEL(_ch); \
                                                                                            \
                                                                                            \
    SET_RG_MODE(0); \
                                                                                            \
                                                                                            \
    SET_RG_MODE(3); \
                                                                                            \
                                                                                            \
    SET_RG_MODE_MANUAL(0); \
    SET_RG_PHY11B_MD_EN(1); \
} while(0)
#define MULTIPLIER 1024
#define START_PADPD(_val,_pa_band,_init_gain,_ret) \
do { \
    int i, rg_tx_scale, regval; \
    int am, pm; \
    int slope_ini = 0, phase_ini = 0; \
    int padpd_am = 0, padpd_pm = 0; \
    u32 addr_am = 0, addr_pm = 0 , mask_am = 0, mask_pm = 0; \
                                                                                            \
    PRINT("start PA DPD on band %d\r\n", _pa_band); \
    SET_RG_DPD_AM_EN(0); \
    SET_RG_TXGAIN_PHYCTRL(1); \
                                                                                            \
    SET_RG_MODE_MANUAL(1); \
    SET_RG_MODE(MODE_STANDBY); \
    if (_pa_band == 0){ \
        SET_REG(ADR_SX_2_4GB_5GB_REGISTER_INT3BIT___CH_TABLE, \
            (0x6 << RG_SX_CHANNEL_SFT) | (0x1 << RG_SX_RFCH_MAP_EN_SFT), 0, \
        (RG_SX_CHANNEL_I_MSK & RG_SX_RFCH_MAP_EN_I_MSK)); \
        SET_RG_TX_GAIN_DPDCAL(6); \
        SET_RG_PGAG_DPDCAL(_init_gain); \
        SET_RG_RFG_DPDCAL(0); \
        SET_RG_TX_GAIN(PAPDP_GAIN_SETTING_2G); \
        SET_RG_DPD_BB_SCALE_2500(0x80); \
    } else { \
        SET_RG_SX5GB_RFCH_MAP_EN(1); \
        SET_RG_SX5GB_CHANNEL(cal_ch_5g[pa_band-1]); \
                                                                                            \
        SET_RG_5G_PGAG_DPDCAL(_init_gain); \
        SET_RG_5G_RFG_DPDCAL(0); \
                                                                                            \
        switch (_pa_band){ \
            case BAND_5100: \
                SET_RG_5G_TX_PAFB_EN_F0(0); \
                SET_RG_5G_TX_GAIN_F0(PAPDP_GAIN_SETTING); \
                SET_RG_5G_TX_GAIN_DPDCAL(PAPDP_GAIN_SETTING); \
                SET_RG_DPD_BB_SCALE_5100(0x80); \
                break; \
            case BAND_5500: \
                SET_RG_5G_TX_PAFB_EN_F1(0); \
                SET_RG_5G_TX_GAIN_F1(PAPDP_GAIN_SETTING); \
                SET_RG_5G_TX_GAIN_DPDCAL(PAPDP_GAIN_SETTING); \
                SET_RG_DPD_BB_SCALE_5500(0x80); \
                break; \
            case BAND_5700: \
                SET_RG_5G_TX_PAFB_EN_F2(0); \
                SET_RG_5G_TX_GAIN_F2(PAPDP_GAIN_SETTING_F2); \
                SET_RG_5G_TX_GAIN_DPDCAL(PAPDP_GAIN_SETTING_F2); \
                SET_RG_DPD_BB_SCALE_5700(0x80); \
                break; \
            case BAND_5900: \
                SET_RG_5G_TX_PAFB_EN_F3(0); \
                SET_RG_5G_TX_GAIN_F3(PAPDP_GAIN_SETTING); \
                SET_RG_5G_TX_GAIN_DPDCAL(PAPDP_GAIN_SETTING); \
                SET_RG_DPD_BB_SCALE_5900(0x80); \
                break; \
            default: \
                break; \
        } \
    } \
    SET_RG_BB_SIG_EN(1); \
                                                                                            \
    SET_RG_DC_RM_BYP(1); \
                                                                                            \
    SET_RG_TX_IQ_SRC(2); \
    SET_RG_TX_BB_SCALE_MANUAL(1); \
                                                                                            \
    SET_RG_TX_SCALE(0x80); \
    SET_RG_TONE_1_RATE(0xccc); \
    SET_RG_TONE_SEL(1); \
                                                                                            \
    SET_RG_RX_PADPD_TONE_SEL(0); \
    SET_RG_RX_PADPD_DATA_SEL(0); \
    SET_RG_RX_PADPD_LEAKY_FACTOR(7); \
    SET_RG_RX_PADPD_EN(1); \
                                                                                            \
                                                                                            \
    SET_RG_MODE(MODE_CALIBRATION); \
                                                                                            \
    if (_pa_band == 0) { \
       SET_RG_CAL_INDEX(CAL_IDX_WIFI2P4G_PADPD); \
    } else { \
       SET_RG_CAL_INDEX(CAL_IDX_WIFI5G_PADPD); \
    } \
                                                                                            \
    UDELAY(100); \
    for (i = 0; i < MAX_PADPD_TONE; i++) { \
                                                                                            \
        if( i < 6 ){ \
            rg_tx_scale = (i+1)*8; \
        } else { \
            rg_tx_scale = 48+(i-5)*4; \
        } \
        SET_RG_TX_SCALE(rg_tx_scale); \
        UDELAY(10000); \
        SET_RG_RX_PADPD_LATCH(1); \
        UDELAY(50); \
        SET_RG_RX_PADPD_LATCH(0); \
        regval= REG32_R(ADR_WIFI_PADPD_CAL_RX_RO); \
        am = (regval >>16) & 0x1ff; \
        pm = regval & 0x1fff; \
        if ( i == 0) { \
            slope_ini = (am * MULTIPLIER) / rg_tx_scale; \
            phase_ini = pm; \
            PRINT("slope is (%d/%d), initial phase is %d \r\n", slope_ini, MULTIPLIER, pm); \
        } \
        PRINT("tx scale is %d,am-am data is %d, am-pm data is %d\r\n", rg_tx_scale, am, pm);\
        if (am != 0) \
           padpd_am = (512 * rg_tx_scale * slope_ini ) / (am*MULTIPLIER); \
                                                                                            \
        padpd_pm = (phase_ini >= pm) ? (phase_ini - pm) : (phase_ini - pm + 8192); \
                                                                                            \
        PRINT(" index %d, padpd_am 0x%x, padpd_pm 0x%x\n", i, padpd_am, padpd_pm); \
                                                                                            \
        switch (_pa_band){ \
            case BAND_2G: \
                addr_am = padpd_am_table_2G[ (i >> 1)].addr; \
                if (i & 0x1) { \
                    mask_am = padpd_am_table_2G[ (i >> 1)].mask1; \
                } else { \
                    mask_am = padpd_am_table_2G[ (i >> 1)].mask0; \
                } \
                addr_pm = padpd_pm_table_2G[ (i >> 1)].addr; \
                if (i & 0x1) { \
                    mask_pm = padpd_pm_table_2G[ (i >> 1)].mask1; \
                } else { \
                    mask_pm = padpd_pm_table_2G[ (i >> 1)].mask0; \
                } \
                break; \
            case BAND_5100: \
                addr_am = padpd_am_table_5100[ (i >> 1)].addr; \
                if (i & 0x1) { \
                    mask_am = padpd_am_table_5100[ (i >> 1)].mask1; \
                } else { \
                    mask_am = padpd_am_table_5100[ (i >> 1)].mask0; \
                } \
                addr_pm = padpd_pm_table_5100[ (i >> 1)].addr; \
                if (i & 0x1) { \
                    mask_pm = padpd_pm_table_5100[ (i >> 1)].mask1; \
                } else { \
                    mask_pm = padpd_pm_table_5100[ (i >> 1)].mask0; \
                } \
                 break; \
            case BAND_5500: \
                 addr_am = padpd_am_table_5500[ (i >> 1)].addr; \
                if (i & 0x1) { \
                    mask_am = padpd_am_table_5500[ (i >> 1)].mask1; \
                } else { \
                    mask_am = padpd_am_table_5500[ (i >> 1)].mask0; \
                } \
                addr_pm = padpd_pm_table_5500[ (i >> 1)].addr; \
                if (i & 0x1) { \
                    mask_pm = padpd_pm_table_5500[ (i >> 1)].mask1; \
                } else { \
                    mask_pm = padpd_pm_table_5500[ (i >> 1)].mask0; \
                } \
                break; \
            case BAND_5700: \
                addr_am = padpd_am_table_5700[ (i >> 1)].addr; \
                if (i & 0x1) { \
                    mask_am = padpd_am_table_5700[ (i >> 1)].mask1; \
                } else { \
                    mask_am = padpd_am_table_5700[ (i >> 1)].mask0; \
                } \
                addr_pm = padpd_pm_table_5700[ (i >> 1)].addr; \
                if (i & 0x1) { \
                    mask_pm = padpd_pm_table_5700[ (i >> 1)].mask1; \
                } else { \
                    mask_pm = padpd_pm_table_5700[ (i >> 1)].mask0; \
                } \
                break; \
            case BAND_5900: \
                addr_am = padpd_am_table_5900[ (i >> 1)].addr; \
                if (i & 0x1) { \
                    mask_am = padpd_am_table_5900[ (i >> 1)].mask1; \
                } else { \
                    mask_am = padpd_am_table_5900[ (i >> 1)].mask0; \
                } \
                addr_pm = padpd_pm_table_5900[ (i >> 1)].addr; \
                if (i & 0x1) { \
                    mask_pm = padpd_pm_table_5900[ (i >> 1)].mask1; \
                } else { \
                    mask_pm = padpd_pm_table_5900[ (i >> 1)].mask0; \
                } \
                break; \
            default: \
                break; \
        } \
        regval = REG32_R(addr_am); \
        REG32_W(addr_am, (regval & mask_am) | ((padpd_am) << ((i & 0x1)*16)) ); \
        if (i & 0x1){ \
            _val->am[ (i >> 1)] = (regval & mask_am) | ((padpd_am) << ((i & 0x1)*16)); \
        } \
                                                                                            \
        regval = REG32_R(addr_pm); \
        REG32_W(addr_pm, (regval & mask_pm) | ((padpd_pm) << ((i & 0x1)*16)) ); \
                                                                                            \
        if (i & 0x1){ \
            _val->pm[ (i >> 1)] = (regval & mask_pm) | ((padpd_pm) << ((i & 0x1)*16)); \
        } \
        if (am >=510) { \
            *_ret = 1; \
            break; \
        } \
    } \
                                                                                            \
    SET_RG_CAL_INDEX(CAL_IDX_NONE); \
    SET_RG_MODE(MODE_STANDBY); \
    SET_RG_MODE_MANUAL(0); \
                                                                                            \
    SET_RG_BB_SIG_EN(0); \
    SET_RG_DC_RM_BYP(0); \
    SET_RG_TX_IQ_SRC(0); \
    SET_RG_TX_BB_SCALE_MANUAL(0); \
                                                                                            \
    SET_RG_TX_SCALE(0x80); \
                                                                                            \
    SET_RG_TONE_SEL(0); \
                                                                                            \
    SET_RG_RX_PADPD_EN(0); \
                                                                                            \
    switch (_pa_band){ \
        case BAND_2G: \
            SET_RG_DPD_BB_SCALE_2500(DEFAULT_DPD_BBSCALE_2500); \
            break; \
        case BAND_5100: \
            SET_RG_DPD_BB_SCALE_5100(DEFAULT_DPD_BBSCALE_5100); \
            break; \
        case BAND_5500: \
             SET_RG_DPD_BB_SCALE_5500(DEFAULT_DPD_BBSCALE_5500); \
                                                                                            \
            break; \
        case BAND_5700: \
             SET_RG_DPD_BB_SCALE_5700(DEFAULT_DPD_BBSCALE_5700); \
                                                                                            \
            break; \
        case BAND_5900: \
             SET_RG_DPD_BB_SCALE_5900(DEFAULT_DPD_BBSCALE_5900); \
                                                                                            \
            break; \
        default: \
            break; \
    } \
                                                                                            \
                                                                                            \
    SET_RG_DPD_AM_EN(1); \
    SET_RG_TXGAIN_PHYCTRL(0); \
                                                                                            \
} while(0)
#define CHECK_PADPD(_dpd,_ch) \
do { \
    int pa_band = 0, ret = 0; \
    struct ssv6006dpd *val; \
    int *pret = &ret; \
                                                                                            \
                                                                                            \
    if (_ch <=14){ \
        pa_band =0; \
    } else if (_ch < 36) { \
        pa_band = 1; \
    } else if ((_ch >= 36) && (_ch < 100)){ \
        pa_band = 2; \
    } else if ((_ch >= 100) && (_ch < 140)){ \
        pa_band = 3; \
    } else if (_ch >= 140){ \
        pa_band = 4; \
    } \
                                                                                            \
    if ( _dpd->dpd_done[pa_band] == false) { \
        int init_gain = 5; \
                                                                                            \
        SET_RG_DPD_AM_EN(0); \
        PRINT("Start PADPD on band %d ,init gain %d\r\n", pa_band, init_gain); \
        while (1){ \
            ret = 0; \
            val = &dpd->val[pa_band]; \
            START_PADPD(val, pa_band, init_gain, pret); \
            if (!ret){ \
                break; \
            } \
            init_gain--; \
            PRINT("Start PADPD on band %d ,init gain %d\r\n", pa_band, init_gain); \
            if (init_gain < 0) { \
                SET_RG_DPD_AM_EN(0); \
                PRINT("WARNING:PADPD FAIL\r\n"); \
                break; \
            } \
        } \
        _dpd->dpd_done[pa_band] = true; \
    } \
} while(0)
#define TU_CHANGE_TURISMOC_CHANNEL(_ch,_ch_type,_dpd) \
do{ \
    const char *chan_type[]={"NL80211_CHAN_NO_HT", \
     "NL80211_CHAN_HT20", \
     "NL80211_CHAN_HT40MINUS", \
     "NL80211_CHAN_HT40PLUS"}; \
                                                                                            \
    PRINT("%s: ch %d, type %s\r\n", __func__, _ch, chan_type[_ch_type]); \
    if (REG32_R(ADR_WIFI_PHY_COMMON_ENABLE_REG) != 0) { \
                                                                                            \
        CHECK_PADPD(_dpd, _ch); \
    } \
    TU_SET_TURISMOC_BW(_ch_type); \
    if ( _ch <=14 && _ch >=1){ \
        SET_SIFS(10); \
     SET_SIGEXT(6); \
     if ((ch >=13) || ((ch >= 9) && (channel_type == NL80211_CHAN_HT40PLUS))) \
                                                                                         \
         SET_RG_EN_RX_PADSW(1); \
     else \
         SET_RG_EN_RX_PADSW(0); \
        TURISMOC_SET_2G_CHANNEL( _ch); \
    } else if (_ch >=34){ \
     SET_SIFS(16); \
     SET_SIGEXT(0); \
        TURISMOC_SET_5G_CHANNEL(_ch); \
    } else { \
        PRINT("invalid channel %d\r\n", _ch); \
    } \
} while(0)
#endif
