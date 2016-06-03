/**
 @file ctc_stats.h

 @author  Copyright (C) 2011 Centec Networks Inc.  All rights reserved.

 @date 2009-12-15

 @version v2.0

   This file contains all stats related data structure, enum, macro and proto.
*/

#ifndef _CTC_STATS_H
#define _CTC_STATS_H
#ifdef __cplusplus
extern "C" {
#endif
/****************************************************************
 *
 * Header Files
 *
 ***************************************************************/
#include "ctc_const.h"
/****************************************************************
*
* Defines and Macros
*
****************************************************************/
/**
 @defgroup stats STATS
 @{
*/

/**
 @brief  Define stats type
*/
enum ctc_stats_type_e
{
    CTC_STATS_TYPE_IGS_PORT_PHB,                        /**< [HB] igs phb port based stats */
    CTC_STATS_TYPE_EGS_PORT_PHB,                        /**< [HB] egs phb port based stats */
    CTC_STATS_TYPE_IGS_GLOBAL_FWD,                      /**< [HB] igs global fwd stats */
    CTC_STATS_TYPE_EGS_GLOBAL_FWD,                      /**< [HB] egs global fwd stats */
    CTC_STATS_TYPE_FWD,                                 /**< [HB.GB.GG] fwd stats */
    CTC_STATS_TYPE_GMAC,                                /**< [HB.GB.GG] gmac stats */
    CTC_STATS_TYPE_XGMAC,                               /**< [HB] xgmac stats */
    CTC_STATS_TYPE_SGMAC,                               /**< [HB.GB.GG] sgmac stats */
    CTC_STATS_TYPE_XQMAC,                               /**< [GG] xqmac stats */
    CTC_STATS_TYPE_CGMAC,                               /**< [GG] cgmac stats */
    CTC_STATS_TYPE_CPUMAC,                              /**< [HB.GB] cpu mac stats */

    CTC_STATS_TYPE_MAX
};
typedef enum ctc_stats_type_e ctc_stats_type_t;

/**
 @brief  Define port stats option type
*/
enum ctc_stats_port_stats_option_type_e
{
    CTC_STATS_PORT_BASED_NULL,                    /**< [HB] port do not do statistics */
    CTC_STATS_PORT_BASED_BASIC,                   /**< [HB] port excluding mac based or protocol based */
    CTC_STATS_PORT_BASED_MAC,                     /**< [HB] mac based port */
    CTC_STATS_PORT_BASED_PROTOCOL,                /**< [HB] protocol based port */
    CTC_STATS_PORT_BASED_PHB,                     /**< [HB] phb */
    CTC_STATS_PORT_BASED_PHB_PER_PORT,            /**< [HB] phb per port */
    CTC_STATS_PORT_BASED_MAX
};
typedef enum ctc_stats_port_stats_option_type_e ctc_stats_port_stats_option_type_t;

/**
 @brief  Define MAC base stats property type
*/
enum  ctc_mac_stats_prop_type_e
{
    CTC_STATS_PACKET_LENGTH_MTU1,                  /**< [HB.GB.GG] MTU1 packet length, packet length larger than this consider as oversized packet. Default is 1518B */
    CTC_STATS_PACKET_LENGTH_MTU2,                  /**< [HB.GB.GG] MTU2 packet length, packet length larger than this consider as jumbo packet. Default is 1536B */
    CTC_STATS_DOT1Q_SUBTRACT_BYTES,                /**< [HB] deal with bytes to subtract for dot1q packet only for humber*/

    CTC_STATS_MAC_STATS_PROP_MAX
};
typedef enum ctc_mac_stats_prop_type_e ctc_mac_stats_prop_type_t;

/**
 @brief  Define MAC base stats direction type
*/
enum  ctc_mac_stats_dir_e
{
    CTC_STATS_MAC_STATS_RX,                  /**< [HB.GB.GG] Mac stats RX direction */
    CTC_STATS_MAC_STATS_TX,                  /**< [HB.GB.GG] Mac stats TX direction */

    CTC_STATS_MAC_STATS_MAX
};
typedef enum ctc_mac_stats_dir_e ctc_mac_stats_dir_t;

/**
 @brief  Define MAC base stats direction type
*/
enum  ctc_stats_property_type_e
{
    CTC_STATS_PROPERTY_SATURATE,                    /**< [HB.GB.GG] deal with general options saturate enable */
    CTC_STATS_PROPERTY_HOLD,                        /**< [HB.GB.GG] deal with general options hold enable */
    CTC_STATS_PROPERTY_CLEAR_AFTER_READ,            /**< [HB] deal with general options clear after read */
    CTC_STATS_PROPERTY_PKT_CNT_THREASHOLD,          /**< [HB.GB] deal with general options pkt cnt threshold */
    CTC_STATS_PROPERTY_BYTE_CNT_THREASHOLD,         /**< [HB.GB] deal with general options byte cnt threshold */
    CTC_STATS_PROPERTY_FIFO_DEPTH_THREASHOLD,       /**< [HB.GB] deal with general options fifo depth threshold */

    CTC_STATS_PROPERTY_MAX
};
typedef enum ctc_stats_property_type_e ctc_stats_property_type_t;

/**
 @brief  Define stats color
*/
enum ctc_stats_color_e
{
    CTC_STATS_GREEN,                    /**< [GB] green color packet stats */
    CTC_STATS_NOT_GREEN,                /**< [GB] not green color packet stats */

    CTC_STATS_COLOR_MAX
};
typedef enum ctc_stats_color_e ctc_stats_color_t;

/**
 @brief  Define stats forward flag
*/
enum ctc_stats_fwd_stats_bitmap_e
{
    CTC_STATS_QUEUE_DEQ_STATS       = 0x0001,            /**< [HB.GB] dequeue stats */
    CTC_STATS_QUEUE_DROP_STATS      = 0x0002,            /**< [HB.GB] drop queue stats. For GB, dequeue stats must be enabled */
    CTC_STATS_PORT_POLICER_STATS    = 0x0004,            /**< [HB] port policer stats */
    CTC_STATS_SERVICE_POLICER_STATS = 0x0008,            /**< [HB] service policer stats */
    CTC_STATS_FLOW_POLICER_STATS    = 0x0010,            /**< [HB.GB] flow policer stats */
    CTC_STATS_FLOW_STATS            = 0x0020,            /**< [HB.GB] flow stats */
    CTC_STATS_VLAN_STATS            = 0x0040,            /**< [GB] vlan stats */
    CTC_STATS_VRF_STATS             = 0x0080,            /**< [GB] vrf stats */
    CTC_STATS_ECMP_STATS            = 0x0100             /**< [GG] Ecmp group stats */
};
typedef enum ctc_stats_fwd_stats_bitmap_e ctc_stats_fwd_stats_bitmap_t;

/**
 @brief  Define stats discard flag
*/
enum ctc_stats_discard_e
{
    CTC_STATS_RANDOM_LOG_DISCARD_STATS      = 0x01,         /**< [HB.GB.GG] random log stats discard pkt */
    CTC_STATS_FLOW_DISCARD_STATS            = 0x02,         /**< [GB.GG] flow stats discard pkt */

    CTC_STATS_MAX
};
typedef enum ctc_stats_discard_e ctc_stats_discard_t;

/**
 @brief Define stats mode
 */
enum ctc_stats_mode_e
{
    CTC_STATS_MODE_PLUS,          /**< [GB.GG] plus stats info correspond to plus hw stats info */
    CTC_STATS_MODE_DETAIL,        /**< [GB.GG] detail stats info based on hw stats info */
    CTC_STATS_MODE_NUM
};
typedef enum ctc_stats_mode_e ctc_stats_mode_t;

/**
 @brief  Define stats phb
*/
struct ctc_stats_phb_s
{
    ctc_stats_color_t color;        /**< [GB] phb color */
    uint8 cos;                      /**< [GB] cos mapped from priority */
    uint8 is_all_phb;               /**< [GB] If set this field, it means all phb stats. Then the color and cos fields are unuseful */
    uint8 rsv[2];
};
typedef struct ctc_stats_phb_s ctc_stats_phb_t;

/**
 @brief  Define mac receive statistics storage structor
*/
struct ctc_stats_mac_rec_s
{
    uint64 good_ucast_pkts;              /**< [HB.GB.GG] length equal to 64B to 1518B(no vlan) or 1522B(vlan),total number of unicast packets received without error */
    uint64 good_ucast_bytes;             /**< [HB.GB.GG] length equal to 64B to 1518B(no vlan) or 1522B(vlan),total bytes of unicast packets received without error */
    uint64 good_mcast_pkts;              /**< [HB.GB.GG] length equal to 64B to 1518B(no vlan) or 1522B(vlan),total number of multicast packets received without error */
    uint64 good_mcast_bytes;             /**< [HB.GB.GG] length equal to 64B to 1518B(no vlan) or 1522B(vlan),total bytes of multicast packets received without error */
    uint64 good_bcast_pkts;              /**< [HB.GB.GG] length equal to 64B to 1518B(no vlan) or 1522B(vlan),total number of broadcast packets received without error */
    uint64 good_bcast_bytes;             /**< [HB.GB.GG] length equal to 64B to 1518B(no vlan) or 1522B(vlan),total bytes of broadcast packets received without error */
    uint64 good_pause_pkts;              /**< [HB] total number of pause packets without error */
    uint64 good_pause_bytes;             /**< [HB] total bytes of pause packets without error */
    uint64 good_normal_pause_pkts;       /**< [GB.GG] total number of nomal pause packets without error */
    uint64 good_normal_pause_bytes;      /**< [GB.GG] total bytes of nomal pause packets without error */
    uint64 good_pfc_pause_pkts;          /**< [GB.GG] total number of pfc pause packets without error */
    uint64 good_pfc_pause_bytes;         /**< [GB.GG] total bytes of pfc pause packets without error */
    uint64 good_control_pkts;            /**< [HB.GB.GG] total number of control packets without error excluding the pause packet */
    uint64 good_control_bytes;           /**< [HB.GB.GG] total bytes of control packets without error excluding the pause packet */
    uint64 jabber_pkts;                  /**< [HB] no mac overrun,length greater than MTU,total number of packets with fcs error or alignment error */
    uint64 jabber_bytes;                 /**< [HB] no mac overrun,length greater than MTU,total bytes of packets with fcs error or alignment error */
    uint64 collision_pkts;               /**< [HB] no mac overrun,length less than 64B,total number of packets with fcs error or alignment error */
    uint64 collision_bytes;              /**< [HB] no mac overrun,length less than 64B,total bytes of packets with fcs error or alignment error */
    uint64 fcs_error_pkts;               /**< [HB.GB.GG] no mac overrun,length equal to 64B to MTU,total number of packets with fcs error */
    uint64 fcs_error_bytes;              /**< [HB.GB.GG] no mac overrun,length equal to 64B to MTU,total bytes of packets with fcs error */
    uint64 alignment_error_pkts;         /**< [HB] no mac overrun,length equal to 64B to MTU,total number of packets with alignment error */
    uint64 alignment_error_bytes;        /**< [HB] no mac overrun,length equal to 64B to MTU,total bytes of packets with alignment error */
    uint64 mac_overrun_pkts;             /**< [HB.GB.GG] total number of packets received with mac overrun condition */
    uint64 mac_overrun_bytes;            /**< [HB.GB.GG] total bytes of packets received with mac overrun condition */
    uint64 good_oversize_pkts;           /**< [HB] no mac overrun,length greater than 1518B(no vlan) or 1522B(vlan),total number of packets received without fcs error and alignment error */
    uint64 good_oversize_bytes;          /**< [HB] no mac overrun,length greater than 1518B(no vlan) or 1522B(vlan),total bytes of packets received without fcs error and alignment error */
    uint64 good_undersize_pkts;          /**< [HB] no mac overrun,length less than 64B,total number of packets received without fcs error and alignment error */
    uint64 good_undersize_bytes;         /**< [HB] no mac overrun,length less than 64B,total bytes of packets received without fcs error and alignment error */
    uint64 gmac_good_oam_pkts;           /**< [HB] total number of packets without error */
    uint64 gmac_good_oam_bytes;          /**< [HB] total bytes of packets without error */
    uint64 good_63_pkts;                 /**< [HB.GB.GG] total number of good packets received with length less than 64B without fcs error and late collision */
    uint64 good_63_bytes;                /**< [HB.GB.GG] total bytes of good packets received with length less than 64B without fcs error and late collision */
    uint64 bad_63_pkts;                  /**< [HB.GB.GG] total number of errored packets received with length less than 64B including fcs error and late collision */
    uint64 bad_63_bytes;                 /**< [HB.GB.GG] total bytes of errored packets received with length less than 64B including fcs error and late collision */
    uint64 good_1519_pkts;               /**< [HB.GB.GG] total number of good packets received with length equal to 1519B to MTU including fcs error and late collision */
    uint64 good_1519_bytes;              /**< [HB.GB.GG] total bytes of good packets received with length equal to 1519B to MTU including fcs error and late collision */
    uint64 bad_1519_pkts;                /**< [HB.GB.GG] total number of errored packets received with length equal to 1519B to MTU including fcs error */
    uint64 bad_1519_bytes;               /**< [HB.GB.GG] total bytes of errored packets received with length equal to 1519B to MTU including fcs error */
    uint64 good_jumbo_pkts;              /**< [HB.GB.GG] total number of good packets received with length greater than MTU including fcs error */
    uint64 good_jumbo_bytes;             /**< [HB.GB.GG] total bytes of good packets received with length greater than MTU including fcs error */
    uint64 bad_jumbo_pkts;               /**< [HB.GB.GG] total number of errored packets received with length greater than MTU including fcs error */
    uint64 bad_jumbo_bytes;              /**< [HB.GB.GG] total bytes of errored packets received with length greater than MTU including fcs error */
    uint64 pkts_64;                      /**< [HB.GB.GG] total number of packets received with length equal to 64B including fcs error and late collision */
    uint64 bytes_64;                     /**< [HB.GB.GG] total bytes of packets received with length equal to 64B including fcs error and late collision */
    uint64 pkts_65_to_127;               /**< [HB.GB.GG] total number of packets received with length equal to 65B to 127B including fcs error and late collision */
    uint64 bytes_65_to_127;              /**< [HB.GB.GG] total bytes of packets received with length equal to 65B to 127B including fcs error and late collision */
    uint64 pkts_128_to_255;              /**< [HB.GB.GG] total number of packets received with length equal to 128B to 255B including fcs error and late collision */
    uint64 bytes_128_to_255;             /**< [HB.GB.GG] total bytes of packets received with length equal to 128B to 255B including fcs error and late collision */
    uint64 pkts_256_to_511;              /**< [HB.GB.GG] total number of packets received with length equal to 256B to 511B including fcs error and late collision */
    uint64 bytes_256_to_511;             /**< [HB.GB.GG] total bytes of packets received with length equal to 256B to 511B including fcs error and late collision */
    uint64 pkts_512_to_1023;             /**< [HB.GB.GG] total number of packets received with length equal to 512B to 1023B including fcs error and late collision */
    uint64 bytes_512_to_1023;            /**< [HB.GB.GG] total bytes of packets received with length equal to 512B to 1023B including fcs error and late collision */
    uint64 pkts_1024_to_1518;            /**< [HB.GB.GG] total number of packets received with length equal to 1024B to 1518B including fcs error and late collision */
    uint64 bytes_1024_to_1518;           /**< [HB.GB.GG] total bytes of packets received with length equal to 1024B to 1518B including fcs error and late collision */
};
typedef struct ctc_stats_mac_rec_s ctc_stats_mac_rec_t;

/**
 @brief  Define mac transmit statistics storage structor
*/
struct ctc_stats_mac_snd_s
{
    uint64 good_ucast_pkts;              /**< [HB.GB.GG] total number of unicast packets transmitted without error */
    uint64 good_ucast_bytes;             /**< [HB.GB.GG] total bytes of unicast packets transmitted without error */
    uint64 good_mcast_pkts;              /**< [HB.GB.GG] total number of multicast packets transmitted without error */
    uint64 good_mcast_bytes;             /**< [HB.GB.GG] total bytes of multicast packets transmitted without error */
    uint64 good_bcast_pkts;              /**< [HB.GB.GG] total number of broadcast packets transmitted without error */
    uint64 good_bcast_bytes;             /**< [HB.GB.GG] total bytes of broadcast packets transmitted without error */
    uint64 good_pause_pkts;              /**< [HB.GB.GG] total number of pause packets transmitted without error */
    uint64 good_pause_bytes;             /**< [HB.GB.GG] total bytes of pause packets transmitted without error */
    uint64 good_control_pkts;            /**< [HB.GB.GG] total number of pause packets transmitted without error excluding the pause packet */
    uint64 good_control_bytes;           /**< [HB.GB.GG] total bytes of pause packets transmitted without error excluding the pause packet */
    uint64 good_oam_pkts;                /**< [HB] total number of oam packets transmitted without error */
    uint64 good_oam_bytes;               /**< [HB] total bytes of oam packets transmitted without error */
    uint64 pkts_63;                      /**< [HB.GB.GG] total number of packets transmitted with length less than 64B including fcs error and late collision */
    uint64 bytes_63;                     /**< [HB.GB.GG] total bytes of packets transmitted with length less than 64B including fcs error and late collision */
    uint64 pkts_64;                      /**< [HB.GB.GG] total number of packets transmitted with length equal to 64B including fcs error and late collision */
    uint64 bytes_64;                     /**< [HB.GB.GG] total bytes of packets transmitted with length equal to 64B including fcs error and late collision */
    uint64 pkts_65_to_127;               /**< [HB.GB.GG] total number of packets transmitted with length equal to 65B to 127B including fcs error and late collision */
    uint64 bytes_65_to_127;              /**< [HB.GB.GG] total bytes of packets transmitted with length equal to 65B to 127B including fcs error and late collision */
    uint64 pkts_128_to_255;              /**< [HB.GB.GG] total number of packets transmitted with length equal to 128B to 255B including fcs error and late collision */
    uint64 bytes_128_to_255;             /**< [HB.GB.GG] total bytes of packets transmitted with length equal to 128B to 255B including fcs error and late collision */
    uint64 pkts_256_to_511;              /**< [HB.GB.GG] total number of packets transmitted with length equal to 256B to 511B including fcs error and late collision */
    uint64 bytes_256_to_511;             /**< [HB.GB.GG] total bytes of packets transmitted with length equal to 256B to 511B including fcs error and late collision */
    uint64 pkts_512_to_1023;             /**< [HB.GB.GG] total number of packets transmitted with length equal to 512B to 1023B including fcs error and late collision */
    uint64 bytes_512_to_1023;            /**< [HB.GB.GG] total bytes of packets transmitted with length equal to 512B to 1023B including fcs error and late collision */
    uint64 pkts_1024_to_1518;            /**< [HB.GB.GG] total number of packets transmitted with length equal to 1024B to 1518B including fcs error and late collision */
    uint64 bytes_1024_to_1518;           /**< [HB.GB.GG] total bytes of packets transmitted with length equal to 1024B to 1518B including fcs error and late collision */
    uint64 pkts_1519;                    /**< [HB.GB.GG] total number of packets transmitted with length equal to 1519B to MTU including fcs error and late collision */
    uint64 bytes_1519;                   /**< [HB.GB.GG] total bytes of packets transmitted with length equal to 1519B to MTU including fcs error and late collision */
    uint64 jumbo_pkts;                   /**< [HB.GB.GG] total number of packets transmitted with length greater than MTU including fcs error and late collision */
    uint64 jumbo_bytes;                  /**< [HB.GB.GG] total bytes of packets transmitted with length greater than MTU including fcs error and late collision */
    uint64 mac_underrun_pkts;            /**< [HB.GB.GG] total number of packets transmitted with mac underrun condition */
    uint64 mac_underrun_bytes;           /**< [HB.GB.GG] total bytes of packets transmitted with mac underrun condition */
    uint64 fcs_error_pkts;               /**< [HB.GB.GG] total number of packets transmitted with fcs error */
    uint64 fcs_error_bytes;              /**< [HB.GB.GG] total bytes of packets transmitted with fcs error */
};
typedef struct ctc_stats_mac_snd_s ctc_stats_mac_snd_t;

/**
 @brief  Define cpu mac statistics storage structor
*/
struct ctc_stats_cpu_mac_s
{
    uint64 cpu_mac_rx_good_pkts;         /**< [GB.GG] the frames counter of the mac receive good packets */
    uint64 cpu_mac_rx_good_bytes;        /**< [GB.GG] the bytes counter of the mac receive good packets */
    uint64 cpu_mac_rx_bad_pkts;          /**< [GB.GG] the frames counter of the mac receive bad packets */
    uint64 cpu_mac_rx_bad_bytes;         /**< [GB.GG] the bytes counter of the mac receive bad packets */
    uint64 cpu_mac_rx_fragment_pkts;     /**< [GB.GG] the frames counter of the mac receive fragment packets */
    uint64 cpu_mac_rx_fcs_error_pkts;    /**< [GB.GG] the frames counter of the mac receive fcs error packets */
    uint64 cpu_mac_rx_overrun_pkts;      /**< [GB.GG] the frames counter of the mac receive overrun packets */
    uint64 cpu_mac_tx_total_pkts;        /**< [GB.GG] the frames counter of the mac transmitted total packets */
    uint64 cpu_mac_tx_total_bytes;       /**< [GB.GG] the bytes counter of the mac transmitted total packets */
    uint64 cpu_mac_tx_fcs_error_pkts;    /**< [GB.GG] the frames counter of the mac transmitted fcs error packets */
    uint64 cpu_mac_tx_underrun_pkts;     /**< [GB.GG] the frames counter of the mac transmitted underrun packets */
};
typedef struct ctc_stats_cpu_mac_s ctc_stats_cpu_mac_t;

/**
 @brief  Define mac statistics receive plus storage structor
*/
struct ctc_stats_mac_rec_plus_s
{
    uint64 all_octets;      /**< [GB.GG] total bytes with all receive bytes */
    uint64 all_pkts;        /**< [GB.GG] total packets with all receive pkts */
    uint64 ucast_pkts;      /**< [GB.GG] total packets with unicast pkts */
    uint64 mcast_pkts;      /**< [GB.GG] total packets with multicast pkts */
    uint64 bcast_pkts;      /**< [GB.GG] total packets with broadcast pkts */
    uint64 runts_pkts;      /**< [GB.GG] total packets with undersize pkts */
    uint64 giants_pkts;     /**< [GB.GG] total packets with oversize pkts */
    uint64 crc_pkts;        /**< [GB.GG] total packets with fcs erorr pkts */
    uint64 frame_pkts;      /**< total packets with frame pkts */
    uint64 overrun_pkts;    /**< [GB.GG] total packets with overrun pkts */
    uint64 pause_pkts;      /**< [GB.GG] total packets with pause pkts */
    uint64 fragments_pkts;  /**< [GB.GG] total packets with fragment pkts */
    uint64 alignment_pkts;  /**< total packets with allignment pkts */
    uint64 jabber_pkts;     /**< [GB.GG] total packets with jabber pkts */
    uint64 jumbo_events;    /**< [GB.GG] total packets with jumbo pkts */
    uint64 drop_events;     /**< [GB.GG] total packets with overrun pkts */
    uint64 error_pkts;      /**< [GB.GG] total packets with fcs erorr, undersize, jabber, collison, allignment, overrun pkts */
};
typedef struct ctc_stats_mac_rec_plus_s ctc_stats_mac_rec_plus_t;

/**
 @brief  Define mac statistics transmit plus storage structor
*/
struct ctc_stats_mac_snd_plus_s
{
    uint64 all_octets;      /**< [GB.GG] total bytes with all transmit bytes */
    uint64 all_pkts;        /**< [GB.GG] total packets with all transmit pkts */
    uint64 ucast_pkts;      /**< [GB.GG] total packets with unicast pkts */
    uint64 mcast_pkts;      /**< [GB.GG] total packets with multicast pkts */
    uint64 bcast_pkts;      /**< [GB.GG] total packets with broadcast pkts */
    uint64 underruns_pkts;  /**< [GB.GG] total packets with underrun pkts */
    uint64 jumbo_events;    /**< [GB.GG] total packets with jumbo pkts */
    uint64 error_pkts;      /**< [GB.GG] total packets with fcs erorr pkts */
};
typedef struct ctc_stats_mac_snd_plus_s ctc_stats_mac_snd_plus_t;


/**
 @brief  Define basic statistics storage structor
*/
struct ctc_stats_basic_s
{
    uint64 packet_count;                  /**< [HB.GB.GG] total number of packets */
    uint64 byte_count;                    /**< [HB.GB.GG] total bytes of paclets */
};
typedef struct ctc_stats_basic_s ctc_stats_basic_t;

/**
 @brief  Define Mac base stats property storage structor
*/
struct ctc_mac_stats_property_s
{
    union
    {
        uint16 length;       /**< [HB.GB.GG] length of mtu packet */
        uint8 byte;          /**< [HB] num of bytes */
    } data;
    uint16 rsv0;
};
typedef struct ctc_mac_stats_property_s ctc_mac_stats_property_t;

/**
 @brief  Define Mac base detail stats property storage structor
*/
struct ctc_mac_stats_detail_s
{
    union
    {
        ctc_stats_mac_rec_t rx_stats;       /**< [HB.GB.GG] mac receive statistics storage */
        ctc_stats_mac_snd_t tx_stats;       /**< [HB.GB.GG] mac send statistics storage */
    } stats;
};
typedef struct ctc_mac_stats_detail_s ctc_mac_stats_detail_t;

/**
 @brief  Define Mac base plus stats property storage structor
*/
struct ctc_mac_stats_plus_s
{
    union
    {
        ctc_stats_mac_rec_plus_t rx_stats_plus;       /**< [GB.GG] mac receive statistics storage */
        ctc_stats_mac_snd_plus_t tx_stats_plus;       /**< [GB.GG] mac send statistics storage */
    } stats;
};
typedef struct ctc_mac_stats_plus_s ctc_mac_stats_plus_t;

/**
 @brief  Define Mac base stats property storage structor
*/
struct ctc_mac_stats_s
{
    uint8 stats_mode;  /**< [GB.GG] get stats mode, 0: plus stats, 1: detail stats */
    uint8 rsv[3];
    union
    {
        ctc_mac_stats_plus_t stats_plus;     /**< [GB.GG] aggreate stats for system */
        ctc_mac_stats_detail_t stats_detail; /**< [HB.GB.GG] centec asic detail stats */
    } u;
};
typedef struct ctc_mac_stats_s ctc_mac_stats_t;

/**
 @brief  Define Dma sync mac stats
*/
struct ctc_stats_mac_stats_sync_s
{
    uint8  valid_cnt;                                  /**< [GB.GG] num of phy port enable */
    uint32 gport[CTC_MAX_PHY_PORT];                    /**< [GB.GG] gport id*/
    ctc_mac_stats_t stats[CTC_MAX_PHY_PORT];           /**< [GB.GG] mac stats on this gport */
};
typedef struct ctc_stats_mac_stats_sync_s ctc_stats_mac_stats_sync_t;

typedef int32 (* ctc_stats_sync_fn_t)  (ctc_stats_mac_stats_sync_t*, void *userdata);

/**
 @brief  Define Mac base stats property storage structor
*/
struct ctc_cpu_mac_stats_s
{
    ctc_stats_cpu_mac_t cpu_mac_stats;     /**< [GB.GG] cpu mac stats for asic */
    uint8 rsv0;
};
typedef struct ctc_cpu_mac_stats_s ctc_cpu_mac_stats_t;


/**
 @brief  Define Global Fwarding stats property storage structor
*/
struct ctc_stats_property_s
{
    union
    {
        bool enable;                 /**< [HB.GB] saturate enable , hold enable ,  clear after read value */
        uint16 threshold_16byte;     /**< [HB.GB] packet count threshold or byte count threshold value */
        uint8 threshold_8byte;       /**< [HB.GB] fifo depth threshold value */
    } data;
};
typedef struct ctc_stats_property_s ctc_stats_property_t;

/**
 @brief  Define Global Fwarding stats property storage structor
*/
struct ctc_stats_property_param_s
{
    ctc_stats_property_type_t prop_type;    /**< [HB.GB] stats proterty type */
    ctc_stats_type_t          stats_type;   /**< [HB.GB] stats type */

};
typedef struct ctc_stats_property_param_s ctc_stats_property_param_t;

/**
 @brief  Define stats_id structor create
*/
enum ctc_stats_statsid_type_e
{
     CTC_STATS_STATSID_TYPE_VLAN,            /**< [GB] vlan stats, support ingress and egress */
     CTC_STATS_STATSID_TYPE_VRF,             /**< [GB.GG] vrf stats */
     CTC_STATS_STATSID_TYPE_ACL,             /**< [GB.GG] acl stats */
     CTC_STATS_STATSID_TYPE_IPMC,            /**< [GB.GG] ipmc stats */
     CTC_STATS_STATSID_TYPE_MPLS,            /**< [GB.GG] mpls ilm stats */
     CTC_STATS_STATSID_TYPE_TUNNEL,          /**< [GB.GG] tunnel stats */
     CTC_STATS_STATSID_TYPE_SCL,             /**< [GB.GG] scl stats */
     CTC_STATS_STATSID_TYPE_NEXTHOP,         /**< [GB.GG] nexthop stats */
     CTC_STATS_STATSID_TYPE_NEXTHOP_MPLS_PW, /**< [GG] nexthop mpls pw stats */
     CTC_STATS_STATSID_TYPE_NEXTHOP_MPLS_LSP,/**< [GG] nexthop mpls lsp stats */
     CTC_STATS_STATSID_TYPE_NEXTHOP_MCAST,   /**< [GG] mcast stats */
     CTC_STATS_STATSID_TYPE_L3IF,            /**< [GB.GG] l3if stats. for gb, only support ingress subif */
     CTC_STATS_STATSID_TYPE_FID,             /**< [GG] fid stats */
     CTC_STATS_STATSID_TYPE_ECMP,            /**< [GG] ecmp group stats */

     CTC_STATS_STATSID_TYPE_MAX
};
typedef enum ctc_stats_statsid_type_e ctc_stats_statsid_type_t;

#define CTC_STATS_MAX_STATSID 0xFFFFFFFF

struct ctc_stats_statsid_s
{
     ctc_stats_statsid_type_t type;             /**< [GB.GG] type for statsid*/
     ctc_direction_t dir;                       /**< [GB.GG] direction*/
     uint32      stats_id;                      /**< [GB.GG] statsid */
     union
     {
          uint16 vlan_id;                       /**< [GB] vlan id */
          uint16 vrf_id;                        /**< [GB] vrf id */
          uint8  acl_priority;                  /**< [GG] priority */
          uint8  is_vc_label;                   /**< [GG] Indicate vc label */
     }statsid;
};
typedef struct ctc_stats_statsid_s ctc_stats_statsid_t;

/**
 @brief  Define stats mode
*/
enum ctc_stats_flow_mode_e
{
     CTC_STATS_MODE_USER,                    /**< [GB.GG] Stats mode user config stats id*/
     CTC_STATS_MODE_DEFINE,                   /**< [GB.GG] Stats mode sdk config stats id*/
     CTC_STATS_FLOW_MODE_MAX
};
typedef enum ctc_stats_flow_mode_e ctc_stats_flow_mode_t;

/**
 @brief  Define stats mode
*/
enum ctc_stats_query_mode_e
{
     CTC_STATS_QUERY_MODE_IO,                /**< [GB.GG] Mac stats mode will reply instant mac stats */
     CTC_STATS_QUERY_MODE_POLL,               /**< [GB.GG] Mac stats mode will reply poll mac stats, with some error*/
     CTC_STATS_QUERY_MODE_MAX
};
typedef enum ctc_stats_query_mode_e ctc_stats_query_mode_t;

/**
 @brief Global stats config info.
*/
struct ctc_stats_global_cfg_s
{
    uint8  stats_mode;              /**< [GB.GG] Referce to ctc_stats_flow_mode_t */
    uint16 query_mode;              /**< [GB.GG] Mac stats used mode, refer to ctc_stats_query_mode_t */
    uint16 stats_bitmap;            /**< [HB.GB.GG] Supported stats bitmap, refer to ctc_stats_fwd_stats_bitmap_t */
    uint16 policer_stats_num;       /**< [GB] policer number which supported stats, it should be alignment with 64 */
};
typedef struct ctc_stats_global_cfg_s ctc_stats_global_cfg_t;

/**@} end of @defgroup stats STATS  */

#ifdef __cplusplus
}
#endif

#endif

