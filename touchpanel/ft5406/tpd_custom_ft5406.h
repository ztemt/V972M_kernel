#ifndef TPD_CUSTOM_FT5406_H__
#define TPD_CUSTOM_FT5406_H__

#include <linux/hrtimer.h>
#include <linux/string.h>
#include <linux/vmalloc.h>
//#include <linux/io.h>

#include <linux/init.h>
#include <linux/module.h>
#include <linux/delay.h>
#include <linux/i2c.h>
#include <linux/input.h>
#include <linux/slab.h>
#include <linux/gpio.h>
#include <linux/sched.h>
#include <linux/kthread.h>
#include <linux/bitops.h>
#include <linux/kernel.h>
#include <linux/delay.h>
#include <linux/byteorder/generic.h>
#ifdef CONFIG_HAS_EARLYSUSPEND
#include <linux/earlysuspend.h>
#endif
#include <linux/interrupt.h>
#include <linux/time.h>
#include <linux/rtpm_prio.h>

#include <linux/proc_fs.h>
#include <asm/uaccess.h>

#include <mach/mt_pm_ldo.h>
#include <mach/mt_typedefs.h>
#include <mach/mt_boot.h>

#include <cust_eint.h>
#include <linux/jiffies.h>

#define FT_I2C_NAME					"FT5406"
#define ZTEMT_TPD_I2C_BUS_ID		0
#define ZTEMT_TPD_POWER_SOURCE		MT65XX_POWER_LDO_VGP4

#define FT_ADDR_LENGTH				1
#define MAX_TRANSACTION_LENGTH		8
#define I2C_MASTER_CLOCK			300
#define MAX_I2C_TRANSFER_SIZE		(MAX_TRANSACTION_LENGTH - FT_ADDR_LENGTH)

#define FT_MAX_TOUCH_POINTS			5
#define FT_HAVE_TOUCH_KEY			0
#define CONFIG_SUPPORT_FTS_CTP_UPG
#define FTS_CTL_IIC

#define TPD_HAVE_BUTTON

#ifdef TPD_HAVE_BUTTON
#define TPD_KEY_COUNT				3
#define TPD_KEYS					{KEY_MENU, KEY_HOMEPAGE, KEY_BACK}
#define TPD_KEYS_DIM				{{179,1337,50,30},{379,1337,50,30},{589,1337,50,30}}
#endif

#if FT_HAVE_TOUCH_KEY
#define FT_KEY_TAB					{KEY_MENU, KEY_HOMEPAGE, KEY_BACK}
#endif

#define FT_DEBUG_ON					0

/* Log define */
#define FT_INFO(fmt,arg...)			printk("<<-FT-INFO->> "fmt"\n",##arg)
#define FT_ERROR(fmt,arg...)		printk("<<-FT-ERROR->> "fmt"\n",##arg)
#define FT_DEBUG(fmt,arg...)		do{\
										if(FT_DEBUG_ON)\
											printk("<<-FT-DEBUG->> [%d]"fmt"\n",__LINE__, ##arg);\
									}while(0)

#endif /* TPD_CUSTOM_FT5406_H__ */
