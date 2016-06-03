/**
 @file dal_kernel_io.h

 @author  Copyright (C) 2012 Centec Networks Inc.  All rights reserved.

 @date 2012-4-9

 @version v2.0

*/
#ifndef _DAL_KERNEL_H_
#define _DAL_KERNEL_H_
#ifdef __cplusplus
extern "C" {
#endif

#if defined(CONFIG_RESOURCES_64BIT) || defined(CONFIG_PHYS_ADDR_T_64BIT)
#define PHYS_ADDR_IS_64BIT
#endif

#ifndef SDK_IN_USERMODE
#ifdef PHYS_ADDR_IS_64BIT
typedef  long long  intptr;
typedef  unsigned long long uintptr;
#else
typedef  int  intptr;
typedef  unsigned int uintptr;
#endif
#endif

#define DAL_PCI_READ_ADDR  0x0
#define DAL_PCI_READ_DATA  0xc
#define DAL_PCI_WRITE_ADDR 0x8
#define DAL_PCI_WRITE_DATA 0x4
#define DAL_PCI_STATUS     0x10

#define DAL_PCI_STATUS_IN_PROCESS      31
#define DAL_PCI_STATUS_BAD_PARITY      5
#define DAL_PCI_STATUS_CPU_ACCESS_ERR  4
#define DAL_PCI_STATUS_READ_CMD        3
#define DAL_PCI_STATUS_REGISTER_ERR    1
#define DAL_PCI_STATUS_REGISTER_ACK    0

#define DAL_PCI_ACCESS_TIMEOUT 0x64

#define DAL_NAME          "linux_dal"  /* "linux_dal" */

#define DAL_DEV_MAJOR     198

#define DAL_DEV_INTR_MAJOR_BASE     200

#define DAL_DEV_NAME      "/dev/" DAL_NAME
#define DAL_ONE_KB 1024
#define DAL_ONE_MB (1024*1024)
struct dal_chip_parm_s
{
    unsigned int chip_id;     /*tmp should be uint8*/
    unsigned int fpga_id;     /*tmp add*/
    unsigned int reg_addr;
    unsigned int value;
};
typedef struct dal_chip_parm_s dal_chip_parm_t;

struct dal_intr_parm_s
{
    unsigned int irq;
    unsigned int enable;
};
typedef struct dal_intr_parm_s dal_intr_parm_t;

struct dal_irq_mapping_s
{
    unsigned int hw_irq;
    unsigned int sw_irq;
};
typedef struct dal_irq_mapping_s dal_irq_mapping_t;

struct dal_user_dev_s
{
    unsigned int chip_num;   /*output: local chip number*/
    unsigned int chip_id;       /*input: local chip id*/
    unsigned int phy_base0; /* low 32bits physical base address */
    unsigned int phy_base1; /* high 32bits physical base address */
    void* virt_base[2];        /* Virtual base address */
};
typedef  struct dal_user_dev_s dal_user_dev_t;

struct dma_info_s
{
    unsigned int lchip;
    unsigned int phy_base;
    unsigned int phy_base_hi;
    unsigned int size;
    unsigned int* virt_base;
};
typedef struct dma_info_s dma_info_t;

struct dal_pci_cfg_ioctl_s
{
    unsigned int chip_id;                      /* Device ID */
    unsigned int offset;
    unsigned int value;
};
typedef struct dal_pci_cfg_ioctl_s  dal_pci_cfg_ioctl_t;

struct dal_msi_info_s
{
    unsigned int lchip;
    unsigned int irq_base;
    unsigned int irq_num;
};
typedef struct dal_msi_info_s dal_msi_info_t;

enum cmd_type_e
{
    CMD_WRITE_CHIP,       /* for humber ioctrol*/
    CMD_READ_CHIP,         /* for humber ioctrol*/
    CMD_GET_DEVICES = 3,
    CMD_GET_DAL_VERSION,
    CMD_PCI_CONFIG_WRITE,
    CMD_PCI_CONFIG_READ,
    CMD_GET_DMA_INFO,
    CMD_REG_INTERRUPTS,
    CMD_UNREG_INTERRUPTS,
    CMD_EN_INTERRUPTS,
    CMD_I2C_READ,
    CMD_I2C_WRITE,
    CMD_GET_MSI_INFO,
    CMD_SET_MSI_CAP,
    CMD_IRQ_MAPPING,

    CMD_TYPE_MAX
};
typedef enum cmd_type_e cmd_type_t;

enum dal_version_e
{
    VERSION_MIN,
    VERSION_1DOT0,

    VERSION_MAX
};
typedef enum dal_version_e dal_version_t;

/* We try to assemble a contiguous segment from chunks of this size */
#define DMA_BLOCK_SIZE (512 * DAL_ONE_KB)

#ifdef __cplusplus
}
#endif

#endif

