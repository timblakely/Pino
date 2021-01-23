// clang-format off
ETL_BFF_REG_RO(uint32_t, CREL,
  ETL_BFF_FIELD(31:28, uint8_t, REL)
  ETL_BFF_FIELD(27:24, uint8_t, STEP)
  ETL_BFF_FIELD(23:20, uint8_t, SUBSTEP)
  ETL_BFF_FIELD(19:16, uint8_t, YEAR)
  ETL_BFF_FIELD(15:8, uint8_t, MON)
  ETL_BFF_FIELD(7:0, uint8_t, DAY)
)

ETL_BFF_REG_RO(uint32_t, ENDN,
  ETL_BFF_FIELD(31:0, uint32_t, ETV)
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
    ETL_BFF_ENUM(0b0, dominant)
    ETL_BFF_ENUM(0b1, recessive)
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
    ETL_BFF_ENUM(0b0, normal)
    ETL_BFF_ENUM(0b1, test)
  )
  ETL_BFF_FIELD_E(6:6, bool, DAR,
    ETL_BFF_ENUM(0b0, retransmit)
    ETL_BFF_ENUM(0b1, noretransmit)
  )
  ETL_BFF_FIELD(5:5, bool, MON)
  ETL_BFF_FIELD(4:4, bool, CSR)
  ETL_BFF_FIELD(3:3, bool, CSA)
  ETL_BFF_FIELD_E(2:2, bool, ASM,
    ETL_BFF_ENUM(0b0, normal)
    ETL_BFF_ENUM(0b1, restricted)
  )
  ETL_BFF_FIELD_E(1:1, bool, CCE,
    ETL_BFF_ENUM(0b0, readonly)
    ETL_BFF_ENUM(0b1, readwrite)
  )
  ETL_BFF_FIELD_E(0:0, bool, INIT,
    ETL_BFF_ENUM(0b0, run)
    ETL_BFF_ENUM(0b1, init)
  )
)

ETL_BFF_REG_RW(uint32_t, NBTP,
  ETL_BFF_FIELD(31:25, uint8_t, NSJW)
  ETL_BFF_FIELD(24:16, uint16_t, NBRP)
  ETL_BFF_FIELD(15:8, uint8_t, NTSEG1)

  ETL_BFF_FIELD(6:0, uint8_t, NTSEG2)
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

ETL_BFF_REG_RO(uint32_t, TOCV,
  ETL_BFF_FIELD(15:0, uint16_t, TOC)
)

ETL_BFF_REG_RESERVED(uint32_t, reserved2, 4)

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
    ETL_BFF_ENUM(0b011, ack)
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
    ETL_BFF_ENUM(0b011, ack)
    ETL_BFF_ENUM(0b100, bit1)
    ETL_BFF_ENUM(0b101, bit0)
    ETL_BFF_ENUM(0b110, crc)
    ETL_BFF_ENUM(0b111, no_change)
  )
)

ETL_BFF_REG_RW(uint32_t, TDCR,
  ETL_BFF_FIELD(14:8, uint8_t, TDCO)

  ETL_BFF_FIELD(6:0, uint8_t, TDCF)
)

ETL_BFF_REG_RESERVED(uint32_t, reserved3, 1)

ETL_BFF_REG_RW(uint32_t, IR,
  ETL_BFF_FIELD(23:23, bool, ARA)
  ETL_BFF_FIELD(22:22, bool, PED)
  ETL_BFF_FIELD(21:21, bool, PEA)
  ETL_BFF_FIELD(20:20, bool, WDI)
  ETL_BFF_FIELD(19:19, bool, BO)
  ETL_BFF_FIELD(18:18, bool, EW)
  ETL_BFF_FIELD(17:17, bool, EP)
  ETL_BFF_FIELD(16:16, bool, ELO)
  ETL_BFF_FIELD(15:15, bool, TOO)
  ETL_BFF_FIELD(14:14, bool, MRAF)
  ETL_BFF_FIELD(13:13, bool, TSW)
  ETL_BFF_FIELD(12:12, bool, TEFL)
  ETL_BFF_FIELD(11:11, bool, TEFF)
  ETL_BFF_FIELD(10:10, bool, TEFN)
  ETL_BFF_FIELD(9:9, bool, TFE)
  ETL_BFF_FIELD(8:8, bool, TCF)
  ETL_BFF_FIELD(7:7, bool, TC)
  ETL_BFF_FIELD(6:6, bool, HPM)
  ETL_BFF_FIELD(5:5, bool, RF1L)
  ETL_BFF_FIELD(4:4, bool, RF1F)
  ETL_BFF_FIELD(3:3, bool, RF1N)
  ETL_BFF_FIELD(2:2, bool, RF0L)
  ETL_BFF_FIELD(1:1, bool, RF0F)
  ETL_BFF_FIELD(0:0, bool, RF0N)
)

ETL_BFF_REG_RW(uint32_t, IE,
  ETL_BFF_FIELD(23:23, bool, ARAE)
  ETL_BFF_FIELD(22:22, bool, PEDE)
  ETL_BFF_FIELD(21:21, bool, PEAE)
  ETL_BFF_FIELD(20:20, bool, WDIE)
  ETL_BFF_FIELD(19:19, bool, BOE)
  ETL_BFF_FIELD(18:18, bool, EWE)
  ETL_BFF_FIELD(17:17, bool, EPE)
  ETL_BFF_FIELD(16:16, bool, ELOE)
  ETL_BFF_FIELD(15:15, bool, TOOE)
  ETL_BFF_FIELD(14:14, bool, MRAFE)
  ETL_BFF_FIELD(13:13, bool, TSWE)
  ETL_BFF_FIELD(12:12, bool, TEFLE)
  ETL_BFF_FIELD(11:11, bool, TEFFE)
  ETL_BFF_FIELD(10:10, bool, TEFNE)
  ETL_BFF_FIELD(9:9, bool, TFEE)
  ETL_BFF_FIELD(8:8, bool, TCFE)
  ETL_BFF_FIELD(7:7, bool, TCE)
  ETL_BFF_FIELD(6:6, bool, HPME)
  ETL_BFF_FIELD(5:5, bool, RF1LE)
  ETL_BFF_FIELD(4:4, bool, RF1FE)
  ETL_BFF_FIELD(3:3, bool, RF1NE)
  ETL_BFF_FIELD(2:2, bool, RF0LE)
  ETL_BFF_FIELD(1:1, bool, RF0FE)
  ETL_BFF_FIELD(0:0, bool, RF0NE)
)

ETL_BFF_REG_RW(uint32_t, ILS,
  ETL_BFF_FIELD(6:6, bool, PERR)
  ETL_BFF_FIELD(5:5, bool, BERR)
  ETL_BFF_FIELD(4:4, bool, MISC)
  ETL_BFF_FIELD(3:3, bool, TFERR)
  ETL_BFF_FIELD(2:2, bool, SMSG)
  ETL_BFF_FIELD(1:1, bool, RxFIFO1)
  ETL_BFF_FIELD(0:0, bool, RxFIFO0)
)

ETL_BFF_REG_RW(uint32_t, ILE,
  ETL_BFF_FIELD(1:1, bool, EINT1)
  ETL_BFF_FIELD(0:0, bool, EINT0)
)

ETL_BFF_REG_RESERVED(uint32_t, reserved4, 8)

ETL_BFF_REG_RW(uint32_t, RXGFC,
  ETL_BFF_FIELD(27:24, uint8_t, LSE)

  ETL_BFF_FIELD(20:16, uint8_t, LSS)

  ETL_BFF_FIELD(9:9, bool, F0OM)
  ETL_BFF_FIELD(8:8, bool, F1OM)

  ETL_BFF_FIELD_E(5:4, uint8_t, ANFS,
    ETL_BFF_ENUM(0b00, accept_rx_fifo0)
    ETL_BFF_ENUM(0b01, accept_rx_fifo1)
    ETL_BFF_ENUM(0b10, reject)
    ETL_BFF_ENUM(0b11, reject_)
  )
  ETL_BFF_FIELD_E(3:2, uint8_t, ANFE,
    ETL_BFF_ENUM(0b00, accept_rx_fifo0)
    ETL_BFF_ENUM(0b01, accept_rx_fifo1)
    ETL_BFF_ENUM(0b10, reject)
    ETL_BFF_ENUM(0b11, reject_)
  )
  ETL_BFF_FIELD_E(1:1, bool, RRFS,
    ETL_BFF_ENUM(0b0, filter)
    ETL_BFF_ENUM(0b1, reject)
  )
  ETL_BFF_FIELD_E(0:0, bool, RRFE,
    ETL_BFF_ENUM(0b0, filter)
    ETL_BFF_ENUM(0b1, reject)
  )
)

ETL_BFF_REG_RW(uint32_t, XIDAM,
  ETL_BFF_FIELD(28:0, uint32_t, EIDM)
)

ETL_BFF_REG_RO(uint32_t, HPMS,
  ETL_BFF_FIELD_E(15:15, bool, FLST,
    ETL_BFF_ENUM(0b0, standard)
    ETL_BFF_ENUM(0b1, extended)
  )

  ETL_BFF_FIELD(12:8, uint8_t, FIDX)
  ETL_BFF_FIELD_E(7:6, uint8_t, MSI,
    ETL_BFF_ENUM(0b00, no_fifo)
    ETL_BFF_ENUM(0b01, fifo_overrun)
    ETL_BFF_ENUM(0b10, store_fifo0)
    ETL_BFF_ENUM(0b11, store_fifo1)
  )

  ETL_BFF_FIELD(2:0, uint8_t, BIDX)
)

ETL_BFF_REG_RESERVED(uint32_t, reserved5, 1)

ETL_BFF_REG_RO(uint32_t, RXF0S,
  ETL_BFF_FIELD(25:25, bool, RF0L)
  ETL_BFF_FIELD(24:24, bool, F0F)

  ETL_BFF_FIELD(17:16, uint8_t, F0PI)

  ETL_BFF_FIELD(9:8, uint8_t, F0GI)

  ETL_BFF_FIELD(3:0, uint8_t, F0FL)
)

ETL_BFF_REG_RW(uint32_t, RXF0A,
  ETL_BFF_FIELD(2:0, uint8_t, F0AI)
)

ETL_BFF_REG_RO(uint32_t, RXF1S,
  ETL_BFF_FIELD(25:25, bool, RF1L)
  ETL_BFF_FIELD(24:24, bool, F1F)

  ETL_BFF_FIELD(17:16, uint8_t, F1PI)

  ETL_BFF_FIELD(9:8, uint8_t, F1FI)

  ETL_BFF_FIELD(3:0, uint8_t, F1FL)
)

ETL_BFF_REG_RW(uint32_t, RXF1A,
  ETL_BFF_FIELD(2:0, uint8_t, F1AI)
)

ETL_BFF_REG_RESERVED(uint32_t, reserved6, 8)

ETL_BFF_REG_RW(uint32_t, TXBC,
  ETL_BFF_FIELD_E(24:24, bool, TFQM,
    ETL_BFF_ENUM(0b0, fifo)
    ETL_BFF_ENUM(0b1, queue)
  )
)

ETL_BFF_REG_RW(uint32_t, TXFQS,
  ETL_BFF_FIELD(21:21, bool, TFQF)

  ETL_BFF_FIELD(17:16, uint8_t, TFQPI)

  ETL_BFF_FIELD(9:8, uint8_t, TFGI)

  ETL_BFF_FIELD(2:0, uint8_t, TFFL)
)

ETL_BFF_REG_RO(uint32_t, TXBRP,
  ETL_BFF_FIELD(2:0, uint8_t, TRP)
)

ETL_BFF_REG_RW(uint32_t, TXBAR,
  ETL_BFF_FIELD(2:0, uint8_t, AR)
)

ETL_BFF_REG_RW(uint32_t, TXBCR,
  ETL_BFF_FIELD(2:0, uint8_t, CR)
)

ETL_BFF_REG_RO(uint32_t, TXBTO,
  ETL_BFF_FIELD(2:0, uint8_t, TO)
)

ETL_BFF_REG_RO(uint32_t, TXBCF,
  ETL_BFF_FIELD(2:0, uint8_t, CF)
)

ETL_BFF_REG_RW(uint32_t, TXBTIE,
  ETL_BFF_FIELD(2:0, uint8_t, TIE)
)

ETL_BFF_REG_RW(uint32_t, TXBCIE,
  ETL_BFF_FIELD(2:0, uint8_t, TXBCIE)
)

ETL_BFF_REG_RO(uint32_t, TXEFS,
  ETL_BFF_FIELD(25:25, bool, TEFL)
  ETL_BFF_FIELD(24:24, bool, EFF)

  ETL_BFF_FIELD(17:16, uint8_t, EFPI)

  ETL_BFF_FIELD(9:8, uint8_t, EFGI)

  ETL_BFF_FIELD(2:0, uint8_t, EFFL)
)

ETL_BFF_REG_RW(uint32_t, TXEFA,
  ETL_BFF_FIELD(1:0, uint8_t, EFAI)
)

ETL_BFF_REG_RESERVED(uint32_t, reserved7, 5)

ETL_BFF_REG_RW(uint32_t, CKDIV,
  ETL_BFF_FIELD_E(3:0, uint8_t, PDIV,
    ETL_BFF_ENUM(0b0000, div1)
    ETL_BFF_ENUM(0b0001, div2)
    ETL_BFF_ENUM(0b0010, div4)
    ETL_BFF_ENUM(0b0011, div6)
    ETL_BFF_ENUM(0b0100, div8)
    ETL_BFF_ENUM(0b0101, div10)
    ETL_BFF_ENUM(0b0110, div12)
    ETL_BFF_ENUM(0b0111, div14)
    ETL_BFF_ENUM(0b1000, div16)
    ETL_BFF_ENUM(0b1001, div18)
    ETL_BFF_ENUM(0b1010, div20)
    ETL_BFF_ENUM(0b1011, div22)
    ETL_BFF_ENUM(0b1100, div24)
    ETL_BFF_ENUM(0b1101, div26)
    ETL_BFF_ENUM(0b1110, div28)
    ETL_BFF_ENUM(0b1111, div30)
  )
)

// clang-format on