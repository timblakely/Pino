#ifndef BLDC_FIRMWARE_PLATFORM_STM32G4_PERIPHERALS_SYSTICK_SYSTICK_H_
#define BLDC_FIRMWARE_PLATFORM_STM32G4_PERIPHERALS_SYSTICK_SYSTICK_H_
namespace platform {
namespace stm32g4 {

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

}  // namespace stm32g4
}  // namespace platform
#endif  // BLDC_FIRMWARE_PLATFORM_STM32G4_PERIPHERALS_SYSTICK_SYSTICK_H_
