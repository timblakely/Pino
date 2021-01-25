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
  // Center-aligned mode selection
  ETL_BFF_FIELD(6:5, uint8_t, CMS)
  // Direction
  ETL_BFF_FIELD(4:4, bool, DIR)
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
// Control register 2
//
//   Offset: 0x004
ETL_BFF_REG_RW(uint32_t, CR2,
  // 31:26 reserved
  // high bit of MMS
  ETL_BFF_FIELD(25:25, bool, MMS_3)
  // 24:8 reserved
  // tim_ti1 selection
  ETL_BFF_FIELD(7:7, bool, TI1S)
  // Master mode selection
  ETL_BFF_FIELD(6:4, uint8_t, MMS)
  // Capture/control DMA selection
  ETL_BFF_FIELD(3:3, bool, CCDS)
  // 2:0 reserved
)

// SMCR
//
// slave mode control register
//
//   Offset: 0x008
ETL_BFF_REG_RW(uint32_t, SMCR,
  // 31:26 reserved
  // SMS Preload Source
  ETL_BFF_FIELD(25:25, bool, SMSPS)
  // SMS Preload Enable
  ETL_BFF_FIELD(24:24, bool, SMSPE)
  // 23:22 reserved
  // Trigger selection - bit 4:3
  ETL_BFF_FIELD(21:20, uint8_t, TS_4_3)
  // 19:17 reserved
  // Slave mode selection - bit 3
  ETL_BFF_FIELD(16:16, bool, SMS_3)
  // External trigger polarity
  ETL_BFF_FIELD(15:15, bool, ETP)
  // External clock enable
  ETL_BFF_FIELD(14:14, bool, ECE)
  // External trigger prescaler
  ETL_BFF_FIELD(13:12, uint8_t, ETPS)
  // External trigger filter
  ETL_BFF_FIELD(11:8, uint8_t, ETF)
  // Master/Slave mode
  ETL_BFF_FIELD(7:7, bool, MSM)
  // Trigger selection
  ETL_BFF_FIELD(6:4, uint8_t, TS)
  // OCREF clear selection
  ETL_BFF_FIELD(3:3, bool, OCCS)
  // Slave mode selection
  ETL_BFF_FIELD(2:0, uint8_t, SMS)
)

// DIER
//
// DMA/Interrupt enable register
//
//   Offset: 0x00C
ETL_BFF_REG_RW(uint32_t, DIER,
  // 31:24 reserved
  // Transition Error interrupt enable
  ETL_BFF_FIELD(23:23, bool, TERRIE)
  // Index Error interrupt enable
  ETL_BFF_FIELD(22:22, bool, IERRIE)
  // Direction Change interrupt enable
  ETL_BFF_FIELD(21:21, bool, DIRIE)
  // Index interrupt enable
  ETL_BFF_FIELD(20:20, bool, IDXIE)
  // 19:15 reserved
  // Trigger DMA request enable
  ETL_BFF_FIELD(14:14, bool, TDE)
  // 13 reserved
  // Capture/Compare 4 DMA request enable
  ETL_BFF_FIELD(12:12, bool, CC4DE)
  // Capture/Compare 3 DMA request enable
  ETL_BFF_FIELD(11:11, bool, CC3DE)
  // Capture/Compare 2 DMA request enable
  ETL_BFF_FIELD(10:10, bool, CC2DE)
  // Capture/Compare 1 DMA request enable
  ETL_BFF_FIELD(9:9, bool, CC1DE)
  // Update DMA request enable
  ETL_BFF_FIELD(8:8, bool, UDE)
  // 7 reserved
  // Trigger interrupt enable
  ETL_BFF_FIELD(6:6, bool, TIE)
  // 5 reserved
  // Capture/Compare 4 interrupt enable
  ETL_BFF_FIELD(4:4, bool, CC4IE)
  // Capture/Compare 3 interrupt enable
  ETL_BFF_FIELD(3:3, bool, CC3IE)
  // Capture/Compare 2 interrupt enable
  ETL_BFF_FIELD(2:2, bool, CC2IE)
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
  // 31:24 reserved
  // Transition Error interrupt flag
  ETL_BFF_FIELD(23:23, bool, TERRF)
  // Index Error interrupt flag
  ETL_BFF_FIELD(22:22, bool, IERRF)
  // Direction Change interrupt flag
  ETL_BFF_FIELD(21:21, bool, DIRF)
  // Index interrupt flag
  ETL_BFF_FIELD(20:20, bool, IDXF)
  // 19:13 reserved
  // Capture/Compare 4 overcapture flag
  ETL_BFF_FIELD(12:12, bool, CC4OF)
  // Capture/Compare 3 overcapture flag
  ETL_BFF_FIELD(11:11, bool, CC3OF)
  // Capture/compare 2 overcapture flag
  ETL_BFF_FIELD(10:10, bool, CC2OF)
  // Capture/Compare 1 overcapture flag
  ETL_BFF_FIELD(9:9, bool, CC1OF)
  // 8:7 reserved
  // Trigger interrupt flag
  ETL_BFF_FIELD(6:6, bool, TIF)
  // 5 reserved
  // Capture/Compare 4 interrupt flag
  ETL_BFF_FIELD(4:4, bool, CC4IF)
  // Capture/Compare 3 interrupt flag
  ETL_BFF_FIELD(3:3, bool, CC3IF)
  // Capture/Compare 2 interrupt flag
  ETL_BFF_FIELD(2:2, bool, CC2IF)
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
  // 31:7 reserved
  // Trigger generation
  ETL_BFF_FIELD(6:6, bool, TG)
  // 5 reserved
  // Capture/compare 4 generation
  ETL_BFF_FIELD(4:4, bool, CC4G)
  // Capture/compare 3 generation
  ETL_BFF_FIELD(3:3, bool, CC3G)
  // Capture/compare 2 generation
  ETL_BFF_FIELD(2:2, bool, CC2G)
  // Capture/compare 1 generation
  ETL_BFF_FIELD(1:1, bool, CC1G)
  // Update generation
  ETL_BFF_FIELD(0:0, bool, UG)
)

// CCMR1
//
// capture/compare mode register 1 (output mode)
//
//   Offset: 0x018
ETL_BFF_REG_RW(uint32_t, CCMR1,
  // 31:25 reserved
  // Output Compare 2 mode - bit 3
  ETL_BFF_FIELD(24:24, bool, OC2M_3)
  // 23:17 reserved
  // Output Compare 1 mode - bit 3
  ETL_BFF_FIELD(16:16, bool, OC1M_3)
  // Output Compare 2 clear enable
  ETL_BFF_FIELD(15:15, bool, OC2CE)
  // Output Compare 2 mode
  ETL_BFF_FIELD(14:12, uint8_t, OC2M)
  // Output Compare 2 preload enable
  ETL_BFF_FIELD(11:11, bool, OC2PE)
  // Output Compare 2 fast enable
  ETL_BFF_FIELD(10:10, bool, OC2FE)
  // Capture/Compare 2 selection
  ETL_BFF_FIELD(9:8, uint8_t, CC2S)
  // Output Compare 1 clear enable
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

// CCMR2
//
// capture/compare mode register 2 (output mode)
//
//   Offset: 0x01C
ETL_BFF_REG_RW(uint32_t, CCMR2,
  // 31:25 reserved
  // Output Compare 4 mode - bit 3
  ETL_BFF_FIELD(24:24, bool, OC4M_3)
  // 23:17 reserved
  // Output Compare 3 mode - bit 3
  ETL_BFF_FIELD(16:16, bool, OC3M_3)
  // Output compare 4 clear enable
  ETL_BFF_FIELD(15:15, bool, OC4CE)
  // Output compare 4 mode
  ETL_BFF_FIELD(14:12, uint8_t, OC4M)
  // Output compare 4 preload enable
  ETL_BFF_FIELD(11:11, bool, OC4PE)
  // Output compare 4 fast enable
  ETL_BFF_FIELD(10:10, bool, OC4FE)
  // Capture/Compare 4 selection
  ETL_BFF_FIELD(9:8, uint8_t, CC4S)
  // Output compare 3 clear enable
  ETL_BFF_FIELD(7:7, bool, OC3CE)
  // Output compare 3 mode
  ETL_BFF_FIELD(6:4, uint8_t, OC3M)
  // Output compare 3 preload enable
  ETL_BFF_FIELD(3:3, bool, OC3PE)
  // Output compare 3 fast enable
  ETL_BFF_FIELD(2:2, bool, OC3FE)
  // Capture/Compare 3 selection
  ETL_BFF_FIELD(1:0, uint8_t, CC3S)
)

// CCER
//
// capture/compare enable register
//
//   Offset: 0x020
ETL_BFF_REG_RW(uint32_t, CCER,
  // 31:16 reserved
  // Capture/Compare 4 complementary output polarity
  ETL_BFF_FIELD(15:15, bool, CC4NP)
  // 14 reserved
  // Capture/Compare 3 output Polarity
  ETL_BFF_FIELD(13:13, bool, CC4P)
  // Capture/Compare 4 output enable
  ETL_BFF_FIELD(12:12, bool, CC4E)
  // Capture/Compare 3 output Polarity
  ETL_BFF_FIELD(11:11, bool, CC3NP)
  // 10 reserved
  // Capture/Compare 3 output Polarity
  ETL_BFF_FIELD(9:9, bool, CC3P)
  // Capture/Compare 3 output enable
  ETL_BFF_FIELD(8:8, bool, CC3E)
  // Capture/Compare 2 output Polarity
  ETL_BFF_FIELD(7:7, bool, CC2NP)
  // 6 reserved
  // Capture/Compare 2 output Polarity
  ETL_BFF_FIELD(5:5, bool, CC2P)
  // Capture/Compare 2 output enable
  ETL_BFF_FIELD(4:4, bool, CC2E)
  // Capture/Compare 1 output Polarity
  ETL_BFF_FIELD(3:3, bool, CC1NP)
  // 2 reserved
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
  ETL_BFF_FIELD(31:31, bool, UIFCPY)
  // counter value
  ETL_BFF_FIELD(30:0, uint32_t, CNT)
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
//   Reset value: 0xFFFFFFFF
ETL_BFF_REG_RW(uint32_t, ARR,
  // Auto-reload value
  ETL_BFF_FIELD(31:0, uint32_t, ARR)
)

// RCR
//
// repetition counter register
//
//   Offset: 0x030
ETL_BFF_REG_RW(uint32_t, RCR,
  // 31:16 reserved
  // Repetition counter value
  ETL_BFF_FIELD(15:0, uint16_t, REP)
)

// CCR1
//
// capture/compare register 1
//
//   Offset: 0x034
ETL_BFF_REG_RW(uint32_t, CCR1,
  // Capture/Compare 1 value
  ETL_BFF_FIELD(31:0, uint32_t, CCR1)
)

// CCR2
//
// capture/compare register 2
//
//   Offset: 0x038
ETL_BFF_REG_RW(uint32_t, CCR2,
  // 31:16 reserved
  // Capture/Compare 2 value
  ETL_BFF_FIELD(15:0, uint16_t, CCR2)
)

// CCR3
//
// capture/compare register 3
//
//   Offset: 0x03C
ETL_BFF_REG_RW(uint32_t, CCR3,
  // 31:16 reserved
  // Capture/Compare value
  ETL_BFF_FIELD(15:0, uint16_t, CCR3)
)

ETL_BFF_REG_RESERVED(uint32_t, reserved15, 3)

// CCR6
//
// capture/compare register 4
//
//   Offset: 0x04C
ETL_BFF_REG_RW(uint32_t, CCR6,
  // 31:16 reserved
  // Capture/Compare value
  ETL_BFF_FIELD(15:0, uint16_t, CCR6)
)

ETL_BFF_REG_RESERVED(uint32_t, reserved16, 2)

// ECR
//
// DMA control register
//
//   Offset: 0x058
ETL_BFF_REG_RW(uint32_t, ECR,
  // 31:27 reserved
  // Pulse Width prescaler
  ETL_BFF_FIELD(26:24, uint8_t, PWPRSC)
  // Pulse width
  ETL_BFF_FIELD(23:16, uint8_t, PW)
  // 15:8 reserved
  // Index Positioning
  ETL_BFF_FIELD(7:6, uint8_t, IPOS)
  // First Index
  ETL_BFF_FIELD(5:5, bool, FIDX)
  // 4:3 reserved
  // Index Direction
  ETL_BFF_FIELD(2:1, uint8_t, IDIR)
  // Index Enable
  ETL_BFF_FIELD(0:0, bool, IE)
)

// TISEL
//
// TIM timer input selection register
//
//   Offset: 0x05C
ETL_BFF_REG_RW(uint32_t, TISEL,
  // 31:28 reserved
  // TI4[0] to TI4[15] input selection
  ETL_BFF_FIELD(27:24, uint8_t, TI4SEL)
  // 23:20 reserved
  // TI3[0] to TI3[15] input selection
  ETL_BFF_FIELD(19:16, uint8_t, TI3SEL)
  // 15:12 reserved
  // TI2[0] to TI2[15] input selection
  ETL_BFF_FIELD(11:8, uint8_t, TI2SEL)
  // 7:4 reserved
  // TI1[0] to TI1[15] input selection
  ETL_BFF_FIELD(3:0, uint8_t, TI1SEL)
)

// AF1
//
// TIM alternate function option register 1
//
//   Offset: 0x060
ETL_BFF_REG_RW(uint32_t, AF1,
  // 31:18 reserved
  // ETR source selection
  ETL_BFF_FIELD(17:14, uint8_t, ETRSEL)
  // 13:0 reserved
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

ETL_BFF_REG_RESERVED(uint32_t, reserved20, 221)

// DCR
//
// control register
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
