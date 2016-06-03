/**
 @file drv_ftm.h

 @date 2011-11-16

 @version v2.0

 alloc memory and offset
*/

#ifndef _SYS_GOLDENGATE_FTM_H
#define _SYS_GOLDENGATE_FTM_H
#ifdef __cplusplus
extern "C" {
#endif

#define DRV_FTM_MEM_MAX (32)

/**
 @brief Define key size
*/
enum drv_ftm_key_size_e
{
    DRV_FTM_KEY_SIZE_INVALID = 0,   /**< [HB.GB]Invalid key size*/
    DRV_FTM_KEY_SIZE_80_BIT  = 1,   /**< [HB.GB]80 bits key size*/
    DRV_FTM_KEY_SIZE_160_BIT = 2,   /**< [HB.GB]160 bits key size*/
    DRV_FTM_KEY_SIZE_320_BIT = 4,   /**< [HB.GB]320 bits key size*/
    DRV_FTM_KEY_SIZE_640_BIT = 8,   /**< [HB.GB]640 bits key size*/
    DRV_FTM_KEY_SIZE_MAX
};
typedef enum drv_ftm_key_size_e drv_ftm_key_size_t;


enum drv_ftm_key_type_e
{
    DRV_FTM_KEY_TYPE_IPV6_ACL0,         /**< [GB]Ipv6 ACL key */
    DRV_FTM_KEY_TYPE_IPV6_ACL1,         /**< [GB]Ipv6 ACL key */

    DRV_FTM_KEY_TYPE_SCL0,              /**< [GG]SCL key */
    DRV_FTM_KEY_TYPE_SCL1,              /**< [GG]SCL key */

    DRV_FTM_KEY_TYPE_ACL0,              /**< [GB.GG]ACL key include MAC , IPV4, MPLS */
    DRV_FTM_KEY_TYPE_ACL1,              /**< [GB.GG]ACL key include MAC , IPV4, MPLS */
    DRV_FTM_KEY_TYPE_ACL2,              /**< [GB.GG]ACL key include MAC , IPV4, MPLS */
    DRV_FTM_KEY_TYPE_ACL3,              /**< [GB.GG]ACL key include MAC , IPV4, MPLS */

    DRV_FTM_KEY_TYPE_ACL0_EGRESS,       /**< [GG]Egress ACL key include MAC , IPV4, IPV6, MPLS */

    DRV_FTM_KEY_TYPE_IPV4_MCAST,        /**< [GB]IPV4 mcast key*/
    DRV_FTM_KEY_TYPE_IPV6_MCAST,        /**< [GB]IPV6 mcast key*/

    DRV_FTM_KEY_TYPE_VLAN_SCL,          /**< [GB]SCL VLAN key*/
    DRV_FTM_KEY_TYPE_MAC_SCL,           /**< [GB]SCL MAC key*/
    DRV_FTM_KEY_TYPE_IPV4_SCL,          /**< [GB]SCL IPv4 key*/

    DRV_FTM_KEY_TYPE_IPV6_SCL,          /**< [GB]SCL IPv6 key*/

    DRV_FTM_KEY_TYPE_FDB,               /**< [GB]FDB key*/
    DRV_FTM_KEY_TYPE_IPV4_UCAST,        /**< [GB.GG]IPv4 Ucast key*/
    DRV_FTM_KEY_TYPE_IPV6_UCAST,        /**< [GB.GG]IPv6 Ucast key*/

    DRV_FTM_KEY_TYPE_IPV4_NAT,          /**< [GB.GG]IPv4 Nat key*/
    DRV_FTM_KEY_TYPE_IPV6_NAT,          /**< [GB.GG]IPv6 Nat key*/
    DRV_FTM_KEY_TYPE_IPV4_PBR,          /**< [GB.GG]IPv4 PBR key*/
    DRV_FTM_KEY_TYPE_IPV6_PBR,          /**< [GB.GG]IPv6 PBR key*/

    DRV_FTM_KEY_TYPE_IPV4_TUNNEL,       /**< [GB]IPv4 Tunnel key*/
    DRV_FTM_KEY_TYPE_IPV6_TUNNEL,       /**< [GB]IPv6 Tunnel key*/

    DRV_FTM_KEY_TYPE_MAX
};
typedef enum drv_ftm_key_type_e drv_ftm_key_type_t;


enum drv_ftm_tbl_type_e
{

    DRV_FTM_TBL_TYPE_LPM_PIPE0,     /**< [GB.GG] LPM PIPE0 table*/

    DRV_FTM_TBL_TYPE_NEXTHOP,       /**< [GB.GG] Nexthop table*/
    DRV_FTM_TBL_TYPE_FWD,           /**< [GB.GG] Fwd table*/
    DRV_FTM_TBL_TYPE_MET,           /**< [GB.GG] Met table*/
    DRV_FTM_TBL_TYPE_EDIT,          /**< [GB.GG] l2 and l3 edit table*/

    DRV_FTM_TBL_TYPE_OAM_MEP,       /**< [GB.GG] All OAM table*/

    DRV_FTM_TBL_TYPE_STATS,         /**< [GB.GG] statistics table*/
    DRV_FTM_TBL_TYPE_LM,            /**< [GB.GG] OAM LM statistics table*/
    DRV_FTM_TBL_TYPE_SCL_HASH_KEY,  /**< [GB.GG] SCL hash key table*/
    DRV_FTM_TBL_TYPE_SCL_HASH_AD,   /**< [GB.GG] SCL AD table*/

    DRV_FTM_TBL_TYPE_FIB_HASH_KEY,  /**< [GB] MAC, IP key table*/
    DRV_FTM_TBL_TYPE_LPM_HASH_KEY,  /**< [GB] LPM hash key table*/
    DRV_FTM_TBL_TYPE_FIB_HASH_AD,   /**< [GB] MAC, IP AD table*/
    DRV_FTM_TBL_TYPE_LPM_PIPE1,     /**< [GB] LPM PIPE1 table*/
    DRV_FTM_TBL_TYPE_LPM_PIPE2,     /**< [GB] LPM PIPE2 table*/
    DRV_FTM_TBL_TYPE_LPM_PIPE3,     /**< [GB] LPM PIPE3 table*/
    DRV_FTM_TBL_TYPE_MPLS,          /**< [GB] MPLS table*/

    DRV_FTM_TBL_FIB0_HASH_KEY,      /**< [GG] MAC, IPDA key table*/
    DRV_FTM_TBL_DSMAC_AD,           /**< [GG] MAC AD table*/
    DRV_FTM_TBL_FIB1_HASH_KEY,      /**< [GG] NAT, IPSA key table*/
    DRV_FTM_TBL_DSIP_AD,            /**< [GG] IP AD table*/

    DRV_FTM_TBL_XCOAM_HASH_KEY,     /**< [GG] OAM and Egress Vlan Xlate table*/
    DRV_FTM_TBL_FLOW_HASH_KEY,      /**< [GG] Flow hash key*/
    DRV_FTM_TBL_FLOW_AD,            /**< [GG] Flow Ad table*/
    DRV_FTM_TBL_IPFIX_HASH_KEY,     /**< [GG] IPFix hash key*/
    DRV_FTM_TBL_IPFIX_AD,           /**< [GG] IPFix AD table*/
    DRV_FTM_TBL_OAM_APS,            /**< [GG] APS table*/

    DRV_FTM_TBL_TYPE_MAX
};
typedef enum drv_ftm_tbl_type_e drv_ftm_tbl_type_t;


enum drv_ftm_cam_type_e
{
    DRV_FTM_CAM_TYPE_INVALID        = 0,
    DRV_FTM_CAM_TYPE_FIB_HOST0_FDB  = 1,
    DRV_FTM_CAM_TYPE_FIB_HOST0_MC   = 2,
    DRV_FTM_CAM_TYPE_FIB_HOST1_NAT  = 3,
    DRV_FTM_CAM_TYPE_FIB_HOST1_MC   = 4,
    DRV_FTM_CAM_TYPE_SCL            = 5,
    DRV_FTM_CAM_TYPE_DCN            = 6,
    DRV_FTM_CAM_TYPE_MPLS           = 7,
    DRV_FTM_CAM_TYPE_OAM            = 8,
    DRV_FTM_CAM_TYPE_XC             = 9,
    DRV_FTM_CAM_TYPE_MAX
};
typedef enum drv_ftm_cam_type_e drv_ftm_cam_type_t;



struct drv_ftm_tbl_info_s
{
    uint32  tbl_id;                             /**[GB]ctc_ftm_tbl_type_t*/
    uint32 mem_bitmap;                          /**[GB]Table allocation in which SRAM*/
    uint32 mem_start_offset[DRV_FTM_MEM_MAX];  /**[GB]Start Offset of SRAM*/
    uint32 mem_entry_num[DRV_FTM_MEM_MAX];     /**[GB]Entry number in SRAM*/
};
typedef struct drv_ftm_tbl_info_s drv_ftm_tbl_info_t;

/**
 @brief Profile key information
*/
struct drv_ftm_key_info_s
{
    uint8  key_size;                    /**< [HB.GB.GG]Value = {1,2,4,8}, indicates {80b,160b,320b,640b}. */
    uint32 max_key_index;               /**< [HB.GB]Key total number. key_max_index * key_size = consumed 80b tcam entry. */
    uint8  key_media;                   /**< [HB.GB]ctc_ftm_key_location_t*/
    uint8  key_id;                      /**< [HB.GB.GG]Key type*/

    uint32 tcam_bitmap;                         /**< [GG]Tcam Key tcam bitmap*/
    uint32 tcam_start_offset[DRV_FTM_MEM_MAX]; /**< [GG]Start Offset of TCAM*/
    uint32 tcam_entry_num[DRV_FTM_MEM_MAX];    /**< [GG]Entry number in TCAM*/
};
typedef struct drv_ftm_key_info_s drv_ftm_key_info_t;


struct drv_ftm_cam_s
{
    uint8 conflict_cam_num[DRV_FTM_CAM_TYPE_MAX];
};
typedef struct drv_ftm_cam_s drv_ftm_cam_t;


struct drv_ftm_profile_info_s
{
    drv_ftm_key_info_t* key_info;   /**< [HB.GB]Profile key information*/
    uint16 key_info_size;           /**< [HB.GB]Size of key_info, multiple of sizeof(ctc_ftm_key_info_t) */
    uint8 profile_type;             /**< [GB]Profile type, refer to ctc_ftm_profile_type_t*/
    uint8  resv;

    drv_ftm_tbl_info_t* tbl_info;               /**< [GB]table information  */
    uint16 tbl_info_size;                       /**< [GB]Size of tbl_info, multiple of sizeof(ctc_ftm_tbl_info_t) */

    drv_ftm_cam_t cam_info;
};
typedef struct drv_ftm_profile_info_s drv_ftm_profile_info_t;

enum drv_ftm_info_type_e
{
    DRV_FTM_INFO_TYPE_CAM,
    DRV_FTM_INFO_TYPE_TCAM,
    DRV_FTM_INFO_TYPE_EDRAM,
    DRV_FTM_INFO_TYPE_MAX,
};
typedef enum drv_ftm_info_type_e drv_ftm_info_type_t;

#define DRV_FTM_FTM_MAX_EDRAM_MEM_NUM       5
#define DRV_FTM_FTM_MAX_TCAM_TBL_NUM        5

struct drv_ftm_info_detail_s
{
    uint8 info_type;                /*< [GG]drv_ftm_info_type_t */
    uint8 tbl_type;                 /*< [GG]drv_ftm_key_type_t or drv_ftm_tbl_type_t or drv_ftm_cam_type_t*/
    uint8 tbl_entry_num;

    /*for edram*/
    uint8 mem_id[DRV_FTM_FTM_MAX_EDRAM_MEM_NUM];
    uint32 entry_num[DRV_FTM_FTM_MAX_EDRAM_MEM_NUM];
    uint32 offset[DRV_FTM_FTM_MAX_EDRAM_MEM_NUM];

    /*for tcam*/
    uint32 tbl_id[DRV_FTM_FTM_MAX_TCAM_TBL_NUM];
    uint32 key_size[DRV_FTM_FTM_MAX_TCAM_TBL_NUM];
    uint32 max_idx[DRV_FTM_FTM_MAX_TCAM_TBL_NUM];

    /* for cam */
    uint8 max_size;
    uint8 used_size;

    char str[32];
};
typedef struct drv_ftm_info_detail_s drv_ftm_info_detail_t;

extern int32
drv_ftm_lookup_ctl_init(uint8 lchip);

extern int32
drv_ftm_mem_alloc(void* profile_info);

extern int32
drv_ftm_get_lpm_tcam_info(uint32 tblid, uint32* p_entry_offset, uint32* p_entry_num, uint32* p_entry_size);

extern int32
drv_ftm_alloc_cam_offset(uint32 tbl_id, uint32 *offset);
extern int32
drv_ftm_free_cam_offset(uint32 tbl_id, uint32 offset);

extern int32
drv_ftm_get_info_detail(drv_ftm_info_detail_t* p_ftm_info);

extern int32
drv_goldengate_ftm_check_tbl_recover(uint8 mem_id, uint32 ram_offset, uint8* p_recover, uint32* p_tblid);

#ifdef __cplusplus
}
#endif

#endif

