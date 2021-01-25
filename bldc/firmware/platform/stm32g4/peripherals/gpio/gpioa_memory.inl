// clang-format off

// MODER
//
// GPIO port mode register
//
//   Offset: 0x000
//   Reset value: 0xABFFFFFF
ETL_BFF_REG_RW(uint32_t, MODER,
  // Port x configuration bits (y = 0..15)
  ETL_BFF_FIELD(31:30, uint8_t, MODER15)
  // Port x configuration bits (y = 0..15)
  ETL_BFF_FIELD(29:28, uint8_t, MODER14)
  // Port x configuration bits (y = 0..15)
  ETL_BFF_FIELD(27:26, uint8_t, MODER13)
  // Port x configuration bits (y = 0..15)
  ETL_BFF_FIELD(25:24, uint8_t, MODER12)
  // Port x configuration bits (y = 0..15)
  ETL_BFF_FIELD(23:22, uint8_t, MODER11)
  // Port x configuration bits (y = 0..15)
  ETL_BFF_FIELD(21:20, uint8_t, MODER10)
  // Port x configuration bits (y = 0..15)
  ETL_BFF_FIELD(19:18, uint8_t, MODER9)
  // Port x configuration bits (y = 0..15)
  ETL_BFF_FIELD(17:16, uint8_t, MODER8)
  // Port x configuration bits (y = 0..15)
  ETL_BFF_FIELD(15:14, uint8_t, MODER7)
  // Port x configuration bits (y = 0..15)
  ETL_BFF_FIELD(13:12, uint8_t, MODER6)
  // Port x configuration bits (y = 0..15)
  ETL_BFF_FIELD(11:10, uint8_t, MODER5)
  // Port x configuration bits (y = 0..15)
  ETL_BFF_FIELD(9:8, uint8_t, MODER4)
  // Port x configuration bits (y = 0..15)
  ETL_BFF_FIELD(7:6, uint8_t, MODER3)
  // Port x configuration bits (y = 0..15)
  ETL_BFF_FIELD(5:4, uint8_t, MODER2)
  // Port x configuration bits (y = 0..15)
  ETL_BFF_FIELD(3:2, uint8_t, MODER1)
  // Port x configuration bits (y = 0..15)
  ETL_BFF_FIELD(1:0, uint8_t, MODER0)
)

// OTYPER
//
// GPIO port output type register
//
//   Offset: 0x004
ETL_BFF_REG_RW(uint32_t, OTYPER,
  // 31:16 reserved
  // Port x configuration bits (y = 0..15)
  ETL_BFF_FIELD(15:15, bool, OT15)
  // Port x configuration bits (y = 0..15)
  ETL_BFF_FIELD(14:14, bool, OT14)
  // Port x configuration bits (y = 0..15)
  ETL_BFF_FIELD(13:13, bool, OT13)
  // Port x configuration bits (y = 0..15)
  ETL_BFF_FIELD(12:12, bool, OT12)
  // Port x configuration bits (y = 0..15)
  ETL_BFF_FIELD(11:11, bool, OT11)
  // Port x configuration bits (y = 0..15)
  ETL_BFF_FIELD(10:10, bool, OT10)
  // Port x configuration bits (y = 0..15)
  ETL_BFF_FIELD(9:9, bool, OT9)
  // Port x configuration bits (y = 0..15)
  ETL_BFF_FIELD(8:8, bool, OT8)
  // Port x configuration bits (y = 0..15)
  ETL_BFF_FIELD(7:7, bool, OT7)
  // Port x configuration bits (y = 0..15)
  ETL_BFF_FIELD(6:6, bool, OT6)
  // Port x configuration bits (y = 0..15)
  ETL_BFF_FIELD(5:5, bool, OT5)
  // Port x configuration bits (y = 0..15)
  ETL_BFF_FIELD(4:4, bool, OT4)
  // Port x configuration bits (y = 0..15)
  ETL_BFF_FIELD(3:3, bool, OT3)
  // Port x configuration bits (y = 0..15)
  ETL_BFF_FIELD(2:2, bool, OT2)
  // Port x configuration bits (y = 0..15)
  ETL_BFF_FIELD(1:1, bool, OT1)
  // Port x configuration bits (y = 0..15)
  ETL_BFF_FIELD(0:0, bool, OT0)
)

// OSPEEDR
//
// GPIO port output speed register
//
//   Offset: 0x008
//   Reset value: 0x0C000000
ETL_BFF_REG_RW(uint32_t, OSPEEDR,
  // Port x configuration bits (y = 0..15)
  ETL_BFF_FIELD(31:30, uint8_t, OSPEEDR15)
  // Port x configuration bits (y = 0..15)
  ETL_BFF_FIELD(29:28, uint8_t, OSPEEDR14)
  // Port x configuration bits (y = 0..15)
  ETL_BFF_FIELD(27:26, uint8_t, OSPEEDR13)
  // Port x configuration bits (y = 0..15)
  ETL_BFF_FIELD(25:24, uint8_t, OSPEEDR12)
  // Port x configuration bits (y = 0..15)
  ETL_BFF_FIELD(23:22, uint8_t, OSPEEDR11)
  // Port x configuration bits (y = 0..15)
  ETL_BFF_FIELD(21:20, uint8_t, OSPEEDR10)
  // Port x configuration bits (y = 0..15)
  ETL_BFF_FIELD(19:18, uint8_t, OSPEEDR9)
  // Port x configuration bits (y = 0..15)
  ETL_BFF_FIELD(17:16, uint8_t, OSPEEDR8)
  // Port x configuration bits (y = 0..15)
  ETL_BFF_FIELD(15:14, uint8_t, OSPEEDR7)
  // Port x configuration bits (y = 0..15)
  ETL_BFF_FIELD(13:12, uint8_t, OSPEEDR6)
  // Port x configuration bits (y = 0..15)
  ETL_BFF_FIELD(11:10, uint8_t, OSPEEDR5)
  // Port x configuration bits (y = 0..15)
  ETL_BFF_FIELD(9:8, uint8_t, OSPEEDR4)
  // Port x configuration bits (y = 0..15)
  ETL_BFF_FIELD(7:6, uint8_t, OSPEEDR3)
  // Port x configuration bits (y = 0..15)
  ETL_BFF_FIELD(5:4, uint8_t, OSPEEDR2)
  // Port x configuration bits (y = 0..15)
  ETL_BFF_FIELD(3:2, uint8_t, OSPEEDR1)
  // Port x configuration bits (y = 0..15)
  ETL_BFF_FIELD(1:0, uint8_t, OSPEEDR0)
)

// PUPDR
//
// GPIO port pull-up/pull-down register
//
//   Offset: 0x00C
//   Reset value: 0x64000000
ETL_BFF_REG_RW(uint32_t, PUPDR,
  // Port x configuration bits (y = 0..15)
  ETL_BFF_FIELD(31:30, uint8_t, PUPDR15)
  // Port x configuration bits (y = 0..15)
  ETL_BFF_FIELD(29:28, uint8_t, PUPDR14)
  // Port x configuration bits (y = 0..15)
  ETL_BFF_FIELD(27:26, uint8_t, PUPDR13)
  // Port x configuration bits (y = 0..15)
  ETL_BFF_FIELD(25:24, uint8_t, PUPDR12)
  // Port x configuration bits (y = 0..15)
  ETL_BFF_FIELD(23:22, uint8_t, PUPDR11)
  // Port x configuration bits (y = 0..15)
  ETL_BFF_FIELD(21:20, uint8_t, PUPDR10)
  // Port x configuration bits (y = 0..15)
  ETL_BFF_FIELD(19:18, uint8_t, PUPDR9)
  // Port x configuration bits (y = 0..15)
  ETL_BFF_FIELD(17:16, uint8_t, PUPDR8)
  // Port x configuration bits (y = 0..15)
  ETL_BFF_FIELD(15:14, uint8_t, PUPDR7)
  // Port x configuration bits (y = 0..15)
  ETL_BFF_FIELD(13:12, uint8_t, PUPDR6)
  // Port x configuration bits (y = 0..15)
  ETL_BFF_FIELD(11:10, uint8_t, PUPDR5)
  // Port x configuration bits (y = 0..15)
  ETL_BFF_FIELD(9:8, uint8_t, PUPDR4)
  // Port x configuration bits (y = 0..15)
  ETL_BFF_FIELD(7:6, uint8_t, PUPDR3)
  // Port x configuration bits (y = 0..15)
  ETL_BFF_FIELD(5:4, uint8_t, PUPDR2)
  // Port x configuration bits (y = 0..15)
  ETL_BFF_FIELD(3:2, uint8_t, PUPDR1)
  // Port x configuration bits (y = 0..15)
  ETL_BFF_FIELD(1:0, uint8_t, PUPDR0)
)

// IDR
//
// GPIO port input data register
//
//   Offset: 0x010
ETL_BFF_REG_RO(uint32_t, IDR,
  // 31:16 reserved
  // Port input data (y = 0..15)
  ETL_BFF_FIELD(15:15, bool, IDR15)
  // Port input data (y = 0..15)
  ETL_BFF_FIELD(14:14, bool, IDR14)
  // Port input data (y = 0..15)
  ETL_BFF_FIELD(13:13, bool, IDR13)
  // Port input data (y = 0..15)
  ETL_BFF_FIELD(12:12, bool, IDR12)
  // Port input data (y = 0..15)
  ETL_BFF_FIELD(11:11, bool, IDR11)
  // Port input data (y = 0..15)
  ETL_BFF_FIELD(10:10, bool, IDR10)
  // Port input data (y = 0..15)
  ETL_BFF_FIELD(9:9, bool, IDR9)
  // Port input data (y = 0..15)
  ETL_BFF_FIELD(8:8, bool, IDR8)
  // Port input data (y = 0..15)
  ETL_BFF_FIELD(7:7, bool, IDR7)
  // Port input data (y = 0..15)
  ETL_BFF_FIELD(6:6, bool, IDR6)
  // Port input data (y = 0..15)
  ETL_BFF_FIELD(5:5, bool, IDR5)
  // Port input data (y = 0..15)
  ETL_BFF_FIELD(4:4, bool, IDR4)
  // Port input data (y = 0..15)
  ETL_BFF_FIELD(3:3, bool, IDR3)
  // Port input data (y = 0..15)
  ETL_BFF_FIELD(2:2, bool, IDR2)
  // Port input data (y = 0..15)
  ETL_BFF_FIELD(1:1, bool, IDR1)
  // Port input data (y = 0..15)
  ETL_BFF_FIELD(0:0, bool, IDR0)
)

// ODR
//
// GPIO port output data register
//
//   Offset: 0x014
ETL_BFF_REG_RW(uint32_t, ODR,
  // 31:16 reserved
  // Port output data (y = 0..15)
  ETL_BFF_FIELD(15:15, bool, ODR15)
  // Port output data (y = 0..15)
  ETL_BFF_FIELD(14:14, bool, ODR14)
  // Port output data (y = 0..15)
  ETL_BFF_FIELD(13:13, bool, ODR13)
  // Port output data (y = 0..15)
  ETL_BFF_FIELD(12:12, bool, ODR12)
  // Port output data (y = 0..15)
  ETL_BFF_FIELD(11:11, bool, ODR11)
  // Port output data (y = 0..15)
  ETL_BFF_FIELD(10:10, bool, ODR10)
  // Port output data (y = 0..15)
  ETL_BFF_FIELD(9:9, bool, ODR9)
  // Port output data (y = 0..15)
  ETL_BFF_FIELD(8:8, bool, ODR8)
  // Port output data (y = 0..15)
  ETL_BFF_FIELD(7:7, bool, ODR7)
  // Port output data (y = 0..15)
  ETL_BFF_FIELD(6:6, bool, ODR6)
  // Port output data (y = 0..15)
  ETL_BFF_FIELD(5:5, bool, ODR5)
  // Port output data (y = 0..15)
  ETL_BFF_FIELD(4:4, bool, ODR4)
  // Port output data (y = 0..15)
  ETL_BFF_FIELD(3:3, bool, ODR3)
  // Port output data (y = 0..15)
  ETL_BFF_FIELD(2:2, bool, ODR2)
  // Port output data (y = 0..15)
  ETL_BFF_FIELD(1:1, bool, ODR1)
  // Port output data (y = 0..15)
  ETL_BFF_FIELD(0:0, bool, ODR0)
)

// BSRR
//
// GPIO port bit set/reset register
//
//   Offset: 0x018
ETL_BFF_REG_RW(uint32_t, BSRR,
  // Port x reset bit y (y = 0..15)
  ETL_BFF_FIELD(31:31, bool, BR15)
  // Port x reset bit y (y = 0..15)
  ETL_BFF_FIELD(30:30, bool, BR14)
  // Port x reset bit y (y = 0..15)
  ETL_BFF_FIELD(29:29, bool, BR13)
  // Port x reset bit y (y = 0..15)
  ETL_BFF_FIELD(28:28, bool, BR12)
  // Port x reset bit y (y = 0..15)
  ETL_BFF_FIELD(27:27, bool, BR11)
  // Port x reset bit y (y = 0..15)
  ETL_BFF_FIELD(26:26, bool, BR10)
  // Port x reset bit y (y = 0..15)
  ETL_BFF_FIELD(25:25, bool, BR9)
  // Port x reset bit y (y = 0..15)
  ETL_BFF_FIELD(24:24, bool, BR8)
  // Port x reset bit y (y = 0..15)
  ETL_BFF_FIELD(23:23, bool, BR7)
  // Port x reset bit y (y = 0..15)
  ETL_BFF_FIELD(22:22, bool, BR6)
  // Port x reset bit y (y = 0..15)
  ETL_BFF_FIELD(21:21, bool, BR5)
  // Port x reset bit y (y = 0..15)
  ETL_BFF_FIELD(20:20, bool, BR4)
  // Port x reset bit y (y = 0..15)
  ETL_BFF_FIELD(19:19, bool, BR3)
  // Port x reset bit y (y = 0..15)
  ETL_BFF_FIELD(18:18, bool, BR2)
  // Port x reset bit y (y = 0..15)
  ETL_BFF_FIELD(17:17, bool, BR1)
  // Port x set bit y (y= 0..15)
  ETL_BFF_FIELD(16:16, bool, BR0)
  // Port x set bit y (y= 0..15)
  ETL_BFF_FIELD(15:15, bool, BS15)
  // Port x set bit y (y= 0..15)
  ETL_BFF_FIELD(14:14, bool, BS14)
  // Port x set bit y (y= 0..15)
  ETL_BFF_FIELD(13:13, bool, BS13)
  // Port x set bit y (y= 0..15)
  ETL_BFF_FIELD(12:12, bool, BS12)
  // Port x set bit y (y= 0..15)
  ETL_BFF_FIELD(11:11, bool, BS11)
  // Port x set bit y (y= 0..15)
  ETL_BFF_FIELD(10:10, bool, BS10)
  // Port x set bit y (y= 0..15)
  ETL_BFF_FIELD(9:9, bool, BS9)
  // Port x set bit y (y= 0..15)
  ETL_BFF_FIELD(8:8, bool, BS8)
  // Port x set bit y (y= 0..15)
  ETL_BFF_FIELD(7:7, bool, BS7)
  // Port x set bit y (y= 0..15)
  ETL_BFF_FIELD(6:6, bool, BS6)
  // Port x set bit y (y= 0..15)
  ETL_BFF_FIELD(5:5, bool, BS5)
  // Port x set bit y (y= 0..15)
  ETL_BFF_FIELD(4:4, bool, BS4)
  // Port x set bit y (y= 0..15)
  ETL_BFF_FIELD(3:3, bool, BS3)
  // Port x set bit y (y= 0..15)
  ETL_BFF_FIELD(2:2, bool, BS2)
  // Port x set bit y (y= 0..15)
  ETL_BFF_FIELD(1:1, bool, BS1)
  // Port x set bit y (y= 0..15)
  ETL_BFF_FIELD(0:0, bool, BS0)
)

// LCKR
//
// GPIO port configuration lock register
//
//   Offset: 0x01C
ETL_BFF_REG_RW(uint32_t, LCKR,
  // 31:17 reserved
  // Lock key
  ETL_BFF_FIELD(16:16, bool, LCKK)
  // Port x lock bit y (y= 0..15)
  ETL_BFF_FIELD(15:15, bool, LCK15)
  // Port x lock bit y (y= 0..15)
  ETL_BFF_FIELD(14:14, bool, LCK14)
  // Port x lock bit y (y= 0..15)
  ETL_BFF_FIELD(13:13, bool, LCK13)
  // Port x lock bit y (y= 0..15)
  ETL_BFF_FIELD(12:12, bool, LCK12)
  // Port x lock bit y (y= 0..15)
  ETL_BFF_FIELD(11:11, bool, LCK11)
  // Port x lock bit y (y= 0..15)
  ETL_BFF_FIELD(10:10, bool, LCK10)
  // Port x lock bit y (y= 0..15)
  ETL_BFF_FIELD(9:9, bool, LCK9)
  // Port x lock bit y (y= 0..15)
  ETL_BFF_FIELD(8:8, bool, LCK8)
  // Port x lock bit y (y= 0..15)
  ETL_BFF_FIELD(7:7, bool, LCK7)
  // Port x lock bit y (y= 0..15)
  ETL_BFF_FIELD(6:6, bool, LCK6)
  // Port x lock bit y (y= 0..15)
  ETL_BFF_FIELD(5:5, bool, LCK5)
  // Port x lock bit y (y= 0..15)
  ETL_BFF_FIELD(4:4, bool, LCK4)
  // Port x lock bit y (y= 0..15)
  ETL_BFF_FIELD(3:3, bool, LCK3)
  // Port x lock bit y (y= 0..15)
  ETL_BFF_FIELD(2:2, bool, LCK2)
  // Port x lock bit y (y= 0..15)
  ETL_BFF_FIELD(1:1, bool, LCK1)
  // Port x lock bit y (y= 0..15)
  ETL_BFF_FIELD(0:0, bool, LCK0)
)

// AFRL
//
// GPIO alternate function low register
//
//   Offset: 0x020
ETL_BFF_REG_RW(uint32_t, AFRL,
  // Alternate function selection for port x bit y (y = 0..7)
  ETL_BFF_FIELD(31:28, uint8_t, AFRL7)
  // Alternate function selection for port x bit y (y = 0..7)
  ETL_BFF_FIELD(27:24, uint8_t, AFRL6)
  // Alternate function selection for port x bit y (y = 0..7)
  ETL_BFF_FIELD(23:20, uint8_t, AFRL5)
  // Alternate function selection for port x bit y (y = 0..7)
  ETL_BFF_FIELD(19:16, uint8_t, AFRL4)
  // Alternate function selection for port x bit y (y = 0..7)
  ETL_BFF_FIELD(15:12, uint8_t, AFRL3)
  // Alternate function selection for port x bit y (y = 0..7)
  ETL_BFF_FIELD(11:8, uint8_t, AFRL2)
  // Alternate function selection for port x bit y (y = 0..7)
  ETL_BFF_FIELD(7:4, uint8_t, AFRL1)
  // Alternate function selection for port x bit y (y = 0..7)
  ETL_BFF_FIELD(3:0, uint8_t, AFRL0)
)

// AFRH
//
// GPIO alternate function high register
//
//   Offset: 0x024
ETL_BFF_REG_RW(uint32_t, AFRH,
  // Alternate function selection for port x bit y (y = 8..15)
  ETL_BFF_FIELD(31:28, uint8_t, AFRH15)
  // Alternate function selection for port x bit y (y = 8..15)
  ETL_BFF_FIELD(27:24, uint8_t, AFRH14)
  // Alternate function selection for port x bit y (y = 8..15)
  ETL_BFF_FIELD(23:20, uint8_t, AFRH13)
  // Alternate function selection for port x bit y (y = 8..15)
  ETL_BFF_FIELD(19:16, uint8_t, AFRH12)
  // Alternate function selection for port x bit y (y = 8..15)
  ETL_BFF_FIELD(15:12, uint8_t, AFRH11)
  // Alternate function selection for port x bit y (y = 8..15)
  ETL_BFF_FIELD(11:8, uint8_t, AFRH10)
  // Alternate function selection for port x bit y (y = 8..15)
  ETL_BFF_FIELD(7:4, uint8_t, AFRH9)
  // Alternate function selection for port x bit y (y = 8..15)
  ETL_BFF_FIELD(3:0, uint8_t, AFRH8)
)

// BRR
//
// GPIO port bit reset register
//
//   Offset: 0x028
ETL_BFF_REG_RW(uint32_t, BRR,
  // 31:16 reserved
  // Port Reset bit
  ETL_BFF_FIELD(15:15, bool, BR15)
  // Port Reset bit
  ETL_BFF_FIELD(14:14, bool, BR14)
  // Port Reset bit
  ETL_BFF_FIELD(13:13, bool, BR13)
  // Port Reset bit
  ETL_BFF_FIELD(12:12, bool, BR12)
  // Port Reset bit
  ETL_BFF_FIELD(11:11, bool, BR11)
  // Port Reset bit
  ETL_BFF_FIELD(10:10, bool, BR10)
  // Port Reset bit
  ETL_BFF_FIELD(9:9, bool, BR9)
  // Port Reset bit
  ETL_BFF_FIELD(8:8, bool, BR8)
  // Port Reset bit
  ETL_BFF_FIELD(7:7, bool, BR7)
  // Port Reset bit
  ETL_BFF_FIELD(6:6, bool, BR6)
  // Port Reset bit
  ETL_BFF_FIELD(5:5, bool, BR5)
  // Port Reset bit
  ETL_BFF_FIELD(4:4, bool, BR4)
  // Port Reset bit
  ETL_BFF_FIELD(3:3, bool, BR3)
  // Port Reset bit
  ETL_BFF_FIELD(2:2, bool, BR2)
  // Port Reset bit
  ETL_BFF_FIELD(1:1, bool, BR1)
  // Port Reset bit
  ETL_BFF_FIELD(0:0, bool, BR0)
)

// clang-format on
