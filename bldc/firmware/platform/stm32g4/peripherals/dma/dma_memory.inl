// clang-format off

// ISR
//
// interrupt status register
//
//   Offset: 0x000
ETL_BFF_REG_RO(uint32_t, ISR,
  // TEIF8
  ETL_BFF_FIELD(31:31, bool, TEIF8)
  // HTIF8
  ETL_BFF_FIELD(30:30, bool, HTIF8)
  // TCIF8
  ETL_BFF_FIELD(29:29, bool, TCIF8)
  // GIF8
  ETL_BFF_FIELD(28:28, bool, GIF8)
  // TEIF7
  ETL_BFF_FIELD(27:27, bool, TEIF7)
  // HTIF7
  ETL_BFF_FIELD(26:26, bool, HTIF7)
  // TCIF7
  ETL_BFF_FIELD(25:25, bool, TCIF7)
  // GIF7
  ETL_BFF_FIELD(24:24, bool, GIF7)
  // TEIF6
  ETL_BFF_FIELD(23:23, bool, TEIF6)
  // HTIF6
  ETL_BFF_FIELD(22:22, bool, HTIF6)
  // TCIF6
  ETL_BFF_FIELD(21:21, bool, TCIF6)
  // GIF6
  ETL_BFF_FIELD(20:20, bool, GIF6)
  // TEIF5
  ETL_BFF_FIELD(19:19, bool, TEIF5)
  // HTIF5
  ETL_BFF_FIELD(18:18, bool, HTIF5)
  // TCIF5
  ETL_BFF_FIELD(17:17, bool, TCIF5)
  // GIF5
  ETL_BFF_FIELD(16:16, bool, GIF5)
  // TEIF4
  ETL_BFF_FIELD(15:15, bool, TEIF4)
  // HTIF4
  ETL_BFF_FIELD(14:14, bool, HTIF4)
  // TCIF4
  ETL_BFF_FIELD(13:13, bool, TCIF4)
  // GIF4
  ETL_BFF_FIELD(12:12, bool, GIF4)
  // TEIF3
  ETL_BFF_FIELD(11:11, bool, TEIF3)
  // HTIF3
  ETL_BFF_FIELD(10:10, bool, HTIF3)
  // TCIF3
  ETL_BFF_FIELD(9:9, bool, TCIF3)
  // GIF3
  ETL_BFF_FIELD(8:8, bool, GIF3)
  // TEIF2
  ETL_BFF_FIELD(7:7, bool, TEIF2)
  // HTIF2
  ETL_BFF_FIELD(6:6, bool, HTIF2)
  // TCIF2
  ETL_BFF_FIELD(5:5, bool, TCIF2)
  // GIF2
  ETL_BFF_FIELD(4:4, bool, GIF2)
  // TEIF1
  ETL_BFF_FIELD(3:3, bool, TEIF1)
  // HTIF1
  ETL_BFF_FIELD(2:2, bool, HTIF1)
  // TCIF1
  ETL_BFF_FIELD(1:1, bool, TCIF1)
  // GIF1
  ETL_BFF_FIELD(0:0, bool, GIF1)
)

// IFCR
//
// DMA interrupt flag clear register
//
//   Offset: 0x004
ETL_BFF_REG_WO(uint32_t, IFCR,
  // TEIF8
  ETL_BFF_FIELD(31:31, bool, CTEIF8)
  // HTIF8
  ETL_BFF_FIELD(30:30, bool, CHTIF8)
  // TCIF8
  ETL_BFF_FIELD(29:29, bool, CTCIF8)
  // GIF8
  ETL_BFF_FIELD(28:28, bool, CGIF8)
  // TEIF7
  ETL_BFF_FIELD(27:27, bool, CTEIF7)
  // HTIF7
  ETL_BFF_FIELD(26:26, bool, CHTIF7)
  // TCIF7
  ETL_BFF_FIELD(25:25, bool, CTCIF7)
  // GIF7
  ETL_BFF_FIELD(24:24, bool, CGIF7)
  // TEIF6
  ETL_BFF_FIELD(23:23, bool, CTEIF6)
  // HTIF6
  ETL_BFF_FIELD(22:22, bool, CHTIF6)
  // TCIF6
  ETL_BFF_FIELD(21:21, bool, CTCIF6)
  // GIF6
  ETL_BFF_FIELD(20:20, bool, CGIF6)
  // TEIF5
  ETL_BFF_FIELD(19:19, bool, CTEIF5)
  // HTIF5
  ETL_BFF_FIELD(18:18, bool, CHTIF5)
  // TCIF5
  ETL_BFF_FIELD(17:17, bool, CTCIF5)
  // GIF5
  ETL_BFF_FIELD(16:16, bool, CGIF5)
  // TEIF4
  ETL_BFF_FIELD(15:15, bool, CTEIF4)
  // HTIF4
  ETL_BFF_FIELD(14:14, bool, CHTIF4)
  // TCIF4
  ETL_BFF_FIELD(13:13, bool, CTCIF4)
  // GIF4
  ETL_BFF_FIELD(12:12, bool, CGIF4)
  // TEIF3
  ETL_BFF_FIELD(11:11, bool, CTEIF3)
  // HTIF3
  ETL_BFF_FIELD(10:10, bool, CHTIF3)
  // TCIF3
  ETL_BFF_FIELD(9:9, bool, CTCIF3)
  // GIF3
  ETL_BFF_FIELD(8:8, bool, CGIF3)
  // TEIF2
  ETL_BFF_FIELD(7:7, bool, CTEIF2)
  // HTIF2
  ETL_BFF_FIELD(6:6, bool, CHTIF2)
  // TCIF2
  ETL_BFF_FIELD(5:5, bool, CTCIF2)
  // GIF2
  ETL_BFF_FIELD(4:4, bool, CGIF2)
  // TEIF1
  ETL_BFF_FIELD(3:3, bool, CTEIF1)
  // HTIF1
  ETL_BFF_FIELD(2:2, bool, CHTIF1)
  // TCIF1
  ETL_BFF_FIELD(1:1, bool, CTCIF1)
  // GIF1
  ETL_BFF_FIELD(0:0, bool, CGIF1)
)

// CCR1
//
// DMA channel 1 configuration register
//
//   Offset: 0x008
ETL_BFF_REG_RW(uint32_t, CCR1,
  // MEM2MEM
  ETL_BFF_FIELD(14:14, bool, MEM2MEM)
  // PL
  ETL_BFF_FIELD(13:12, uint8_t, PL)
  // MSIZE
  ETL_BFF_FIELD(11:10, uint8_t, MSIZE)
  // PSIZE
  ETL_BFF_FIELD(9:8, uint8_t, PSIZE)
  // MINC
  ETL_BFF_FIELD(7:7, bool, MINC)
  // PINC
  ETL_BFF_FIELD(6:6, bool, PINC)
  // CIRC
  ETL_BFF_FIELD(5:5, bool, CIRC)
  // DIR
  ETL_BFF_FIELD(4:4, bool, DIR)
  // TEIE
  ETL_BFF_FIELD(3:3, bool, TEIE)
  // HTIE
  ETL_BFF_FIELD(2:2, bool, HTIE)
  // TCIE
  ETL_BFF_FIELD(1:1, bool, TCIE)
  // channel enable
  ETL_BFF_FIELD(0:0, bool, EN)
)

// CNDTR1
//
// channel x number of data to transfer register
//
//   Offset: 0x00C
ETL_BFF_REG_RW(uint32_t, CNDTR1,
  // Number of data items to transfer
  ETL_BFF_FIELD(15:0, uint16_t, NDT)
)

// CPAR1
//
// DMA channel x peripheral address register
//
//   Offset: 0x010
ETL_BFF_REG_RW(uint32_t, CPAR1,
  // Peripheral address
  ETL_BFF_FIELD(31:0, uint32_t, PA)
)

// CMAR1
//
// DMA channel x memory address register
//
//   Offset: 0x014
ETL_BFF_REG_RW(uint32_t, CMAR1,
  // Memory 1 address (used in case of Double buffer mode)
  ETL_BFF_FIELD(31:0, uint32_t, MA)
)

ETL_BFF_REG_RESERVED(uint32_t, reserved1, 1)

// CCR2
//
// DMA channel 2 configuration register
//
//   Offset: 0x01C
ETL_BFF_REG_RW(uint32_t, CCR2,
  // MEM2MEM
  ETL_BFF_FIELD(14:14, bool, MEM2MEM)
  // PL
  ETL_BFF_FIELD(13:12, uint8_t, PL)
  // MSIZE
  ETL_BFF_FIELD(11:10, uint8_t, MSIZE)
  // PSIZE
  ETL_BFF_FIELD(9:8, uint8_t, PSIZE)
  // MINC
  ETL_BFF_FIELD(7:7, bool, MINC)
  // PINC
  ETL_BFF_FIELD(6:6, bool, PINC)
  // CIRC
  ETL_BFF_FIELD(5:5, bool, CIRC)
  // DIR
  ETL_BFF_FIELD(4:4, bool, DIR)
  // TEIE
  ETL_BFF_FIELD(3:3, bool, TEIE)
  // HTIE
  ETL_BFF_FIELD(2:2, bool, HTIE)
  // TCIE
  ETL_BFF_FIELD(1:1, bool, TCIE)
  // channel enable
  ETL_BFF_FIELD(0:0, bool, EN)
)

// CNDTR2
//
// channel x number of data to transfer register
//
//   Offset: 0x020
ETL_BFF_REG_RW(uint32_t, CNDTR2,
  // Number of data items to transfer
  ETL_BFF_FIELD(15:0, uint16_t, NDT)
)

// CPAR2
//
// DMA channel x peripheral address register
//
//   Offset: 0x024
ETL_BFF_REG_RW(uint32_t, CPAR2,
  // Peripheral address
  ETL_BFF_FIELD(31:0, uint32_t, PA)
)

// CMAR2
//
// DMA channel x memory address register
//
//   Offset: 0x028
ETL_BFF_REG_RW(uint32_t, CMAR2,
  // Memory 1 address (used in case of Double buffer mode)
  ETL_BFF_FIELD(31:0, uint32_t, MA)
)

ETL_BFF_REG_RESERVED(uint32_t, reserved2, 1)

// CCR3
//
// DMA channel 3 configuration register
//
//   Offset: 0x030
ETL_BFF_REG_RW(uint32_t, CCR3,
  // MEM2MEM
  ETL_BFF_FIELD(14:14, bool, MEM2MEM)
  // PL
  ETL_BFF_FIELD(13:12, uint8_t, PL)
  // MSIZE
  ETL_BFF_FIELD(11:10, uint8_t, MSIZE)
  // PSIZE
  ETL_BFF_FIELD(9:8, uint8_t, PSIZE)
  // MINC
  ETL_BFF_FIELD(7:7, bool, MINC)
  // PINC
  ETL_BFF_FIELD(6:6, bool, PINC)
  // CIRC
  ETL_BFF_FIELD(5:5, bool, CIRC)
  // DIR
  ETL_BFF_FIELD(4:4, bool, DIR)
  // TEIE
  ETL_BFF_FIELD(3:3, bool, TEIE)
  // HTIE
  ETL_BFF_FIELD(2:2, bool, HTIE)
  // TCIE
  ETL_BFF_FIELD(1:1, bool, TCIE)
  // channel enable
  ETL_BFF_FIELD(0:0, bool, EN)
)

// CNDTR3
//
// channel x number of data to transfer register
//
//   Offset: 0x034
ETL_BFF_REG_RW(uint32_t, CNDTR3,
  // Number of data items to transfer
  ETL_BFF_FIELD(15:0, uint16_t, NDT)
)

// CPAR3
//
// DMA channel x peripheral address register
//
//   Offset: 0x038
ETL_BFF_REG_RW(uint32_t, CPAR3,
  // Peripheral address
  ETL_BFF_FIELD(31:0, uint32_t, PA)
)

// CMAR3
//
// DMA channel x memory address register
//
//   Offset: 0x03C
ETL_BFF_REG_RW(uint32_t, CMAR3,
  // Memory 1 address (used in case of Double buffer mode)
  ETL_BFF_FIELD(31:0, uint32_t, MA)
)

ETL_BFF_REG_RESERVED(uint32_t, reserved3, 1)

// CCR4
//
// DMA channel 3 configuration register
//
//   Offset: 0x044
ETL_BFF_REG_RW(uint32_t, CCR4,
  // MEM2MEM
  ETL_BFF_FIELD(14:14, bool, MEM2MEM)
  // PL
  ETL_BFF_FIELD(13:12, uint8_t, PL)
  // MSIZE
  ETL_BFF_FIELD(11:10, uint8_t, MSIZE)
  // PSIZE
  ETL_BFF_FIELD(9:8, uint8_t, PSIZE)
  // MINC
  ETL_BFF_FIELD(7:7, bool, MINC)
  // PINC
  ETL_BFF_FIELD(6:6, bool, PINC)
  // CIRC
  ETL_BFF_FIELD(5:5, bool, CIRC)
  // DIR
  ETL_BFF_FIELD(4:4, bool, DIR)
  // TEIE
  ETL_BFF_FIELD(3:3, bool, TEIE)
  // HTIE
  ETL_BFF_FIELD(2:2, bool, HTIE)
  // TCIE
  ETL_BFF_FIELD(1:1, bool, TCIE)
  // channel enable
  ETL_BFF_FIELD(0:0, bool, EN)
)

// CNDTR4
//
// channel x number of data to transfer register
//
//   Offset: 0x048
ETL_BFF_REG_RW(uint32_t, CNDTR4,
  // Number of data items to transfer
  ETL_BFF_FIELD(15:0, uint16_t, NDT)
)

// CPAR4
//
// DMA channel x peripheral address register
//
//   Offset: 0x04C
ETL_BFF_REG_RW(uint32_t, CPAR4,
  // Peripheral address
  ETL_BFF_FIELD(31:0, uint32_t, PA)
)

// CMAR4
//
// DMA channel x memory address register
//
//   Offset: 0x050
ETL_BFF_REG_RW(uint32_t, CMAR4,
  // Memory 1 address (used in case of Double buffer mode)
  ETL_BFF_FIELD(31:0, uint32_t, MA)
)

ETL_BFF_REG_RESERVED(uint32_t, reserved4, 1)

// CCR5
//
// DMA channel 4 configuration register
//
//   Offset: 0x058
ETL_BFF_REG_RW(uint32_t, CCR5,
  // MEM2MEM
  ETL_BFF_FIELD(14:14, bool, MEM2MEM)
  // PL
  ETL_BFF_FIELD(13:12, uint8_t, PL)
  // MSIZE
  ETL_BFF_FIELD(11:10, uint8_t, MSIZE)
  // PSIZE
  ETL_BFF_FIELD(9:8, uint8_t, PSIZE)
  // MINC
  ETL_BFF_FIELD(7:7, bool, MINC)
  // PINC
  ETL_BFF_FIELD(6:6, bool, PINC)
  // CIRC
  ETL_BFF_FIELD(5:5, bool, CIRC)
  // DIR
  ETL_BFF_FIELD(4:4, bool, DIR)
  // TEIE
  ETL_BFF_FIELD(3:3, bool, TEIE)
  // HTIE
  ETL_BFF_FIELD(2:2, bool, HTIE)
  // TCIE
  ETL_BFF_FIELD(1:1, bool, TCIE)
  // channel enable
  ETL_BFF_FIELD(0:0, bool, EN)
)

// CNDTR5
//
// channel x number of data to transfer register
//
//   Offset: 0x05C
ETL_BFF_REG_RW(uint32_t, CNDTR5,
  // Number of data items to transfer
  ETL_BFF_FIELD(15:0, uint16_t, NDT)
)

// CPAR5
//
// DMA channel x peripheral address register
//
//   Offset: 0x060
ETL_BFF_REG_RW(uint32_t, CPAR5,
  // Peripheral address
  ETL_BFF_FIELD(31:0, uint32_t, PA)
)

// CMAR5
//
// DMA channel x memory address register
//
//   Offset: 0x064
ETL_BFF_REG_RW(uint32_t, CMAR5,
  // Memory 1 address (used in case of Double buffer mode)
  ETL_BFF_FIELD(31:0, uint32_t, MA)
)

ETL_BFF_REG_RESERVED(uint32_t, reserved5, 1)

// CCR6
//
// DMA channel 5 configuration register
//
//   Offset: 0x06C
ETL_BFF_REG_RW(uint32_t, CCR6,
  // MEM2MEM
  ETL_BFF_FIELD(14:14, bool, MEM2MEM)
  // PL
  ETL_BFF_FIELD(13:12, uint8_t, PL)
  // MSIZE
  ETL_BFF_FIELD(11:10, uint8_t, MSIZE)
  // PSIZE
  ETL_BFF_FIELD(9:8, uint8_t, PSIZE)
  // MINC
  ETL_BFF_FIELD(7:7, bool, MINC)
  // PINC
  ETL_BFF_FIELD(6:6, bool, PINC)
  // CIRC
  ETL_BFF_FIELD(5:5, bool, CIRC)
  // DIR
  ETL_BFF_FIELD(4:4, bool, DIR)
  // TEIE
  ETL_BFF_FIELD(3:3, bool, TEIE)
  // HTIE
  ETL_BFF_FIELD(2:2, bool, HTIE)
  // TCIE
  ETL_BFF_FIELD(1:1, bool, TCIE)
  // channel enable
  ETL_BFF_FIELD(0:0, bool, EN)
)

// CNDTR6
//
// channel x number of data to transfer register
//
//   Offset: 0x070
ETL_BFF_REG_RW(uint32_t, CNDTR6,
  // Number of data items to transfer
  ETL_BFF_FIELD(15:0, uint16_t, NDT)
)

// CPAR6
//
// DMA channel x peripheral address register
//
//   Offset: 0x074
ETL_BFF_REG_RW(uint32_t, CPAR6,
  // Peripheral address
  ETL_BFF_FIELD(31:0, uint32_t, PA)
)

// CMAR6
//
// DMA channel x memory address register
//
//   Offset: 0x078
ETL_BFF_REG_RW(uint32_t, CMAR6,
  // Memory 1 address (used in case of Double buffer mode)
  ETL_BFF_FIELD(31:0, uint32_t, MA)
)

ETL_BFF_REG_RESERVED(uint32_t, reserved6, 1)

// CCR7
//
// DMA channel 6 configuration register
//
//   Offset: 0x080
ETL_BFF_REG_RW(uint32_t, CCR7,
  // MEM2MEM
  ETL_BFF_FIELD(14:14, bool, MEM2MEM)
  // PL
  ETL_BFF_FIELD(13:12, uint8_t, PL)
  // MSIZE
  ETL_BFF_FIELD(11:10, uint8_t, MSIZE)
  // PSIZE
  ETL_BFF_FIELD(9:8, uint8_t, PSIZE)
  // MINC
  ETL_BFF_FIELD(7:7, bool, MINC)
  // PINC
  ETL_BFF_FIELD(6:6, bool, PINC)
  // CIRC
  ETL_BFF_FIELD(5:5, bool, CIRC)
  // DIR
  ETL_BFF_FIELD(4:4, bool, DIR)
  // TEIE
  ETL_BFF_FIELD(3:3, bool, TEIE)
  // HTIE
  ETL_BFF_FIELD(2:2, bool, HTIE)
  // TCIE
  ETL_BFF_FIELD(1:1, bool, TCIE)
  // channel enable
  ETL_BFF_FIELD(0:0, bool, EN)
)

// CNDTR7
//
// channel x number of data to transfer register
//
//   Offset: 0x084
ETL_BFF_REG_RW(uint32_t, CNDTR7,
  // Number of data items to transfer
  ETL_BFF_FIELD(15:0, uint16_t, NDT)
)

// CPAR7
//
// DMA channel x peripheral address register
//
//   Offset: 0x088
ETL_BFF_REG_RW(uint32_t, CPAR7,
  // Peripheral address
  ETL_BFF_FIELD(31:0, uint32_t, PA)
)

// CMAR7
//
// DMA channel x memory address register
//
//   Offset: 0x08C
ETL_BFF_REG_RW(uint32_t, CMAR7,
  // Memory 1 address (used in case of Double buffer mode)
  ETL_BFF_FIELD(31:0, uint32_t, MA)
)

ETL_BFF_REG_RESERVED(uint32_t, reserved7, 1)

// CCR8
//
// DMA channel 7 configuration register
//
//   Offset: 0x094
ETL_BFF_REG_RW(uint32_t, CCR8,
  // MEM2MEM
  ETL_BFF_FIELD(14:14, bool, MEM2MEM)
  // PL
  ETL_BFF_FIELD(13:12, uint8_t, PL)
  // MSIZE
  ETL_BFF_FIELD(11:10, uint8_t, MSIZE)
  // PSIZE
  ETL_BFF_FIELD(9:8, uint8_t, PSIZE)
  // MINC
  ETL_BFF_FIELD(7:7, bool, MINC)
  // PINC
  ETL_BFF_FIELD(6:6, bool, PINC)
  // CIRC
  ETL_BFF_FIELD(5:5, bool, CIRC)
  // DIR
  ETL_BFF_FIELD(4:4, bool, DIR)
  // TEIE
  ETL_BFF_FIELD(3:3, bool, TEIE)
  // HTIE
  ETL_BFF_FIELD(2:2, bool, HTIE)
  // TCIE
  ETL_BFF_FIELD(1:1, bool, TCIE)
  // channel enable
  ETL_BFF_FIELD(0:0, bool, EN)
)

// CNDTR8
//
// channel x number of data to transfer register
//
//   Offset: 0x098
ETL_BFF_REG_RW(uint32_t, CNDTR8,
  // Number of data items to transfer
  ETL_BFF_FIELD(15:0, uint16_t, NDT)
)

// CPAR8
//
// DMA channel x peripheral address register
//
//   Offset: 0x09C
ETL_BFF_REG_RW(uint32_t, CPAR8,
  // Peripheral address
  ETL_BFF_FIELD(31:0, uint32_t, PA)
)

// CMAR8
//
// DMA channel x memory address register
//
//   Offset: 0x0A0
ETL_BFF_REG_RW(uint32_t, CMAR8,
  // Memory 1 address (used in case of Double buffer mode)
  ETL_BFF_FIELD(31:0, uint32_t, MA)
)

// clang-format on
