#ifndef BLDC_FIRMWARE_STM32G474_DRIVERS_GPIO_H_
#define BLDC_FIRMWARE_STM32G474_DRIVERS_GPIO_H_

namespace stm32g474 {
namespace drivers {

enum class GpioPort {
  A,
  B,
  C,
  D,
  E,
};

// enum class GpioMode {
//   Input,
//   Output,
//   Alternate,
//   OutputPushPull,
//   OutputOpenDrain,
//   AlternateFunctionPushPull,
//   AlternateFunctionOpenDrain,
//   Analog,
//   // InterruptRising,
//   // InterruptFalling,
//   // InterruptRisingFalling,
//   // // TODO(blakely): Event, or external?
//   // EventRising,
//   // EventFalling,
//   // EventRisingFalling,
// };

enum class GpioOutputMode {
  PushPull,
  OpenDrain,
};

enum class GpioPullup {
  None,
  PullUp,
  PullDown,
};

enum class GpioAlternateFunction {
  None,
};

class Gpio {
 public:
  static void ConfigureInputPin(GpioPort port, uint32_t pin, GpioPullup pullup);
  static void ConfigureOutputPin(GpioPort port, uint32_t pin, GpioPullup pullup,
                                 GpioOutputMode mode);
  static void SetOutputPin(GpioPort port, uint32_t pin);
  static void ClearOutputPin(GpioPort port, uint32_t pin);
  static void ConfigurePeripheralPin(GpioPort port, uint8_t pin,
                                     GpioPullup pullup,
                                     GpioAlternateFunction alternate_function);
};

}  // namespace drivers
}  // namespace stm32g474

#endif  // BLDC_FIRMWARE_STM32G474_DRIVERS_GPIO_H_
