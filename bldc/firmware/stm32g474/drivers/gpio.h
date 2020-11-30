#ifndef BLDC_FIRMWARE_STM32G474_DRIVERS_GPIO_H_
#define BLDC_FIRMWARE_STM32G474_DRIVERS_GPIO_H_

namespace stm32g474 {
namespace drivers {

class Gpio {
 public:
  enum class Port { A, B, C, D, E };
  enum class OutputMode { PushPull, OpenDrain };
  enum class Pullup { None, PullUp, PullDown };
  enum class AlternateFunction {
    None,
    AF10 = 10,
  };

  // struct Pin {
  //   Pin(Port port, Pin pin);

  // };

  static void ConfigureInputPin(Port port, uint32_t pin, Pullup pullup);
  static void ConfigureOutputPin(Port port, uint32_t pin, Pullup pullup,
                                 OutputMode mode);
  static void SetPullup(Port port, uint32_t pin, Pullup pullup);
  static void SetOutputPin(Port port, uint32_t pin);
  static void ClearOutputPin(Port port, uint32_t pin);
  static void ConfigurePeripheralPin(Port port, uint8_t pin, Pullup pullup,
                                     AlternateFunction alternate_function);
};

}  // namespace drivers
}  // namespace stm32g474

#endif  // BLDC_FIRMWARE_STM32G474_DRIVERS_GPIO_H_
