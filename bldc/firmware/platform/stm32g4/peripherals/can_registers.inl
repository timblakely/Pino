// clang-format off
ETL_BFF_REG_RO(uint32_t, CREL,
  ETL_BFF_FIELD(31 : 28, unsigned, REL)
  ETL_BFF_FIELD(27 : 24, unsigned, STEP)
  ETL_BFF_FIELD(23 : 20, unsigned, SUBSTEP)
  ETL_BFF_FIELD(19 : 16, unsigned, YEAR)
  ETL_BFF_FIELD(15 : 8, unsigned, MON)
  ETL_BFF_FIELD(7 : 0, unsigned, DAY)
)

ETL_BFF_REG_RO(uint32_t, ENDN,
  ETL_BFF_FIELD(31 : 0, unsigned, ETV)
)

ETL_BFF_REG_RESERVED(uint32_t, reserved1, 1)

ETL_BFF_REG_RW(uint32_t, DBTP,
  ETL_BFF_FIELD(23:23, bool, TDC)

  ETL_BFF_FIELD(20:16, uint8_t, DBRP)

  ETL_BFF_FIELD(12:8, uint8_t, DTSEG1)
  ETL_BFF_FIELD(7:4, uint8_t, DTSEG2)
  ETL_BFF_FIELD(3:0, uint8_t, DSJW)
)

ETL_BFF_REG_RW(uint32_t, TEST,
  ETL_BFF_FIELD_E(7:7, bool, RX,
    ETL_BFF_ENUM(0, dominant)
    ETL_BFF_ENUM(1, recessive)
  )
  ETL_BFF_FIELD_E(6:5, uint8_t, TX,
    ETL_BFF_ENUM(0b00, can_core)
    ETL_BFF_ENUM(0b01, sample_point)
    ETL_BFF_ENUM(0b10, dominant)
    ETL_BFF_ENUM(0b11, recessive)
  )
  ETL_BFF_FIELD(4:4, bool, LBCK)
)

ETL_BFF_REG_RW(uint32_t, RWD,
  ETL_BFF_FIELD(15:8, uint8_t, WDV)
  ETL_BFF_FIELD(7:0, uint8_t, WDC)
)

ETL_BFF_REG_RW(uint32_t, CCCR,
  ETL_BFF_FIELD(15:15, bool, NISO)
  ETL_BFF_FIELD(14:14, bool, TXP)
  ETL_BFF_FIELD(13:13, bool, EFBI)
  ETL_BFF_FIELD(12:12, bool, PXHD)

  ETL_BFF_FIELD(9:9, bool, BRSE)
  ETL_BFF_FIELD(8:8, bool, FDOE)
  ETL_BFF_FIELD_E(7:7, bool, TEST,
    ETL_BFF_ENUM(0, normal)
    ETL_BFF_ENUM(1, test)
  )
  ETL_BFF_FIELD_E(6:6, bool, DAR,
    ETL_BFF_ENUM(0, retransmit)
    ETL_BFF_ENUM(1, noretransmit)
  )
  ETL_BFF_FIELD(5:5, bool, MON)
  ETL_BFF_FIELD(4:4, bool, CSR)
  ETL_BFF_FIELD(3:3, bool, CSA)
  ETL_BFF_FIELD_E(2:2, bool, ASM,
    ETL_BFF_ENUM(0, normal)
    ETL_BFF_ENUM(1, restricted)
  )
  ETL_BFF_FIELD_E(1:1, bool, CCE,
    ETL_BFF_ENUM(0, readonly)
    ETL_BFF_ENUM(1, readwrite)
  )
  ETL_BFF_FIELD_E(0:0, bool, INT,
    ETL_BFF_ENUM(0, run)
    ETL_BFF_ENUM(1, init)
  )
)

ETL_BFF_REG_RW(uint32_t, NBTP,
  ETL_BFF_FIELD(31 : 25, unsigned, NSJW)
  ETL_BFF_FIELD(24 : 16, unsigned, NBRP)
  ETL_BFF_FIELD(15 : 8, unsigned, NTSEG1)
  ETL_BFF_FIELD(6 : 0, unsigned, NTSEG2)
)

ETL_BFF_REG_RW(uint32_t, TSCC,
  ETL_BFF_FIELD(19:16, uint8_t, TCP)

  ETL_BFF_FIELD_E(1:0, uint8_t, TSS,
    ETL_BFF_ENUM(0b00, zero)
    ETL_BFF_ENUM(0b01, increment_by_tcp)
    ETL_BFF_ENUM(0b10, tim3_cnt)
    ETL_BFF_ENUM(0b11, zero_)
  )
)

ETL_BFF_REG_RW(uint32_t, TSCV,
  ETL_BFF_FIELD(15:0, uint16_t, TSC)
)

ETL_BFF_REG_RW(uint32_t, TOCC,
  ETL_BFF_FIELD(31:16, uint16_t, TOP)
  
  ETL_BFF_FIELD_E(2:1, uint8_t, TOS,
    ETL_BFF_ENUM(0b00, continuous)
    ETL_BFF_ENUM(0b01, tx_event_fifo)
    ETL_BFF_ENUM(0b10, rx_fifo0)
    ETL_BFF_ENUM(0b11, rx_fifo1)
  )
  ETL_BFF_FIELD(0:0, bool, ETOC)
)

ETL_BFF_REG_RW(uint32_t, TOCV,
  ETL_BFF_FIELD(15:0, uint16_t, TOC)
)

ETL_BFF_REG_RO(uint32_t, ECR,
  ETL_BFF_FIELD(23:16, uint8_t, CEL)
  ETL_BFF_FIELD(15:15, bool, RP)
  ETL_BFF_FIELD(14:8, uint8_t, REC)
  ETL_BFF_FIELD(7:0, uint8_t, TEC)
)

ETL_BFF_REG_RO(uint32_t, PSR,
  ETL_BFF_FIELD(22:16, uint8_t, TDCV)

  ETL_BFF_FIELD(14:14, bool, PXE)
  ETL_BFF_FIELD(13:13, bool, REDL)
  ETL_BFF_FIELD(12:12, bool, RBRS)
  ETL_BFF_FIELD(11:11, bool, RESI)
  ETL_BFF_FIELD_E(10:8, uint8_t, DLEC,
    ETL_BFF_ENUM(0b000, none)
    ETL_BFF_ENUM(0b001, stuff)
    ETL_BFF_ENUM(0b010, form)
    ETL_BFF_ENUM(0b11, ack)
    ETL_BFF_ENUM(0b100, bit1)
    ETL_BFF_ENUM(0b101, bit0)
    ETL_BFF_ENUM(0b110, crc)
    ETL_BFF_ENUM(0b111, no_change)
  )
  ETL_BFF_FIELD(7:7, bool, BO)
  ETL_BFF_FIELD(6:6, bool, EW)
  ETL_BFF_FIELD(5:5, bool, EP)
  ETL_BFF_FIELD_E(4:3, uint8_t, ACT,
    ETL_BFF_ENUM(0b00, synchronizing)
    ETL_BFF_ENUM(0b01, idle)
    ETL_BFF_ENUM(0b10, receiver)
    ETL_BFF_ENUM(0b11, transmitter)
  )
  ETL_BFF_FIELD_E(2:0, uint8_t, LEC,
    ETL_BFF_ENUM(0b000, none)
    ETL_BFF_ENUM(0b001, stuff)
    ETL_BFF_ENUM(0b010, form)
    ETL_BFF_ENUM(0b110, ack)
    ETL_BFF_ENUM(0b100, bit1)
    ETL_BFF_ENUM(0b101, bit0)
    ETL_BFF_ENUM(0b110, crc)
    ETL_BFF_ENUM(0b111, no_change)
  )
)

ETL_BFF_REG_RW(uint32_t, name,
  
)

// clang-format on