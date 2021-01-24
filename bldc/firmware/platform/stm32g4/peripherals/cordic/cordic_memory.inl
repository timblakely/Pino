// clang-format off

// CSR
//
// CORDIC Control Status register
//
//   Offset: 0x000
ETL_BFF_REG_RW(uint32_t, CSR,
  // RRDY
  ETL_BFF_FIELD(31:31, bool, RRDY)
  // 30 : 23 reserved
  // ARGSIZE
  ETL_BFF_FIELD(22:22, bool, ARGSIZE)
  // RESSIZE
  ETL_BFF_FIELD(21:21, bool, RESSIZE)
  // NARGS
  ETL_BFF_FIELD(20:20, bool, NARGS)
  // NRES
  ETL_BFF_FIELD(19:19, bool, NRES)
  // DMAWEN
  ETL_BFF_FIELD(18:18, bool, DMAWEN)
  // DMAREN
  ETL_BFF_FIELD(17:17, bool, DMAREN)
  // IEN
  ETL_BFF_FIELD(16:16, bool, IEN)
  // 15 : 11 reserved
  // SCALE
  ETL_BFF_FIELD(10:8, uint8_t, SCALE)
  // PRECISION
  ETL_BFF_FIELD(7:4, uint8_t, PRECISION)
  // FUNC
  ETL_BFF_FIELD(3:0, uint8_t, FUNC)
)

// WDATA
//
// FMAC Write Data register
//
//   Offset: 0x004
ETL_BFF_REG_RW(uint32_t, WDATA,
  // ARG
  ETL_BFF_FIELD(31:0, uint32_t, ARG)
)

// RDATA
//
// FMAC Read Data register
//
//   Offset: 0x008
ETL_BFF_REG_RO(uint32_t, RDATA,
  // RES
  ETL_BFF_FIELD(31:0, uint32_t, RES)
)

// clang-format on
