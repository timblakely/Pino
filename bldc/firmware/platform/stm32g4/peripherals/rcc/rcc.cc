#include "bldc/firmware/platform/stm32g4/peripherals/rcc/rcc.h"

#include "bldc/firmware/platform/stm32g4/peripherals/flash.h"
#include "bldc/firmware/platform/stm32g4/peripherals/systick/systick.h"
#include "third_party/stm32cubeg4/stm32g474xx.h"
#include "third_party/stm32cubeg4/stm32g4xx_ll_bus.h"
#include "third_party/stm32cubeg4/stm32g4xx_ll_pwr.h"
#include "third_party/stm32cubeg4/stm32g4xx_ll_rcc.h"

namespace platform {
namespace stm32g4 {

rcc::Peripheral* const Rcc::peripheral_ =
    reinterpret_cast<rcc::Peripheral*>(rcc::kRccInstance);

void Rcc::SetupClocks() {
  // TODO(blakely): Make this more general when needed.

  // TODO(blakely): This isn't technically relatd to RCC, but it's still
  // important to do early.
  LL_PWR_DisableUCPDDeadBattery();

  LL_APB1_GRP1_EnableClock(LL_APB1_GRP1_PERIPH_PWR);
  LL_APB2_GRP1_EnableClock(LL_APB2_GRP1_PERIPH_SYSCFG);

  // Allow for bumping the core voltage by 80mV during high frequency
  // operation.
  LL_PWR_EnableRange1BoostMode();

  // Configure HSE
  LL_RCC_HSE_Enable();
  while (!LL_RCC_HSE_IsReady()) {
    asm("nop");
  }

  // Don't use HSI
  LL_RCC_HSI_Disable();

  // Configure PLL
  LL_RCC_PLL_Disable();
  while (LL_RCC_PLL_IsReady()) {
    asm("nop");
  }
  LL_RCC_PLL_SetMainSource(LL_RCC_PLLSOURCE_HSE);
  LL_RCC_PLL_ConfigDomain_SYS(LL_RCC_PLLSOURCE_HSE, LL_RCC_PLLM_DIV_6, 85,
                              LL_RCC_PLLR_DIV_2);
  LL_RCC_PLL_Enable();
  while (!LL_RCC_PLL_IsReady()) {
    asm("nop");
  }
  LL_RCC_PLL_EnableDomain_SYS();

  // Set the system clock source to HSE. However, we can't ramp directly from
  // the 16MHz HSI directly to 170MHz. Have to enter a few intermediate states
  // first:

  // 1) Set AHB prescalar div to 2 (=8Mhz)
  LL_RCC_SetAHBPrescaler(LL_RCC_SYSCLK_DIV_2);

  // 2) Lower the peripheral clocks all the way down so they don't freak out
  //    during transition.
  LL_RCC_SetAPB1Prescaler(LL_RCC_APB1_DIV_16);
  LL_RCC_SetAPB2Prescaler(LL_RCC_APB2_DIV_16);

  // 3) Set Clock source to PLL (170/2=85Mhz)
  LL_RCC_SetSysClkSource(LL_RCC_SYS_CLKSOURCE_PLL);

  // 4) Wait for sysclksource to change
  while (LL_RCC_GetSysClkSource() != LL_RCC_SYS_CLKSOURCE_STATUS_PLL) {
    asm("nop");
  }

  // 5) Modify the number of flash wait states according to the new SysClock.
  Flash::UpdateWaitStates(GetSysClockFrequency());

  // 6) Make sure the systick is updated, then wait a microsecond
  SysTickTimer::UpdatePeriod();
  SysTickTimer::BlockingWait(1);

  // 7) Set AHB prescalar div to 1 (=170Mhz) (done below)
  LL_RCC_SetAHBPrescaler(LL_RCC_SYSCLK_DIV_1);

  // Reset system clock again to match new divider.
  SysTickTimer::UpdatePeriod();

  // Configure peripheral clocks back to where they're supposed to be.
  LL_RCC_SetAPB1Prescaler(LL_RCC_APB1_DIV_1);
  LL_RCC_SetAPB2Prescaler(LL_RCC_APB2_DIV_1);

  // TODO(blakely): move into their respective drivers
  // Peripheral clock configuration
  LL_RCC_SetLPUARTClockSource(LL_RCC_LPUART1_CLKSOURCE_PCLK1);
  LL_RCC_SetADCClockSource(LL_RCC_ADC12_CLKSOURCE_SYSCLK);
  LL_RCC_SetADCClockSource(LL_RCC_ADC345_CLKSOURCE_SYSCLK);
}

uint32_t Rcc::GetSysClockFrequency() {
  switch (LL_RCC_GetSysClkSource()) {
    case LL_RCC_SYS_CLKSOURCE_STATUS_HSI:
      return HSI_VALUE;
      break;
    case LL_RCC_SYS_CLKSOURCE_STATUS_HSE:
      // Hardcoded
      return 24'000'000U;
      break;
    case LL_RCC_SYS_CLKSOURCE_STATUS_PLL:
    default:
      return __LL_RCC_CALC_PLLCLK_FREQ(kHSEOscillatorSpeed,
                                       LL_RCC_PLL_GetDivider(),
                                       LL_RCC_PLL_GetN(), LL_RCC_PLL_GetR());
  }
}

uint32_t Rcc::GetHClockFrequency() {
  const auto sysclock_freq = GetSysClockFrequency();
  const auto ahb_prescalar = LL_RCC_GetAHBPrescaler();
  return __LL_RCC_CALC_HCLK_FREQ(sysclock_freq, ahb_prescalar);
}

void Rcc::Enable(Gpio::Port port) {
  switch (port) {
    case Gpio::Port::A:
      return LL_AHB2_GRP1_EnableClock(LL_AHB2_GRP1_PERIPH_GPIOA);
    case Gpio::Port::B:
      return LL_AHB2_GRP1_EnableClock(LL_AHB2_GRP1_PERIPH_GPIOB);
    case Gpio::Port::C:
      return LL_AHB2_GRP1_EnableClock(LL_AHB2_GRP1_PERIPH_GPIOC);
    case Gpio::Port::D:
      return LL_AHB2_GRP1_EnableClock(LL_AHB2_GRP1_PERIPH_GPIOD);
    case Gpio::Port::E:
      return LL_AHB2_GRP1_EnableClock(LL_AHB2_GRP1_PERIPH_GPIOE);
  }
}

void Rcc::EnableClock(timer::Instance instance, bool enable) {
  switch (instance) {
    case timer::Instance::Tim3:
      return peripheral_->EnableTim3(enable);
    case timer::Instance::Tim4:
      return peripheral_->EnableTim4(enable);
    case timer::Instance::Tim5:
      return peripheral_->EnableTim5(enable);
    default:
      return;
  }
}

}  // namespace stm32g4
}  // namespace platform
