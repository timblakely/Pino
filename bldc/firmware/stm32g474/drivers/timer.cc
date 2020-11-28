#include "bldc/firmware/stm32g474/drivers/timer.h"

namespace stm32g474 {
namespace drivers {

uint32_t SysTickTimer::period_micros_ = 1000;
uint32_t SysTickTimer::tick_count_ = 0;

void SysTickTimer::SetPeriod(uint32_t micros) {
  period_micros_ = micros;
  UpdatePeriod();
}

void SysTickTimer::UpdatePeriod() {
  // TODO(blakely): Determine if we need to disable interrupts here.
  Nvic::SetInterrupt(drivers::CortexInterrupt::ISysTick, 2, 0,
                     [] { SysTickHandler(); });
  const uint32_t core_clock_freq = Rcc::GetHClockFrequency();
  cortex::SysTick_Config((core_clock_freq / 1'000'000U) * period_micros_);
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

}  // namespace drivers
}  // namespace stm32g474