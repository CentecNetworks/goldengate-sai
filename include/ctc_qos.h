
/**
   This file contains all acl related data structure, enum, macro and proto.
*/

#ifndef _CTC_QOS_H_
#define _CTC_QOS_H_

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

#define CTC_MAX_QUEUE_CLASS_NUM     4
#define CTC_RESC_DROP_PREC_NUM      4
#define CTC_DROP_PREC_NUM           4
#define CTC_RESRC_MAX_CONGEST_LEVEL_NUM             8
#define CTC_RESRC_MAX_CONGEST_LEVEL_THRD_NUM        7

#define CTC_QOS_SHP_TOKE_THRD_DEFAULT 0xFFFFFFFF
/**
 @defgroup qos QOS
 @{
*/

/**
 @brief QoS color
*/
enum ctc_qos_color_e
{
    CTC_QOS_COLOR_NONE,     /**< [HB.GB.GG] None color */
    CTC_QOS_COLOR_RED,      /**< [HB.GB.GG] Red color: the lowest drop precedence */
    CTC_QOS_COLOR_YELLOW,   /**< [HB.GB.GG] Yellow color: the mild drop precedence */
    CTC_QOS_COLOR_GREEN,    /**< [HB.GB.GG] Green color: the highest drop precedence */

    MAX_CTC_QOS_COLOR
};
typedef enum ctc_qos_color_e ctc_qos_color_t;

/**
 @brief qos trust type
*/
enum ctc_qos_trust_type_e
{
    CTC_QOS_TRUST_PORT        = 0,       /**< [HB.GB.GG] trust Port */
    CTC_QOS_TRUST_OUTER       = 1,       /**< [HB.GB.GG] copy outer */
    CTC_QOS_TRUST_COS         = 2,       /**< [HB.GB.GG] trust COS */
    CTC_QOS_TRUST_DSCP        = 3,       /**< [HB.GB.GG] trust DSCP */
    CTC_QOS_TRUST_IP          = 4,       /**< [HB.GB.GG] trust IP Precedence */
    CTC_QOS_TRUST_STAG_COS    = 5,       /**< [GB.GG] trust stag-cos */
    CTC_QOS_TRUST_CTAG_COS    = 6,       /**< [GB.GG] trust ctag-cos */
    CTC_QOS_TRUST_MAX
};
typedef enum ctc_qos_trust_type_e ctc_qos_trust_type_t;

/**
 @brief Qos domain mapping type
*/
enum ctc_qos_domain_map_type_e
{
    CTC_QOS_DOMAIN_MAP_IGS_COS_TO_PRI_COLOR,      /**< [HB.GB.GG] Mapping ingress cos +  dei to priority + color */
    CTC_QOS_DOMAIN_MAP_IGS_DSCP_TO_PRI_COLOR,     /**< [HB.GB.GG] Mapping ingress dscp + ecn to priority + color */
    CTC_QOS_DOMAIN_MAP_IGS_IP_PREC_TO_PRI_COLOR,  /**< [HB.GB.GG] Mapping ingress ip-precedence to priority + color */
    CTC_QOS_DOMAIN_MAP_IGS_EXP_TO_PRI_COLOR,      /**< [HB.GB.GG] Mapping ingress exp to priority + color */
    CTC_QOS_DOMAIN_MAP_EGS_PRI_COLOR_TO_COS,      /**< [HB.GB.GG] Mapping egress  priority + color to cos + cfi*/
    CTC_QOS_DOMAIN_MAP_EGS_PRI_COLOR_TO_DSCP,     /**< [HB.GB.GG] Mapping egress  priority + color to dscp*/
    CTC_QOS_DOMAIN_MAP_EGS_PRI_COLOR_TO_EXP,      /**< [HB.GB.GG] Mapping egress  priority + color to exp*/
    CTC_QOS_DOMAIN_MAP_TYPE_MAX
};
typedef enum ctc_qos_domain_map_type_e ctc_qos_domain_map_type_t;

/**
 @brief Qos domain mapping type
*/
struct ctc_qos_domain_map_s
{
    uint8    domain_id;      /**< [HB.GB.GG] Domain id <0-7>, apply on port*/
    uint8    type;           /**< [HB.GB.GG] Domain mapping type, pls refer to ctc_qos_domain_map_type_t*/

    uint8    priority;       /**< [HB.GB.GG] Qos priorty <0-63>*/
    uint8    color;          /**< [HB.GB.GG] Qos color, pls refer to ctc_qos_color_t*/

    union
    {
        struct
        {
            uint8    cos;   /**< [HB.GB.GG] Vlan id cos <0-7>*/
            uint8    dei;   /**< [HB.GB.GG] Vlan id dei <0-1>*/
        } dot1p;

        struct
        {
            uint8    dscp; /**< [HB.GB.GG] Ip dscp <0-63>*/
            uint8    ecn;  /**< [GB.GG]     Ip ecn <0-3>*/
        } tos;

        uint8    exp;      /**< [HB.GB.GG] Mpls exp <0-3>*/
        uint8    ip_prec;  /**< [HB.GB.GG] Ip precedence <0-7>*/

    } hdr_pri;

};
typedef struct ctc_qos_domain_map_s ctc_qos_domain_map_t;

/**
 @brief Qos policer type
*/
enum ctc_qos_policer_type_e
{
    CTC_QOS_POLICER_TYPE_PORT,           /**< [HB.GB.GG] Port policer (support ing and egs) */
    CTC_QOS_POLICER_TYPE_FLOW,           /**< [HB.GB.GG] Flow policer (support ing and egs)*/
    CTC_QOS_POLICER_TYPE_SERVICE,        /**< [HB.GB.GG] Service policer (only support ingress) */
    CTC_QOS_POLICER_TYPE_MAX
};
typedef enum ctc_qos_policer_type_e ctc_qos_policer_type_t;

/**
 @brief Qos policer type
*/
enum ctc_qos_policer_mode_e
{
    CTC_QOS_POLICER_MODE_RFC2697,    /**< [HB.GB.GG] RFC2697 srTCM */
    CTC_QOS_POLICER_MODE_RFC2698,    /**< [HB.GB.GG] RFC2698 trTCM */
    CTC_QOS_POLICER_MODE_RFC4115,    /**< [GB.GG]    RFC4115 mode enhanced trTCM*/
    CTC_QOS_POLICER_MODE_MEF_BWP,    /**< [GB.GG]    MEF BWP(bandwidth profile) */
    CTC_QOS_POLICER_MODE_MAX
};
typedef enum ctc_qos_policer_mode_e ctc_qos_policer_mode_t;

/**
 @brief Qos policer parameter
*/
struct ctc_qos_policer_param_s
{
    uint8  policer_mode;    /**< [GB.GG] policer mode refer to ctc_qos_policer_mode_t*/
    uint8  is_srtcm;        /**< [HB.GB.GG]  Is_srtcm = 1 for RFC2697 SrTCM (Single-rate Three Color Marking),
                                                              Is_srtcm = 0 for RFC2698 TrTCM (Two-rate Three Color Marking) */

    uint8  cf_en;           /**< [GB.GG]  Only for MEF BWP, couple flag enable*/
    uint8  rsv;

    uint8  is_color_aware;  /**< [HB.GB.GG]  is_color_aware = 1 for is_color_aware, is_color_aware = 0 for Color-blind mode */
    uint8  use_l3_length;   /**< [HB.GB.GG]  Use packet length from layer 3 header for metering */
    uint8  stats_en;        /**< [HB.GB.GG]  enable policer stats for three color */
    uint8  drop_color;      /**< [HB.GB.GG]  the drop color after policing  */


    uint32 cir;  /**< [HB.GB.GG]  Committed Information Rate (unit :kbps)*/
    uint32 cbs;  /**< [HB.GB.GG]  Committed Burst Size, equivalent to the C-bucket size (unit :kb)*/

    uint32 pir;  /**< [HB.GB.GG]   PIR(RFC2698) or EIR(RFC4115,BWP) (unit :kbps)*/
    uint32 pbs;  /**< [HB.GB.GG]   PBS(RFC2698,)or EBS (RFC2697, RFC4115,BWP)(unit :kb)*/
};
typedef struct ctc_qos_policer_param_s ctc_qos_policer_param_t;

/**
 @brief Qos policer Hierarchical Bandwidth Profile.
   1.1, when bwp is applied to MEF10.3,the relationship between the cos index
        and the cos level is as follows :
         Cos level    Cos index
        -------------------------
          3            1
          2            2
          1            3
        ------------------------
   1.2, when bwp is applied to triple_play mode,the cos index =0 is total policer
        service;
*/
struct ctc_qos_policer_hbwp_s
{
    uint8  cos_index;     /**< [GB.GG] Cos Level,support up to 4 cos level */
    uint8  sf_en;         /**< [GB.GG] Share flag enable*/
    uint8  triple_play;   /**< [GG] if set, cos_index = 0 regard as total policer */
    uint8  rsv;

    uint8  sp_en;         /**< [GB] Strict schedule enable*/
    uint8  cf_total_dis;  /**< [GB.GG] Coupling total disable */
    uint16 weight;        /**< [GB] Weight value<0-0x3FF>, only support cos 1 weight, cos 0 is (0x3FF - Weight)*/

    uint32 cir_max;      /**< [GB.GG] Max Cir rate,(unit:kbps)*/
    uint32 pir_max;      /**< [GB.GG] Max Eir rate,(unit:kbps)*/
};
typedef struct ctc_qos_policer_hbwp_s ctc_qos_policer_hbwp_t;

/**
 @brief Qos policer data structure
*/
struct ctc_qos_policer_s
{
    uint8  type;    /**< [HB.GB.GG]  Policer type, refer to ctc_qos_policer_type_t*/
    uint8  dir;     /**< [HB.GB.GG]  Ingress or egress , refer to ctc_direction_t, only for Port policer */
    uint8  enable;  /**< [HB.GB.GG]  Policer enable or disable*/
    uint8  hbwp_en; /**< [GB.GG]     MEF BWP enable or disable*/
    union
    {
        uint16 policer_id;      /**< [HB.GB.GG]  Flow policer and HBWP id <1-0xFFFF>*/
        uint16 service_id;      /**< [HB.GB]  Service ID <1-0xFFFF>*/
        uint32 gport;           /**< [HB.GB.GG]  Global port*/
    } id;

    ctc_qos_policer_hbwp_t hbwp;       /**< [GB.GG]   MEF Bandwidth Profile*/
    ctc_qos_policer_param_t policer;   /**< [HB.GB.GG] Policer parameter info*/

};
typedef struct ctc_qos_policer_s ctc_qos_policer_t;

/**
 @brief Qos policer stats info
*/
struct ctc_qos_policer_stats_info_s
{
    uint64 confirm_pkts;        /**< [HB.GB.GG] Total number of packets with color green*/
    uint64 confirm_bytes;       /**< [HB.GB.GG] Total bytes of packets with color green*/
    uint64 exceed_pkts;         /**< [HB.GB.GG] Total number of packets with color yellow*/
    uint64 exceed_bytes;        /**< [HB.GB.GG] Total bytes of packets with color yellow*/
    uint64 violate_pkts;        /**< [HB.GB.GG] Total number of packets with color red*/
    uint64 violate_bytes;       /**< [HB.GB.GG] Total bytes of packets with color red*/
};
typedef struct ctc_qos_policer_stats_info_s ctc_qos_policer_stats_info_t;

/**
 @brief Qos policer stats structure
*/
struct ctc_qos_policer_stats_s
{
    uint8 type;         /**< [HB.GB.GG]ctc_qos_policer_type_t*/
    uint8 dir;          /**< [HB.GB.GG]ctc_direction_t */
    uint8 hbwp_en;      /**< [GB.GG] MEF BWP enable or disable*/
    uint8 cos_index;    /**< [GB.GG] Cos Level,support up to 4 cos level */

    union
    {
        uint16 policer_id;      /**< [HB.GB.GG] Flow policer and BWP id <00xFFFF> */
        uint16 service_id;      /**< [HB.GB] Service ID <0xFFFF> */
        uint32 gport;           /**< [HB.GB.GG] Global port*/
    } id;
	ctc_qos_policer_stats_info_t stats; /**< [HB.GB.GG] Stats paramete*/

};
typedef struct ctc_qos_policer_stats_s ctc_qos_policer_stats_t;



/**
 @brief Qos global configure type
*/
enum ctc_qos_glb_cfg_type_e
{
    CTC_QOS_GLB_CFG_POLICER_EN,             /**< [HB.GB.GG] Global polcier update enable*/
    CTC_QOS_GLB_CFG_POLICER_STATS_EN,       /**< [HB.GB.GG] Global polcier statst enable*/
    CTC_QOS_GLB_CFG_POLICER_IPG_EN,         /**< [HB.GB.GG] Global polcier ipg enable*/
    CTC_QOS_GLB_CFG_POLICER_SEQENCE_EN,     /**< [HB.GB.GG] Global polcier port and flow sequential enable*/
    CTC_QOS_GLB_CFG_POLICER_FLOW_FIRST_EN,  /**< [HB.GB.GG] Global polcier port and flow plicer priority,
                                                         high 16 bit is dir, low 16bit is enable value*/

    CTC_QOS_GLB_CFG_RESRC_MGR_EN,           /**< [HB.GB.GG] Global resource manger enable */
    CTC_QOS_GLB_CFG_QUE_SHAPE_EN,           /**< [HB.GB.GG] Global queue shaping enable*/
    CTC_QOS_GLB_CFG_GROUP_SHAPE_EN,         /**< [HB.GB.GG] Global group shaping enable*/
    CTC_QOS_GLB_CFG_PORT_SHAPE_EN,          /**< [HB.GB.GG] Global port shaping  enable*/
    CTC_QOS_GLB_CFG_SHAPE_IPG_EN,           /**< [GB.GG]    Global queue shaping ipg enable*/
    CTC_QOS_GLB_CFG_SHAPE_IPG_SIZE,         /**< [HB]    Global queue shaping ipg size*/
    CTC_QOS_GLB_CFG_QUE_STATS_EN,           /**< [HB]    Global queue stats enable*/
    CTC_QOS_GLB_CFG_PHB_MAP,                /**< [GB.GG]    Priority mapped to phb*/
    CTC_QOS_GLB_CFG_REASON_SHAPE_PKT_EN,    /**< [GB.GG] Cpu Reason shape base on packet*/
    CTC_QOS_GLB_CFG_POLICER_HBWP_SHARE_EN,  /**< [GB]    HBWP using global share mode*/
    CTC_QOS_GLB_CFG_MONITOR_DROP_QID,       /**< [GG]    Queue ID for monitoring Queue Drop*/
    CTC_QOS_GLB_CFG_TRUNCATION_LEN,         /**< [GG]  The length for packet truncation.*/
    CTC_QOS_GLB_CFG_POLICER_MARK_ECN_EN,    /**< [GG]  TCP ECN field will be mark when do policer*/
    CTC_QOS_GLB_CFG_SCH_WRR_EN,             /**< [GG]  Schedule WRR mode enable*/

    CTC_QOS_GLB_CFG_MAX
};
typedef enum ctc_qos_glb_cfg_type_e ctc_qos_glb_cfg_type_t;

/**
 @brief Qos Phb map type
*/
enum ctc_qos_phb_map_type_e
{
   CTC_QOS_PHB_MAP_PRI,      /**< [GB.GG] Map priority to phb*/
   CTC_QOS_PHB_MAP_MAX
};
typedef enum ctc_qos_phb_map_type_e ctc_qos_phb_map_type_t;


struct ctc_qos_phb_map_s
{
    uint8 map_type;      /**< [GB.GG] Map type, refer to ctc_qos_phb_map_type_t*/
    uint8 priority;      /**< [GB.GG] Qos priorty <0-63>*/
    uint8 cos_index;     /**< [GB.GG] Regard as cos index */
};
typedef struct ctc_qos_phb_map_s ctc_qos_phb_map_t;


struct ctc_qos_queue_id_s
{
    uint8  queue_type; /**< [HB.GB.GG] Queue type, refer to ctc_queue_type_t*/
    uint16 queue_id;   /**< [HB.GB.GG] Queue id */

    uint32 gport;      /**< [HB.GB.GG] Global port*/
    uint16 service_id; /**< [HB.GB] Service identifaication*/
    uint16 cpu_reason; /**< [HB.GB.GG] Cpu reason*/

};
typedef struct ctc_qos_queue_id_s ctc_qos_queue_id_t;

/**
 @brief Qos global configure
*/
struct ctc_qos_glb_cfg_s
{
    uint16 cfg_type;                 /**< [GB.GG] Configre type, refer to ctc_qos_glb_cfg_type_t*/
    union
    {
        uint32 value;                /**< [GB.GG] Configre value*/
        ctc_qos_phb_map_t phb_map;   /**< [GB.GG] Phb mapping configure*/
		ctc_qos_queue_id_t queue_id; /**< [GB.GG] Phb mapping configure*/
    } u;
};
typedef struct ctc_qos_glb_cfg_s ctc_qos_glb_cfg_t;

/**
 @brief Qos drop mode
*/
enum ctc_queue_drop_mode_s
{
    CTC_QUEUE_DROP_WTD,     /**< [HB.GB.GG] WTD drop mode */
    CTC_QUEUE_DROP_WRED,    /**< [HB.GB.GG] WRED drop mode */

    MAX_CTC_QUEUE_DROP
};
typedef enum ctc_queue_drop_mode_s ctc_queue_drop_mode_t;

/**
 @brief Qos queue drop
*/
struct ctc_qos_queue_drop_s
{
    ctc_queue_drop_mode_t mode;          /**< [HB.GB.GG] Queue Drop Mode, type of CTC_QUEUE_DROP_XXX */

    uint16 min_th[CTC_DROP_PREC_NUM];    /**< [HB.GB] WRED min threshold */
    uint16 max_th[CTC_DROP_PREC_NUM];    /**< [HB.GB.GG] WRED max threshold, or WTD drop threshold */
    uint16 drop_prob[CTC_DROP_PREC_NUM]; /**< [HB.GB.GG] WRED max drop probability */
    uint8  weight;                       /**< [HB]    WRED weight */
    uint8  rsv;
    uint16 ecn_mark_th;                  /**< [GG] If ecn_mark_th equal 0, ecn mark disable. else mean queue ecn mark threshold.
                                                  ecn_mark_th should less than max_th*/
};
typedef struct ctc_qos_queue_drop_s ctc_qos_queue_drop_t;




/**
 @brief Qos queue drop data structure
*/
struct ctc_qos_drop_s
{
    ctc_qos_queue_id_t queue;   /**< [HB.GB.GG] Generate queue id information*/
    ctc_qos_queue_drop_t drop;  /**< [HB.GB.GG] Drop info, refer to ctc_qos_queue_drop_t*/
};
typedef struct ctc_qos_drop_s ctc_qos_drop_t;

/**
 @brief Qos queue stats info
*/
struct ctc_qos_queue_stats_info_s
{
    uint64 deq_packets;     /**< [HB.GB.GG] De-queue packet number */
    uint64 deq_bytes;       /**< [HB.GB.GG] De-queue packet bytes */
    uint64 drop_packets;    /**< [HB.GB.GG] Dropped packet number */
    uint64 drop_bytes;      /**< [HB.GB.GG] Dropped packet bytes */
};
typedef struct ctc_qos_queue_stats_info_s ctc_qos_queue_stats_info_t;

/**
 @brief Qos queue stats data structure
*/
struct ctc_qos_queue_stats_s
{
    ctc_qos_queue_id_t queue;   /**< [HB.GB.GG] Generate queue id information*/

    uint8 stats_en;             /**< [GB.GG] Note: HB only support enable all queue stats globally*/

    ctc_qos_queue_stats_info_t stats;   /**< [HB.GB.GG] */

};
typedef struct ctc_qos_queue_stats_s ctc_qos_queue_stats_t;


/**
 @brief Qos queue packet len adjust data structure
*/
struct ctc_qos_queue_pkt_adjust_s
{
    ctc_qos_queue_id_t queue;     /**< [HB.GB.GG] Generate queue id information*/
    uint8 adjust_len;             /**< [GB.GG] packet length adjust for shaping,
                                               if MSB set, mean minus packet length */
};
typedef struct ctc_qos_queue_pkt_adjust_s ctc_qos_queue_pkt_adjust_t;

/**
 @brief Qos queue type
*/
enum ctc_queue_type_e
{
    CTC_QUEUE_TYPE_SERVICE_INGRESS,     /**< [HB.GB] Ingress service queue */
    CTC_QUEUE_TYPE_NETWORK_EGRESS,      /**< [HB.GB.GG] Egress network queue */
    CTC_QUEUE_TYPE_SERVICE_EGRESS,      /**< [HB.GB] Egress service queue */
    CTC_QUEUE_TYPE_ILOOP,               /**< [HB.GB.GG] Ingress loopback queue */
    CTC_QUEUE_TYPE_NORMAL_CPU,          /**< [HB.GB] Normal CPU queue */
    CTC_QUEUE_TYPE_OAM,                 /**< [HB.GB.GG] OAM queue */
    CTC_QUEUE_TYPE_ELOOP,               /**< [HB.GB.GG] Egress loopback queue */
    CTC_QUEUE_TYPE_STATIC_INT_PORT,     /**< [HB]    Static internal port queue */
    CTC_QUEUE_TYPE_EXCP_CPU,            /**< [HB.GB.GG] Exception CPU queue */
    CTC_QUEUE_TYPE_FABRIC,              /**< [HB]    Fabric queue */
    CTC_QUEUE_TYPE_INTERNAL_PORT,       /**< [HB.GB.GG] Internal port queue */
    CTC_QUEUE_TYPE_SGMAC_PORT_TO_CPU,   /**< [HB]    Sgmac port to cpu queue*/
    CTC_QUEUE_TYPE_SGMAC_CPU_TO_CPU,    /**< [HB]    Sgmac cpu to cpu queue*/

    MAX_CTC_QUEUE_TYPE
};
typedef enum ctc_queue_type_e ctc_queue_type_t;

/**
 @brief Qos queue configure type
*/
enum ctc_qos_queue_cfg_type_e
{
    CTC_QOS_QUEUE_CFG_SERVICE_BIND,             /**< [HB.GB] Service bind information*/
    CTC_QOS_QUEUE_CFG_PRI_MAP,                  /**< [GB.GG]    Priority to queue select configure*/
    CTC_QOS_QUEUE_CFG_QUEUE_NUM,                /**< [GB]    Queue number set for normal queue*/
    CTC_QOS_QUEUE_CFG_QUEUE_REASON_MAP,         /**< [GB.GG]    Cpu reason mapping queue*/
    CTC_QOS_QUEUE_CFG_QUEUE_REASON_DEST,        /**< [GB.GG]    Cpu reason set destination*/
    CTC_QOS_QUEUE_CFG_QUEUE_REASON_PRIORITY,    /**< [GB]       Cpu reason set priority*/
    CTC_QOS_QUEUE_CFG_QUEUE_REASON_MODE,        /**< [GB]       Cpu reason set mode DMA/ETH to cpu*/
    CTC_QOS_QUEUE_CFG_QUEUE_REASON_MISC,        /**< [GG]      Set Cpu reason paramer*/
    CTC_QOS_QUEUE_CFG_QUEUE_STATS_EN,           /**< [GB.GG]    Queue stats enale configure*/
    CTC_QOS_QUEUE_CFG_SCHED_WDRR_MTU,           /**< [HB.GB.GG] Schedule wdrr mtu size configure*/
    CTC_QOS_QUEUE_CFG_QUEUE_SIZE_MODE,          /**< [HB]    1 -- buffer_cnt, 0 -- packet*/
    CTC_QOS_QUEUE_CFG_LENGTH_ADJUST,            /**< [HB.GB.GG]    Adjust length for shaping, the length can be negative*/
    CTC_QOS_QUEUE_CFG_MAX
};
typedef enum ctc_qos_queue_cfg_type_e ctc_qos_queue_cfg_type_t;

/**
 @brief Qos service id flag
*/
enum ctc_qos_service_id_flag_s
{
    CTC_QOS_SERVICE_ID_WITH_QUEUE         = 1 << 0, /**< [HB.GB] Need bind queue */
    CTC_QOS_SERVICE_ID_WITH_POLICER       = 1 << 1, /**< [HB.GB] Need bind policer */
    CTC_QOS_SERVICE_ID_WITH_POLICER_STATS = 1 << 2, /**< [HB.GB] Need assign policer stats */
    MAX_CTC_QOS_SERVICE_ID_FLAG
};
typedef enum ctc_qos_service_id_flag_s ctc_qos_service_id_flag_t;

/**
 @brief Qos service id opcode
*/
enum ctc_qos_service_id_opcode_s
{
    CTC_QOS_SERVICE_ID_CREATE                   = 0, /**< [HB.GB] Create service id with queue */
    CTC_QOS_SERVICE_ID_DESTROY                  = 1, /**< [HB.GB] Destroy service id */
    CTC_QOS_SERVICE_ID_BIND_DESTPORT            = 3, /**< [HB.GB] Service id binding with queue */
    CTC_QOS_SERVICE_ID_UNBIND_DESTPORT          = 4, /**< [HB.GB] Service id unbinding with queue */
    MAX_CTC_QOS_SERVICE_ID_OPCODE
};
typedef enum ctc_qos_service_id_opcode_s ctc_qos_service_id_opcode_t;

/**
 @brief Qos service information
*/
struct ctc_qos_service_info_s
{
    uint16 flag;        /**< [HB.GB] ctc_qos_queue_cfg_type_t */
    uint8  opcode;      /**< [HB.GB] ctc_qos_service_id_opcode_t */
    uint16 service_id;  /**< [HB.GB] Service identifciation*/
    uint32 gport;       /**< [HB.GB] Service bind port*/
};
typedef struct ctc_qos_service_info_s ctc_qos_service_info_t;

/**
 @brief Qos priority maping
*/
struct ctc_qos_pri_map_s
{
    uint8 priority;             /**< [HB.GB.GG] priority <0-63> */
    uint8 color;                /**< [HB.GB.GG] color 1-red 2-yellow 3-green */
    uint8 queue_select;         /**< [HB.GB.GG] mapped queue select <0-63> */
    uint8 drop_precedence;      /**< [HB.GB.GG] mapped drop precedence <0-3> */
};
typedef struct ctc_qos_pri_map_s ctc_qos_pri_map_t;

/**
 @brief Qos queue number
*/
struct ctc_qos_queue_number_s
{
    uint8 queue_type;   /**< [GB] Queue type, refer to ctc_queue_type_t*/
    uint8 queue_number; /**< [GB] Queue number binding*/

};
typedef struct ctc_qos_queue_number_s ctc_qos_queue_number_t;

/**
 @brief Qos reason queue map when cpu reason 's destination is local cpu
*/
struct ctc_qos_queue_cpu_reason_map_s
{
    uint16 cpu_reason;     /**< [HB.GB.GG] Cpu reason type, refer to ctc_pkt_cpu_reason_t*/
    uint8 reason_group;   /**< [HB.GB.GG] Cpu reason group */
    uint8 queue_id;       /**< [HB.GB.GG] Cpu reason queue id*/
};
typedef struct ctc_qos_queue_cpu_reason_map_s ctc_qos_queue_cpu_reason_map_t;

/**
 @brief Qos reason queue destination
*/
struct ctc_qos_queue_cpu_reason_dest_s
{
    uint16  cpu_reason;   /**< [HB.GB.GG] Cpu reason type, refer to ctc_pkt_cpu_reason_t*/
    uint8  dest_type;    /**< [HB.GB.GG] Cpu reason type, refer to ctc_pkt_cpu_reason_dest_t*/
    uint32 dest_port;    /**< [GB.GG] Cpu macda index <0-3> if dest_type is CTC_PKT_CPU_REASON_TO_LOCAL_CPU,
                                  remote cpu port if dest_type is CTC_PKT_CPU_REASON_TO_REMOTE_CPU */
	uint32 nhid;        /**< [GB.GG] nhid if dest_type is CTC_PKT_CPU_REASON_TO_NHID */
};
typedef struct ctc_qos_queue_cpu_reason_dest_s ctc_qos_queue_cpu_reason_dest_t;

/**
 @brief Qos reason priority
*/
struct ctc_qos_queue_cpu_reason_priority_s
{
    uint16 cpu_reason;     /**< [GB] Cpu reason type, refer to ctc_pkt_cpu_reason_t */
    uint8 cos;            /**< [GB] Cpu reason cos, will mapping to channel ID for DMA, or cos in CPUMAC header */
    uint8 rsv[1];
};
typedef struct ctc_qos_queue_cpu_reason_priority_s ctc_qos_queue_cpu_reason_priority_t;

/**
 @brief Qos reason
*/
struct ctc_qos_group_cpu_reason_mode_s
{
    uint8 group_type;       /**< [GB]  Cpu reason group type, refer to ctc_pkt_cpu_reason_group_type_t */
    uint8 group_id;         /**< [GB]  Cpu reason group <0-15>, valid if group_type is CTC_PKT_CPU_REASON_GROUP_EXCEPTION */
    uint8 mode;             /**< [GB]  The mode for packet to cpu, refer to ctc_pkt_mode_t */
    uint8 rsv;
};
typedef struct ctc_qos_group_cpu_reason_mode_s ctc_qos_group_cpu_reason_mode_t;


/**
 @brief Qos reason
*/
struct ctc_qos_group_cpu_reason_misc_s
{
    uint16 cpu_reason;       /**< [HB.GB.GG] Cpu reason type, refer to ctc_pkt_cpu_reason_t */
    uint8 truncation_en;     /**<  [GG]       Packet will be truncated,and the truncation length refer to CTC_QOS_GLB_CFG_TRUNCATION_LEN  */
    uint8 rsv[2];
};
typedef struct ctc_qos_group_cpu_reason_misc_s ctc_qos_group_cpu_reason_misc_t;

/**
 @brief Qos queue configure
*/
struct ctc_qos_queue_cfg_s
{
    uint8 type; /**< [HB.GB.GG] Queue configure type, refer to ctc_qos_queue_cfg_type_t*/
    uint8 rsv[3];
    union
    {
        ctc_qos_service_info_t srv_queue_info;  /**< [HB.GB] Service queue info*/
        ctc_qos_pri_map_t  pri_map;             /**< [HB.GB.GG] Priority to queue maping*/
        ctc_qos_queue_number_t queue_num;       /**< [GB]    Queue number config*/
        ctc_qos_queue_cpu_reason_map_t reason_map;   /**< [GB.GG]    Cpu reason mapping queue*/
        ctc_qos_queue_cpu_reason_dest_t reason_dest; /**< [GB.GG]    Cpu reason set destination*/
        ctc_qos_queue_cpu_reason_priority_t reason_pri; /**< [GB]    Cpu reason set priority*/
        ctc_qos_group_cpu_reason_mode_t     reason_mode; /**< [GB]    Cpu reason set mode DMA/ETH*/
		ctc_qos_group_cpu_reason_misc_t    reason_misc;  /**< [GG]    cpu reason paramer */
        ctc_qos_queue_stats_t stats;            /**< [GB.GG]    Queue stats enable */
        ctc_qos_queue_pkt_adjust_t pkt;         /**< [GB.GG]    Ajdust the packet length which equalize the shaping rate*/
        uint32 value_32;                        /**< [HB.GB.GG] Uint32 value according to ctc_qos_queue_cfg_type_t */
    } value;
};
typedef struct ctc_qos_queue_cfg_s ctc_qos_queue_cfg_t;

/**
 @brief Qos shape type
*/
enum ctc_qos_shape_type_e
{
    CTC_QOS_SHAPE_PORT,   /**< [HB.GB.GG] Port shaping*/
    CTC_QOS_SHAPE_QUEUE,  /**< [HB.GB.GG] Queue shaping*/
    CTC_QOS_SHAPE_GROUP,  /**< [HB.GB.GG] Group shaping*/
    CTC_QOS_SHAPE_MAX
};
typedef enum ctc_qos_shape_type_e ctc_qos_shape_type_t;

/**
 @brief Qos queue shape
*/
struct ctc_qos_shape_queue_s
{
    ctc_qos_queue_id_t queue; /**< [HB.GB.GG] Generate queue id
                                 information*/

    uint8  enable;            /**< [HB.GB.GG] Queue shaping enable*/
    uint8  rsv0[3];

    uint32  pir;              /**< [HB.GB.GG] Max rate,
                                 Peak Information Rate (unit :kbps)
                                 or packet/s for cpu reason
                                 if CTC_QOS_GLB_CFG_REASON_SHAPE_PKT_EN*/
    uint32  pbs;             /**< [HB.GB] Peak Burst Size, (unit :kbps),
                                if set CTC_QOS_SHP_TOKE_THRD_DEFAULT,
                                default value will be set */

    uint32  cir;  /**< [HB.GB.GG]  Committed Information Rate (unit :kbps)*/
    uint32  cbs;  /**< [HB.GB]  Committed Burst Size, (unit:kb),
                        if set CTC_QOS_SHP_TOKE_THRD_DEFAULT,
                        default value will be set */

};
typedef struct ctc_qos_shape_queue_s ctc_qos_shape_queue_t;

/**
 @brief Qos group shape
*/
struct ctc_qos_shape_group_s
{
    uint16 service_id;      /**< [HB.GB]  Service identifaication*/
    uint32 gport;           /**< [HB]     Dest Port*/
	ctc_qos_queue_id_t queue;   /**<[GG] Generate queue id information*/

    uint8  group_type;      /*[HB.GB]group type, refer to
                                  ctc_qos_sched_group_type_t*/
    uint8  dir;             /**< [HB]      Direction, refer to ctc_direction_t */
    uint8  enable;          /**< [HB.GB.GG]  Group shaping enable*/

    uint32  pir;            /**< [HB.GB.GG] group shaping commit rate,(unit:kbps)*/
    uint32  pbs;            /**< [HB.GB] group shaping bucket size,(unit:kb),
                                  if set CTC_QOS_SHP_TOKE_THRD_DEFAULT,
                                  default value will be set*/
};
typedef struct ctc_qos_shape_group_s ctc_qos_shape_group_t;

/**
 @brief Qos port shape
*/
struct ctc_qos_shape_port_s
{
    uint32 gport;       /**< [HB.GB.GG] Global port*/
    uint8  enable;      /**< [HB.GB.GG] Port shaping enable*/
    uint8  sub_dest_id; /**< [GG] only valid for local cpu port, range <0-3> */

    uint32  pir;       /**< [HB.GB.GG] Peak Information Rate,
                            (unit:kbps)*/
    uint32  pbs;       /**< [HB.GB]  Peak Burst Size,(unit:kb),
                         if set CTC_QOS_SHP_TOKE_THRD_DEFAULT,
                         default value will be set */

    uint32  ecn_mark_rate; /*[GG] ECN will be marked when output port rate reach ecn_mark_rate, (unit :kbps)*/

};
typedef struct ctc_qos_shape_port_s ctc_qos_shape_port_t;

/**
 @brief Qos shape data structure
*/
struct ctc_qos_shape_s
{
    uint8 type;        /**< [HB.GB.GG] Shaping type, refer to ctc_qos_shape_type_t*/
    uint8 rsv0[3];

    union
    {
        ctc_qos_shape_queue_t queue_shape; /**< [HB.GB.GG] Queue shaping*/
        ctc_qos_shape_group_t group_shape; /**< [HB.GB.GG] Group shaping*/
        ctc_qos_shape_port_t port_shape;   /**< [HB.GB.GG] Port shaping*/
    } shape;
};
typedef struct ctc_qos_shape_s ctc_qos_shape_t;

/**
 @brief Qos schedule type
*/
enum ctc_qos_sched_type_e
{
    CTC_QOS_SCHED_QUEUE,        /**< [HB.GB.GG] Queue level schedule*/
    CTC_QOS_SCHED_GROUP,        /**< [GB.GG]    Group level schedule*/
    CTC_QOS_SCHED_SUB_GROUP,    /**< [GB]       Sub Group level schedule*/
    CTC_QOS_SCHED_MAX
};
typedef enum ctc_qos_sched_type_e ctc_qos_sched_type_t;

/**
 @brief Qos schedule group type
*/
enum ctc_qos_sched_group_type_e
{
    CTC_QOS_SCHED_GROUP_PORT,       /**< [GB] Schedule is port group*/
    CTC_QOS_SCHED_GROUP_SERVICE,    /**< [GB] Schedule is service group*/
    CTC_QOS_SCHED_GROUP_MAX
};
typedef enum ctc_qos_sched_group_type_e ctc_qos_sched_group_type_t;

/**
 @brief Qos schedule configure type
*/
enum ctc_qos_sched_cfg_type_e
{
    CTC_QOS_SCHED_CFG_CONFIRM_WEIGHT,   /**< [HB.GB] Confrim (green color) weight*/
    CTC_QOS_SCHED_CFG_EXCEED_WEIGHT,    /**< [GB.GG]    Exceed (yellow color) weight*/
    CTC_QOS_SCHED_CFG_CONFIRM_CLASS,    /**< [HB.GB.GG] Confrim (green color) class*/
    CTC_QOS_SCHED_CFG_EXCEED_CLASS,     /**< [GB.GG]    Exceed (yellow color) class*/
    CTC_QOS_SCHED_CFG_MAX
};
typedef enum ctc_qos_sched_cfg_type_e ctc_qos_sched_cfg_type_t;

/**
 @brief Qos queue level schedule
*/
struct ctc_qos_sched_queue_s
{
    uint8  cfg_type;   /**< [HB.GB] Configure type, refer to ctc_qos_sched_cfg_type_t */

    ctc_qos_queue_id_t queue;   /**< [HB.GB.GG] Generate queue id information*/

    uint16 confirm_weight;  /**< [HB.GB] Comfirmed weight for green packet*/
    uint16 exceed_weight;   /**< [GB.GG]  Exceeded  weight for yellow packet*/

    uint8 confirm_class;    /**< [HB.GB.GG] queue class for green packet */
    uint8 exceed_class;     /**< [GB.GG]    queue class for yellow packet */

};
typedef struct ctc_qos_sched_queue_s ctc_qos_sched_queue_t;

/**
 @brief Qos group level schedule
*/
struct ctc_qos_sched_group_s
{
    uint8 group_type; /*[GB]Scheudle type, refer to ctc_qos_sched_group_type_t*/
    uint8 cfg_type;   /*[GB.GG]Configure type, refer to ctc_qos_sched_cfg_type_t*/

    uint32 gport;      /**< [GB] Global port(input)*/
    uint16 service_id; /**< [GB] Service identifaication(input)*/
    ctc_qos_queue_id_t queue;   /**< [GG] Generate queue id information*/

    uint8 queue_class;    /**< [GB.GG] Queeu class (input)<0-7> include confirm class and exceed class*/
    uint8 class_priority; /**< [GB.GG] Class priority ,<0-3>*/

    uint8 weight;         /**< [GB.GG] Schedule weight*/
    uint8 rsv[3];
};
typedef struct ctc_qos_sched_group_s ctc_qos_sched_group_t;

/**
 @brief Qos sub group level schedule
*/
struct ctc_qos_sched_sub_group_s
{
    uint8 service_id;   /**< [GB] Service identifaication*/

    uint8 weight;       /**< [GB] Schedule weitgh*/

    uint8 sub_group_id; /**< [GB] Sub group id, 0((High pri),1 2*/
    uint8 rsv0;
};
typedef struct ctc_qos_sched_sub_group_s ctc_qos_sched_sub_group_t;

/**
 @brief Qos schedule data structure
*/
struct ctc_qos_sched_s
{
    uint8 type;         /**< [HB.GB.GG] Scheudle type, refer to ctc_qos_sched_type_t */
    uint8 rsv0[3];

    union
    {
        ctc_qos_sched_queue_t     queue_sched;      /**< [HB.GB.GG] Queue level schedule*/
        ctc_qos_sched_group_t     group_sched;      /**< [GB.GG]    Group level schedule*/
        ctc_qos_sched_sub_group_t sub_group_sched;  /**< [GB]    Sub group level schedule*/
    } sched;
};
typedef struct ctc_qos_sched_s ctc_qos_sched_t;

/**
 @brief Qos ingress resource pools type
*/
enum ctc_qos_igs_resrc_pool_type_e
{
    CTC_QOS_IGS_RESRC_DEFAULT_POOL,      /**< [GG] Default pool */
    CTC_QOS_IGS_RESRC_NON_DROP_POOL,     /**< [GG] Non-drop pool */
    CTC_QOS_IGS_RESRC_MIN_POOL,          /**< [GG] Min guarantee pool */
    CTC_QOS_IGS_RESRC_C2C_POOL,          /**< [GG] CPU to CPU pool */
    CTC_QOS_IGS_RESRC_ROUND_TRIP_POOL,   /**< [GG] Round trip pool */
    CTC_QOS_IGS_RESRC_CONTROL_POOL,      /**< [GG] Control pool, from cpu or to cpu */

    CTC_QOS_IGS_RESRC_POOL_MAX
};
typedef enum ctc_qos_igs_resrc_pool_type_e ctc_qos_igs_resrc_pool_type_t;

/**
 @brief Qos egress resource pools type
*/
enum ctc_qos_egs_resrc_pool_type_e
{
    CTC_QOS_EGS_RESRC_DEFAULT_POOL,      /**< [GG] Default pool, support congest level */
    CTC_QOS_EGS_RESRC_NON_DROP_POOL,     /**< [GG] Non-drop pool */
    CTC_QOS_EGS_RESRC_SPAN_POOL,         /**< [GG] SPAN and mcast pool, support congest level */
    CTC_QOS_EGS_RESRC_CONTROL_POOL,      /**< [GG] Control pool, from cpu or to cpu */
    CTC_QOS_EGS_RESRC_MIN_POOL,          /**< [GG] Min guarantee pool */
    CTC_QOS_EGS_RESRC_C2C_POOL,          /**< [GG] CPU to CPU pool */

    CTC_QOS_EGS_RESRC_POOL_MAX
};
typedef enum ctc_qos_egs_resrc_pool_type_e ctc_qos_egs_resrc_pool_type_t;

/**
 @brief Qos resource configure type
*/
enum ctc_qos_resrc_cfg_type_e
{
    CTC_QOS_RESRC_CFG_POOL_CLASSIFY,        /**< [GG] Priority => pool */
    CTC_QOS_RESRC_CFG_PORT_MIN,             /**< [GG] Port min guarantee threshold */
    CTC_QOS_RESRC_CFG_QUEUE_DROP,           /**< [GG] Config queue drop profile */
    CTC_QOS_RESRC_CFG_FLOW_CTL,             /**< [GG] Config queue flow control threshold */
    CTC_QOS_RESRC_CFG_MAX
};
typedef enum ctc_qos_resrc_cfg_type_e ctc_qos_resrc_cfg_type_t;

/**
 @brief Qos resource classify pool
*/
struct ctc_qos_resrc_classify_pool_s
{
    uint32 gport;               /**< [GG] Global port */
    uint8  priority;            /**< [GG] Qos priorty <0-63> */
    uint8  dir;                 /**< [GG] Direction, refer to ctc_direction_t */

    uint8  pool;                /**< [GG] refer to ctc_qos_igs_resrc_pool_type_t and ctc_qos_egs_resrc_pool_type_t */
};
typedef struct ctc_qos_resrc_classify_pool_s ctc_qos_resrc_classify_pool_t;

/**
 @brief Qos resource port min guarante threshold config
*/
struct ctc_qos_resrc_port_min_s
{
    uint32 gport;               /**< [GG] Global port */
    uint8  dir;                 /**< [GG] Direction, refer to ctc_direction_t */

    uint16 threshold;           /**< [GG] Port min guarantee threshold, uint is buffer cell <0-255> */
};
typedef struct ctc_qos_resrc_port_min_s ctc_qos_resrc_port_min_t;

struct ctc_qos_resrc_fc_s
{
    uint32 gport;               /**< [GG] Global port */
    uint8  priority_class;      /**< [GG] Pfc priority class <0-7>, value should be priority/8 */
    uint8 is_pfc;               /**< [GG] Is pfc */

    uint16 xon_thrd;            /**< [GG] Xon threshold which triger send xon pause frame */
    uint16 xoff_thrd;           /**< [GG] Xoff threshold which triger send xoff pause frame */
    uint16 drop_thrd;           /**< [GG] Drop threshold which packet will be drop  */
};
typedef struct ctc_qos_resrc_fc_s ctc_qos_resrc_fc_t;


typedef ctc_qos_drop_t  ctc_qos_drop_array[CTC_RESRC_MAX_CONGEST_LEVEL_NUM];
/**
 @brief Qos resource mangement data structure
*/
struct ctc_qos_resrc_s
{
    uint8  cfg_type;            /**< [GG] Configure type, refer to ctc_qos_resrc_cfg_type_t*/

    union
    {
        ctc_qos_resrc_classify_pool_t pool;     /**< [GG] classify pool */
        ctc_qos_resrc_port_min_t port_min;      /**< [GG] set ingress/egress port guarantee min threshold */
        ctc_qos_drop_array queue_drop;          /**< [GG] set queue drop of 8 congest level */
        ctc_qos_resrc_fc_t flow_ctl;            /**< [GG] set flow Control resource threshold */
    }u;
};
typedef struct ctc_qos_resrc_s ctc_qos_resrc_t;

/**
 @brief Qos resource pool stats type
*/
enum ctc_qos_resrc_pool_stats_type_e
{
    CTC_QOS_RESRC_STATS_IGS_POOL_COUNT,         /**< [GG] ingress pool instant count */
    CTC_QOS_RESRC_STATS_IGS_TOTAL_COUNT,        /**< [GG] ingress total instant count */
    CTC_QOS_RESRC_STATS_EGS_POOL_COUNT,         /**< [GG] egress pool instant count */
    CTC_QOS_RESRC_STATS_EGS_TOTAL_COUNT,        /**< [GG] egress total instant count */
    CTC_QOS_RESRC_STATS_QUEUE_COUNT,            /**< [GG] queue instant count */

    CTC_QOS_RESRC_STATS_COUNT_MAX
};
typedef enum ctc_qos_resrc_pool_stats_type_e ctc_qos_resrc_pool_stats_type_t;

/**
 @brief Qos resource pool stats
*/
struct ctc_qos_resrc_pool_stats_s
{
    uint8  type;                /**< [GG] stats type, refer to ctc_qos_resrc_pool_stats_type_t */

    uint32 gport;               /**< [GG] Global port */
    uint8  priority;            /**< [GG] Qos priorty <0-63> */
    uint8  pool;                /**< [GG] refer to ctc_qos_igs_resrc_pool_type_t and ctc_qos_egs_resrc_pool_type_t */

    uint16 count;               /**< [GG] instant count */
};
typedef struct ctc_qos_resrc_pool_stats_s ctc_qos_resrc_pool_stats_t;

/**
 @brief Qos resource mangement drop profile
*/
struct ctc_qos_resrc_drop_profile_s
{
    uint8  congest_level_num;       /**< [GG] congest level num <1-8> */
    uint16 congest_threshold[CTC_RESRC_MAX_CONGEST_LEVEL_THRD_NUM];         /**< [GG] congest threshold for different level */
    ctc_qos_queue_drop_t queue_drop[CTC_RESRC_MAX_CONGEST_LEVEL_NUM];       /**< [GG] queue threshold for different level */
};
typedef struct ctc_qos_resrc_drop_profile_s ctc_qos_resrc_drop_profile_t;

/**
 @brief Qos resource profile
*/
enum ctc_qos_resrc_pool_mode_e
{
    CTC_QOS_RESRC_POOL_DISABLE,          /**< [GG] Disable resource managent. For ingress only have default pool; for egress, have default and control pool */
    CTC_QOS_RESRC_POOL_MODE1,            /**< [GG] disable span and non-drop pool */
    CTC_QOS_RESRC_POOL_MODE2,            /**< [GG] all pool used, and some pool map is done */
    CTC_QOS_RESRC_POOL_USER_DEFINE,      /**< [GG] User define mode */

    CTC_QOS_RESRC_POOL_MODE_MAX
};
typedef enum ctc_qos_resrc_pool_mode_e ctc_qos_resrc_pool_mode_t;

/**
 @brief  qos resrc init config
*/
struct ctc_qos_resrc_pool_cfg_s
{
    uint32 igs_pool_size[CTC_QOS_IGS_RESRC_POOL_MAX];   /**< [GG] Assign igs pools size, total is 30*1024 buffer cells, for user define */
    uint32 egs_pool_size[CTC_QOS_EGS_RESRC_POOL_MAX];   /**< [GG] Assign egs pools size, total is 30*1024 buffer cells, for user define */
    uint8  igs_pool_mode;                   /**< [GG] Select resource profile, refert to ctc_qos_resrc_profile_t */
    uint8  egs_pool_mode;                   /**< [GG] Select resource profile, refert to ctc_qos_resrc_profile_t */
    ctc_qos_resrc_drop_profile_t drop_profile[CTC_QOS_EGS_RESRC_POOL_MAX];  /**< [GG]  Only default|non-drop|span|control pool support drop profile */
};
typedef struct ctc_qos_resrc_pool_cfg_s ctc_qos_resrc_pool_cfg_t;

/**
 @brief  qos resrc init config
*/
enum ctc_qos_port_queue_num_e
{
    CTC_QOS_PORT_QUEUE_NUM_8       = 8,  /**< [GB.GG] 8 queue mode*/
    CTC_QOS_PORT_QUEUE_NUM_16      = 16, /**< [GB.GG] 16 queue mode*/
    CTC_QOS_PORT_QUEUE_NUM_4_BPE,        /**< [GG] 4 queue mode for 480 port extender, must configurate by BPE before use*/
    CTC_QOS_PORT_QUEUE_NUM_8_BPE,        /**< [GG] 8 queue mode for 240 port extender, must configurate by BPE before use*/
    MAX_CTC_PORT_QUEUE_NUM_MAX
};
typedef enum ctc_qos_port_queue_num_e ctc_qos_port_queue_num_t;

/**
 @brief  qos global config
*/
struct ctc_qos_global_cfg_s
{
    uint8  queue_num_per_network_port;      /**< [HB.GB.GG] queue number per network port, refer to ctc_qos_port_queue_num_t*/
    uint8  queue_num_per_static_int_port;   /**< [HB] queue number per static internal port */
    uint8  queue_num_per_fabric;            /**< [HB] queue number per fabric */
    uint8  max_internal_port_id;            /**< [HB] max internal port id */
    uint8  queue_num_per_internal_port;     /**< [HB.GB] queue number per internal port*/
    uint8  queue_num_per_cpu_reason_group;  /**< [HB.GB] queue number per cpu reason group */
    uint16 service_num_with_queue;          /**< [HB] service number which with queue */
    uint8  queue_num_per_ingress_service;   /**< [HB] queue number per ingress service */
    uint8  queue_num_per_egress_service;    /**< [HB] queue number per egress service */
    uint8  queue_aging_time;                /**< [GB] queue aging interval (uint:s), default  aging time is 30s*/
    uint8  max_cos_level;                   /**< [GG] the max number of cos level in MEF BWP */
    uint16 policer_num;                     /**< [GG] the max number of policer, support 1K/2K/4K/8K, default 4K
                                                      8K support 1G rate,  4K support 10G rate,
                                                      2K support 40G rate, 1K support 100G rate */
    uint8  queue_num_for_cpu_reason;        /**< [GG] the queue number for cpu reason, support 128/64/32, default 128*/
    ctc_qos_resrc_pool_cfg_t resrc_pool;    /**< [GG] resource pool init value */

};
typedef struct ctc_qos_global_cfg_s ctc_qos_global_cfg_t;

/**@} end of @defgroup qos QOS */

#ifdef __cplusplus
}
#endif

#endif

