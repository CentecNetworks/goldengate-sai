/**
 @file ctc_l2.h

 @author  Copyright (C) 2012 Centec Networks Inc.  All rights reserved.

 @date 2012-03-26

 @version v2.0
*/

#ifndef _CTC_DMA_H
#define _CTC_DMA_H
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
#include "ctc_learning_aging.h"

/****************************************************************
*
* Defines and Macros
*
****************************************************************/
#define CTC_DMA_LEARN_PROC_NUM       16
#define CTC_DMA_PKT_CRC_LEN          4              /**< [GB.GG]length of CRC of packet */
#define CTC_DMA_PKT_RX_CHAN_NUM      4         /**< [GB.GG]max packet rx channel number */

enum ctc_dma_direction_e
{
    CTC_DMA_DIR_RX,     /**< [GB] Chip to CPU : RX or Read */
    CTC_DMA_DIR_TX      /**< [GB] CPU to Chip : TX or Write */
};
typedef enum ctc_dma_direction_e ctc_dma_direction_t;

enum ctc_dma_func_type_e
{
    CTC_DMA_FUNC_PACKET_RX,   /**<[GB.GG]DMA Packet Rx Function */
    CTC_DMA_FUNC_PACKET_TX,   /**<[GB.GG]DMA Packet Tx Function*/
    CTC_DMA_FUNC_TABLE_R,       /**<[GB]DMA Table Read Function */
    CTC_DMA_FUNC_TABLE_W,      /**<[GB]DMA Table Write Function */
    CTC_DMA_FUNC_STATS,           /**<[GB.GG]DMA Stats Function */
    CTC_DMA_FUNC_HW_LEARNING,  /**<[GB.GG]DMA Learning Function, software leaning */
    CTC_DMA_FUNC_IPFIX,           /**<[GG]DMA Ipfix Function */
    CTC_DMA_FUNC_SDC,             /**<[GG]DMA SDC Function */
    CTC_DMA_FUNC_MONITOR,     /**<[GG]DMA Monitor Function */

    CTC_DMA_FUNC_MAX
};
typedef  enum ctc_dma_func_type_e ctc_dma_func_type_t;


typedef int32 (* CTC_CALLBACK_LEARN_FUN_P)  (uint8 lchip, void* p_learn_info, uint8 entry_num);  /* ctc_l2_addr_t */

struct ctc_dma_tbl_rw_s
{
    uint32  tbl_addr;       /**<[GB] table addr */
    uint32* buffer;         /**<[GB] system buffer */

    uint16  entry_num;      /**<[GB] number of entry */
    uint16  entry_len;      /**<[GB] table entry size */

    uint8   rflag;          /**<[GB] 1:read, 0:write */
    uint8   lchip;          /**<[GB] local chip id */
    uint8   rsv[2];
};
typedef struct ctc_dma_tbl_rw_s ctc_dma_tbl_rw_t;

struct ctc_dma_chan_cfg_s
{
    uint32 desc_num;            /**<[GB.GG] number of descriptors for DMA channel */
    uint16  priority;               /**<[GB.GG] priority of DMA process sync task: linux [1,139]: [1,99] RT, [100,139] nice; vxworks [0,255]
                                              [GG]Notice: number of sync tasks for one DMA function depends on variable of priority, different priority means
                                              using different tasks, same priority means using same task */
    uint8    dmasel;              /**< [GG] 0:DmaCtl0, 1:DmaCtl1*/
    uint16    data;                  /**< [GG] special parameter for some channel, depending on function,
                                                      for packet: packet size per desc
                                                      others: useless temp
                                          */
    uint8    rsv[3];
};
typedef struct ctc_dma_chan_cfg_s ctc_dma_chan_cfg_t;

struct ctc_dma_global_cfg_s
{
    ctc_dma_chan_cfg_t  stats;      /**<[GB] number of descriptors for stats DMA */
    ctc_dma_chan_cfg_t  learning;   /**<[GB.GG] number of FDB cache entry for learning */
    ctc_dma_chan_cfg_t  ipfix;   /**< [GG]desc resource for ipfix */
    ctc_dma_chan_cfg_t  pkt_rx[CTC_DMA_PKT_RX_CHAN_NUM]; /**<[GB.GG] parameters for packet RX DMA */
    ctc_dma_chan_cfg_t  pkt_tx;  /**< [GG] parameter for packet tx DMA */

    uint16  pkt_rx_chan_num;        /**< [GB.GG] number of channels for packet RX DMA [1, 4] */
    uint16  pkt_tx_desc_num;        /**< [GB] number of descriptors for packet TX DMA */

    uint16  table_r_desc_num;       /**< [GB] number of descriptors for table read DMA */
    uint16  table_w_desc_num;       /**<[GB]number of descriptors for table write DMA */

    uint16  pkt_rx_size_per_desc;   /**< [GB]size of received pkt for every descriptor */
    uint16  func_en_bitmap;         /**< [GB.GG]indate which DMA function is enabled, refer to ctc_dma_func_type_t */
    uint8   hw_learning_sync_en;           /**< Hw learing sync enable, fdb will sync to sdk */

    uint8   mac_limit_en;           /**< [GB]Hw learing mac limit enable, fdb count will sync to sdk */

    CTC_CALLBACK_LEARN_FUN_P    learning_proc_func;  /**< [GB]Hw learning call back function */
};
typedef struct ctc_dma_global_cfg_s ctc_dma_global_cfg_t;

#ifdef __cplusplus
}
#endif

#endif  /*_CTC_DMA_H*/

