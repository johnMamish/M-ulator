//************************************************************
// Desciption: PRCv13 Register File Header File
//      Generated by genRF 12/14/2015 01:18:39
//************************************************************

#ifndef PRCV13_RF_H
#define PRCV13_RF_H

// Register 0x00 [AMBA:0xA0000000]
typedef union prcv13_r00{
  struct{
    unsigned MBUS_R0		: 24;
  };
  uint32_t as_int;
} prcv13_r00_t;
#define PRCv13_R00_DEFAULT {{0x000000}}
_Static_assert(sizeof(prcv13_r00_t) == 4, "Punned Structure Size");

// Register 0x01 [AMBA:0xA0000004]
typedef union prcv13_r01{
  struct{
    unsigned MBUS_R1		: 24;
  };
  uint32_t as_int;
} prcv13_r01_t;
#define PRCv13_R01_DEFAULT {{0x000000}}
_Static_assert(sizeof(prcv13_r01_t) == 4, "Punned Structure Size");

// Register 0x02 [AMBA:0xA0000008]
typedef union prcv13_r02{
  struct{
    unsigned MBUS_R2		: 24;
  };
  uint32_t as_int;
} prcv13_r02_t;
#define PRCv13_R02_DEFAULT {{0x000000}}
_Static_assert(sizeof(prcv13_r02_t) == 4, "Punned Structure Size");

// Register 0x03 [AMBA:0xA000000C]
typedef union prcv13_r03{
  struct{
    unsigned MBUS_R3		: 24;
  };
  uint32_t as_int;
} prcv13_r03_t;
#define PRCv13_R03_DEFAULT {{0x000000}}
_Static_assert(sizeof(prcv13_r03_t) == 4, "Punned Structure Size");

// Register 0x04 [AMBA:0xA0000010]
typedef union prcv13_r04{
  struct{
    unsigned MBUS_R4		: 24;
  };
  uint32_t as_int;
} prcv13_r04_t;
#define PRCv13_R04_DEFAULT {{0x000000}}
_Static_assert(sizeof(prcv13_r04_t) == 4, "Punned Structure Size");

// Register 0x05 [AMBA:0xA0000014]
typedef union prcv13_r05{
  struct{
    unsigned MBUS_R5		: 24;
  };
  uint32_t as_int;
} prcv13_r05_t;
#define PRCv13_R05_DEFAULT {{0x000000}}
_Static_assert(sizeof(prcv13_r05_t) == 4, "Punned Structure Size");

// Register 0x06 [AMBA:0xA0000018]
typedef union prcv13_r06{
  struct{
    unsigned MBUS_R6		: 24;
  };
  uint32_t as_int;
} prcv13_r06_t;
#define PRCv13_R06_DEFAULT {{0x000000}}
_Static_assert(sizeof(prcv13_r06_t) == 4, "Punned Structure Size");

// Register 0x07 [AMBA:0xA000001C]
typedef union prcv13_r07{
  struct{
    unsigned MBUS_R7		: 24;
  };
  uint32_t as_int;
} prcv13_r07_t;
#define PRCv13_R07_DEFAULT {{0x000000}}
_Static_assert(sizeof(prcv13_r07_t) == 4, "Punned Structure Size");

// Register 0x08 [AMBA:0xA0000020]
typedef union prcv13_r08{
  struct{
    unsigned CHIP_ID		: 16;
  };
  uint32_t as_int;
} prcv13_r08_t;
#define PRCv13_R08_DEFAULT {{0x0000}}
_Static_assert(sizeof(prcv13_r08_t) == 4, "Punned Structure Size");

// Register 0x09 [AMBA:0xA0000024]
typedef union prcv13_r09{
  struct{
    unsigned MBUS_THRES		: 20;
  };
  uint32_t as_int;
} prcv13_r09_t;
#define PRCv13_R09_DEFAULT {{0x80008}}
_Static_assert(sizeof(prcv13_r09_t) == 4, "Punned Structure Size");

// Register 0x0A [AMBA:0xA0000028]
typedef union prcv13_r0A{
  struct{
    // ** NOT-DEFINED ** //
    // ** NOT-DEFINED ** //
    // ** NOT-DEFINED ** //
    // ** NOT-DEFINED ** //
    // ** NOT-DEFINED ** //
    // ** NOT-DEFINED ** //
    // ** NOT-DEFINED ** //
    // ** NOT-DEFINED ** //
    // ** NOT-DEFINED ** //
    // ** NOT-DEFINED ** //
    // ** NOT-DEFINED ** //
    // ** NOT-DEFINED ** //
    unsigned CONFIG_HALT_CPU		: 4;
    unsigned OLD_MSG_REG_MASK		: 1;
  };
  uint32_t as_int;
} prcv13_r0A_t;
#define PRCv13_R0A_DEFAULT {{ /* NOT-DEFINED */  /* NOT-DEFINED */  /* NOT-DEFINED */  /* NOT-DEFINED */  /* NOT-DEFINED */  /* NOT-DEFINED */  /* NOT-DEFINED */  /* NOT-DEFINED */  /* NOT-DEFINED */  /* NOT-DEFINED */  /* NOT-DEFINED */  /* NOT-DEFINED */ 0xA, 0x1}}
_Static_assert(sizeof(prcv13_r0A_t) == 4, "Punned Structure Size");

// Register 0x0B [AMBA:0xA000002C]
typedef union prcv13_r0B{
  struct{
    unsigned GOC_SEL		: 4;
    unsigned GOC_SEL_DLY		: 2;
    unsigned GOC_ONECLK_MODE		: 1;
    unsigned GOC_CLK_GEN_SEL_FREQ		: 3;
    unsigned GOC_CLK_GEN_SEL_DIV		: 2;
    unsigned DSLP_CLK_GEN_FAST_MODE		: 1;
    unsigned CLK_GEN_RING		: 2;
    unsigned CLK_GEN_DIV_MBC		: 2;
    unsigned CLK_GEN_DIV_CORE		: 2;
    unsigned CLK_GEN_HIGH_FREQ		: 1;
  };
  uint32_t as_int;
} prcv13_r0B_t;
#define PRCv13_R0B_DEFAULT {{0x8, 0x0, 0x0, 0x6, 0x0, 0x0, 0x1, 0x1, 0x3, 0x0}}
_Static_assert(sizeof(prcv13_r0B_t) == 4, "Punned Structure Size");

// Register 0x0C [AMBA:0xA0000030]
// -- EMPTY --

// Register 0x0D [AMBA:0xA0000034]
typedef union prcv13_r0D{
  struct{
    unsigned SRAM_USE_INVERTER_SA		: 1;
    unsigned SRAM_TUNE_DECODER_DLY		: 4;
    unsigned SRAM_TUNE_WL_WIDTH		: 4;
    unsigned SRAM_TUNE_ASO_DLY		: 5;
    unsigned SRAM_USE_VREF_0P6		: 1;
    unsigned SRAM_USE_V0P6_NWELL		: 1;
  };
  uint32_t as_int;
} prcv13_r0D_t;
#define PRCv13_R0D_DEFAULT {{0x0, 0x2, 0x2, 0x00, 0x0, 0x0}}
_Static_assert(sizeof(prcv13_r0D_t) == 4, "Punned Structure Size");

// Register 0x0E [AMBA:0xA0000038]
typedef union prcv13_r0E{
  struct{
    unsigned GOCEP_TIMEOUT		: 24;
  };
  uint32_t as_int;
} prcv13_r0E_t;
#define PRCv13_R0E_DEFAULT {{0x1E8480}}
_Static_assert(sizeof(prcv13_r0E_t) == 4, "Punned Structure Size");

// Register 0x0F [AMBA:0xA000003C]
typedef union prcv13_r0F{
  struct{
    unsigned GOCEP_PASS		: 1;
    unsigned GOCEP_PASS_AND_RUN		: 1;
    unsigned GOCEP_FAIL		: 1;
    unsigned GOCEP_FAIL_CHIP_ID		: 1;
    unsigned GOCEP_FAIL_HEADER_PARITY		: 1;
    unsigned GOCEP_FAIL_MEM_PARITY		: 1;
    unsigned GOCEP_FAIL_TIMEOUT		: 1;
    unsigned GOCEP_CPU_WAS_RUNNING		: 1;
  };
  uint32_t as_int;
} prcv13_r0F_t;
#define PRCv13_R0F_DEFAULT {{0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0}}
_Static_assert(sizeof(prcv13_r0F_t) == 4, "Punned Structure Size");

// Register 0x10 [AMBA:0xA0000040]
typedef union prcv13_r10{
  struct{
    unsigned RUN_CPU		: 1;
  };
  uint32_t as_int;
} prcv13_r10_t;
#define PRCv13_R10_DEFAULT {{0x0}}
_Static_assert(sizeof(prcv13_r10_t) == 4, "Punned Structure Size");

// Register 0x11 [AMBA:0xA0000044]
typedef union prcv13_r11{
  struct{
    unsigned WUP_TSTAMP_SAT		: 15;
    // ** NOT-DEFINED ** //
    unsigned WUP_IRQ_EN		: 1;
    unsigned WUP_IRQ_IN_SLEEP_ONLY		: 1;
  };
  uint32_t as_int;
} prcv13_r11_t;
#define PRCv13_R11_DEFAULT {{0x0000 /* NOT-DEFINED */ , 0x0, 0x1}}
_Static_assert(sizeof(prcv13_r11_t) == 4, "Punned Structure Size");

// Register 0x12 [AMBA:0xA0000048]
// -- READ-ONLY --

// Register 0x13 [AMBA:0xA000004C]
// -- EMPTY --

// Register 0x14 [AMBA:0xA0000050]
// -- EMPTY --

// Register 0x15 [AMBA:0xA0000054]
// -- EMPTY --

// Register 0x16 [AMBA:0xA0000058]
// -- EMPTY --

// Register 0x17 [AMBA:0xA000005C]
// -- EMPTY --

// Register 0x18 [AMBA:0xA0000060]
// -- EMPTY --

// Register 0x19 [AMBA:0xA0000064]
// -- EMPTY --

// Register 0x1A [AMBA:0xA0000068]
// -- EMPTY --

// Register 0x1B [AMBA:0xA000006C]
// -- EMPTY --

// Register 0x1C [AMBA:0xA0000070]
// -- EMPTY --

// Register 0x1D [AMBA:0xA0000074]
// -- EMPTY --

// Register 0x1E [AMBA:0xA0000078]
// -- EMPTY --

// Register 0x1F [AMBA:0xA000007C]
// -- EMPTY --

// Register 0x20 [AMBA:0xA0000080]
// -- EMPTY --

// Register 0x21 [AMBA:0xA0000084]
typedef union prcv13_r21{
  struct{
    unsigned STR_WR_CH3_WR_BUF_LOWER		: 16;
    unsigned STR_WR_CH3_ALT_ADDR		: 8;
  };
  uint32_t as_int;
} prcv13_r21_t;
#define PRCv13_R21_DEFAULT {{0x0000, 0x00}}
_Static_assert(sizeof(prcv13_r21_t) == 4, "Punned Structure Size");

// Register 0x22 [AMBA:0xA0000088]
typedef union prcv13_r22{
  struct{
    unsigned STR_WR_CH3_WR_BUF_UPPER		: 16;
    unsigned STR_WR_CH3_ALT_REG_WR		: 8;
  };
  uint32_t as_int;
} prcv13_r22_t;
#define PRCv13_R22_DEFAULT {{0x0000, 0x00}}
_Static_assert(sizeof(prcv13_r22_t) == 4, "Punned Structure Size");

// Register 0x23 [AMBA:0xA000008C]
typedef union prcv13_r23{
  struct{
    unsigned STR_WR_CH3_BUF_LEN		: 20;
    // ** NOT-DEFINED ** //
    unsigned STR_WR_CH3_DBLB		: 1;
    unsigned STR_WR_CH3_WRP		: 1;
    unsigned STR_WR_CH3_EN		: 1;
  };
  uint32_t as_int;
} prcv13_r23_t;
#define PRCv13_R23_DEFAULT {{0x007FF /* NOT-DEFINED */ , 0x0, 0x0, 0x1}}
_Static_assert(sizeof(prcv13_r23_t) == 4, "Punned Structure Size");

// Register 0x24 [AMBA:0xA0000090]
typedef union prcv13_r24{
  struct{
    unsigned STR_WR_CH3_BUF_OFF		: 20;
  };
  uint32_t as_int;
} prcv13_r24_t;
#define PRCv13_R24_DEFAULT {{0x00000}}
_Static_assert(sizeof(prcv13_r24_t) == 4, "Punned Structure Size");

// Register 0x25 [AMBA:0xA0000094]
typedef union prcv13_r25{
  struct{
    unsigned STR_WR_CH2_WR_BUF_LOWER		: 16;
    unsigned STR_WR_CH2_ALT_ADDR		: 8;
  };
  uint32_t as_int;
} prcv13_r25_t;
#define PRCv13_R25_DEFAULT {{0x0000, 0x00}}
_Static_assert(sizeof(prcv13_r25_t) == 4, "Punned Structure Size");

// Register 0x26 [AMBA:0xA0000098]
typedef union prcv13_r26{
  struct{
    unsigned STR_WR_CH2_WR_BUF_UPPER		: 16;
    unsigned STR_WR_CH2_ALT_REG_WR		: 8;
  };
  uint32_t as_int;
} prcv13_r26_t;
#define PRCv13_R26_DEFAULT {{0x0000, 0x00}}
_Static_assert(sizeof(prcv13_r26_t) == 4, "Punned Structure Size");

// Register 0x27 [AMBA:0xA000009C]
typedef union prcv13_r27{
  struct{
    unsigned STR_WR_CH2_BUF_LEN		: 20;
    // ** NOT-DEFINED ** //
    unsigned STR_WR_CH2_DBLB		: 1;
    unsigned STR_WR_CH2_WRP		: 1;
    unsigned STR_WR_CH2_EN		: 1;
  };
  uint32_t as_int;
} prcv13_r27_t;
#define PRCv13_R27_DEFAULT {{0x007FF /* NOT-DEFINED */ , 0x0, 0x0, 0x1}}
_Static_assert(sizeof(prcv13_r27_t) == 4, "Punned Structure Size");

// Register 0x28 [AMBA:0xA00000A0]
typedef union prcv13_r28{
  struct{
    unsigned STR_WR_CH2_BUF_OFF		: 20;
  };
  uint32_t as_int;
} prcv13_r28_t;
#define PRCv13_R28_DEFAULT {{0x00000}}
_Static_assert(sizeof(prcv13_r28_t) == 4, "Punned Structure Size");

// Register 0x29 [AMBA:0xA00000A4]
typedef union prcv13_r29{
  struct{
    unsigned STR_WR_CH1_WR_BUF_LOWER		: 16;
    unsigned STR_WR_CH1_ALT_ADDR		: 8;
  };
  uint32_t as_int;
} prcv13_r29_t;
#define PRCv13_R29_DEFAULT {{0x0000, 0x00}}
_Static_assert(sizeof(prcv13_r29_t) == 4, "Punned Structure Size");

// Register 0x2A [AMBA:0xA00000A8]
typedef union prcv13_r2A{
  struct{
    unsigned STR_WR_CH1_WR_BUF_UPPER		: 16;
    unsigned STR_WR_CH1_ALT_REG_WR		: 8;
  };
  uint32_t as_int;
} prcv13_r2A_t;
#define PRCv13_R2A_DEFAULT {{0x0000, 0x00}}
_Static_assert(sizeof(prcv13_r2A_t) == 4, "Punned Structure Size");

// Register 0x2B [AMBA:0xA00000AC]
typedef union prcv13_r2B{
  struct{
    unsigned STR_WR_CH1_BUF_LEN		: 20;
    // ** NOT-DEFINED ** //
    unsigned STR_WR_CH1_DBLB		: 1;
    unsigned STR_WR_CH1_WRP		: 1;
    unsigned STR_WR_CH1_EN		: 1;
  };
  uint32_t as_int;
} prcv13_r2B_t;
#define PRCv13_R2B_DEFAULT {{0x007FF /* NOT-DEFINED */ , 0x0, 0x0, 0x1}}
_Static_assert(sizeof(prcv13_r2B_t) == 4, "Punned Structure Size");

// Register 0x2C [AMBA:0xA00000B0]
typedef union prcv13_r2C{
  struct{
    unsigned STR_WR_CH1_BUF_OFF		: 20;
  };
  uint32_t as_int;
} prcv13_r2C_t;
#define PRCv13_R2C_DEFAULT {{0x00000}}
_Static_assert(sizeof(prcv13_r2C_t) == 4, "Punned Structure Size");

// Register 0x2D [AMBA:0xA00000B4]
typedef union prcv13_r2D{
  struct{
    unsigned STR_WR_CH0_WR_BUF_LOWER		: 16;
    unsigned STR_WR_CH0_ALT_ADDR		: 8;
  };
  uint32_t as_int;
} prcv13_r2D_t;
#define PRCv13_R2D_DEFAULT {{0x0000, 0x00}}
_Static_assert(sizeof(prcv13_r2D_t) == 4, "Punned Structure Size");

// Register 0x2E [AMBA:0xA00000B8]
typedef union prcv13_r2E{
  struct{
    unsigned STR_WR_CH0_WR_BUF_UPPER		: 16;
    unsigned STR_WR_CH0_ALT_REG_WR		: 8;
  };
  uint32_t as_int;
} prcv13_r2E_t;
#define PRCv13_R2E_DEFAULT {{0x0000, 0x00}}
_Static_assert(sizeof(prcv13_r2E_t) == 4, "Punned Structure Size");

// Register 0x2F [AMBA:0xA00000BC]
typedef union prcv13_r2F{
  struct{
    unsigned STR_WR_CH0_BUF_LEN		: 20;
    // ** NOT-DEFINED ** //
    unsigned STR_WR_CH0_DBLB		: 1;
    unsigned STR_WR_CH0_WRP		: 1;
    unsigned STR_WR_CH0_EN		: 1;
  };
  uint32_t as_int;
} prcv13_r2F_t;
#define PRCv13_R2F_DEFAULT {{0x007FF /* NOT-DEFINED */ , 0x0, 0x0, 0x1}}
_Static_assert(sizeof(prcv13_r2F_t) == 4, "Punned Structure Size");

// Register 0x30 [AMBA:0xA00000C0]
typedef union prcv13_r30{
  struct{
    unsigned STR_WR_CH0_BUF_OFF		: 20;
  };
  uint32_t as_int;
} prcv13_r30_t;
#define PRCv13_R30_DEFAULT {{0x00000}}
_Static_assert(sizeof(prcv13_r30_t) == 4, "Punned Structure Size");

// Register 0x31 [AMBA:0xA00000C4]
// -- EMPTY --

// Register 0x32 [AMBA:0xA00000C8]
// -- EMPTY --

// Register 0x33 [AMBA:0xA00000CC]
typedef union prcv13_r33{
  struct{
    unsigned BLK_WR_LENGTH_LIMIT		: 20;
    // ** NOT-DEFINED ** //
    // ** NOT-DEFINED ** //
    unsigned BLK_WR_CACT		: 1;
    unsigned BLK_WR_EN		: 1;
  };
  uint32_t as_int;
} prcv13_r33_t;
#define PRCv13_R33_DEFAULT {{0x00000 /* NOT-DEFINED */  /* NOT-DEFINED */ , 0x0, 0x1}}
_Static_assert(sizeof(prcv13_r33_t) == 4, "Punned Structure Size");

// Register 0x34 [AMBA:0xA00000D0]
// -- EMPTY --

// Register 0x35 [AMBA:0xA00000D4]
// -- EMPTY --

// Register 0x36 [AMBA:0xA00000D8]
// -- EMPTY --

// Register 0x37 [AMBA:0xA00000DC]
// -- EMPTY --

// Register 0x38 [AMBA:0xA00000E0]
// -- EMPTY --

// Register 0x39 [AMBA:0xA00000E4]
// -- EMPTY --

// Register 0x3A [AMBA:0xA00000E8]
// -- EMPTY --

// Register 0x3B [AMBA:0xA00000EC]
// -- EMPTY --

// Register 0x3C [AMBA:0xA00000F0]
// -- EMPTY --

// Register 0x3D [AMBA:0xA00000F4]
// -- EMPTY --

// Register 0x3E [AMBA:0xA00000F8]
// -- EMPTY --

// Register 0x3F [AMBA:0xA00000FC]
// -- EMPTY --

// Register 0x40 [AMBA:0xA0000100]
typedef union prcv13_r40{
  struct{
    // ** NOT-DEFINED ** //
    // ** NOT-DEFINED ** //
    // ** NOT-DEFINED ** //
    // ** NOT-DEFINED ** //
    // ** NOT-DEFINED ** //
    // ** NOT-DEFINED ** //
    // ** NOT-DEFINED ** //
    // ** NOT-DEFINED ** //
    // ** NOT-DEFINED ** //
    // ** NOT-DEFINED ** //
    // ** NOT-DEFINED ** //
    // ** NOT-DEFINED ** //
    // ** NOT-DEFINED ** //
    // ** NOT-DEFINED ** //
    // ** NOT-DEFINED ** //
    // ** NOT-DEFINED ** //
    // ** NOT-DEFINED ** //
    // ** NOT-DEFINED ** //
    // ** NOT-DEFINED ** //
    // ** NOT-DEFINED ** //
    // ** NOT-DEFINED ** //
    // ** NOT-DEFINED ** //
    // ** NOT-DEFINED ** //
    unsigned ACT_RST		: 1;
  };
  uint32_t as_int;
} prcv13_r40_t;
#define PRCv13_R40_DEFAULT {{ /* NOT-DEFINED */  /* NOT-DEFINED */  /* NOT-DEFINED */  /* NOT-DEFINED */  /* NOT-DEFINED */  /* NOT-DEFINED */  /* NOT-DEFINED */  /* NOT-DEFINED */  /* NOT-DEFINED */  /* NOT-DEFINED */  /* NOT-DEFINED */  /* NOT-DEFINED */  /* NOT-DEFINED */  /* NOT-DEFINED */  /* NOT-DEFINED */  /* NOT-DEFINED */  /* NOT-DEFINED */  /* NOT-DEFINED */  /* NOT-DEFINED */  /* NOT-DEFINED */  /* NOT-DEFINED */  /* NOT-DEFINED */  /* NOT-DEFINED */ 0x0}}
_Static_assert(sizeof(prcv13_r40_t) == 4, "Punned Structure Size");

// Declare the structs
extern volatile prcv13_r00_t prc_v13_r00;

#endif // PRCV13_RF_H
