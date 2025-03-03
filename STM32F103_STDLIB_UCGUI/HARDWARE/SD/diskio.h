/*****************************************************************************
 * 文件名  ：diskio.h
 * 描述    ：SD卡底层配置宏文件         
 * 实验平台：STM32F103VET6
 * 库版本  ：ST3.5.0
 * 作者    ：吴志涛
******************************************************************************/
#ifndef _DISKIO
#define _DISKIO
#include "integer.h"

/* Status of Disk Functions */
typedef BYTE	DSTATUS;
/* Results of Disk Functions */
typedef enum {
	RES_OK = 0,		/* 0: Successful */
	RES_ERROR,		/* 1: R/W Error */
	RES_WRPRT,		/* 2: Write Protected */
	RES_NOTRDY,		/* 3: Not Ready */
	RES_PARERR		/* 4: Invalid Parameter */
} DRESULT;

/*---------------------------------------*/
/* Prototypes for disk control functions */

DSTATUS disk_initialize (BYTE pdrv);
DSTATUS disk_status (BYTE pdrv);
DRESULT disk_read (BYTE pdrv, BYTE* buff, DWORD sector, BYTE count);
DRESULT disk_write (BYTE pdrv, const BYTE* buff, DWORD sector, BYTE count);
DRESULT disk_ioctl (BYTE pdrv, BYTE cmd, void* buff);

DWORD get_fattime (void);

/* Disk Status Bits (DSTATUS) */

#define STA_NOINIT		0x01	/* Drive not initialized */
#define STA_NODISK		0x02	/* No medium in the drive */
#define STA_PROTECT		0x04	/* Write protected */


/* Command code for disk_ioctrl fucntion */

/* Generic command (mandatory for FatFs) */
#define CTRL_SYNC			0	/* Flush disk cache (for write functions) */
#define GET_SECTOR_COUNT	1	/* Get media size (for only f_mkfs()) */
#define GET_SECTOR_SIZE		2	/* Get sector size (for multiple sector size (_MAX_SS >= 1024)) */
#define GET_BLOCK_SIZE		3	/* Get erase block size (for only f_mkfs()) */

#endif
