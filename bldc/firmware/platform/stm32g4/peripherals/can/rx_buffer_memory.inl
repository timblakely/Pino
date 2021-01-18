// clang-format off
ETL_BFF_REG_RW(uint32_t, R0,
  ETL_BFF_FIELD(31:31, bool, ESI)
  ETL_BFF_FIELD(30:30, bool, XTD)
  ETL_BFF_FIELD(29:29, bool, RTR)
  ETL_BFF_FIELD(28:0, uint32_t, ID)
)

ETL_BFF_REG_RW(uint32_t, R1,
  ETL_BFF_FIELD(31:31, bool, ANMF)
  ETL_BFF_FIELD(30:24, uint8_t, FIDX)

  ETL_BFF_FIELD(21:21, bool, FDF)
  ETL_BFF_FIELD(20:20, bool, BRS)
  ETL_BFF_FIELD(19:16, uint8_t, DLC)
  ETL_BFF_FIELD(15:0, uint16_t, RXTS)
)
// clang-format on