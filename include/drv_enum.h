#ifndef __DRV_TYPE_H__
#define __DRV_TYPE_H__

#include "sal_types.h"

//Field Enum
#define CTC_FIELD_ENUM(ModuleName, RegName, FieldName, Bits, ...) \
  RegName##_##FieldName##_f,

//Field Addr
#define CTC_FIELD_ADDR(ModuleName, RegName, FieldName, Bits, ...) \
  static segs_t RegName##_##FieldName##_tbl_segs[] = {__VA_ARGS__};

//Field Info
#define CTC_FIELD_INFO(ModuleName, RegName, FieldName, Bits, ...) \
   { \
      #FieldName, \
      Bits, \
      sizeof(RegName##_##FieldName##_tbl_segs) / sizeof(segs_t), \
      RegName##_##FieldName##_tbl_segs, \
   },

//DS Field List Seperator
#define CTC_DS_SEPERATOR_INFO(ModuleName, RegName, SliceType, OpType, Entry, Word, ...) \
 }; \
 static fields_t RegName##_tbl_fields[] = {


//DS Field Sepertor
#define CTC_DS_SEPERATOR_ENUM(ModuleName, RegName, SliceType, OpType, Entry, Word, ...) \
  RegName##__f = -1,

//DS ENUM
#define CTC_DS_ENUM(ModuleName, RegName, SliceType, OpType, Entry, Word, ...) \
   RegName##_t,

//DS TYPE
#define CTC_DS_TYPE(ModuleName, RegName, SliceType, OpType, Entry, Word, ...) \
  typedef struct {uint32 m[Word];} RegName##_m;

//DS ADDR
#define CTC_DS_ADDR(ModuleName, RegName, SliceType, OpType, Entry, Word, ...) \
   static addrs_t RegName##_tbl_addrs[] = {__VA_ARGS__};

//DS LIST
#define CTC_DS_INFO(ModuleName, RegName, SliceType, OpType, Entry, Word, ...) \
   { \
      #RegName, \
      SliceType, \
      OpType, \
      Entry, \
      Word*4, \
      sizeof(RegName##_tbl_addrs)/sizeof(addrs_t), \
      RegName##_tbl_addrs, \
      sizeof(RegName##_tbl_fields)/sizeof(fields_t), \
      RegName##_tbl_fields, \
      NULL, \
   },
#define CTC_MODULE_DS(ModuleName, RegName, SliceType, OpType, Entry, Word, ...) \
   RegName##_t,

#define CTC_MODULE_ENUM(ModuleName, InstNum) \
     ModuleName##_m,

#define CTC_MODULE_INFO(ModuleName, InstNum) \
     {#ModuleName, \
     	InstNum, \
     	dbg_##ModuleName##_tbl_id_list, \
     	sizeof(dbg_##ModuleName##_tbl_id_list)/sizeof(tbls_id_t), \
     },
#define CTC_MODULE_SEPERATOR(ModuleName, InstNum) \
   }; \
   static tbls_id_t dbg_##ModuleName##_tbl_id_list[]  = {


//DRV_DEF_M    (ModuleName, InstNum)
//  DRV_DEF_D  (ModuleName, RegName, SliceType, OpType, Entry, Word, ...)
//	  DRV_DEF_F(ModuleName, InstNum, RegName, FieldName, Bits, ...)

#undef DRV_DEF_C
#undef DRV_DEF_M
#undef DRV_DEF_D
#undef DRV_DEF_F

//drv_type.h:
#ifdef DRV_DEF_C
	#error DRV_DEF_C has been defined
#endif

#ifdef DRV_DEF_M
	#error DRV_DEF_M has been defined
#endif

#ifdef DRV_DEF_D
	#error DRV_DEF_D has been defined
#endif

#ifdef DRV_DEF_F
	#error DRV_DEF_F has been defined
#endif
#define DRV_DEF_C(MaxInstNum, MaxEntry, MaxWord, MaxBits,MaxStartPos,MaxSegSize)

// Field Enum
#define DRV_DEF_M(ModuleName, InstNum)
#define DRV_DEF_D(ModuleName, InstNum, RegName, SliceType, OpType, Entry, Word, ...) \
        CTC_DS_SEPERATOR_ENUM(ModuleName, RegName, SliceType, OpType, Entry, Word, __VA_ARGS__)
#define DRV_DEF_F(ModuleName, InstNum, RegName, FieldName, Bits, ...) \
        CTC_FIELD_ENUM(ModuleName, RegName, FieldName, Bits, __VA_ARGS__)
typedef enum fld_id_e {
#include "drv_ds.h"
} fld_id_t;
#undef DRV_DEF_M
#undef DRV_DEF_D
#undef DRV_DEF_F

// DS Enum
#define DRV_DEF_M(ModuleName, InstNum)
#define DRV_DEF_D(ModuleName, InstNum, RegName, SliceType, OpType, Entry, Word, ...) \
        CTC_DS_ENUM(ModuleName, RegName, SliceType, OpType, Entry, Word, __VA_ARGS__)
#define DRV_DEF_F(ModuleName, InstNum, RegName, FieldName, Bits, ...)
typedef enum tbls_id_e {
#include "drv_ds.h"
   MaxTblId_t
} tbls_id_t;
#undef DRV_DEF_M
#undef DRV_DEF_D
#undef DRV_DEF_F

#if 0
#define DRV_DEF_M(ModuleName, InstNum) \
        CTC_MODULE_ENUM(ModuleName, InstNum)
#define DRV_DEF_D(ModuleName, InstNum, RegName, SliceType, OpType, Entry, Word, ...)
#define DRV_DEF_F(ModuleName, InstNum, RegName, FieldName, Bits, ...)
typedef enum dbg_modules_id_e {
#include "drv_ds.h"
   MaxModId_m,
}dbg_mod_id_t;
#undef DRV_DEF_M
#undef DRV_DEF_D
#undef DRV_DEF_F
#endif

// DS Type
#define DRV_DEF_M(ModuleName, InstNum)
#define DRV_DEF_D(ModuleName, InstNum, RegName, SliceType, OpType, Entry, Word, ...) \
        CTC_DS_TYPE(ModuleName, RegName, SliceType, OpType, Entry, Word, __VA_ARGS__)
#define DRV_DEF_F(ModuleName, InstNum, RegName, FieldName, Bits, ...)
#include "drv_ds.h"
#undef DRV_DEF_M
#undef DRV_DEF_D
#undef DRV_DEF_F


#undef DRV_DEF_C

#endif // __DRV_TYPE_H__
