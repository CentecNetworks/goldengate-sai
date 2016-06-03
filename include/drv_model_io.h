/**
  @file drv_model_io.h

  @date 2010-07-23

  @version v5.1

  The file implement driver IOCTL defines and macros
*/
#ifndef _DRV_MODEL_IO_H_
#define _DRV_MODEL_IO_H_

#include "sal.h"
#include "drv_lib.h"

/**
 @brief set the memory entry's write bit
*/
extern void
drv_model_sram_tbl_set_wbit(uint8 chip_id_offset, tbls_id_t tbl_id, uint32 index);

/**
 @brief clear the memory entry's write bit
*/
extern void
drv_model_sram_tbl_clear_wbit(uint8 chip_id_offset, tbls_id_t tbl_id, uint32 index);

/**
 @brief get the memory entry's write bit
*/
extern uint8
drv_model_sram_tbl_get_wbit(uint8 chip_id_offset, tbls_id_t tbl_id, uint32 index);

/**
 @brief write memory data to a sram memory location on memory model
*/
extern int32
drv_model_sram_tbl_write(uint8 chip_id_offset, tbls_id_t tbl_id, uint32 index, uint32* data);

/**
 @brief read memory data from a sram memory location on memory model
*/
extern int32
drv_model_sram_tbl_read(uint8 chip_id_offset, tbls_id_t tbl_id, uint32 index, uint32* data);

/**
 @brief write tcam interface on memory model
*/
extern int32
drv_model_tcam_tbl_write(uint8 chip_id_offset, tbls_id_t tbl_id, uint32 index, tbl_entry_t* entry);

/**
 @brief read tcam interface on memory model
*/
extern int32
drv_model_tcam_tbl_read(uint8 chip_id_offset, tbls_id_t tbl_id, uint32 index, tbl_entry_t *entry);

/**
 @brief remove tcam interface on memory model
*/
extern int32
drv_model_tcam_tbl_remove(uint8 chip_id_offset, tbls_id_t tbl_id, uint32 index);

/**
 @brief write memory data to a sram memory location on memory model(according to one address)
*/
int32
drv_model_write_sram_entry(uint8 chip_id_offset, uintptr addr, uint32* data, int32 len);
/**
 @brief read table data to a sram memory location on memory model(according to one address)
*/
int32
drv_model_read_sram_entry(uint8 chip_id_offset, uintptr addr, uint32* data, int32 len);

/**
 @brief cpu acceleration interface on memory model for fib host0 hash
*/
extern int32
drv_model_fib_acc_process(uint8 chip_id, uint32* i_fib_acc_cpu_req, uint32* o_fib_acc_cpu_rlt, uint8 is_store);

/**
 @brief cpu acceleration interface on memory model for all other hash
*/
extern int32
drv_model_cpu_acc_asic_lkup(uint8 chip_id, uint8 req_type, void * cpu_req, void * cpu_req1, void *cpu_rlt);

extern int32
drv_model_ipfix_acc_process(uint8 chip_id, void* i_ipfix_req, void* o_ipfix_result);
/**
 @brief set or clear vbit for hash key
*/
//int32
//drv_model_hash_vbit_operation(uint8, uint8, uint32, hash_op_type_t);

#endif
