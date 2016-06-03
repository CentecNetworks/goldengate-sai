/**
 @file ctc_mirror.h

 @date 2010-1-7

 @version v2.0

 This file define the types used in APIs

*/

#ifndef _MIRROR_H
#define _MIRROR_H
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
 @defgroup mirror MIRROR
 @{
*/
/**
 @brief define max session id
*/
#define MAX_CTC_MIRROR_SESSION_ID  4  /**< [HB.GB.GG] mirror max session num*/
/**
 @brief Denote setting session
*/
enum ctc_mirror_session_type_e
{
    CTC_MIRROR_L2SPAN_SESSION = 0,  /**< [HB.GB.GG] mirror l2span session*/
    CTC_MIRROR_L3SPAN_SESSION = 1,  /**< [HB.GB.GG] mirror l3span session*/
    CTC_MIRROR_ACLLOG_SESSION = 2,  /**< [HB.GB.GG] mirror acllog session*/
    CTC_MIRROR_CPU_SESSION    = 3,  /**< [GB.GG] mirror cpu session*/
    MAX_CTC_MIRROR_SESSION_TYPE = 4
};
typedef enum ctc_mirror_session_type_e ctc_mirror_session_type_t;

#define    CTC_MIRROR_ERSPAN_PSC_IPV4_FLAG_L4_PORT       0x00000001
#define    CTC_MIRROR_ERSPAN_PSC_IPV4_FLAG_IP_ADDR       0x00000002
#define    CTC_MIRROR_ERSPAN_PSC_IPV4_FLAG_IS_UDP        0x00000004
#define    CTC_MIRROR_ERSPAN_PSC_IPV4_FLAG_IS_TCP        0x00000008

#define    CTC_MIRROR_ERSPAN_PSC_IPV6_FLAG_L4_PORT       0x00000001
#define    CTC_MIRROR_ERSPAN_PSC_IPV6_FLAG_IP_ADDR       0x00000002
#define    CTC_MIRROR_ERSPAN_PSC_IPV6_FLAG_IS_UDP        0x00000004
#define    CTC_MIRROR_ERSPAN_PSC_IPV6_FLAG_IS_TCP        0x00000008

#define    CTC_MIRROR_ERSPAN_PSC_TYPE_IPV4   0x1
#define    CTC_MIRROR_ERSPAN_PSC_TYPE_IPV6   0x2

struct ctc_mirror_erspan_psc_s
{
    uint32  type;       /**< [GG] refer CTC_MIRROR_ERSPAN_PSC_TYPE_XXX*/
    uint32  ipv4_flag;  /**< [GG] refer CTC_MIRROR_ERSPAN_PSC_IPV4_FLAG_XXX, 0 meaning disable */
    uint32  ipv6_flag;  /**< [GG] refer CTC_MIRROR_ERSPAN_PSC_IPV6_FLAG_XXX, 0 meaning disable */
};
typedef struct ctc_mirror_erspan_psc_s ctc_mirror_erspan_psc_t;

/**
 @brief Denote setting port/vlan mirror drop packet
*/
enum ctc_mirror_discard_e
{
    CTC_MIRROR_L2SPAN_DISCARD = 0x1,      /**< [HB.GB.GG] mirror qos session drop packet*/
    CTC_MIRROR_L3SPAN_DISCARD = 0x2,      /**< [HB.GB.GG] mirror vlan session drop packet*/
    CTC_MIRROR_ACLLOG_PRI_DISCARD = 0x4   /**< [HB.GB.GG] mirror acl priority session drop packet*/
};
typedef enum ctc_mirror_discard_e ctc_mirror_discard_t;

/**
 @brief Denote mirror port/vlan/acl nexthop info
*/
enum ctc_mirror_info_type_e
{
    CTC_MIRROR_INFO_PORT,                /**< [GB.GG] port mirror info */
    CTC_MIRROR_INFO_VLAN,                /**< [GB.GG] vlan mirror info */
    CTC_MIRROR_INFO_ACL,                 /**< [GB.GG] acl mirror info */
    CTC_MIRROR_INFO_NUM
};
typedef enum ctc_mirror_info_type_e ctc_mirror_info_type_t;

/**
 @brief Define mirror source information used in Mirror API
*/
struct ctc_mirror_dest_s
{
    uint8   acl_priority;  /**< [HB.GB.GG] GB and GG: mirror acl priority 0,1,2,3; HB: mirror acl priority 0,1*/
    uint8   session_id;    /**< [HB.GB.GG] mirror session id, range<0-3>; HB: for aclqos log, range<0-2>, 3 is reserved*/
    uint8   is_rspan;      /**< [HB.GB.GG] if set, session is remote mirror; if not set, session is local mirror*/
    uint8   vlan_valid;    /**< [HB.GB.GG] used in remote mirror, if set, remote mirror edit info by rspan.vlan_id; Otherwise, by rspan.nh_id*/
    uint32 dest_gport;     /**< [HB.GB.GG] mirror destination global port*/
    union
    {
        uint16 vlan_id;  /**< [HB.GB.GG] rspan over L2*/
        uint32 nh_id;    /**< [HB.GB.GG] rspan edit info by nexthop*/
    } rspan;
    ctc_mirror_session_type_t type;  /**< [HB.GB.GG] mirror session type, see enum ctc_mirror_session_type_t*/
    ctc_direction_t dir;             /**< [HB.GB.GG] direction of mirror, ingress or egress*/
};
typedef struct ctc_mirror_dest_s ctc_mirror_dest_t;

/**
 @brief Defien rspan escape info, packet with this info will be not mirror
*/
struct ctc_mirror_rspan_escape_s
{
    mac_addr_t mac0;       /**< [HB.GB.GG] mac0 value,all should be 0 if no care*/
    mac_addr_t mac_mask0;  /**< [HB.GB.GG] mac0 mask, all should be 0xFF if no care*/
    mac_addr_t mac1;       /**< [HB.GB.GG] mac1 value,all should be 0 if no care*/
    mac_addr_t mac_mask1;  /**< [HB.GB.GG] mac1 mask, all should be 0xFF if no care*/
};
typedef struct ctc_mirror_rspan_escape_s ctc_mirror_rspan_escape_t;

/**@} end of @defgroup mirror  */

#ifdef __cplusplus
}
#endif

#endif

