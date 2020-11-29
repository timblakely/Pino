#ifndef BLDC_FIRMWARE_STM32G474_DRIVERS_GPIO_H_
#define BLDC_FIRMWARE_STM32G474_DRIVERS_GPIO_H_

namespace stm32g474 {
namespace drivers {

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

class Gpio {
 public:
  enum class Port { A, B, C, D, E };
  enum class OutputMode { PushPull, OpenDrain };
  enum class Pullup { None, PullUp, PullDown };
  enum class AlternateFunction { None };
  
  static void ConfigureInputPin(Port port, uint32_t pin, Pullup pullup);
  static void ConfigureOutputPin(Port port, uint32_t pin, Pullup pullup,
                                 OutputMode mode);
  static void SetOutputPin(Port port, uint32_t pin);
  static void ClearOutputPin(Port port, uint32_t pin);
  static void ConfigurePeripheralPin(Port port, uint8_t pin, Pullup pullup,
                                     AlternateFunction alternate_function);
};

}  // namespace drivers
}  // namespace stm32g474

#endif  // BLDC_FIRMWARE_STM32G474_DRIVERS_GPIO_H_
