#ifndef BLDC_FIRMWARE_STM32G474_DRIVERS_GPIO_H_
#define BLDC_FIRMWARE_STM32G474_DRIVERS_GPIO_H_

namespace stm32g474 {
namespace drivers {

class Gpio {
 public:
  enum class Port { A, B, C, D, E };
  enum class OutputMode { PushPull, OpenDrain };
  enum class Pullup { None, PullUp, PullDown };
  enum class Speed { Low, Medium, High, VeryHigh };
  enum class AlternateFunction {
    None,
    AF10 = 10,
  };

  class Pin {
   public:
    Pin(Port port, uint32_t pin);
    explicit Pin(Pin& other);
    explicit Pin(Pin&& other);
    Pin& operator=(Pin&&) = default;

    void Configure(OutputMode mode, Pullup pullup, Speed speed = Speed::Low);
    void Configure(OutputMode mode, Pullup pullup, AlternateFunction af,
                   Speed speed = Speed::Low);

    void High();
    void Low();

    void SetMode(OutputMode mode);
    void SetPullup(Pullup pullup);
    void SetSpeed(Speed speed);

   private:
    Port port_;
    uint32_t pin_;
    uint32_t ll_pin_;

    // Workaround for the STM libraries using typedef'd anonymous structs.
    struct GPIO_TypeDefI;
    GPIO_TypeDefI* ll_port_;
  };

  //   static void ConfigureInputPin(Port port, uint32_t pin, Pullup pullup);
  //   static void ConfigureOutputPin(Port port, uint32_t pin, Pullup pullup,
  //                                  OutputMode mode);
  //   static void SetPullup(Port port, uint32_t pin, Pullup pullup);
  //   static void SetOutputPin(Port port, uint32_t pin);
  //   static void ClearOutputPin(Port port, uint32_t pin);
  //   static void ConfigurePeripheralPin(Port port, uint8_t pin, Pullup pullup,
  //                                      AlternateFunction alternate_function);
};

}  // namespace drivers
}  // namespace stm32g474

#endif  // BLDC_FIRMWARE_STM32G474_DRIVERS_GPIO_H_
