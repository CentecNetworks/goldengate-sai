/**
 @file ctc_ptp.h

 @date 2010-5-25

 @version v2.0

 This file contains IEEE1588 PTP related data structure, enum, macro.

*/

#ifndef _CTC_PTP_H
#define _CTC_PTP_H
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
 @defgroup ptp PTP
 @{
*/

/**
 @brief define ptp global prop
*/
enum ctc_ptp_global_prop_s
{
    CTC_PTP_GLOBAL_PROP_PTP_UCASE_EN = 0, /**< [GB] if set,  PTP ucast will be processed, default enable*/
    CTC_PTP_GLOBAL_PROP_SYNC_COPY_TO_CPU_EN, /**< [GB] if set, TC will copy sync and follow_up message to CPU */
    CTC_PTP_GLOBAL_PROP_SIGNALING_COPY_TO_CPU_EN, /**< [GB] if set, TC will copy signaling message to CPU */
    CTC_PTP_GLOBAL_PROP_MANAGEMENT_COPY_TO_CPU_EN, /**<  [GB] if set, TC will copy management message to CPU*/
    CTC_PTP_GLOBAL_PROP_DELAY_REQUEST_PROCESS_EN, /**< [GB] if set, P2P transparent clock will process Delay_Request message*/
    CTC_PTP_GLOBAL_PROP_PORT_BASED_PTP_EN, /**< [GB] if set, PTP will be enabled by port or vlan, default by port*/
    CTC_PTP_GLOBAL_PROP_CACHE_AGING_TIME, /**< [GB.GG] aging time for TS, unit:seconds*/
    CTC_PTP_GLOBAL_PROP_SYNC_OR_TOD_INPUT_SELECT, /**< [GB.GG] select Sync Interface or ToD Interface to synchronize from master clock */
    MAX_CTC_PTP_GLOBAL_PROP
};
typedef enum ctc_ptp_global_prop_s ctc_ptp_global_prop_t;

/**
 @brief  define type for delay adjust
*/
enum ctc_ptp_adjust_delay_type_e
{
    CTC_PTP_ADJUST_DELAY_INGRESS_LATENCY = 0,   /**< [GB.GG] latency from phy to mac on RX, <0-0xFFFF>*/
    CTC_PTP_ADJUST_DELAY_EGRESS_LATENCY,    /**< [GB.GG] latency from mac to phy on TX, <0-0xFFFF>*/
    CTC_PTP_ADJUST_DELAY_INGRESS_ASYMMETRY, /**< [GB.GG] asymmetry on ingress, <(-0x000FFFFFFFFF)-0x000FFFFFFFFF> */
    CTC_PTP_ADJUST_DELAY_EGRESS_ASYMMETRY,  /**< [GB.GG] asymmetry on egress, <(-0x000FFFFFFFFF)-0x000FFFFFFFFF>*/
    CTC_PTP_ADJUST_DELAY_PATH_DELAY,         /**< [GB.GG] path delay, <0-0x000FFFFFFFFF>*/

    MAX_CTC_PTP_ADJUST_DELAY
};
typedef enum ctc_ptp_adjust_delay_type_e ctc_ptp_adjust_delay_type_t;

/**
 @brief  define PTP device type
*/
enum ctc_ptp_device_type_e
{
    CTC_PTP_DEVICE_NONE = 0,    /**< [GB.GG] blind for PTP message,forward it as normal packet*/
    CTC_PTP_DEVICE_OC,          /**< [GB.GG] ordinary clock device*/
    CTC_PTP_DEVICE_BC,          /**< [GB.GG] boundary clock device*/
    CTC_PTP_DEVICE_E2E_TC,      /**< [GB.GG] end-to-end transparent clock device or E2ETC+OC/BC*/
    CTC_PTP_DEVICE_P2P_TC,      /**< [GB.GG] peer-to-peer transparent clock device or P2PTC+OC/BC*/

    MAX_CTC_PTP_DEVICE
};
typedef enum ctc_ptp_device_type_e ctc_ptp_device_type_t;

/**
 @brief  captured ts type
*/
enum ctc_ptp_captured_type_e
{
    CTC_PTP_CAPTURED_TYPE_TX = 0,  /**< [GB.GG] TS captured type is TX*/
    CTC_PTP_CAPTURED_TYPE_RX,      /**< [GB.GG] TS captured type is RX*/

    CTC_PTP_CAPTURED_MAX
};
typedef enum ctc_ptp_captured_type_e ctc_ptp_captured_type_t;

/**
 @brief  define input captured source
*/
enum ctc_ptp_captured_src_e
{
    CTC_PTP_TIEM_INTF_SYNC_PULSE = 5,   /**< [GB.GG] TS captured source is Sync Interface*/
    CTC_PTP_TIEM_INTF_TOD_1PPS = 6,     /**< [GB.GG] TS captured source is ToD Interface*/

    MAX_CTC_PTP_TIEM_INTF
};
typedef enum ctc_ptp_captured_src_e ctc_ptp_captured_src_t;

/**
 @brief  define Sync or ToD Interface selected
*/
enum ctc_ptp_intf_selected_e
{
    CTC_PTP_INTF_SELECT_NONE,         /**< [GB.GG] Select none to sync*/
    CTC_PTP_INTF_SELECT_SYNC,         /**< [GB.GG] Select Sync Interface to sync*/
    CTC_PTP_INTF_SELECT_TOD,          /**< [GB.GG] Select ToD Interface to sync*/

    MAX_CTC_PTP_INTF_SELECT
};
typedef enum ctc_ptp_intf_selected_e ctc_ptp_intf_selected_t;

/**
 @brief   ptp init global config
*/
struct ctc_ptp_global_config_s
{
    uint8  ptp_ucast_en;                 /**< [GB] if set,  PTP ucast will be processed, default enable*/
    uint8  sync_copy_to_cpu_en;         /**< [GB] if set, TC will copy sync and follow_up message to CPU */
    uint8  signaling_copy_to_cpu_en;      /**< [GB] if set, TC will copy signaling message to CPU */
    uint8  management_copy_to_cpu_en;  /**<  [GB] if set, TC will copy management message to CPU*/

    uint8  delay_request_process_en;    /**< [GB] if set, P2P transparent clock will process Delay_Request message*/
    uint8  port_based_ptp_en;            /**< [GB] if set, PTP will be enabled by port or vlan, default by port*/
    uint16 cache_aging_time;             /**< [GB.GG] aging time for TS, unit:seconds*/

    ctc_ptp_intf_selected_t  intf_selected;  /**< [GB.GG] select Sync Interface or ToD Interface to synchronize from master clock*/

    uint8  ntpv4_en; /**< [HB] 0: 1588 mode, 1: NTPv4 mode*/
    uint8  resv[3];    /**< Reserved0 */
};
typedef struct ctc_ptp_global_config_s ctc_ptp_global_config_t;

/**
 @brief   ptp frc time
*/
struct ctc_ptp_time_s
{
    uint32 seconds;          /**< [HB.GB.GG] seconds*/
    uint32 nanoseconds;      /**< [HB.GB.GG] nano seconds*/
    uint32 nano_nanoseconds; /**< [HB.GB.GG] nano nano seconds*/
    uint8  is_negative;       /**< [HB.GB.GG] negative time indicator*/
    uint8  resv[3];
};
typedef struct ctc_ptp_time_s ctc_ptp_time_t;

/**
 @brief   ptp Sync interface configurations
*/
struct ctc_ptp_sync_intf_cfg_s
{
    uint8  mode;               /**< [HB.GB.GG] 0: input, 1: output */
    uint8  lock;                /**< [HB.GB.GG] indicating the clock accuracy is better than some threshold*/
    uint8  accuracy;           /**< [HB.GB.GG] timer accuracy, <32-49, or 0xFE>*/
    uint8  resv0;

    uint32 sync_clock_hz;     /**< [HB.GB.GG] sycnClock signal frequency, <0-25000000>*/
    uint32 sync_pulse_hz;     /**< [GB.GG] sycnPulse signal frequency, <0-250000>*/

    uint8  sync_pulse_duty;  /**< [HB.GB.GG] the duty of syncPulse signal, value range is <1-99>*/
    uint8  epoch;             /**< [HB.GB.GG] indicate how many syncClock cycle will be by-passed before send the first bit of time code,<0-63>*/
    uint16 resv1;
};
typedef struct ctc_ptp_sync_intf_cfg_s ctc_ptp_sync_intf_cfg_t;

/**
 @brief   ptp Sync interface input timescode
*/
struct ctc_ptp_sync_intf_code_s
{
    uint32 seconds;       /**< [HB.GB.GG] second of input time*/
    uint32 nanoseconds;  /**< [HB.GB.GG] nano second input time*/
    uint8  lock;          /**< [HB.GB.GG] lock status from input*/
    uint8  accuracy;     /**< [HB.GB.GG] timer accuracy*/
    uint8  crc_error;    /**< [HB.GB.GG] crc error status*/
    uint8  crc;           /**< [HB.GB.GG] crc*/
};
typedef struct ctc_ptp_sync_intf_code_s ctc_ptp_sync_intf_code_t;

/**
 @brief   ptp ToD interface configurations
*/
struct ctc_ptp_tod_intf_cfg_s
{
    uint8  mode;                /**< [GB.GG] 0: input mode, 1: output mode*/
    uint8  pulse_duty;         /**< [GB.GG] the duty of 1pps signal, value range is <1-99>*/
    uint16  resv;

    uint16 stop_bit_num;       /**< [GB.GG] except for default 1 stop bit, how many stop bits will be sent*/
    uint16 epoch;               /**< [GB.GG] indicate how many clock cycle will be by-passed before send the first bit of time code,GB:<0,0xFFF>,
                                      1ms=epoch*1024/clockCore(M)/1000, GG:<0,0x7FFF>, 1ms=epoch*512/clockCore(M)/1000*/

    uint32 pulse_delay;         /**< [GB.GG] 1pps delay between master and slave, unit is ns>*/
};
typedef struct ctc_ptp_tod_intf_cfg_s ctc_ptp_tod_intf_cfg_t;

/**
 @brief   ptp ToD interface input message
*/
struct ctc_ptp_tod_intf_code_s
{
    uint8  msg_char0;   /**< [GB.GG] char0 of message, used for input mode*/
    uint8  msg_char1;   /**< [GB.GG] char1 of message, used for input mode*/
    uint8  msg_class;   /**< [GB.GG] class of messag, used for input and output mode*/
    uint8  msg_id;      /**< [GB.GG] identify of this message, used for input and output mode*/

    uint16 msg_length;  /**< [GB.GG] length of the payload of this message, used for input and output mode*/
    uint16 gps_week;    /**< [GB.GG] GPS week, used for input mode*/

    uint32 gps_second_time_of_week; /**< [GB.GG] GPS Second time of week, used for input mode*/

    int8   leap_second; /**< [GB.GG] Leap seconds between GPS and UTC, used for input and output mode*/
    uint8  pps_status;  /**< [GB.GG] 1PPS status <0-0xFF>, used for input and output mode*/
    uint8  pps_accuracy; /**< [GB.GG] 1PPS accuracy, used for input and output mode*/
    uint8  crc_error;   /**< [GB.GG] crc error status, used for input mode*/

    uint8  crc;                 /**< [GB.GG] crc, used for input mode*/
    uint8  clock_src;           /**< [GB.GG] clock source <0-3>, used for output mode */
    uint16 clock_src_status;    /**< [GB.GG] clock source work status, used for output mode */

    uint16 monitor_alarm;       /**< [GB.GG] monitor alarm, used for output mode */
    uint16 resv;

};
typedef struct ctc_ptp_tod_intf_code_s ctc_ptp_tod_intf_code_t;

/**
 @brief   ptp captured timestamp
*/
struct ctc_ptp_capured_ts_s
{
    ctc_ptp_captured_type_t  type;   /* [GB.GG] captured ts type */
    union
    {
        uint16  lport;         /**< [GB.GG] captured port for tx*/
        uint8  captured_src; /**< [GB.GG] captured source for rx, 5:syncPulse; 6:1PPS, refert to ctc_ptp_captured_src_t*/
    } u;
    uint16  seq_id;            /**< [GB.GG] sequence ID*/
    ctc_ptp_time_t ts;        /**< [GB.GG] ts*/
};
typedef struct ctc_ptp_capured_ts_s ctc_ptp_capured_ts_t;

/**
 @brief   TX ts callback date for isr
*/
#define CTC_PTP_TX_TS_CACHE_MAX (256)
struct ctc_ptp_ts_cache_s
{
    uint8 entry_count;                                   /**< [GB.GG] the total number of entry*/
    uint8 resv[3];
    ctc_ptp_capured_ts_t entry[CTC_PTP_TX_TS_CACHE_MAX];  /**< [GB.GG] TX captured entry*/
};
typedef struct ctc_ptp_ts_cache_s ctc_ptp_ts_cache_t;

/**
 @brief   RX time messge callback date for isr
*/
struct ctc_ptp_rx_ts_message_s
{
    ctc_ptp_captured_src_t source;                      /**< [GB.GG] RX captured source*/
    union
    {
        ctc_ptp_sync_intf_code_t  sync_intf_message;   /**< [GB.GG] Sync Interface input message*/
        ctc_ptp_tod_intf_code_t   tod_intf_message;    /**< [GB.GG] ToD Interface input message*/
    } u;
    ctc_ptp_time_t captured_ts;                         /**< [GB.GG] captured TS*/
};
typedef struct ctc_ptp_rx_ts_message_s ctc_ptp_rx_ts_message_t;

/**
 @brief  define ptp message type
*/
enum ctc_ptp_msg_type_e
{
    CTC_PTP_MSG_TYPE_SYNC = 0,                 /**< [GG] sync message type*/
    CTC_PTP_MSG_TYPE_DELAY_REQ,             /**< [GG] delay request message type*/
    CTC_PTP_MSG_TYPE_PDELAY_REQ,            /**< [GG] peer delay request message type*/
    CTC_PTP_MSG_TYPE_PDELAY_RESP,           /**< [GG] peer delay response message type*/
    CTC_PTP_MSG_TYPE_FOLLOW_UP = 8,        /**< [GG] follow up message type*/
    CTC_PTP_MSG_TYPE_DELAY_RESP,             /**< [GG] delay response message type*/
    CTC_PTP_MSG_TYPE_PDELAY_RESP_FOLLOW_UP, /**< [GG] peer delay response follow up message type*/
    CTC_PTP_MSG_TYPE_ANNOUNCE,                  /**< [GG] announce message type*/
    CTC_PTP_MSG_TYPE_SIGNAL,                 /**< [GG] signaling message type*/
    CTC_PTP_MSG_TYPE_MANAGEMENT,            /**< [GG] management message type*/
    CTC_PTP_MSG_TYPE_MAX = 16
};
typedef enum ctc_ptp_msg_type_e ctc_ptp_msg_type_t;

/**
 @brief  define ptp action flag
*/
enum ctc_ptp_action_flag_e
{
    CTC_PTP_ACTION_FLAG_DISCARD               = 0x0001,  /**< [GG] discard message, per message type control*/
    CTC_PTP_ACTION_FLAG_COPY_TO_CPU       = 0x0002,  /**< [GG] copy message to cpu, per message type control*/
    CTC_PTP_ACTION_FLAG_RESIDENCE_TIME  = 0x0004,  /**< [GG] update the residence time, per message type control*/
    CTC_PTP_ACTION_FLAG_PATH_DELAY          = 0x0008,  /**< [GG] apply the path delay time, per message type control*/
    CTC_PTP_ACTION_FLAG_IGS_ASYM_DELAY  = 0x0010,  /**< [GG] apply the ingress asymmetry delay time, per message type control*/
    CTC_PTP_ACTION_FLAG_EGS_ASYM_DELAY  = 0x0020  /**< [GG] apply the egress asymmetry delay time, per message type control*/
};
typedef enum ctc_ptp_action_flag_e ctc_ptp_action_flag_t;

/**
 @brief   ptp device clock type config
*/
struct ctc_ptp_clock_s
{
    uint8 clock_id;                         /**< [GG] clock id, <2-7>, 0 is disable, 1 is reserved*/
    uint8 resv[3];

    uint32 action_flag[CTC_PTP_MSG_TYPE_MAX]; /**< [GG] ptp action flag, ref ctc_ptp_action_flag_t, per ctc_ptp_msg_type_t control*/
};
typedef struct ctc_ptp_clock_s ctc_ptp_clock_t;

/**@} end of @defgroup  ptp PTP */

#ifdef __cplusplus
}
#endif

#endif

