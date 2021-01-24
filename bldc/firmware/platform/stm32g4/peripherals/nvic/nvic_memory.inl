// clang-format off

// ISER0
//
// Interrupt Set-Enable Register
//
//   Offset: 0x000
ETL_BFF_REG_RW(uint32_t, ISER0,
  // SETENA
  ETL_BFF_FIELD(31:0, uint32_t, SETENA)
)

// ISER1
//
// Interrupt Set-Enable Register
//
//   Offset: 0x004
ETL_BFF_REG_RW(uint32_t, ISER1,
  // SETENA
  ETL_BFF_FIELD(31:0, uint32_t, SETENA)
)

// ISER2
//
// Interrupt Set-Enable Register
//
//   Offset: 0x008
ETL_BFF_REG_RW(uint32_t, ISER2,
  // SETENA
  ETL_BFF_FIELD(31:0, uint32_t, SETENA)
)

// ISER3
//
// Interrupt Set-Enable Register
//
//   Offset: 0x00C
ETL_BFF_REG_RW(uint32_t, ISER3,
  // SETENA
  ETL_BFF_FIELD(31:0, uint32_t, SETENA)
)

ETL_BFF_REG_RESERVED(uint32_t, reserved1, 28)

// ICER0
//
// Interrupt Clear-Enable Register
//
//   Offset: 0x080
ETL_BFF_REG_RW(uint32_t, ICER0,
  // CLRENA
  ETL_BFF_FIELD(31:0, uint32_t, CLRENA)
)

// ICER1
//
// Interrupt Clear-Enable Register
//
//   Offset: 0x084
ETL_BFF_REG_RW(uint32_t, ICER1,
  // CLRENA
  ETL_BFF_FIELD(31:0, uint32_t, CLRENA)
)

// ICER2
//
// Interrupt Clear-Enable Register
//
//   Offset: 0x088
ETL_BFF_REG_RW(uint32_t, ICER2,
  // CLRENA
  ETL_BFF_FIELD(31:0, uint32_t, CLRENA)
)

// ICER3
//
// Interrupt Clear-Enable Register
//
//   Offset: 0x08C
ETL_BFF_REG_RW(uint32_t, ICER3,
  // CLRENA
  ETL_BFF_FIELD(31:0, uint32_t, CLRENA)
)

ETL_BFF_REG_RESERVED(uint32_t, reserved2, 28)

// ISPR0
//
// Interrupt Set-Pending Register
//
//   Offset: 0x100
ETL_BFF_REG_RW(uint32_t, ISPR0,
  // SETPEND
  ETL_BFF_FIELD(31:0, uint32_t, SETPEND)
)

// ISPR1
//
// Interrupt Set-Pending Register
//
//   Offset: 0x104
ETL_BFF_REG_RW(uint32_t, ISPR1,
  // SETPEND
  ETL_BFF_FIELD(31:0, uint32_t, SETPEND)
)

// ISPR2
//
// Interrupt Set-Pending Register
//
//   Offset: 0x108
ETL_BFF_REG_RW(uint32_t, ISPR2,
  // SETPEND
  ETL_BFF_FIELD(31:0, uint32_t, SETPEND)
)

// ISPR3
//
// Interrupt Set-Pending Register
//
//   Offset: 0x10C
ETL_BFF_REG_RW(uint32_t, ISPR3,
  // SETPEND
  ETL_BFF_FIELD(31:0, uint32_t, SETPEND)
)

ETL_BFF_REG_RESERVED(uint32_t, reserved3, 28)

// ICPR0
//
// Interrupt Clear-Pending Register
//
//   Offset: 0x180
ETL_BFF_REG_RW(uint32_t, ICPR0,
  // CLRPEND
  ETL_BFF_FIELD(31:0, uint32_t, CLRPEND)
)

// ICPR1
//
// Interrupt Clear-Pending Register
//
//   Offset: 0x184
ETL_BFF_REG_RW(uint32_t, ICPR1,
  // CLRPEND
  ETL_BFF_FIELD(31:0, uint32_t, CLRPEND)
)

// ICPR2
//
// Interrupt Clear-Pending Register
//
//   Offset: 0x188
ETL_BFF_REG_RW(uint32_t, ICPR2,
  // CLRPEND
  ETL_BFF_FIELD(31:0, uint32_t, CLRPEND)
)

// ICPR3
//
// Interrupt Clear-Pending Register
//
//   Offset: 0x18C
ETL_BFF_REG_RW(uint32_t, ICPR3,
  // CLRPEND
  ETL_BFF_FIELD(31:0, uint32_t, CLRPEND)
)

ETL_BFF_REG_RESERVED(uint32_t, reserved4, 28)

// IABR0
//
// Interrupt Active Bit Register
//
//   Offset: 0x200
ETL_BFF_REG_RO(uint32_t, IABR0,
  // ACTIVE
  ETL_BFF_FIELD(31:0, uint32_t, ACTIVE)
)

// IABR1
//
// Interrupt Active Bit Register
//
//   Offset: 0x204
ETL_BFF_REG_RO(uint32_t, IABR1,
  // ACTIVE
  ETL_BFF_FIELD(31:0, uint32_t, ACTIVE)
)

// IABR2
//
// Interrupt Active Bit Register
//
//   Offset: 0x208
ETL_BFF_REG_RO(uint32_t, IABR2,
  // ACTIVE
  ETL_BFF_FIELD(31:0, uint32_t, ACTIVE)
)

// IABR3
//
// Interrupt Active Bit Register
//
//   Offset: 0x20C
ETL_BFF_REG_RO(uint32_t, IABR3,
  // ACTIVE
  ETL_BFF_FIELD(31:0, uint32_t, ACTIVE)
)

ETL_BFF_REG_RESERVED(uint32_t, reserved5, 60)

// IPR0
//
// Interrupt Priority Register
//
//   Offset: 0x300
ETL_BFF_REG_RW(uint32_t, IPR0,
  // IPR_N3
  ETL_BFF_FIELD(31:24, uint8_t, IPR_N3)
  // IPR_N2
  ETL_BFF_FIELD(23:16, uint8_t, IPR_N2)
  // IPR_N1
  ETL_BFF_FIELD(15:8, uint8_t, IPR_N1)
  // IPR_N0
  ETL_BFF_FIELD(7:0, uint8_t, IPR_N0)
)

// IPR1
//
// Interrupt Priority Register
//
//   Offset: 0x304
ETL_BFF_REG_RW(uint32_t, IPR1,
  // IPR_N3
  ETL_BFF_FIELD(31:24, uint8_t, IPR_N3)
  // IPR_N2
  ETL_BFF_FIELD(23:16, uint8_t, IPR_N2)
  // IPR_N1
  ETL_BFF_FIELD(15:8, uint8_t, IPR_N1)
  // IPR_N0
  ETL_BFF_FIELD(7:0, uint8_t, IPR_N0)
)

// IPR2
//
// Interrupt Priority Register
//
//   Offset: 0x308
ETL_BFF_REG_RW(uint32_t, IPR2,
  // IPR_N3
  ETL_BFF_FIELD(31:24, uint8_t, IPR_N3)
  // IPR_N2
  ETL_BFF_FIELD(23:16, uint8_t, IPR_N2)
  // IPR_N1
  ETL_BFF_FIELD(15:8, uint8_t, IPR_N1)
  // IPR_N0
  ETL_BFF_FIELD(7:0, uint8_t, IPR_N0)
)

// IPR3
//
// Interrupt Priority Register
//
//   Offset: 0x30C
ETL_BFF_REG_RW(uint32_t, IPR3,
  // IPR_N3
  ETL_BFF_FIELD(31:24, uint8_t, IPR_N3)
  // IPR_N2
  ETL_BFF_FIELD(23:16, uint8_t, IPR_N2)
  // IPR_N1
  ETL_BFF_FIELD(15:8, uint8_t, IPR_N1)
  // IPR_N0
  ETL_BFF_FIELD(7:0, uint8_t, IPR_N0)
)

// IPR4
//
// Interrupt Priority Register
//
//   Offset: 0x310
ETL_BFF_REG_RW(uint32_t, IPR4,
  // IPR_N3
  ETL_BFF_FIELD(31:24, uint8_t, IPR_N3)
  // IPR_N2
  ETL_BFF_FIELD(23:16, uint8_t, IPR_N2)
  // IPR_N1
  ETL_BFF_FIELD(15:8, uint8_t, IPR_N1)
  // IPR_N0
  ETL_BFF_FIELD(7:0, uint8_t, IPR_N0)
)

// IPR5
//
// Interrupt Priority Register
//
//   Offset: 0x314
ETL_BFF_REG_RW(uint32_t, IPR5,
  // IPR_N3
  ETL_BFF_FIELD(31:24, uint8_t, IPR_N3)
  // IPR_N2
  ETL_BFF_FIELD(23:16, uint8_t, IPR_N2)
  // IPR_N1
  ETL_BFF_FIELD(15:8, uint8_t, IPR_N1)
  // IPR_N0
  ETL_BFF_FIELD(7:0, uint8_t, IPR_N0)
)

// IPR6
//
// Interrupt Priority Register
//
//   Offset: 0x318
ETL_BFF_REG_RW(uint32_t, IPR6,
  // IPR_N3
  ETL_BFF_FIELD(31:24, uint8_t, IPR_N3)
  // IPR_N2
  ETL_BFF_FIELD(23:16, uint8_t, IPR_N2)
  // IPR_N1
  ETL_BFF_FIELD(15:8, uint8_t, IPR_N1)
  // IPR_N0
  ETL_BFF_FIELD(7:0, uint8_t, IPR_N0)
)

// IPR7
//
// Interrupt Priority Register
//
//   Offset: 0x31C
ETL_BFF_REG_RW(uint32_t, IPR7,
  // IPR_N3
  ETL_BFF_FIELD(31:24, uint8_t, IPR_N3)
  // IPR_N2
  ETL_BFF_FIELD(23:16, uint8_t, IPR_N2)
  // IPR_N1
  ETL_BFF_FIELD(15:8, uint8_t, IPR_N1)
  // IPR_N0
  ETL_BFF_FIELD(7:0, uint8_t, IPR_N0)
)

// IPR8
//
// Interrupt Priority Register
//
//   Offset: 0x320
ETL_BFF_REG_RW(uint32_t, IPR8,
  // IPR_N3
  ETL_BFF_FIELD(31:24, uint8_t, IPR_N3)
  // IPR_N2
  ETL_BFF_FIELD(23:16, uint8_t, IPR_N2)
  // IPR_N1
  ETL_BFF_FIELD(15:8, uint8_t, IPR_N1)
  // IPR_N0
  ETL_BFF_FIELD(7:0, uint8_t, IPR_N0)
)

// IPR9
//
// Interrupt Priority Register
//
//   Offset: 0x324
ETL_BFF_REG_RW(uint32_t, IPR9,
  // IPR_N3
  ETL_BFF_FIELD(31:24, uint8_t, IPR_N3)
  // IPR_N2
  ETL_BFF_FIELD(23:16, uint8_t, IPR_N2)
  // IPR_N1
  ETL_BFF_FIELD(15:8, uint8_t, IPR_N1)
  // IPR_N0
  ETL_BFF_FIELD(7:0, uint8_t, IPR_N0)
)

// IPR10
//
// Interrupt Priority Register
//
//   Offset: 0x328
ETL_BFF_REG_RW(uint32_t, IPR10,
  // IPR_N3
  ETL_BFF_FIELD(31:24, uint8_t, IPR_N3)
  // IPR_N2
  ETL_BFF_FIELD(23:16, uint8_t, IPR_N2)
  // IPR_N1
  ETL_BFF_FIELD(15:8, uint8_t, IPR_N1)
  // IPR_N0
  ETL_BFF_FIELD(7:0, uint8_t, IPR_N0)
)

// IPR11
//
// Interrupt Priority Register
//
//   Offset: 0x32C
ETL_BFF_REG_RW(uint32_t, IPR11,
  // IPR_N3
  ETL_BFF_FIELD(31:24, uint8_t, IPR_N3)
  // IPR_N2
  ETL_BFF_FIELD(23:16, uint8_t, IPR_N2)
  // IPR_N1
  ETL_BFF_FIELD(15:8, uint8_t, IPR_N1)
  // IPR_N0
  ETL_BFF_FIELD(7:0, uint8_t, IPR_N0)
)

// IPR12
//
// Interrupt Priority Register
//
//   Offset: 0x330
ETL_BFF_REG_RW(uint32_t, IPR12,
  // IPR_N3
  ETL_BFF_FIELD(31:24, uint8_t, IPR_N3)
  // IPR_N2
  ETL_BFF_FIELD(23:16, uint8_t, IPR_N2)
  // IPR_N1
  ETL_BFF_FIELD(15:8, uint8_t, IPR_N1)
  // IPR_N0
  ETL_BFF_FIELD(7:0, uint8_t, IPR_N0)
)

// IPR13
//
// Interrupt Priority Register
//
//   Offset: 0x334
ETL_BFF_REG_RW(uint32_t, IPR13,
  // IPR_N3
  ETL_BFF_FIELD(31:24, uint8_t, IPR_N3)
  // IPR_N2
  ETL_BFF_FIELD(23:16, uint8_t, IPR_N2)
  // IPR_N1
  ETL_BFF_FIELD(15:8, uint8_t, IPR_N1)
  // IPR_N0
  ETL_BFF_FIELD(7:0, uint8_t, IPR_N0)
)

// IPR14
//
// Interrupt Priority Register
//
//   Offset: 0x338
ETL_BFF_REG_RW(uint32_t, IPR14,
  // IPR_N3
  ETL_BFF_FIELD(31:24, uint8_t, IPR_N3)
  // IPR_N2
  ETL_BFF_FIELD(23:16, uint8_t, IPR_N2)
  // IPR_N1
  ETL_BFF_FIELD(15:8, uint8_t, IPR_N1)
  // IPR_N0
  ETL_BFF_FIELD(7:0, uint8_t, IPR_N0)
)

// IPR15
//
// Interrupt Priority Register
//
//   Offset: 0x33C
ETL_BFF_REG_RW(uint32_t, IPR15,
  // IPR_N3
  ETL_BFF_FIELD(31:24, uint8_t, IPR_N3)
  // IPR_N2
  ETL_BFF_FIELD(23:16, uint8_t, IPR_N2)
  // IPR_N1
  ETL_BFF_FIELD(15:8, uint8_t, IPR_N1)
  // IPR_N0
  ETL_BFF_FIELD(7:0, uint8_t, IPR_N0)
)

// IPR16
//
// Interrupt Priority Register
//
//   Offset: 0x340
ETL_BFF_REG_RW(uint32_t, IPR16,
  // IPR_N3
  ETL_BFF_FIELD(31:24, uint8_t, IPR_N3)
  // IPR_N2
  ETL_BFF_FIELD(23:16, uint8_t, IPR_N2)
  // IPR_N1
  ETL_BFF_FIELD(15:8, uint8_t, IPR_N1)
  // IPR_N0
  ETL_BFF_FIELD(7:0, uint8_t, IPR_N0)
)

// IPR17
//
// Interrupt Priority Register
//
//   Offset: 0x344
ETL_BFF_REG_RW(uint32_t, IPR17,
  // IPR_N3
  ETL_BFF_FIELD(31:24, uint8_t, IPR_N3)
  // IPR_N2
  ETL_BFF_FIELD(23:16, uint8_t, IPR_N2)
  // IPR_N1
  ETL_BFF_FIELD(15:8, uint8_t, IPR_N1)
  // IPR_N0
  ETL_BFF_FIELD(7:0, uint8_t, IPR_N0)
)

// IPR18
//
// Interrupt Priority Register
//
//   Offset: 0x348
ETL_BFF_REG_RW(uint32_t, IPR18,
  // IPR_N3
  ETL_BFF_FIELD(31:24, uint8_t, IPR_N3)
  // IPR_N2
  ETL_BFF_FIELD(23:16, uint8_t, IPR_N2)
  // IPR_N1
  ETL_BFF_FIELD(15:8, uint8_t, IPR_N1)
  // IPR_N0
  ETL_BFF_FIELD(7:0, uint8_t, IPR_N0)
)

// IPR19
//
// Interrupt Priority Register
//
//   Offset: 0x34C
ETL_BFF_REG_RW(uint32_t, IPR19,
  // IPR_N3
  ETL_BFF_FIELD(31:24, uint8_t, IPR_N3)
  // IPR_N2
  ETL_BFF_FIELD(23:16, uint8_t, IPR_N2)
  // IPR_N1
  ETL_BFF_FIELD(15:8, uint8_t, IPR_N1)
  // IPR_N0
  ETL_BFF_FIELD(7:0, uint8_t, IPR_N0)
)

// IPR20
//
// Interrupt Priority Register
//
//   Offset: 0x350
ETL_BFF_REG_RW(uint32_t, IPR20,
  // IPR_N3
  ETL_BFF_FIELD(31:24, uint8_t, IPR_N3)
  // IPR_N2
  ETL_BFF_FIELD(23:16, uint8_t, IPR_N2)
  // IPR_N1
  ETL_BFF_FIELD(15:8, uint8_t, IPR_N1)
  // IPR_N0
  ETL_BFF_FIELD(7:0, uint8_t, IPR_N0)
)

// IPR21
//
// Interrupt Priority Register
//
//   Offset: 0x354
ETL_BFF_REG_RW(uint32_t, IPR21,
)

// IPR22
//
// Interrupt Priority Register
//
//   Offset: 0x358
ETL_BFF_REG_RW(uint32_t, IPR22,
)

// IPR23
//
// Interrupt Priority Register
//
//   Offset: 0x35C
ETL_BFF_REG_RW(uint32_t, IPR23,
)

// IPR24
//
// Interrupt Priority Register
//
//   Offset: 0x360
ETL_BFF_REG_RW(uint32_t, IPR24,
)

// IPR25
//
// Interrupt Priority Register
//
//   Offset: 0x364
ETL_BFF_REG_RW(uint32_t, IPR25,
)

// clang-format on
