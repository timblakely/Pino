// clang-format off

// CR
//
// Clock control register
//
//   Offset: 0x000
//   Reset value: 0x00000063
ETL_BFF_REG_RW(uint32_t, CR,
  // Main PLL clock ready flag
  ETL_BFF_FIELD(25:25, bool, PLLRDY)
  // Main PLL enable
  ETL_BFF_FIELD(24:24, bool, PLLON)
  // 23 : 20 reserved
  // Clock security system enable
  ETL_BFF_FIELD(19:19, bool, CSSON)
  // HSE crystal oscillator bypass
  ETL_BFF_FIELD(18:18, bool, HSEBYP)
  // HSE clock ready flag
  ETL_BFF_FIELD(17:17, bool, HSERDY)
  // HSE clock enable
  ETL_BFF_FIELD(16:16, bool, HSEON)
  // 15 : 11 reserved
  // HSI clock ready flag
  ETL_BFF_FIELD(10:10, bool, HSIRDY)
  // HSI always enable for peripheral kernels
  ETL_BFF_FIELD(9:9, bool, HSIKERON)
  // HSI clock enable
  ETL_BFF_FIELD(8:8, bool, HSION)
)

// ICSCR
//
// Internal clock sources calibration register
//
//   Offset: 0x004
//   Reset value: 0x40000000
ETL_BFF_REG_RW(uint32_t, ICSCR,
  // Internal High Speed clock trimming
  ETL_BFF_FIELD(30:24, uint8_t, HSITRIM)
  // Internal High Speed clock Calibration
  ETL_BFF_FIELD(23:16, uint8_t, HSICAL0)
)

// CFGR
//
// Clock configuration register
//
//   Offset: 0x008
//   Reset value: 0x00000005
ETL_BFF_REG_RW(uint32_t, CFGR,
  // Microcontroller clock output prescaler
  ETL_BFF_FIELD(30:28, uint8_t, MCOPRE)
  // Microcontroller clock output
  ETL_BFF_FIELD(27:24, uint8_t, MCOSEL)
  // 23 : 14 reserved
  // APB high-speed prescaler (APB2)
  ETL_BFF_FIELD(13:11, uint8_t, PPRE2)
  // PB low-speed prescaler (APB1)
  ETL_BFF_FIELD(10:8, uint8_t, PPRE1)
  // AHB prescaler
  ETL_BFF_FIELD(7:4, uint8_t, HPRE)
  // System clock switch status
  ETL_BFF_FIELD(3:2, uint8_t, SWS)
  // System clock switch
  ETL_BFF_FIELD(1:0, uint8_t, SW)
)

// PLLCFGR
//
// PLL configuration register
//
//   Offset: 0x00C
//   Reset value: 0x00001000
ETL_BFF_REG_RW(uint32_t, PLLCFGR,
  // Main PLL division factor for PLLSAI2CLK
  ETL_BFF_FIELD(31:27, uint8_t, PLLPDIV)
  // Main PLL division factor for PLLCLK (system clock)
  ETL_BFF_FIELD(26:25, uint8_t, PLLR)
  // Main PLL PLLCLK output enable
  ETL_BFF_FIELD(24:24, bool, PLLREN)
  // 23 reserved
  // Main PLL division factor for PLLUSB1CLK(48 MHz clock)
  ETL_BFF_FIELD(22:21, uint8_t, PLLQ)
  // Main PLL PLLUSB1CLK output enable
  ETL_BFF_FIELD(20:20, bool, PLLQEN)
  // 19 : 18 reserved
  // Main PLL division factor for PLLSAI3CLK (SAI1 and SAI2 clock)
  ETL_BFF_FIELD(17:17, bool, PLLP)
  // Main PLL PLLSAI3CLK output enable
  ETL_BFF_FIELD(16:16, bool, PLLPEN)
  // 15 reserved
  // Main PLL multiplication factor for VCO
  ETL_BFF_FIELD(14:8, uint8_t, PLLN)
  // Division factor for the main PLL and audio PLL (PLLSAI1 and PLLSAI2) input
// clock
  ETL_BFF_FIELD(7:4, uint8_t, PLLM)
  // 3 : 2 reserved
  // Main PLL, PLLSAI1 and PLLSAI2 entry clock source
  ETL_BFF_FIELD(1:0, uint8_t, PLLSRC)
)

ETL_BFF_REG_RESERVED(uint32_t, reserved1, 2)

// CIER
//
// Clock interrupt enable register
//
//   Offset: 0x018
ETL_BFF_REG_RW(uint32_t, CIER,
  // HSI48 ready interrupt enable
  ETL_BFF_FIELD(10:10, bool, HSI48RDYIE)
  // LSE clock security system interrupt enable
  ETL_BFF_FIELD(9:9, bool, LSECSSIE)
  // 8 : 6 reserved
  // PLL ready interrupt enable
  ETL_BFF_FIELD(5:5, bool, PLLRDYIE)
  // HSE ready interrupt enable
  ETL_BFF_FIELD(4:4, bool, HSERDYIE)
  // HSI ready interrupt enable
  ETL_BFF_FIELD(3:3, bool, HSIRDYIE)
  // 2 reserved
  // LSE ready interrupt enable
  ETL_BFF_FIELD(1:1, bool, LSERDYIE)
  // LSI ready interrupt enable
  ETL_BFF_FIELD(0:0, bool, LSIRDYIE)
)

// CIFR
//
// Clock interrupt flag register
//
//   Offset: 0x01C
ETL_BFF_REG_RO(uint32_t, CIFR,
  // HSI48 ready interrupt flag
  ETL_BFF_FIELD(10:10, bool, HSI48RDYF)
  // LSE Clock security system interrupt flag
  ETL_BFF_FIELD(9:9, bool, LSECSSF)
  // Clock security system interrupt flag
  ETL_BFF_FIELD(8:8, bool, CSSF)
  // 7 : 6 reserved
  // PLL ready interrupt flag
  ETL_BFF_FIELD(5:5, bool, PLLRDYF)
  // HSE ready interrupt flag
  ETL_BFF_FIELD(4:4, bool, HSERDYF)
  // HSI ready interrupt flag
  ETL_BFF_FIELD(3:3, bool, HSIRDYF)
  // 2 reserved
  // LSE ready interrupt flag
  ETL_BFF_FIELD(1:1, bool, LSERDYF)
  // LSI ready interrupt flag
  ETL_BFF_FIELD(0:0, bool, LSIRDYF)
)

// CICR
//
// Clock interrupt clear register
//
//   Offset: 0x020
ETL_BFF_REG_WO(uint32_t, CICR,
  // HSI48 oscillator ready interrupt clear
  ETL_BFF_FIELD(10:10, bool, HSI48RDYC)
  // LSE Clock security system interrupt clear
  ETL_BFF_FIELD(9:9, bool, LSECSSC)
  // Clock security system interrupt clear
  ETL_BFF_FIELD(8:8, bool, CSSC)
  // 7 : 6 reserved
  // PLL ready interrupt clear
  ETL_BFF_FIELD(5:5, bool, PLLRDYC)
  // HSE ready interrupt clear
  ETL_BFF_FIELD(4:4, bool, HSERDYC)
  // HSI ready interrupt clear
  ETL_BFF_FIELD(3:3, bool, HSIRDYC)
  // 2 reserved
  // LSE ready interrupt clear
  ETL_BFF_FIELD(1:1, bool, LSERDYC)
  // LSI ready interrupt clear
  ETL_BFF_FIELD(0:0, bool, LSIRDYC)
)

ETL_BFF_REG_RESERVED(uint32_t, reserved2, 1)

// AHB1RSTR
//
// AHB1 peripheral reset register
//
//   Offset: 0x028
ETL_BFF_REG_RW(uint32_t, AHB1RSTR,
  // CRC reset
  ETL_BFF_FIELD(12:12, bool, CRCRST)
  // 11 : 9 reserved
  // Flash memory interface reset
  ETL_BFF_FIELD(8:8, bool, FLASHRST)
  // 7 : 5 reserved
  // FMAC reset
  ETL_BFF_FIELD(4:4, bool, FMACRST)
  // CORDIC reset
  ETL_BFF_FIELD(3:3, bool, CORDICRST)
  // DMAMUXRST
  ETL_BFF_FIELD(2:2, bool, DMAMUX1RST)
  // DMA2 reset
  ETL_BFF_FIELD(1:1, bool, DMA2RST)
  // DMA1 reset
  ETL_BFF_FIELD(0:0, bool, DMA1RST)
)

// AHB2RSTR
//
// AHB2 peripheral reset register
//
//   Offset: 0x02C
ETL_BFF_REG_RW(uint32_t, AHB2RSTR,
  // Random Number Generator module reset
  ETL_BFF_FIELD(26:26, bool, RNGRST)
  // 25 reserved
  // Cryptography module reset
  ETL_BFF_FIELD(24:24, bool, AESRST)
  // 23 : 20 reserved
  // DAC4 interface reset
  ETL_BFF_FIELD(19:19, bool, DAC4RST)
  // DAC3 interface reset
  ETL_BFF_FIELD(18:18, bool, DAC3RST)
  // DAC2 interface reset
  ETL_BFF_FIELD(17:17, bool, DAC2RST)
  // DAC1 interface reset
  ETL_BFF_FIELD(16:16, bool, DAC1RST)
  // 15 reserved
  // SAR ADC345 interface reset
  ETL_BFF_FIELD(14:14, bool, ADC345RST)
  // ADC reset
  ETL_BFF_FIELD(13:13, bool, ADC12RST)
  // 12 : 7 reserved
  // IO port G reset
  ETL_BFF_FIELD(6:6, bool, GPIOGRST)
  // IO port F reset
  ETL_BFF_FIELD(5:5, bool, GPIOFRST)
  // IO port E reset
  ETL_BFF_FIELD(4:4, bool, GPIOERST)
  // IO port D reset
  ETL_BFF_FIELD(3:3, bool, GPIODRST)
  // IO port C reset
  ETL_BFF_FIELD(2:2, bool, GPIOCRST)
  // IO port B reset
  ETL_BFF_FIELD(1:1, bool, GPIOBRST)
  // IO port A reset
  ETL_BFF_FIELD(0:0, bool, GPIOARST)
)

// AHB3RSTR
//
// AHB3 peripheral reset register
//
//   Offset: 0x030
ETL_BFF_REG_RW(uint32_t, AHB3RSTR,
  // Quad SPI 1 module reset
  ETL_BFF_FIELD(8:8, bool, QSPIRST)
  // 7 : 1 reserved
  // Flexible memory controller reset
  ETL_BFF_FIELD(0:0, bool, FMCRST)
)

ETL_BFF_REG_RESERVED(uint32_t, reserved3, 1)

// APB1RSTR1
//
// APB1 peripheral reset register 1
//
//   Offset: 0x038
ETL_BFF_REG_RW(uint32_t, APB1RSTR1,
  // Low Power Timer 1 reset
  ETL_BFF_FIELD(31:31, bool, LPTIM1RST)
  // I2C3 interface reset
  ETL_BFF_FIELD(30:30, bool, I2C3RST)
  // 29 reserved
  // Power interface reset
  ETL_BFF_FIELD(28:28, bool, PWRRST)
  // 27 : 26 reserved
  // FDCAN reset
  ETL_BFF_FIELD(25:25, bool, FDCANRST)
  // 24 reserved
  // USBD reset
  ETL_BFF_FIELD(23:23, bool, USBRST)
  // I2C2 reset
  ETL_BFF_FIELD(22:22, bool, I2C2RST)
  // I2C1 reset
  ETL_BFF_FIELD(21:21, bool, I2C1RST)
  // UART5 reset
  ETL_BFF_FIELD(20:20, bool, UART5RST)
  // UART4 reset
  ETL_BFF_FIELD(19:19, bool, UART4RST)
  // USART3 reset
  ETL_BFF_FIELD(18:18, bool, USART3RST)
  // USART2 reset
  ETL_BFF_FIELD(17:17, bool, USART2RST)
  // 16 reserved
  // SPI3 reset
  ETL_BFF_FIELD(15:15, bool, SPI3RST)
  // SPI2 reset
  ETL_BFF_FIELD(14:14, bool, SPI2RST)
  // 13 : 9 reserved
  // Clock recovery system reset
  ETL_BFF_FIELD(8:8, bool, CRSRST)
  // 7 : 6 reserved
  // TIM7 timer reset
  ETL_BFF_FIELD(5:5, bool, TIM7RST)
  // TIM6 timer reset
  ETL_BFF_FIELD(4:4, bool, TIM6RST)
  // TIM5 timer reset
  ETL_BFF_FIELD(3:3, bool, TIM5RST)
  // TIM3 timer reset
  ETL_BFF_FIELD(2:2, bool, TIM4RST)
  // TIM3 timer reset
  ETL_BFF_FIELD(1:1, bool, TIM3RST)
  // TIM2 timer reset
  ETL_BFF_FIELD(0:0, bool, TIM2RST)
)

// APB1RSTR2
//
// APB1 peripheral reset register 2
//
//   Offset: 0x03C
ETL_BFF_REG_RW(uint32_t, APB1RSTR2,
  // UCPD1 reset
  ETL_BFF_FIELD(8:8, bool, UCPD1RST)
  // 7 : 2 reserved
  // I2C4 reset
  ETL_BFF_FIELD(1:1, bool, I2C4RST)
  // Low-power UART 1 reset
  ETL_BFF_FIELD(0:0, bool, LPUART1RST)
)

// APB2RSTR
//
// APB2 peripheral reset register
//
//   Offset: 0x040
ETL_BFF_REG_RW(uint32_t, APB2RSTR,
  // HRTIMER reset
  ETL_BFF_FIELD(26:26, bool, HRTIM1RST)
  // 25 : 22 reserved
  // Serial audio interface 1 (SAI1) reset
  ETL_BFF_FIELD(21:21, bool, SAI1RST)
  // Timer 20 reset
  ETL_BFF_FIELD(20:20, bool, TIM20RST)
  // 19 reserved
  // TIM17 timer reset
  ETL_BFF_FIELD(18:18, bool, TIM17RST)
  // TIM16 timer reset
  ETL_BFF_FIELD(17:17, bool, TIM16RST)
  // TIM15 timer reset
  ETL_BFF_FIELD(16:16, bool, TIM15RST)
  // SPI 4 reset
  ETL_BFF_FIELD(15:15, bool, SPI4RST)
  // USART1 reset
  ETL_BFF_FIELD(14:14, bool, USART1RST)
  // TIM8 timer reset
  ETL_BFF_FIELD(13:13, bool, TIM8RST)
  // SPI1 reset
  ETL_BFF_FIELD(12:12, bool, SPI1RST)
  // TIM1 timer reset
  ETL_BFF_FIELD(11:11, bool, TIM1RST)
  // 10 : 1 reserved
  // System configuration (SYSCFG) reset
  ETL_BFF_FIELD(0:0, bool, SYSCFGRST)
)

ETL_BFF_REG_RESERVED(uint32_t, reserved4, 1)

// AHB1ENR
//
// AHB1 peripheral clock enable register
//
//   Offset: 0x048
//   Reset value: 0x00000100
ETL_BFF_REG_RW(uint32_t, AHB1ENR,
  // CRC clock enable
  ETL_BFF_FIELD(12:12, bool, CRCEN)
  // 11 : 9 reserved
  // Flash memory interface clock enable
  ETL_BFF_FIELD(8:8, bool, FLASHEN)
  // 7 : 5 reserved
  // FMAC clock enable
  ETL_BFF_FIELD(4:4, bool, FMACEN)
  // CORDIC clock enable
  ETL_BFF_FIELD(3:3, bool, CORDICEN)
  // DMAMUX clock enable
  ETL_BFF_FIELD(2:2, bool, DMAMUXEN)
  // DMA2 clock enable
  ETL_BFF_FIELD(1:1, bool, DMA2EN)
  // DMA1 clock enable
  ETL_BFF_FIELD(0:0, bool, DMA1EN)
)

// AHB2ENR
//
// AHB2 peripheral clock enable register
//
//   Offset: 0x04C
ETL_BFF_REG_RW(uint32_t, AHB2ENR,
  // Random Number Generator clock enable
  ETL_BFF_FIELD(26:26, bool, RNGEN)
  // 25 reserved
  // AES clock enable
  ETL_BFF_FIELD(24:24, bool, AESEN)
  // 23 : 20 reserved
  // DAC4 clock enable
  ETL_BFF_FIELD(19:19, bool, DAC4EN)
  // Random Number Generator clock enable
  ETL_BFF_FIELD(18:18, bool, DAC3EN)
  // HASH clock enable
  ETL_BFF_FIELD(17:17, bool, DAC2EN)
  // AES accelerator clock enable
  ETL_BFF_FIELD(16:16, bool, DAC1EN)
  // 15 reserved
  // DCMI clock enable
  ETL_BFF_FIELD(14:14, bool, ADC345EN)
  // ADC clock enable
  ETL_BFF_FIELD(13:13, bool, ADC12EN)
  // 12 : 7 reserved
  // IO port G clock enable
  ETL_BFF_FIELD(6:6, bool, GPIOGEN)
  // IO port F clock enable
  ETL_BFF_FIELD(5:5, bool, GPIOFEN)
  // IO port E clock enable
  ETL_BFF_FIELD(4:4, bool, GPIOEEN)
  // IO port D clock enable
  ETL_BFF_FIELD(3:3, bool, GPIODEN)
  // IO port C clock enable
  ETL_BFF_FIELD(2:2, bool, GPIOCEN)
  // IO port B clock enable
  ETL_BFF_FIELD(1:1, bool, GPIOBEN)
  // IO port A clock enable
  ETL_BFF_FIELD(0:0, bool, GPIOAEN)
)

// AHB3ENR
//
// AHB3 peripheral clock enable register
//
//   Offset: 0x050
ETL_BFF_REG_RW(uint32_t, AHB3ENR,
  // QUADSPI memory interface clock enable
  ETL_BFF_FIELD(8:8, bool, QSPIEN)
  // 7 : 1 reserved
  // Flexible memory controller clock enable
  ETL_BFF_FIELD(0:0, bool, FMCEN)
)

ETL_BFF_REG_RESERVED(uint32_t, reserved5, 1)

// APB1ENR1
//
// APB1ENR1
//
//   Offset: 0x058
ETL_BFF_REG_RW(uint32_t, APB1ENR1,
  // Low power timer 1 clock enable
  ETL_BFF_FIELD(31:31, bool, LPTIM1EN)
  // I2C3 clock enable
  ETL_BFF_FIELD(30:30, bool, I2C3EN)
  // 29 reserved
  // Power interface clock enable
  ETL_BFF_FIELD(28:28, bool, PWREN)
  // 27 : 26 reserved
  // FDCAN clock enable
  ETL_BFF_FIELD(25:25, bool, FDCANEN)
  // 24 reserved
  // USB device clock enable
  ETL_BFF_FIELD(23:23, bool, USBEN)
  // I2C2 clock enable
  ETL_BFF_FIELD(22:22, bool, I2C2EN)
  // I2C1 clock enable
  ETL_BFF_FIELD(21:21, bool, I2C1EN)
  // UART5 clock enable
  ETL_BFF_FIELD(20:20, bool, UART5EN)
  // UART4 clock enable
  ETL_BFF_FIELD(19:19, bool, UART4EN)
  // USART3 clock enable
  ETL_BFF_FIELD(18:18, bool, USART3EN)
  // USART2 clock enable
  ETL_BFF_FIELD(17:17, bool, USART2EN)
  // 16 reserved
  // SPI3 clock enable
  ETL_BFF_FIELD(15:15, bool, SP3EN)
  // SPI2 clock enable
  ETL_BFF_FIELD(14:14, bool, SPI2EN)
  // 13 : 12 reserved
  // Window watchdog clock enable
  ETL_BFF_FIELD(11:11, bool, WWDGEN)
  // RTC APB clock enable
  ETL_BFF_FIELD(10:10, bool, RTCAPBEN)
  // 9 reserved
  // CRSclock enable
  ETL_BFF_FIELD(8:8, bool, CRSEN)
  // 7 : 6 reserved
  // TIM7 timer clock enable
  ETL_BFF_FIELD(5:5, bool, TIM7EN)
  // TIM6 timer clock enable
  ETL_BFF_FIELD(4:4, bool, TIM6EN)
  // TIM5 timer clock enable
  ETL_BFF_FIELD(3:3, bool, TIM5EN)
  // TIM4 timer clock enable
  ETL_BFF_FIELD(2:2, bool, TIM4EN)
  // TIM3 timer clock enable
  ETL_BFF_FIELD(1:1, bool, TIM3EN)
  // TIM2 timer clock enable
  ETL_BFF_FIELD(0:0, bool, TIM2EN)
)

// APB1ENR2
//
// APB1 peripheral clock enable register 2
//
//   Offset: 0x05C
ETL_BFF_REG_RW(uint32_t, APB1ENR2,
  // UCPD1 clock enable
  ETL_BFF_FIELD(8:8, bool, UCPD1EN)
  // 7 : 2 reserved
  // I2C4 clock enable
  ETL_BFF_FIELD(1:1, bool, I2C4EN)
  // Low power UART 1 clock enable
  ETL_BFF_FIELD(0:0, bool, LPUART1EN)
)

// APB2ENR
//
// APB2ENR
//
//   Offset: 0x060
ETL_BFF_REG_RW(uint32_t, APB2ENR,
  // HRTIMER clock enable
  ETL_BFF_FIELD(26:26, bool, HRTIM1EN)
  // 25 : 22 reserved
  // SAI1 clock enable
  ETL_BFF_FIELD(21:21, bool, SAI1EN)
  // Timer 20 clock enable
  ETL_BFF_FIELD(20:20, bool, TIM20EN)
  // 19 reserved
  // TIM17 timer clock enable
  ETL_BFF_FIELD(18:18, bool, TIM17EN)
  // TIM16 timer clock enable
  ETL_BFF_FIELD(17:17, bool, TIM16EN)
  // TIM15 timer clock enable
  ETL_BFF_FIELD(16:16, bool, TIM15EN)
  // SPI 4 clock enable
  ETL_BFF_FIELD(15:15, bool, SPI4EN)
  // USART1clock enable
  ETL_BFF_FIELD(14:14, bool, USART1EN)
  // TIM8 timer clock enable
  ETL_BFF_FIELD(13:13, bool, TIM8EN)
  // SPI1 clock enable
  ETL_BFF_FIELD(12:12, bool, SPI1EN)
  // TIM1 timer clock enable
  ETL_BFF_FIELD(11:11, bool, TIM1EN)
  // 10 : 1 reserved
  // SYSCFG clock enable
  ETL_BFF_FIELD(0:0, bool, SYSCFGEN)
)

ETL_BFF_REG_RESERVED(uint32_t, reserved6, 1)

// AHB1SMENR
//
// AHB1 peripheral clocks enable in Sleep and Stop modes register
//
//   Offset: 0x068
//   Reset value: 0x0000130F
ETL_BFF_REG_RW(uint32_t, AHB1SMENR,
  // CRCSMEN
  ETL_BFF_FIELD(12:12, bool, CRCSMEN)
  // 11 : 10 reserved
  // SRAM1 interface clocks enable during Sleep and Stop modes
  ETL_BFF_FIELD(9:9, bool, SRAM1SMEN)
  // Flash memory interface clocks enable during Sleep and Stop modes
  ETL_BFF_FIELD(8:8, bool, FLASHSMEN)
  // 7 : 5 reserved
  // FMACSM clock enable
  ETL_BFF_FIELD(4:4, bool, FMACSMEN)
  // CORDIC clock enable during sleep mode
  ETL_BFF_FIELD(3:3, bool, CORDICSMEN)
  // DMAMUX clock enable during Sleep and Stop modes
  ETL_BFF_FIELD(2:2, bool, DMAMUX1SMEN)
  // DMA2 clocks enable during Sleep and Stop modes
  ETL_BFF_FIELD(1:1, bool, DMA2SMEN)
  // DMA1 clocks enable during Sleep and Stop modes
  ETL_BFF_FIELD(0:0, bool, DMA1SMEN)
)

// AHB2SMENR
//
// AHB2 peripheral clocks enable in Sleep and Stop modes register
//
//   Offset: 0x06C
//   Reset value: 0x050F667F
ETL_BFF_REG_RW(uint32_t, AHB2SMENR,
  // Random Number Generator clock enable during sleep mode
  ETL_BFF_FIELD(26:26, bool, RNGEN)
  // 25 reserved
  // Cryptography clock enable during sleep mode
  ETL_BFF_FIELD(24:24, bool, AESMEN)
  // 23 : 20 reserved
  // DAC4 clock enable during sleep mode
  ETL_BFF_FIELD(19:19, bool, DAC4SMEN)
  // DAC3 clock enable during sleep mode
  ETL_BFF_FIELD(18:18, bool, DAC3SMEN)
  // HASH clock enable during Sleep and Stop modes
  ETL_BFF_FIELD(17:17, bool, DAC2SMEN)
  // AES accelerator clocks enable during Sleep and Stop modes
  ETL_BFF_FIELD(16:16, bool, DAC1SMEN)
  // 15 reserved
  // DCMI clock enable during Sleep and Stop modes
  ETL_BFF_FIELD(14:14, bool, ADC345SMEN)
  // ADC clocks enable during Sleep and Stop modes
  ETL_BFF_FIELD(13:13, bool, ADC12SMEN)
  // 12 : 11 reserved
  // SRAM2 interface clocks enable during Sleep and Stop modes
  ETL_BFF_FIELD(10:10, bool, SRAM2SMEN)
  // CCM SRAM interface clocks enable during Sleep and Stop modes
  ETL_BFF_FIELD(9:9, bool, CCMSRAMSMEN)
  // 8 : 7 reserved
  // IO port G clocks enable during Sleep and Stop modes
  ETL_BFF_FIELD(6:6, bool, GPIOGSMEN)
  // IO port F clocks enable during Sleep and Stop modes
  ETL_BFF_FIELD(5:5, bool, GPIOFSMEN)
  // IO port E clocks enable during Sleep and Stop modes
  ETL_BFF_FIELD(4:4, bool, GPIOESMEN)
  // IO port D clocks enable during Sleep and Stop modes
  ETL_BFF_FIELD(3:3, bool, GPIODSMEN)
  // IO port C clocks enable during Sleep and Stop modes
  ETL_BFF_FIELD(2:2, bool, GPIOCSMEN)
  // IO port B clocks enable during Sleep and Stop modes
  ETL_BFF_FIELD(1:1, bool, GPIOBSMEN)
  // IO port A clocks enable during Sleep and Stop modes
  ETL_BFF_FIELD(0:0, bool, GPIOASMEN)
)

// AHB3SMENR
//
// AHB3 peripheral clocks enable in Sleep and Stop modes register
//
//   Offset: 0x070
//   Reset value: 0x00000101
ETL_BFF_REG_RW(uint32_t, AHB3SMENR,
  // QUADSPI memory interface clock enable during Sleep and Stop modes
  ETL_BFF_FIELD(8:8, bool, QSPISMEN)
  // 7 : 1 reserved
  // Flexible memory controller clocks enable during Sleep and Stop modes
  ETL_BFF_FIELD(0:0, bool, FMCSMEN)
)

ETL_BFF_REG_RESERVED(uint32_t, reserved7, 1)

// APB1SMENR1
//
// APB1SMENR1
//
//   Offset: 0x078
//   Reset value: 0xD2FECD3F
ETL_BFF_REG_RW(uint32_t, APB1SMENR1,
  // Low Power Timer1 clock enable during sleep mode
  ETL_BFF_FIELD(31:31, bool, LPTIM1SMEN)
  // I2C3 clocks enable during Sleep and Stop modes
  ETL_BFF_FIELD(30:30, bool, I2C3SMEN)
  // 29 reserved
  // Power interface clocks enable during Sleep and Stop modes
  ETL_BFF_FIELD(28:28, bool, PWRSMEN)
  // 27 : 26 reserved
  // FDCAN clock enable during sleep mode
  ETL_BFF_FIELD(25:25, bool, FDCANSMEN)
  // 24 reserved
  // USB device clocks enable during Sleep and Stop modes
  ETL_BFF_FIELD(23:23, bool, USBSMEN)
  // I2C2 clocks enable during Sleep and Stop modes
  ETL_BFF_FIELD(22:22, bool, I2C2SMEN)
  // I2C1 clocks enable during Sleep and Stop modes
  ETL_BFF_FIELD(21:21, bool, I2C1SMEN)
  // UART5 clocks enable during Sleep and Stop modes
  ETL_BFF_FIELD(20:20, bool, UART5SMEN)
  // UART4 clocks enable during Sleep and Stop modes
  ETL_BFF_FIELD(19:19, bool, UART4SMEN)
  // USART3 clocks enable during Sleep and Stop modes
  ETL_BFF_FIELD(18:18, bool, USART3SMEN)
  // USART2 clocks enable during Sleep and Stop modes
  ETL_BFF_FIELD(17:17, bool, USART2SMEN)
  // 16 reserved
  // SPI3 clocks enable during Sleep and Stop modes
  ETL_BFF_FIELD(15:15, bool, SP3SMEN)
  // SPI2 clocks enable during Sleep and Stop modes
  ETL_BFF_FIELD(14:14, bool, SPI2SMEN)
  // 13 : 12 reserved
  // Window watchdog clocks enable during Sleep and Stop modes
  ETL_BFF_FIELD(11:11, bool, WWDGSMEN)
  // RTC APB clock enable during Sleep and Stop modes
  ETL_BFF_FIELD(10:10, bool, RTCAPBSMEN)
  // 9 reserved
  // CRS clock enable during sleep mode
  ETL_BFF_FIELD(8:8, bool, CRSSMEN)
  // 7 : 6 reserved
  // TIM7 timer clocks enable during Sleep and Stop modes
  ETL_BFF_FIELD(5:5, bool, TIM7SMEN)
  // TIM6 timer clocks enable during Sleep and Stop modes
  ETL_BFF_FIELD(4:4, bool, TIM6SMEN)
  // TIM5 timer clocks enable during Sleep and Stop modes
  ETL_BFF_FIELD(3:3, bool, TIM5SMEN)
  // TIM4 timer clocks enable during Sleep and Stop modes
  ETL_BFF_FIELD(2:2, bool, TIM4SMEN)
  // TIM3 timer clocks enable during Sleep and Stop modes
  ETL_BFF_FIELD(1:1, bool, TIM3SMEN)
  // TIM2 timer clocks enable during Sleep and Stop modes
  ETL_BFF_FIELD(0:0, bool, TIM2SMEN)
)

// APB1SMENR2
//
// APB1 peripheral clocks enable in Sleep and Stop modes register 2
//
//   Offset: 0x07C
//   Reset value: 0x00000103
ETL_BFF_REG_RW(uint32_t, APB1SMENR2,
  // UCPD1 clocks enable during Sleep and Stop modes
  ETL_BFF_FIELD(8:8, bool, UCPD1SMEN)
  // 7 : 2 reserved
  // I2C4 clocks enable during Sleep and Stop modes
  ETL_BFF_FIELD(1:1, bool, I2C4SMEN)
  // Low power UART 1 clocks enable during Sleep and Stop modes
  ETL_BFF_FIELD(0:0, bool, LPUART1SMEN)
)

// APB2SMENR
//
// APB2SMENR
//
//   Offset: 0x080
//   Reset value: 0x0437F801
ETL_BFF_REG_RW(uint32_t, APB2SMENR,
  // HRTIMER clock enable during sleep mode
  ETL_BFF_FIELD(26:26, bool, HRTIM1SMEN)
  // 25 : 22 reserved
  // SAI1 clock enable during sleep mode
  ETL_BFF_FIELD(21:21, bool, SAI1SMEN)
  // Timer 20clock enable during sleep mode
  ETL_BFF_FIELD(20:20, bool, TIM20SMEN)
  // 19 reserved
  // TIM17 timer clocks enable during Sleep and Stop modes
  ETL_BFF_FIELD(18:18, bool, TIM17SMEN)
  // TIM16 timer clocks enable during Sleep and Stop modes
  ETL_BFF_FIELD(17:17, bool, TIM16SMEN)
  // TIM15 timer clocks enable during Sleep and Stop modes
  ETL_BFF_FIELD(16:16, bool, TIM15SMEN)
  // SPI4 timer clocks enable during Sleep and Stop modes
  ETL_BFF_FIELD(15:15, bool, SPI4SMEN)
  // USART1clocks enable during Sleep and Stop modes
  ETL_BFF_FIELD(14:14, bool, USART1SMEN)
  // TIM8 timer clocks enable during Sleep and Stop modes
  ETL_BFF_FIELD(13:13, bool, TIM8SMEN)
  // SPI1 clocks enable during Sleep and Stop modes
  ETL_BFF_FIELD(12:12, bool, SPI1SMEN)
  // TIM1 timer clocks enable during Sleep and Stop modes
  ETL_BFF_FIELD(11:11, bool, TIM1SMEN)
  // 10 : 1 reserved
  // SYSCFG clocks enable during Sleep and Stop modes
  ETL_BFF_FIELD(0:0, bool, SYSCFGSMEN)
)

ETL_BFF_REG_RESERVED(uint32_t, reserved8, 1)

// CCIPR
//
// CCIPR
//
//   Offset: 0x088
ETL_BFF_REG_RW(uint32_t, CCIPR,
  // ADC3/4/5 clock source selection
  ETL_BFF_FIELD(31:30, uint8_t, ADC345SEL)
  // ADCs clock source selection
  ETL_BFF_FIELD(29:28, uint8_t, ADC12SEL)
  // 48 MHz clock source selection
  ETL_BFF_FIELD(27:26, uint8_t, CLK48SEL)
  // SAI2 clock source selection
  ETL_BFF_FIELD(25:24, uint8_t, FDCANSEL)
  // SAI1 clock source selection
  ETL_BFF_FIELD(23:22, uint8_t, I2S23SEL)
  // Low power timer 2 clock source selection
  ETL_BFF_FIELD(21:20, uint8_t, SAI1SEL)
  // Low power timer 1 clock source selection
  ETL_BFF_FIELD(19:18, uint8_t, LPTIM1SEL)
  // I2C3 clock source selection
  ETL_BFF_FIELD(17:16, uint8_t, I2C3SEL)
  // I2C2 clock source selection
  ETL_BFF_FIELD(15:14, uint8_t, I2C2SEL)
  // I2C1 clock source selection
  ETL_BFF_FIELD(13:12, uint8_t, I2C1SEL)
  // LPUART1 clock source selection
  ETL_BFF_FIELD(11:10, uint8_t, LPUART1SEL)
  // UART5 clock source selection
  ETL_BFF_FIELD(9:8, uint8_t, UART5SEL)
  // UART4 clock source selection
  ETL_BFF_FIELD(7:6, uint8_t, UART4SEL)
  // USART3 clock source selection
  ETL_BFF_FIELD(5:4, uint8_t, USART3SEL)
  // USART2 clock source selection
  ETL_BFF_FIELD(3:2, uint8_t, USART2SEL)
  // USART1 clock source selection
  ETL_BFF_FIELD(1:0, uint8_t, USART1SEL)
)

ETL_BFF_REG_RESERVED(uint32_t, reserved9, 1)

// BDCR
//
// BDCR
//
//   Offset: 0x090
ETL_BFF_REG_RW(uint32_t, BDCR,
  // Low speed clock output selection
  ETL_BFF_FIELD(25:25, bool, LSCOSEL)
  // Low speed clock output enable
  ETL_BFF_FIELD(24:24, bool, LSCOEN)
  // 23 : 17 reserved
  // RTC domain software reset
  ETL_BFF_FIELD(16:16, bool, BDRST)
  // RTC clock enable
  ETL_BFF_FIELD(15:15, bool, RTCEN)
  // 14 : 10 reserved
  // RTC clock source selection
  ETL_BFF_FIELD(9:8, uint8_t, RTCSEL)
  // 7 reserved
  // LSECSSD
  ETL_BFF_FIELD(6:6, bool, LSECSSD)
  // LSECSSON
  ETL_BFF_FIELD(5:5, bool, LSECSSON)
  // SE oscillator drive capability
  ETL_BFF_FIELD(4:3, uint8_t, LSEDRV)
  // LSE oscillator bypass
  ETL_BFF_FIELD(2:2, bool, LSEBYP)
  // LSE oscillator ready
  ETL_BFF_FIELD(1:1, bool, LSERDY)
  // LSE oscillator enable
  ETL_BFF_FIELD(0:0, bool, LSEON)
)

// CSR
//
// CSR
//
//   Offset: 0x094
//   Reset value: 0x0C000000
ETL_BFF_REG_RW(uint32_t, CSR,
  // Low-power reset flag
  ETL_BFF_FIELD(31:31, bool, LPWRSTF)
  // Window watchdog reset flag
  ETL_BFF_FIELD(30:30, bool, WWDGRSTF)
  // Independent window watchdog reset flag
  ETL_BFF_FIELD(29:29, bool, IWDGRSTF)
  // Software reset flag
  ETL_BFF_FIELD(28:28, bool, SFTRSTF)
  // BOR flag
  ETL_BFF_FIELD(27:27, bool, BORRSTF)
  // Pad reset flag
  ETL_BFF_FIELD(26:26, bool, PINRSTF)
  // Option byte loader reset flag
  ETL_BFF_FIELD(25:25, bool, OBLRSTF)
  // 24 reserved
  // Remove reset flag
  ETL_BFF_FIELD(23:23, bool, RMVF)
  // 22 : 2 reserved
  // LSI oscillator ready
  ETL_BFF_FIELD(1:1, bool, LSIRDY)
  // LSI oscillator enable
  ETL_BFF_FIELD(0:0, bool, LSION)
)

// CRRCR
//
// Clock recovery RC register
//
//   Offset: 0x098
ETL_BFF_REG_RW(uint32_t, CRRCR,
  // HSI48 clock calibration
  ETL_BFF_FIELD(15:7, uint16_t, HSI48CAL)
  // 6 : 2 reserved
  // HSI48 clock ready flag
  ETL_BFF_FIELD(1:1, bool, HSI48RDY)
  // HSI48 clock enable
  ETL_BFF_FIELD(0:0, bool, HSI48ON)
)

// CCIPR2
//
// Peripherals independent clock configuration register
//
//   Offset: 0x09C
ETL_BFF_REG_RW(uint32_t, CCIPR2,
  // Octospi clock source selection
  ETL_BFF_FIELD(21:20, uint8_t, QSPISEL)
  // 19 : 2 reserved
  // I2C4 clock source selection
  ETL_BFF_FIELD(1:0, uint8_t, I2C4SEL)
)

// clang-format on
