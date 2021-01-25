// clang-format off

// CR1
//
// control register 1
//
//   Offset: 0x000
ETL_BFF_REG_RW(uint32_t, CR1,
  // 31:13 reserved
  // Dithering Enable
  ETL_BFF_FIELD(12:12, bool, DITHEN)
  // UIF status bit remapping
  ETL_BFF_FIELD(11:11, bool, UIFREMAP)
  // 10 reserved
  // Clock division
  ETL_BFF_FIELD(9:8, uint8_t, CKD)
  // Auto-reload preload enable
  ETL_BFF_FIELD(7:7, bool, ARPE)
  // 6:4 reserved
  // One-pulse mode
  ETL_BFF_FIELD(3:3, bool, OPM)
  // Update request source
  ETL_BFF_FIELD(2:2, bool, URS)
  // Update disable
  ETL_BFF_FIELD(1:1, bool, UDIS)
  // Counter enable
  ETL_BFF_FIELD(0:0, bool, CEN)
)

// CR2
//
// control register 2
//
//   Offset: 0x004
ETL_BFF_REG_RW(uint32_t, CR2,
  // 31:10 reserved
  // Output Idle state 1
  ETL_BFF_FIELD(9:9, bool, OIS1N)
  // Output Idle state 1
  ETL_BFF_FIELD(8:8, bool, OIS1)
  // 7:4 reserved
  // Capture/compare DMA selection
  ETL_BFF_FIELD(3:3, bool, CCDS)
  // Capture/compare control update selection
  ETL_BFF_FIELD(2:2, bool, CCUS)
  // 1 reserved
  // Capture/compare preloaded control
  ETL_BFF_FIELD(0:0, bool, CCPC)
)

ETL_BFF_REG_RESERVED(uint32_t, reserved1, 1)

// DIER
//
// DMA/Interrupt enable register
//
//   Offset: 0x00C
ETL_BFF_REG_RW(uint32_t, DIER,
  // 31:14 reserved
  // COM DMA request enable
  ETL_BFF_FIELD(13:13, bool, COMDE)
  // 12:10 reserved
  // Capture/Compare 1 DMA request enable
  ETL_BFF_FIELD(9:9, bool, CC1DE)
  // Update DMA request enable
  ETL_BFF_FIELD(8:8, bool, UDE)
  // Break interrupt enable
  ETL_BFF_FIELD(7:7, bool, BIE)
  // 6 reserved
  // COM interrupt enable
  ETL_BFF_FIELD(5:5, bool, COMIE)
  // 4:2 reserved
  // Capture/Compare 1 interrupt enable
  ETL_BFF_FIELD(1:1, bool, CC1IE)
  // Update interrupt enable
  ETL_BFF_FIELD(0:0, bool, UIE)
)

// SR
//
// status register
//
//   Offset: 0x010
ETL_BFF_REG_RW(uint32_t, SR,
  // 31:10 reserved
  // Capture/Compare 1 overcapture flag
  ETL_BFF_FIELD(9:9, bool, CC1OF)
  // 8 reserved
  // Break interrupt flag
  ETL_BFF_FIELD(7:7, bool, BIF)
  // 6 reserved
  // COM interrupt flag
  ETL_BFF_FIELD(5:5, bool, COMIF)
  // 4:2 reserved
  // Capture/compare 1 interrupt flag
  ETL_BFF_FIELD(1:1, bool, CC1IF)
  // Update interrupt flag
  ETL_BFF_FIELD(0:0, bool, UIF)
)

// EGR
//
// event generation register
//
//   Offset: 0x014
ETL_BFF_REG_RW(uint32_t, EGR,
  // 31:8 reserved
  // Break generation
  ETL_BFF_FIELD(7:7, bool, BG)
  // 6 reserved
  // Capture/Compare control update generation
  ETL_BFF_FIELD(5:5, bool, COMG)
  // 4:2 reserved
  // Capture/compare 1 generation
  ETL_BFF_FIELD(1:1, bool, CC1G)
  // Update generation
  ETL_BFF_FIELD(0:0, bool, UG)
)

// CCMR1
//
// capture/compare mode register (output mode)
//
//   Offset: 0x018
ETL_BFF_REG_RW(uint32_t, CCMR1,
  // 31:17 reserved
  // Output Compare 1 mode
  ETL_BFF_FIELD(16:16, bool, OC1M_3)
  // 15:8 reserved
  ETL_BFF_FIELD(7:7, bool, OC1CE)
  // Output Compare 1 mode
  ETL_BFF_FIELD(6:4, uint8_t, OC1M)
  // Output Compare 1 preload enable
  ETL_BFF_FIELD(3:3, bool, OC1PE)
  // Output Compare 1 fast enable
  ETL_BFF_FIELD(2:2, bool, OC1FE)
  // Capture/Compare 1 selection
  ETL_BFF_FIELD(1:0, uint8_t, CC1S)
)

ETL_BFF_REG_RESERVED(uint32_t, reserved5, 1)

// CCER
//
// capture/compare enable register
//
//   Offset: 0x020
ETL_BFF_REG_RW(uint32_t, CCER,
  // 31:4 reserved
  // Capture/Compare 1 output Polarity
  ETL_BFF_FIELD(3:3, bool, CC1NP)
  // Capture/Compare 1 complementary output enable
  ETL_BFF_FIELD(2:2, bool, CC1NE)
  // Capture/Compare 1 output Polarity
  ETL_BFF_FIELD(1:1, bool, CC1P)
  // Capture/Compare 1 output enable
  ETL_BFF_FIELD(0:0, bool, CC1E)
)

// CNT
//
// counter
//
//   Offset: 0x024
ETL_BFF_REG_RW(uint32_t, CNT,
  // UIF Copy
  ETL_BFF_FIELD(31:31, bool, UIFCPY)
  // 30:16 reserved
  // counter value
  ETL_BFF_FIELD(15:0, uint16_t, CNT)
)

// PSC
//
// prescaler
//
//   Offset: 0x028
ETL_BFF_REG_RW(uint32_t, PSC,
  // 31:16 reserved
  // Prescaler value
  ETL_BFF_FIELD(15:0, uint16_t, PSC)
)

// ARR
//
// auto-reload register
//
//   Offset: 0x02C
//   Reset value: 0x0000FFFF
ETL_BFF_REG_RW(uint32_t, ARR,
  // 31:20 reserved
  // ARR dither bits
  ETL_BFF_FIELD(19:16, uint8_t, ARR_DITH)
  // Auto-reload value
  ETL_BFF_FIELD(15:0, uint16_t, ARR)
)

// RCR
//
// repetition counter register
//
//   Offset: 0x030
ETL_BFF_REG_RW(uint32_t, RCR,
  // 31:8 reserved
  // Repetition counter value
  ETL_BFF_FIELD(7:0, uint8_t, REP)
)

// CCR1
//
// capture/compare register 1
//
//   Offset: 0x034
ETL_BFF_REG_RW(uint32_t, CCR1,
  // 31:20 reserved
  // CCR1 dither bits
  ETL_BFF_FIELD(19:16, uint8_t, CCR1_DITH)
  // Capture/Compare 1 value
  ETL_BFF_FIELD(15:0, uint16_t, CCR1)
)

// CCR2
//
// capture/compare register 2
//
//   Offset: 0x038
ETL_BFF_REG_RW(uint32_t, CCR2,
  // 31:20 reserved
  // CCR1 dither bits
  ETL_BFF_FIELD(19:16, uint8_t, CCR1_DITH)
  // Capture/Compare 1 value
  ETL_BFF_FIELD(15:0, uint16_t, CCR2)
)

ETL_BFF_REG_RESERVED(uint32_t, reserved12, 2)

// BDTR
//
// break and dead-time register
//
//   Offset: 0x044
ETL_BFF_REG_RW(uint32_t, BDTR,
  // 31:29 reserved
  ETL_BFF_FIELD(28:28, bool, BKBID)
  // 27 reserved
  ETL_BFF_FIELD(26:26, bool, BKDSRM)
  // 25:20 reserved
  // Break filter
  ETL_BFF_FIELD(19:16, uint8_t, BKF)
  // Main output enable
  ETL_BFF_FIELD(15:15, bool, MOE)
  // Automatic output enable
  ETL_BFF_FIELD(14:14, bool, AOE)
  // Break polarity
  ETL_BFF_FIELD(13:13, bool, BKP)
  // Break enable
  ETL_BFF_FIELD(12:12, bool, BKE)
  // Off-state selection for Run mode
  ETL_BFF_FIELD(11:11, bool, OSSR)
  // Off-state selection for Idle mode
  ETL_BFF_FIELD(10:10, bool, OSSI)
  // Lock configuration
  ETL_BFF_FIELD(9:8, uint8_t, LOCK)
  // Dead-time generator setup
  ETL_BFF_FIELD(7:0, uint8_t, DTG)
)

ETL_BFF_REG_RESERVED(uint32_t, reserved13, 3)

// DTR2
//
// timer Deadtime Register 2
//
//   Offset: 0x054
ETL_BFF_REG_RW(uint32_t, DTR2,
  // 31:18 reserved
  // Deadtime Preload Enable
  ETL_BFF_FIELD(17:17, bool, DTPE)
  // Deadtime Asymmetric Enable
  ETL_BFF_FIELD(16:16, bool, DTAE)
  // 15:8 reserved
  // Dead-time generator setup
  ETL_BFF_FIELD(7:0, uint8_t, DTGF)
)

ETL_BFF_REG_RESERVED(uint32_t, reserved14, 1)

// TISEL
//
// TIM timer input selection register
//
//   Offset: 0x05C
ETL_BFF_REG_RW(uint32_t, TISEL,
  // 31:4 reserved
  // TI1[0] to TI1[15] input selection
  ETL_BFF_FIELD(3:0, uint8_t, TI1SEL)
)

// AF1
//
// TIM alternate function option register 1
//
//   Offset: 0x060
ETL_BFF_REG_RW(uint32_t, AF1,
  // 31:14 reserved
  // BRK COMP4 input polarity
  ETL_BFF_FIELD(13:13, bool, BKCMP4P)
  // BRK COMP3 input polarity
  ETL_BFF_FIELD(12:12, bool, BKCMP3P)
  // BRK COMP2 input polarity
  ETL_BFF_FIELD(11:11, bool, BKCMP2P)
  // BRK COMP1 input polarity
  ETL_BFF_FIELD(10:10, bool, BKCMP1P)
  // BRK BKIN input polarity
  ETL_BFF_FIELD(9:9, bool, BKINP)
  // 8 reserved
  // BRK COMP7 enable
  ETL_BFF_FIELD(7:7, bool, BKCMP7E)
  // BRK COMP6 enable
  ETL_BFF_FIELD(6:6, bool, BKCMP6E)
  // BRK COMP5 enable
  ETL_BFF_FIELD(5:5, bool, BKCMP5E)
  // BRK COMP4 enable
  ETL_BFF_FIELD(4:4, bool, BKCMP4E)
  // BRK COMP3 enable
  ETL_BFF_FIELD(3:3, bool, BKCMP3E)
  // BRK COMP2 enable
  ETL_BFF_FIELD(2:2, bool, BKCMP2E)
  // BRK COMP1 enable
  ETL_BFF_FIELD(1:1, bool, BKCMP1E)
  // BRK BKIN input enable
  ETL_BFF_FIELD(0:0, bool, BKINE)
)

// AF2
//
// TIM alternate function option register 2
//
//   Offset: 0x064
ETL_BFF_REG_RW(uint32_t, AF2,
  // 31:19 reserved
  // OCREF_CLR source selection
  ETL_BFF_FIELD(18:16, uint8_t, OCRSEL)
  // 15:0 reserved
)

// OR1
//
// Option register 1
//
//   Offset: 0x068
ETL_BFF_REG_RW(uint32_t, OR1,
  // 31:1 reserved
  // HSE Divided by 32 enable
  ETL_BFF_FIELD(0:0, bool, HSE32EN)
)

ETL_BFF_REG_RESERVED(uint32_t, reserved18, 220)

// DCR
//
// DMA control register
//
//   Offset: 0x3DC
ETL_BFF_REG_RW(uint32_t, DCR,
  // 31:13 reserved
  // DMA burst length
  ETL_BFF_FIELD(12:8, uint8_t, DBL)
  // 7:5 reserved
  // DMA base address
  ETL_BFF_FIELD(4:0, uint8_t, DBA)
)

// DMAR
//
// DMA address for full transfer
//
//   Offset: 0x3E0
ETL_BFF_REG_RW(uint32_t, DMAR,
  // DMA register for burst accesses
  ETL_BFF_FIELD(31:0, uint32_t, DMAB)
)

// clang-format on
