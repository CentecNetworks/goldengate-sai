/**
 @file ctc_l2.h

 @author  Copyright (C) 2011 Centec Networks Inc.  All rights reserved.

 @date 2009-11-26

 @version v2.0

   This file contains all L2 related data structure, enum, macro and proto.
*/

#ifndef _CTC_L2_H
#define _CTC_L2_H
#ifdef __cplusplus
extern "C" {
#endif
/****************************************************************
 *
 * Header Files
 *
 ***************************************************************/
#include "sal_types.h"
#include "ctc_const.h"

/****************************************************************
*
* Defines and Macros
*
****************************************************************/

/**
 @defgroup fdb FDB
 @{
*/

/**
 @brief  define l2 FDB entry flags
*/
enum ctc_l2_flag_e
{
    CTC_L2_FLAG_IS_STATIC         = 0x00000001, /**<[HB,GB,GG][uc] unicast FDB,if set ,indicate the entry is static entry, using for MAC DA */
    CTC_L2_FLAG_DISCARD           = 0x00000002, /**<[HB,GB,GG][uc,mc] unicast static FDB, indicate the entry is discard entry,using for MAC DA */
    CTC_L2_FLAG_SRC_DISCARD       = 0x00000004, /**<[HB,GB,GG][uc,mc] unicast static  FDB, indicate the entry is discard entry, using for MAC SA */
    CTC_L2_FLAG_SRC_DISCARD_TOCPU = 0x00000008, /**<[HB,GB,GG][uc,mc] unicast static FDB, indicate the entry is discard entry and packet will send to CPU, using for MAC SA */
    CTC_L2_FLAG_COPY_TO_CPU       = 0x00000010, /**<[HB,GB,GG][uc,mc] unicast static FDB, indicate packet will copy to CPU, using for MAC DA */
    CTC_L2_FLAG_AGING_DISABLE     = 0x00000020, /**<[HB,GB,GG][uc] unicast dynamic FDB if set, indicate the entry will disable aging, but can do learning check */
    CTC_L2_FLAG_PROTOCOL_ENTRY    = 0x00000040, /**<[HB,GB,GG][uc,mc] unicast/Mcast FDB,indicate the entry is protocal entry should send to CPU when match, using for MAC DA */
    CTC_L2_FLAG_BIND_PORT         = 0x00000080, /**<[HB,GB,GG][uc] unicast FDB, MAC binding port/MAC +vlan binding port,when source mismatch should discard, using for MAC SA */
    CTC_L2_FLAG_RAW_PKT_ELOG_CPU  = 0x00000100, /**<[HB] unicast static FDB, send raw packet to cpu,using for terminating protocol pakcet(LBM/DMM/LMM) to cpu */
    CTC_L2_FLAG_REMOTE_DYNAMIC    = 0x00000200, /**<[HB,GB,GG][uc] unicast dynamic FDB, if set ,indicate the entry is remote chip learning dynamic entry, using for MAC DA */
    CTC_L2_FLAG_SYSTEM_RSV        = 0x00000400, /**<[HB,GB,GG][uc] unicast static FDB, if set ,indicate the entry is system mac, it can't be deleted by flush api, using for MAC DA */
    CTC_L2_FLAG_PORTUNTAGGED      = 0x00000800, /**<[HB] unicast static FDB, if set ,indicate the output packet will is untagged packet from output port */
    CTC_L2_FLAG_UCAST_DISCARD     = 0x00001000, /**<[HB,GB][uc] unicast static FDB, if set ,indicate the output packet will be discard for unicast */
    CTC_L2_FLAG_KEEP_EMPTY_ENTRY  = 0x00002000, /**<[HB,GB,GG][mc] Remove all member. api behavior. not action */
    CTC_L2_FLAG_SERVICE_QUEUE     = 0x00004000, /**<[HB] unicast/Mcast FDB, if set, indicate the packet will do service queue*/
    CTC_L2_FLAG_PTP_ENTRY         = 0x00010000, /**<[GB]   [uc,mc] FDB,ptp mac address, using for MAC DA */
    CTC_L2_FLAG_SELF_ADDRESS      = CTC_L2_FLAG_PTP_ENTRY, /**<[GG]   [uc,mc] indicate that mac addres is switch's */
    CTC_L2_FLAG_WHITE_LIST_ENTRY  = 0x00020000, /**<[GB.GG] unicast FDB with nexthop, if set , indicate this entry won't do aging but will do learning */
    CTC_L2_FLAG_REMOVE_DYNAMIC    = 0x00040000, /**<[GG] Only remove dynamic entry, using for MAC SA*/
    CTC_L2_FLAG_ASSIGN_OUTPUT_PORT    = 0x00080000, /**<[GG] DestId assigned by user */

    MAX_CTC_L2_FLAG
};
typedef enum ctc_l2_flag_e ctc_l2_flag_t;



/**
 @brief  define l2 FDB entry sync flags
*/
enum ctc_l2_sync_msg_flag_e
{
    CTC_L2_SYNC_MSG_FLAG_IS_LOGIC_PORT      = 0x00000001, /**<[GB] If set, indicate gport is logic port , else is normal port */
    CTC_L2_SYNC_MSG_FLAG_IS_AGING           = 0x00000002  /**<[GB] If set, indicate entry is aging sync, else is learning sync*/
};
typedef enum ctc_l2_sync_msg_flag_e ctc_l2_sync_msg_flag_t;


/**
 @brief define vlan property flags
*/
enum ctc_l2_dft_vlan_flag_e
{
    CTC_L2_DFT_VLAN_FLAG_UNKOWN_UCAST_DROP   = 0x00000001,  /**<[HB,GB] Unknown unicast discard in specific VLAN */
    CTC_L2_DFT_VLAN_FLAG_UNKOWN_MCAST_DROP   = 0x00000002,  /**<[HB,GB] Unknown multicast discard in specific VLAN */
    CTC_L2_DFT_VLAN_FLAG_PROTOCOL_EXCP_TOCPU = 0x00000004,  /**<[HB,GB,GG] Protocol exception to cpu in in specific VLAN */
    CTC_L2_DFT_VLAN_FLAG_USE_LOGIC_PORT      = 0x00000010,  /**<[GB,GG] Learning use logic-port per fid, */
    CTC_L2_DFT_VLAN_FLAG_LEARNING_DISABLE    = 0x00000020,  /**<[GB] learning disable per default entry */
    CTC_L2_DFT_VLAN_FLAG_ASSIGN_OUTPUT_PORT    = 0x00000040, /**<[GG] DestId assigned by user, this is used for member */

    MAX_CTC_L2_DFT_VLAN_FLAG
};
typedef enum ctc_l2_dft_vlan_flag_e ctc_l2_dft_vlan_flag_t;


/**
 @brief [GG] Create fid property flag param
*/
enum ctc_l2_fid_property_e
{
    CTC_L2_FID_PROP_LEARNING,                    /**<[GG] Learning enable per fid*/
    CTC_L2_FID_PROP_IGMP_SNOOPING,               /**<[GG] Igmp snooping enable per fid*/
    CTC_L2_FID_PROP_DROP_UNKNOWN_UCAST,          /**<[GG] Drop unknown ucast packet enable per fid*/
    CTC_L2_FID_PROP_DROP_UNKNOWN_MCAST,          /**<[GG] Drop unknown mcast packet enable per fid*/
    CTC_L2_FID_PROP_IGS_STATS_EN,                /**<[GG] Enable/Disable ingress vsi stats. value is stats_id, 0 means disable*/
    CTC_L2_FID_PROP_EGS_STATS_EN                 /**<[GG] Enable/Disable egress vsi stats. value is stats_id, 0 means disable*/
};
typedef enum ctc_l2_fid_property_e  ctc_l2_fid_property_t;


/**
 @brief  define l2 FDB entry type flags
*/
enum ctc_l2_fdb_entry_op_type_e
{
    CTC_L2_FDB_ENTRY_OP_BY_VID,       /**<[HB,GB,GG] operation BY FID(VLAN/VSI)*/
    CTC_L2_FDB_ENTRY_OP_BY_PORT,      /**<[HB,GB,GG] operation BY PORT(VLAN/VSI)*/
    CTC_L2_FDB_ENTRY_OP_BY_MAC,       /**<[HB,GB,GG] operation BY MA(VLAN/VSI)*/
    CTC_L2_FDB_ENTRY_OP_BY_PORT_VLAN, /**<[HB,GB,GG] operation BY PORT + FID(VLAN/VSI)*/
    CTC_L2_FDB_ENTRY_OP_BY_MAC_VLAN,  /**<[HB,GB,GG] operation BY MAC+FID(VLAN/VSI)*/
    CTC_L2_FDB_ENTRY_OP_ALL,          /**<[HB,GB,GG] operation BY ALL(VLAN/VSI)*/
    MAX_CTC_L2_FDB_ENTRY_OP
};
typedef enum ctc_l2_fdb_entry_op_type_e ctc_l2_flush_fdb_type_t;
typedef enum ctc_l2_fdb_entry_op_type_e ctc_l2_fdb_query_type_t;

/**
 @brief define l2 FDB flush flag
*/
enum ctc_l2_fdb_entry_flag_e
{
    CTC_L2_FDB_ENTRY_STATIC,        /**<[HB,GB,GG] all static fdb record */
    CTC_L2_FDB_ENTRY_DYNAMIC,       /**<[HB,GB,GG] all dynamic fdb record */
    CTC_L2_FDB_ENTRY_LOCAL_DYNAMIC, /**<[HB,GB,GG] all local chip's dynamic fdb record */
    CTC_L2_FDB_ENTRY_ALL,           /**<[HB,GB,GG] all fdb record */
    MAX_CTC_L2_FDB_ENTRY_FLAG
};
typedef enum ctc_l2_fdb_entry_flag_e ctc_l2_flush_fdb_flag_t;
typedef enum ctc_l2_fdb_entry_flag_e ctc_l2_fdb_query_flag_t;

/**
 @brief define source port type
*/
enum ctc_l2_fdb_src_port_e
{
    CTC_L2_FDB_SRC_PORT_TYPE_NORMAL = 0,       /**<[HB] from normal port */
    CTC_L2_FDB_SRC_PORT_TYPE_LOGIC = 1,        /**<[HB] from logic  port */
    MAX_CTC_L2_FDB_SRC_PORT_TYPE
};
typedef enum ctc_l2_fdb_src_port_e ctc_l2_fdb_src_port_t;


/**
 @brief Device-independent L2 unicast address
*/
struct ctc_l2_addr_s
{
    mac_addr_t mac;             /**<[HB,GB,GG] 802_3 MAC address */
    uint16  mask_valid;         /**<[HB,GB] mac address mask valid*/
    mac_addr_t mask;            /**<[HB,GB] mac address mask */

    uint16  fid;                /**<[HB,GB,GG] vid or fid ,if fid == 0xFFFF,indicate vlan will be masked */
    uint32 gport;              /**<[HB,GB,GG] The following two case,the gport is destination and soure port;
                                                 1.1 Use l2_add_fdb to add fdb ;
                                                 1.2 Use l2_add_fdb_with_nexthop to add fdb && FDB use gport to learning FDB
                                                    && CTC_L2_FLAG_ASSIGN_OUTPUT_PORT set.
                                               2.  else the gport is soure port; */
    uint32  flag;               /**<[HB,GB,GG] ctc_l2_flag_t  CTC_L2_xxx flags */

    /* the following info only use for vpls/qinq serverce queue appication/PBB */
    ctc_l2_fdb_src_port_t gsrcport_type;  /**<[HB] src port type */
    uint16  logic_port;       /**<[HB] if CTC_L2_FLAG_LEARNING_USE_LOGIC_PORT set */
    uint32  assign_port;    /**<[GG]using for CTC_L2_FLAG_ASSIGN_OUTPUT_PORT, means destination Port*/
};
typedef struct ctc_l2_addr_s ctc_l2_addr_t;


/**
 @brief Device-independent L2 sync address
*/
struct ctc_l2_sync_msg_s
{
    mac_addr_t mac;             /**<[GB] 802_3 MAC address */

    uint16  fid;                /**<[GB] vid or fid ,if fid == 0xFFFF,indicate vlan will be masked */
    uint32 gport;              /**<[GB] Port ID ,if CTC_L2_SYNC_FLAG_IS_LOGIC_PORT set is logic port, else is gport; */
    uint32  flag;               /**<[GB] ctc_l2_sync_flag_t  CTC_L2_SYNC_xxx flags */
    uint32  index;            /**<[GB] fdb entry key index in chip*/
};
typedef struct ctc_l2_sync_msg_s ctc_l2_sync_msg_t;

/**
 @brief define FDB query DS
*/
struct ctc_l2_fdb_query_s
{
    mac_addr_t mac;            /**<[HB,GB,GG] 802_3 MAC address */
    uint16     fid;            /**<[HB,GB,GG] vid or fid */
    uint32     count;          /**<[HB,GB,GG] (out) return fdb count */
    uint32 gport;          /**<[HB,GB,GG] FDB Port ID */
    uint8      query_type;     /**<[HB,GB,GG] ctc_l2_fdb_query_type_t */
    uint8      query_flag;     /**<[HB,GB,GG] ctc_l2_fdb_query_flag_t */
    uint8      use_logic_port; /**<[GB,GG] gport is used as logic port */
    uint8      query_hw;          /**<[GB,GG] dump hash key by hardware, only support by hardware leaning */
    uint8      rsv0[2];
};
typedef struct ctc_l2_fdb_query_s ctc_l2_fdb_query_t;

/**
 @brief  Store FDB entries query results,the results contain ucast fdb entries
*/
struct ctc_l2_fdb_query_rst_s
{
    ctc_l2_addr_t* buffer;      /**<[HB,GB,GG] [in/out] A buffer store query results */
    uint32  start_index;        /**<[HB,GB,GG] If it is the first query, it is equal to 0, else it is equal to the last next_query_index */
    uint32  next_query_index;   /**<[HB,GB,GG] [out] return index of the next query */
    uint8   is_end;             /**<[HB,GB,GG] [out] if is_end == 1, indicate the end of query */
    uint8   rsv;                /**< reserved*/
    uint16  buffer_len;         /**<[HB,GB,GG] multiple of sizeof(ctc_l2_addr_t) */

};
typedef struct ctc_l2_fdb_query_rst_s ctc_l2_fdb_query_rst_t;

/**
 @brief  Flush FDB entries data structure
*/
struct ctc_l2_flush_fdb_s
{
    mac_addr_t mac;             /**<[HB,GB,GG] 802_3 MAC address */
    uint16 fid;                 /**<[HB,GB,GG] vid or fid */
    uint32 gport;               /**<[HB,GB,GG] FDB Port ID */
    uint8  flush_flag;          /**<[HB,GB,GG] ctc_l2_flush_fdb_flag_t */
    uint8  flush_type;          /**<[HB,GB,GG] ctc_l2_flush_fdb_type_t */
    uint8  use_logic_port;      /**<[GB,GG] gport is used as logic port */
    uint8  rsv0[3];
};
typedef  struct ctc_l2_flush_fdb_s ctc_l2_flush_fdb_t;

/**@} end of @defgroup  fdb FDB */

/**
 @defgroup l2mcast L2Mcast
 @{
*/
/**
 @brief Device-independent L2 multicast address
*/
struct ctc_l2_mcast_addr_s
{
    mac_addr_t mac;             /**<[HB,GB,GG] 802_3 MAC address */
    uint16  fid;                /**<[HB,GB,GG] vid or fid */
    uint32  flag;               /**<[HB,GB,GG] ctc_l2_flag_t  CTC_L2_xxx flags */
    uint16  l2mc_grp_id;        /**<[HB,GB,GG] mcast group_id, it only valid when add mcast group,and unique over the switch system */
    uint8   member_invalid;     /**<[HB,GB,GG] if set, member will be invalid,maybe applied to add/remove mcast group */
    uint8   with_nh;            /**<[HB,GB,GG] if set, packet will be edited by nhid */
    struct
    {
        uint32   mem_port;      /**<[HB,GB,GG] member port if member is local member  gport:gchip(8bit) +local phy port(8bit);
                                                    else if member is remote chip entry,gport: gchip(local) + remote gchip id(8bit)*/
        uint32   nh_id;         /**<[HB,GB,GG] packet will be edited by nhid*/
    } member;
    bool remote_chip;           /**<[HB] if set,member is remote chip entry*/
};
typedef struct ctc_l2_mcast_addr_s ctc_l2_mcast_addr_t;
/**
 @brief Device-independent L2 default information address
*/
struct ctc_l2dflt_addr_s
{
    /* create default entry, only need flag, fid, l2mc_grp_id. */
    uint32   flag;               /**<[HB,GB,GG] ctc_l2_dft_vlan_flag_t  CTC_L2_DFT_VLAN_FLAG_xxx flags */
    uint16   fid;                /**<[HB,GB,GG] vid or fid */
    uint32 gport;              /**<[HB] port as default entry key */
    uint16   l2mc_grp_id;        /**<[HB,GB,GG] mcast group_id, it only valid when add default entry,and unique over the switch system */


    uint8    port_valid;         /**<[HB] if set,indicate port as default entry key is valid*/
    uint8    with_nh;            /**<[HB,GB,GG] if set, packet will be edited by nhid */
    uint16   logic_port;         /**<[HB,GB,GG] if CTC_L2_FLAG_LEARNING_USE_LOGIC_PORT set,indicate logic Port is valid */
    uint16   rsv0;
    struct
    {
        uint32   mem_port;       /**<[HB,GB,GG]  member port if member is local member  gport:gchip(8bit) +local phy port(8bit);
                                                    else if member is remote chip entry,gport: gchip(local) + remote gchip id(8bit) */
        uint32   nh_id;          /**<[HB,GB,GG]  packet will be edited by nhid */
    } member;

    uint8    port_unattged;      /**<[HB] if set, out packet will untagged packet from the member port,only for humber. */
    uint8    remote_chip;        /**<[HB,GB,GG] if set,member is remote chip entry*/
    uint8    port_srv_queue;     /**<[HB] if set, out packet will  enqueue by service id,only for humber. */
    uint8    rsv1;
};
typedef struct ctc_l2dflt_addr_s ctc_l2dflt_addr_t;


/**@} end of @defgroup  l2mcast L2Mcast */

/**
 @defgroup stp STP
 @{
 */
#define CTC_STP_NUM    0x80
#define CTC_MAX_STP_ID 0x7F
#define CTC_MIN_STP_ID 0
enum stp_state_e
{
    CTC_STP_FORWARDING  = 0x00,     /**<[HB,GB,GG] stp state, packet normal forwarding */
    CTC_STP_BLOCKING    = 0x01,     /**<[HB,GB,GG] stp state, packet blocked */
    CTC_STP_LEARNING    = 0x02,     /**<[HB,GB,GG] stp state, learning enable */
    CTC_STP_UNAVAIL      = 0x03
};
/**@} end of @defgroup  stp STP */

/**
 @brief stp mode
*/
enum ctc_l2_stp_mode_e
{
    CTC_STP_MODE_128, /**<[GG] 128 stp instance per port */
    CTC_STP_MODE_64,  /**<[GG] 64 stp instance per port */
    CTC_STP_MODE_32,  /**<[GG] 32 stp instance per port */

    CTC_STP_MODE_MAX
};
typedef enum ctc_l2_stp_mode_e ctc_l2_stp_mode_t;

/**
 @brief l2 fdb global config information
*/
struct ctc_l2_fdb_global_cfg_s
{
    uint32 flush_fdb_cnt_per_loop;  /**<[HB,GB,GG] flush flush_fdb_cnt_per_loop entries one time if flush_fdb_cnt_per_loop>0,
                                         flush all entries if flush_fdb_cnt_per_loop=0 */
    uint32 logic_port_num;          /**<[GB,GG] num of logic port */
    uint16 default_entry_rsv_num;   /**<[HB,GB,GG] Systems reserve the number of default entry,example:
                                       if systems support per FID default entry,and systems support FID ranges:1-4094,
                                       it's equal to 4094; if systems support FID ranges:100-200, it's equal to 100
                                       [GB,GG] use it as the max fid num*/

    uint8 hw_learn_en;              /**<[GB,GG] global hardware learning  */
    uint8 stp_mode;                 /**<[GG] stp instance mode, refer to ctc_l2_stp_mode_t */
    uint8 rsv[2];
};
typedef struct ctc_l2_fdb_global_cfg_s ctc_l2_fdb_global_cfg_t;

#ifdef __cplusplus
}
#endif

#endif  /*_CTC_L2_H*/

