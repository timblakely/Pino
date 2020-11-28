#ifndef BLDC_FIRMWARE_STM32G474_DRIVERS_TIMER_H_
#define BLDC_FIRMWARE_STM32G474_DRIVERS_TIMER_H_

namespace stm32g474 {
namespace drivers {

enum class AdvancedTimer {
  Tim1,
  Tim8,
  Tim20,
};

enum class GeneralTimer {
  // 16 or 32 bit
  Tim2,
  Tim3,
  Tim4,
  Tim5,

  // 16 bit, but with center-aligned pwm
  Tim15,
  Tim16,
  Tim17,
};

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

}  // namespace drivers
}  // namespace stm32g474
#endif  // BLDC_FIRMWARE_STM32G474_DRIVERS_TIMER_H_
