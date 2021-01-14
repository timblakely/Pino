// clang-format off
ETL_BFF_REG_RW(uint32_t, FLSSA,
  ETL_BFF_FIELD_E(31:30, uint8_t, SFT,
    ETL_BFF_ENUM(0b00, range)
    ETL_BFF_ENUM(0b01, dual_id)
    ETL_BFF_ENUM(0b10, classic_with_mask)
    ETL_BFF_ENUM(0b11, disabled)
  )
  ETL_BFF_FIELD_E(29:27, uint8_t, SFEC,
    ETL_BFF_ENUM(0b001, disable)
    ETL_BFF_ENUM(0b001, store_fifo0)
    ETL_BFF_ENUM(0b010, store_fifo1)
    ETL_BFF_ENUM(0b011, reject)
    ETL_BFF_ENUM(0b100, priority)
    ETL_BFF_ENUM(0b101, priority_store_fifo0)
    ETL_BFF_ENUM(0b110, priority_store_fifo1)
  )
  ETL_BFF_FIELD(26:16, uint16_t, SFID1)

  ETL_BFF_FIELD(10:0, uint16_t, SFID2)
)
// clang-format on