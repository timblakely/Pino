// clang-format off

// CR1
//
// control register 1
//
//   Offset: 0x000
ETL_BFF_REG_RW(uint32_t, CR1,
  // 31:16 reserved
  // Bidirectional data mode enable
  ETL_BFF_FIELD(15:15, bool, BIDIMODE)
  // Output enable in bidirectional mode
  ETL_BFF_FIELD(14:14, bool, BIDIOE)
  // Hardware CRC calculation enable
  ETL_BFF_FIELD(13:13, bool, CRCEN)
  // CRC transfer next
  ETL_BFF_FIELD(12:12, bool, CRCNEXT)
  // CRC length
  ETL_BFF_FIELD(11:11, bool, CRCL)
  // Receive only
  ETL_BFF_FIELD(10:10, bool, RXONLY)
  // Software slave management
  ETL_BFF_FIELD(9:9, bool, SSM)
  // Internal slave select
  ETL_BFF_FIELD(8:8, bool, SSI)
  // Frame format
  ETL_BFF_FIELD(7:7, bool, LSBFIRST)
  // SPI enable
  ETL_BFF_FIELD(6:6, bool, SPE)
  // Baud rate control
  ETL_BFF_FIELD(5:3, uint8_t, BR)
  // Master selection
  ETL_BFF_FIELD(2:2, bool, MSTR)
  // Clock polarity
  ETL_BFF_FIELD(1:1, bool, CPOL)
  // Clock phase
  ETL_BFF_FIELD(0:0, bool, CPHA)
)

// CR2
//
// control register 2
//
//   Offset: 0x004
//   Reset value: 0x00000700
ETL_BFF_REG_RW(uint32_t, CR2,
  // 31:15 reserved
  // Last DMA transfer for transmission
  ETL_BFF_FIELD(14:14, bool, LDMA_TX)
  // Last DMA transfer for reception
  ETL_BFF_FIELD(13:13, bool, LDMA_RX)
  // FIFO reception threshold
  ETL_BFF_FIELD(12:12, bool, FRXTH)
  // Data size
  ETL_BFF_FIELD(11:8, uint8_t, DS)
  // Tx buffer empty interrupt enable
  ETL_BFF_FIELD(7:7, bool, TXEIE)
  // RX buffer not empty interrupt enable
  ETL_BFF_FIELD(6:6, bool, RXNEIE)
  // Error interrupt enable
  ETL_BFF_FIELD(5:5, bool, ERRIE)
  // Frame format
  ETL_BFF_FIELD(4:4, bool, FRF)
  // NSS pulse management
  ETL_BFF_FIELD(3:3, bool, NSSP)
  // SS output enable
  ETL_BFF_FIELD(2:2, bool, SSOE)
  // Tx buffer DMA enable
  ETL_BFF_FIELD(1:1, bool, TXDMAEN)
  // Rx buffer DMA enable
  ETL_BFF_FIELD(0:0, bool, RXDMAEN)
)

// SR
//
// status register
//
//   Offset: 0x008
//   Reset value: 0x00000002
ETL_BFF_REG_RW(uint32_t, SR,
  // 31:13 reserved
  // FIFO transmission level
  ETL_BFF_FIELD(12:11, uint8_t, FTLVL)
  // FIFO reception level
  ETL_BFF_FIELD(10:9, uint8_t, FRLVL)
  // TI frame format error
  ETL_BFF_FIELD(8:8, bool, FRE)
  // Busy flag
  ETL_BFF_FIELD(7:7, bool, BSY)
  // Overrun flag
  ETL_BFF_FIELD(6:6, bool, OVR)
  // Mode fault
  ETL_BFF_FIELD(5:5, bool, MODF)
  // CRC error flag
  ETL_BFF_FIELD(4:4, bool, CRCERR)
  // Underrun flag
  ETL_BFF_FIELD(3:3, bool, UDR)
  // Channel side
  ETL_BFF_FIELD(2:2, bool, CHSIDE)
  // Transmit buffer empty
  ETL_BFF_FIELD(1:1, bool, TXE)
  // Receive buffer not empty
  ETL_BFF_FIELD(0:0, bool, RXNE)
)

// DR
//
// data register
//
//   Offset: 0x00C
ETL_BFF_REG_RW(uint32_t, DR,
  // 31:16 reserved
  // Data register
  ETL_BFF_FIELD(15:0, uint16_t, DR)
)

// CRCPR
//
// CRC polynomial register
//
//   Offset: 0x010
//   Reset value: 0x00000007
ETL_BFF_REG_RW(uint32_t, CRCPR,
  // 31:16 reserved
  // CRC polynomial register
  ETL_BFF_FIELD(15:0, uint16_t, CRCPOLY)
)

// RXCRCR
//
// RX CRC register
//
//   Offset: 0x014
ETL_BFF_REG_RO(uint32_t, RXCRCR,
  // 31:16 reserved
  // Rx CRC register
  ETL_BFF_FIELD(15:0, uint16_t, RxCRC)
)

// TXCRCR
//
// TX CRC register
//
//   Offset: 0x018
ETL_BFF_REG_RO(uint32_t, TXCRCR,
  // 31:16 reserved
  // Tx CRC register
  ETL_BFF_FIELD(15:0, uint16_t, TxCRC)
)

// I2SCFGR
//
// configuration register
//
//   Offset: 0x01C
ETL_BFF_REG_RW(uint32_t, I2SCFGR,
  // 31:13 reserved
  // Asynchronous start enable
  ETL_BFF_FIELD(12:12, bool, ASTRTEN)
  ETL_BFF_FIELD(11:11, bool, I2SMOD)
  ETL_BFF_FIELD(10:10, bool, I2SE)
  ETL_BFF_FIELD(9:8, uint8_t, I2SCFG)
  ETL_BFF_FIELD(7:7, bool, PCMSYNC)
  // 6 reserved
  ETL_BFF_FIELD(5:4, uint8_t, I2SSTD)
  ETL_BFF_FIELD(3:3, bool, CKPOL)
  ETL_BFF_FIELD(2:1, uint8_t, DATLEN)
  ETL_BFF_FIELD(0:0, bool, CHLEN)
)

// I2SPR
//
// prescaler register
//
//   Offset: 0x020
//   Reset value: 0x00000002
ETL_BFF_REG_RW(uint32_t, I2SPR,
  // 31:10 reserved
  ETL_BFF_FIELD(9:9, bool, MCKOE)
  ETL_BFF_FIELD(8:8, bool, ODD)
  ETL_BFF_FIELD(7:0, uint8_t, I2SDIV)
)

// clang-format on
