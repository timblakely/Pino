// clang-format off
// Intentionally not an array, as it's actually two 32 bit values repeated, and
// the Biffield API doesn't support that.
ETL_BFF_REG_RW(uint32_t, F0,
   ETL_BFF_FIELD_E(31:29, uint8_t, EFEC,
    ETL_BFF_ENUM(0b001, disable)
    ETL_BFF_ENUM(0b001, store_fifo0)
    ETL_BFF_ENUM(0b010, store_fifo1)
    ETL_BFF_ENUM(0b011, reject)
    ETL_BFF_ENUM(0b100, priority)
    ETL_BFF_ENUM(0b101, priority_store_fifo0)
    ETL_BFF_ENUM(0b110, priority_store_fifo1)
  )
  ETL_BFF_FIELD(28:0, uint32_t, EFID1)
)

ETL_BFF_REG_RW(uint32_t, F1,
  ETL_BFF_FIELD_E(31:30, uint8_t, EFT,
    ETL_BFF_ENUM(0b00, range)
    ETL_BFF_ENUM(0b01, dual_id)
    ETL_BFF_ENUM(0b10, classic_with_mask)
    ETL_BFF_ENUM(0b11, disabled)
  )

  ETL_BFF_FIELD(28:0, uint32_t, eFID2)
)
// clang-format on