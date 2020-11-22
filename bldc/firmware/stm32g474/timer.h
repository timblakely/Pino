#ifndef BLDC_FIRMWARE_STM32G474_TIMER_H_
#define BLDC_FIRMWARE_STM32G474_TIMER_H_

namespace stm32g474 {
class SysTickTimer {
 public:
  static void SetPeriod(uint32_t micros);
  // Update period, assuming the clock changed.
  static void UpdatePeriod();
  static void ResetCount();
  static void BlockingWait(uint32_t micros);

 private:
  static void SysTickHandler();
  static uint32_t period_micros_;
  static uint32_t tick_count_;
};
}  // namespace stm32g474
#endif  // BLDC_FIRMWARE_STM32G474_TIMER_H_
