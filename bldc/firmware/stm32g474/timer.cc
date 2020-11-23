#include "bldc/firmware/stm32g474/timer.h"

#include "bldc/firmware/stm32g474/drivers/nvic.h"
#include "bldc/firmware/stm32g474/drivers/rcc.h"

namespace cortex {
// Needed for vendor-specific definitions, otherwise we'd include cortex_m4.h
// directly. :/
#include "third_party/stm32cubeg4/stm32g4xx.h"
}  // namespace cortex

namespace stm32g474 {

using drivers::Nvic;
using drivers::Rcc;

uint32_t SysTickTimer::period_micros_ = 1000;
uint32_t SysTickTimer::tick_count_ = 0;

void SysTickTimer::SetPeriod(uint32_t micros) {
  period_micros_ = micros;
  UpdatePeriod();
}

void SysTickTimer::UpdatePeriod() {
  // TODO(blakely): Determine if we need to disable interrupts here.
  // Nvic::SetInterrupt(drivers::CortexInterrupt::ISysTick, 2, 0,
  //                    [] { SysTickHandler(); });
  Nvic::SetInterrupt(drivers::CortexInterrupt::ISysTick, 2, 0,
                     sys_tick_handler_);
  const uint32_t core_clock_freq = Rcc::GetHClockFrequency();
  cortex::SysTick_Config((core_clock_freq * period_micros_) / 1'000'000U);
  ResetCount();
}

void SysTickTimer::ResetCount() { tick_count_ = 0; }

void SysTickTimer::SysTickHandler() {
  ++tick_count_;  //
}

void SysTickTimer::BlockingWait(uint32_t micros) {
  ResetCount();
  while (tick_count_ * period_micros_ < micros) {
    asm("nop");
  }
}

}  // namespace stm32g474