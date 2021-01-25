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

// clang-format on
