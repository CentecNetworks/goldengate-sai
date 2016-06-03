/**
 @file ctc_aps.h

 @date 2010-3-10

 @version v2.0

 The file define all struct used in aps APIs.
*/

#ifndef _CTC_APS_H
#define _CTC_APS_H
#ifdef __cplusplus
extern "C" {
#endif

/****************************************************************
 *
 * Header Files
 *
 ***************************************************************/

#include "sal_types.h"
/****************************************************************
*
* Defines and Macros
*
****************************************************************/

/**
 @addtogroup aps APS
 @{
*/
enum ctc_aps_flag_e
{
    CTC_APS_FLAG_IS_L2             = 0x00000001, /**< [GB.GG] Used for indicate l2 aps protection */
    CTC_APS_FLAG_IS_MPLS           = 0x00000002, /**< [GB.GG] Used for indicate mpls aps protection */
    MAX_CTC_APS_FLAG
};
typedef enum ctc_aps_flag_e ctc_aps_flag_t;

/**
 @brief Define APS type
*/
enum ctc_aps_type_e
{
    CTC_APS_DISABLE,   /**<[HB] APS disable */
    CTC_APS_SELECT=2,     /**< [HB.GB] APS selector */
    CTC_APS_BRIDGE=3,      /**< [HB.GB] APS bridge */
    CTC_APS_TYPE_MAX
};
typedef enum ctc_aps_type_e ctc_aps_type_t;

/**
 @brief  Define Nexthop outgoing interface information structure
*/
struct ctc_aps_oif_info_s
{
    uint32 gport;           /**< [HB] Outgoing global port */
    uint16 vid;             /**< [HB] Outgoing vlan id ,when vid = 4095,the vid is invalid,
                                  if vlan port is normal L2 interface and vlan is valid,
                                   the vlan will be used to get egress vlan property */
};
typedef struct ctc_aps_oif_info_s ctc_aps_oif_info_t;

struct aps_l3if_port_s
{
    ctc_aps_oif_info_t w_wport;   /**< [HB] Working_path work port */
    ctc_aps_oif_info_t w_pport;    /**< [HB] Working_path protection port */
    ctc_aps_oif_info_t p_wport;    /**< [HB] Protection_path work port */
    ctc_aps_oif_info_t p_pport;     /**< [HB] Protection_path protection port */
    bool next_w_en;    /**< [HB] Indicate w_pport is use or not */
    bool next_p_en;     /**< [HB] Indicate p_pport is use or not */
};
typedef struct aps_l3if_port_s aps_l3if_port_t;

/**
 @brief Define MPLS APS Next Bridge group
*/
struct ctc_aps_next_aps_s
{
    uint16 w_group_id;                  /**< [GB.GG] Next working aps bridge group id */
    uint16 p_group_id;                  /**< [GB.GG] Next protection aps bridge group id */
};
typedef struct ctc_aps_next_aps_s ctc_aps_next_aps_t;

/**
 @brief Define APS Bridge group
*/
struct ctc_aps_bridge_group_s
{
    uint32 working_gport;               /**< [HB.GB.GG] APS bridge working path for mpls aps indicate l3if id */
    uint32 protection_gport;            /**< [HB.GB.GG] APS bridge protection path for mpls aps indicate l3if id */

    uint16 w_l3if_id;                   /**< [GB.GG] Working l3if id */
    uint16 p_l3if_id;                   /**< [GB.GG] Protection l3if id */

    ctc_aps_next_aps_t next_aps;        /**< [GB.GG] Next aps group */

    uint8 next_w_aps_en;                 /**< [GB.GG] Use next_w_aps neglect working_gport */
    uint8 next_p_aps_en;                 /**< [GB.GG] Use next_w_aps neglect protection_gport */
    uint8 protect_en;                    /**< [HB.GB.GG] For bridge switch */
    uint8 aps_flag;                    /**< [GB.GG] APS flag,ctc_aps_flag_t */

    uint8 physical_isolated;          /**< [GB.GG] Indicate port aps use physical isolated path */

    uint8 raps_en;                       /**< [HB.GB.GG] Indicate raps whether enable */
    uint16 raps_group_id;               /**< [HB.GB.GG] Raps mcast group id */

    uint8 aps_failover_en;              /**< [GB.GG] Indicate link down use hw based port level aps */
    uint8 rsv[3];
};
typedef struct ctc_aps_bridge_group_s ctc_aps_bridge_group_t;

/**
 @brief Define R-APS member
*/
struct ctc_raps_member_s
{
    uint16 group_id;        /**< [HB.GB.GG] Mcast group id */
    uint32 mem_port;        /**< [HB.GB.GG] Member port if member is local member  gport:gchip(8bit) +local phy port(8bit);
                                            else if member is remote chip entry,gport: gchip(local) + remote gchip id(8bit)*/
    bool   remote_chip;     /**< [HB.GB.GG] If set,member is remote chip entry */
    bool   remove_flag;     /**< [HB.GB.GG] If set,remove member, else add member */

};
typedef struct ctc_raps_member_s ctc_raps_member_t;

/**@}*/ /*end of @addtogroup APS*/

#ifdef __cplusplus
}
#endif

#endif

