/**
 @file drv_struct_le.h

 @date December 5, 2012, 5:37 am

 @version v5.28.0


  The file contains all tables and regs' struct declaration (little edian)

 ##################################################################################
 It is automatically generated with RegAutoGen, developed by ghu@centecnetworks.com
 Project: GreatBelt
 Creator: ghu@centecnetworks.com
 Date: December 5, 2012, 5:37 am

 The version (v5.28.0) is released
     by jliao@centecnetworks.com
     on June 14, 2012, 4:26 am
     decription: Final Spec update 11

 ##################################################################################
*/
#ifndef _DRV_STRUCT_LE_H_
#define _DRV_STRUCT_LE_H_

#include "sal.h"


struct ms_packet_header_s                                               /* 581 */
{
   uint32 u1_l                                                             :32;

   uint32 u1_m                                                             :32;

   uint32 u1_h                                                             :10;
   uint32 u2                                                               :6;
   uint32 time_stamp_15_0                                                  :16;

   uint32 time_stamp_37_16                                                 :22;
   uint32 u3_l                                                             :10;

   uint32 u3_h                                                             :14;
   uint32 operation_type                                                   :3;
   uint32 ttl                                                              :8;
   uint32 logic_src_port_6_0                                               :7;

   uint32 logic_src_port_13_7                                              :7;
   uint32 fid                                                              :14;
   uint32 oam_use_fid                                                      :1;
   uint32 mac_known                                                        :1;
   uint32 stag_action                                                      :2;
   uint32 keep_old_header                                                  :1;
   uint32 debug_session_en                                                 :1;
   uint32 mac_learning_en                                                :1;
   uint32 bridge_operation                                                 :1;
   uint32 oam_tunnel_en                                                    :1;
   uint32 mux_length_type                                                  :2;

   uint32 src_vlan_ptr                                                     :13;
   uint32 svlan_tpid_index                                                 :2;
   uint32 from_cpu_or_oam                                                  :1;
   uint32 outer_vlan_is_cvlan                                              :1;
   uint32 ingress_edit_en                                                  :1;
   uint32 from_cpu_lm_down_disable                                         :1;
   uint32 dsnexthop_dot_bypass_all                                         :1;
   uint32 bypass_ingress_edit                                              :1;
   uint32 from_fabric                                                      :1;
   uint32 source_port_extender                                             :1;
   uint32 svlan_tag_operation_valid                                        :1;
   uint32 from_cpu_lm_up_disable                                           :1;
   uint32 port_mac_sa_en                                                   :1;
   uint32 next_hop_ext                                                     :1;
   uint32 source_cfi                                                       :1;
   uint32 is_leaf                                                          :1;
   uint32 critical_packet                                                  :1;
   uint32 length_adjust_type_1_0                                           :2;

   uint32 length_adjust_type_2                                             :1;
   uint32 next_hop_ptr                                                     :18;
   uint32 color                                                            :2;
   uint32 src_vlan_id_10_0                                                 :11;

   uint32 src_vlan_id_11                                                   :1;
   uint32 source_port                                                      :16;
   uint32 logic_port_type                                                  :1;
   uint32 header_hash                                                      :8;
   uint32 source_cos                                                       :3;
   uint32 packet_type                                                      :3;

   uint32 priority                                                         :6;
   uint32 dest_map                                                         :18;
   uint32 packet_offset                                                    :8;
};
typedef struct ms_packet_header_s ms_packet_header_t;

struct auto_gen_en_ctl0_s {
   uint32 auto_gen_en0                                                     :1;
   uint32 rsv_0                                                            :31;
};
typedef struct auto_gen_en_ctl0_s auto_gen_en_ctl0_t;

struct auto_gen_en_ctl1_s {
   uint32 auto_gen_en1                                                     :1;
   uint32 rsv_0                                                            :31;
};
typedef struct auto_gen_en_ctl1_s auto_gen_en_ctl1_t;

struct auto_gen_en_ctl2_s {
   uint32 auto_gen_en2                                                     :1;
   uint32 rsv_0                                                            :31;
};
typedef struct auto_gen_en_ctl2_s auto_gen_en_ctl2_t;

struct auto_gen_en_ctl3_s {
   uint32 auto_gen_en3                                                     :1;
   uint32 rsv_0                                                            :31;
};
typedef struct auto_gen_en_ctl3_s auto_gen_en_ctl3_t;

struct auto_gen_pkt_ctl_s {
   uint32 rsv_0                                                    :2;
   uint32 pkts_stats_threshold                                             :6;
   uint32 octets_stats_threshold                                           :6;
   uint32 auto_gen_en                                                      :4;
   uint32 tick_gen_en0                                                     :1;
   uint32 tick_gen_en1                                                     :1;
   uint32 tick_gen_en2                                                     :1;
   uint32 tick_gen_en3                                                     :1;
   uint32 rsv_1                                                            :10;

   uint32 tick_gen_interval0                                               :16;
   uint32 tick_gen_interval1                                               :16;

   uint32 tick_gen_interval2                                               :16;
   uint32 tick_gen_interval3                                               :16;

};
typedef struct auto_gen_pkt_ctl_s auto_gen_pkt_ctl_t;

struct auto_gen_pkt_pkt_cfg_s {
   uint32 rsv_0                                                            :16;
   uint32 pkt_hdr_len                                                      :9;
   uint32 tx_seq_num_en                                                    :1;
   uint32 pattern_type                                                     :3;
   uint32 tx_mode                                                          :1;
   uint32 is_use_period                                                    :1;
   uint32 is_use_timeout                                                   :1;

   uint32 rate_frac_cnt                                                    :16;
   uint32 rate_cnt                                                         :16;

   uint32 repeat_pattern                                                   :32;

   uint32 rate_cnt_cfg                                                     :16;
   uint32 rate_frac_cnt_cfg                                                :16;

   uint32 tx_pkt_size                                                      :14;
   uint32 is_have_end_tlv                                                  :1;
   uint32 seq_num_offset                                                   :7;
   uint32 period_cnt9_0                                                  :10;

   uint32 period_cnt39_10                                                :30;
   uint32 rsv_1                                                            :2;

   uint32 timeoutcnt                                                       :32;

   uint32 tx_pkt_cnt                                                       :32;

   uint32 time_out_cfg                                                     :32;




};
typedef struct auto_gen_pkt_pkt_cfg_s auto_gen_pkt_pkt_cfg_t;

struct auto_gen_pkt_pkt_hdr_s {
   uint32 pkt_hdr_userdata1                                                :32;

   uint32 pkt_hdr_userdata0                                                :32;
};
typedef struct auto_gen_pkt_pkt_hdr_s auto_gen_pkt_pkt_hdr_t;

struct auto_gen_pkt_rx_pkt_stats_s {
   uint32 rx_octets31_0                                                  :32;

   uint32 rx_octets37_32                                                 :6;
   uint32 seq_disorder_cnt                                                :16;
   uint32 seq_num_chk_en                                                   :1;
   uint32 mep_chk                                                          :1;
   uint32 rsv_0                                                            :8;

   uint32 rx_pkts                                                          :32;

   uint32 last_seq_num                                                      :32;

   uint32 slr_tx_fcf                                                       :32;

   uint32 rx_rcl                                                           :32;


};
typedef struct auto_gen_pkt_rx_pkt_stats_s auto_gen_pkt_rx_pkt_stats_t;

struct auto_gen_pkt_tx_pkt_stats_s {
   uint32 tx_pkts                                                          :32;

   uint32 seq_num                                                          :32;

   uint32 tx_octets31_0                                                  :32;

   uint32 tx_octets37_32                                                 :6;
   uint32 is_ack                                                           :1;
   uint32 first_pkt_trigger                                                :1;
   uint32 rsv_0                                                            :24;

   uint32 tx_fcb                                                           :32;


};
typedef struct auto_gen_pkt_tx_pkt_stats_s auto_gen_pkt_tx_pkt_stats_t;

struct dbg_oam_defect_msg_s {
   uint32 valid                                                            :1;
   uint32 mep_index                                                        :14;
   uint32 signal_fail                                                      :1;
   uint32 rmep_index                                                       :14;
   uint32 rsv_0                                                            :2;
};
typedef struct dbg_oam_defect_msg_s dbg_oam_defect_msg_t;

struct dbg_oam_defect_proc_s {
   uint32 valid                                                            :1;
   uint32 mep_index                                                        :14;
   uint32 rmep_index                                                       :14;
   uint32 defect_sub_type                                                  :3;

   uint32 defect_type                                                      :3;
   uint32 rsv_0                                                            :29;
};
typedef struct dbg_oam_defect_proc_s dbg_oam_defect_proc_t;

struct dbg_oam_hdr_adj_s {
   uint32 valid                                                            :1;
   uint32 rsv_0                                                            :17;
   uint32 mep_index                                                        :14;

   ms_packet_header_t packet_header;
};
typedef struct dbg_oam_hdr_adj_s dbg_oam_hdr_adj_t;

struct dbg_oam_hdr_edit_s {
   uint32 valid                                                            :1;
   uint32 rsv_0                                                            :31;

   ms_packet_header_t packet_header;

   uint32 exception                                                        :6;
   uint32 mep_index                                                        :14;
   uint32 rsv_1                                                            :12;

};
typedef struct dbg_oam_hdr_edit_s dbg_oam_hdr_edit_t;

struct dbg_oam_rx_proc_s {
   uint32 valid                                                            :1;
   uint32 mep_index                                                        :14;
   uint32 rmep_index                                                       :14;
   uint32 exception2_0                                                   :3;

   uint32 exception5_3                                                   :3;
   uint32 rsv_0                                                            :29;
};
typedef struct dbg_oam_rx_proc_s dbg_oam_rx_proc_t;


struct ds_bfd_interval_cam_s {
    uint32 tx_interval                                                      :10;
    uint32 rx_interval                                                      :10;
    uint32 is33ms                                                           :1;
    uint32 rsv_0                                                            :11;
};
typedef struct ds_bfd_interval_cam_s ds_bfd_interval_cam_t;

struct ds_aps_bridge_s {
    uint32 working_ucast_id                                                 :12;
    uint32 protecting_ucast_id                                              :12;
    uint32 working_dest_vlan_ptr7_0                                       :8;

    uint32 working_dest_vlan_ptr12_8                                      :5;
    uint32 protecting_dest_vlan_ptr                                         :13;
    uint32 protecting_outer_edit_ptr13_0                                  :14;

    uint32 protecting_outer_edit_ptr17_14                                 :4;
    uint32 working_outer_edit_ptr16_0                                     :17;
    uint32 rsv_0                                                            :11;

    uint32 working_outer_edit_ptr17                                       :1;
    uint32 spme_aps_en                                                      :1;
    uint32 protecting_dest_map                                              :19;
    uint32 protecting_next_aps_bridge_en                                    :1;
    uint32 working_next_aps_bridge_en                                       :1;
    uint32 protecting_en                                                    :1;
    uint32 working_is_link_aggregation                                      :1;
    uint32 link_change_en                                                   :1;
    uint32 protecting_is_link_aggregation                                   :1;
    uint32 protecting_remote_chip                                           :1;
    uint32 protecting_end_local_rep                                         :1;
    uint32 working_dest_map2_0                                            :3;

    uint32 working_dest_map18_3                                           :16;
    uint32 working_remote_chip                                              :1;
    uint32 working_end_local_rep                                            :1;
    uint32 different_nexthop                                                :1;
    uint32 l2_aps_mode                                                      :1;
    uint32 rsv_1                                                            :12;

    uint32 rsv_2                                                            :32;

};
typedef struct ds_aps_bridge_s ds_aps_bridge_t;


struct ds_bfd_mep_s
{

    uint32 mep_type                                                         :3;
    uint32 eth_oam_p2_p_mode                                                :1;
    uint32 active                                                           :1;
    uint32 is_bfd                                                           :1;
    uint32 is_remote                                                        :1;
    uint32 is_up                                                            :1;
    uint32 sf_fail_while                                                    :6;
    uint32 ma_index                                                         :13;
    uint32 ccm_interval                                                     :3;
    uint32 bfd_srcport1_0                                               :2;
    /*uint32 u2.g1.bfd_srcport[1:0]                                           :2;
    uint32 u2.g2.csf_while[1:0]                                             :2;*/

    uint32 bfd_srcport15_2                                                :14;
    /*uint32 u2.g1.bfd_srcport[15:2]                                          :14;
    uint32 u2.g2.csf_while[8:2]                                             :7;
    uint32 u2.g2.csf_type                                                   :3;
    uint32 u2.g2.d_csf                                                      :1;
    uint32 u2.g2.rx_csf_type                                                :3;*/
    uint32 cci_en                                                           :1;
    uint32 hello_while                                                      :10;
    uint32 local_diag                                                       :5;
    uint32 is_csf_en                                                        :1;
    uint32 rx_csf_while0                                                  :1;

    uint32 rx_csf_while12_1                                               :12;
    uint32 actual_min_tx_interval8_0                                      :9;
    uint32 rsv_0                                                            :11;

    uint32 actual_min_tx_interval9                                        :1;
    uint32 desired_min_tx_interval                                          :10;
    uint32 local_disc20_0                                                 :21;

    uint32 local_disc31_21                                                :11;
    uint32 local_stat                                                       :2;
    uint32 is_csf_tx_en                                                     :1;
    uint32 ip_da_l17_0                                                    :18;

    uint32 ip_da_l19_18                                                   :2;
    uint32 dest_map                                                         :18;
    uint32 cc_tx_mode                                                       :1;
    uint32 rsv_1                                                            :11;


};
typedef struct ds_bfd_mep_s ds_bfd_mep_t;

struct ds_bfd_rmep_s {
   uint32 mep_type                                                         :3;
   uint32 eth_oam_p2_p_mode                                                :1;
   uint32 active                                                           :1;
   uint32 is_bfd                                                           :1;
   uint32 is_remote                                                        :1;
   uint32 is_up                                                            :1;
   uint32 sf_fail_while                                                    :6;
   uint32 sf_state                                                         :1;
   uint32 ip_sa16_0                                                :17;
   /*
   uint32 u1.g1.ip_sa[16:0]                                                :17;
   uint32 u1.g2.d_mis_con                                                  :1;
   uint32 u1.g2.d_mis_con_while                                            :4;
   uint32 u1.g2.cv_while                                                   :3;
   uint32 u1.g2.ma_name_index[8:0]                                         :9;
 */

   uint32 ip_sa31_17                                               :15;
   /*
   uint32 u1.g1.ip_sa[31:17]                                               :15;
   uint32 u1.g2.ma_name_index[13:9]                                        :5;
   uint32 u1.g2.ma_id_length_type                                          :2;
   uint32 u1.g2.ccm_interval                                               :3;
  */
   uint32 required_min_rx_interval                                         :10;
   uint32 rsv_0                                                            :1;
   uint32 aps_signal_fail_remote                                           :2;
   uint32 aps_bridge_en                                                    :1;
   uint32 actual_rx_interval2_0                                          :3;

   uint32 actual_rx_interval9_3                                          :7;
   uint32 remote_diag                                                      :5;
   uint32 disc_chk_en                                                      :1;
   uint32 fbit                                                             :1;
   uint32 aps_en                                                           :1;
   uint32 local_defect_mult                                                :4;
   uint32 defect_while1_0                                                :2;
   uint32 rsv_1                                                            :11;

   uint32 defect_while13_2                                               :12;
   uint32 is_cv_en                                                         :1;
   uint32 is_csf_en                                                        :1;
   uint32 defect_mult                                                      :4;
   uint32 first_pkt_rx                                                     :1;
   uint32 remote_disc12_0                                                :13;

   uint32 remote_disc31_13                                               :19;
   uint32 remote_stat                                                      :2;
   uint32 ach_chan_type                                                    :3;
   uint32 is_multi_hop                                                     :1;
   uint32 slow_tx_timer_cfg                                                :2;
   uint32 ip_da_h4_0                                                     :5;

   uint32 ip_da_h11_5                                                    :7;
   uint32 echo_rx_en                                                       :1;
   uint32 d_loc                                                            :1;
   uint32 learn_en                                                         :1;
   uint32 time_negotiation                                                 :1;
   uint32 ip_bfd_ttl                                                       :8;
   uint32 pbit                                                             :1;
   uint32 cc_tx_mode                                                       :1;
   uint32 rsv_2                                                            :11;

};
typedef struct ds_bfd_rmep_s ds_bfd_rmep_t;


struct ds_bfd_slow_interval_cfg_s {
   uint32 rx_slow_interval                                                 :10;
   uint32 tx_slow_interval                                                 :10;
   uint32 rsv_0                                                            :12;
};
typedef struct ds_bfd_slow_interval_cfg_s ds_bfd_slow_interval_cfg_t;

struct ds_bfd_v6_addr_s {
   uint32 addr31_0                                                       :32;

   uint32 addr63_32                                                      :32;

   uint32 addr95_64                                                      :32;

   uint32 addr127_96                                                     :32;
};
typedef struct ds_bfd_v6_addr_s ds_bfd_v6_addr_t;


struct ds_eth_mep_s {

   uint32 mep_type                                                         :3;
   uint32 eth_oam_p2_p_mode                                                :1;
   uint32 active                                                           :1;
   uint32 is_bfd                                                           :1;
   uint32 is_remote                                                        :1;
   uint32 is_up                                                            :1;
   uint32 sf_fail_while                                                    :6;
   uint32 ma_index                                                         :13;
   uint32 ccm_interval                                                     :3;
   uint32 mep_id1_0                                                      :2;

   uint32 mep_id12_2                                                     :11;
   uint32 mep_primary_vid                                                  :12;
   uint32 ma_id_check_disable                                              :1;
   uint32 aps_bridge_en                                                    :1;
   uint32 enable_pm                                                        :1;
   uint32 cci_en                                                           :1;
   uint32 seq_num_en                                                       :1;
   uint32 share_mac_en                                                     :1;
   uint32 ccm_seq_num2_0                                                 :3;

   uint32 ccm_seq_num23_3                                                :21;
   uint32 rsv_0                                                            :11;

   uint32 ccm_seq_num31_24                                               :8;
   uint32 auto_gen_pkt_ptr                                                 :2;
   uint32 p2p_use_uc_da                                                    :1;
   uint32 d_meg_lvl_timer                                                  :4;
   uint32 d_mismerge_timer                                                 :4;
   uint32 d_unexp_mep_timer                                                :4;
   uint32 port_id                                                          :8;
   uint32 d_meg_lvl                                                        :1;

   uint32 d_mismerge                                                       :1;
   uint32 d_unexp_mep                                                      :1;
   uint32 tpid_type                                                        :2;
   uint32 present_rdi                                                      :1;
   uint32 rmep_last_rdi                                                    :1;
   uint32 port_status                                                      :2;
   uint32 present_traffic_check_en                                         :1;
   uint32 present_traffic                                                  :1;
   uint32 auto_gen_en                                                      :1;
   uint32 cci_while                                                        :3;
   uint32 dest_map                                                         :18;

   uint32 aps_signal_fail_local                                            :3;
   uint32 learn_en                                                         :1;
   uint32 unknown_ccm_num                                                   :3;
   uint32 rsv_1                                                            :25;

};
typedef struct ds_eth_mep_s ds_eth_mep_t;


struct ds_eth_rmep_s {
   uint32 mep_type                                                         :3;
   uint32 eth_oam_p2_p_mode                                                :1;
   uint32 active                                                           :1;
   uint32 is_bfd                                                           :1;
   uint32 is_remote                                                        :1;
   uint32 is_up                                                            :1;
   uint32 sf_fail_while                                                    :6;
   uint32 sf_state                                                         :1;
   uint32 mep_index                                                  :14;
   /*uint32 u3.g1.mep_index                                                  :14;
   uint32 u3.g2.mep_id                                                     :13;*/
   uint32 rmepmacmismatch                                                  :1;
   uint32 seq_num_en                                                       :1;
   uint32 rmep_mac_sa0                                                   :1;

   uint32 rmep_mac_sa32_1                                                :32;

   uint32 rmep_mac_sa47_33                                               :15;
   uint32 mac_status_change                                                :1;
   uint32 is_csf_en                                                        :1;
   uint32 ccm_seq_num3_0                                           :4;
   /*uint32 u1.g1.ccm_seq_num[3:0]                                           :4;
   uint32 u1.g2.csf_while[3:0]                                             :4;*/
   uint32 rsv_0                                                            :11;

   uint32 ccm_seq_num31_4                                          :28;
   /*uint32 u1.g1.ccm_seq_num[31:4]                                          :28;
   uint32 u1.g2.csf_while[8:4]                                             :5;
   uint32 u1.g2.csf_type                                                   :3;
   uint32 u1.g2.is_csf_tx_en                                               :1;
   uint32 u1.g2.rx_csf_type                                                :3;
   uint32 u1.g2.rx_csf_while                                               :13;
   uint32 u1.g2.d_csf                                                      :1;
   uint32 u1.g2.is_csf_use_uc_da                                           :1;*/
   uint32 aps_signal_fail_remote3_0                                      :4;

   uint32 aps_signal_fail_remote4                                        :1;
   uint32 cnt_shift_while                                                  :3;
   uint32 exp_ccm_num                                                      :8;
   uint32 d_loc                                                            :1;
   uint32 d_unexp_period_timer                                             :4;
   uint32 d_unexp_period                                                   :1;
   uint32 rmep_last_rdi                                                    :1;
   uint32 rmep_while                                                       :4;
   uint32 mac_addr_update_disable                                          :1;
   uint32 seq_num_fail_counter                                             :6;
   uint32 rmep_last_port_status                                            :2;

   uint32 first_pkt_rx                                                     :1;
   uint32 rmep_last_intf_status                                            :3;
   uint32 rsv_1                                                            :28;

};
typedef struct ds_eth_rmep_s ds_eth_rmep_t;

struct ds_link_aggregate_group_s {
   uint32 link_agg_mem_num                                                 :5;
   uint32 link_agg_port_member_ptr                                         :5;
   uint32 link_agg_mem_base                                                :10;
   uint32 link_agg_flow_num                                                :2;
   uint32 link_agg_port_remap_en                                           :1;
   uint32 rsv_0                                                            :9;
};
typedef struct ds_link_aggregate_group_s ds_link_aggregate_group_t;

struct ds_link_aggregate_member_s {
   uint32 dest_channel_id                                                  :7;
   uint32 dest_queue                                                       :9;
   uint32 dest_chip_id                                                     :5;
   uint32 active                                                           :1;
   uint32 old_ts                                                           :8;
   uint32 rsv_0                                                            :2;
};
typedef struct ds_link_aggregate_member_s ds_link_aggregate_member_t;

struct ds_ma_s {
   uint32 next_hop_ptr                                               :18;
   /*uint32 u1.g1.next_hop_ptr                                               :18;
   uint32 u1.g2.vrfid                                                      :14;
   uint32 u1.g3.src_vlan_ptr                                               :13;*/
   uint32 sf_fail_while_cfg_type                                           :1;
   uint32 aps_en                                                           :1;
   uint32 linkoam                                                          :1;
   uint32 ma_name_len                                                      :6;
   uint32 md_lvl                                                           :3;
   uint32 tx_with_if_status                                                :1;
   uint32 rx_oam_type0                                                   :1;

   uint32 rx_oam_type3_1                                                 :3;
   uint32 use_vrfid_lkup                                                   :1;
   uint32 tx_with_port_status                                              :1;
   uint32 tx_with_send_id                                                  :1;
   uint32 mpls_ttl                                                         :8;
   uint32 ma_name_index                                                    :14;
   uint32 priority_index                                                   :3;
   uint32 tx_untagged_oam                                                  :1;

   uint32 ma_id_length_type                                                :2;
   uint32 mpls_label_valid                                                 :4;
   uint32 next_hop_ext                                                     :1;
   uint32 packet_type                                                      :3;
   uint32 csf_time_idx                                                     :3;
   uint32 protecting_path                                                  :1;
   uint32 csf_interval                                                     :3;
   uint32 sf_state                                                         :1;
   uint32 ipv6_hdr                                                         :1;
   uint32 tunnel_aps_en                                                    :1;
   uint32 use_oam_exp                                                      :1;
   uint32 rsv_0                                                            :11;

};
typedef struct ds_ma_s ds_ma_t;


struct ds_ma_name_s {
    uint32 ma_id_umc0                                              :32;

    uint32 ma_id_umc1                                             :32;

    uint32 rsv_0                                                    :32;

};
typedef struct ds_ma_name_s ds_ma_name_t;

struct ds_oam_defect_status_s {
   uint32 defect_status                                                    :32;
};
typedef struct ds_oam_defect_status_s ds_oam_defect_status_t;

struct ds_oam_excp_s {
   uint32 next_hop_ptr                                                     :18;
   uint32 priority                                                         :6;
   uint32 dest_map7_0                                                :8;

   uint32 dest_map17_8                                               :10;
   uint32 rsv_0                                                            :22;

};
typedef struct ds_oam_excp_s ds_oam_excp_t;


struct ds_port_property_s {
   uint32 mac_sa_byte31_0                                                :32;

   uint32 mac_sa_byte47_32                                               :16;
   uint32 if_status                                                        :3;
   uint32 rsv_0                                                            :13;
};
typedef struct ds_port_property_s ds_port_property_t;

struct ds_priority_map_s {
   uint32 priority                                                         :6;
   uint32 cos                                                              :3;
   uint32 color                                                            :2;
   uint32 rsv_0                                                            :21;
};
typedef struct ds_priority_map_s ds_priority_map_t;

struct oam_defect_cache_s {
   uint32 scan_ptr                                                         :9;
   uint32 rsv_0                                                            :23;
};
typedef struct oam_defect_cache_s oam_defect_cache_t;

struct oam_error_defect_ctl_s {
   uint32 report_defect_en31_0                                           :32;

   uint32 report_defect_en63_32                                          :32;

   uint32 scan_defect_interval                                             :32;

   uint32 cache_entry_valid                                                :16;
   uint32 max_ptr                                                          :8;
   uint32 min_ptr                                                          :8;

   uint32 defect_cache_threshold                                           :4;
   uint32 stop_on_max_ptr                                                  :1;
   uint32 scan_en                                                          :1;
   uint32 rsv_0                                                            :26;
};
typedef struct oam_error_defect_ctl_s oam_error_defect_ctl_t;

struct oam_ether_cci_ctl_s {
   uint32 quater_bfd_interval                                              :16;
   uint32 relative_cci7_interval                                           :4;
   uint32 relative_cci6_interval                                           :4;
   uint32 relative_cci5_interval                                           :4;
   uint32 relative_cci4_interval                                           :4;

   uint32 relative_cci3_interval                                           :4;
   uint32 quater_cci2_interval                                             :22;
   uint32 rsv_0                                                            :6;
};
typedef struct oam_ether_cci_ctl_s oam_ether_cci_ctl_t;

struct oam_ether_send_id_s {
   uint32 send_id_byte11to14                                               :32;

   uint32 send_id_byte7to10                                                :32;

   uint32 send_id_byte3to6                                                 :32;

   uint32 send_id_byte0to2                                                 :24;
   uint32 send_id_length                                                   :4;
   uint32 rsv_0                                                            :4;
};
typedef struct oam_ether_send_id_s oam_ether_send_id_t;

struct oam_ether_tx_ctl_s {

   uint32 egr_rb_mac_da31_0                                              :32;

   uint32 egr_rb_mac_da47_32                                             :16;
   uint32 iloop_chan_id                                                    :16;

   uint32 bfd_udp_dst_port                                                 :16;
   uint32 bfd_multi_hop_udp_dst_port                                       :16;

   uint32 ach_y1731_chan_type                                              :16;
   uint32 rsv_0                                                            :16;

   uint32 ach_header_l                                                     :16;
   uint32 tx_bridge_mac15_0                                              :16;

   uint32 tx_bridge_mac47_16                                             :32;

   uint32 rsv_1                                                            :16;
   uint32 tpid3                                                            :16;

   uint32 tpid2                                                            :16;
   uint32 tpid1                                                            :16;

   uint32 tpid0                                                            :16;
   uint32 ccm_ether_type                                                   :16;

   uint32 oam_drop_port                                                    :12;
   uint32 rsv_2                                                            :4;
   uint32 cfm_mcast_addr15_0                                             :16;

   uint32 cfm_mcast_addr44_16                                            :29;
   uint32 rsv_3                                                            :3;

   uint32 oam_chip_id                                                      :5;
   uint32 rsv_4                                                            :11;
   uint32 user_vlan_ptr                                                    :13;
   uint32 rsv_5                                                            :3;

   uint32 lkup_link_agg_mem                                                :1;
   uint32 ccm_first_tlv_offset                                             :8;
   uint32 ccm_version                                                      :5;
   uint32 ccm_opcode                                                       :8;
   uint32 oam_port_id                                                      :8;
   uint32 rsv_6                                                            :1;
   uint32 critical_pkt                                                     :1;

   uint32 linkagg_dest_id15_9                                              :7;
   uint32 tx_ccm_by_epe                                                    :1;
   uint32 bridge_nexthop_ptr                                               :18;
   uint32 cc_interval_use33ms                                              :1;
   uint32 rsv_7                                                            :5;

   uint32 echo_interval                                                    :32;


};
typedef struct oam_ether_tx_ctl_s oam_ether_tx_ctl_t;

struct oam_header_adjust_ctl_s {
   uint32 oam_pdu_bypass_oam_engine                                        :16;
   uint32 relay_all_to_cpu                                                 :1;
   uint32 rsv_0                                                            :15;

};
typedef struct oam_header_adjust_ctl_s oam_header_adjust_ctl_t;

struct oam_header_edit_ctl_s {
    uint32 cpu_exception_en31_0                                           :32;

   uint32 cpu_exception_en47_32                                          :16;
   uint32 oam_port_id                                                      :7;
   uint32 rsv_0                                                            :1;
   uint32 brg_dest_map11_9                                                 :3;
   uint32 local_chip_id                                                    :5;

   uint32 tx_ccm_by_epe                                                    :1;
   uint32 mplsdlm_dflags_chk                                               :1;
   uint32 mplsdlm_query_code_max_value                                     :3;
   uint32 use_pkt_pri                                                      :1;
   uint32 lbr_sa_type                                                      :1;
   uint32 lbr_sa_using_lbm_da                                              :1;
   uint32 mplsdlm_ver_chk                                                  :1;
   uint32 mplsdlm_query_code_chk                                           :1;
   uint32 rbd_en                                                           :1;
   uint32 rsv_1                                                            :21;

   uint32 redirect_bypass_destmap                                          :18;
   uint32 rsv_2                                                            :14;

   uint32 relay_all_to_cpu_nexthop_ptr                                     :18;
   uint32 rsv_3                                                            :14;

   uint32 bypass_next_hop_ptr                                              :18;
   uint32 rsv_4                                                            :14;

   uint32 i_loop_dest_map                                                  :18;
   uint32 lbr_ttl                                                          :8;
   uint32 rsv_5                                                            :6;

};
typedef struct oam_header_edit_ctl_s oam_header_edit_ctl_t;

struct oam_parser_ether_ctl_s {
    uint32 ach_chan_type_csf                                                :16;
   uint32 ach_chan_type_dlm                                                :16;

   uint32 ach_bfd_default_chan_type                                        :16;
   uint32 ach_chan_type_dlmdm                                              :16;

   uint32 ach_chan_type_dm                                                 :16;
   uint32 ach_y1731_chan_type                                              :16;

   uint32 ach_bfd_chan_type_cc                                             :16;
   uint32 max_length_field                                                 :16;

   uint32 cvlan_tpid                                                       :16;
   uint32 g_tpid0_svlan_tpid                                             :16;

   uint32 g_tpid1_svlan_tpid                                             :16;
   uint32 g_tpid2_svlan_tpid                                             :16;

   uint32 g_tpid3_svlan_tpid                                             :16;
   uint32 mplstp_dlmdm_msg_len                                             :8;
   uint32 y1731_scc_opcode                                                 :8;

   uint32 mpls_tp_oam_alert_label                                          :20;
   uint32 mplstp_dm_msg_len                                                :7;
   uint32 ignore_bfd_version                                               :1;
   uint32 rsv_0                                                            :4;

   uint32 mplstp_dlm_msg_len                                               :7;
   uint32 mplstp_lbm_tlv_type_chk                                          :1;
   uint32 bfd_ach_mep_id_max_len                                           :6;
   uint32 bfd_pfbit_conflict_check_en                                      :1;
   uint32 mplstp_lbm_tlv_offset_chk                                        :1;
   uint32 max_if_status_tlv_value                                          :3;
   uint32 min_if_status_tlv_value                                          :3;
   uint32 invalid_ccm_interval_check_en                                    :1;
   uint32 ignore_eth_oam_version                                           :1;
   uint32 mplstp_lbm_tlv_len_chk                                           :1;
   uint32 mplstp_lbm_tlv_sub_type_chk                                      :1;
   uint32 bfd_abit_check_en                                                :1;
   uint32 max_port_status_tlv_value                                        :2;
   uint32 min_port_status_tlv_value                                        :2;
   uint32 allow_non_zero_oui                                               :1;

   uint32 ach_bfd_chan_type_cv                                             :16;
   uint32 min_mep_id                                                       :8;
   uint32 ma_id_length_chk                                                 :8;

   uint32 md_name_length_chk                                               :8;
   uint32 cfm_pdu_min_length                                               :8;
   uint32 bfd_ach_mep_id_max_type                                          :8;
   uint32 first_tlv_offset_chk                                             :8;

   uint32 cfm_pdu_max_length                                               :14;
   uint32 bfd_len_check_en                                                 :1;
   uint32 bfd_multipoint_chk                                               :1;
   uint32 bvlan_tpid                                                       :16;

   uint32 mplstp_lbm_tlv_offset                                            :3;
   uint32 max_mep_id                                                       :13;
   uint32 tlv_length_check_en                                              :1;
   uint32 cfm_pdu_mac_da_md_lvl_check_en                                   :1;
   uint32 bfd_p2p_check_en                                                 :1;
   uint32 bfd_detect_mult_check_en                                         :1;
   uint32 bfd_ach_mep_id_type_chk_en                                       :1;
   uint32 bfd_ach_mep_id_len_chk_en                                        :1;
   uint32 y1731_slr_code                                                    :8;
   uint32 rsv_1                                                            :2;

   uint32 y1731_slm_code                                                    :8;
   uint32 y1731_mcc_code                                                   :8;
   uint32 ach_chan_type_fm                                                 :16;

   uint32 ach_chan_type_mcc                                                :16;
   uint32 ach_chan_type_scc                                                :16;

};
typedef struct oam_parser_ether_ctl_s oam_parser_ether_ctl_t;


struct oam_parser_layer2_protocol_cam_s {
   uint32 cam_mask0                                                        :23;
   uint32 additional_offset0                                               :4;
   uint32 rsv_0                                                            :5;

   uint32 cam_value0                                                       :23;
   uint32 cam_layer3_type0                                                 :4;
   uint32 rsv_1                                                            :5;

   uint32 cam_mask1                                                        :23;
   uint32 additional_offset1                                               :4;
   uint32 rsv_2                                                            :5;

   uint32 cam_value1                                                       :23;
   uint32 cam_layer3_type1                                                 :4;
   uint32 rsv_3                                                            :5;

   uint32 cam_mask2                                                        :23;
   uint32 additional_offset2                                               :4;
   uint32 rsv_4                                                            :5;

   uint32 cam_value2                                                       :23;
   uint32 cam_layer3_type2                                                 :4;
   uint32 rsv_5                                                            :5;

   uint32 cam_value3                                                       :23;
   uint32 additional_offset3                                               :4;
   uint32 rsv_6                                                            :5;

   uint32 cam_mask3                                                        :23;
   uint32 cam_layer3_type3                                                 :4;
   uint32 rsv_7                                                            :5;
};
typedef struct oam_parser_layer2_protocol_cam_s oam_parser_layer2_protocol_cam_t;

struct oam_parser_layer2_protocol_cam_valid_s {
   uint32 layer2_cam_entry_valid                                           :4;
   uint32 rsv_0                                                            :28;
};
typedef struct oam_parser_layer2_protocol_cam_valid_s oam_parser_layer2_protocol_cam_valid_t;

struct oam_rx_proc_ether_ctl_s {
   uint32 ether_defect_to_rdi1                                             :32;

   uint32 ether_defect_to_rdi0                                             :32;

   uint32 max_bfd_interval                                                 :32;

   uint32 bridge_mac_low                                                   :32;

   uint32 bridge_mac_high                                                  :16;
   uint32 tp_csf_los                                                       :3;
   uint32 tp_csf_fdi                                                       :3;
   uint32 tp_csf_rdi                                                       :3;
   uint32 tp_csf_clear                                                     :3;
   uint32 eth_csf_rdi                                                      :3;
   uint32 tp_cv_to_cpu                                                     :1;

   uint32 d_meg_lvl_timer_cfg                                              :4;
   uint32 d_mismerge_timer_cfg                                             :4;
   uint32 d_unexp_mep_timer_cfg                                            :4;
   uint32 d_unexp_period_timer_cfg                                         :4;
   uint32 eth_csf_los                                                      :3;
   uint32 eth_csf_fdi                                                      :3;
   uint32 mplstpdlm_outbandto_cpu                                          :1;
   uint32 seqnum_fail_report_thrd                                          :6;
   uint32 lbm_macda_check_en                                               :1;
   uint32 alarm_src_mac_mismatch                                           :1;
   uint32 lbm_proc_by_cpu                                                  :1;

   uint32 eth_csf_to_cpu                                                   :1;
   uint32 portbased_section_oam                                            :1;
   uint32 lmm_macda_check_en                                               :1;
   uint32 tp_csf_to_cpu                                                    :1;
   uint32 lmm_proc_by_cpu                                                  :1;
   uint32 min_interval_to_cpu                                              :3;
   uint32 rmep_while_cfg                                                   :4;
   uint32 ccm_with_unknown_tlv_tocpu                                       :1;
   uint32 rmep_lkup_disable                                                :1;
   uint32 d_mis_con_while_cfg                                              :4;
   uint32 eth_csf_clear                                                    :3;
   uint32 dm_proc_by_cpu                                                   :1;
   uint32 timer_auto_negotiation                                           :1;
   uint32 update_rx_disc                                                   :1;
   uint32 mac_status_change_chk_en                                         :1;
   uint32 bfd_use33ms                                                      :1;
   uint32 dm_mac_da_check_en                                               :1;
   uint32 upto_down_pbit_chk_en                                            :1;
   uint32 admin_down_dloc                                                  :1;
   uint32 mplsdlm_tlv_chk                                                  :1;
   uint32 sm_pro_by_cpu                                                    :1;
   uint32 sm_mac_da_check_en                                               :1;

   uint32 array20_rx_csf_while_cfg                                       :13;
   uint32 rsv_0                                                            :3;
   uint32 array21_rx_csf_while_cfg                                       :13;
   uint32 rsv_1                                                            :3;

   uint32 array22_rx_csf_while_cfg                                       :13;
   uint32 rsv_2                                                            :3;
   uint32 array23_rx_csf_while_cfg                                       :13;
   uint32 rsv_3                                                            :3;

   uint32 array24_rx_csf_while_cfg                                       :13;
   uint32 rsv_4                                                            :3;
   uint32 array25_rx_csf_while_cfg                                       :13;
   uint32 rsv_5                                                            :3;

   uint32 array26_rx_csf_while_cfg                                       :13;
   uint32 rsv_6                                                            :3;
   uint32 array27_rx_csf_while_cfg                                       :13;
   uint32 rsv_7                                                            :3;

   uint32 array0_csf_while_cfg                                           :9;
   uint32 rsv_8                                                            :7;
   uint32 array1_csf_while_cfg                                           :9;
   uint32 rsv_9                                                            :7;

   uint32 array2_csf_while_cfg                                           :9;
   uint32 rsv_10                                                           :7;
   uint32 array3_csf_while_cfg                                           :9;
   uint32 rsv_11                                                           :7;

   uint32 array4_csf_while_cfg                                           :9;
   uint32 rsv_12                                                           :7;
   uint32 array5_csf_while_cfg                                           :9;
   uint32 rsv_13                                                           :7;

   uint32 array6_csf_while_cfg                                           :9;
   uint32 rsv_14                                                           :7;
   uint32 array7_csf_while_cfg                                           :9;
   uint32 rsv_15                                                           :7;

   uint32 unknown_ccm_thrd                                                 :3;
   uint32 auto_gen_mac_chk_en                                              :1;
   uint32 always_negotiation                                              :1;
   uint32 rsv_16                                                           :27;


};
typedef struct oam_rx_proc_ether_ctl_s oam_rx_proc_ether_ctl_t;

struct oam_tbl_addr_ctl_s {
   uint32 ma_name_base_addr                                                :12;
   uint32 mp_base_addr                                                     :12;
   uint32 rsv_0                                                            :8;

   uint32 ma_base_addr                                                     :12;
   uint32 rsv_1                                                            :20;
};
typedef struct oam_tbl_addr_ctl_s oam_tbl_addr_ctl_t;

struct oam_update_aps_ctl_s {
   uint32 vlan                                                             :16;
   uint32 tpid                                                             :16;

   uint32 mac_sa31_0                                                     :32;

   uint32 mac_sa47_32                                                    :16;
   uint32 mac_da15_0                                                     :16;

   uint32 mac_da47_16                                                    :32;

   uint32 dest_map                                                         :18;
   uint32 aps_eth_type13_0                                               :14;

   uint32 aps_eth_type15_14                                              :2;
   uint32 sig_fail_next_hop_ptr                                            :18;
   uint32 global_aps_en                                                    :1;
   uint32 src_chip_id                                                      :5;
   uint32 rsv_0                                                            :6;



};
typedef struct oam_update_aps_ctl_s oam_update_aps_ctl_t;

struct oam_update_ctl_s {
    uint32 oam_up_phy_num                                                   :16;
    uint32 oam_bfd_phy_num                                                  :16;

    uint32 bfd_max_ptr                                                      :16;
    uint32 bfd_minptr                                                       :16;

    uint32 bfd_upd_interval                                                 :16;
    uint32 ccm_max_ptr                                                      :16;

    uint32 ccm_min_ptr                                                      :16;
    uint32 upd_interval                                                     :16;

    uint32 gen_rdi_by_dloc                                                  :1;
    uint32 cnt_shift_while_cfg                                              :3;
    uint32 itu_defect_clear_mode                                            :1;
    uint32 sf_fail_while_cfg1                                               :6;
    uint32 cci_while_cfg                                                    :3;
    uint32 upd_en                                                           :1;
    uint32 sf_fail_while_cfg0                                               :6;
    uint32 bfd_upd_en                                                       :1;
    uint32 cv_while_cfg                                                     :3;
    uint32 rsv_0                                                            :7;


};
typedef struct oam_update_ctl_s oam_update_ctl_t;

struct oam_update_status_s {
   uint32 bfd_upd_ptr                                                      :16;
   uint32 ccm_upd_ptr                                                      :16;

   uint32 ccm_quater_flag                                                  :6;
   uint32 ccm_quater_flag_seen                                             :6;
   uint32 rsv_0                                                            :20;
};
typedef struct oam_update_status_s oam_update_status_t;

struct ms_excp_info_s                                                   /* 576 */
{
   uint32 acl_log_id2                                                      :2;
   uint32 acl_log_id3                                                      :2;
   uint32 exception_number                                                 :3;
   uint32 exception_from_sgmac                                             :1;
   uint32 exception_vector                                                 :9;
   uint32 exception_packet_type                                            :3;
   uint32 egress_exception                                                 :1;
   uint32 acl_log_id0                                                      :2;
   uint32 acl_log_id1                                                      :2;
   uint32 l3_span_id                                                       :2;
   uint32 l2_span_id                                                       :2;
   uint32 exception_sub_index0                                        :3;

   uint32 exception_sub_index1                                        :3;
   uint32 dest_id_discard                                                  :1;
   uint32 src_queue_select                                                 :1;
   uint32 cut_through                                                      :1;
   uint32 rsv_0                                                            :26;
};
typedef struct ms_excp_info_s ms_excp_info_t;

#endif /*end of _DRV_STRUCT_LE_H_*/

