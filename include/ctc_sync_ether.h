/**
 @file ctc_sync_ether.h

 @author  Copyright(C) 2005-2010 Centec Networks Inc.  All rights reserved.

 @date 2009-12-15

 @version v2.0

   This file contains all stats related data structure, enum, macro and proto.
*/

/****************************************************************
*
* Defines and Macros
*
****************************************************************/

#ifndef _CTC_SYNC_ETHER_H
#define _CTC_SYNC_ETHER_H
#ifdef __cplusplus
extern "C" {
#endif

#include "sal_types.h"
#include "ctc_const.h"

struct ctc_sync_ether_cfg_s
{
    uint8  divider;                    /**< [HB.GB.GG] clock divider, GB: <0-63>, GG: <0-31>*/
    uint8  link_status_detect_en;    /**< [GB.GG] indicate whether detect link status, and the clock will not output
                                             when link down if enable detect link status*/
    uint8  clock_output_en;           /**< [HB.GB.GG] 1: output enable, 0: output disable */
    uint8  rsv0;
    uint16  recovered_clock_lport;    /**< [HB.GB.GG] local port ID, clock recovered from the port */
    uint8  rsv1[2];
};
typedef struct ctc_sync_ether_cfg_s ctc_sync_ether_cfg_t;

#ifdef __cplusplus
}
#endif

#endif

