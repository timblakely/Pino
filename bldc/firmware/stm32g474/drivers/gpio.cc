// Needed for forward declaration of typedef.
// clang-format off
#include "third_party/stm32cubeg4/stm32g4xx_ll_gpio.h"
#include "bldc/firmware/stm32g474/drivers/gpio.h"
// clang-format on

#include "bldc/firmware/stm32g474/drivers/rcc.h"

namespace stm32g474 {
namespace drivers {

GPIO_TypeDef* GetLLPort(Gpio::Port port) {
  switch (port) {
    case Gpio::Port::A:
    default:
      return GPIOA;
    case Gpio::Port::B:
      return GPIOB;
    case Gpio::Port::C:
      return GPIOC;
    case Gpio::Port::D:
      return GPIOD;
    case Gpio::Port::E:
      return GPIOE;
  }
}

constexpr uint32_t GetLLAlternateFunction(Gpio::AlternateFunction af) {
  return static_cast<uint32_t>(af);
}

void Gpio::ConfigureOutputPin(Port port, uint32_t pin, Pullup pullup,
                              OutputMode mode) {
  Rcc::Enable(port);

  auto ll_port = GetLLPort(port);
  // This is somewhat of a hack; LL_GPIO_PIN_n is simply LL_GPIO_BSRR, which in
  // turn is just 0b1 left shifted by n
  const uint32_t ll_pin = 0b1 << pin;
  LL_GPIO_SetPinMode(ll_port, ll_pin, LL_GPIO_MODE_OUTPUT);
  SetPullup(port, pin, pullup);
  if (mode == OutputMode::PushPull) {
    LL_GPIO_SetPinOutputType(ll_port, ll_pin, LL_GPIO_OUTPUT_PUSHPULL);
  } else {
    LL_GPIO_SetPinOutputType(ll_port, ll_pin, LL_GPIO_OUTPUT_OPENDRAIN);
  }
}

void Gpio::SetPullup(Port port, uint32_t pin, Pullup pullup) {
  Rcc::Enable(port);
  auto ll_port = GetLLPort(port);
  const uint32_t ll_pin = 0b1 << pin;
  switch (pullup) {
    case Pullup::PullUp:
      LL_GPIO_SetPinPull(ll_port, ll_pin, LL_GPIO_PULL_UP);
      break;
    case Pullup::PullDown:
      LL_GPIO_SetPinPull(ll_port, ll_pin, LL_GPIO_PULL_DOWN);
      break;
    case Pullup::None:
      LL_GPIO_SetPinPull(ll_port, ll_pin, LL_GPIO_PULL_NO);
      break;
  }
}

void Gpio::SetOutputPin(Port port, uint32_t pin) {
  LL_GPIO_SetOutputPin(GetLLPort(port), 0b1 << pin);
}

void Gpio::ClearOutputPin(Port port, uint32_t pin) {
  LL_GPIO_ResetOutputPin(GetLLPort(port), 0b1 << pin);
}

void Gpio::ConfigurePeripheralPin(Port port, uint8_t pin, Pullup pullup,
                                  AlternateFunction alternate_function) {
  auto ll_port = GetLLPort(port);
  const uint32_t ll_pin = 0b1 << pin;
  SetPullup(port, pin, pullup);
  LL_GPIO_SetPinMode(ll_port, ll_pin, LL_GPIO_MODE_ALTERNATE);
  auto ll_af = GetLLAlternateFunction(alternate_function);
  if (pin < 8) {
    LL_GPIO_SetAFPin_0_7(ll_port, ll_pin, ll_af);
  } else {
    LL_GPIO_SetAFPin_8_15(ll_port, ll_pin, ll_af);
  }
}

}  // namespace drivers
}  // namespace stm32g474