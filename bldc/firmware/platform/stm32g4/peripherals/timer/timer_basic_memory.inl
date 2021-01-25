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
  // 10:8 reserved
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
  // 31:7 reserved
  // Master mode selection
  ETL_BFF_FIELD(6:4, uint8_t, MMS)
  // 3:0 reserved
)

ETL_BFF_REG_RESERVED(uint32_t, reserved1, 1)

// DIER
//
// DMA/Interrupt enable register
//
//   Offset: 0x00C
ETL_BFF_REG_RW(uint32_t, DIER,
  // 31:9 reserved
  // Update DMA request enable
  ETL_BFF_FIELD(8:8, bool, UDE)
  // 7:1 reserved
  // Update interrupt enable
  ETL_BFF_FIELD(0:0, bool, UIE)
)

// SR
//
// status register
//
//   Offset: 0x010
ETL_BFF_REG_RW(uint32_t, SR,
  // 31:1 reserved
  // Update interrupt flag
  ETL_BFF_FIELD(0:0, bool, UIF)
)

// EGR
//
// event generation register
//
//   Offset: 0x014
ETL_BFF_REG_RW(uint32_t, EGR,
  // 31:1 reserved
  // Update generation
  ETL_BFF_FIELD(0:0, bool, UG)
)

ETL_BFF_REG_RESERVED(uint32_t, reserved4, 3)

// CNT
//
// counter
//
//   Offset: 0x024
ETL_BFF_REG_RW(uint32_t, CNT,
  // UIF Copy
  ETL_BFF_FIELD(31:31, bool, UIFCPY)
  // 30:16 reserved
  // Low counter value
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
  // 31:16 reserved
  // Low Auto-reload value
  ETL_BFF_FIELD(15:0, uint16_t, ARR)
)

// clang-format on
