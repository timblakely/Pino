#include "bldc/firmware/stm32g474/drivers/rcc.h"

#include "bldc/firmware/stm32g474/drivers/flash.h"
#include "bldc/firmware/stm32g474/timer.h"
#include "third_party/stm32cubeg4/stm32g474xx.h"

namespace bus {
#include "third_party/stm32cubeg4/stm32g4xx_ll_bus.h"
}  // namespace bus

namespace pwr {
#include "third_party/stm32cubeg4/stm32g4xx_ll_pwr.h"
}  // namespace pwr

namespace rcc {
#include "third_party/stm32cubeg4/stm32g4xx_ll_rcc.h"
}  // namespace rcc

namespace stm32g474 {
namespace drivers {

void Rcc::SetupClocks() {
  // TODO(blakely): Make this more general when needed.

  // TODO(blakely): This isn't technically relatd to RCC, but it's still
  // important to do early.
  pwr::LL_PWR_DisableUCPDDeadBattery();

  bus::LL_APB1_GRP1_EnableClock(LL_APB1_GRP1_PERIPH_PWR);
  bus::LL_APB2_GRP1_EnableClock(LL_APB2_GRP1_PERIPH_SYSCFG);

  // Allow for bumping the core voltage by 80mV during high frequency operation.
  pwr::LL_PWR_EnableRange1BoostMode();

  // Configure HSE
  rcc::LL_RCC_HSE_Enable();
  while (!rcc::LL_RCC_HSE_IsReady()) {
    asm("nop");
  }

  // Don't use HSI
  rcc::LL_RCC_HSI_Disable();

  // Configure PLL
  rcc::LL_RCC_PLL_Disable();
  while (rcc::LL_RCC_PLL_IsReady()) {
    asm("nop");
  }
  rcc::LL_RCC_PLL_SetMainSource(LL_RCC_PLLSOURCE_HSE);
  rcc::LL_RCC_PLL_ConfigDomain_SYS(LL_RCC_PLLSOURCE_HSE, LL_RCC_PLLM_DIV_6, 85,
                                   LL_RCC_PLLR_DIV_2);
  rcc::LL_RCC_PLL_Enable();
  while (!rcc::LL_RCC_PLL_IsReady()) {
    asm("nop");
  }
  rcc::LL_RCC_PLL_EnableDomain_SYS();

  // Set the system clock source to HSE. However, we can't ramp directly from
  // the 16MHz HSI directly to 170MHz. Have to enter a few intermediate states
  // first:

  // 1) Set AHB prescalar div to 2 (=8Mhz)
  rcc::LL_RCC_SetAHBPrescaler(LL_RCC_SYSCLK_DIV_2);

  // 2) Lower the peripheral clocks all the way down so they don't freak out
  //    during transition.
  rcc::LL_RCC_SetAPB1Prescaler(LL_RCC_APB1_DIV_16);
  rcc::LL_RCC_SetAPB2Prescaler(LL_RCC_APB2_DIV_16);

  // 3) Set Clock source to PLL (170/2=85Mhz)
  rcc::LL_RCC_SetSysClkSource(LL_RCC_SYS_CLKSOURCE_PLL);

  // 4) Wait for sysclksource to change
  while (rcc::LL_RCC_GetSysClkSource() != LL_RCC_SYS_CLKSOURCE_STATUS_PLL) {
    asm("nop");
  }

  // 5) Modify the number of flash wait states according to the new SysClock.
  Flash::UpdateWaitStates(GetSysClockFrequency());

  // 6) Wait a microsecond
  SysTickTimer::UpdatePeriod();
  SysTickTimer::BlockingWait(1);

  // 7) Set AHB prescalar div to 1 (=170Mhz) (done below)
  rcc::LL_RCC_SetAHBPrescaler(LL_RCC_SYSCLK_DIV_1);

  // Configure peripheral clocks back to where they're supposed to be.
  rcc::LL_RCC_SetAPB1Prescaler(LL_RCC_APB1_DIV_1);
  rcc::LL_RCC_SetAPB2Prescaler(LL_RCC_APB2_DIV_1);

  // TODO(blakely): move into their respective drivers
  // Peripheral clock configuration
  rcc::LL_RCC_SetLPUARTClockSource(LL_RCC_LPUART1_CLKSOURCE_PCLK1);
  rcc::LL_RCC_SetADCClockSource(LL_RCC_ADC12_CLKSOURCE_SYSCLK);
  rcc::LL_RCC_SetADCClockSource(LL_RCC_ADC345_CLKSOURCE_SYSCLK);
}

uint32_t Rcc::GetSysClockFrequency() {
  switch (rcc::LL_RCC_GetSysClkSource()) {
    case LL_RCC_SYS_CLKSOURCE_STATUS_HSI:
      return HSI_VALUE;
      break;
    case LL_RCC_SYS_CLKSOURCE_STATUS_HSE:
      // Hardcoded
      return 24'000'000U;
      break;
    case LL_RCC_SYS_CLKSOURCE_STATUS_PLL:
    default:
      return __LL_RCC_CALC_PLLCLK_FREQ(
          kHSEOscillatorSpeed, rcc::LL_RCC_PLL_GetDivider(),
          rcc::LL_RCC_PLL_GetN(), rcc::LL_RCC_PLL_GetR());
  }
}

uint32_t Rcc::GetHClockFrequency() {
  const auto sysclock_freq = GetSysClockFrequency();
  const auto ahb_prescalar = rcc::LL_RCC_GetAHBPrescaler();
  return __LL_RCC_CALC_HCLK_FREQ(sysclock_freq, ahb_prescalar);
}

}  // namespace drivers
}  // namespace stm32g474
