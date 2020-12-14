#ifndef BLDC_FIRMWARE_STM32G474_DRIVERS_TIMER_H_
#define BLDC_FIRMWARE_STM32G474_DRIVERS_TIMER_H_

namespace platform {
namespace stm32g4 {

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

enum class CountMode {
  Up,
  Down,
  Centered,
};

// Capable of interacting with digital hall effect sensors on CH1-3.
enum class AdvancedTimer {
  Tim1,
  Tim8,
  Tim20,
};

enum class GenericTimer {

};

class AdvancedTimerImpl {
 public:
  enum class CountMode {
    Up,
  };
  AdvancedTimerImpl(AdvancedTimer timer);

  void SetPrescalar(uint32_t prescalar);
  void SetCountMode(CountMode mode);

 private:
  AdvancedTimer timer_instance_;
};

class Tim2 {
 public:
  void Enable();
  void Configure();
  void Start();
  void EnableOutputChannel();
};

class Tim3 {
 public:
  Tim3();

  enum class Channel {
    CH1,
    CH2,
    CH3,
    CH4,
  };
  void Enable();
  void Configure();
  void Start();
  void EnableOutputChannel();
};

//
enum class TimerInstance {
  Tim2,
  Tim3,
  Tim4,
};

class Timer {
 public:
  Timer(TimerInstance instance);
  void Enable();
  void Configure();
  void Start();
  void EnableOutput();

 private:
  TimerInstance instance_;
  // Workaround for the STM libraries using typedef'd anonymous structs.
  struct TIM_TypeDefI;
  TIM_TypeDefI* timer_;
  uint32_t prescalar_;
  uint32_t period_;
};

}  // namespace stm32g4
}  // namespace platform
#endif  // BLDC_FIRMWARE_STM32G474_DRIVERS_TIMER_H_
