#ifndef __S6E3FA3_J7Y17_PARAM_H__
#define __S6E3FA3_J7Y17_PARAM_H__

#include <linux/types.h>
#include <linux/kernel.h>
#include "dynamic_aid_s6e3fa3_j7y17.h"

#define EXTEND_BRIGHTNESS	355
#define UI_MAX_BRIGHTNESS	255
#define UI_DEFAULT_BRIGHTNESS	140
#define NORMAL_TEMPERATURE	25	/* 25 degrees Celsius */

#define GAMMA_CMD_CNT		ARRAY_SIZE(SEQ_GAMMA_CONDITION_SET)
#define ACL_CMD_CNT		ARRAY_SIZE(SEQ_ACL_OFF)
#define OPR_CMD_CNT		ARRAY_SIZE(SEQ_OPR_ACL_OFF)
#define ELVSS_CMD_CNT		ARRAY_SIZE(SEQ_ELVSS_SET)
#define AID_CMD_CNT		ARRAY_SIZE(SEQ_AID_SETTING)
#define HBM_CMD_CNT		ARRAY_SIZE(SEQ_HBM_OFF)
#define TSET_CMD_CNT		ARRAY_SIZE(SEQ_TSET_SETTING)

#define LDI_REG_ELVSS		0xB6
#define LDI_REG_COORDINATE	0xA1
#define LDI_REG_DATE		LDI_REG_MTP
#define LDI_REG_ID		0x04
#define LDI_REG_CHIP_ID		0xD6
#define LDI_REG_MTP		0xC8
#define LDI_REG_HBM		0xB4
#define LDI_REG_RDDPM		0x0A
#define LDI_REG_RDDSM		0x0E
#define LDI_REG_ESDERR		0xEE
#define LDI_REG_MANUFACTURE_INFO	0xC9


/* len is read length */
#define LDI_LEN_ELVSS		(ELVSS_CMD_CNT - 1)
#define LDI_LEN_COORDINATE	4
#define LDI_LEN_DATE		7
#define LDI_LEN_ID		3
#define LDI_LEN_CHIP_ID		5
#define LDI_LEN_MTP		35
#define LDI_LEN_HBM		28
#define LDI_LEN_RDDPM		1
#define LDI_LEN_RDDSM		1
#define LDI_LEN_ESDERR		1
#define LDI_LEN_MANUFACTURE_INFO	20

/* offset is position including addr, not only para */
#define LDI_OFFSET_AOR_1	1
#define LDI_OFFSET_AOR_2	2

#define LDI_OFFSET_ELVSS_1	1	/* B6h 1st Para: MPS_CON */
#define LDI_OFFSET_ELVSS_2	2	/* B6h 2nd Para: ELVSS_Dim_offset */
#define LDI_OFFSET_ELVSS_3	22	/* B6h 22nd Para: ELVSS Temp Compensation */

#define LDI_OFFSET_HBM		1
#define LDI_OFFSET_ACL		1
#define LDI_OFFSET_TSET		1

#define LDI_GPARA_DATE		40	/* 0xC8 41st Para */
#define LDI_GPARA_HBM_ELVSS	22	/* 0xB6 23th para */
#define LDI_GPARA_MANUFACTURE_INFO	1	/* C9h 2nd Para */

struct lcd_seq_info {
	unsigned char	*cmd;
	unsigned int	len;
	unsigned int	sleep;
};

static unsigned char SEQ_SLEEP_OUT[] = {
	0x11
};

static unsigned char SEQ_SLEEP_IN[] = {
	0x10
};

static unsigned char SEQ_DISPLAY_ON[] = {
	0x29
};

static unsigned char SEQ_DISPLAY_OFF[] = {
	0x28
};

static unsigned char SEQ_TEST_KEY_ON_F0[] = {
	0xF0,
	0x5A, 0x5A
};

static unsigned char SEQ_TEST_KEY_OFF_F0[] = {
	0xF0,
	0xA5, 0xA5
};

static unsigned char SEQ_TEST_KEY_ON_FC[] = {
	0xFC,
	0x5A, 0x5A
};

static unsigned char SEQ_TEST_KEY_OFF_FC[] = {
	0xFC,
	0xA5, 0xA5
};

static unsigned char SEQ_TE_ON[] = {
	0x35,
	0x00
};

static unsigned char SEQ_PCD_SETTING[] = {
	0xCC,
	0x5C
};


static const unsigned char SEQ_AVC_SETTING_1[] = {
	0xB0,
	0x1E
};

static const unsigned char SEQ_AVC_SETTING_2[] = {
	0xFD,
	0xB2
};

static const unsigned char SEQ_ELVSSTEMPSET_1[] = {
	0xB6,
	0xAC, 0x29
};

static const unsigned char SEQ_ELVSSTEMPSET_2[] = {
	0xF5,
	0x84, 0x33
};


static const unsigned char SEQ_GAMMA_CONDITION_SET[] = {
	0xCA,
	0x01, 0x00, 0x01, 0x00, 0x01, 0x00, 0x80, 0x80, 0x80, 0x80,
	0x80, 0x80, 0x80, 0x80, 0x80, 0x80, 0x80, 0x80, 0x80, 0x80,
	0x80, 0x80, 0x80, 0x80, 0x80, 0x80, 0x80, 0x80, 0x80, 0x80,
	0x00, 0x00, 0x00, 0x00, 0x00
};

static const unsigned char SEQ_AID_SETTING[] = {
	0xB2,
	0x00, 0x10
};

static unsigned char SEQ_ELVSS_SET[] = {
	0xB6,
	0xBC,	/* B6h 1st Para: MPS_CON */
	0x07,	/* B6h 2nd Para: ELVSS_Dim_offset */
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00,
	0x00,	/* B6h 22nd Para: ELVSS Temp Compensation */
	0x00	/* B6h 23rd Para: OTP for B6h 22nd Para of HBM Interpolation */
};

static unsigned char SEQ_GAMMA_UPDATE[] = {
	0xF7,
	0x03
};

static unsigned char SEQ_HBM_OFF[] = {
	0x53,
	0x00
};

static unsigned char SEQ_HBM_ON[] = {
	0x53,
	0xC0
};


static unsigned char SEQ_ACL_SET[] = {
	0xB5,
	0x00,
	0x00,
	0x14,
	0x00
};

static unsigned char SEQ_OPR_ACL_OFF[] = {
	0x40	/* 16 Frame Avg. at ACL Off */
};

static unsigned char SEQ_OPR_ACL_ON[] = {
	0x50	/* 32 Frame Avg. at ACL On */
};

static unsigned char SEQ_ACL_START_POINT_60[] = {
	0x99
};

static unsigned char SEQ_ACL_START_POINT_50[] = {
	0x7F
};

static unsigned char SEQ_ACL_PERCENT_8[] = {
	0x0A
};

static unsigned char SEQ_ACL_PERCENT_15[] = {
	0x14
};

static unsigned char SEQ_ACL_OFF[] = {
	0x55,
	0x00
};

static unsigned char SEQ_ACL_ON[] = {
	0x55,
	0x02	/* 0x02 : ACL 8% (Default) */
};

static unsigned char SEQ_TSET_SETTING[] = {
	0xB8,
	0x19	/* (ex) 25 degree : 0x19 */
};
#ifdef CONFIG_DISPLAY_USE_INFO

#define ERR_READ_REG 0xee
#define ERR_RDNUMED_REG 0x05
#define ERR_RDDSDR_REG 0x0f

/* Write COMMAND before read */
static const unsigned char SEQ_ESD_MONITOR_ON[] = {
	0xED,
	0x4C,
};


#endif


#ifdef CONFIG_LCD_DOZE_MODE
enum {
	ALPM_OFF,
	ALPM_ON_LOW,	/* ALPM 2 NIT */
	HLPM_ON_LOW,	/* HLPM 2 NIT */
	ALPM_ON_HIGH,	/* ALPM 60 NIT */
	HLPM_ON_HIGH,	/* HLPM 60 NIT */
	ALPM_MODE_MAX
};

static const unsigned char SEQ_SELECT_HLPM_60[] = {
	0xBB,
	0x14,			/* 0x14 : HLPM 60nit Mode */
	0x00, 0x07, 0x12
};

static const unsigned char SEQ_SELECT_HLPM_02[] = {
	0xBB,
	0x54,			/* 0x54 : HLPM 2nit Mode */
	0x00, 0x07, 0x12
};

static const unsigned char SEQ_SELECT_ALPM_60[] = {
	0xBB,
	0x84,			/* 0x84 : ALPM 60nit Mode */
	0x00, 0x07, 0x12
};

static const unsigned char SEQ_SELECT_ALPM_02[] = {
	0xBB,
	0xC4,			/* 0xC4 : ALPM 2nit Mode */
	0x00, 0x07, 0x12
};

static const unsigned char SEQ_SELECT_60NIT_ON[] = {
	0x53,
	0x02			/* 0x02 : HLPM/ALPM 60nit On */
};

static const unsigned char SEQ_SELECT_02NIT_ON[] = {
	0x53,
	0x03			/* 0x03 : HLPM/ALPM 2nit On */
};

static const unsigned char SEQ_LTPS_EQ_HLPM[] = {
	0xFD,
	0xA1, 0x20, 0x08, 0x04, 0x44, 0x00, 0x8C, 0x07,
	0x00, 0x00, 0xFF, 0x00, 0x0A, 0xAA, 0x0A, 0xAA,
	0x0A, 0xAA, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x5A, 0x80, 0x57, 0x65, 0xB2, 0x95,
	0xA5, 0x04, 0x55, 0x05, 0x01, 0x01, 0x01
};
static const unsigned char SEQ_LTPS_EQ_ALPM[] = {
	0xFD,
	0xA1, 0x20, 0x08, 0x04, 0x44, 0x00, 0x0C, 0x07,
	0x00, 0x00, 0xFF, 0x00, 0x0A, 0xAA, 0x0A, 0xAA,
	0x0A, 0xAA, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x5A, 0x80, 0x57, 0x65, 0xB2, 0x95,
	0xA5, 0x04, 0x55, 0x05, 0x01, 0x01, 0x01
};


static const unsigned char SEQ_ALPM_OFF[] = {
	0x53,
	0x00
};

static const unsigned char SEQ_LTPS_EQ_NORMAL[] = {
	0xFD,
	0xA1, 0x20, 0x08, 0x04, 0x44, 0x00, 0x0C
};

#endif


enum {
	ACL_STATUS_0P,
	ACL_STATUS_8P,
	ACL_STATUS_MAX
};

enum {
	OPR_STATUS_ACL_OFF,
	OPR_STATUS_ACL_ON,
	OPR_STATUS_MAX
};

enum {
	CAPS_OFF,
	CAPS_ON,
	CAPS_MAX
};

enum {
	TEMP_ABOVE_MINUS_00_DEGREE,	/* T > 0 */
	TEMP_ABOVE_MINUS_15_DEGREE,	/* -15 < T <= 0 */
	TEMP_BELOW_MINUS_15_DEGREE,	/* T <= -15 */
	TEMP_MAX
};

enum {
	HBM_STATUS_OFF,
	HBM_STATUS_ON,
	HBM_STATUS_MAX
};

static unsigned char *HBM_TABLE[HBM_STATUS_MAX] = {SEQ_HBM_OFF, SEQ_HBM_ON};
static unsigned char *ACL_TABLE[ACL_STATUS_MAX] = {SEQ_ACL_OFF, SEQ_ACL_ON};
static unsigned char *OPR_TABLE[OPR_STATUS_MAX] = {SEQ_OPR_ACL_OFF, SEQ_OPR_ACL_ON};

static unsigned char elvss_mpscon_offset_data[IBRIGHTNESS_HBM_MAX][3] = {
	[IBRIGHTNESS_005NIT ... IBRIGHTNESS_020NIT] = {0xB6, 0xAC, 0x07},
	[IBRIGHTNESS_021NIT] = {0xB6, 0xAC, 0x09},
	[IBRIGHTNESS_022NIT] = {0xB6, 0xAC, 0x0B},
	[IBRIGHTNESS_024NIT] = {0xB6, 0xAC, 0x0D},
	[IBRIGHTNESS_025NIT] = {0xB6, 0xAC, 0x0F},
	[IBRIGHTNESS_027NIT] = {0xB6, 0xAC, 0x11},
	[IBRIGHTNESS_029NIT] = {0xB6, 0xAC, 0x13},
	[IBRIGHTNESS_030NIT] = {0xB6, 0xAC, 0x15},
	[IBRIGHTNESS_032NIT] = {0xB6, 0xAC, 0x17},
	[IBRIGHTNESS_034NIT ... IBRIGHTNESS_039NIT] = {0xB6, 0xAC, 0x1A},
	[IBRIGHTNESS_041NIT ... IBRIGHTNESS_077NIT] = {0xB6, 0xBC, 0x1A},
	[IBRIGHTNESS_082NIT ... IBRIGHTNESS_098NIT] = {0xB6, 0xBC, 0x19},
	[IBRIGHTNESS_105NIT ... IBRIGHTNESS_111NIT] = {0xB6, 0xBC, 0x18},
	[IBRIGHTNESS_119NIT ... IBRIGHTNESS_143NIT] = {0xB6, 0xBC, 0x17},
	[IBRIGHTNESS_152NIT] = {0xB6, 0xBC, 0x16},
	[IBRIGHTNESS_162NIT] = {0xB6, 0xBC, 0x15},
	[IBRIGHTNESS_172NIT ... IBRIGHTNESS_183NIT] = {0xB6, 0xBC, 0x14},
	[IBRIGHTNESS_195NIT] = {0xB6, 0xBC, 0x13},
	[IBRIGHTNESS_207NIT] = {0xB6, 0xBC, 0x12},
	[IBRIGHTNESS_220NIT] = {0xB6, 0xBC, 0x11},
	[IBRIGHTNESS_234NIT] = {0xB6, 0xBC, 0x10},
	[IBRIGHTNESS_249NIT] = {0xB6, 0xBC, 0x0F},
	[IBRIGHTNESS_265NIT] = {0xB6, 0xBC, 0x0E},
	[IBRIGHTNESS_282NIT] = {0xB6, 0xBC, 0x0D},
	[IBRIGHTNESS_300NIT] = {0xB6, 0xBC, 0x0B},
	[IBRIGHTNESS_316NIT] = {0xB6, 0xBC, 0x0A},
	[IBRIGHTNESS_333NIT] = {0xB6, 0xBC, 0x09},
	[IBRIGHTNESS_360NIT] = {0xB6, 0xBC, 0x07},
	[IBRIGHTNESS_378NIT] = {0xB6, 0xBC, 0x11},
	[IBRIGHTNESS_395NIT] = {0xB6, 0xBC, 0x0F},
	[IBRIGHTNESS_413NIT] = {0xB6, 0xBC, 0x0D},
	[IBRIGHTNESS_430NIT] = {0xB6, 0xBC, 0x0B},
	[IBRIGHTNESS_448NIT] = {0xB6, 0xBC, 0x0A},
	[IBRIGHTNESS_465NIT] = {0xB6, 0xBC, 0x09},
	[IBRIGHTNESS_483NIT] = {0xB6, 0xBC, 0x08},
	[IBRIGHTNESS_500NIT] = {0xB6, 0xBC, 0x07},
};

static unsigned char AOR_TABLE[UI_MAX_BRIGHTNESS + 1 + 1][AID_CMD_CNT] = {
	{0xB2, 0x70, 0x4C},
	{0xB2, 0x70, 0x4A},
	{0xB2, 0x70, 0x47},
	{0xB2, 0x70, 0x44},
	{0xB2, 0x70, 0x42},
	{0xB2, 0x70, 0x3E},
	{0xB2, 0x70, 0x3A},
	{0xB2, 0x70, 0x36},
	{0xB2, 0x70, 0x33},
	{0xB2, 0x70, 0x26},
	{0xB2, 0x70, 0x23},
	{0xB2, 0x70, 0x21},
	{0xB2, 0x70, 0x1E},
	{0xB2, 0x70, 0x1C},
	{0xB2, 0x70, 0x1A},
	{0xB2, 0x70, 0x17},
	{0xB2, 0x70, 0x14},
	{0xB2, 0x70, 0x11},
	{0xB2, 0x70, 0x0E},
	{0xB2, 0x70, 0x0A},
	{0xB2, 0x70, 0x05},
	{0xB2, 0x70, 0x01},
	{0xB2, 0x60, 0xFD},
	{0xB2, 0x60, 0xF9},
	{0xB2, 0x60, 0xF6},
	{0xB2, 0x60, 0xF2},
	{0xB2, 0x60, 0xEE},
	{0xB2, 0x60, 0xEA},
	{0xB2, 0x60, 0xE7},
	{0xB2, 0x60, 0xE2},
	{0xB2, 0x60, 0xDE},
	{0xB2, 0x60, 0xDA},
	{0xB2, 0x60, 0xD6},
	{0xB2, 0x60, 0xD2},
	{0xB2, 0x60, 0xCE},
	{0xB2, 0x60, 0xCB},
	{0xB2, 0x60, 0xC8},
	{0xB2, 0x60, 0xC5},
	{0xB2, 0x60, 0xC2},
	{0xB2, 0x60, 0xBE},
	{0xB2, 0x60, 0xBA},
	{0xB2, 0x60, 0xB3},
	{0xB2, 0x60, 0xAB},
	{0xB2, 0x60, 0xA6},
	{0xB2, 0x60, 0xA1},
	{0xB2, 0x60, 0x91},
	{0xB2, 0x60, 0x82},
	{0xB2, 0x60, 0x77},
	{0xB2, 0x60, 0x6B},
	{0xB2, 0x60, 0x61},
	{0xB2, 0x60, 0x57},
	{0xB2, 0x60, 0x4C},
	{0xB2, 0x60, 0x42},
	{0xB2, 0x60, 0x28},
	{0xB2, 0x60, 0x0D},
	{0xB2, 0x60, 0x03},
	{0xB2, 0x50, 0xF8},
	{0xB2, 0x50, 0xE3},
	{0xB2, 0x50, 0xCE},
	{0xB2, 0x50, 0xB3},
	{0xB2, 0x50, 0x98},
	{0xB2, 0x50, 0x89},
	{0xB2, 0x50, 0x7A},
	{0xB2, 0x50, 0x5F},
	{0xB2, 0x50, 0x44},
	{0xB2, 0x50, 0x33},
	{0xB2, 0x50, 0x22},
	{0xB2, 0x50, 0x03},
	{0xB2, 0x40, 0xE4},
	{0xB2, 0x40, 0xD1},
	{0xB2, 0x40, 0xBE},
	{0xB2, 0x40, 0xAA},
	{0xB2, 0x40, 0x95},
	{0xB2, 0x40, 0x75},
	{0xB2, 0x40, 0x56},
	{0xB2, 0x40, 0x3C},
	{0xB2, 0x40, 0x21},
	{0xB2, 0x40, 0x02},
	{0xB2, 0x30, 0xE3},
	{0xB2, 0x30, 0xC4},
	{0xB2, 0x30, 0xA5},
	{0xB2, 0x30, 0x84},
	{0xB2, 0x30, 0x64},
	{0xB2, 0x30, 0x3B},
	{0xB2, 0x30, 0x12},
	{0xB2, 0x20, 0xF3},
	{0xB2, 0x20, 0xD5},
	{0xB2, 0x20, 0xE9},
	{0xB2, 0x20, 0xC5},
	{0xB2, 0x20, 0xE7},
	{0xB2, 0x20, 0xC5},
	{0xB2, 0x20, 0xED},
	{0xB2, 0x20, 0xC5},
	{0xB2, 0x20, 0xEA},
	{0xB2, 0x20, 0xC5},
	{0xB2, 0x20, 0xE8},
	{0xB2, 0x20, 0xC5},
	{0xB2, 0x20, 0xED},
	{0xB2, 0x20, 0xC5},
	{0xB2, 0x20, 0xE4},
	{0xB2, 0x20, 0xC5},
	{0xB2, 0x20, 0xEE},
	{0xB2, 0x20, 0xC5},
	{0xB2, 0x20, 0xE6},
	{0xB2, 0x20, 0xC5},
	{0xB2, 0x20, 0xEE},
	{0xB2, 0x20, 0xC5},
	{0xB2, 0x20, 0xE7},
	{0xB2, 0x20, 0xC5},
	{0xB2, 0x20, 0xF6},
	{0xB2, 0x20, 0xDD},
	{0xB2, 0x20, 0xC5},
	{0xB2, 0x20, 0xF8},
	{0xB2, 0x20, 0xDF},
	{0xB2, 0x20, 0xC5},
	{0xB2, 0x20, 0xF5},
	{0xB2, 0x20, 0xDD},
	{0xB2, 0x20, 0xC5},
	{0xB2, 0x20, 0xF7},
	{0xB2, 0x20, 0xDE},
	{0xB2, 0x20, 0xC5},
	{0xB2, 0x20, 0xB2},
	{0xB2, 0x20, 0x9E},
	{0xB2, 0x20, 0x8B},
	{0xB2, 0x20, 0x78},
	{0xB2, 0x20, 0x5F},
	{0xB2, 0x20, 0x47},
	{0xB2, 0x20, 0x2E},
	{0xB2, 0x20, 0x15},
	{0xB2, 0x20, 0x0C},
	{0xB2, 0x20, 0x04},
	{0xB2, 0x10, 0xFB},
	{0xB2, 0x10, 0xF3},
	{0xB2, 0x10, 0xEA},
	{0xB2, 0x10, 0xE1},
	{0xB2, 0x10, 0xD9},
	{0xB2, 0x10, 0xD0},
	{0xB2, 0x10, 0xC7},
	{0xB2, 0x10, 0xBF},
	{0xB2, 0x10, 0xB6},
	{0xB2, 0x10, 0xAE},
	{0xB2, 0x10, 0xA5},
	{0xB2, 0x10, 0x9D},
	{0xB2, 0x10, 0x94},
	{0xB2, 0x10, 0x8C},
	{0xB2, 0x10, 0x83},
	{0xB2, 0x10, 0x7B},
	{0xB2, 0x10, 0x72},
	{0xB2, 0x10, 0x6A},
	{0xB2, 0x10, 0x62},
	{0xB2, 0x10, 0x59},
	{0xB2, 0x10, 0x50},
	{0xB2, 0x10, 0x47},
	{0xB2, 0x10, 0x3E},
	{0xB2, 0x10, 0x35},
	{0xB2, 0x10, 0x2B},
	{0xB2, 0x10, 0x22},
	{0xB2, 0x10, 0x19},
	{0xB2, 0x10, 0x10},
	{0xB2, 0x10, 0x07},
	{0xB2, 0x00, 0xFE},
	{0xB2, 0x00, 0xF5},
	{0xB2, 0x00, 0xEB},
	{0xB2, 0x00, 0xE0},
	{0xB2, 0x00, 0xD6},
	{0xB2, 0x00, 0xCC},
	{0xB2, 0x00, 0xC2},
	{0xB2, 0x00, 0xB7},
	{0xB2, 0x00, 0xAD},
	{0xB2, 0x00, 0xA3},
	{0xB2, 0x00, 0x99},
	{0xB2, 0x00, 0x8E},
	{0xB2, 0x00, 0x84},
	{0xB2, 0x00, 0x79},
	{0xB2, 0x00, 0x6F},
	{0xB2, 0x00, 0x64},
	{0xB2, 0x00, 0x5A},
	{0xB2, 0x00, 0x4F},
	{0xB2, 0x00, 0x45},
	{0xB2, 0x00, 0x3A},
	{0xB2, 0x00, 0x30},
	{0xB2, 0x00, 0x25},
	{0xB2, 0x00, 0x1B},
	{0xB2, 0x00, 0x10},
	{0xB2, 0x00, 0x79},
	{0xB2, 0x00, 0x6F},
	{0xB2, 0x00, 0x64},
	{0xB2, 0x00, 0x5A},
	{0xB2, 0x00, 0x4F},
	{0xB2, 0x00, 0x45},
	{0xB2, 0x00, 0x3A},
	{0xB2, 0x00, 0x30},
	{0xB2, 0x00, 0x25},
	{0xB2, 0x00, 0x1B},
	{0xB2, 0x00, 0x10},
	{0xB2, 0x00, 0x7A},
	{0xB2, 0x00, 0x70},
	{0xB2, 0x00, 0x67},
	{0xB2, 0x00, 0x5D},
	{0xB2, 0x00, 0x54},
	{0xB2, 0x00, 0x4A},
	{0xB2, 0x00, 0x40},
	{0xB2, 0x00, 0x37},
	{0xB2, 0x00, 0x2D},
	{0xB2, 0x00, 0x23},
	{0xB2, 0x00, 0x1A},
	{0xB2, 0x00, 0x10},
	{0xB2, 0x00, 0x7A},
	{0xB2, 0x00, 0x70},
	{0xB2, 0x00, 0x66},
	{0xB2, 0x00, 0x5D},
	{0xB2, 0x00, 0x53},
	{0xB2, 0x00, 0x4A},
	{0xB2, 0x00, 0x40},
	{0xB2, 0x00, 0x36},
	{0xB2, 0x00, 0x2D},
	{0xB2, 0x00, 0x23},
	{0xB2, 0x00, 0x1A},
	{0xB2, 0x00, 0x10},
	{0xB2, 0x00, 0x68},
	{0xB2, 0x00, 0x60},
	{0xB2, 0x00, 0x57},
	{0xB2, 0x00, 0x4E},
	{0xB2, 0x00, 0x45},
	{0xB2, 0x00, 0x3C},
	{0xB2, 0x00, 0x33},
	{0xB2, 0x00, 0x2B},
	{0xB2, 0x00, 0x22},
	{0xB2, 0x00, 0x19},
	{0xB2, 0x00, 0x10},
	{0xB2, 0x00, 0x6A},
	{0xB2, 0x00, 0x62},
	{0xB2, 0x00, 0x5A},
	{0xB2, 0x00, 0x51},
	{0xB2, 0x00, 0x49},
	{0xB2, 0x00, 0x41},
	{0xB2, 0x00, 0x39},
	{0xB2, 0x00, 0x31},
	{0xB2, 0x00, 0x29},
	{0xB2, 0x00, 0x20},
	{0xB2, 0x00, 0x18},
	{0xB2, 0x00, 0x10},
	{0xB2, 0x00, 0x95},
	{0xB2, 0x00, 0x8A},
	{0xB2, 0x00, 0x7F},
	{0xB2, 0x00, 0x74},
	{0xB2, 0x00, 0x69},
	{0xB2, 0x00, 0x5E},
	{0xB2, 0x00, 0x52},
	{0xB2, 0x00, 0x47},
	{0xB2, 0x00, 0x3C},
	{0xB2, 0x00, 0x31},
	{0xB2, 0x00, 0x26},
	{0xB2, 0x00, 0x1B},
	{0xB2, 0x00, 0x10},
	{0xB2, 0x00, 0x10},
	{0xB2, 0x00, 0x10}	/* for interpolation and HBM */
};

/* platform brightness <-> gamma level */
static unsigned int brightness_table[EXTEND_BRIGHTNESS + 1] = {
	[0 ... 0] =	IBRIGHTNESS_005NIT,
	[1 ... 4] =	IBRIGHTNESS_006NIT,
	[5 ... 8] =	IBRIGHTNESS_007NIT,
	[9 ... 12] =	IBRIGHTNESS_008NIT,
	[13 ... 16] =	IBRIGHTNESS_009NIT,
	[17 ... 20] =	IBRIGHTNESS_010NIT,
	[21 ... 24] =	IBRIGHTNESS_011NIT,
	[25 ... 28] =	IBRIGHTNESS_012NIT,
	[29 ... 32] =	IBRIGHTNESS_013NIT,
	[33 ... 36] =	IBRIGHTNESS_014NIT,
	[37 ... 40] =	IBRIGHTNESS_015NIT,
	[41 ... 42] =	IBRIGHTNESS_016NIT,
	[43 ... 44] =	IBRIGHTNESS_017NIT,
	[45 ... 46] =	IBRIGHTNESS_019NIT,
	[47 ... 48] =	IBRIGHTNESS_020NIT,
	[49 ... 50] =	IBRIGHTNESS_021NIT,
	[51 ... 52] =	IBRIGHTNESS_022NIT,
	[53 ... 54] =	IBRIGHTNESS_024NIT,
	[55 ... 56] =	IBRIGHTNESS_025NIT,
	[57 ... 58] =	IBRIGHTNESS_027NIT,
	[59 ... 60] =	IBRIGHTNESS_029NIT,
	[61 ... 62] =	IBRIGHTNESS_030NIT,
	[63 ... 64] =	IBRIGHTNESS_032NIT,
	[65 ... 66] =	IBRIGHTNESS_034NIT,
	[67 ... 68] =	IBRIGHTNESS_037NIT,
	[69 ... 70] =	IBRIGHTNESS_039NIT,
	[71 ... 72] =	IBRIGHTNESS_041NIT,
	[73 ... 74] =	IBRIGHTNESS_044NIT,
	[75 ... 76] =	IBRIGHTNESS_047NIT,
	[77 ... 78] =	IBRIGHTNESS_050NIT,
	[79 ... 80] =	IBRIGHTNESS_053NIT,
	[81 ... 82] =	IBRIGHTNESS_056NIT,
	[83 ... 84] =	IBRIGHTNESS_060NIT,
	[85 ... 86] =	IBRIGHTNESS_064NIT,
	[87 ... 88] =	IBRIGHTNESS_068NIT,
	[89 ... 90] =	IBRIGHTNESS_072NIT,
	[91 ... 92] =	IBRIGHTNESS_077NIT,
	[93 ... 94] =	IBRIGHTNESS_082NIT,
	[95 ... 96] =	IBRIGHTNESS_087NIT,
	[97 ... 98] =	IBRIGHTNESS_093NIT,
	[99 ... 100] =	IBRIGHTNESS_098NIT,
	[101 ... 102] =	IBRIGHTNESS_105NIT,
	[103 ... 104] =	IBRIGHTNESS_111NIT,
	[105 ... 106] =	IBRIGHTNESS_119NIT,
	[107 ... 108] =	IBRIGHTNESS_126NIT,
	[109 ... 111] =	IBRIGHTNESS_134NIT,
	[112 ... 114] =	IBRIGHTNESS_143NIT,
	[115 ... 117] =	IBRIGHTNESS_152NIT,
	[118 ... 120] =	IBRIGHTNESS_162NIT,
	[121 ... 124] =	IBRIGHTNESS_172NIT,
	[125 ... 128] =	IBRIGHTNESS_183NIT,
	[129 ... 139] =	IBRIGHTNESS_195NIT,
	[140 ... 150] =	IBRIGHTNESS_207NIT,
	[151 ... 161] =	IBRIGHTNESS_220NIT,
	[162 ... 172] =	IBRIGHTNESS_234NIT,
	[173 ... 183] =	IBRIGHTNESS_249NIT,
	[184 ... 194] =	IBRIGHTNESS_265NIT,
	[195 ... 206] =	IBRIGHTNESS_282NIT,
	[207 ... 218] =	IBRIGHTNESS_300NIT,
	[219 ... 229] =	IBRIGHTNESS_316NIT,
	[230 ... 241] =	IBRIGHTNESS_333NIT,
	[242 ... 267] =	IBRIGHTNESS_360NIT,
	[268 ... 279] =	IBRIGHTNESS_378NIT,
	[280 ... 292] =	IBRIGHTNESS_395NIT,
	[293 ... 304] =	IBRIGHTNESS_413NIT,
	[305 ... 317] =	IBRIGHTNESS_430NIT,
	[318 ... 329] =	IBRIGHTNESS_448NIT,
	[330 ... 341] =	IBRIGHTNESS_465NIT,
	[342 ... 354] =	IBRIGHTNESS_483NIT,
	[355 ... EXTEND_BRIGHTNESS] =	 IBRIGHTNESS_500NIT,
};

#endif /* __S6E3FA3_J7Y17_PARAM_H__ */
