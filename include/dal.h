/**
 @file dal.h

 @author  Copyright (C) 2012 Centec Networks Inc.  All rights reserved.

 @date 2012-4-9

 @version v2.0

*/
#ifndef _DAL_H_
#define _DAL_H_
#ifdef __cplusplus
extern "C" {
#endif

#include "sal.h"
#include "sal_types.h"

#define DAL_DEBUG_OUT(fmt, args...)            \
{ \
    if (g_dal_debug_on)  \
    {   \
        sal_printf(fmt, ##args);                        \
    }   \
}

#define DAL_DEBUG_DUMP(fmt, args...)            \
{ \
        sal_printf(fmt, ##args);                        \
}

#define DAL_MAX_CHIP_NUM   8                   /* DAL support max chip num is 8 */
#define DAL_MAX_INTR_NUM    6

struct dal_dma_info_s
{
    unsigned int phy_base;
    unsigned int phy_base_hi;
    unsigned int size;
    unsigned int* virt_base;
};
typedef struct dal_dma_info_s dal_dma_info_t;

/**
 @brief  define dal error type
*/
enum dal_err_e
{
    DAL_E_NONE = 0,                 /**< NO error */
    DAL_E_INVALID_PTR = -1000,      /**< invalid pointer */
    DAL_E_INVALID_FD = -999,        /**< invalid FD */
    DAL_E_TIME_OUT = -998,          /**< time out */
    DAL_E_INVALID_ACCESS = -997, /**< invalid access type*/
    DAL_E_MPOOL_NOT_CREATE = -996, /**< mpool not create*/
    DAL_E_INVALID_IRQ = -995,
    DAL_E_DEV_NOT_FOUND = -994,
    DAL_E_EXCEED_MAX = -993,
    DAL_E_NOT_INIT = -992,
    DAL_E_ENVALID_MSI_PARA = -991,

    DAL_E_ERROR_CODE_END
};

enum dal_access_type_e
{
    DAL_PCI_IO,       /* [HB]humber is access as pci device, using ioctrl */
    DAL_SUPER_IF,   /* [HB]humber is controled by fpga device */
    DAL_PCIE_MM,    /* [GB]Gb is access as pcie device, using mmap */
    DAL_SPECIAL_EMU, /* [GB]special for emulation */
    DAL_MAX_ACCESS_TYPE
};
typedef enum dal_access_type_e dal_access_type_t;

struct dal_pci_dev_s
{
    unsigned int busNo;
    unsigned int devNo;
    unsigned int funNo;
};
typedef struct dal_pci_dev_s dal_pci_dev_t;

struct dal_op_s
{
    int32   (* pci_read)(uint8 lchip, uint32 offset, uint32* value);
    int32   (* pci_write)(uint8 lchip, uint32 offset, uint32 value);
    int32   (* pci_conf_read)(uint8 lchip, uint32 offset, uint32* value);
    int32   (* pci_conf_write)(uint8 lchip, uint32 offset, uint32 value);
    int32   (* i2c_read)(uint8 lchip, uint16 offset, uint8 len, uint8* buf);
    int32   (* i2c_write)(uint8 lchip, uint16 offset, uint8 len, uint8* buf);
    int32   (* interrupt_register)(uint32 irq, int32 prio, void (*)(void*), void* data);
    int32   (* interrupt_unregister)(uint32 irq);
    int32   (* interrupt_set_en)(uint32 irq, uint32 enable);
    int32   (* interrupt_get_msi_info)(uint8 lchip, uint8* irq_base);
    int32   (* interrupt_set_msi_cap)(uint8 lchip, uint32 enable, uint32 num);
    uintptr  (* logic_to_phy)(uint8 lchip, void* laddr);
    void* (* phy_to_logic)(uint8 lchip, uintptr paddr);
    uint32* (* dma_alloc)(uint8 lchip, int32 size, int32 dma_type);
    void    (* dma_free)(uint8 lchip, void* ptr);
    uintptr pcie_base_addr[DAL_MAX_CHIP_NUM]; /* Configure PCIe base address  in vxworks environment*/
};
typedef struct dal_op_s dal_op_t;

int32 dal_op_init(dal_op_t* dal_op);
int32 dal_set_device_access_type(dal_access_type_t device_type);
int32 dal_get_device_access_type(dal_access_type_t* p_device_type);
int32 dal_dma_debug_info(uint8 lchip);
int32 dal_get_dma_info(unsigned int lchip, void* p_info);
int32 dal_create_irq_mapping(uint8 hw_irq, uint8* sw_irq);

#ifdef __cplusplus
}
#endif

#endif

