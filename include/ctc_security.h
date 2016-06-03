/**
 @file ctc_security.h

 @author  Copyright (C) 2011 Centec Networks Inc.  All rights reserved.

 @date 2010-2-4

 @version v2.0

   This file contains all security related data structure, enum, macro and proto.
*/

#ifndef _CTC_SECURITY_H_
#define _CTC_SECURITY_H_
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

/**
 @defgroup security SECURITY
 @{
*/

/**
 @brief Security action type used in ip source guard
*/
enum ctc_security_action_type_e
{
    CTC_SECURITY_ACTION_TYPE_FWD,              /**< [HB] Packet will be forwarding nomally*/
    CTC_SECURITY_ACTION_TYPE_COPY_TO_CPU,      /**< [HB] Packet will be copy to cpu and forwarding*/
    CTC_SECURITY_ACTION_TYPE_REDIRECT_TO_CPU,  /**< [HB] Packet will be redirect to cpu only*/
    CTC_SECURITY_ACTION_TYPE_DISCARD           /**< [HB] Packet will be discard*/
};
typedef enum ctc_security_action_type_e ctc_security_action_type_t;

/**
 @brief Security mac limit action type
*/
enum ctc_maclimit_action_e
{
    CTC_MACLIMIT_ACTION_NONE,     /**< [HB.GB.GG] Packet will forwarding and learning mac if reach mac learning limitation*/
    CTC_MACLIMIT_ACTION_FWD,      /**< [HB.GB.GG] Packet will forwarding but no learning mac if reach mac learning limitation*/
    CTC_MACLIMIT_ACTION_DISCARD,  /**< [HB.GB.GG] Packet will discard and no learning mac if reach mac learning limitation*/
    CTC_MACLIMIT_ACTION_TOCPU     /**< [HB.GB.GG] Packet will discard and no learning, redirect to cpu if reach mac learning limitation*/
};
typedef enum ctc_maclimit_action_e ctc_maclimit_action_t;

/**
 @brief Security ip source guard type
*/
enum ctc_security_ip_source_guard_type_e
{
    CTC_SECURITY_BINDING_TYPE_IP,           /**< [HB.GB.GG] Check item ip*/
    CTC_SECURITY_BINDING_TYPE_IP_VLAN,      /**< [HB.GB.GG] Check item ip and vlan*/
    CTC_SECURITY_BINDING_TYPE_IP_MAC,       /**< [HB.GB.GG] Check item ip and mac*/
    CTC_SECURITY_BINDING_TYPE_IPV6_MAC,     /**< [HB.GB.GG] Check item ipv6 and mac*/
    CTC_SECURITY_BINDING_TYPE_IP_MAC_VLAN,  /**< [HB.GB.GG] Check item ip and mac and vlan*/
    CTC_SECURITY_BINDING_TYPE_MAC,          /**< [GB.GG] Check item mac*/
    CTC_SECURITY_BINDING_TYPE_MAC_VLAN,     /**< [GB.GG] Check item mac and vlan*/
    CTC_SECURITY_BINDING_TYPE_MAX
};
typedef enum ctc_security_ip_source_guard_type_e ctc_security_ip_source_guard_type_t;

/**
 @brief Security storm control operation type
*/
enum ctc_security_storm_ctl_op_e
{
    CTC_SECURITY_STORM_CTL_OP_PORT, /**< [GB.GG] Port based strorm control*/
    CTC_SECURITY_STORM_CTL_OP_VLAN, /**< [GB.GG] Vlan based strorm control*/
    CTC_SECURITY_STORM_CTL_OP_MAX
};
typedef enum ctc_security_storm_ctl_op_e ctc_security_storm_ctl_op_t;

/**
 @brief Security storm control type
*/
enum ctc_security_storm_ctl_type_e
{
    CTC_SECURITY_STORM_CTL_BCAST,          /**< [HB.GB.GG] Broadcast storm control*/
    CTC_SECURITY_STORM_CTL_KNOWN_MCAST,    /**< [HB.GB.GG] Known multicast storm control*/
    CTC_SECURITY_STORM_CTL_UNKNOWN_MCAST,  /**< [HB.GB.GG] Unknown multicast storm control*/
    CTC_SECURITY_STORM_CTL_ALL_MCAST,      /**< [HB.GB.GG] Known and unknown multicast storm control*/
    CTC_SECURITY_STORM_CTL_KNOWN_UCAST,    /**< [HB.GB.GG] Known unicast storm control*/
    CTC_SECURITY_STORM_CTL_UNKNOWN_UCAST,  /**< [HB.GB.GG] Unknown unicast storm control*/
    CTC_SECURITY_STORM_CTL_ALL_UCAST,      /**< [HB.GB.GG] Known and unknown unicast storm control*/
    CTC_SECURITY_STORM_CTL_MAX
};
typedef enum ctc_security_storm_ctl_type_e ctc_security_storm_ctl_type_t;

/**
 @brief Security storm control mode
*/
enum ctc_security_storm_ctl_mode_e
{
    CTC_SECURITY_STORM_CTL_MODE_PPS,    /**< [HB.GB.GG] Packet per second*/
    CTC_SECURITY_STORM_CTL_MODE_BPS,    /**< [HB.GB.GG] Bytes per second*/
    CTC_SECURITY_STORM_CTL_MODE_KPPS,   /**< [GG] K Packet per second*/
    CTC_SECURITY_STORM_CTL_MODE_KBPS,   /**< [HB] K Bytes per second*/
    CTC_SECURITY_STORM_CTL_MODE_MAX
};
typedef enum ctc_security_storm_ctl_mode_e ctc_security_storm_ctl_mode_t;

/**
 @brief Security storm control granularity
*/
enum ctc_security_storm_ctl_granularity_e
{
    CTC_SECURITY_STORM_CTL_GRANU_100,    /**< [GB.GG] Granularity is 100   bps or pps*/
    CTC_SECURITY_STORM_CTL_GRANU_1000,   /**< [GB.GG] Granularity is 1000  bps or pps*/
    CTC_SECURITY_STORM_CTL_GRANU_10000,  /**< [GB] Granularity is 10000 bps or pps*/
    CTC_SECURITY_STORM_CTL_GRANU_5000,   /**< [GG] Granularity is 5000 bps or pps*/

    CTC_SECURITY_STORM_CTL_GRANU_MAX
};
typedef enum ctc_security_storm_ctl_granularity_e ctc_security_storm_ctl_granularity_t;

/**
 @brief Secuirty learn limit type
*/
enum ctc_security_learn_limit_type_e
{
    CTC_SECURITY_LEARN_LIMIT_TYPE_PORT,       /**< [GG] Learn limit for port*/
    CTC_SECURITY_LEARN_LIMIT_TYPE_VLAN,       /**< [GG] Learn limit for vlan*/
    CTC_SECURITY_LEARN_LIMIT_TYPE_SYSTEM,    /**< [GG] Learn limit for system*/

    CTC_SECURITY_LEARN_LIMIT_TYPE_MAX
};
typedef enum ctc_security_learn_limit_type_e ctc_security_learn_limit_type_t;


/**
 @brief Secuirty data structure for learn limit
*/
struct ctc_security_learn_limit_s
{
    ctc_security_learn_limit_type_t  limit_type;        /**< [GG] Learn limit type must be ctc_security_learn_limit_type_t. */

    uint32 gport;                                      /**< [GG] Global source port when limit_type is  CTC_SECURITY_LEARN_LIMIT_TYPE_PORT*/
    uint16 vlan;                                        /**< [GG] Vlan ID when limit_type is  CTC_SECURITY_LEARN_LIMIT_TYPE_VLAN */

    uint32 limit_num;                                /**< [GG] mac limit threshold */
    uint32 limit_action;                             /**< [GG] action when reach threshold, refer to ctc_maclimit_action_t */
};
typedef struct ctc_security_learn_limit_s ctc_security_learn_limit_t;

/**
 @brief Security data structure for ip source guard
*/
struct ctc_security_ip_source_guard_elem_s
{
    ctc_security_ip_source_guard_type_t ip_src_guard_type;  /**< [HB.GB.GG] Ip source guard type referred to ctc_security_ip_source_guard_type_t*/
    mac_addr_t mac_sa;                                      /**< [HB.GB.GG] Source mac address */
    ipv6_addr_t ipv6_sa;                                    /**< [HB.GB.GG] Source ipv6 address */
    ip_addr_t ipv4_sa;                                      /**< [HB.GB.GG] Source ipv4 address */
    uint16 vid;                                             /**< [HB.GB.GG] Vlan id */
    uint32 gport;                                           /**< [HB.GB.GG] Global port, if ip_src_guard_type is CTC_SECURITY_BINDING_TYPE_IPV6_MAC,
                                                                            gport can not be used to be binding */
    uint8 is_svlan;                                         /**< [HB] Judge svlan or cvlan*/
    uint8 ipv4_or_ipv6;                                     /**< [HB.GB.GG] Judge use ipv4 or ipv6 */
};
typedef struct ctc_security_ip_source_guard_elem_s ctc_security_ip_source_guard_elem_t;

/**
 @brief Secuirty data structure for storm control per port
*/
struct ctc_security_stmctl_cfg_s
{
    ctc_security_storm_ctl_type_t type;  /**< [HB.GB.GG] Type for storm control */
    ctc_security_storm_ctl_mode_t mode;  /**< [HB.GB.GG] Mode for storm control */
    uint32 gport;                       /**< [HB.GB.GG] Port based  storm control */
    uint8    storm_en;                   /**< [HB.GB.GG] Storm control enable */
    uint8    discarded_to_cpu;           /**< [HB.GB.GG] Discarded packet by storm control and redirect to cpu */
    uint32   threshold;                  /**< [HB.GB.GG] Threshold for storm control, according to mode */
    uint8    op;                         /**< [GB.GG] Base is vlan or port storm ctl, refer to ctc_security_storm_ctl_op_t*/
    uint8    rsv0;
    uint16  vlan_id;                     /**< [GB.GG] Vlan based  storm control */

};
typedef struct ctc_security_stmctl_cfg_s ctc_security_stmctl_cfg_t;

/**
 @brief Secuirty data structure for storm control global
*/
struct ctc_security_stmctl_glb_cfg_s
{
    uint8 ipg_en;           /**< [HB.GB.GG] Ipg is considered in storm control operation */
    uint8 ustorm_ctl_mode;  /**< [HB.GB.GG] If set, known and unknown unicast storm is separated */
    uint8 mstorm_ctl_mode;  /**< [HB.GB.GG] If set, known and unknown multicast storm is separated */
    uint8 rsv;
    uint16 granularity;     /**< [GB.GG] Granularity for storm control, ctc_security_storm_ctl_granularity_t */
};
typedef struct ctc_security_stmctl_glb_cfg_s ctc_security_stmctl_glb_cfg_t;

/**@} end of @defgroup  security SECURITY */

#ifdef __cplusplus
}
#endif

#endif

