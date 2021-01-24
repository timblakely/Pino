// clang-format off

// CTRL
//
// SysTick control and status register
//
//   Offset: 0x000
ETL_BFF_REG_RW(uint32_t, CTRL,
  // COUNTFLAG
  ETL_BFF_FIELD(16:16, bool, COUNTFLAG)
  // 15 : 3 reserved
  // Clock source selection
  ETL_BFF_FIELD(2:2, bool, CLKSOURCE)
  // SysTick exception request enable
  ETL_BFF_FIELD(1:1, bool, TICKINT)
  // Counter enable
  ETL_BFF_FIELD(0:0, bool, ENABLE)
)

// LOAD
//
// SysTick reload value register
//
//   Offset: 0x004
ETL_BFF_REG_RW(uint32_t, LOAD,
  // RELOAD value
  ETL_BFF_FIELD(23:0, uint32_t, RELOAD)
)

// VAL
//
// SysTick current value register
//
//   Offset: 0x008
ETL_BFF_REG_RW(uint32_t, VAL,
  // Current counter value
  ETL_BFF_FIELD(23:0, uint32_t, CURRENT)
)

// CALIB
//
// SysTick calibration value register
//
//   Offset: 0x00C
ETL_BFF_REG_RW(uint32_t, CALIB,
  // NOREF flag. Reads as zero
  ETL_BFF_FIELD(31:31, bool, NOREF)
  // SKEW flag: Indicates whether the TENMS value is exact
  ETL_BFF_FIELD(30:30, bool, SKEW)
  // 29 : 24 reserved
  // Calibration value
  ETL_BFF_FIELD(23:0, uint32_t, TENMS)
)

// clang-format on
