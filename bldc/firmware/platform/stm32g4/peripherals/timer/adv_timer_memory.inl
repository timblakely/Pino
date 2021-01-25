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
  ETL_BFF_FIELD_E(9:8, uint8_t, CKD,
    ETL_BFF_ENUM(0b00, div1)
    ETL_BFF_ENUM(0b01, div2)
    ETL_BFF_ENUM(0b10, div4)
  )
  // Auto-reload preload enable
  ETL_BFF_FIELD(7:7, bool, ARPE)
  // Center-aligned mode selection
  ETL_BFF_FIELD_E(6:5, uint8_t, CMS,
    ETL_BFF_ENUM(0b00, edge_aligned)
    ETL_BFF_ENUM(0b01, center_aligned_1)
    ETL_BFF_ENUM(0b10, center_aligned_2)
    ETL_BFF_ENUM(0b11, center_aligned_3)
  )
  // Direction
  ETL_BFF_FIELD_E(4:4, bool, DIR,
    ETL_BFF_ENUM(0b0, up)
    ETL_BFF_ENUM(0b1, down)
  )
  // One-pulse mode
  ETL_BFF_FIELD(3:3, bool, OPM)
  // Update request source
  ETL_BFF_FIELD_E(2:2, bool, URS,
    ETL_BFF_ENUM(0b0, all)
    ETL_BFF_ENUM(0b1, only_overflow_underflow)
  )
  // Update disable
  ETL_BFF_FIELD_E(1:1, bool, UDIS,
    ETL_BFF_ENUM(0b0, enabled)
    ETL_BFF_ENUM(0b1, disabled)
  )
  // Counter enable
  ETL_BFF_FIELD(0:0, bool, CEN)
)

// CR2
//
// control register 2
//
//   Offset: 0x004
ETL_BFF_REG_RW(uint32_t, CR2,
  // 31:26 reserved
  // Master mode selection - bit 3
  ETL_BFF_FIELD(25:25, bool, MMS_3)
  // 24 reserved
  // Master mode selection 2
  ETL_BFF_FIELD(23:20, uint8_t, MMS2)
  // 19 reserved
  // Output Idle state 6 (OC6 output)
  ETL_BFF_FIELD(18:18, bool, OIS6)
  // 17 reserved
  // Output Idle state 5 (OC5 output)
  ETL_BFF_FIELD(16:16, bool, OIS5)
  // Output Idle state 4 (OC4N output)
  ETL_BFF_FIELD(15:15, bool, OIS4N)
  // Output Idle state 4
  ETL_BFF_FIELD(14:14, bool, OIS4)
  // Output Idle state 3
  ETL_BFF_FIELD(13:13, bool, OIS3N)
  // Output Idle state 3
  ETL_BFF_FIELD(12:12, bool, OIS3)
  // Output Idle state 2
  ETL_BFF_FIELD(11:11, bool, OIS2N)
  // Output Idle state 2
  ETL_BFF_FIELD(10:10, bool, OIS2)
  // Output Idle state 1
  ETL_BFF_FIELD(9:9, bool, OIS1N)
  // Output Idle state 1
  ETL_BFF_FIELD(8:8, bool, OIS1)
  // TI1 selection
  ETL_BFF_FIELD(7:7, bool, TI1S)
  // Master mode selection
  ETL_BFF_FIELD(6:4, uint8_t, MMS)
  // Capture/compare DMA selection
  ETL_BFF_FIELD(3:3, bool, CCDS)
  // Capture/compare control update selection
  ETL_BFF_FIELD(2:2, bool, CCUS)
  // 1 reserved
  // Capture/compare preloaded control
  ETL_BFF_FIELD(0:0, bool, CCPC)
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
  ETL_BFF_FIELD_E(15:15, bool, ETP,
    ETL_BFF_ENUM(0b0, normal)
    ETL_BFF_ENUM(0b1, inverted)
  )
  // External clock enable
  ETL_BFF_FIELD(14:14, bool, ECE)
  // External trigger prescaler
  ETL_BFF_FIELD_E(13:12, uint8_t, ETPS,
    ETL_BFF_ENUM(0b00, div1)
    ETL_BFF_ENUM(0b01, div2)
    ETL_BFF_ENUM(0b10, div4)
    ETL_BFF_ENUM(0b11, div8)
  )
  // External trigger filter
  ETL_BFF_FIELD_E(11:8, uint8_t, ETF,
    ETL_BFF_ENUM(0b0000, dts)
    ETL_BFF_ENUM(0b0001, kernel_ck_n2)
    ETL_BFF_ENUM(0b0010, kernel_ck_n4)
    ETL_BFF_ENUM(0b0011, kernel_ck_n8)
    ETL_BFF_ENUM(0b0100, dts_div2_n6)
    ETL_BFF_ENUM(0b0101, dts_div2_n8)
    ETL_BFF_ENUM(0b0110, dts_div4_n6)
    ETL_BFF_ENUM(0b0111, dts_div4_n8)
    ETL_BFF_ENUM(0b1000, dts_div8_n6)
    ETL_BFF_ENUM(0b1001, dts_div8_n8)
    ETL_BFF_ENUM(0b1010, dts_div16_n5)
    ETL_BFF_ENUM(0b1011, dts_div16_n6)
    ETL_BFF_ENUM(0b1100, dts_div16_n8)
    ETL_BFF_ENUM(0b1101, dts_div32_n5)
    ETL_BFF_ENUM(0b1110, dts_div32_n6)
    ETL_BFF_ENUM(0b1111, dts_div32_n8)
  )
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
  // COM DMA request enable
  ETL_BFF_FIELD(13:13, bool, COMDE)
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
  // Break interrupt enable
  ETL_BFF_FIELD(7:7, bool, BIE)
  // Trigger interrupt enable
  ETL_BFF_FIELD(6:6, bool, TIE)
  // COM interrupt enable
  ETL_BFF_FIELD(5:5, bool, COMIE)
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
  // 19:18 reserved
  // Compare 6 interrupt flag
  ETL_BFF_FIELD(17:17, bool, CC6IF)
  // Compare 5 interrupt flag
  ETL_BFF_FIELD(16:16, bool, CC5IF)
  // 15:14 reserved
  // System Break interrupt flag
  ETL_BFF_FIELD(13:13, bool, SBIF)
  // Capture/Compare 4 overcapture flag
  ETL_BFF_FIELD(12:12, bool, CC4OF)
  // Capture/Compare 3 overcapture flag
  ETL_BFF_FIELD(11:11, bool, CC3OF)
  // Capture/compare 2 overcapture flag
  ETL_BFF_FIELD(10:10, bool, CC2OF)
  // Capture/Compare 1 overcapture flag
  ETL_BFF_FIELD(9:9, bool, CC1OF)
  // Break 2 interrupt flag
  ETL_BFF_FIELD(8:8, bool, B2IF)
  // Break interrupt flag
  ETL_BFF_FIELD(7:7, bool, BIF)
  // Trigger interrupt flag
  ETL_BFF_FIELD(6:6, bool, TIF)
  // COM interrupt flag
  ETL_BFF_FIELD(5:5, bool, COMIF)
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
  // 31:9 reserved
  // Break 2 generation
  ETL_BFF_FIELD(8:8, bool, B2G)
  // Break generation
  ETL_BFF_FIELD(7:7, bool, BG)
  // Trigger generation
  ETL_BFF_FIELD(6:6, bool, TG)
  // Capture/Compare control update generation
  ETL_BFF_FIELD(5:5, bool, COMG)
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
  // 31:22 reserved
  // Capture/Compare 6 output polarity
  ETL_BFF_FIELD(21:21, bool, CC6P)
  // Capture/Compare 6 output enable
  ETL_BFF_FIELD(20:20, bool, CC6E)
  // 19:18 reserved
  // Capture/Compare 5 output polarity
  ETL_BFF_FIELD(17:17, bool, CC5P)
  // Capture/Compare 5 output enable
  ETL_BFF_FIELD(16:16, bool, CC5E)
  // Capture/Compare 4 complementary output polarity
  ETL_BFF_FIELD(15:15, bool, CC4NP)
  // Capture/Compare 4 complementary output enable
  ETL_BFF_FIELD(14:14, bool, CC4NE)
  // Capture/Compare 3 output Polarity
  ETL_BFF_FIELD(13:13, bool, CC4P)
  // Capture/Compare 4 output enable
  ETL_BFF_FIELD(12:12, bool, CC4E)
  // Capture/Compare 3 output Polarity
  ETL_BFF_FIELD(11:11, bool, CC3NP)
  // Capture/Compare 3 complementary output enable
  ETL_BFF_FIELD(10:10, bool, CC3NE)
  // Capture/Compare 3 output Polarity
  ETL_BFF_FIELD(9:9, bool, CC3P)
  // Capture/Compare 3 output enable
  ETL_BFF_FIELD(8:8, bool, CC3E)
  // Capture/Compare 2 output Polarity
  ETL_BFF_FIELD(7:7, bool, CC2NP)
  // Capture/Compare 2 complementary output enable
  ETL_BFF_FIELD(6:6, bool, CC2NE)
  // Capture/Compare 2 output Polarity
  ETL_BFF_FIELD(5:5, bool, CC2P)
  // Capture/Compare 2 output enable
  ETL_BFF_FIELD(4:4, bool, CC2E)
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
  // UIFCPY
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
  // ARR Dither bits
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
  // 31:20 reserved
  // CCR1 Dither bits
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
  // CCR2 Dither bits
  ETL_BFF_FIELD(19:16, uint8_t, CCR2_DITH)
  // Capture/Compare 2 value
  ETL_BFF_FIELD(15:0, uint16_t, CCR2)
)

// CCR3
//
// capture/compare register 3
//
//   Offset: 0x03C
ETL_BFF_REG_RW(uint32_t, CCR3,
  // 31:20 reserved
  // CCR3 Dither bits
  ETL_BFF_FIELD(19:16, uint8_t, CCR3_DITH)
  // Capture/Compare value
  ETL_BFF_FIELD(15:0, uint16_t, CCR3)
)

// CCR4
//
// capture/compare register 4
//
//   Offset: 0x040
ETL_BFF_REG_RW(uint32_t, CCR4,
  // 31:20 reserved
  // CCR4 Dither bits
  ETL_BFF_FIELD(19:16, uint8_t, CCR4_DITH)
  // Capture/Compare value
  ETL_BFF_FIELD(15:0, uint16_t, CCR4)
)

// BDTR
//
// break and dead-time register
//
//   Offset: 0x044
ETL_BFF_REG_RW(uint32_t, BDTR,
  // 31:30 reserved
  // BK2ID
  ETL_BFF_FIELD(29:29, bool, BK2ID)
  // BKBID
  ETL_BFF_FIELD(28:28, bool, BKBID)
  // BK2DSRM
  ETL_BFF_FIELD(27:27, bool, BK2DSRM)
  // BKDSRM
  ETL_BFF_FIELD(26:26, bool, BKDSRM)
  // Break 2 polarity
  ETL_BFF_FIELD(25:25, bool, BK2P)
  // Break 2 Enable
  ETL_BFF_FIELD(24:24, bool, BK2E)
  // Break 2 filter
  ETL_BFF_FIELD(23:20, uint8_t, BK2F)
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

// CCR5
//
// Capture/compare register 5
//
//   Offset: 0x048
ETL_BFF_REG_RW(uint32_t, CCR5,
  // Group Channel 5 and Channel 3
  ETL_BFF_FIELD(31:31, bool, GC5C3)
  // Group Channel 5 and Channel 2
  ETL_BFF_FIELD(30:30, bool, GC5C2)
  // Group Channel 5 and Channel 1
  ETL_BFF_FIELD(29:29, bool, GC5C1)
  // 28:20 reserved
  // CCR5 Dither bits
  ETL_BFF_FIELD(19:16, uint8_t, CCR5_DITH)
  // Capture/Compare value
  ETL_BFF_FIELD(15:0, uint16_t, CCR5)
)

// CCR6
//
// Capture/compare register 6
//
//   Offset: 0x04C
ETL_BFF_REG_RW(uint32_t, CCR6,
  // 31:20 reserved
  // CCR6 Dither bits
  ETL_BFF_FIELD(19:16, uint8_t, CCR6_DITH)
  // Capture/Compare value
  ETL_BFF_FIELD(15:0, uint16_t, CCR6)
)

// CCMR3
//
// capture/compare mode register 3
//
//   Offset: 0x050
ETL_BFF_REG_RW(uint32_t, CCMR3,
  // 31:25 reserved
  // Output Compare 6 mode bit 3
  ETL_BFF_FIELD(24:24, bool, OC6M_3)
  // 23:17 reserved
  // Output Compare 5 mode bit 3
  ETL_BFF_FIELD(16:16, bool, OC5M_3)
  // Output compare 6 clear enable
  ETL_BFF_FIELD(15:15, bool, OC6CE)
  // Output compare 6 mode
  ETL_BFF_FIELD(14:12, uint8_t, OC6M)
  // Output compare 6 preload enable
  ETL_BFF_FIELD(11:11, bool, OC6PE)
  // Output compare 6 fast enable
  ETL_BFF_FIELD(10:10, bool, OC6FE)
  // 9:8 reserved
  // Output compare 5 clear enable
  ETL_BFF_FIELD(7:7, bool, OC5CE)
  // Output compare 5 mode
  ETL_BFF_FIELD(6:4, uint8_t, OC5M)
  // Output compare 5 preload enable
  ETL_BFF_FIELD(3:3, bool, OC5PE)
  // Output compare 5 fast enable
  ETL_BFF_FIELD(2:2, bool, OC5FE)
  // 1:0 reserved
)

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
  // Dead-time falling edge generator setup
  ETL_BFF_FIELD(7:0, uint8_t, DTGF)
)

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
  // Index Blanking
  ETL_BFF_FIELD(4:3, uint8_t, IBLK)
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
  // 15:14 reserved
  // BRK2 COMP4 input polarity
  ETL_BFF_FIELD(13:13, bool, BK2CMP4P)
  // BRK2 COMP3 input polarity
  ETL_BFF_FIELD(12:12, bool, BK2CMP3P)
  // BRK2 COMP2 input polarity
  ETL_BFF_FIELD(11:11, bool, BK2CMP2P)
  // BRK2 COMP1 input polarity
  ETL_BFF_FIELD(10:10, bool, BK2CMP1P)
  // BRK2 BKIN input polarity
  ETL_BFF_FIELD(9:9, bool, BK2INP)
  // tim_brk2_cmp8 enable
  ETL_BFF_FIELD(8:8, bool, BK2CMP8E)
  // BRK2 COMP7 enable
  ETL_BFF_FIELD(7:7, bool, BK2CMP7E)
  // BRK2 COMP6 enable
  ETL_BFF_FIELD(6:6, bool, BK2CMP6E)
  // BRK2 COMP5 enable
  ETL_BFF_FIELD(5:5, bool, BK2CMP5E)
  // BRK2 COMP4 enable
  ETL_BFF_FIELD(4:4, bool, BK2CMP4E)
  // BRK2 COMP3 enable
  ETL_BFF_FIELD(3:3, bool, BK2CMP3E)
  // BRK2 COMP2 enable
  ETL_BFF_FIELD(2:2, bool, BK2CMP2E)
  // BRK2 COMP1 enable
  ETL_BFF_FIELD(1:1, bool, BK2CMP1E)
  // BRK BKIN input enable
  ETL_BFF_FIELD(0:0, bool, BKINE)
)

ETL_BFF_REG_RESERVED(uint32_t, reserved25, 221)

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
