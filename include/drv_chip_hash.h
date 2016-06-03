/****************************************************************************
 * drv_chip_hash.h  Provides driver chip hash handle function declaration.
 *
 * Copyright (C) 2011 Centec Networks Inc.  All rights reserved.
 *
 * Vision:      V4.1.1
 * Author       XuZx.
 * Date:        2011-7-7.
 * Reason:      Sync for GreatBelt 4.2.1
 *
 * Modify History:
 *
 ****************************************************************************/
#ifndef _DRV_CHIP_HASH_H_
#define _DRV_CHIP_HASH_H_

#include "sal.h"
#include "drv_lib.h"

extern int32
drv_chip_hash_lookup(lookup_info_t*, lookup_result_t*);

extern int32
drv_chip_fdb_acceleration(lookup_info_t*, uint8, uint8, lookup_result_t*);

#endif

