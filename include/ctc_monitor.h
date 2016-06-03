/**
 @file ctc_monitor.h

 @author Copyright (C) 2011 Centec Networks Inc.  All rights reserved.

 @date 2011-12-27

 @version v2.0

This file contains all monitor related data structure, enum, macro and proto.

*/
#ifndef _CTC_MONITOR_H
#define _CTC_MONITOR_H
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
#define CTC_MONITOR_LATENCY_THRD_LEVEL 8 /**<[GG] Support 8 latency threshold levels*/
/**
 @defgroup monitor MONITOR
 @{
*/

/**
@brief  monitor type
*/
enum ctc_monitor_type_e
{
    CTC_MONITOR_BUFFER,    /**<[GG]  monitor buffer count*/
    CTC_MONITOR_LATENCY,   /**<[GG]  monitor latency*/
};
typedef enum ctc_monitor_type_e ctc_monitor_type_t;

/**
@brief  monitor config type
*/
enum ctc_monitor_config_type_e
{
    CTC_MONITOR_CONFIG_MON_INFORM_EN,     /**<[GG]  Buffer and latency inform enable, per port enable*/
    CTC_MONITOR_CONFIG_MON_INFORM_MIN,    /**<[GG]  Buffer and latency inform min thrd,  per port control
                                                  for buffer is bufcnt thrd<0-MaxBuffer> 16 multiple(such as 0,16,32,...),
                                                  for latency is thrd level<0-7>*/
    CTC_MONITOR_CONFIG_MON_INFORM_MAX,    /**<[GG]  Buffer and latency inform max thrd,  per port control
                                                  for buffer is bufcnt thrd<0-MaxBuffer> 16 multiple(such as 0,16,32,...),
                                                  for latency is thrd level<0-7>*/

    CTC_MONITOR_CONFIG_LOG_EN,            /**<[GG]  Buffer and Lantency log packet to cpu, latency per port enable, buffer global enable*/
    CTC_MONITOR_CONFIG_LOG_THRD_LEVEL,    /**<[GG]  Lantency log thrd level<0-7>, per port control,
                                                  buffer log use buffer hig thrd condition, so don't use this api */

    CTC_MONITOR_CONFIG_MON_SCAN_EN,       /**<[GG]   Buffer and Lantency timer scan enable, per port enable*/
    CTC_MONITOR_CONFIG_MON_INTERVAL,      /**<[GG]   Buffer and Lantency timer scan inteval, global control*/

};
typedef enum ctc_monitor_config_type_e ctc_monitor_config_type_t;

/**
@brief  monitor configure
*/
struct ctc_monitor_config_s
{
    uint8 monitor_type;  /**<[GG] monitor type, refert to ctc_monitor_type_t*/
    uint8 cfg_type;      /**<[GG] property type, refert to ctc_monitor_config_type_t*/
    uint8 rsv;
    uint32 gport;        /**<[GG] port of monitor*/
    uint32 value;        /**<[GG] configure value*/
};
typedef struct ctc_monitor_config_s ctc_monitor_config_t;

/**
@brief  monitor buffer wartermark
*/
struct ctc_monitor_watermark_buffer_s
{
    uint32 max_uc_cnt;      /**<[GG]  record max unicast buffer cnt*/
    uint32 max_mc_cnt;      /**<[GG]  record max multicast buffer cnt*/
    uint32 max_total_cnt;   /**<[GG]  record max total buffer cnt*/
};
typedef struct ctc_monitor_watermark_buffer_s ctc_monitor_watermark_buffer_t;

/**
@brief  monitor latency wartermark
*/
struct ctc_monitor_watermark_latency_s
{
    uint64 max_latency;     /**<[GG]  record max latency*/
};
typedef struct ctc_monitor_watermark_latency_s ctc_monitor_watermark_latency_t;

/**
@brief  monitor wartermark
*/
struct ctc_monitor_watermark_s
{
    uint8 monitor_type;        /**<[GG] monitor type, refert to ctc_monitor_type_t*/
    uint32 gport;              /**<[GG] port of monitor*/

    union
    {
        ctc_monitor_watermark_buffer_t buffer;    /**<[GG] buffer watermark*/
        ctc_monitor_watermark_latency_t latency;  /**<[GG] latency watermark*/
    }u;
};
typedef struct ctc_monitor_watermark_s ctc_monitor_watermark_t;

/**
@brief  monitor message type
*/
enum ctc_monitor_msg_type_e
{
     CTC_MONITOR_MSG_EVENT,        /**<[GG] monitor buffer event message*/
     CTC_MONITOR_MSG_STATS,        /**<[GG] monitor buffer stats message*/
};
typedef enum ctc_monitor_msg_type_e ctc_monitor_msg_type_t;

/**
@brief  buffer monitor event
*/
struct ctc_monitor_buffer_event_s
{
    uint32 gport;           /**<[GG] port of monitor*/
    uint8 event_state;      /**<[GG] if threshold_state be set 1, latency greater than defined threshold, else less than defined threshold  */
    uint8 threshold_level;  /**<[GG] threshold level when buffer event overcome  */
    uint32 uc_cnt;          /**<[GG] unicast buffer cell count*/
    uint32 mc_cnt;          /**<[GG] multicast  buffer cell count*/

};
typedef struct ctc_monitor_buffer_event_s ctc_monitor_buffer_event_t;

/**
@brief  buffer monitor stats
*/
struct ctc_monitor_buffer_stats_s
{
    uint8 info_type; /**<[GG] information tyupe of stats*/
    uint8 rsv;
    uint32 gport;    /**<[GG] port of monitor*/
    uint32 uc_cnt;   /**<[GG] unicast buffer cell count*/
    uint32 mc_cnt;   /**<[GG] multicast  buffer cell count*/

    uint32 totol_cnt; /**<[GG] totoal buffer cell count*/
    uint32 sc_cnt;    /**<[GG] Default pool buffer cell count*/
    uint32 sc_pkt_cnt;/**<[GG] Default pool buffer cell packet count*/
};
typedef struct ctc_monitor_buffer_stats_s ctc_monitor_buffer_stats_t;

/**
@brief  latency monitor event
*/
struct ctc_monitor_latency_event_s
{
    uint32 gport;       /**<[GG] global phyical port of monitor*/
    uint32 source_port; /**<[GG] source port of packet*/
    uint64 latency;     /**<[GG] packet latency through switch*/
    uint8  event_state; /**<[GG] if event_state be set 1, latency greater than defined threshold, else less than defined threshold  */
    uint8 level;        /**<[GG] congestion level of smart buffer*/
    uint8 port;         /**<[GG] global source phy port of monitor such as linkagg memeber port*/
    uint8 rsv;
};
typedef struct ctc_monitor_latency_event_s ctc_monitor_latency_event_t;

/**
@brief  latency monitor stats
*/
struct ctc_monitor_latency_stats_s
{
    uint32 gport;  /**<[GG] port of monitor*/
    uint16 rsv;
    uint32 threshold_cnt[CTC_MONITOR_LATENCY_THRD_LEVEL];   /**<[GG] latency threshold count per per level <0-7>*/
};
typedef struct ctc_monitor_latency_stats_s ctc_monitor_latency_stats_t;

/**
@brief  monitor message
*/
struct ctc_monitor_msg_s
{
    uint8 monitor_type; /**<[GG] monitor type, refert to ctc_monitor_type_t*/
    uint8 msg_type;     /**<[GG] message  type, refert to ctc_monitor_msg_type_t*/
    uint8 rsv[2];

    uint64 timestamp;    /**<[GG] timestamp of message*/

    union
    {
        ctc_monitor_buffer_event_t buffer_event;      /**<[GG] buffer event information*/
        ctc_monitor_buffer_stats_t buffer_stats;      /**<[GG] buffer stats information*/
        ctc_monitor_latency_event_t latency_event;    /**<[GG] latency event information*/
        ctc_monitor_latency_stats_t latency_stats;    /**<[GG] latency stats information*/
    }  u;

};
typedef struct ctc_monitor_msg_s ctc_monitor_msg_t;


/**
@brief  monitor profile of hardware
*/
struct ctc_monitor_data_s
{
    uint16 msg_num;     /**<[GG] message numbers*/
    uint16 rsv;
    ctc_monitor_msg_t*  p_msg; /**<[GG] message of event or stats*/
};
typedef struct ctc_monitor_data_s ctc_monitor_data_t;

/**
@brief  callback of monitor for protocol stack
*/
typedef void (* ctc_monitor_fn_t)(ctc_monitor_data_t * info, void* userdata) ;  /**<Callback function to get data from DMA*/


struct ctc_monitor_latency_threshold_s
{
    uint8 level;      /**< [GG] latecny threshold level <0-7>*/
    uint8 rsv;
    uint16 threshold; /**< [GG] latecny threshold of specific level*/
};
typedef struct ctc_monitor_latency_threshold_s ctc_monitor_latency_thrd_t;


/**
@brief  monitor global config type
*/
enum ctc_monitor_glb_config_type_e
{
    CTC_MONITOR_GLB_CONFIG_LATENCY_THRD,     /**<[GG]  latency level threshold*/
    CTC_MONITOR_GLB_CONFIG_BUFFER_LOG_MODE,  /**<[GG]  buffer log mode, 0: causer, 1: victim*/
};
typedef enum ctc_monitor_glb_config_type_e ctc_monitor_glb_config_type_t;


/**
@brief  monitor global config
*/
struct ctc_monitor_glb_cfg_s
{
    uint8 cfg_type;                         /**<[GG] configre type refer to ctc_monitor_glb_config_type_t*/
    union
    {
        uint32 value;                       /**< [GG] configre value according to ctc_monitor_glb_config_type_t*/
        ctc_monitor_latency_thrd_t  thrd;   /**< [GG] configre latecny threshold*/
    }u;
};
typedef struct ctc_monitor_glb_cfg_s ctc_monitor_glb_cfg_t;

#ifdef __cplusplus
}
#endif

#endif
/**@} end of @defgroup   monitor MONITOR */

