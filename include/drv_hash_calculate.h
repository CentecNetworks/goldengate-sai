/****************************************************************************
 * drv_hash_calculate.h  Provides driver hash calculate function declaration.
 *
 * Copyright (C) 2012 Centec Networks Inc.  All rights reserved.

 * Modify History:
 * Revision:    V1.0.
 * Author:      JiangSZ
 * Date:        2012-11-27.
 * Reason:      Create for goldenGate V1.0.
 *
 ****************************************************************************/
#ifndef _DRV_HASH_CALCULATE_H_
#define _DRV_HASH_CALCULATE_H_

#include "sal.h"

extern uint32
hash_crc(uint32 seed, uint8 *data, uint32 bit_len, uint32 poly, uint32 poly_len);

extern uint16
hash_xor16(uint16* data, uint32 data_length);

uint8
hash_xor8(uint8* data, uint32 bit_len);

#endif

