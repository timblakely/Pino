// clang-format off

// ACR
//
// Access control register
//
//   Offset: 0x000
//   Reset value: 0x00000600
ETL_BFF_REG_RW(uint32_t, ACR,
  // Debug software enable
  ETL_BFF_FIELD(18:18, bool, DBG_SWEN)
  // 17 : 15 reserved
  // Flash Power-down mode during Low-power sleep mode
  ETL_BFF_FIELD(14:14, bool, SLEEP_PD)
  // Flash Power-down mode during Low-power run mode
  ETL_BFF_FIELD(13:13, bool, RUN_PD)
  // Data cache reset
  ETL_BFF_FIELD(12:12, bool, DCRST)
  // Instruction cache reset
  ETL_BFF_FIELD(11:11, bool, ICRST)
  // Data cache enable
  ETL_BFF_FIELD(10:10, bool, DCEN)
  // Instruction cache enable
  ETL_BFF_FIELD(9:9, bool, ICEN)
  // Prefetch enable
  ETL_BFF_FIELD(8:8, bool, PRFTEN)
  // 7 : 4 reserved
  // Latency
  ETL_BFF_FIELD(3:0, uint8_t, LATENCY)
)

// PDKEYR
//
// Power down key register
//
//   Offset: 0x004
ETL_BFF_REG_WO(uint32_t, PDKEYR,
  // RUN_PD in FLASH_ACR key
  ETL_BFF_FIELD(31:0, uint32_t, PDKEYR)
)

// KEYR
//
// Flash key register
//
//   Offset: 0x008
ETL_BFF_REG_WO(uint32_t, KEYR,
  // KEYR
  ETL_BFF_FIELD(31:0, uint32_t, KEYR)
)

// OPTKEYR
//
// Option byte key register
//
//   Offset: 0x00C
ETL_BFF_REG_WO(uint32_t, OPTKEYR,
  // Option byte key
  ETL_BFF_FIELD(31:0, uint32_t, OPTKEYR)
)

// SR
//
// Status register
//
//   Offset: 0x010
ETL_BFF_REG_RW(uint32_t, SR,
  // Busy
  ETL_BFF_FIELD(16:16, bool, BSY)
  // Option validity error
  ETL_BFF_FIELD(15:15, bool, OPTVERR)
  // PCROP read error
  ETL_BFF_FIELD(14:14, bool, RDERR)
  // 13 : 10 reserved
  // Fast programming error
  ETL_BFF_FIELD(9:9, bool, FASTERR)
  // Fast programming data miss error
  ETL_BFF_FIELD(8:8, bool, MISERR)
  // Programming sequence error
  ETL_BFF_FIELD(7:7, bool, PGSERR)
  // Size error
  ETL_BFF_FIELD(6:6, bool, SIZERR)
  // Programming alignment error
  ETL_BFF_FIELD(5:5, bool, PGAERR)
  // Write protected error
  ETL_BFF_FIELD(4:4, bool, WRPERR)
  // Programming error
  ETL_BFF_FIELD(3:3, bool, PROGERR)
  // 2 reserved
  // Operation error
  ETL_BFF_FIELD(1:1, bool, OPERR)
  // End of operation
  ETL_BFF_FIELD(0:0, bool, EOP)
)

// CR
//
// Flash control register
//
//   Offset: 0x014
//   Reset value: 0xC0000000
ETL_BFF_REG_RW(uint32_t, CR,
  // FLASH_CR Lock
  ETL_BFF_FIELD(31:31, bool, LOCK)
  // Options Lock
  ETL_BFF_FIELD(30:30, bool, OPTLOCK)
  // Securable memory area protection bank 2
  ETL_BFF_FIELD(29:29, bool, SEC_PROT2)
  // SEC_PROT1
  ETL_BFF_FIELD(28:28, bool, SEC_PROT1)
  // Force the option byte loading
  ETL_BFF_FIELD(27:27, bool, OBL_LAUNCH)
  // PCROP read error interrupt enable
  ETL_BFF_FIELD(26:26, bool, RDERRIE)
  // Error interrupt enable
  ETL_BFF_FIELD(25:25, bool, ERRIE)
  // End of operation interrupt enable
  ETL_BFF_FIELD(24:24, bool, EOPIE)
  // 23 : 19 reserved
  // Fast programming
  ETL_BFF_FIELD(18:18, bool, FSTPG)
  // Options modification start
  ETL_BFF_FIELD(17:17, bool, OPTSTRT)
  // Start
  ETL_BFF_FIELD(16:16, bool, STRT)
  // Bank 2 mass erase
  ETL_BFF_FIELD(15:15, bool, MER2)
  // 14 : 12 reserved
  // Bank erase
  ETL_BFF_FIELD(11:11, bool, BKER)
  // 10 reserved
  // Page number
  ETL_BFF_FIELD(9:3, uint8_t, PNB)
  // Bank 1 Mass erase
  ETL_BFF_FIELD(2:2, bool, MER1)
  // Page erase
  ETL_BFF_FIELD(1:1, bool, PER)
  // Programming
  ETL_BFF_FIELD(0:0, bool, PG)
)

// ECCR
//
// Flash ECC register
//
//   Offset: 0x018
ETL_BFF_REG_RW(uint32_t, ECCR,
  // ECC detection
  ETL_BFF_FIELD(31:31, bool, ECCD)
  // ECC correction
  ETL_BFF_FIELD(30:30, bool, ECCC)
  // ECC2 detection
  ETL_BFF_FIELD(29:29, bool, ECCD2)
  // ECC correction
  ETL_BFF_FIELD(28:28, bool, ECCC2)
  // 27 : 25 reserved
  // ECCIE
  ETL_BFF_FIELD(24:24, bool, ECCIE)
  // 23 reserved
  // SYSF_ECC
  ETL_BFF_FIELD(22:22, bool, SYSF_ECC)
  // BK_ECC
  ETL_BFF_FIELD(21:21, bool, BK_ECC)
  // 20 : 19 reserved
  // ECC fail address
  ETL_BFF_FIELD(18:0, uint32_t, ADDR_ECC)
)

ETL_BFF_REG_RESERVED(uint32_t, reserved1, 1)

// OPTR
//
// Flash option register
//
//   Offset: 0x020
//   Reset value: 0xF0000000
ETL_BFF_REG_RW(uint32_t, OPTR,
  // IRHEN
  ETL_BFF_FIELD(30:30, bool, IRHEN)
  // NRST_MODE
  ETL_BFF_FIELD(29:28, uint8_t, NRST_MODE)
  // nBOOT0
  ETL_BFF_FIELD(27:27, bool, nBOOT0)
  // nSWBOOT0
  ETL_BFF_FIELD(26:26, bool, nSWBOOT0)
  // CCM SRAM Erase when system reset
  ETL_BFF_FIELD(25:25, bool, CCMSRAM_RST)
  // SRAM2 parity check enable
  ETL_BFF_FIELD(24:24, bool, SRAM_PE)
  // Boot configuration
  ETL_BFF_FIELD(23:23, bool, nBOOT1)
  // Single or dual bank mode
  ETL_BFF_FIELD(22:22, bool, DBANK)
  // 21 reserved
  // Dual-bank boot
  ETL_BFF_FIELD(20:20, bool, BFB2)
  // Window watchdog selection
  ETL_BFF_FIELD(19:19, bool, WWDG_SW)
  // Independent watchdog counter freeze in Standby mode
  ETL_BFF_FIELD(18:18, bool, IWDG_STDBY)
  // Independent watchdog counter freeze in Stop mode
  ETL_BFF_FIELD(17:17, bool, IWDG_STOP)
  // Independent watchdog selection
  ETL_BFF_FIELD(16:16, bool, IDWG_SW)
  // 15 reserved
  // nRST_SHDW
  ETL_BFF_FIELD(14:14, bool, nRST_SHDW)
  // nRST_STDBY
  ETL_BFF_FIELD(13:13, bool, nRST_STDBY)
  // nRST_STOP
  ETL_BFF_FIELD(12:12, bool, nRST_STOP)
  // 11 reserved
  // BOR reset Level
  ETL_BFF_FIELD(10:8, uint8_t, BOR_LEV)
  // Read protection level
  ETL_BFF_FIELD(7:0, uint8_t, RDP)
)

// PCROP1SR
//
// Flash Bank 1 PCROP Start address register
//
//   Offset: 0x024
//   Reset value: 0xFFFF0000
ETL_BFF_REG_RW(uint32_t, PCROP1SR,
  // Bank 1 PCROP area start offset
  ETL_BFF_FIELD(14:0, uint16_t, PCROP1_STRT)
)

// PCROP1ER
//
// Flash Bank 1 PCROP End address register
//
//   Offset: 0x028
//   Reset value: 0x0FFF0000
ETL_BFF_REG_RW(uint32_t, PCROP1ER,
  // PCROP area preserved when RDP level decreased
  ETL_BFF_FIELD(31:31, bool, PCROP_RDP)
  // 30 : 15 reserved
  // Bank 1 PCROP area end offset
  ETL_BFF_FIELD(14:0, uint16_t, PCROP1_END)
)

// WRP1AR
//
// Flash Bank 1 WRP area A address register
//
//   Offset: 0x02C
ETL_BFF_REG_RW(uint32_t, WRP1AR,
  // Bank 1 WRP first area A end offset
  ETL_BFF_FIELD(22:16, uint8_t, WRP1A_END)
  // 15 : 7 reserved
  // Bank 1 WRP first area start offset
  ETL_BFF_FIELD(6:0, uint8_t, WRP1A_STRT)
)

// WRP1BR
//
// Flash Bank 1 WRP area B address register
//
//   Offset: 0x030
ETL_BFF_REG_RW(uint32_t, WRP1BR,
  // Bank 1 WRP second area B start offset
  ETL_BFF_FIELD(22:16, uint8_t, WRP1B_END)
  // 15 : 7 reserved
  // Bank 1 WRP second area B end offset
  ETL_BFF_FIELD(6:0, uint8_t, WRP1B_STRT)
)

ETL_BFF_REG_RESERVED(uint32_t, reserved2, 4)

// PCROP2SR
//
// Proprietary code readout protection 2 start
//
//   Offset: 0x044
ETL_BFF_REG_RW(uint32_t, PCROP2SR,
  // PCROP area start offset
  ETL_BFF_FIELD(14:0, uint16_t, PCROP2_STRT)
)

// PCROP2ER
//
// Proprietary code readout protection 2 end
//
//   Offset: 0x048
ETL_BFF_REG_RW(uint32_t, PCROP2ER,
  // PCROP area end offset
  ETL_BFF_FIELD(14:0, uint16_t, PCROP2_END)
)

// WRP2AR
//
// Bank 2 WRP area A address
//
//   Offset: 0x04C
ETL_BFF_REG_RW(uint32_t, WRP2AR,
  // WRP first area A end offset
  ETL_BFF_FIELD(22:16, uint8_t, WRP2A_END)
  // 15 : 7 reserved
  // WRP first area A start offset
  ETL_BFF_FIELD(6:0, uint8_t, WRP2A_STRT)
)

// WRP2BR
//
// Bank 2 WRP area B address
//
//   Offset: 0x050
ETL_BFF_REG_RW(uint32_t, WRP2BR,
  // WRP first area B end offset
  ETL_BFF_FIELD(22:16, uint8_t, WRP2B_END)
  // 15 : 7 reserved
  // WRP first area B start offset
  ETL_BFF_FIELD(6:0, uint8_t, WRP2B_STRT)
)

ETL_BFF_REG_RESERVED(uint32_t, reserved3, 7)

// SEC1R
//
// securable area bank1 register
//
//   Offset: 0x070
//   Reset value: 0xFF00FF00
ETL_BFF_REG_RW(uint32_t, SEC1R,
  // BOOT_LOCK
  ETL_BFF_FIELD(16:16, bool, BOOT_LOCK)
  // 15 : 8 reserved
  // SEC_SIZE1
  ETL_BFF_FIELD(7:0, uint8_t, SEC_SIZE1)
)

// SEC2R
//
// Flash securable area bank2
//
//   Offset: 0x074
ETL_BFF_REG_RW(uint32_t, SEC2R,
  // number of pages in secure bank 2
  ETL_BFF_FIELD(7:0, uint8_t, SEC_SIZE2)
)

// clang-format on
