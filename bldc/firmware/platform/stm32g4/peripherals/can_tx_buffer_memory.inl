// clang-format off
ETL_BFF_REG_RW(uint32_t, T0,
  ETL_BFF_FIELD(31:31, bool, ESI)
  ETL_BFF_FIELD(30:30, bool, XTD)
  ETL_BFF_FIELD(29:29, bool, RTR)
  ETL_BFF_FIELD(28:0, uint32_t, ID)
)

ETL_BFF_REG_RW(uint32_t, T1,
  ETL_BFF_FIELD(31:24, uint8_t, MM)
  ETL_BFF_FIELD(23:23, bool, EFC)

  ETL_BFF_FIELD(21:21, bool, FDF)
  ETL_BFF_FIELD(20:20, bool, BRS)
  
  ETL_BFF_FIELD_E(19:16, uint8_t, DLC,
    ETL_BFF_ENUM(0b0000, can0)    
    ETL_BFF_ENUM(0b0001, can1)    
    ETL_BFF_ENUM(0b0010, can2)    
    ETL_BFF_ENUM(0b0011, can3)    
    ETL_BFF_ENUM(0b0100, can4)    
    ETL_BFF_ENUM(0b0101, can5)    
    ETL_BFF_ENUM(0b0110, can6)    
    ETL_BFF_ENUM(0b0111, can7)    
    ETL_BFF_ENUM(0b1000, can8)    

    ETL_BFF_ENUM(0b0000, fdcan0)    
    ETL_BFF_ENUM(0b0001, fdcan1)    
    ETL_BFF_ENUM(0b0010, fdcan2)    
    ETL_BFF_ENUM(0b0011, fdcan3)    
    ETL_BFF_ENUM(0b0100, fdcan4)    
    ETL_BFF_ENUM(0b0101, fdcan5)    
    ETL_BFF_ENUM(0b0110, fdcan6)    
    ETL_BFF_ENUM(0b0111, fdcan7)    
    ETL_BFF_ENUM(0b1000, fdcan8)    
    ETL_BFF_ENUM(0b1001, fdcan12)    
    ETL_BFF_ENUM(0b1010, fdcan16)    
    ETL_BFF_ENUM(0b1011, fdcan20)    
    ETL_BFF_ENUM(0b1100, fdcan24)    
    ETL_BFF_ENUM(0b1101, fdcan32)    
    ETL_BFF_ENUM(0b1110, fdcan48)    
    ETL_BFF_ENUM(0b1111, fdcan64)    
  )
)
// clang-format on