/**
  @file drv_model_dma.h

  @date 2013-07-01

  @version v5.1

  The file implement driver for dma software simulation defines and macros
*/
#ifndef _DRV_MODEL_DMA_H_
#define _DRV_MODEL_DMA_H_

#if (SDK_WORK_PLATFORM == 1)

#include "sal.h"
#include "drv_lib.h"

#define DRV_MODEL_DMA_MAX_NUM           32

enum DRV_MODEL_DMA_MODE {
    DRV_MODEL_DMA_MODE_LEARNING    =    0,
    DRV_MODEL_DMA_MODE_AGING       =    1,
    DRV_MODEL_DMA_MODE_EFD         =    2,
    DRV_MODEL_DMA_MODE_MAC         =    3,
    DRV_MODEL_DMA_MODE_IPFIX       =    4,
    DRV_MODEL_DMA_MODE_STATS       =    5,
    DRV_MODEL_DMA_MODE_LATENCY     =    6,
};

struct IpfixSessionRecord_Fifo {
    uint32 destination_info                                                 :15;
    uint32 destination_type                                                 :3;
    uint32 dropped_packet                                                   :1;
    uint32 max_ttl                                                          :8;
    uint32 min_ttl_4_0                                                      :5;

    uint32 min_ttl_7_5                                                      :3;
    uint32 ttl_changed                                                      :1;
    uint32 ttl                                                              :8;
    uint32 fragment                                                         :1;
    uint32 non_fragment                                                     :1;
    uint32 last_ts_17_0                                                     :18;

    uint32 last_ts_19_18                                                    :2;
    uint32 first_ts_18_0                                                    :19;
    uint32 rsv_0                                                            :11;

    uint32 first_ts_19                                                      :1;
    uint32 byte_count_30_0                                                  :31;

    uint32 byte_count_36_31                                                 :6;
    uint32 packet_count_25_0                                                :26;

    uint32 packet_count_31_26                                               :6;
    uint32 first_pkt_recv_done                                              :1;
    uint32 expired                                                          :1;
    uint32 export_reason                                                    :4;
    uint32 rsv_1                                                            :20;

};

struct drv_model_dma_info_s
{
    uint8 valid;
    uint8 rsv0[3];
    uint8 dma_mode;

    union
    {
        struct
        {
            uint8 fast_learning_en;
            uint8 is_gport;
            uint8 is_eth_oam;
            uint8 rsv0;

            uint8 is_add;
            uint8 eth_oam_level;
            mac_addr_t  mac;

            uint16 learning_src_port;
            uint16 vsi;
            uint32 old_svlan_id;
            uint32 old_cvlan_id;
            uint32 new_svlan_id;
            uint32 new_cvlan_id; //may be new cvlan id or ad index

            uint32 key_index;
        }
        learning;
        struct
        {
            uint32 aging_ptr;
        }
        aging;
        struct
        {
            uint16 flow_id;
            uint8 op_code;
            uint8 rsv0;
        }
        efd;
        struct
        {
            mac_addr_t  mac;

            uint8 pending;
            uint8 valid;
            uint16 vsiid;

            uint32 ad_index;

            uint8 hash_type;
            uint8 rsv0[3];

            uint32 key_index;
        }
        mac;
        struct
        {
            struct IpfixSessionRecord_Fifo ipfix_session_record;

            uint32 ad_index;
        }
        ipfix;
        struct
        {
            uint16 statsPtr        :14;
            uint32 packetCount     :32;
            uint64 byteCount       :40;
        }
        stats;
        struct
        {
            uint32 info_type                            :1;
            uint32 channel_id                           :7;
            uint32 latency_event_data_timestamp_23_0    :24;

            uint32 latency_event_data_timestamp_55_24   :32;

            uint32 latency_event_data_timestamp_63_56   :8;
            uint32 latency_event_data_valid             :1;
            uint32 rsv_0                                :24;
        }
        latency;
    }u;
};
typedef struct drv_model_dma_info_s drv_model_dma_info_t;

/**
 @brief add the dma fifo
*/
extern int32
drv_model_dma_add_fifo(uint8 chip_id_offset, drv_model_dma_info_t * dma_info);

/**
 @brief del the dma fifo
*/
extern int32
drv_model_dma_del_fifo(uint8 chip_id_offset, drv_model_dma_info_t * dma_info);

/**
 @brief get the dma fifo info by index
*/
extern int32
drv_model_dma_get_fifo(uint8 chip_id_offset, uint16 idx, drv_model_dma_info_t * dma_info);

/**
 @brief get the dma fifo storeg status
*/
extern int32
drv_model_dma_is_not_full(uint8 chip_id_offset);

/**
 @brief set the dma fifo full, for ipfix module test
*/
extern int32
drv_model_dma_set_fifo_full(uint8 chip_id_offset);

#endif

#endif

