/**
  @file drv_tbl_reg.h

  @date 2010-07-22

  @version v5.1

  The file implement driver IOCTL defines and macros
*/

#ifndef _DRV_TBL_REG_H_
#define _DRV_TBL_REG_H_

#include "drv_common.h"
#include "drv_register.h"

#include "drv_enum.h"

/**********************************************************************************
              Define Typedef, define and Data Structure
***********************************************************************************/
#define DRV_BYTES_PER_ENTRY 12        /* 12 bytes per entry for 80 bits*/
#define DRV_LPM_KEY_BYTES_PER_ENTRY 8        /* 8 bytes per entry for 40 bits */
#define DRV_LPM_AD0_BYTE_PER_ENTRY 8        /* IP prefix LPM AD 2W */
#define DRV_LPM_AD1_BYTE_PER_ENTRY 4        /* NAT prefix LPM AD 1W */
#define DRV_ADDR_BYTES_PER_ENTRY 16   /* 16 bytes address per entry for 80 bits*/
#define DRV_BYTES_PER_WORD 4
#define DRV_BITS_PER_WORD 32
#define DRV_WORDS_PER_ENTRY (DRV_BYTES_PER_ENTRY/DRV_BYTES_PER_WORD)  /* 3 words per entry for 80 bits*/
#define DRV_LPM_WORDS_PER_ENTRY (DRV_LPM_KEY_BYTES_PER_ENTRY/DRV_BYTES_PER_WORD)  /* 2 words per entry for 40 bits*/

#define DRV_MAX_ADDR_ENTRY_NUM 3
#define DRV_MAX_ARRAY_NUM 64

#define DRV_ENTRYS_PER_TCAM_BLOCK 512
#define DRV_MAX_TCAM_BLOCK_NUM 16
#define DRV_ACL_TCAM_BLOCK_NUM 4 /* blocks reserved for ACL keys */
#define DRV_ACL_TCAM_ENTRY_NUM (DRV_ACL_TCAM_BLOCK_NUM*DRV_ENTRYS_PER_TCAM_BLOCK)

#define DRV_ACL_TCAM_640_OFFSET_IDX  (2*1024)

/* All the following asic mem base is not determined, shall refer to asic design */

#define MAX_MEMORY_BLOCK_NUM 18
#define LM_EXT_BLOCK_NUM 0
#define MAX_DRV_BLOCK_NUM (MAX_MEMORY_BLOCK_NUM + LM_EXT_BLOCK_NUM)
#define ADDR_OFFSET 3

#define MAX_NOR_TCAM_NUM 7
#define MAX_LPM_TCAM_NUM 2
#define MAX_DRV_TCAM_BLOCK_NUM (MAX_NOR_TCAM_NUM + MAX_LPM_TCAM_NUM)

#define MAX_SHARE_TABLE_IN_ONE_MEMORY_BLOCK 8

enum cm_chip_mem_id_e
{
    CM_SHARE_RAM0,
    CM_SHARE_RAM1,
    CM_SHARE_RAM2,
    CM_SHARE_RAM3,
    CM_SHARE_RAM4,
    CM_SHARE_RAM5,
    CM_SHARE_RAM6,

    CM_DS_IPMAC_RAM0,
    CM_DS_IPMAC_RAM1,
    CM_DS_IPMAC_RAM2,
    CM_DS_IPMAC_RAM3,

    CM_USERIDHASHKEY_RAM0,
    CM_USERIDHASHKEY_RAM1,
    CM_USERIDHASHAD_RAM,

    CM_L23EDITRAM0,
    CM_L23EDITRAM1,

    CM_NEXTHOPMET_RAM0,
    CM_NEXTHOPMET_RAM1,

    //CM_DSFWD_RAM,

    CM_STATS_RAM,

    CM_POLICERCOUNTERRAM0,
    CM_POLICERCOUNTERRAM1,

    CM_TCAM_KEY0,
    CM_TCAM_KEY1,
    CM_TCAM_KEY2,
    CM_TCAM_KEY3,
    CM_TCAM_KEY4,
    CM_TCAM_KEY5,
    CM_TCAM_KEY6,

    CM_TCAM_AD0,
    CM_TCAM_AD1,
    CM_TCAM_AD2,
    CM_TCAM_AD3,
    CM_TCAM_AD4,
    CM_TCAM_AD5,
    CM_TCAM_AD6,

    CM_LPM_TCAM_KEY0,
    CM_LPM_TCAM_KEY1,

    CM_LPM_TCAM_KEY4,

    CM_LPM_TCAM_AD0,
    CM_LPM_TCAM_AD1,

    CM_MAX_MEM_CHIP_ID,
};
typedef enum cm_chip_mem_id_e cm_chip_mem_id_t;


#define DYNAMIC_PP_HASH_BLOCK_SHIFT 20
#define DYNAMIC_PP_AD_BLOCK_SHIFT 21
#define DYNAMIC_L2L3_BLOCK_SHIFT 20

/* 3W address base */
#define DYNAMIC_PP_HASH_BASE 0x8d000000
#define DYNAMIC_PP_AD_BASE 0x94000000
#define DYNAMIC_L2L3_BASE 0x01800000

/*SDK Modify {*/
#define DYNAMIC_SLICE0_ADDR_BASE_OFFSET_TO_DUP 0x60000000
#define DYNAMIC_SLICE1_ADDR_BASE_OFFSET_TO_DUP 0x40000000
/*SDK Modify }*/

#define DRV_SHARE_RAM0_BASE_4W  (DYNAMIC_PP_HASH_BASE+(CM_SHARE_RAM0<<DYNAMIC_PP_HASH_BLOCK_SHIFT))
#define DRV_SHARE_RAM1_BASE_4W  (DYNAMIC_PP_HASH_BASE+(CM_SHARE_RAM1<<DYNAMIC_PP_HASH_BLOCK_SHIFT))
#define DRV_SHARE_RAM2_BASE_4W  (DYNAMIC_PP_HASH_BASE+(CM_SHARE_RAM2<<DYNAMIC_PP_HASH_BLOCK_SHIFT))
#define DRV_SHARE_RAM3_BASE_4W  (DYNAMIC_PP_HASH_BASE+(CM_SHARE_RAM3<<DYNAMIC_PP_HASH_BLOCK_SHIFT))
#define DRV_SHARE_RAM4_BASE_4W  (DYNAMIC_PP_HASH_BASE+(CM_SHARE_RAM4<<DYNAMIC_PP_HASH_BLOCK_SHIFT))
#define DRV_SHARE_RAM5_BASE_4W  (DYNAMIC_PP_HASH_BASE+(CM_SHARE_RAM5<<DYNAMIC_PP_HASH_BLOCK_SHIFT))
#define DRV_SHARE_RAM6_BASE_4W  (DYNAMIC_PP_HASH_BASE+(CM_SHARE_RAM6<<DYNAMIC_PP_HASH_BLOCK_SHIFT))

#define DRV_DS_IPMAC_RAM0_BASE_4W   (DYNAMIC_PP_AD_BASE+((CM_DS_IPMAC_RAM0-7)<<DYNAMIC_PP_AD_BLOCK_SHIFT))
#define DRV_DS_IPMAC_RAM1_BASE_4W   (DYNAMIC_PP_AD_BASE+((CM_DS_IPMAC_RAM1-7)<<DYNAMIC_PP_AD_BLOCK_SHIFT))
#define DRV_DS_IPMAC_RAM2_BASE_4W   (DYNAMIC_PP_AD_BASE+((CM_DS_IPMAC_RAM2-7)<<DYNAMIC_PP_AD_BLOCK_SHIFT))
#define DRV_DS_IPMAC_RAM3_BASE_4W   (DYNAMIC_PP_AD_BASE+((CM_DS_IPMAC_RAM3-7)<<DYNAMIC_PP_AD_BLOCK_SHIFT))

#define DRV_USERIDHASHKEY_RAM0_BASE_4W  (DYNAMIC_PP_HASH_BASE+((CM_USERIDHASHKEY_RAM0-4)<<DYNAMIC_PP_HASH_BLOCK_SHIFT))
#define DRV_USERIDHASHKEY_RAM1_BASE_4W  (DYNAMIC_PP_HASH_BASE+((CM_USERIDHASHKEY_RAM1-4)<<DYNAMIC_PP_HASH_BLOCK_SHIFT))
#define DRV_USERIDHASHAD_RAM_BASE_4W    (DYNAMIC_PP_HASH_BASE+((CM_USERIDHASHAD_RAM-4)<<DYNAMIC_PP_HASH_BLOCK_SHIFT))

#define DRV_L23EDITRAM0_BASE_4W     (DYNAMIC_L2L3_BASE+((CM_L23EDITRAM0-14)<<DYNAMIC_L2L3_BLOCK_SHIFT))
#define DRV_L23EDITRAM1_BASE_4W     (DYNAMIC_L2L3_BASE+((CM_L23EDITRAM1-14)<<DYNAMIC_L2L3_BLOCK_SHIFT))

#define DRV_NEXTHOPMET_RAM0_BASE_4W     (DYNAMIC_PP_AD_BASE+((CM_NEXTHOPMET_RAM0-12)<<DYNAMIC_PP_AD_BLOCK_SHIFT))
#define DRV_NEXTHOPMET_RAM1_BASE_4W     (DYNAMIC_PP_AD_BASE+((CM_NEXTHOPMET_RAM1-12)<<DYNAMIC_PP_AD_BLOCK_SHIFT))

//#define DRV_DSFWD_RAM_BASE_4W           (DRV_NEXTHOPMET_RAM1_BASE_4W+DRV_NEXTHOPMET_RAM1_MAX_ENTRY_NUM*DRV_ADDR_BYTES_PER_ENTRY)

#define DRV_STATS_RAM_BASE_4W           (DRV_NEXTHOPMET_RAM1_BASE_4W+DRV_NEXTHOPMET_RAM1_MAX_ENTRY_NUM*DRV_ADDR_BYTES_PER_ENTRY)

#define DRV_POLICERCOUNTERRAM0_BASE_4W  (DRV_STATS_RAM_BASE_4W+DRV_STATS_RAM_MAX_ENTRY_NUM*DRV_ADDR_BYTES_PER_ENTRY)
#define DRV_POLICERCOUNTERRAM1_BASE_4W  (DRV_POLICERCOUNTERRAM0_BASE_4W+DRV_POLICERCOUNTERRAM0_MAX_ENTRY_NUM*DRV_ADDR_BYTES_PER_ENTRY)


/* 6W address base */
#define DYNAMIC_PP_HASH_BASE_6W 0x8e000000
#define DYNAMIC_PP_AD_BASE_6W 0x96000000
#define DYNAMIC_L2L3_BASE_6W 0x01a00000

#define DRV_SHARE_RAM0_BASE_6W  (DYNAMIC_PP_HASH_BASE_6W+(CM_SHARE_RAM0<<DYNAMIC_PP_HASH_BLOCK_SHIFT))
#define DRV_SHARE_RAM1_BASE_6W  (DYNAMIC_PP_HASH_BASE_6W+(CM_SHARE_RAM1<<DYNAMIC_PP_HASH_BLOCK_SHIFT))
#define DRV_SHARE_RAM2_BASE_6W  (DYNAMIC_PP_HASH_BASE_6W+(CM_SHARE_RAM2<<DYNAMIC_PP_HASH_BLOCK_SHIFT))
#define DRV_SHARE_RAM3_BASE_6W  (DYNAMIC_PP_HASH_BASE_6W+(CM_SHARE_RAM3<<DYNAMIC_PP_HASH_BLOCK_SHIFT))
#define DRV_SHARE_RAM4_BASE_6W  (DYNAMIC_PP_HASH_BASE_6W+(CM_SHARE_RAM4<<DYNAMIC_PP_HASH_BLOCK_SHIFT))
#define DRV_SHARE_RAM5_BASE_6W  (DYNAMIC_PP_HASH_BASE_6W+(CM_SHARE_RAM5<<DYNAMIC_PP_HASH_BLOCK_SHIFT))
#define DRV_SHARE_RAM6_BASE_6W  (DYNAMIC_PP_HASH_BASE_6W+(CM_SHARE_RAM6<<DYNAMIC_PP_HASH_BLOCK_SHIFT))

#define DRV_DS_IPMAC_RAM0_BASE_6W   (DYNAMIC_PP_AD_BASE_6W+((CM_DS_IPMAC_RAM0-7)<<DYNAMIC_PP_AD_BLOCK_SHIFT))
#define DRV_DS_IPMAC_RAM1_BASE_6W   (DYNAMIC_PP_AD_BASE_6W+((CM_DS_IPMAC_RAM1-7)<<DYNAMIC_PP_AD_BLOCK_SHIFT))
#define DRV_DS_IPMAC_RAM2_BASE_6W   (DYNAMIC_PP_AD_BASE_6W+((CM_DS_IPMAC_RAM2-7)<<DYNAMIC_PP_AD_BLOCK_SHIFT))
#define DRV_DS_IPMAC_RAM3_BASE_6W   (DYNAMIC_PP_AD_BASE_6W+((CM_DS_IPMAC_RAM3-7)<<DYNAMIC_PP_AD_BLOCK_SHIFT))

#define DRV_USERIDHASHKEY_RAM0_BASE_6W  (DYNAMIC_PP_HASH_BASE_6W+((CM_USERIDHASHKEY_RAM0-4)<<DYNAMIC_PP_HASH_BLOCK_SHIFT))
#define DRV_USERIDHASHKEY_RAM1_BASE_6W  (DYNAMIC_PP_HASH_BASE_6W+((CM_USERIDHASHKEY_RAM1-4)<<DYNAMIC_PP_HASH_BLOCK_SHIFT))
#define DRV_USERIDHASHAD_RAM_BASE_6W    (DYNAMIC_PP_HASH_BASE_6W+((CM_USERIDHASHAD_RAM-4)<<DYNAMIC_PP_HASH_BLOCK_SHIFT))

#define DRV_NEXTHOPMET_RAM0_BASE_6W     (DYNAMIC_PP_AD_BASE_6W+((CM_NEXTHOPMET_RAM0-12)<<DYNAMIC_PP_AD_BLOCK_SHIFT))
#define DRV_NEXTHOPMET_RAM1_BASE_6W     (DYNAMIC_PP_AD_BASE_6W+((CM_NEXTHOPMET_RAM1-12)<<DYNAMIC_PP_AD_BLOCK_SHIFT))

#define DRV_L23EDITRAM0_BASE_6W     (DYNAMIC_L2L3_BASE_6W+((CM_L23EDITRAM0-14)<<DYNAMIC_L2L3_BLOCK_SHIFT))
#define DRV_L23EDITRAM1_BASE_6W     (DYNAMIC_L2L3_BASE_6W+((CM_L23EDITRAM1-14)<<DYNAMIC_L2L3_BLOCK_SHIFT))

#define DRV_STATS_RAM_BASE_6W           (DRV_NEXTHOPMET_RAM1_BASE_6W+DRV_NEXTHOPMET_RAM1_MAX_ENTRY_NUM*DRV_ADDR_BYTES_PER_ENTRY)

#define DRV_POLICERCOUNTERRAM0_BASE_6W  (DRV_STATS_RAM_BASE_6W+DRV_STATS_RAM_MAX_ENTRY_NUM*DRV_ADDR_BYTES_PER_ENTRY)
#define DRV_POLICERCOUNTERRAM1_BASE_6W  (DRV_POLICERCOUNTERRAM0_BASE_6W+DRV_POLICERCOUNTERRAM0_MAX_ENTRY_NUM*DRV_ADDR_BYTES_PER_ENTRY)

/* 12W address base */
#define DYNAMIC_PP_HASH_BASE_12W 0x8c000000
#define DYNAMIC_PP_AD_BASE_12W 0x95000000
#define DYNAMIC_L2L3_BASE_12W 0x01c00000

#define DRV_SHARE_RAM0_BASE_12W  (DYNAMIC_PP_HASH_BASE_12W+(CM_SHARE_RAM0<<DYNAMIC_PP_HASH_BLOCK_SHIFT))
#define DRV_SHARE_RAM1_BASE_12W  (DYNAMIC_PP_HASH_BASE_12W+(CM_SHARE_RAM1<<DYNAMIC_PP_HASH_BLOCK_SHIFT))
#define DRV_SHARE_RAM2_BASE_12W  (DYNAMIC_PP_HASH_BASE_12W+(CM_SHARE_RAM2<<DYNAMIC_PP_HASH_BLOCK_SHIFT))
#define DRV_SHARE_RAM3_BASE_12W  (DYNAMIC_PP_HASH_BASE_12W+(CM_SHARE_RAM3<<DYNAMIC_PP_HASH_BLOCK_SHIFT))
#define DRV_SHARE_RAM4_BASE_12W  (DYNAMIC_PP_HASH_BASE_12W+(CM_SHARE_RAM4<<DYNAMIC_PP_HASH_BLOCK_SHIFT))
#define DRV_SHARE_RAM5_BASE_12W  (DYNAMIC_PP_HASH_BASE_12W+(CM_SHARE_RAM5<<DYNAMIC_PP_HASH_BLOCK_SHIFT))
#define DRV_SHARE_RAM6_BASE_12W  (DYNAMIC_PP_HASH_BASE_12W+(CM_SHARE_RAM6<<DYNAMIC_PP_HASH_BLOCK_SHIFT))

#define DRV_DS_IPMAC_RAM0_BASE_12W   (DYNAMIC_PP_AD_BASE_12W+((CM_DS_IPMAC_RAM0-7)<<DYNAMIC_PP_AD_BLOCK_SHIFT))
#define DRV_DS_IPMAC_RAM1_BASE_12W   (DYNAMIC_PP_AD_BASE_12W+((CM_DS_IPMAC_RAM1-7)<<DYNAMIC_PP_AD_BLOCK_SHIFT))
#define DRV_DS_IPMAC_RAM2_BASE_12W   (DYNAMIC_PP_AD_BASE_12W+((CM_DS_IPMAC_RAM2-7)<<DYNAMIC_PP_AD_BLOCK_SHIFT))
#define DRV_DS_IPMAC_RAM3_BASE_12W   (DYNAMIC_PP_AD_BASE_12W+((CM_DS_IPMAC_RAM3-7)<<DYNAMIC_PP_AD_BLOCK_SHIFT))

#define DRV_USERIDHASHKEY_RAM0_BASE_12W  (DYNAMIC_PP_HASH_BASE_12W+((CM_USERIDHASHKEY_RAM0-4)<<DYNAMIC_PP_HASH_BLOCK_SHIFT))
#define DRV_USERIDHASHKEY_RAM1_BASE_12W  (DYNAMIC_PP_HASH_BASE_12W+((CM_USERIDHASHKEY_RAM1-4)<<DYNAMIC_PP_HASH_BLOCK_SHIFT))
#define DRV_USERIDHASHAD_RAM_BASE_12W    (DYNAMIC_PP_HASH_BASE_12W+((CM_USERIDHASHAD_RAM-4)<<DYNAMIC_PP_HASH_BLOCK_SHIFT))

#define DRV_NEXTHOPMET_RAM0_BASE_12W     (DYNAMIC_PP_AD_BASE_12W+((CM_NEXTHOPMET_RAM0-12)<<DYNAMIC_PP_AD_BLOCK_SHIFT))
#define DRV_NEXTHOPMET_RAM1_BASE_12W     (DYNAMIC_PP_AD_BASE_12W+((CM_NEXTHOPMET_RAM1-12)<<DYNAMIC_PP_AD_BLOCK_SHIFT))

#define DRV_L23EDITRAM0_BASE_12W     (DYNAMIC_L2L3_BASE_12W+((CM_L23EDITRAM0-14)<<DYNAMIC_L2L3_BLOCK_SHIFT))
#define DRV_L23EDITRAM1_BASE_12W     (DYNAMIC_L2L3_BASE_12W+((CM_L23EDITRAM1-14)<<DYNAMIC_L2L3_BLOCK_SHIFT))

#define DRV_STATS_RAM_BASE_12W           (DRV_NEXTHOPMET_RAM1_BASE_12W+DRV_NEXTHOPMET_RAM1_MAX_ENTRY_NUM*DRV_ADDR_BYTES_PER_ENTRY)

#define DRV_POLICERCOUNTERRAM0_BASE_12W  (DRV_STATS_RAM_BASE_12W+DRV_STATS_RAM_MAX_ENTRY_NUM*DRV_ADDR_BYTES_PER_ENTRY)
#define DRV_POLICERCOUNTERRAM1_BASE_12W  (DRV_POLICERCOUNTERRAM0_BASE_12W+DRV_POLICERCOUNTERRAM0_MAX_ENTRY_NUM*DRV_ADDR_BYTES_PER_ENTRY)


#define DRV_SHARE_RAM_INVALID_ENTRY_NUM             0xFFFFFFFF  /* invalid entry num */
/* Entry num is based on 72/80 bits, whatever the mem type */

#define DRV_SHARE_RAM0_MAX_ENTRY_NUM                (8*4*1024)  /* 2*8k(342+10) */
#define DRV_SHARE_RAM1_MAX_ENTRY_NUM                (8*4*1024)  /* 2*8k(342+10) */
#define DRV_SHARE_RAM2_MAX_ENTRY_NUM                (8*4*1024)  /* 2*8k(342+10) */
#define DRV_SHARE_RAM3_MAX_ENTRY_NUM                (8*4*1024)  /* 2*8k(342+10) */
#define DRV_SHARE_RAM4_MAX_ENTRY_NUM                (2*4*1024)  /* 2*2k(342+10) */
#define DRV_SHARE_RAM5_MAX_ENTRY_NUM                (4*4*1024)  /* 2*4k(342+10) */
#define DRV_SHARE_RAM6_MAX_ENTRY_NUM                (4*4*1024)  /* 2*4k(342+10) */

#define DRV_DS_IPMAC_RAM0_MAX_ENTRY_NUM             (8*4*1024)  /* 2*8k(326+10) */
#define DRV_DS_IPMAC_RAM1_MAX_ENTRY_NUM             (4*4*1024)  /* 2*4k(326+10) */
#define DRV_DS_IPMAC_RAM2_MAX_ENTRY_NUM             (4*4*1024)  /* 2*4k(326+10) */
#define DRV_DS_IPMAC_RAM3_MAX_ENTRY_NUM             (4*4*1024)  /* 2*4k(326+10) */

#define DRV_USERIDHASHKEY_RAM0_MAX_ENTRY_NUM        (2*4*1024)  /* 2*2k(342+10) */
#define DRV_USERIDHASHKEY_RAM1_MAX_ENTRY_NUM        (2*4*1024)  /* 2*2k(342+10) */
#define DRV_USERIDHASHAD_RAM_MAX_ENTRY_NUM          (16*2*1024)  /* 2*16k(167+9) */

#define DRV_L23EDITRAM0_MAX_ENTRY_NUM               (5*4*1024)  /* 2*6k(342+10) */
#define DRV_L23EDITRAM1_MAX_ENTRY_NUM               (4*4*1024)  /* 2*4k(342+10) */

#define DRV_NEXTHOPMET_RAM0_MAX_ENTRY_NUM           (12*4*1024)  /* 2*12k(326+10) */
#define DRV_NEXTHOPMET_RAM1_MAX_ENTRY_NUM           (8*4*1024)  /* 2*8k(326+10) */

//#define DRV_DSFWD_RAM_MAX_ENTRY_NUM                 (10*1024)  /* 10k(88+8) */

#define DRV_STATS_RAM_MAX_ENTRY_NUM                 (32*1024)  /* 32k(72+8) */

#define DRV_POLICERCOUNTERRAM0_MAX_ENTRY_NUM        (1*2*1024)  /* 1k(153+?) */
#define DRV_POLICERCOUNTERRAM1_MAX_ENTRY_NUM        (1*4*1024)  /* 1k(216+?) */

/* FLOW TCAM */
#define DRV_TCAM_COUPLE_MODE_BASE_NUM              (21*1024) /* 10.5*2*1024 */

#define DRV_TCAM_KEY0_MAX_ENTRY_NUM                 (128*2*4)  /* 2*128(320) */
#define DRV_TCAM_KEY1_MAX_ENTRY_NUM                 (128*2*4)  /* 2*128(320) */
#define DRV_TCAM_KEY2_MAX_ENTRY_NUM                 (128*2*4)  /* 2*128(320) */
#define DRV_TCAM_KEY3_MAX_ENTRY_NUM                 (128*2*4)  /* 2*128(320) */
#define DRV_TCAM_KEY4_MAX_ENTRY_NUM                 (128*2*4)  /* 2*128(320) */
#define DRV_TCAM_KEY5_MAX_ENTRY_NUM                 (1024*2*4)  /* 2*1024(320) */
#define DRV_TCAM_KEY6_MAX_ENTRY_NUM                 (1024*2*4)  /* 2*1024(320) */

#define DRV_TCAM_AD0_MAX_ENTRY_NUM                  (512*2)  /* 512(167+9) */
#define DRV_TCAM_AD1_MAX_ENTRY_NUM                  (512*2)  /* 512(167+9) */
#define DRV_TCAM_AD2_MAX_ENTRY_NUM                  (512*2)  /* 512(167+9) */
#define DRV_TCAM_AD3_MAX_ENTRY_NUM                  (512*2)  /* 512(167+9) */
#define DRV_TCAM_AD4_MAX_ENTRY_NUM                  (512*2)  /* 512(167+9) */
#define DRV_TCAM_AD5_MAX_ENTRY_NUM                  (4*1024*2)  /* 4k(167+9) */
#define DRV_TCAM_AD6_MAX_ENTRY_NUM                  (4*1024*2)  /* 4k(167+9) */

#define DRV_LPM_TCAM_KEY0_MAX_ENTRY_NUM             (4*1024*2)  /* 2*2k(98) 49 bit unit */
#define DRV_LPM_TCAM_KEY1_MAX_ENTRY_NUM             (256*2*2)     /* 256(360) 85 bit unit */

#define DRV_LPM_TCAM_AD0_MAX_ENTRY_NUM              (8*1024)  /* 8k(49+?) 49 bit unit */
#define DRV_LPM_TCAM_AD1_MAX_ENTRY_NUM              (512)     /* 512(18+?) 18 bit unit */

#define DRV_TCAM_KEY_BASE_ADDR 0xa0000000
#define DRV_TCAM_AD_BASE_ADDR 0xa0800000
#define DRV_TCAM_MASK_BASE_ADDR 0xa0400000

#define DRV_TCAM_KEY0_BASE_4W   DRV_TCAM_KEY_BASE_ADDR
#define DRV_TCAM_KEY1_BASE_4W   DRV_TCAM_KEY0_BASE_4W + DRV_TCAM_KEY0_MAX_ENTRY_NUM*DRV_ADDR_BYTES_PER_ENTRY
#define DRV_TCAM_KEY2_BASE_4W   DRV_TCAM_KEY1_BASE_4W + DRV_TCAM_KEY1_MAX_ENTRY_NUM*DRV_ADDR_BYTES_PER_ENTRY
#define DRV_TCAM_KEY3_BASE_4W   DRV_TCAM_KEY2_BASE_4W + DRV_TCAM_KEY2_MAX_ENTRY_NUM*DRV_ADDR_BYTES_PER_ENTRY
#define DRV_TCAM_KEY4_BASE_4W   DRV_TCAM_KEY3_BASE_4W + DRV_TCAM_KEY3_MAX_ENTRY_NUM*DRV_ADDR_BYTES_PER_ENTRY
#define DRV_TCAM_KEY5_BASE_4W   DRV_TCAM_KEY4_BASE_4W + DRV_TCAM_KEY4_MAX_ENTRY_NUM*DRV_ADDR_BYTES_PER_ENTRY
#define DRV_TCAM_KEY6_BASE_4W   DRV_TCAM_KEY5_BASE_4W + DRV_TCAM_KEY5_MAX_ENTRY_NUM*DRV_ADDR_BYTES_PER_ENTRY

#define DRV_TCAM_AD0_BASE_4W    DRV_TCAM_AD_BASE_ADDR
#define DRV_TCAM_AD1_BASE_4W    DRV_TCAM_AD0_BASE_4W + DRV_TCAM_AD0_MAX_ENTRY_NUM*DRV_ADDR_BYTES_PER_ENTRY
#define DRV_TCAM_AD2_BASE_4W    DRV_TCAM_AD1_BASE_4W + DRV_TCAM_AD1_MAX_ENTRY_NUM*DRV_ADDR_BYTES_PER_ENTRY
#define DRV_TCAM_AD3_BASE_4W    DRV_TCAM_AD2_BASE_4W + DRV_TCAM_AD2_MAX_ENTRY_NUM*DRV_ADDR_BYTES_PER_ENTRY
#define DRV_TCAM_AD4_BASE_4W    DRV_TCAM_AD3_BASE_4W + DRV_TCAM_AD3_MAX_ENTRY_NUM*DRV_ADDR_BYTES_PER_ENTRY
#define DRV_TCAM_AD5_BASE_4W    DRV_TCAM_AD4_BASE_4W + DRV_TCAM_AD4_MAX_ENTRY_NUM*DRV_ADDR_BYTES_PER_ENTRY
#define DRV_TCAM_AD6_BASE_4W    DRV_TCAM_AD5_BASE_4W + DRV_TCAM_AD5_MAX_ENTRY_NUM*DRV_ADDR_BYTES_PER_ENTRY

#define DRV_TCAM_MASK0_BASE_4W   DRV_TCAM_MASK_BASE_ADDR
#define DRV_TCAM_MASK1_BASE_4W   DRV_TCAM_MASK0_BASE_4W + DRV_TCAM_KEY0_MAX_ENTRY_NUM*DRV_ADDR_BYTES_PER_ENTRY
#define DRV_TCAM_MASK2_BASE_4W   DRV_TCAM_MASK1_BASE_4W + DRV_TCAM_KEY1_MAX_ENTRY_NUM*DRV_ADDR_BYTES_PER_ENTRY
#define DRV_TCAM_MASK3_BASE_4W   DRV_TCAM_MASK2_BASE_4W + DRV_TCAM_KEY2_MAX_ENTRY_NUM*DRV_ADDR_BYTES_PER_ENTRY
#define DRV_TCAM_MASK4_BASE_4W   DRV_TCAM_MASK3_BASE_4W + DRV_TCAM_KEY3_MAX_ENTRY_NUM*DRV_ADDR_BYTES_PER_ENTRY
#define DRV_TCAM_MASK5_BASE_4W   DRV_TCAM_MASK4_BASE_4W + DRV_TCAM_KEY4_MAX_ENTRY_NUM*DRV_ADDR_BYTES_PER_ENTRY
#define DRV_TCAM_MASK6_BASE_4W   DRV_TCAM_MASK5_BASE_4W + DRV_TCAM_KEY5_MAX_ENTRY_NUM*DRV_ADDR_BYTES_PER_ENTRY

#define DRV_TCAM_KEY_MAX_ENTRY_NUM \
    (DRV_TCAM_KEY0_MAX_ENTRY_NUM + DRV_TCAM_KEY1_MAX_ENTRY_NUM + DRV_TCAM_KEY2_MAX_ENTRY_NUM + \
    DRV_TCAM_KEY3_MAX_ENTRY_NUM + DRV_TCAM_KEY4_MAX_ENTRY_NUM + DRV_TCAM_KEY5_MAX_ENTRY_NUM + \
    DRV_TCAM_KEY6_MAX_ENTRY_NUM)

#define DRV_TCAM_AD_MAX_ENTRY_NUM \
    (DRV_TCAM_AD0_MAX_ENTRY_NUM + DRV_TCAM_AD1_MAX_ENTRY_NUM + DRV_TCAM_AD2_MAX_ENTRY_NUM + \
    DRV_TCAM_AD3_MAX_ENTRY_NUM + DRV_TCAM_AD4_MAX_ENTRY_NUM + DRV_TCAM_AD5_MAX_ENTRY_NUM + \
    DRV_TCAM_AD6_MAX_ENTRY_NUM)

/* LPM TCAM */
#define DRV_LPM_IP_KEY_BASE_ADDR 0xa1800000
#define DRV_LPM_IP_AD_BASE_ADDR 0x00440000
#define DRV_LPM_IP_MASK_BASE_ADDR 0xa2800000
#define DRV_LPM_NAT_KEY_BASE_ADDR 0xa1000000
#define DRV_LPM_NAT_AD_BASE_ADDR 0x88004000
#define DRV_LPM_NAT_MASK_BASE_ADDR 0xa2000000

#define DRV_LPM_TCAM_DATA_ASIC_BASE0 DRV_LPM_IP_KEY_BASE_ADDR
#define DRV_LPM_TCAM_MASK_ASIC_BASE0 DRV_LPM_IP_MASK_BASE_ADDR
#define DRV_LPM_TCAM_DATA_ASIC_BASE1 DRV_LPM_NAT_KEY_BASE_ADDR
#define DRV_LPM_TCAM_MASK_ASIC_BASE1 DRV_LPM_NAT_MASK_BASE_ADDR
#define DRV_LPM_TCAM_MAX_ENTRY_NUM DRV_LPM_TCAM_KEY0_MAX_ENTRY_NUM
#define DRV_LPM_TCAM_NAT_MAX_ENTRY_NUM DRV_LPM_TCAM_KEY1_MAX_ENTRY_NUM

#define DRV_LPM_TCAM_AD_ASIC_BASE0 DRV_LPM_IP_AD_BASE_ADDR
#define DRV_LPM_TCAM_AD_ASIC_BASE1 DRV_LPM_NAT_AD_BASE_ADDR
#define DRV_LPM_TCAM_AD_MAX_ENTRY_NUM (DRV_LPM_TCAM_AD0_MAX_ENTRY_NUM + DRV_LPM_TCAM_AD1_MAX_ENTRY_NUM)
#define DRV_LPM_TCAM_NAT_AD_MAX_ENTRY_NUM DRV_LPM_TCAM_AD1_MAX_ENTRY_NUM

#define DRV_DYNAMIC_SRAM_MAX_ENTRY_NUM \
    (DRV_SHARE_RAM0_MAX_ENTRY_NUM+DRV_SHARE_RAM1_MAX_ENTRY_NUM+DRV_SHARE_RAM2_MAX_ENTRY_NUM+DRV_SHARE_RAM3_MAX_ENTRY_NUM+ \
    DRV_SHARE_RAM4_MAX_ENTRY_NUM+DRV_SHARE_RAM5_MAX_ENTRY_NUM+ DRV_SHARE_RAM6_MAX_ENTRY_NUM+ \
    DRV_DS_IPMAC_RAM0_MAX_ENTRY_NUM+DRV_DS_IPMAC_RAM1_MAX_ENTRY_NUM+DRV_DS_IPMAC_RAM2_MAX_ENTRY_NUM+DRV_DS_IPMAC_RAM3_MAX_ENTRY_NUM+ \
    DRV_USERIDHASHKEY_RAM0_MAX_ENTRY_NUM+DRV_USERIDHASHKEY_RAM1_MAX_ENTRY_NUM+DRV_USERIDHASHAD_RAM_MAX_ENTRY_NUM+ \
    DRV_L23EDITRAM0_MAX_ENTRY_NUM+DRV_L23EDITRAM1_MAX_ENTRY_NUM+ \
    DRV_NEXTHOPMET_RAM0_MAX_ENTRY_NUM+DRV_NEXTHOPMET_RAM1_MAX_ENTRY_NUM+ \
    DRV_STATS_RAM_MAX_ENTRY_NUM+DRV_POLICERCOUNTERRAM0_MAX_ENTRY_NUM+DRV_POLICERCOUNTERRAM1_MAX_ENTRY_NUM)

#define DRV_ADDR_IN_DYNAMIC_PP_SRAM_4W_RANGE(addr,couple_mode) \
    (((addr) >= DRV_SHARE_RAM0_BASE_4W) && ((addr) < (DRV_USERIDHASHAD_RAM_BASE_4W+(DRV_USERIDHASHAD_RAM_MAX_ENTRY_NUM << couple_mode)*DRV_ADDR_BYTES_PER_ENTRY)))

#define DRV_ADDR_IN_DYNAMIC_AD_SRAM_4W_RANGE(addr,couple_mode) \
    (((addr) >= DRV_DS_IPMAC_RAM0_BASE_4W) && ((addr) < (DRV_NEXTHOPMET_RAM1_BASE_4W+(DRV_NEXTHOPMET_RAM1_MAX_ENTRY_NUM << couple_mode)*DRV_ADDR_BYTES_PER_ENTRY)))

#define DRV_ADDR_IN_DYNAMIC_L2L3_SRAM_4W_RANGE(addr,couple_mode) \
    (((addr) >= DRV_L23EDITRAM0_BASE_4W) && ((addr) < (DRV_L23EDITRAM1_BASE_4W+(DRV_L23EDITRAM1_MAX_ENTRY_NUM << couple_mode)*DRV_ADDR_BYTES_PER_ENTRY)))

#define DRV_ADDR_IN_TCAM_DATA_RANGE(addr,couple_mode) \
    (((addr) >= DRV_TCAM_KEY0_BASE_4W) && ((addr) < DRV_TCAM_KEY0_BASE_4W+(DRV_TCAM_KEY_MAX_ENTRY_NUM << couple_mode)*DRV_ADDR_BYTES_PER_ENTRY))

#define DRV_ADDR_IN_TCAM_MASK_RANGE(addr,couple_mode) \
    (((addr) >= DRV_TCAM_MASK0_BASE_4W) && ((addr) < DRV_TCAM_MASK0_BASE_4W+(DRV_TCAM_KEY_MAX_ENTRY_NUM << couple_mode)*DRV_ADDR_BYTES_PER_ENTRY))

#define DRV_ADDR_IN_TCAMAD_SRAM_4W_RANGE(addr,couple_mode) \
    (((addr) >= DRV_TCAM_AD0_BASE_4W) && ((addr) < DRV_TCAM_AD0_BASE_4W+(DRV_TCAM_AD_MAX_ENTRY_NUM << couple_mode)*DRV_ADDR_BYTES_PER_ENTRY))

#define DRV_ADDR_IN_LPM_TCAM_DATA_RANGE(addr,couple_mode) \
    (((addr) >= DRV_LPM_TCAM_DATA_ASIC_BASE0) && ((addr) < DRV_LPM_TCAM_DATA_ASIC_BASE0+(DRV_LPM_TCAM_MAX_ENTRY_NUM << couple_mode)*DRV_LPM_KEY_BYTES_PER_ENTRY))

#define DRV_ADDR_IN_LPM_TCAM_MASK_RANGE(addr,couple_mode) \
    (((addr) >= DRV_LPM_TCAM_MASK_ASIC_BASE0) && ((addr) < DRV_LPM_TCAM_MASK_ASIC_BASE0+(DRV_LPM_TCAM_MAX_ENTRY_NUM << couple_mode)*DRV_LPM_KEY_BYTES_PER_ENTRY))

#define DRV_ADDR_IN_LPM_TCAM_AD_RANGE(addr,couple_mode) \
    (((addr) >= DRV_LPM_TCAM_AD_ASIC_BASE0) && ((addr) < DRV_LPM_TCAM_AD_ASIC_BASE0+(DRV_LPM_TCAM_AD0_MAX_ENTRY_NUM << couple_mode)*DRV_LPM_AD0_BYTE_PER_ENTRY))

#define DRV_ADDR_IN_LPM_NAT_TCAM_DATA_RANGE(addr,couple_mode) \
    (((addr) >= DRV_LPM_TCAM_DATA_ASIC_BASE1) && ((addr) < DRV_LPM_TCAM_DATA_ASIC_BASE1+(DRV_LPM_TCAM_NAT_MAX_ENTRY_NUM << couple_mode)*DRV_ADDR_BYTES_PER_ENTRY))

#define DRV_ADDR_IN_LPM_NAT_TCAM_MASK_RANGE(addr,couple_mode) \
    (((addr) >= DRV_LPM_TCAM_MASK_ASIC_BASE1) && ((addr) < DRV_LPM_TCAM_MASK_ASIC_BASE1+(DRV_LPM_TCAM_NAT_MAX_ENTRY_NUM << couple_mode)*DRV_ADDR_BYTES_PER_ENTRY))

#define DRV_ADDR_IN_LPM_NAT_TCAM_AD_RANGE(addr,couple_mode) \
    (((addr) >= DRV_LPM_TCAM_AD_ASIC_BASE1) && ((addr) < DRV_LPM_TCAM_AD_ASIC_BASE1+(DRV_LPM_TCAM_NAT_AD_MAX_ENTRY_NUM << couple_mode)*DRV_LPM_AD1_BYTE_PER_ENTRY))


#define TCAM_BITMAP_MAX_NUM 4

typedef uint32 field_array_t[DRV_MAX_ARRAY_NUM];


struct hash_lookup_bitmap_s
{
    uint32 bitmap;
    uint32 extra_mode;
};
typedef struct hash_lookup_bitmap_s hash_lookup_bitmap_t;

enum drv_tcam_lookup_e
{
    DRV_TCAM_LOOKUP1,
    DRV_TCAM_LOOKUP2,
    DRV_TCAM_LOOKUP3,
    DRV_TCAM_LOOKUP4,
    DRV_TCAM_LOOKUP_NUM
};
typedef enum drv_tcam_lookup_e drv_tcam_lookup_t;

enum drv_acl_lookup_e
{
    DRV_ACL_LOOKUP0,
    DRV_ACL_LOOKUP1,
    DRV_ACL_LOOKUP2,
    DRV_ACL_LOOKUP3,
    DRV_ACL_LOOKUP_NUM
};
typedef enum drv_acl_lookup_e drv_acl_lookup_t;


/* descriptor extended property structure */
struct entry_desc_s
{
    char desc[64];
};
typedef struct entry_desc_s entry_desc_t;

/* debug extended property structure */
struct dbg_info_s
{
    uint8 b_show;
};
typedef struct dbg_info_s dbg_info_t;

/* Tcam key memories extended property structure */
enum tcam_type_e
{
    TCAM_TYPE_ACL_USERID,
    TCAM_TYPE_LPM,
    TCAM_TYPE_INVALID,
};
typedef enum tcam_type_e tcam_type_t;


struct tcam_alloc_info_s
{
    uint32 tcam_mem_bitmap;                                             /* bitmap indicate table in which tcam memory block */
    uint32 tcam_mem_hw_data_base[MAX_DRV_TCAM_BLOCK_NUM][ADDR_OFFSET];  /* hw_data_base per memory block */
    uint32 tcam_mem_hw_mask_base[MAX_DRV_TCAM_BLOCK_NUM][ADDR_OFFSET];  /* hw_data_base per memory block */
    uint32 tcam_mem_entry_num[MAX_DRV_TCAM_BLOCK_NUM];                  /* enter num in per memory block, per 80 bit */
    uint32 tcam_mem_entry_start_index[MAX_DRV_TCAM_BLOCK_NUM];          /* global table start index in per memory block */
    uint32 tcam_mem_entry_end_index[MAX_DRV_TCAM_BLOCK_NUM];            /* global table end index in per memory bloci */
};
typedef struct tcam_alloc_info_s tcam_alloc_info_t;

struct tcam_mem_ext_content_s
{
    addrs_t *hw_mask_base;
    uint8 key_size;
    tcam_type_t tcam_type;
    tcam_alloc_info_t tcam_alloc_info;
};
typedef struct tcam_mem_ext_content_s tcam_mem_ext_content_t;


/* dynamic tbl extended property structure */
enum dynamic_mem_access_mode_u
{
    DYNAMIC_DEFAULT = 0,    /* according table entry size to decide how many 80-bits per index */
    DYNAMIC_4W_MODE,        /* per 80 bits per index */
    DYNAMIC_8W_MODE,        /* per 80 bits per index */
    DYNAMIC_16W_MODE,        /* per 80 bits per index */
    DYNAMIC_INVALID,
};
typedef enum dynamic_mem_access_mode_u dynamic_mem_access_mode_t;

struct dynamic_mem_allocate_info_s
{
    uint32 dynamic_mem_bitmap;                                          /* bitmap indicate table in which dynamic memory block */
    uint32 dynamic_mem_hw_data_base[MAX_DRV_BLOCK_NUM][ADDR_OFFSET];    /* hw_data_base per memory block */
    uint32 dynamic_mem_entry_num[MAX_DRV_BLOCK_NUM];                    /* enter num in per memory block, per 80 bit */
    uint32 dynamic_mem_entry_start_index[MAX_DRV_BLOCK_NUM];            /* global table start index in per memory block */
    uint32 dynamic_mem_entry_end_index[MAX_DRV_BLOCK_NUM];              /* global table end index in per memory bloci */
};
typedef struct dynamic_mem_allocate_info_s dynamic_mem_allocate_info_t;

struct dynamic_mem_ext_content_s
{
    dynamic_mem_allocate_info_t dynamic_mem_allocate_info;  /* store memory allocated info of table in which block */
    dynamic_mem_access_mode_t dynamic_access_mode;          /* access mode, indicate how to explain one index of table */
};
typedef struct dynamic_mem_ext_content_s dynamic_mem_ext_content_t;

#define TCAM_TYPE_EXT (tcam_mem_ext_content_t *)
#define DYNAMIC_TYPE_EXT (dynamic_mem_ext_content_t *)

/* Define get Memory infomation operation */
#define TABLE_INFO_PTR(tbl_id)             (&drv_tbls_list[tbl_id])
#define TABLE_INFO(tbl_id)                 (drv_tbls_list[tbl_id])
#define TABLE_NAME(tbl_id)                 (TABLE_INFO(tbl_id).ptr_tbl_name)
#define TABLE_ENTRY_TYPE(tbl_id)           (TABLE_INFO(tbl_id).slicetype)
#define TABLE_DATA_BASE(tbl_id, addroffset)(TABLE_INFO(tbl_id).addrs[addroffset])
#define TABLE_MAX_INDEX(tbl_id)            (TABLE_INFO(tbl_id).entry)
#define TABLE_ENTRY_SIZE(tbl_id)           (TABLE_INFO(tbl_id).word)
#define TABLE_MAX_ADDR_OFFSET(tbl_id)      ((TABLE_MAX_INDEX(tbl_id))*((TABLE_ENTRY_SIZE(tbl_id)/DRV_BYTES_PER_ENTRY*DRV_ADDR_BYTES_PER_ENTRY)))
#define TABLE_DATA_END_ADDR(tbl_id)        ((TABLE_DATA_BASE(tbl_id))+(TABLE_MAX_ADDR_OFFSET(tbl_id)))
#define TABLE_FIELD_NUM(tbl_id)            (TABLE_INFO(tbl_id).field_num)
#define TABLE_FIELD_INFO_PTR(tbl_id)       (TABLE_INFO(tbl_id).ptr_fields)
#define TABLE_EXT_INFO_PTR(tbl_id)         (TABLE_INFO(tbl_id).ptr_ext_info)
#define TABLE_EXT_INFO_TYPE(tbl_id)        (TABLE_EXT_INFO_PTR(tbl_id)->ext_content_type)
#define TABLE_EXT_INFO_CONTENT_PTR(tbl_id) (TABLE_EXT_INFO_PTR(tbl_id)->ptr_ext_content)
#define TABLE_OP_TYPE(tbl_id)           (TABLE_INFO(tbl_id).optype)

#define BURST_IO_WRITE  0x1
#define BURST_IO_READ   0x1
#define BURST_IO_MASK   0x2

//#define TABLE_FIELD_SEG_PTR(seg_id)     (TABLE_INFO(tbl_id).ptr_fields.)

#define CHK_IS_REGISTER(tbl_id)\
    ((tbl_id >= 0)&&(tbl_id < MaxTblId_t)&&(TABLE_MAX_INDEX(tbl_id) == 1))\

#define CHK_TABLE_ID_VALID(tbl_id)\
    ((tbl_id >= 0)&&(tbl_id < MaxTblId_t))\

#define CHK_FIELD_ID_VALID(tbl_id, field_id)\
    ((field_id) >= 0)&&((field_id) < TABLE_FIELD_NUM(tbl_id))\


#define CHK_TABLE_EXT_INFO_ISTCAM(tbl_id)\
    (EXT_INFO_TYPE_TCAM == (TABLE_EXT_INFO_TYPE(tbl_id)))\

#define TCAM_EXT_INFO_PTR(tbl_id)                   (TCAM_TYPE_EXT (TABLE_EXT_INFO_PTR(tbl_id)->ptr_ext_content))
#define TCAM_MASK_BASE_LPM(tbl_id, addroffset)      (TCAM_EXT_INFO_PTR(tbl_id)->hw_mask_base[addroffset])
#define TCAM_KEY_SIZE(tbl_id)                       (TCAM_EXT_INFO_PTR(tbl_id)->key_size)
#define TCAM_KEY_TYPE(tbl_id)                       (TCAM_EXT_INFO_PTR(tbl_id)->tcam_type)
#define TCAM_BITMAP(tbl_id)                         (TCAM_EXT_INFO_PTR(tbl_id)->tcam_alloc_info.tcam_mem_bitmap)
#define TCAM_DATA_BASE(tbl_id, blk_id, addroffset)  (TCAM_EXT_INFO_PTR(tbl_id)->tcam_alloc_info.tcam_mem_hw_data_base[blk_id][addroffset])
#define TCAM_MASK_BASE(tbl_id, blk_id, addroffset)  (TCAM_EXT_INFO_PTR(tbl_id)->tcam_alloc_info.tcam_mem_hw_mask_base[blk_id][addroffset])
#define TCAM_ENTRY_NUM(tbl_id, blk_id)              (TCAM_EXT_INFO_PTR(tbl_id)->tcam_alloc_info.tcam_mem_entry_num[blk_id])
#define TCAM_START_INDEX(tbl_id, blk_id)            (TCAM_EXT_INFO_PTR(tbl_id)->tcam_alloc_info.tcam_mem_entry_start_index[blk_id])
#define TCAM_END_INDEX(tbl_id, blk_id)              (TCAM_EXT_INFO_PTR(tbl_id)->tcam_alloc_info.tcam_mem_entry_end_index[blk_id])


#define DYNAMIC_EXT_INFO_PTR(tbl_id)                    (DYNAMIC_TYPE_EXT (TABLE_EXT_INFO_PTR(tbl_id)->ptr_ext_content))
#define DYNAMIC_ACCESS_MODE(tbl_id)                     (DYNAMIC_EXT_INFO_PTR(tbl_id)->dynamic_access_mode)
#define DYNAMIC_BITMAP(tbl_id)                          (DYNAMIC_EXT_INFO_PTR(tbl_id)->dynamic_mem_allocate_info.dynamic_mem_bitmap)
#define DYNAMIC_DATA_BASE(tbl_id, blk_id, addroffset)   (DYNAMIC_EXT_INFO_PTR(tbl_id)->dynamic_mem_allocate_info.dynamic_mem_hw_data_base[blk_id][addroffset])
#define DYNAMIC_ENTRY_NUM(tbl_id, blk_id)               (DYNAMIC_EXT_INFO_PTR(tbl_id)->dynamic_mem_allocate_info.dynamic_mem_entry_num[blk_id])
#define DYNAMIC_START_INDEX(tbl_id, blk_id)             (DYNAMIC_EXT_INFO_PTR(tbl_id)->dynamic_mem_allocate_info.dynamic_mem_entry_start_index[blk_id])
#define DYNAMIC_END_INDEX(tbl_id, blk_id)               (DYNAMIC_EXT_INFO_PTR(tbl_id)->dynamic_mem_allocate_info.dynamic_mem_entry_end_index[blk_id])


/* check chip id valid */
extern drv_init_chip_info_t drv_init_chip_info;

#define DRV_CHIP_ID_VALID_CHECK(chip_id) \
if ((drv_init_chip_info.drv_init_chipid_base \
    + drv_init_chip_info.drv_init_chip_num) <= (chip_id))\
{\
    DRV_DBG_INFO("\nERROR! INVALID ChipID! chipid: %d, file:%s line:%d function:%s\n",chip_id,__FILE__,__LINE__,__FUNCTION__);\
    return DRV_E_INVALID_CHIP;\
}

/* check Table Id valid */
#define DRV_TBL_ID_VALID_CHECK(tbl_id) \
if ((tbl_id) >= (MaxTblId_t))\
{\
    DRV_DBG_INFO("\nERROR! INVALID TblID! TblID: %d, file:%s line:%d function:%s\n",tbl_id,__FILE__,__LINE__,__FUNCTION__);\
    return DRV_E_INVALID_TBL;\
}

/* check if Table is empty */
#define DRV_TBL_EMPTY_CHECK(tbl_id) \
if (TABLE_MAX_INDEX(tbl_id) == 0)\
{\
    DRV_DBG_INFO("\nERROR! Operation on an empty table! TblID: %d, file:%s line:%d function:%s\n",tbl_id,__FILE__,__LINE__,__FUNCTION__);\
    return DRV_E_INVALID_TBL;\
}

/* check is index of table id is valid */
#define DRV_TBL_INDEX_VALID_CHECK(tbl_id, index) \
if (index >= TABLE_MAX_INDEX(tbl_id))\
{\
    DRV_DBG_INFO("\nERROR! Index-0x%x exceeds the max_index 0x%x! TblID: %d, file:%s line:%d function:%s\n", \
                   index, TABLE_MAX_INDEX(tbl_id), tbl_id,__FILE__,__LINE__,__FUNCTION__);\
    return DRV_E_INVALID_INDEX;\
}

enum sram_share_mem_id_e
{
    /* Hash key and ADs*/
    LPM_LOOKUP_KEY_TABLE    = 0,

    FIB_MACHOST0_KEY_SHARE_TABLE = 1,
    FIB_MACHOST1_KEY_SHARE_TABLE = 2,

    FIB_DS_FLOW_KEY_SHARE_TABLE = 3,
    FIB_DS_FLOW_AD_SHARE_TABLE = 4,

    USER_ID_HASH_KEY_SHARE_TABLE = 5,
    USER_ID_HASH_AD_SHARE_TABLE  = 6,

    EGRESS_OAM_HASH_KEY_SHARE_TABLE = 7,

    FIB_L2_AD_SHARE_TABLE  = 8,
    FIB_L3_AD_SHARE_TABLE  = 9,

    /* other indepencence tables treated as share table */
    DS_LM_SHARE_TABLE = 10,
    DS_APS_SHARE_TABLE = 11,
    OAM_MEP_SHARE_TABLE = 12,
    OAM_MA_SHARE_TABLE = 13,
    OAM_MANAME_SHARE_TABLE = 14,

    EDIT_SHARE_TABLE = 15,

    NEXTHOP_SHARE_TABLE = 16,
    MET_ENTRY_SHARE_TABLE = 17,
    //DS_MPLS_AD_SHARE_TABLE = 19,
    IP_FIX_HASH_KEY_SHARE_TABLE = 18,
    IP_FIX_HASH_AD_SHARE_TABLE = 19,

    //DS_FWD_SHARE_TABLE = 18,
    //DS_STATS_SHARE_TABLE = 19,
    //DS_POLICER_SHARE_TABLE = 20,

    MAX_SRAM_SHARE_MEM_ID,
};
typedef enum sram_share_mem_id_e sram_share_mem_id_t;

enum tmp_tcam_share_mem_info_e
{
    /*Tcam key*/
    NEW_INGR_ACL_KEY0_SHARE_TABLE,
    NEW_INGR_ACL_KEY1_SHARE_TABLE,
    NEW_INGR_ACL_KEY2_SHARE_TABLE,
    NEW_INGR_ACL_KEY3_SHARE_TABLE,
    NEW_EGR_ACL_KEY0_SHARE_TABLE,
    IG_USERID_0_TCAM_KEY_SHARE_TABLE,
    IG_USERID_1_TCAM_KEY_SHARE_TABLE,


    /*LPM internal Tcam*/
    NEW_LPM_TCAM_KEY0_SHARE_TABLE,
    NEW_LPM_TCAM_KEY1_SHARE_TABLE,

    MAX_TMP_TCAM_SHARE_MEM_ID,
};
typedef enum tmp_tcam_share_mem_info_e tmp_tcam_share_mem_info_t;

#define DYNAMIC_DS_MAX_LINE_NUM 5
struct dynamic_ds_share_mem_line_connect_s
{
    uint32 line_num;
    uint32 line_bitmap;
    uint32 ram_capacity[DYNAMIC_DS_MAX_LINE_NUM];
};
typedef struct dynamic_ds_share_mem_line_connect_s dynamic_ds_share_mem_line_connect_t;

struct tcam_mem_line_connect_s
{
    uint32 line_num;
    uint32 is_allocated;
    uint32 allocated_id;
    uint32 line_bitmap;
};
typedef struct tcam_mem_line_connect_s tcam_mem_line_connect_t;


/**********************************************************************************
                      Define external transfer var
***********************************************************************************/
/* sdk has a global pointer arry for per-chip */
extern tables_info_t drv_tbls_list[MaxTblId_t];

/* all dynimic table's related EDRAM info */
extern uint16 dynic_table_related_edram_bitmap[];
/**********************************************************************************
                      Define API function interfaces
***********************************************************************************/

/**
 @brief according to memory field id to find the field property
*/
extern fields_t*
drv_find_field(tbls_id_t tbl_id, fld_id_t field_id);

/**
 @brief set a field of a memory data entry
*/
extern int32
drv_set_field(tbls_id_t tbl_id, fld_id_t field_id,
                  void* entry, uint32* value);


extern uint32
drv_get_field_value(tbls_id_t tbl_id, fld_id_t field_id,  void* entry);

/**
 @brief get a field of a memory data entry
*/
extern int32
drv_get_field(tbls_id_t tbl_id, fld_id_t field_id,
                  void* entry, uint32* value);


/**
 @brief Get a field of  word & bit offset
*/
extern int32
drv_get_field_offset(tbls_id_t tbl_id, fld_id_t field_id, uint32* w_offset, uint32 *b_offset);


/**
 @brief Check tcam field in key size
*/
extern int32
drv_tcam_field_chk(tbls_id_t tbl_id, fld_id_t field_id);

/**
 @brief register a memory
*/
extern int32
drv_tbl_register(tbls_id_t tbl_id, uint8 entry_type, uint32 data_offset, uint32 max_idx,
                     uint16 entry_size, uint8 num_f, fields_t* ptr_f);

/**
 @brief
*/
extern int32
drv_sram_ds_to_entry(tbls_id_t tbl_id, void* ds, uint32* entry);

/**
 @brief
*/
extern int32
drv_sram_entry_to_ds(tbls_id_t tbl_id, uint32* entry, void* ds);

/**
 @brief
*/
extern int32
drv_tcam_ds_to_entry(tbls_id_t tbl_id, void* ds, void* entry);

/**
 @brief
*/
extern int32
drv_tcam_entry_to_ds(tbls_id_t tbl_id, void* entry, void* ds);

/**
 @brief
*/
extern int32
drv_get_tbl_index_base(tbls_id_t tbl_id, uint32 index, uint8 *addr_offset);

/**
 @brief
*/
extern int32
drv_get_tbl_string_by_id(tbls_id_t tbl_id, char* name);

/**
 @brief
*/
extern int32
drv_get_field_string_by_id(tbls_id_t tbl_id, fld_id_t field_id, char* name);

/**
 @brief
*/
extern int32
drv_get_tbl_id_by_string(tbls_id_t* tbl_id, char* name);

/**
 @brief
*/
extern int32
drv_get_field_id_by_string(tbls_id_t tbl_id, fld_id_t* field_id, char* name);

/* Get hardware address according to tablid + index (do not include tcam key) */
extern int32
drv_table_get_hw_addr(tbls_id_t tbl_id, uint32 index, uint32 *hw_addr, uint32 is_dump_cfg);

/* Get hardware address according to tablid + index + data/mask flag (only tcam key) */
extern int32
drv_tcam_key_get_hw_addr(tbls_id_t tbl_id, uint32 index, bool is_data, uint32 *hw_addr);

extern int32
drv_get_tcam_640_offset(tbls_id_t tbl_id, uint32 *tcam_640_offset);

/* judge table is tcam key table according tbl_id */
extern int8 drv_table_is_tcam_key(tbls_id_t tbl_id);

/* judge table is dynamic table according tbl_id */
extern int8 drv_table_is_dynamic_table(tbls_id_t tbl_id);

extern int32 drv_table_consum_hw_addr_size_per_index(tbls_id_t tbl_id, uint32 *hw_addr_size);

extern int8 drv_table_is_tcam_ad(tbls_id_t tbl_id);
extern int8 drv_table_is_lpm_tcam_key(tbls_id_t tbl_id);
extern int8 drv_table_is_lpm_tcam_ad(tbls_id_t tbl_id);

extern int8 drv_table_is_lpm_tcam_key_ip_prefix(tbls_id_t tbl_id);
extern int8 drv_table_is_lpm_tcam_ip_ad(tbls_id_t tbl_id);
extern int8 drv_table_is_lpm_tcam_nat_ad(tbls_id_t tbl_id);
extern int8 drv_get_flow_tcam_line_bitmap(tbls_id_t tbl_id);

extern uint32 drv_get_tcam_entry_num(uint8 block_num, uint8 is_ad);
#if (SDK_WORK_PLATFORM == 0)
extern int8 drv_table_is_slice1(tbls_id_t tbl_id);
extern int8 drv_table_is_parser_tbl(tbls_id_t tbl_id);
#endif
extern uint32 drv_get_tcam_addr_offset(uint8 block_num, uint8 is_mask);
extern uint32 drv_get_tcam_ad_addr_offset(uint8 block_num);

#endif  /*end of _DRV_TBL_REG_H_*/

