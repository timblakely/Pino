// clang-format off
ETL_BFF_REG_RW(uint32_t, E0,
  ETL_BFF_FIELD(31:31, bool, ESI)
  ETL_BFF_FIELD(30:30, bool, XTD)
  ETL_BFF_FIELD(29:29, bool, RTR)
  ETL_BFF_FIELD(28:0, uint32_t, ID)
)

ETL_BFF_REG_RW(uint32_t, E1,
  ETL_BFF_FIELD(31:24, uint8_t, MM)
  ETL_BFF_FIELD_E(23:22, uint8_t, EFC,
    ETL_BFF_ENUM(0b01, success)
    ETL_BFF_ENUM(0b10, tx_while_cancelled)
  )
  ETL_BFF_FIELD(21:21, bool, EDL)
  ETL_BFF_FIELD(20:20, bool, BRS)
  ETL_BFF_FIELD(19:16, uint8_t, DLC)
  ETL_BFF_FIELD(15:0, uint16_t, TXTS)
)
// clang-format on