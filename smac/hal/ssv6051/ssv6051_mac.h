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

#ifndef _HALSSV6051_H_
#define _HALSSV6051_H_ 
#define SSV6051_NUM_HW_STA 2
#define PBUF_BASE_ADDR 0x80000000
#define PBUF_ADDR_SHIFT 16
#define PBUF_MapPkttoID(_pkt) (((u32)_pkt&0x0FFF0000)>>PBUF_ADDR_SHIFT)
#define PBUF_MapIDtoPkt(_id) (PBUF_BASE_ADDR|((_id)<<PBUF_ADDR_SHIFT))
struct ssv6051_tx_desc
{
    u32 len:16;
    u32 c_type:3;
    u32 f80211:1;
    u32 qos:1;
    u32 ht:1;
    u32 use_4addr:1;
    u32 RSVD_0:3;
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
    u32 tx_report:1;
    u32 tx_burst:1;
    u32 ack_policy:2;
    u32 aggregation:1;
    u32 RSVD_1:3;
    u32 do_rts_cts:2;
    u32 reason:6;
    u32 payload_offset:8;
    u32 RSVD_4:7;
    u32 RSVD_2:1;
    u32 fCmdIdx:3;
    u32 wsid:4;
    u32 txq_idx:3;
    u32 TxF_ID:6;
    u32 rts_cts_nav:16;
    u32 frame_consume_time:10;
    u32 crate_idx:6;
    u32 drate_idx:6;
    u32 dl_length:12;
    u32 RSVD_3:14;
    u32 RESERVED[8];
    struct fw_rc_retry_params rc_params[SSV62XX_TX_MAX_RATES];
};
struct ssv6051_rx_desc
{
    u32 len:16;
    u32 c_type:3;
    u32 f80211:1;
    u32 qos:1;
    u32 ht:1;
    u32 use_4addr:1;
    u32 l3cs_err:1;
    u32 l4cs_err:1;
    u32 align2:1;
    u32 RSVD_0:2;
    u32 psm:1;
    u32 stype_b5b4:2;
    u32 extra_info:1;
    u32 edca0_used:4;
    u32 edca1_used:5;
    u32 edca2_used:5;
    u32 edca3_used:5;
    u32 mng_used:4;
    u32 tx_page_used:9;
    u32 hdr_offset:8;
    u32 frag:1;
    u32 unicast:1;
    u32 hdr_len:6;
    u32 RxResult:8;
    u32 wildcard_bssid:1;
    u32 RSVD_1:1;
    u32 reason:6;
    u32 payload_offset:8;
    u32 tx_id_used:8;
    u32 fCmdIdx:3;
    u32 wsid:4;
    u32 RSVD_3:3;
    u32 rate_idx:6;
};
struct ssv6051_rxphy_info {
    u32 len:16;
    u32 rsvd0:16;
    u32 mode:3;
    u32 ch_bw:3;
    u32 preamble:1;
    u32 ht_short_gi:1;
    u32 rate:7;
    u32 rsvd1:1;
    u32 smoothing:1;
    u32 no_sounding:1;
    u32 aggregate:1;
    u32 stbc:2;
    u32 fec:1;
    u32 n_ess:2;
    u32 rsvd2:8;
    u32 l_length:12;
    u32 l_rate:3;
    u32 rsvd3:17;
    u32 rsvd4;
    u32 rpci:8;
    u32 snr:8;
    u32 service:16;
};
struct ssv6051_rxphy_info_padding {
u32 rpci:8;
u32 snr:8;
u32 RSVD:16;
};
#endif
