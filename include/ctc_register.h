/**
 @file ctc_register.h

 @author  Copyright (C) 2011 Centec Networks Inc.  All rights reserved.

 @date 2011-7-26

 @version v2.0

   This file contains all register related data structure, enum, macro and proto.
*/

#ifndef _CTC_REGISTER_H
#define _CTC_REGISTER_H
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
 @brief  global control type
*/
enum ctc_global_control_type_e
{
    CTC_GLOBAL_DISCARD_SAME_MACDASA_PKT = 0,   /**< [GB.GG]value: bool*, TRUE or FALSE */
    CTC_GLOBAL_DISCARD_SAME_IPDASA_PKT,        /**< [GB.GG]value: bool*, TRUE or FALSE */

    CTC_GLOBAL_DISCARD_TTL_0_PKT,              /**< [GB.GG]value: bool*, TRUE or FALSE */
    CTC_GLOBAL_DISCARD_MCAST_SA_PKT,           /**< [GB.GG]value: bool*, TRUE or FALSE */

    CTC_GLOBAL_SERVICE_POLICER_NUM,            /**< [HB]Global service policer num */
    CTC_GLOBAL_SUPPORT_PHB,                    /**< value: bool*, TRUE or FALSE */
    CTC_GLOBAL_ACL_CHANGE_COS_ONLY,  /**< [GG]acl vlan edit actioin only change cos, value: bool*, TRUE or FALSE */
    CTC_GLOBAL_CONTROL_MAX
};
typedef enum ctc_global_control_type_e ctc_global_control_type_t;

#ifdef __cplusplus
}
#endif

#endif

