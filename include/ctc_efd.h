/**
 @file ctc_efd.h

 @author  Copyright (C) 2014 Centec Networks Inc.  All rights reserved.

 @date 2014-10-28

 @version v3.0

   This file contains all efd related data structure, enum, macro and proto.
*/

#ifndef _CTC_EFD_H
#define _CTC_EFD_H
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

#define CTC_EFD_FLOW_ID_ARRAY_MAX       64


/**
 @brief  global control type
*/
enum ctc_efd_global_control_type_e
{
    CTC_EFD_GLOBAL_MODE_TCP,               /**< [GG]Only TCP packets do EFD. value: bool*, TRUE or FALSE */
    CTC_EFD_GLOBAL_PRIORITY_EN,            /**< [GG]When enable, the elephant flow will use the configed priority. value: bool*, TRUE or FALSE */
    CTC_EFD_GLOBAL_PRIORITY,               /**< [GG]Config global priority for the elephant flow. value: <0-63> */
    CTC_EFD_GLOBAL_COLOR_EN,               /**< [GG]When enable, the elephant flow will use the configed color. value: bool*, TRUE or FALSE */
    CTC_EFD_GLOBAL_COLOR,                  /**< [GG]Config global color for the elephant flow. value: 1-red 2-yellow 3-green */
    CTC_EFD_GLOBAL_MIN_PKT_LEN,            /**< [GG]Only packet length > MIN_PKT_LEN value do EFD. value:  0-0x3fff, 0 means all packet length do EFD */
    CTC_EFD_GLOBAL_CONTROL_MAX
};
typedef enum ctc_efd_global_control_type_e ctc_efd_global_control_type_t;


/**
@brief  efd data of hardware
*/
struct ctc_efd_data_s
{
    uint16 count;                                       /**<[GG]Flow id number*/
    uint16 rsv;
    uint32 flow_id_array[CTC_EFD_FLOW_ID_ARRAY_MAX];    /**<[GG]Use array to store flow id */
};
typedef struct ctc_efd_data_s ctc_efd_data_t;

/**
@brief  callback of efd for aging
*/
typedef void (* ctc_efd_fn_t)(ctc_efd_data_t* info, void* userdata) ;  /**< [GG]Callback function to get aging flowId from DMA */


#ifdef __cplusplus
}
#endif

#endif

