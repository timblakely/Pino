#include "bldc/firmware/stm32g474/drivers/gpio.h"

#include "bldc/firmware/stm32g474/drivers/rcc.h"
#include "third_party/stm32cubeg4/stm32g4xx_ll_gpio.h"

namespace stm32g474 {
namespace drivers {

GPIO_TypeDef* GetLLPort(GpioPort port) {
  switch (port) {
    case GpioPort::A:
    default:
      return GPIOA;
    case GpioPort::B:
      return GPIOB;
    case GpioPort::C:
      return GPIOC;
    case GpioPort::D:
      return GPIOD;
    case GpioPort::E:
      return GPIOE;
  }
}

void Gpio::ConfigureOutputPin(GpioPort port, uint32_t pin, GpioPullup pullup,
                              GpioOutputMode mode) {
  Rcc::Enable(port);

  auto ll_port = GetLLPort(port);
  // This is somewhat of a hack; LL_GPIO_PIN_n is simply LL_GPIO_BSRR, which in
  // turn is just 0b1 left shifted by n
  const uint32_t ll_pin = 0b1 << pin;
  LL_GPIO_SetPinMode(ll_port, ll_pin, LL_GPIO_MODE_OUTPUT);
  switch (pullup) {
    case GpioPullup::PullUp:
      LL_GPIO_SetPinPull(ll_port, ll_pin, LL_GPIO_PULL_UP);
      break;
    case GpioPullup::PullDown:
      LL_GPIO_SetPinPull(ll_port, ll_pin, LL_GPIO_PULL_DOWN);
      break;
    case GpioPullup::None:
      LL_GPIO_SetPinPull(ll_port, ll_pin, LL_GPIO_PULL_NO);
      break;
  }
  if (mode == GpioOutputMode::PushPull) {
    LL_GPIO_SetPinOutputType(ll_port, ll_pin, LL_GPIO_OUTPUT_PUSHPULL);
  } else {
    LL_GPIO_SetPinOutputType(ll_port, ll_pin, LL_GPIO_OUTPUT_OPENDRAIN);
  }
}

void Gpio::SetOutputPin(GpioPort port, uint32_t pin) {
  LL_GPIO_SetOutputPin(GetLLPort(port), 0b1 << pin);
}

}  // namespace drivers
}  // namespace stm32g474