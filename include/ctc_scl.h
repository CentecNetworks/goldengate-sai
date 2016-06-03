/**
 @file ctc_scl.h

 @date 2013-02-21

 @version v2.0

 The file define api struct used in SCL.
*/

#ifndef _CTC_SCL_H_
#define _CTC_SCL_H_

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

/****************************************************************
*
* Data Structures
*
****************************************************************/

enum  ctc_scl_global_e
{
    CTC_SCL_MIN_USER_ENTRY_ID = 0,                       /**< [GB.GG.DT2] Min user entry id */
    CTC_SCL_MAX_USER_ENTRY_ID = 0x7FFFFFFF,       /**< [GB.GG.DT2] Max user entry id */
    CTC_SCL_GROUP_ID_MIN_NORMAL = 0,                  /**< [GB.GG.DT2] Min normal group id */
    CTC_SCL_GROUP_ID_MAX_NORMAL = 0xFFFF0000,  /**< [GB.GG.DT2] Max normal group id */
    CTC_SCL_KEY_SIZE_SINGLE = 0,                             /**< [GB.GG.DT2] Ipv4 tcam key use single size */
    CTC_SCL_KEY_SIZE_DOUBLE = 1                             /**< [GB.GG.DT2] Ipv4 tcam key use double size */
};
typedef enum ctc_scl_global_e ctc_scl_global_t;

/* Below groups are created already. just use it . */
/** @brief  SCL hash group id */
enum ctc_scl_group_id_hash_e
{
    CTC_SCL_GROUP_ID_HASH_PORT = 0xFFFF0001,                  /**< [GB.GG.DT2] Group id of hash port group */
    CTC_SCL_GROUP_ID_HASH_PORT_CVLAN = 0xFFFF0002,      /**< [GB.GG.DT2] Group id of hash port cvlan group */
    CTC_SCL_GROUP_ID_HASH_PORT_SVLAN = 0xFFFF0003,      /**< [GB.GG.DT2] Group id of hash port svlan group */
    CTC_SCL_GROUP_ID_HASH_PORT_2VLAN = 0xFFFF0004,      /**< [GB.GG.DT2] Group id of hash port double vlan group */
    CTC_SCL_GROUP_ID_HASH_PORT_CVLAN_COS = 0xFFFF0005, /**< [GB.GG.DT2] Group id of hash port cvlan cos group */
    CTC_SCL_GROUP_ID_HASH_PORT_SVLAN_COS = 0xFFFF0006, /**< [GB.GG.DT2] Group id of hash port svlan cos group */
    CTC_SCL_GROUP_ID_HASH_MAC = 0xFFFF0007,                       /**< [GB.GG.DT2] Group id of hash mac group */
    CTC_SCL_GROUP_ID_HASH_PORT_MAC = 0xFFFF0008,             /**< [GB.GG.DT2] Group id of hash port mac group */
    CTC_SCL_GROUP_ID_HASH_IPV4 = 0xFFFF0009,                      /**< [GB.GG.DT2] Group id of hash ipv4 group */
    CTC_SCL_GROUP_ID_HASH_PORT_IPV4 = 0xFFFF000A,            /**< [GB.GG.DT2] Group id of hash port ipv4 group */
    CTC_SCL_GROUP_ID_HASH_IPV6 = 0xFFFF000B,                       /**< [GB.GG.DT2] Group id of hash ipv6 group */
    CTC_SCL_GROUP_ID_HASH_L2 = 0xFFFF000C,                           /**< [GB.GG.DT2] Group id of hash layer 2 group */
    CTC_SCL_GROUP_ID_HASH_PORT_IPV6 = 0xFFFF000D,            /**< [GG.DT2] Group id of hash port ipv6 group */
    CTC_SCL_GROUP_ID_HASH_MAX = 0xFFFF000D                         /**< [GB.GG.DT2] Max group id of hash group */
};
typedef enum ctc_scl_group_id_hash_e ctc_scl_group_id_hash_t;

/** @brief  SCL Key Type */
enum ctc_scl_key_type_e
{
    CTC_SCL_KEY_TCAM_VLAN            ,  /**< [GB.GG] Tcam vlan key */
    CTC_SCL_KEY_TCAM_MAC             ,  /**< [GB.GG.DT2] Tcam mac key */
    CTC_SCL_KEY_TCAM_IPV4            ,  /**< [GB.GG.DT2] Tcam ipv4 key */
    CTC_SCL_KEY_TCAM_IPV4_SINGLE    ,  /**< [DT2] Tcam ipv4 single key */
    CTC_SCL_KEY_TCAM_IPV6            ,  /**< [GB.GG.DT2] Tcam ipv6 key */
    CTC_SCL_KEY_TCAM_IPV6_SINGLE    ,  /**< [DT2] Tcam ipv6 single key */
    CTC_SCL_KEY_HASH_PORT            ,  /**< [GB.GG.DT2] Hash port key */
    CTC_SCL_KEY_HASH_PORT_CVLAN      ,  /**< [GB.GG.DT2] Hash port cvlan key */
    CTC_SCL_KEY_HASH_PORT_SVLAN      ,  /**< [GB.GG.DT2] Hash port svlan key */
    CTC_SCL_KEY_HASH_PORT_2VLAN      ,  /**< [GB.GG.DT2] Hash port double vlan key */
    CTC_SCL_KEY_HASH_PORT_CVLAN_COS  ,  /**< [GB.GG.DT2] Hash port  cvlan cos key */
    CTC_SCL_KEY_HASH_PORT_SVLAN_COS  ,  /**< [GB.GG.DT2] Hash port svlan cos key */
    CTC_SCL_KEY_HASH_MAC             ,  /**< [GB.GG.DT2] Hash mac key */
    CTC_SCL_KEY_HASH_PORT_MAC        ,  /**< [GB.GG.DT2] Hash port mac key */
    CTC_SCL_KEY_HASH_IPV4            ,  /**< [GB.GG.DT2] Hash ipv4 key */
    CTC_SCL_KEY_HASH_PORT_IPV4       ,  /**< [GB.GG.DT2] Hash port ipv4 key */
    CTC_SCL_KEY_HASH_IPV6            ,  /**< [GB.GG.DT2] Hash ipv6 key */
    CTC_SCL_KEY_HASH_L2              ,  /**< [GB.GG.DT2] Hash layer 2 key */
    CTC_SCL_KEY_HASH_PORT_IPV6       ,  /**< [GG.DT2] Hash port ipv6 key */
    CTC_SCL_KEY_NUM
};
typedef enum ctc_scl_key_type_e ctc_scl_key_type_t;


#define  HASH_KEY

enum  ctc_scl_gport_type_e
{
    CTC_SCL_GPROT_TYPE_PORT,             /**< [GB.GG.DT2] global port */
    CTC_SCL_GPROT_TYPE_PORT_CLASS,       /**< [GB.GG.DT2] port class */
    CTC_SCL_GPROT_TYPE_LOGIC_PORT,       /**< [GG.DT2] logic port */
    CTC_SCL_GPROT_TYPE_NUM
};
typedef enum ctc_scl_gport_type_e ctc_scl_gport_type_t;

struct ctc_scl_hash_port_key_s
{
    uint32              gport;                  /**< [GB.GG.DT2] global port value */
    uint8               gport_type;             /**< [GB.GG.DT2] global port type: CTC_SCL_GPROT_TYPE_XXX */
    uint8               dir;                    /**< [GB.GG.DT2] refer to ctc_direction_t */
};
typedef struct ctc_scl_hash_port_key_s ctc_scl_hash_port_key_t;

struct ctc_scl_hash_port_cvlan_key_s
{
    uint32              gport;                  /**< [GB.GG.DT2] global port value */
    uint8               gport_type;             /**< [GB.GG.DT2] global port type: CTC_SCL_GPROT_TYPE_XXX */

    uint8               dir;                    /**< [GB.GG.DT2] refer to ctc_direction_t  */
    uint16              cvlan;                  /**< [GB.GG.DT2] cvlan id */
    uint8               rsv0[2];                /**< [GB.GG.DT2] */
};
typedef struct ctc_scl_hash_port_cvlan_key_s ctc_scl_hash_port_cvlan_key_t;

struct ctc_scl_hash_port_svlan_key_s
{
    uint32              gport;                  /**< [GB.GG.DT2] global port value */
    uint8               gport_type;             /**< [GB.GG.DT2] global port type: CTC_SCL_GPROT_TYPE_XXX */

    uint8               dir;                    /**< [GB.GG.DT2] refer to ctc_direction_t */
    uint16              svlan;                  /**< [GB.GG.DT2] svlan id */
    uint8               rsv0[2];                /**< [GB.GG.DT2] */
};
typedef struct ctc_scl_hash_port_svlan_key_s ctc_scl_hash_port_svlan_key_t;

struct ctc_scl_hash_port_2vlan_key_s
{
    uint32              gport;                  /**< [GB.GG.DT2] global port value */
    uint8               gport_type;             /**< [GB.GG.DT2] global port type: CTC_SCL_GPROT_TYPE_XXX */
    uint8               dir;                    /**< [GB.GG.DT2] refer to ctc_direction_t */

    uint16              svlan;                  /**< [GB.GG.DT2] svlan id */
    uint16              cvlan;                  /**< [GB.GG.DT2] cvlan id */
};
typedef struct ctc_scl_hash_port_2vlan_key_s ctc_scl_hash_port_2vlan_key_t;

struct ctc_scl_hash_port_cvlan_cos_key_s
{
    uint32              gport;                  /**< [GB.GG.DT2] global port value */
    uint8               gport_type;         /**< [GB.GG.DT2] global port type: CTC_SCL_GPROT_TYPE_XXX */
    uint8               dir;                    /**< [GB.GG.DT2] refer to ctc_direction_t */

    uint16              cvlan;                   /**< [GB.GG.DT2] cvlan id */
    uint8               ctag_cos;               /**< [GB.GG.DT2] C-tag CoS */
    uint8               rsv0;
};
typedef struct ctc_scl_hash_port_cvlan_cos_key_s ctc_scl_hash_port_cvlan_cos_key_t;

struct ctc_scl_hash_port_svlan_cos_key_s
{
    uint32              gport;                  /**< [GB.GG.DT2] global port value */
    uint8               gport_type;             /**< [GB.GG.DT2] global port type: CTC_SCL_GPROT_TYPE_XXX */
    uint8               dir;                    /**< [GB.GG.DT2] refer to ctc_direction_t */

    uint16              svlan;                  /**< [GB.GG.DT2] svlan id */
    uint8               stag_cos;               /**< [GB.GG.DT2] S-tag CoS */
    uint8               rsv0;
};
typedef struct ctc_scl_hash_port_svlan_cos_key_s ctc_scl_hash_port_svlan_cos_key_t;

struct ctc_scl_hash_mac_key_s
{
    mac_addr_t          mac;        /**< [GB.GG.DT2] macsa OR macda, based on mac_is_da */
    uint8               mac_is_da;      /**< [GB.GG.DT2] mac is macda OR macsa */
    uint8               rsv0;
};
typedef struct ctc_scl_hash_mac_key_s ctc_scl_hash_mac_key_t;

struct ctc_scl_hash_port_mac_key_s
{
    mac_addr_t          mac;                /**< [GB.GG.DT2] macsa OR macda, based on mac_is_da */
    uint8               mac_is_da;          /**< [GB.GG.DT2] mac is macda OR macsa */
    uint8               rsv0;               /**< [GB.GG.DT2] */

    uint32              gport;              /**< [GB.GG.DT2] global port value */
    uint8               gport_type;         /**< [GB.GG.DT2] global port type: CTC_SCL_GPROT_TYPE_XXX */
    uint8               rsv1;

};
typedef struct ctc_scl_hash_port_mac_key_s ctc_scl_hash_port_mac_key_t;

struct ctc_scl_hash_ipv4_key_s
{
    uint32              ip_sa;                  /**< [GB.GG.DT2] IP-SA */
};
typedef struct ctc_scl_hash_ipv4_key_s ctc_scl_hash_ipv4_key_t;

struct ctc_scl_hash_port_ipv4_key_s
{
    uint32              ip_sa;                  /**< [GB.GG.DT2] IP-SA */

    uint32              gport;                  /**< [GB.GG.DT2] global port value */
    uint8               gport_type;             /**< [GB.GG.DT2] global port type: CTC_SCL_GPROT_TYPE_XXX */
    uint8               rsv0;
};
typedef struct ctc_scl_hash_port_ipv4_key_s ctc_scl_hash_port_ipv4_key_t;

struct ctc_scl_hash_ipv6_key_s
{
    ipv6_addr_t         ip_sa;                  /**< [GB.GG.DT2] IP-SA */
};
typedef struct ctc_scl_hash_ipv6_key_s ctc_scl_hash_ipv6_key_t;

struct ctc_scl_hash_port_ipv6_key_s
{
    ipv6_addr_t         ip_sa;                  /**< [GB.GG.DT2] IP-SA */

    uint32              gport;                  /**< [GG.DT2] global port value */
    uint8               gport_type;             /**< [GB.GG.DT2] global port type: CTC_SCL_GPROT_TYPE_XXX */
    uint8               rsv0;
};
typedef struct ctc_scl_hash_port_ipv6_key_s ctc_scl_hash_port_ipv6_key_t;

struct ctc_scl_hash_l2_key_s
{
    uint32               field_sel_id;                  /**< [GG.DT2] Field Select Id */
    mac_addr_t          mac_da;                  /**< [GB.GG.DT2] MAC-DA */
    mac_addr_t          mac_sa;                  /**< [GB.GG.DT2] MAC-SA */

    uint16              vlan_id;                 /**< [GB.GG.DT2] S-VLAN */
    uint32              gport;                   /**< [GB.GG.DT2] GG can only used as class id 1-0xFF*/
    uint16              eth_type;            /**< [GG.DT2] Ethernet type */
    uint8                cos;                     /**< [GB.GG.DT2] S-tag CoS */
    uint8                tag_valid;           /**< [GG.DT2] S-tag exist */
    uint8                cfi;                      /**< [GG.DT2] S-tag CFI */
    uint8                rsv[3];

};
typedef struct ctc_scl_hash_l2_key_s ctc_scl_hash_l2_key_t;

struct ctc_scl_hash_l2_field_sel_s
{
    uint8 mac_da     ;      /**< [GG.DT2] L2 key field Select MAC-DA */
    uint8 mac_sa     ;      /**< [GG.DT2] L2 key field Select MAC-SA */
    uint8 eth_type   ;      /**< [GG.DT2] L2 key field Select Ethernet type */
    uint8 class_id   ;      /**< [GG.DT2] L2 key field Select class id */
    uint8 cos        ;      /**< [GG.DT2] L2 key field Select S-tag CoS */
    uint8 cfi        ;      /**< [GG.DT2] L2 key field Select S-tag CFI */
    uint8 vlan_id    ;      /**< [GG.DT2] L2 key field Select S-VLAN */
    uint8 tag_valid  ;      /**< [GG.DT2] L2 key field Select S-tag exist */
};
typedef struct ctc_scl_hash_l2_field_sel_s ctc_scl_hash_l2_field_sel_t;

struct ctc_scl_hash_field_sel_s
{
    uint8  key_type;            /**< [GG.DT2] Refer ctc_scl_key_type_t */
    uint32 field_sel_id;        /**< [GG.DT2] Field Select Id */

    union
    {
        ctc_scl_hash_l2_field_sel_t   l2;      /**< [GG.DT2] L2 key field select */
    }u;

};
typedef struct ctc_scl_hash_field_sel_s ctc_scl_hash_field_sel_t;


#define  TCAM_KEY




/** @brief  Vlan key field flag*/
enum ctc_scl_tcam_vlan_key_flag_e
{
    CTC_SCL_TCAM_VLAN_KEY_FLAG_CVLAN       = 1U << 0,      /**< [GB.GG] Valid C-VLAN in vlan key */
    CTC_SCL_TCAM_VLAN_KEY_FLAG_CTAG_COS    = 1U << 1,      /**< [GB.GG] Valid C-tag CoS in vlan key */
    CTC_SCL_TCAM_VLAN_KEY_FLAG_CTAG_CFI    = 1U << 2,      /**< [GB.GG] Valid C-tag CFI in vlan key */
    CTC_SCL_TCAM_VLAN_KEY_FLAG_SVLAN       = 1U << 3,      /**< [GB.GG] Valid S-VLAN in vlan key */
    CTC_SCL_TCAM_VLAN_KEY_FLAG_STAG_COS    = 1U << 4,      /**< [GB.GG] Valid S-tag CoS in vlan key */
    CTC_SCL_TCAM_VLAN_KEY_FLAG_STAG_CFI    = 1U << 5,      /**< [GB.GG] Valid S-tag CFI in vlan key */
    CTC_SCL_TCAM_VLAN_KEY_FLAG_CTAG_VALID  = 1U << 6,      /**< [GB.GG] Valid C-tag exist in vlan key */
    CTC_SCL_TCAM_VLAN_KEY_FLAG_STAG_VALID  = 1U << 7,      /**< [GB.GG] Valid S-tag exist in vlan key */
    CTC_SCL_TCAM_VLAN_KEY_FLAG_CUSTOMER_ID = 1U << 8       /**< [GB.GG] Valid customer id in vlan key */
};
typedef enum ctc_scl_tcam_vlan_key_flag_e ctc_scl_tcam_vlan_key_flag_t;

/** @brief  Vlan key field */
struct ctc_scl_tcam_vlan_key_s
{
    uint32 flag;                /**< [GB.GG] Bitmap of CTC_SCL_TCAM_MAC_KEY_FLAG_XXX */

    uint16 cvlan;               /**< [GB.GG] C-VLAN */
    uint16 cvlan_mask;          /**< [GB.GG] C-VLAN mask*/
    uint16 svlan;               /**< [GB.GG] S-VLAN */
    uint16 svlan_mask;          /**< [GB.GG] S-VLAN mask*/

    uint8  ctag_cos;            /**< [GB.GG] C-tag CoS */
    uint8  ctag_cos_mask;       /**< [GB.GG] C-tag CoS mask*/
    uint8  ctag_cfi;            /**< [GB.GG] C-tag CFI */
    uint8  ctag_valid;          /**< [GB.GG] Ctag valid*/

    uint8  stag_cos;            /**< [GB.GG] S-tag CoS */
    uint8  stag_cos_mask;       /**< [GB.GG] S-tag CoS mask*/
    uint8  stag_cfi;            /**< [GB.GG] S-tag CFI */
    uint8  stag_valid;          /**< [GB.GG] Stag valid*/
    uint32 customer_id;         /**< [GB.GG] Customer id, used for decap vpn label with iloop */
    uint32 customer_id_mask;    /**< [GB.GG] Customer id mask */
};
typedef struct ctc_scl_tcam_vlan_key_s ctc_scl_tcam_vlan_key_t;

/** @brief  Mac key field flag*/
enum ctc_scl_tcam_mac_key_flag_e
{
    CTC_SCL_TCAM_MAC_KEY_FLAG_MAC_DA      = 1U << 0,         /**< [GB.GG.DT2] Valid MAC-DA in mac key */
    CTC_SCL_TCAM_MAC_KEY_FLAG_MAC_SA      = 1U << 1,         /**< [GB.GG.DT2] Valid MAC-SA in mac key */
    CTC_SCL_TCAM_MAC_KEY_FLAG_CVLAN       = 1U << 2,         /**< [GB.GG.DT2] Valid C-VLAN in mac key */
    CTC_SCL_TCAM_MAC_KEY_FLAG_CTAG_COS    = 1U << 3,         /**< [GB.GG.DT2] Valid C-tag CoS in mac key */
    CTC_SCL_TCAM_MAC_KEY_FLAG_CTAG_CFI    = 1U << 4,         /**< [GB.GG.DT2] Valid C-tag CFI in mac key */
    CTC_SCL_TCAM_MAC_KEY_FLAG_SVLAN       = 1U << 5,         /**< [GB.GG.DT2] Valid S-VLAN in mac key */
    CTC_SCL_TCAM_MAC_KEY_FLAG_STAG_COS    = 1U << 6,         /**< [GB.GG.DT2] Valid S-tag CoS in mac key */
    CTC_SCL_TCAM_MAC_KEY_FLAG_STAG_CFI    = 1U << 7,         /**< [GB.GG.DT2] Valid S-tag CFI in mac key */
    CTC_SCL_TCAM_MAC_KEY_FLAG_L2_TYPE     = 1U << 8,         /**< [GB.GG.DT2] Valid l2-type in mac key */
    CTC_SCL_TCAM_MAC_KEY_FLAG_L3_TYPE     = 1U << 9,         /**< [GB] Valid l3-type in mac key */
    CTC_SCL_TCAM_MAC_KEY_FLAG_CTAG_VALID  = 1U <<10,         /**< [GG.DT2] Valid C-tag exist in mac key */
    CTC_SCL_TCAM_MAC_KEY_FLAG_STAG_VALID  = 1U <<11,         /**< [GG.DT2] Valid S-tag exist in mac key */
    CTC_SCL_TCAM_MAC_KEY_FLAG_ETH_TYPE    = 1U <<12         /**< [GG.DT2] Valid Ethernet type in mac key */
};
typedef enum ctc_scl_tcam_mac_key_flag_e ctc_scl_tcam_mac_key_flag_t;

/** @brief  Mac key field */
struct ctc_scl_tcam_mac_key_s
{
    uint32 flag;                /**< [GB.GG.DT2] Bitmap of CTC_SCL_TCAM_MAC_KEY_FLAG_XXX */

    mac_addr_t mac_da;          /**< [GB.GG.DT2] MAC-DA */
    mac_addr_t mac_da_mask;     /**< [GB.GG.DT2] MAC-DA mask */
    mac_addr_t mac_sa;          /**< [GB.GG.DT2] MAC-SA */
    mac_addr_t mac_sa_mask;     /**< [GB.GG.DT2] MAC-SA mask */

    uint16 cvlan;               /**< [GB.GG.DT2] C-VLAN */
    uint16 cvlan_mask;          /**< [GB.GG.DT2] C-VLAN mask*/
    uint16 svlan;               /**< [GB.GG.DT2] S-VLAN */
    uint16 svlan_mask;          /**< [GB.GG.DT2] S-VLAN mask*/

    uint8  ctag_cos;            /**< [GB.GG.DT2] C-tag CoS */
    uint8  ctag_cos_mask;       /**< [GB.GG.DT2] C-tag CoS mask*/
    uint8  ctag_cfi;            /**< [GB.GG.DT2] C-tag CFI */
    uint8  ctag_valid;          /**< [GG.DT2] C-tag exist */

    uint8  stag_cos;            /**< [GB.GG.DT2] S-tag CoS */
    uint8  stag_cos_mask;       /**< [GB.GG.DT2] S-tag CoS mask*/
    uint8  stag_cfi;            /**< [GB.GG.DT2] S-tag CFI */
    uint8  stag_valid;          /**< [GG.DT2] S-tag exist */

    uint8  l2_type;             /**< [GB.GG.DT2] Layer 2 type. Refer to ctc_parser_l2_type_t */
    uint8  l2_type_mask;        /**< [GB.GG.DT2] Layer 2 type mask*/
    uint8  l3_type;             /**< [GB] Layer 3 type. Refer to ctc_parser_l3_type_t */
    uint8  l3_type_mask;        /**< [GB] Layer 3 type mask*/

    uint16 eth_type;            /**< [GG.DT2] Ethernet type */
    uint16 eth_type_mask;       /**< [GG.DT2] Ethernet type mask*/
} ;
typedef struct ctc_scl_tcam_mac_key_s ctc_scl_tcam_mac_key_t;

enum ctc_scl_tcam_ipv4_key_flag_e
{

    CTC_SCL_TCAM_IPV4_KEY_FLAG_MAC_DA        = 1U << 0,  /**< [GB.GG.DT2-D] Valid MAC-DA in IPv4 key */
    CTC_SCL_TCAM_IPV4_KEY_FLAG_MAC_SA        = 1U << 1,  /**< [GB.GG.DT2-D] Valid MAC-SA in IPv4 key */
    CTC_SCL_TCAM_IPV4_KEY_FLAG_CVLAN         = 1U << 2,  /**< [GB.GG.DT2-D] Valid C-VLAN in IPv4 key */
    CTC_SCL_TCAM_IPV4_KEY_FLAG_CTAG_COS      = 1U << 3,  /**< [GB.GG.DT2-D] Valid C-tag CoS in IPv4 key */
    CTC_SCL_TCAM_IPV4_KEY_FLAG_CTAG_CFI      = 1U << 4,  /**< [GB.GG.DT2-D] Valid C-tag CFI in IPv4 key */
    CTC_SCL_TCAM_IPV4_KEY_FLAG_SVLAN         = 1U << 5,  /**< [GB.GG.DT2-D] Valid S-VLAN in IPv4 key */
    CTC_SCL_TCAM_IPV4_KEY_FLAG_STAG_COS      = 1U << 6,  /**< [GB.GG.DT2-D] Valid S-tag CoS in IPv4 key */
    CTC_SCL_TCAM_IPV4_KEY_FLAG_STAG_CFI      = 1U << 7,  /**< [GB.GG.DT2-D] Valid S-tag CFI in IPv4 key */
    CTC_SCL_TCAM_IPV4_KEY_FLAG_L2_TYPE       = 1U << 8,  /**< [GB.GG.DT2] Valid l2-type in IPv4 key.*/
    CTC_SCL_TCAM_IPV4_KEY_FLAG_L3_TYPE       = 1U << 9,  /**< [GB.GG.DT2] Valid l3-type in IPv4 key */
    CTC_SCL_TCAM_IPV4_KEY_FLAG_IP_SA         = 1U << 10, /**< [GB.GG.DT2] Valid IP-SA in IPv4 key */
    CTC_SCL_TCAM_IPV4_KEY_FLAG_IP_DA         = 1U << 11, /**< [GB.GG.DT2] Valid IP-DA in IPv4 key */
    CTC_SCL_TCAM_IPV4_KEY_FLAG_L4_PROTOCOL   = 1U << 12, /**< [GB.GG.DT2] Valid L4-Proto in IPv4 key */
    CTC_SCL_TCAM_IPV4_KEY_FLAG_DSCP          = 1U << 13, /**< [GB.GG.DT2] Valid DSCP in IPv4 key */
    CTC_SCL_TCAM_IPV4_KEY_FLAG_PRECEDENCE    = 1U << 14, /**< [GB.GG.DT2] Valid IP Precedence in IPv4 key */
    CTC_SCL_TCAM_IPV4_KEY_FLAG_IP_FRAG       = 1U << 15, /**< [GB.GG.DT2] Valid fragment in IPv4 key */
    CTC_SCL_TCAM_IPV4_KEY_FLAG_IP_OPTION     = 1U << 16, /**< [GB.GG.DT2] Valid IP option in IPv4 key */
    CTC_SCL_TCAM_IPV4_KEY_FLAG_L4_TYPE       = 1U << 17, /**< [GB] Valid l4-type in IPv4 key */
    CTC_SCL_TCAM_IPV4_KEY_FLAG_ETH_TYPE      = 1U << 18, /**< [GB.GG.DT2] Valid Ether type in IPv4 Key */
    CTC_SCL_TCAM_IPV4_KEY_FLAG_STAG_VALID    = 1U << 19, /**< [GG.DT2-D] Valid Stag-valid in IPv4 key */
    CTC_SCL_TCAM_IPV4_KEY_FLAG_CTAG_VALID    = 1U << 20, /**< [GG.DT2-D] Valid Ctag-valid in IPv4 key */
    CTC_SCL_TCAM_IPV4_KEY_FLAG_ECN           = 1U << 21  /**< [GG.DT2] Valid ECN in IPv4 key */

};
typedef enum ctc_scl_tcam_ipv4_key_flag_e ctc_scl_tcam_ipv4_key_flag_t;

enum ctc_scl_tcam_ipv4_key_sub_flag_e
{
    CTC_SCL_TCAM_IPV4_KEY_SUB_FLAG_L4_SRC_PORT       = 1U << 0, /**< [GB.GG.DT2] Depend on L4_PROTOCOL = TCP|UDP. Valid L4 source port in IPv4 key */
    CTC_SCL_TCAM_IPV4_KEY_SUB_FLAG_L4_DST_PORT       = 1U << 1, /**< [GB.GG.DT2] Depend on L4_PROTOCOL = TCP|UDP. Valid L4 destination port in IPv4 key */
    CTC_SCL_TCAM_IPV4_KEY_SUB_FLAG_ICMP_TYPE         = 1U << 2, /**< [GB.GG.DT2] Depend on L4_PROTOCOL = ICMP. Valid ICMP type in IPv4 key */
    CTC_SCL_TCAM_IPV4_KEY_SUB_FLAG_ICMP_CODE         = 1U << 3, /**< [GB.GG.DT2] Depend on L4_PROTOCOL = ICMP. Valid ICMP code in IPv4 key */
    CTC_SCL_TCAM_IPV4_KEY_SUB_FLAG_IGMP_TYPE         = 1U << 4, /**< [GB.GG.DT2] Depend on L4_PROTOCOL = IGMP. Valid IGMP type in IPv4 key */
    CTC_SCL_TCAM_IPV4_KEY_SUB_FLAG_ARP_OP_CODE       = 1U << 5, /**< [GB.GG.DT2] (GB)Depend on ARP_PACKET. (GG)Depend on L3_TYPE. Valid Arp op code in Arp Key. */
    CTC_SCL_TCAM_IPV4_KEY_SUB_FLAG_ARP_SENDER_IP     = 1U << 6, /**< [GB.GG.DT2] (GB)Depend on ARP_PACKET. (GG)Depend on L3_TYPE. Valid Arp sender Ip in Arp Key. */
    CTC_SCL_TCAM_IPV4_KEY_SUB_FLAG_ARP_TARGET_IP     = 1U << 7, /**< [GB.GG.DT2] (GB)Depend on ARP_PACKET. (GG)Depend on L3_TYPE. Valid Arp target Ip in Arp Key. */
    CTC_SCL_TCAM_IPV4_KEY_SUB_FLAG_ARP_PROTOCOL_TYPE = 1U << 8, /**< [GG.DT2] (GB)Depend on ARP_PACKET. (GG)Depend on L3_TYPE. Valid Arp target Ip in Arp Key. */
    CTC_SCL_TCAM_IPV4_KEY_SUB_FLAG_GRE_KEY           = 1U << 9,  /**< [GG.DT2] Depend on L4_PROTOCOL = GRE. Valid GRE key in IPv4 key */
    CTC_SCL_TCAM_IPV4_KEY_SUB_FLAG_NVGRE_KEY           = 1U << 10,  /**< [GG.DT2] Depend on L4_PROTOCOL = GRE. Valid NVGRE key in IPv4 key */
    CTC_SCL_TCAM_IPV4_KEY_SUB_FLAG_VNI           = 1U << 11  /**< [GG.DT2] Valid vni in IPv4 key for vxlan */
};
typedef enum ctc_scl_tcam_ipv4_key_sub_flag_e ctc_scl_tcam_ipv4_key_sub_flag_t;

struct ctc_scl_tcam_ipv4_key_s
{
    uint32 flag;                        /**< [GB.GG.DT2] Bitmap of CTC_SCL_TCAM_IPV4_KEY_FLAG_XXX */
    uint32 sub_flag;                    /**< [GB.GG.DT2] Bitmap of CTC_SCL_TCAM_IPV4_KEY_SUB_FLAG_XXX */
    uint32 sub1_flag;                   /**< [GG.DT2] */
    uint32 sub2_flag;                   /**< [GG.DT2] */
    uint8  key_size;                    /**< [GG.DT2] CTC_SCL_KEY_SIZE_SINGLE or CTC_SCL_KEY_SIZE_DOUBLE */

    uint32 ip_sa;                       /**< [GB.GG.DT2] IP-SA */
    uint32 ip_sa_mask;                  /**< [GB.GG.DT2] IP-SA mask */
    uint32 ip_da;                       /**< [GB.GG.DT2] IP-DA */
    uint32 ip_da_mask;                  /**< [GB.GG.DT2] IP-DA mask */

    mac_addr_t mac_sa;                  /**< [GB.GG.DT2] MAC-SA */
    mac_addr_t mac_sa_mask;             /**< [GB.GG.DT2] MAC-SA mask */
    mac_addr_t mac_da;                  /**< [GB.GG.DT2] MAC-DA */
    mac_addr_t mac_da_mask;             /**< [GB.GG.DT2] MAC-DA mask */


    uint16 cvlan;                       /**< [GB.GG.DT2] C-VLAN */
    uint16 cvlan_mask;                  /**< [GB.GG.DT2] C-VLAN mask*/
    uint16 svlan;                       /**< [GB.GG.DT2] S-VLAN */
    uint16 svlan_mask;                  /**< [GB.GG.DT2] S-VLAN mask*/

    uint8  ctag_cos;                    /**< [GB.GG.DT2] C-tag CoS */
    uint8  ctag_cos_mask;               /**< [GB.GG.DT2] C-tag CoS mask*/
    uint8  stag_cos;                    /**< [GB.GG.DT2] S-tag CoS */
    uint8  stag_cos_mask;               /**< [GB.GG.DT2] S-tag CoS mask*/

    uint8  ctag_cfi;                    /**< [GB.GG.DT2] C-tag CFI */
    uint8  stag_cfi;                    /**< [GB.GG.DT2] S-tag CFI */
    uint8  rsv0[2];

    uint16 eth_type;                    /**< [GB] Ethernet type */
    uint16 eth_type_mask;               /**< [GB] Ethernet type mask*/

    uint16 l4_src_port;                 /**< [GB.GG.DT2] Layer 4 source port.Min/Data */
    uint16 l4_src_port_mask;            /**< [GB.GG.DT2] Layer 4 source port.Max/Mask */
    uint16 l4_dst_port;                 /**< [GB.GG.DT2] Layer 4 dest port */
    uint16 l4_dst_port_mask;            /**< [GB.GG.DT2] Layer 4 dest port */

    uint8  l2_type;                     /**< [GB.GG.DT2] Layer 2 type. Refer to ctc_parser_l2_type_t */
    uint8  l2_type_mask;                /**< [GB.GG.DT2] Layer 2 type */
    uint8  l3_type;                     /**< [GB.GG.DT2] Layer 3 type. Refer to ctc_parser_l3_type_t */
    uint8  l3_type_mask;                /**< [GB.GG.DT2] Layer 3 type */

    uint8  l4_type;                     /**< [GB] Layer 4 type. Refer to ctc_parser_l4_type_t */
    uint8  l4_type_mask;                /**< [GB] Layer 4 type */
    uint8  dscp;                        /**< [GB.GG.DT2] DSCP or Ip precedence */
    uint8  dscp_mask;                   /**< [GB.GG.DT2] DSCP or Ip precedence mask */

    uint8  ip_frag;                     /**< [GB.GG.DT2] Ip fragment, CTC_IP_FRAG_XXX */
    uint8  ip_option;                   /**< [GB.GG.DT2] Ip option */
    uint8  routed_packet;               /**< [GB.GG.DT2] Routed packet */
    uint8  rsv1;


    uint8  l4_protocol;                 /**< [GB.GG.DT2] Layer 4 protocol */
    uint8  l4_protocol_mask;            /**< [GB.GG.DT2] Layer 4 protocol protocol*/
    uint8  igmp_type;                   /**< [GB.GG.DT2] IGMP type */
    uint8  igmp_type_mask;              /**< [GB.GG.DT2] IGMP type mask*/

    uint8  icmp_type;                   /**< [GB.GG.DT2] ICMP type */
    uint8  icmp_type_mask;              /**< [GB.GG.DT2] ICMP type mask*/
    uint8  icmp_code;                   /**< [GB.GG.DT2] ICMP code */
    uint8  icmp_code_mask;              /**< [GB.GG.DT2] ICMP code mask*/

    uint32 sender_ip;                   /**< [GB.GG.DT2] Sender ip */
    uint32 sender_ip_mask;              /**< [GB.GG.DT2] Sender ip mask */
    uint32 target_ip;                   /**< [GB.GG.DT2] Target ip */
    uint32 target_ip_mask;              /**< [GB.GG.DT2] Target ip mask */

    uint16 arp_op_code;                 /**< [GB.GG.DT2] Arp op code*/
    uint16 arp_op_code_mask;            /**< [GB.GG.DT2] Arp op code mask*/

    uint8  ecn;                         /**< [GG.DT2] ECN */
    uint8  ecn_mask;                    /**< [GG.DT2] ECN mask */

    uint8  stag_valid;                  /**< [GG.DT2] S-tag exist */
    uint8  ctag_valid;                  /**< [GG.DT2] C-tag exist */

    uint16 arp_protocol_type;           /**< [GG.DT2] Arp protocol type */
    uint16 arp_protocol_type_mask;      /**< [GG.DT2] Arp protocol type mask */

    uint32 mpls_label0;                 /**< [GG.DT2] MPLS label 0, include: Label + Exp + S + TTL */
    uint32 mpls_label0_mask;            /**< [GG.DT2] MPLS label 0 mask*/
    uint32 mpls_label1;                 /**< [GG.DT2] MPLS label 1, include: Label + Exp + S + TTL */
    uint32 mpls_label1_mask;            /**< [GG.DT2] MPLS label 1 mask*/
    uint32 mpls_label2;                 /**< [GG.DT2] MPLS label 2, include: Label + Exp + S + TTL */
    uint32 mpls_label2_mask;            /**< [GG.DT2] MPLS label 2 mask*/

    uint8  mpls_label_num;              /**< [GG.DT2] */
    uint8  mpls_label_num_mask;         /**< [GG.DT2] */

    uint8 ethoam_level;                 /**< [GG.DT2]*/
    uint8 ethoam_level_mask;            /**< [GG.DT2]*/

    uint8 ethoam_version;               /**< [GG.DT2]*/
    uint8 ethoam_version_mask;          /**< [GG.DT2]*/

    uint8 ethoam_op_code;               /**< [GG.DT2]*/
    uint8 ethoam_op_code_mask;          /**< [GG.DT2]*/

    uint8 ethoam_is_y1732;              /**< [GG.DT2]*/

    uint8 slowproto_sub_type;       /**< [GG.DT2]*/
    uint8 slowproto_sub_type_mask;  /**< [GG.DT2]*/

    uint16 slowproto_flags;         /**< [GG.DT2]*/
    uint16 slowproto_flags_mask;    /**< [GG.DT2]*/

    uint8 slowproto_code;           /**< [GG.DT2]*/
    uint8 slowproto_code_mask;      /**< [GG.DT2]*/

    uint8 ptp_version;                  /**< [GG.DT2]*/
    uint8 ptp_version_mask;             /**< [GG.DT2]*/

    uint8 ptp_msg_type;                 /**< [GG.DT2]*/
    uint8 ptp_msg_type_mask;            /**< [GG.DT2]*/

    uint32 fcoe_did;                    /**< [GG.DT2]*/
    uint32 fcoe_did_mask;               /**< [GG.DT2]*/

    uint32 fcoe_sid;                    /**< [GG.DT2]*/
    uint32 fcoe_sid_mask;               /**< [GG.DT2]*/

    uint32 gre_key;                     /**< [GG.DT2]*/
    uint32 gre_key_mask;                /**< [GG.DT2]*/

    uint32 vni;                     /**< [GG.DT2]*/
    uint32 vni_mask;                /**< [GG.DT2]*/
} ;
typedef struct ctc_scl_tcam_ipv4_key_s ctc_scl_tcam_ipv4_key_t;


enum ctc_scl_tcam_ipv6_key_flag_e
{
    CTC_SCL_TCAM_IPV6_KEY_FLAG_MAC_DA        = 1U << 0,  /**< [GB.GG.DT2] Valid MAC-DA in IPv6 key */
    CTC_SCL_TCAM_IPV6_KEY_FLAG_MAC_SA        = 1U << 1,  /**< [GB.GG.DT2] Valid MAC-SA in IPv6 key */
    CTC_SCL_TCAM_IPV6_KEY_FLAG_CVLAN         = 1U << 2,  /**< [GB.GG.DT2] Valid CVLAN in IPv6 key */
    CTC_SCL_TCAM_IPV6_KEY_FLAG_CTAG_COS      = 1U << 3,  /**< [GB.GG.DT2] Valid Ctag CoS in IPv6 key */
    CTC_SCL_TCAM_IPV6_KEY_FLAG_CTAG_CFI      = 1U << 4,  /**< [GB.GG.DT2] Valid C-tag Cfi in IPv6 key */
    CTC_SCL_TCAM_IPV6_KEY_FLAG_SVLAN         = 1U << 5,  /**< [GB.GG.DT2] Valid SVLAN in IPv6 key */
    CTC_SCL_TCAM_IPV6_KEY_FLAG_STAG_COS      = 1U << 6,  /**< [GB.GG.DT2] Valid Stag CoS in IPv6 key */
    CTC_SCL_TCAM_IPV6_KEY_FLAG_STAG_CFI      = 1U << 7,  /**< [GB.GG.DT2] Valid S-tag Cfi in IPv6 key */
    CTC_SCL_TCAM_IPV6_KEY_FLAG_ETH_TYPE      = 1U << 8,  /**< [GB] Valid Ether-type in IPv6 key */
    CTC_SCL_TCAM_IPV6_KEY_FLAG_L2_TYPE       = 1U << 9,  /**< [GB.GG.DT2] Valid L2-type CoS in IPv6 key */
    CTC_SCL_TCAM_IPV6_KEY_FLAG_L3_TYPE       = 1U << 10, /**< [GB] Valid L3-type in IPv6 key */
    CTC_SCL_TCAM_IPV6_KEY_FLAG_L4_TYPE       = 1U << 11, /**< [GB.GG.DT2] Valid L4-type in IPv6 key*/
    CTC_SCL_TCAM_IPV6_KEY_FLAG_IP_SA         = 1U << 12, /**< [GB.GG.DT2] Valid IPv6-SA in IPv6 key */
    CTC_SCL_TCAM_IPV6_KEY_FLAG_IP_DA         = 1U << 13, /**< [GB.GG.DT2] Valid IPv6-DA in IPv6 key */
    CTC_SCL_TCAM_IPV6_KEY_FLAG_L4_PROTOCOL   = 1U << 14, /**< [GB.GG.DT2] Valid L4-Protocol in IPv6 key */
    CTC_SCL_TCAM_IPV6_KEY_FLAG_DSCP          = 1U << 15, /**< [GB.GG.DT2] Valid DSCP in IPv6 key */
    CTC_SCL_TCAM_IPV6_KEY_FLAG_PRECEDENCE    = 1U << 16, /**< [GB.GG.DT2] Valid IP Precedence in IPv6 key */
    CTC_SCL_TCAM_IPV6_KEY_FLAG_IP_FRAG       = 1U << 17, /**< [GB.GG.DT2] Valid fragment in IPv6 key */
    CTC_SCL_TCAM_IPV6_KEY_FLAG_IP_OPTION     = 1U << 18, /**< [GB.GG.DT2] Valid IP option in IPv6 key */
    CTC_SCL_TCAM_IPV6_KEY_FLAG_FLOW_LABEL    = 1U << 19, /**< [GB.GG.DT2] Valid IPv6 flow label in IPv6 key */
    CTC_SCL_TCAM_IPV6_KEY_FLAG_STAG_VALID    = 1U << 20, /**< [GG.DT2] Valid Stag-valid in IPv6 key */
    CTC_SCL_TCAM_IPV6_KEY_FLAG_CTAG_VALID    = 1U << 21, /**< [GG.DT2] Valid Ctag-valid in IPv6 key */
    CTC_SCL_TCAM_IPV6_KEY_FLAG_ECN           = 1U << 22  /**< [GG.DT2] */
};
typedef enum ctc_scl_tcam_ipv6_key_flag_e ctc_scl_tcam_ipv6_key_flag_t;

enum ctc_scl_tcam_ipv6_key_sub_flag_e
{
    CTC_SCL_TCAM_IPV6_KEY_SUB_FLAG_L4_SRC_PORT   = 1U << 0, /**< [GB.GG.DT2] Depend on L4_PROTOCOL = TCP|UDP Valid L4 source port in IPv6 key */
    CTC_SCL_TCAM_IPV6_KEY_SUB_FLAG_L4_DST_PORT   = 1U << 1, /**< [GB.GG.DT2] Depend on L4_PROTOCOL = TCP|UDP Valid L4 destination port in IPv6 key */
    CTC_SCL_TCAM_IPV6_KEY_SUB_FLAG_ICMP_TYPE     = 1U << 2, /**< [GB.GG.DT2] Depend on L4_PROTOCOL = ICMP.   Valid ICMP type in IPv6 key */
    CTC_SCL_TCAM_IPV6_KEY_SUB_FLAG_ICMP_CODE     = 1U << 3, /**< [GB.GG.DT2] Depend on L4_PROTOCOL = ICMP.   Valid ICMP code in IPv6 key */
    CTC_SCL_TCAM_IPV6_KEY_SUB_FLAG_GRE_KEY       = 1U << 4,  /**< [GG.DT2] Depend on L4_PROTOCOL = GRE.  Valid GRE key in IPv6 key*/
    CTC_SCL_TCAM_IPV6_KEY_SUB_FLAG_NVGRE_KEY           = 1U << 5,  /**< [GG.DT2] Depend on L4_PROTOCOL = GRE. Valid NVGRE key in IPv6 key */
    CTC_SCL_TCAM_IPV6_KEY_SUB_FLAG_VNI           = 1U << 6  /**< [GG.DT2] Valid vni key in IPv6 key for vxlan */
};
typedef enum ctc_scl_tcam_ipv6_key_sub_flag_e ctc_scl_tcam_ipv6_key_sub_flag_t;

struct ctc_scl_tcam_ipv6_key_s
{
    uint32 flag;                        /**< [GB.GG.DT2] Bitmap of CTC_SCL_TCAM_IPV6_KEY_FLAG_XXX */
    uint32 sub_flag;                    /**< [GB.GG.DT2] Bitmap of CTC_SCL_TCAM_IPV6_KEY_SUB_FLAG_XXX */

    ipv6_addr_t ip_sa;                  /**< [GB.GG.DT2] IPv6-SA */
    ipv6_addr_t ip_sa_mask;             /**< [GB.GG.DT2] IPv6-SA mask */
    ipv6_addr_t ip_da;                  /**< [GB.GG.DT2] IPv6-DA */
    ipv6_addr_t ip_da_mask;             /**< [GB.GG.DT2] IPv6-DA mask */

    mac_addr_t mac_sa;                  /**< [GB.GG.DT2] MAC-SA */
    mac_addr_t mac_sa_mask;             /**< [GB.GG.DT2] MAC-SA mask */
    mac_addr_t mac_da;                  /**< [GB.GG.DT2] MAC-DA */
    mac_addr_t mac_da_mask;             /**< [GB.GG.DT2] MAC-DA mask */

    uint16 l4_src_port;                 /**< [GB.GG.DT2] Layer 4 source port.Min/Data */
    uint16 l4_src_port_mask;            /**< [GB.GG.DT2] Layer 4 source port.Max/Mask */
    uint16 l4_dst_port;                 /**< [GB.GG.DT2] Layer 4 dest port */
    uint16 l4_dst_port_mask;            /**< [GB.GG.DT2] Layer 4 dest port */

    uint16 cvlan;                       /**< [GB.GG.DT2] C-VLAN */
    uint16 cvlan_mask;                  /**< [GB.GG.DT2] C-VLAN mask*/
    uint16 svlan;                       /**< [GB.GG.DT2] S-VLAN */
    uint16 svlan_mask;                  /**< [GB.GG.DT2] S-VLAN mask*/

    uint8  ctag_cos;                    /**< [GB.GG.DT2] C-tag CoS */
    uint8  ctag_cos_mask;               /**< [GB.GG.DT2] C-tag CoS mask */
    uint8  stag_cos;                    /**< [GB.GG.DT2] S-tag CoS */
    uint8  stag_cos_mask;               /**< [GB.GG.DT2] S-tag Cos mask */

    uint8  ctag_cfi;                    /**< [GB.GG.DT2] C-tag CFI */
    uint8  stag_cfi;                    /**< [GB.GG.DT2] S-tag CFI */
    uint8  l2_type;                     /**< [GB.GG.DT2] Layer 2 type. Refer to ctc_parser_l2_type_t */
    uint8  l2_type_mask;                /**< [GB.GG.DT2] Layer 2 type mask*/

    uint8  l3_type;                     /**< [GB.GG.DT2] Layer 3 type. Refer to ctc_parser_l3_type_t */
    uint8  l3_type_mask;                /**< [GB.GG.DT2] Layer 3 type mask*/
    uint8  l4_type;                     /**< [GB.GG.DT2] Layer 4 type. Refer to ctc_parser_l4_type_t */
    uint8  l4_type_mask;                /**< [GB.GG.DT2] Layer 4 type mask*/

    uint8  ip_option;                   /**< [GB.GG.DT2] IP option */
    uint8  ip_frag;                     /**< [GB.GG.DT2] Ip fragment, CTC_IP_FRAG_XXX */
    uint8  rsv0[2];

    uint8  l4_protocol;                 /**< [GB.GG.DT2] Layer 4 protocol */
    uint8  l4_protocol_mask;            /**< [GB.GG.DT2] Layer 4 protocol mask*/
    uint8  dscp;                        /**< [GB.GG.DT2] DSCP */
    uint8  dscp_mask;                   /**< [GB.GG.DT2] DSCP mask */

    uint8  icmp_type;                   /**< [GB.GG.DT2] ICMP type */
    uint8  icmp_type_mask;              /**< [GB.GG.DT2] ICMP type mask*/

    uint8  icmp_code;                   /**< [GB.GG.DT2] ICMP code */
    uint8  icmp_code_mask;              /**< [GB.GG.DT2] ICMP code mask*/

    uint16 eth_type;                    /**< [GB.GG.DT2] Ethernet type */
    uint16 eth_type_mask;               /**< [GB.GG.DT2] Ethernet type mask */

    uint32 flow_label;                  /**< [GB.GG.DT2] Flow label */
    uint32 flow_label_mask;             /**< [GB.GG.DT2] Flow label */

    uint8  ecn;                         /**< [GG.DT2] ECN */
    uint8  ecn_mask;                    /**< [GG.DT2] ECN mask */

    uint8  stag_valid;                  /**< [GG.DT2] S-tag exist */
    uint8  ctag_valid;                  /**< [GG.DT2] C-tag exist */

    uint32 gre_key;                     /**< [GG.DT2] GRE key */
    uint32 gre_key_mask;                /**< [GG.DT2] GRE key mask */

    uint32 vni;                     /**< [GG.DT2] VNI id*/
    uint32 vni_mask;                /**< [GG.DT2] VNI id mask*/
} ;
typedef struct ctc_scl_tcam_ipv6_key_s ctc_scl_tcam_ipv6_key_t;


struct ctc_scl_key_s
{
    ctc_scl_key_type_t type;                 /**< [HB.GB.GG.DT2] CTC_SCL_KEY_XXX */
    uint8 resolve_conflict;                           /**< [DT2] resolve conflict, install to tcam*/
    uint8 rsv;

    union
    {
        ctc_scl_tcam_vlan_key_t             tcam_vlan_key;            /**<[GB.GG.DT2] SCL VLAN key content */
        ctc_scl_tcam_mac_key_t              tcam_mac_key;             /**<[GB.GG.DT2] SCL MAC  key content */
        ctc_scl_tcam_ipv4_key_t             tcam_ipv4_key;            /**<[GB.GG.DT2] SCL IPv4 key content */
        ctc_scl_tcam_ipv6_key_t             tcam_ipv6_key;            /**<[GB.GG.DT2] SCL IPv6 key content */

        ctc_scl_hash_port_key_t             hash_port_key;            /**<[GB.GG.DT2] SCL port hash key content */
        ctc_scl_hash_port_cvlan_key_t       hash_port_cvlan_key;      /**<[GB.GG.DT2] SCL port c-vlan hash key content */
        ctc_scl_hash_port_svlan_key_t       hash_port_svlan_key;      /**<[GB.GG.DT2] SCL port s-vlan hash key content */
        ctc_scl_hash_port_2vlan_key_t       hash_port_2vlan_key;      /**<[GB.GG.DT2] SCL port double vlan hash key content */
        ctc_scl_hash_port_cvlan_cos_key_t   hash_port_cvlan_cos_key;  /**<[GB.GG.DT2] SCL port c-vlan cos hash key content */
        ctc_scl_hash_port_svlan_cos_key_t   hash_port_svlan_cos_key;  /**<[GB.GG.DT2] SCL port s-vlan cos hash key content */
        ctc_scl_hash_port_mac_key_t         hash_port_mac_key;        /**<[GB.GG.DT2] SCL port mac hash key content */
        ctc_scl_hash_port_ipv4_key_t        hash_port_ipv4_key;       /**<[GB.GG.DT2] SCL port ipv4 hash key content */
        ctc_scl_hash_mac_key_t              hash_mac_key;             /**<[GB.GG.DT2] SCL mac hash key content */
        ctc_scl_hash_ipv4_key_t             hash_ipv4_key;            /**<[GB.GG.DT2] SCL ipv4 hash key content */
        ctc_scl_hash_ipv6_key_t             hash_ipv6_key;            /**<[GB.GG.DT2] SCL ipv6 hash key content */
        ctc_scl_hash_port_ipv6_key_t        hash_port_ipv6_key;       /**<[GG.DT2] SCL port ipv6 hash key content */
        ctc_scl_hash_l2_key_t               hash_l2_key;              /**<[GB.GG.DT2] SCL layer 2 hash key content */
    } u;
};
typedef struct ctc_scl_key_s ctc_scl_key_t;

enum ctc_scl_action_type_e
{
    CTC_SCL_ACTION_INGRESS,     /**<[GB.GG.DT2] Ingress SCL action */
    CTC_SCL_ACTION_EGRESS,      /**<[GB.GG.DT2] Engress SCL action */
    CTC_SCL_ACTION_FLOW,        /**<[GG.DT2] SCL flow action*/
    CTC_SCL_ACTION_NUM
};
typedef enum ctc_scl_action_type_e ctc_scl_action_type_t;


#define ACTION
enum ctc_scl_vlan_domain_e
{
    CTC_SCL_VLAN_DOMAIN_SVLAN,    /**< [GB.GG.DT2] svlan domain */
    CTC_SCL_VLAN_DOMAIN_CVLAN,    /**< [GB.GG.DT2] cvlan domain */
    CTC_SCL_VLAN_DOMAIN_UNCHANGE,  /**< [GB.GG.DT2] keep unchange */
    CTC_SCL_VLAN_DOMAIN_MAX
};
typedef enum ctc_scl_vlan_domain_e ctc_scl_vlan_domain_t;


/**
 @brief [GB.GG] define acl vlan edit operation
*/
struct ctc_scl_vlan_edit_s
{
    uint8  stag_op;         /**< [GB.GG.DT2] operation type of stag, see CTC_VLAN_TAG_OP_XXX  */
    uint8  svid_sl;         /**< [GB.GG.DT2] select type of svid, see CTC_VLAN_TAG_SL_XXX  */
    uint8  scos_sl;         /**< [GB.GG.DT2] select type of scos, see CTC_VLAN_TAG_SL_XXX  */
    uint8  scfi_sl;         /**< [GB.GG.DT2] select type of scfi, see CTC_VLAN_TAG_SL_XXX  */
    uint16 svid_new;        /**< [GB.GG.DT2] new svid, valid only if svid_sl is CTC_VLAN_TAG_OP_REP|CTC_VLAN_TAG_OP_REP_OR_ADD|CTC_VLAN_TAG_OP_ADD*/
    uint8  scos_new;        /**< [GB.GG.DT2] new scos, valid only if scos_sl is CTC_VLAN_TAG_OP_REP|CTC_VLAN_TAG_OP_REP_OR_ADD|CTC_VLAN_TAG_OP_ADD*/
    uint8  scfi_new;        /**< [GB.GG.DT2] new scfi, valid only if scfi_sl is CTC_VLAN_TAG_OP_REP|CTC_VLAN_TAG_OP_REP_OR_ADD|CTC_VLAN_TAG_OP_ADD*/

    uint8  ctag_op;         /**< [GB.GG.DT2] operation type of ctag, see CTC_VLAN_TAG_OP_XXX */
    uint8  cvid_sl;         /**< [GB.GG.DT2] select type of cvid, see CTC_VLAN_TAG_SL_XXX */
    uint8  ccos_sl;         /**< [GB.GG.DT2] select type of ccos, see CTC_VLAN_TAG_SL_XXX */
    uint8  ccfi_sl;         /**< [GB.GG.DT2] select type of ccfi, see CTC_VLAN_TAG_SL_XXX */
    uint16 cvid_new;        /**< [GB.GG.DT2] new cvid, valid only if cvid_sl is CTC_VLAN_TAG_OP_REP|CTC_VLAN_TAG_OP_REP_OR_ADD|CTC_VLAN_TAG_OP_ADD*/
    uint8  ccos_new;        /**< [GB.GG.DT2] new ccos, valid only if ccos_sl is CTC_VLAN_TAG_OP_REP|CTC_VLAN_TAG_OP_REP_OR_ADD|CTC_VLAN_TAG_OP_ADD*/
    uint8  ccfi_new;        /**< [GB.GG.DT2] new ccfi, valid only if ccfi_sl is CTC_VLAN_TAG_OP_REP|CTC_VLAN_TAG_OP_REP_OR_ADD|CTC_VLAN_TAG_OP_ADD*/

    uint8  vlan_domain;     /**< [GB.GG.DT2] refer ctc_scl_vlan_domain_t. [ingress] */

};
typedef struct ctc_scl_vlan_edit_s ctc_scl_vlan_edit_t;


struct ctc_scl_query_s
{
    uint32  group_id;   /* [GB.GG.DT2] [in]     SCL group ID*/
    uint32  entry_size; /* [GB.GG.DT2] [in]     The maximum number of entry IDs to return. If 0, the number of entries is returned*/
    uint32* entry_array;/* [GB.GG.DT2] [in|out] A pointer to a memory buffer to hold the array of IDs*/
    uint32  entry_count;/* [GB.GG.DT2] [out]    Number of entries returned or. if entry_size  is 0, the number of entries available.*/
};
typedef struct ctc_scl_query_s ctc_scl_query_t;

enum ctc_scl_igs_action_flag_e
{
    CTC_SCL_IGS_ACTION_FLAG_DISCARD              = 1U << 0,  /**< [GB.GG.DT2] Discard the packet */
    CTC_SCL_IGS_ACTION_FLAG_STATS                = 1U << 1,  /**< [GB.GG.DT2] Statistic */
    CTC_SCL_IGS_ACTION_FLAG_PRIORITY_AND_COLOR   = 1U << 2,  /**< [GB.GG.DT2] Priority color */
    CTC_SCL_IGS_ACTION_FLAG_COPY_TO_CPU          = 1U << 3,  /**< [GB.GG.DT2] Copy to cpu */
    CTC_SCL_IGS_ACTION_FLAG_REDIRECT             = 1U << 4,  /**< [GB.GG.DT2] Redirect */
    CTC_SCL_IGS_ACTION_FLAG_AGING                = 1U << 5,  /**< [GB] Aging */
    CTC_SCL_IGS_ACTION_FLAG_FID                  = 1U << 6,  /**< [GB.GG.DT2] FID */
    CTC_SCL_IGS_ACTION_FLAG_VLAN_EDIT            = 1U << 7,  /**< [GB.GG.DT2] Vlan edit */
    CTC_SCL_IGS_ACTION_FLAG_LOGIC_PORT           = 1U << 8,  /**< [GB.GG.DT2] Logic port */
    CTC_SCL_IGS_ACTION_FLAG_BINDING_EN           = 1U << 9,  /**< [GB.GG.DT2] Enable binding */
    CTC_SCL_IGS_ACTION_FLAG_USER_VLANPTR         = 1U << 10, /**< [GB.GG.DT2] User vlan ptr */
    CTC_SCL_IGS_ACTION_FLAG_VPLS                 = 1U << 11, /**< [GB] VPLS */
    CTC_SCL_IGS_ACTION_FLAG_APS                  = 1U << 12, /**< [GB.GG.DT2] APS */
    CTC_SCL_IGS_ACTION_FLAG_ETREE_LEAF           = 1U << 13, /**< [GB.GG.DT2] Etree leaf */
    CTC_SCL_IGS_ACTION_FLAG_SERVICE_ID           = 1U << 14, /**< [GB] Service ID */
    CTC_SCL_IGS_ACTION_FLAG_IGMP_SNOOPING        = 1U << 15, /**< [GB] IGMP snooping */
    CTC_SCL_IGS_ACTION_FLAG_STP_ID               = 1U << 16, /**< [GG.DT2] STP ID */
    CTC_SCL_IGS_ACTION_FLAG_VPLS_OAM             = 1U << 17, /**< [GG.DT2] indecate VPLS OAM if set in L2VPN OAM, otherwise VPWS*/
    CTC_SCL_IGS_ACTION_FLAG_PRIORITY             = 1U << 18, /**< [GG.DT2] Priority */
    CTC_SCL_IGS_ACTION_FLAG_COLOR                = 1U << 19, /**< [GG.DT2] Color */
    CTC_SCL_IGS_ACTION_FLAG_DSCP                 = 1U << 20, /**< [GG.DT2] Dscp */
    CTC_SCL_IGS_ACTION_FLAG_L2VPN_OAM            = 1U << 21, /**< [GG.DT2] indecate L2VPN OAM, need config l2vpn_oam_id*/
    CTC_SCL_IGS_ACTION_FLAG_VRFID                = 1U << 22  /**< [GB.GG.DT2] Vrf ID of the route*/
};
typedef enum ctc_scl_igs_action_flag_e ctc_scl_igs_action_flag_t;

enum ctc_scl_igs_action_sub_flag_e
{
    CTC_SCL_IGS_ACTION_SUB_FLAG_SERVICE_ACL_EN      = 1U << 1,   /**< [GB.GG.DT2] Depend on FLAG_SERVICE_ID. */
    CTC_SCL_IGS_ACTION_SUB_FLAG_SERVICE_QUEUE_EN    = 1U << 2,   /**< [GB] Depend on FLAG_SERVICE_ID. need binding logic port*/
    CTC_SCL_IGS_ACTION_SUB_FLAG_SERVICE_POLICER_EN  = 1U << 3    /**< [GB.GG.DT2] Depend on FLAG_SERVICE_ID. */
};
typedef enum ctc_scl_igs_action_sub_flag_e ctc_scl_igs_action_sub_flag_t;

enum ctc_scl_bind_type_e
{
    CTC_SCL_BIND_TYPE_PORT,          /**< [GB.GG.DT2] Port bind */
    CTC_SCL_BIND_TYPE_VLAN,          /**< [GB.GG.DT2] Vlan bind */
    CTC_SCL_BIND_TYPE_IPV4SA,        /**< [GB.GG.DT2] Ipv4-SA bind */
    CTC_SCL_BIND_TYPE_IPV4SA_VLAN,   /**< [GB.GG.DT2] Ipv4-SA and Vlan bind */
    CTC_SCL_BIND_TYPE_MACSA,         /**< [GB.GG.DT2] MAC-SA bind */
    CTC_SCL_BIND_TYPE_MAX            /**< [GB.GG.DT2] Max bind type */
};
typedef enum ctc_scl_bind_type_e ctc_scl_bind_type_t;

struct ctc_scl_bind_s
{
    ctc_scl_bind_type_t type;        /**< [GB.GG.DT2] refer ctc_scl_bind_type_t */
    mac_addr_t          mac_sa;      /**< [GB.GG.DT2] MAC-SA */
    uint32              ipv4_sa;     /**< [GB.GG.DT2]  Ipv4-SA */
    uint32              gport;       /**< [GB.GG.DT2] Global port */
    uint16              vlan_id;     /**< [GB.GG.DT2] VLAN ID*/
};
typedef struct ctc_scl_bind_s ctc_scl_bind_t;

struct ctc_scl_aps_s
{
    uint16   protected_vlan;         /**< [GB.GG.DT2] Protected vlan */
    uint16   aps_select_group_id;    /**< [GB.GG.DT2] APS select group id*/
    uint8    is_working_path;        /**< [GB.GG.DT2] is working path */
    uint8    protected_vlan_valid;   /**< [GB.GG.DT2] Protected vlan valid */
};
typedef struct ctc_scl_aps_s ctc_scl_aps_t;

struct ctc_scl_vpls_s
{
    uint8 mac_limit_en;             /**< [GB] Enable mac limit */
    uint8 learning_en;              /**< [GB] Enable learning */
};
typedef struct ctc_scl_vpls_s ctc_scl_vpls_t;

struct ctc_scl_logic_port_s
{
    uint16 logic_port;                      /**< [GB.GG.DT2] Logic port */
    uint8  logic_port_type;                 /**< [GB.GG.DT2] If set, indicates logic port horizon split. Used for VPLS. */
};
typedef struct ctc_scl_logic_port_s ctc_scl_logic_port_t;

struct ctc_scl_igs_action_s
{
    uint32                      flag;          /**< [GB.GG.DT2] Bitmap of CTC_SCL_IGS_ACTION_FLAG_XXX */
    uint32                      sub_flag;      /**< [GB.GG.DT2] Bitmap of CTC_SCL_IGS_ACTION_SUB_FLAG_XXX */

    uint16                      fid;           /**< [GB.GG.DT2] Can be used as VPLS vsiid.*/
    uint16                      service_id;    /**< [GB] Service ID */
    uint32                      nh_id;         /**< [GB.GG.DT2] Forward nexthop ID, shared by scl, qos and pbr*/
    uint8                       color;         /**< [GB.GG.DT2] Color: green, yellow, or red :CTC_QOS_COLOR_XXX*/
    uint8                       priority;      /**< [GB.GG.DT2] Priority: 0 - 63 */
    uint16                      user_vlanptr;  /**< [GB.GG.DT2] User vlan ptr */
    uint32                      stats_id;      /**< [GB.GG.DT2] Stats id */
    uint8                       stp_id;        /**< [GG.DT2] STP id: 1 - 127 */
    uint8                       dscp;          /**< [GG.DT2] DSCP */
    uint16                      l2vpn_oam_id;  /**< [GG.DT2] vpws oam id or vpls fid */
    uint16                      policer_id;    /**< [GG.DT2] Policer ID */
    uint16                      vrf_id;        /**< [GB.GG.DT2] Vrf ID of the route */
    ctc_scl_bind_t              bind;          /**< [GB.GG.DT2] refer ctc_scl_bind_t */
    ctc_scl_aps_t               aps;           /**< [GB.GG.DT2] refer ctc_scl_aps_t */
    ctc_scl_vpls_t              vpls;          /**< [GB.GG.DT2] refer ctc_scl_vpls_t */
    ctc_scl_logic_port_t        logic_port;    /**< [GB.GG.DT2] refer ctc_scl_logic_port_t */
    ctc_scl_vlan_edit_t         vlan_edit;     /**< [GB.GG.DT2] refer ctc_scl_vlan_edit_t */
};
typedef struct ctc_scl_igs_action_s ctc_scl_igs_action_t;

enum ctc_scl_egs_action_flag_e
{
    CTC_SCL_EGS_ACTION_FLAG_DISCARD    = 1U << 0, /**< [GB.GG.DT2] Discard the packet */
    CTC_SCL_EGS_ACTION_FLAG_STATS      = 1U << 1, /**< [GB.GG.DT2] Statistic */
    CTC_SCL_EGS_ACTION_FLAG_AGING      = 1U << 2, /**< [GB] Aging */
    CTC_SCL_EGS_ACTION_FLAG_VLAN_EDIT  = 1U << 3  /**< [GB.GG.DT2] Vlan edit */
};
typedef enum ctc_scl_egs_action_flag_e ctc_scl_egs_action_flag_t;

struct ctc_scl_egs_action_s
{
    uint32                          flag;           /**< [GB.GG.DT2] refer CTC_SCl_EGS_ACTION_XXX*/
    uint32                          stats_id;       /**< [GB.GG.DT2] Stats id */
    ctc_scl_vlan_edit_t             vlan_edit;      /**< [GB.GG.DT2] Refer ctc_scl_vlan_edit_t */
};
typedef struct ctc_scl_egs_action_s ctc_scl_egs_action_t;

enum ctc_scl_flow_action_flag_e
{
    CTC_SCL_FLOW_ACTION_FLAG_DISCARD                            = 1U << 0,  /**< [GG.DT2] Discard the packet */
    CTC_SCL_FLOW_ACTION_FLAG_STATS                                = 1U << 1,  /**< [GG.DT2] Statistic */
    CTC_SCL_FLOW_ACTION_FLAG_TRUST                                = 1U << 2,  /**< [GG.DT2] QoS trust state */
    CTC_SCL_FLOW_ACTION_FLAG_COPY_TO_CPU                    = 1U << 3,  /**< [GG.DT2] Copy to cpu */
    CTC_SCL_FLOW_ACTION_FLAG_REDIRECT                           = 1U << 4,  /**< [GG.DT2] Redirect */
    CTC_SCL_FLOW_ACTION_FLAG_MICRO_FLOW_POLICER      = 1U << 5, /**< [GG] Micro Flow policer */
    CTC_SCL_FLOW_ACTION_FLAG_MACRO_FLOW_POLICER     = 1U << 6, /**< [GG] Macro Flow Policer */
    CTC_SCL_FLOW_ACTION_FLAG_METADATA                         = 1U << 7, /**< [GG.DT2] Metadata */
    CTC_SCL_FLOW_ACTION_FLAG_POSTCARD_EN                    = 1U << 8,  /**< [GG.DT2] Enable postcard*/
    CTC_SCL_FLOW_ACTION_FLAG_PRIORITY                            = 1U << 9, /**< [GG.DT2] Priority */
    CTC_SCL_FLOW_ACTION_FLAG_COLOR                                 = 1U << 10,  /**< [GG.DT2] Color */
    CTC_SCL_FLOW_ACTION_FLAG_DENY_BRIDGE                     = 1U << 11,  /**< [GG.DT2] Deny bridging process */
    CTC_SCL_FLOW_ACTION_FLAG_DENY_LEARNING                 = 1U << 12,  /**< [GG.DT2] Deny learning process */
    CTC_SCL_FLOW_ACTION_FLAG_DENY_ROUTE                       = 1U << 13,  /**< [GG.DT2] Deny routing process */
    CTC_SCL_FLOW_ACTION_FLAG_FORCE_BRIDGE                    = 1U << 14,  /**< [GG.DT2] Force bridging process */
    CTC_SCL_FLOW_ACTION_FLAG_FORCE_LEARNING                = 1U << 15,  /**< [GG.DT2] Force learning process */
    CTC_SCL_FLOW_ACTION_FLAG_FORCE_ROUTE                      = 1U << 16,  /**< [GG.DT2] Force routing process */
    CTC_SCL_FLOW_ACTION_FLAG_ACL_FLOW_TCAM_EN           = 1U << 17,  /**< [GG.DT2] Enable acl flow tcam lookup */
    CTC_SCL_FLOW_ACTION_FLAG_ACL_FLOW_HASH_EN           = 1U << 18,  /**< [GG.DT2] Enable acl flow hash lookup */
    CTC_SCL_FLOW_ACTION_FLAG_OVERWRITE_ACL_FLOW_TCAM   = 1U << 19,  /**< [GG.DT2] Overwrite acl flow tcam lookup */
    CTC_SCL_FLOW_ACTION_FLAG_OVERWRITE_ACL_FLOW_HASH   = 1U << 20,  /**< [GG.DT2] Overwrite acl flow hash lookup */
    CTC_SCL_FLOW_ACTION_FLAG_OVERWRITE_PORT_IPFIX           = 1U << 21,  /**< [GG.DT2] Overwrite port ipfix hash lookup */
    CTC_SCL_FLOW_ACTION_FLAG_FID                                             = 1U << 22, /**< [GG.DT2] fid */
    CTC_SCL_FLOW_ACTION_FLAG_VRFID                                         = 1U << 23  /**< [GG.DT2] Vrf ID of the route */
};
typedef enum ctc_scl_flow_action_flag_e ctc_scl_flow_action_flag_t;

struct ctc_scl_flow_action_acl_s
{
    uint8                        acl_hash_lkup_type;               /**< [GG.DT2] Acl hash lookup type, CTC_ACL_HASH_LKUP_TYPE_XXX */
    uint8                        acl_hash_field_sel_id;            /**< [GG.DT2] Acl hash lookup field select */
    uint8                        acl_tcam_lkup_type;               /**< [GG.DT2] Acl tcam lookup type, CTC_ACL_TCAM_LKUP_TYPE_XXX */
    uint8                        acl_tcam_lkup_priority;           /**< [DT2] Acl tcam lookup priority */
    uint16                       acl_tcam_lkup_class_id;           /**< [GG.DT2] Acl tcam lookup class id */
    uint8                        acl_tcam_use_logic_port;          /**< [DT2] if set, acl use logic_port to lookup, other, acl use global_port to lookup */
    uint8                        acl_tcam_use_port_bitmap;         /**< [DT2] if set, acl use port_bitmap to lookup */
    uint8                        acl_tcam_use_metadata;            /**< [DT2] if set, acl use metadata to lookup*/
    uint8                        rsv[3];
};
typedef struct ctc_scl_flow_action_acl_s ctc_scl_flow_action_acl_t;

struct ctc_scl_flow_action_s
{
    uint32                      flag;          /**< [GG.DT2] Bitmap of CTC_SCL_FLOW_ACTION_FLAG_XXX */
    uint32                      metadata;            /**< [GG.DT2] Metadata*/
    uint32                      nh_id;         /**< [GG.DT2] Forward nexthop ID, shared by scl, qos and pbr*/
    uint8                        color;         /**< [GG.DT2] Color: green, yellow, or red :CTC_QOS_COLOR_XXX*/
    uint8                        priority;      /**< [GG.DT2] Priority: 0 - 63 */
    uint8                        trust;               /**< [GG.DT2] QoS trust state, CTC_QOS_TRUST_XXX */
    uint8                        rsv;
    uint16                     micro_policer_id;    /**< [GG.DT2] Micro flow policer ID */
    uint16                     macro_policer_id;    /**< [GG.DT2] Macro flow policer ID */
    uint32                     stats_id;      /**< [GG.DT2] Stats id */
    uint8                       ipfix_lkup_type;     /**< [GG.DT2] Refer to ctc_ipfix_lkup_type_t */
    uint8                       ipfix_field_sel_id;   /**< [GG.DT2] Field select id , used associate with ctc_ipfix_key_type_t */
    uint16                     fid;                       /**<[GG.DT2] fid */
    uint16                     vrf_id;                  /**< [GG.DT2] Vrf ID of the route */
    uint8                        rsv0[2];

    ctc_scl_flow_action_acl_t     acl;      /**< [GG.DT2] Action to acl */
};
typedef struct ctc_scl_flow_action_s ctc_scl_flow_action_t;


struct ctc_scl_action_s
{
    ctc_scl_action_type_t           type;           /**< [GB.GG.DT2] Refer ctc_scl_action_type_t */
    union
    {
        ctc_scl_igs_action_t          igs_action;     /**< [GB.GG.DT2] Refer ctc_scl_igs_action_t */
        ctc_scl_egs_action_t        egs_action;     /**< [GB.GG.DT2] Refer ctc_scl_egs_action_t */
        ctc_scl_flow_action_t       flow_action;     /**< [GG.DT2] Refer ctc_scl_flow_action_t */
    }u;

};
typedef struct ctc_scl_action_s ctc_scl_action_t;

struct ctc_scl_default_action_s
{
    uint32 gport;         /**< [GB.GG.DT2] Global port */
    ctc_scl_action_t action;        /**< [GB.GG.DT2] scl action struct*/
};
typedef struct ctc_scl_default_action_s ctc_scl_default_action_t;


/** @brief  scl entry struct */
struct ctc_scl_entry_s
{
    ctc_scl_key_t key;              /**< [GB.GG.DT2] scl key struct*/
    ctc_scl_action_t action;        /**< [GB.GG.DT2] scl action struct*/

    uint32 entry_id;                /**< [GB.GG.DT2] scl action id. */
    uint8  priority_valid;          /**< [GB.GG.DT2] scl entry prioirty valid. if not valid, use default priority */
    uint32 priority;                /**< [GB.GG.DT2] scl entry priority. 0-0xffffffff */
    uint8  mode;                    /**< [DT2] 0, use sturct to install key and action; 1, use field to install key and action */
};
typedef struct ctc_scl_entry_s ctc_scl_entry_t;

/** @brief  scl copy entry struct */
struct ctc_scl_copy_entry_s
{
    uint32 src_entry_id;  /**< [GB.GG.DT2] SCL entry ID to copy from */
    uint32 dst_entry_id;  /**< [GB.GG.DT2] New entry copied from src_entry */
    uint32 dst_group_id;  /**< [GB.GG.DT2] Group ID new entry belongs */
};
typedef struct ctc_scl_copy_entry_s ctc_scl_copy_entry_t;



/** @brief  scl group type */
enum ctc_scl_group_type_e
{
    CTC_SCL_GROUP_TYPE_GLOBAL,       /**< [GB.GG.DT2] Global scl, mask ports. */
    CTC_SCL_GROUP_TYPE_PORT,         /**< [GB.GG.DT2] Port scl, care gport. (GB)only for vlan key. */
    CTC_SCL_GROUP_TYPE_PORT_CLASS,   /**< [GB.GG.DT2] A port class scl is against a class(group) of port*/
    CTC_SCL_GROUP_TYPE_LOGIC_PORT,   /**< [GG.DT2] Logic Port scl, care logic_port. */
    CTC_SCL_GROUP_TYPE_HASH,         /**< [GB.GG.DT2] Hash group. */
    CTC_SCL_GROUP_TYPE_MAX
};
typedef enum ctc_scl_group_type_e ctc_scl_group_type_t;

/** @brief  scl group info */
struct ctc_scl_group_info_s
{
    uint8 type;                      /**< [GB.GG.DT2] CTC_SCL_GROUP_TYPE_XXX*/
    uint8 lchip;                     /**< [GB.GG.DT2] Local chip id. only for type= PORT_CLASS. Other type ignore it.*/
    uint8 priority;                  /**< [GG.DT2] install_group ignore this. Group priority 0-1. */
    union
    {
        uint16 port_class_id;        /**< [GB.GG.DT2] port class id. multiple ports can share same un.un.port_class_id. for GB <1~61>. for HB <0~127> */
        uint32 gport;       /**< [GB.GG.DT2] global_port, include linkagg */
        uint16 logic_port;      /**< [GB.GG.DT2] Logic port */
    }un;
};
typedef struct ctc_scl_group_info_s ctc_scl_group_info_t;

enum ctc_scl_field_action_type_e
{
    /*Ingress Egress Flow share*/
    CTC_SCL_FIELD_ACTION_TYPE_DISCARD ,                 /**< [DT2] DisCard Packet of All Color. */
    CTC_SCL_FIELD_ACTION_TYPE_STATS ,                   /**< [DT2] Packet Statistics; data0: Stats Id. */
    CTC_SCL_FIELD_ACTION_TYPE_VLAN_EDIT,               /**< [DT2] Vlan Edit;ext_data: ctc_scl_vlan_edit_t. */

    /*Ingress Flow share*/
    CTC_SCL_FIELD_ACTION_TYPE_COPY_TO_CPU ,             /**< [DT2] Copy To Cpu. */
    CTC_SCL_FIELD_ACTION_TYPE_REDIRECT ,                /**< [DT2] Redirect Packet; data0: Nexthop Id. */
    CTC_SCL_FIELD_ACTION_TYPE_FID ,                     /**< [DT2] Fid; data0: fid. */
    CTC_SCL_FIELD_ACTION_TYPE_VRFID ,                   /**< [DT2] Vrf id; data0: Vrfid. */
    CTC_SCL_FIELD_ACTION_TYPE_PRIORITY ,                /**< [DT2] New Priority of All Color; data0: New Priority. */
    CTC_SCL_FIELD_ACTION_TYPE_COLOR ,                   /**< [DT2] Change Color; data0: New color. */
    CTC_SCL_FIELD_ACTION_TYPE_DSCP ,                    /**< [DT2] Dscp; data0: New Dscp*/
    CTC_SCL_FIELD_ACTION_TYPE_POLICER_ID ,              /**< [DT2] policer id; data0: Policer Id.*/
    CTC_SCL_FIELD_ACTION_TYPE_TRUST_DSCP ,              /**< [DT2] trust Dscp. */

    /*only valid for Ingress Action*/
    CTC_SCL_FIELD_ACTION_TYPE_LOGIC_PORT ,              /**< [DT2] Logic Port; ext_data: ctc_scl_logic_port_t. */
    CTC_SCL_FIELD_ACTION_TYPE_USER_VLANPTR ,            /**< [DT2] User VlanPtr; data0: User VlanPtr */
    CTC_SCL_FIELD_ACTION_TYPE_APS  ,                    /**< [DT2] Aps Group; ext_data: ctc_scl_aps_t. */
    CTC_SCL_FIELD_ACTION_TYPE_ETREE_LEAF,               /**< [DT2] VPLS Etree Leaf. */
    CTC_SCL_FIELD_ACTION_TYPE_STP_ID ,                  /**< [DT2] Stp Id; data0: Stp Id. */

    /*only valid for Flow Action*/
    CTC_SCL_FIELD_ACTION_TYPE_METADATA ,                /**< [DT2] Metadata; data0: meta data. */
    CTC_SCL_FIELD_ACTION_TYPE_DENY_BRIDGE ,             /**< [DT2] Deny Bridge. */
    CTC_SCL_FIELD_ACTION_TYPE_DENY_LEARNING ,           /**< [DT2] Deny Learning. */
    CTC_SCL_FIELD_ACTION_TYPE_DENY_ROUTE ,              /**< [DT2] Deny Route. */
    CTC_SCL_FIELD_ACTION_TYPE_FORCE_BRIDGE ,            /**< [DT2] Force Bridge. */
    CTC_SCL_FIELD_ACTION_TYPE_FORCE_LEARNING ,          /**< [DT2] Force Learning. */
    CTC_SCL_FIELD_ACTION_TYPE_FORCE_ROUTE ,             /**< [DT2] Forece Route. */
    CTC_SCL_FIELD_ACTION_TYPE_ACL_TCAM_EN ,             /**< [DT2] Enable acl flow tcam lookup; ext_data: ctc_scl_flow_action_acl_t. */
    CTC_SCL_FIELD_ACTION_TYPE_ACL_HASH_EN ,             /**< [DT2] Enable acl flow hash lookup; ext_data: ctc_scl_flow_action_acl_t. */
    CTC_SCL_FIELD_ACTION_TYPE_OVERWRITE_ACL_TCAM ,      /**< [DT2] Overwrite acl flow tcam lookup. */
    CTC_SCL_FIELD_ACTION_TYPE_OVERWRITE_ACL_HASH ,      /**< [DT2] Overwrite acl flow hash lookup. */
    CTC_SCL_FIELD_ACTION_TYPE_ACL_QOS_USE_OUTERINFO ,   /**< [DT2] Acl qos user outer info. */
    CTC_SCL_FIELD_ACTION_TYPE_NUM
};
typedef enum ctc_scl_field_action_type_e ctc_scl_field_action_type_t;

struct ctc_scl_field_action_s
{
    uint32 type;                            /**< [DT2] Action Field type, CTC_SCL_ACTION_FIELD_TYPE_XXX. */

    uint32 data0;                           /**< [DT2] Action Field data0 (uint32). */
    uint32 data1;                           /**< [DT2] Action Field data1 (uint32). */
    void*  ext_data;                        /**< [DT2] Action Field data (void*). */
};
typedef struct ctc_scl_field_action_s ctc_scl_field_action_t;

#ifdef __cplusplus
}
#endif

#endif

