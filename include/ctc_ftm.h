/**
 @file ctc_ftm.h

 @author  Copyright (C) 2011 Centec Networks Inc.  All rights reserved.

 @date 2009-11-11

 @version v2.0

   This file contains all memory allocation related data structure, enum, macro and proto.
*/

#ifndef _CTC_FTM_H
#define _CTC_FTM_H
#ifdef __cplusplus
extern "C" {
#endif

/****************************************************************
*
* Defines and Macros
*
****************************************************************/
#define MAX_CTC_FTM_KEY_TYPE_SIZE (2 * CTC_FTM_KEY_TYPE_MAX)

#define CTC_FTM_SRAM_MAX (32)

/**
 @defgroup ftm FTM
 @{
*/

/**
 @brief Define allocation key location
*/
enum ctc_ftm_key_location_e
{
    CTC_FTM_INT_TCAM,         /**< [HB.GB]Location in internal TCAM*/
    CTC_FTM_EXT_TCAM,         /**< [HB]Location in external TCAM*/
    CTC_FTM_HASH,             /**< [HB]Location in SRAM*/
    CTC_FTM_LOCATION_MAX
};
typedef enum ctc_ftm_key_location_e ctc_ftm_key_location_t;

/**
 @brief Define key type
*/
#ifdef HUMBER
enum ctc_ftm_key_type_e
{
    CTC_FTM_KEY_TYPE_IPV6_UCAST,         /**< [HB]Ipv6 unicast route key, must be first enum */
    CTC_FTM_KEY_TYPE_IPV4_UCAST,         /**< [HB]Ipv4 unicast route key*/
    CTC_FTM_KEY_TYPE_IPV4_MCAST,         /**< [HB]Ipv4 multicast route key*/
    CTC_FTM_KEY_TYPE_IPV4_NAT,           /**< [HB]Ipv4 nat key*/
    CTC_FTM_KEY_TYPE_IPV4_PBR,           /**< [HB]Ipv4 pbr key*/
    CTC_FTM_KEY_TYPE_USERID_MAC,         /**< [HB]User id mac key*/
    CTC_FTM_KEY_TYPE_USERID_VLAN,        /**< [HB]User id vlan key*/
    CTC_FTM_KEY_TYPE_IPV6_MCAST,         /**< [HB]Ipv6 multicast route key*/
    CTC_FTM_KEY_TYPE_IPV6_NAT,           /**< [HB]Ipv6 nat key*/
    CTC_FTM_KEY_TYPE_FIB,                /**< [HB]Mac key*/
    CTC_FTM_KEY_TYPE_IPV6_PBR,           /**< [HB]Ipv6 pbr key*/
    CTC_FTM_KEY_TYPE_USERID_IPV4,        /**< [HB]User id ipv4 key*/
    CTC_FTM_KEY_TYPE_USERID_IPV6,        /**< [HB]User id ipv6 key*/
    CTC_FTM_KEY_TYPE_OAM,                /**< [HB]Oam key*/
    CTC_FTM_KEY_TYPE_ACL_IPV6,           /**< [HB]Acl ipv6 key*/
    CTC_FTM_KEY_TYPE_ACL_MAC_IPV4,       /**< [HB]Acl mac ipv4 mpls key*/
    CTC_FTM_KEY_TYPE_QOS_MAC_IPV4,       /**< [HB]Qos mac ipv4 mpls key*/
    CTC_FTM_KEY_TYPE_QOS_IPV6,           /**< [HB]Qos ipv6 key*/

    CTC_FTM_KEY_TYPE_RSV,
    CTC_FTM_KEY_TYPE_MAX
};
typedef enum ctc_ftm_key_type_e ctc_ftm_key_type_t;

#else

enum ctc_ftm_key_type_e
{
    CTC_FTM_KEY_TYPE_IPV6_ACL0,         /**< [GB]Ipv6 ACL key */
    CTC_FTM_KEY_TYPE_IPV6_ACL1,         /**< [GB]Ipv6 ACL key */

    CTC_FTM_KEY_TYPE_SCL0,              /**< [GG]SCL key */
    CTC_FTM_KEY_TYPE_SCL1,              /**< [GG]SCL key */

    CTC_FTM_KEY_TYPE_ACL0,              /**< [GB.GG]ACL key include MAC , IPV4, MPLS */
    CTC_FTM_KEY_TYPE_ACL1,              /**< [GB.GG]ACL key include MAC , IPV4, MPLS */
    CTC_FTM_KEY_TYPE_ACL2,              /**< [GB.GG]ACL key include MAC , IPV4, MPLS */
    CTC_FTM_KEY_TYPE_ACL3,              /**< [GB.GG]ACL key include MAC , IPV4, MPLS */

    CTC_FTM_KEY_TYPE_ACL0_EGRESS,       /**< [GG]Egress ACL key include MAC , IPV4, IPV6, MPLS */

    CTC_FTM_KEY_TYPE_IPV4_MCAST,        /**< [GB]IPV4 mcast key*/
    CTC_FTM_KEY_TYPE_IPV6_MCAST,        /**< [GB]IPV6 mcast key*/

    CTC_FTM_KEY_TYPE_VLAN_SCL,          /**< [GB]SCL VLAN key*/
    CTC_FTM_KEY_TYPE_MAC_SCL,           /**< [GB]SCL MAC key*/
    CTC_FTM_KEY_TYPE_IPV4_SCL,          /**< [GB]SCL IPv4 key*/

    CTC_FTM_KEY_TYPE_IPV6_SCL,          /**< [GB]SCL IPv6 key*/

    CTC_FTM_KEY_TYPE_FDB,               /**< [GB]FDB key*/
    CTC_FTM_KEY_TYPE_IPV4_UCAST,        /**< [GB.GG]IPv4 Ucast key*/
    CTC_FTM_KEY_TYPE_IPV6_UCAST,        /**< [GB.GG]IPv6 Ucast key*/

    CTC_FTM_KEY_TYPE_IPV4_NAT,          /**< [GB.GG]IPv4 Nat key*/
    CTC_FTM_KEY_TYPE_IPV6_NAT,          /**< [GB.GG]IPv6 Nat key*/
    CTC_FTM_KEY_TYPE_IPV4_PBR,          /**< [GB.GG]IPv4 PBR key*/
    CTC_FTM_KEY_TYPE_IPV6_PBR,          /**< [GB.GG]IPv6 PBR key*/

    CTC_FTM_KEY_TYPE_IPV4_TUNNEL,       /**< [GB]IPv4 Tunnel key*/
    CTC_FTM_KEY_TYPE_IPV6_TUNNEL,       /**< [GB]IPv6 Tunnel key*/

    CTC_FTM_KEY_TYPE_MAX
};
typedef enum ctc_ftm_key_type_e ctc_ftm_key_type_t;
#endif  /*!HUMBER*/

/**
 @brief Define key size
*/
enum ctc_ftm_key_size_e
{
    CTC_FTM_KEY_SIZE_INVALID = 0,   /**< [HB.GB]Invalid key size*/
    CTC_FTM_KEY_SIZE_80_BIT  = 1,   /**< [HB.GB]80 bits key size*/
    CTC_FTM_KEY_SIZE_160_BIT = 2,   /**< [HB.GB.GG]160 bits key size*/
    CTC_FTM_KEY_SIZE_320_BIT = 4,   /**< [HB.GB.GG]320 bits key size*/
    CTC_FTM_KEY_SIZE_640_BIT = 8,   /**< [HB.GB.GG]640 bits key size*/
    CTC_FTM_KEY_SIZE_MAX
};
typedef enum ctc_ftm_key_size_e ctc_ftm_key_size_t;

/**
 @brief Define TCAM type
*/
enum ctc_ftm_tcam_type_e
{
    CTC_FTM_TCAM_TYPE_NL9K = 2, /**< [HB]Netlogic 9000 TCAM type*/
    CTC_FTM_TCAM_TYPE_MAX
};
typedef enum ctc_ftm_tcam_type_e ctc_ftm_tcam_type_t;

/**
 @brief Profile key information
*/
struct ctc_ftm_key_info_s
{
    uint8  key_size;                    /**< [HB.GB.GG]Value = {1,2,4,8}, indicates {80b,160b,320b,640b}. */
    uint32 max_key_index;               /**< [HB.GB]Key total number. key_max_index * key_size = consumed 80b tcam entry. */
    uint8  key_media;                   /**< [HB.GB]ctc_ftm_key_location_t*/
    uint8  key_id;                      /**< [HB.GB.GG]Key type*/

    uint32 tcam_bitmap;                         /**< [GG]Tcam Key tcam bitmap*/
    uint32 tcam_start_offset[CTC_FTM_SRAM_MAX]; /**< [GG]Start Offset of TCAM*/
    uint32 tcam_entry_num[CTC_FTM_SRAM_MAX];    /**< [GG]Entry number in TCAM*/
};
typedef struct ctc_ftm_key_info_s ctc_ftm_key_info_t;

/**
 @brief Define table type
*/
#ifdef HUMBER
enum ctc_ftm_tbl_type_e
{
    CTC_FTM_TBL_TYPE_MPLS,          /**< [HB]store global MPLS table's sram size */
    CTC_FTM_TBL_TYPE_GLB_MET,       /**< [HB]store global MET table's sram size */
    CTC_FTM_TBL_TYPE_GLB_NH,        /**< [HB]store global Nexthop table's sram size */
    CTC_FTM_TBL_TYPE_LOCAL_NH,      /**< [HB]store local Nexthop table's sram size */
    CTC_FTM_TBL_TYPE_L2EDIT,        /**< [HB]store l2edit table's sram size */
    CTC_FTM_TBL_TYPE_L3EDIT,        /**< [HB]store l3edit table's sram size */
    CTC_FTM_TBL_TYPE_IP_TUNNEL,     /**< [HB]store IP-tunnel table's sram size*/
    CTC_FTM_TBL_TYPE_HASH,          /**< [HB]Optional hash size, 48K or 96K */
    CTC_FTM_TBL_TYPE_ASS_DYN_SRAM,  /**< [HB]Internal Sram for associate and dynamic table */
    CTC_FTM_TBL_TYPE_EXT_TCAM_TYPE, /**< [HB]External TCAM hardware type, default NL9K */
    CTC_FTM_TBL_TYPE_EXT_TCAM_SIZE, /**< [HB]External external tcam size, 256K */
    CTC_FTM_TBL_TYPE_EXT_SRAM_SIZE, /**< [HB]External sram size */
    CTC_FTM_TBL_TYPE_EXT_QDR_SIZE,  /**< [HB]External QDR size */
    CTC_FTM_TBL_TYPE_FLOW_PLOCIER,  /**< [HB]store policer table's sram size*/
    CTC_FTM_TBL_TYPE_FWD_STATS,     /**< [HB]store forward statistics table's sram size*/

    CTC_FTM_TBL_TYPE_MAX
};
typedef enum ctc_ftm_tbl_type_e ctc_ftm_tbl_type_t;

#else

enum ctc_ftm_tbl_type_e
{

    CTC_FTM_TBL_TYPE_LPM_PIPE0,     /**< [GB.GG] LPM PIPE0 table*/

    CTC_FTM_TBL_TYPE_NEXTHOP,       /**< [GB.GG] Nexthop table*/
    CTC_FTM_TBL_TYPE_FWD,           /**< [GB.GG] Fwd table*/
    CTC_FTM_TBL_TYPE_MET,           /**< [GB.GG] Met table*/
    CTC_FTM_TBL_TYPE_EDIT,          /**< [GB.GG] l2 and l3 edit table*/

    CTC_FTM_TBL_TYPE_OAM_MEP,       /**< [GB.GG] All OAM table*/

    CTC_FTM_TBL_TYPE_STATS,         /**< [GB.GG] statistics table*/
    CTC_FTM_TBL_TYPE_LM,            /**< [GB.GG] OAM LM statistics table*/
    CTC_FTM_TBL_TYPE_SCL_HASH_KEY,  /**< [GB.GG] SCL hash key table*/
    CTC_FTM_TBL_TYPE_SCL_HASH_AD,   /**< [GB.GG] SCL AD table*/

    CTC_FTM_TBL_TYPE_FIB_HASH_KEY,  /**< [GB] MAC, IP key table*/
    CTC_FTM_TBL_TYPE_LPM_HASH_KEY,  /**< [GB] LPM hash key table*/
    CTC_FTM_TBL_TYPE_FIB_HASH_AD,   /**< [GB] MAC, IP AD table*/
    CTC_FTM_TBL_TYPE_LPM_PIPE1,     /**< [GB] LPM PIPE1 table*/
    CTC_FTM_TBL_TYPE_LPM_PIPE2,     /**< [GB] LPM PIPE2 table*/
    CTC_FTM_TBL_TYPE_LPM_PIPE3,     /**< [GB] LPM PIPE3 table*/
    CTC_FTM_TBL_TYPE_MPLS,          /**< [GB] MPLS table*/

    CTC_FTM_TBL_TYPE_FIB0_HASH_KEY,      /**< [GG] MAC, IPDA key table*/
    CTC_FTM_TBL_TYPE_DSMAC_AD,           /**< [GG] MAC AD table*/
    CTC_FTM_TBL_TYPE_FIB1_HASH_KEY,      /**< [GG] NAT, IPSA key table*/
    CTC_FTM_TBL_TYPE_DSIP_AD,            /**< [GG] IP AD table*/

    CTC_FTM_TBL_TYPE_XCOAM_HASH_KEY,     /**< [GG] OAM and Egress Vlan Xlate table*/
    CTC_FTM_TBL_TYPE_FLOW_HASH_KEY,      /**< [GG] Flow hash key*/
    CTC_FTM_TBL_TYPE_FLOW_AD,            /**< [GG] Flow Ad table*/
    CTC_FTM_TBL_TYPE_IPFIX_HASH_KEY,     /**< [GG] IPFix hash key*/
    CTC_FTM_TBL_TYPE_IPFIX_AD,           /**< [GG] IPFix AD table*/
    CTC_FTM_TBL_TYPE_OAM_APS,            /**< [GG] APS table*/

    CTC_FTM_TBL_TYPE_MAX
};
typedef enum ctc_ftm_tbl_type_e ctc_ftm_tbl_type_t;
#endif  /*!HUMBER*/

enum ctc_ftm_spec_e
{
    CTC_FTM_SPEC_INVALID,
    CTC_FTM_SPEC_MAC,               /**<[GG] the FDB spec>*/
    CTC_FTM_SPEC_IPUC_HOST,         /**<[GG] the IP Host route spec>*/
    CTC_FTM_SPEC_IPUC_LPM,          /**<[GG] the IP LPM route spec>*/
    CTC_FTM_SPEC_IPMC,              /**<[GG] the IPMC spec>*/
    CTC_FTM_SPEC_ACL,               /**<[GG] the ACL spec>*/
    CTC_FTM_SPEC_SCL_FLOW,          /**<[GG] the flow scl spec >*/
    CTC_FTM_SPEC_ACL_FLOW,          /**<[GG] the flow acl spec>*/
    CTC_FTM_SPEC_OAM,               /**<[GG] the OAM session spec>*/
    CTC_FTM_SPEC_SCL,               /**<[GG] the ingress SCL spec>*/
    CTC_FTM_SPEC_TUNNEL,            /**<[GG] IP Tunnel/ Nvgre /Vxlan spec>*/
    CTC_FTM_SPEC_MPLS,              /**<[GG] the MPLS spec>*/
    CTC_FTM_SPEC_VRF,               /**<[GG] the vrf spec>*/
    CTC_FTM_SPEC_L2MC,              /**<[GG] the L2MC spec>*/
    CTC_FTM_SPEC_FID,               /**<[GG] the FID spec>*/
    CTC_FTM_SPEC_IPFIX,             /**<[GG] the IPFix flow spec>*/

    CTC_FTM_SPEC_MAX
};
typedef enum ctc_ftm_spec_e ctc_ftm_spec_t;

/**
 @brief Define tble type
*/
enum ctc_ftm_flag_e
{
    CTC_FTM_FLAG_IPUC_SA_EN             = (1 << 0), /**< [HB]Enable rpf */
    CTC_FTM_FLAG_ACL_QOS_DUAL_LKUP      = (1 << 1), /**< [HB]Enable lookup acl/qos key at the same time */
    CTC_FTM_FLAG_ACL_QOS_MERGE_MAC_IP   = (1 << 2), /**< [HB]Enable merge acl/qos mac/ip Key */
    CTC_FTM_FLAG_MPLS_IN_EXT_SRAM       = (1 << 3), /**< [HB]Mpls table store in external sram or not */
    CTC_FTM_FLAG_MET_IN_EXT_SRAM        = (1 << 4), /**< [HB]MET table store in external sram or not */
    CTC_FTM_FLAG_NH_IN_EXT_SRAM         = (1 << 5), /**< [HB]Nexthop table store in external sram or not*/
    CTC_FTM_FLAG_L2EDIT_IN_EXT_SRAM     = (1 << 6), /**< [HB]L2edit table store in external sram or not */
    CTC_FTM_FLAG_L3EDIT_IN_EXT_SRAM     = (1 << 7), /**< [HB]L3edit table store in external sram or not*/
    CTC_FTM_FLAG_EXT_QDR_EN             = (1 << 8), /**< [HB]Enable external QDR*/
    CTC_FTM_FLAG_DISABLE_MERGE_MAC_IP_KEY_PHYSICAL = (1 << 9), /**< [HB]If disable merge mac ip key physical, mac key size is half of ipv4 key size, and not support ext tcam, not support acl key*/
    CTC_FTM_FLAG_COUPLE_EN              = (1 << 10), /**< [GG] If set couple mode Enable*/
    CTC_FTM_FLAG_MAX
};
typedef enum ctc_ftm_flag_e ctc_ftm_flag_t;

/**
 @brief Define profile type
*/
enum ctc_ftm_profile_type_e
{
    CTC_FTM_PROFILE_0,          /**< [GB.GG]Default profile*/
    CTC_FTM_PROFILE_1,          /**< [GB]Enterprise profile*/
    CTC_FTM_PROFILE_2,          /**< [GB]Bridge profile*/
    CTC_FTM_PROFILE_3,          /**< [GB]Ipv4 host profile*/
    CTC_FTM_PROFILE_4,          /**< [GB]Ipv4 lpm profile*/
    CTC_FTM_PROFILE_5,          /**< [GB]Ipv6 profile*/
    CTC_FTM_PROFILE_6,          /**< [GB]Metro profile*/
    CTC_FTM_PROFILE_7,          /**< [GB]VPWS ridge profile*/
    CTC_FTM_PROFILE_8,          /**< [GB]VPLS profile*/
    CTC_FTM_PROFILE_9,          /**< [GB]L3VPN profile*/
    CTC_FTM_PROFILE_10,         /**< [GB]PTN profile*/
    CTC_FTM_PROFILE_11,         /**< [GB]PON profile*/

    CTC_FTM_PROFILE_USER_DEFINE,/**< [GB.GG]FLEX profile, accoring key_info and tbl_info*/

    CTC_FTM_PROFILE_MAX
};
typedef enum ctc_ftm_profile_type_e ctc_ftm_profile_type_t;

/**
 @brief Profile table information
*/
struct ctc_ftm_tbl_info_s
{
    uint32  tbl_id;                             /**[GB.GG]ctc_ftm_tbl_type_t*/
    uint32 mem_bitmap;                          /**[GB.GG]Table allocation in which SRAM*/
    uint32 mem_start_offset[CTC_FTM_SRAM_MAX];  /**[GB.GG]Start Offset of SRAM*/
    uint32 mem_entry_num[CTC_FTM_SRAM_MAX];     /**[GB.GG]Entry number in SRAM*/
};
typedef struct ctc_ftm_tbl_info_s ctc_ftm_tbl_info_t;

/**
 @brief Profile misc information
*/
struct ctc_ftm_misc_info_s
{
    uint32 mcast_group_number;                  /**[GB.GG]The Mcast group Number*/
    uint32 glb_nexthop_number;                  /**[GB.GG]The nexthop Number for egress edit mode*/
    uint16 vsi_number;                          /**[GB]The VPLS VSI number*/
    uint16 ecmp_number;                         /**[GB]The ECMP number*/
    uint32 profile_specs[CTC_FTM_SPEC_MAX];     /**[GG]Profile specs*/

};
typedef struct ctc_ftm_misc_info_s ctc_ftm_misc_info_t;

/**
 @brief Profile information
*/
struct ctc_ftm_profile_info_s
{
    uint32 flag;                    /**< [HB.GG]Ftm flag refer to ctc_ftm_flag_t*/
    ctc_ftm_key_info_t* key_info;   /**< [HB.GB.GG]Profile key information*/
    uint16 key_info_size;           /**< [HB.GB.GG]Size of key_info, multiple of sizeof(ctc_ftm_key_info_t) */
    uint8 profile_type;             /**< [GB.GG]Profile type, refer to ctc_ftm_profile_type_t*/
    uint8  rsv0;

    uint32 table_size[CTC_FTM_TBL_TYPE_MAX];    /**< [HB]Ftm flexiable table size*/
    ctc_ftm_tbl_info_t *tbl_info;               /**< [GB.GG]table information  */
    uint16 tbl_info_size;                       /**< [GB.GG]Size of tbl_info, multiple of sizeof(ctc_ftm_tbl_info_t) */
    uint16 rsv1;

    ctc_ftm_misc_info_t  misc_info;             /**< [GB.GG]Misc info */
};
typedef struct ctc_ftm_profile_info_s ctc_ftm_profile_info_t;

/**@} end of @defgroup ftm FTM  */

#ifdef __cplusplus
}
#endif

#endif

