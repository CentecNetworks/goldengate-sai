/**
 @file ctc_bpe.h

 @author Copyright (C) 2011 Centec Networks Inc.  All rights reserved.

 @date 2013-05-28

 @version v2.0

This file contains all bpe related data structure, enum, macro and proto.

*/
#ifndef _CTC_BPE_H
#define _CTC_BPE_H
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

/**
 @defgroup bpe BPE
 @{
*/
/****************************************************************
*
* Defines and Macros
*
****************************************************************/
/**
 @brief  Define the mode of bpe group
*/

#define CTC_BPE_ETAG_TPID  0x893F
#define CTC_BPE_EVB_TPID   0x8100

enum ctc_bpe_intlk_mode_e
{
    CTC_BPE_INTLK_PKT_MODE = 0,    /**< [GB] Interlaken use pkt mode */
    CTC_BPE_INTLK_SEGMENT_MODE,    /**< [GB] Interlaken use segment mode */
    CTC_BPE_INTLK_MAX_MODE         /**< [GB] Max interlaken mode */
};
typedef enum ctc_bpe_intlk_mode_e  ctc_bpe_intlk_mode_t;

/**
 @brief bpe global config information
*/
struct ctc_bpe_global_cfg_s
{
    uint8   intlk_mode;       /**< [GB] ctc_bpe_intlk_mode_t */
    uint8   is_port_extender; /**< [GG] If set,indicate it is a 802.1 BR PE */
    uint16  max_uc_ecid_id;   /**< [GG] PE support the max number of ucast's ECID */

    uint16  max_mc_ecid_id;   /**< [GG] PE support the max number of mcast's ECID */
    uint16   port_base;        /**< [GG] EVB, 802.2BR and mux/demux's port base */
    uint8  rsv;
};
typedef struct ctc_bpe_global_cfg_s  ctc_bpe_global_cfg_t;

/**
 @brief bpe port extender type
*/
enum ctc_bpe_externder_mode_s
{
    CTC_BPE_MUX_DEMUX_MODE,     /**< [GB][GG] Mux/Demux */
    CTC_BPE_8021QBG_M_VEPA,     /**< [GG] Multi-channel VEPA */
    CTC_BPE_8021BR_CB_CASCADE,  /**< [GG] Cascade port of CB */
    CTC_BPE_8021BR_PE_CASCADE,  /**< [GG] Cascade port of PE */
    CTC_BPE_8021BR_EXTENDED,    /**< [GG] Extended port of PE */
    CTC_BPE_8021BR_UPSTREAM,    /**< [GG] Upstream port of PE */
    CTC_BPE_MAX_EXTERNDER_MODE
};
typedef enum ctc_bpe_externder_mode_s  ctc_bpe_externder_mode_t;

/**
 @brief bpe port mux/demux config information
*/
struct ctc_bpe_extender_s
{
    uint8  mode;            /**< [GB.GG] ctc_bpe_externder_mode_t */
    uint8  port_num;        /**< [GB.GG] Port extender number on the physical port */
    uint16 vlan_base;       /**< [GB.GG] Vlan base in mux/demux ,E-VID base in 802.1qbg, E-CID base in 802.1br */

    uint16 port_base;       /**< [GB.GG] The lport base */
    uint8  enable;          /**< [GB.GG] Enable */
    uint8  rsv;
};
typedef struct ctc_bpe_extender_s ctc_bpe_extender_t;

/**
@} end of @defgroup   bpe BPE */

#ifdef __cplusplus
}
#endif

#endif
