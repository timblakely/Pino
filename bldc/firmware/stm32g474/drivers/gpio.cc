// Needed for forward declaration of typedef.
// clang-format off
#include "third_party/stm32cubeg4/stm32g4xx_ll_gpio.h"
#include "bldc/firmware/stm32g474/drivers/gpio.h"
// clang-format on

#include "bldc/firmware/stm32g474/drivers/rcc.h"
#include "pstd/constexpr_map.h"

namespace stm32g474 {
namespace drivers {

// Getting around the anonymous struct issue.
struct Gpio::Pin::GPIO_TypeDefI : GPIO_TypeDef {};

Gpio::Pin::Pin(Port port, uint32_t pin)
    : port_(port), pin_(pin), ll_pin_(1U << pin) {
  constexpr static const auto port_map =
      pstd::ConstexprMap<Port, std::intptr_t>({
          {Port::A, GPIOA_BASE},
          {Port::B, GPIOB_BASE},
          {Port::C, GPIOC_BASE},
          {Port::D, GPIOD_BASE},
          {Port::E, GPIOE_BASE},
      });
  ll_port_ = reinterpret_cast<GPIO_TypeDefI*>(port_map.at(port));
}

void Gpio::Pin::Configure(OutputMode mode, Pullup pullup, Speed speed) {
  Rcc::Enable(port_);
  SetMode(mode);
  SetPullup(pullup);
  SetSpeed(speed);
  LL_GPIO_SetPinMode(ll_port_, ll_pin_, LL_GPIO_MODE_OUTPUT);
}

void Gpio::Pin::Configure(OutputMode mode, Pullup pullup, AlternateFunction af,
                          Speed speed) {
  Rcc::Enable(port_);
  SetMode(mode);
  SetPullup(pullup);
  SetSpeed(speed);
  LL_GPIO_SetPinMode(ll_port_, ll_pin_, LL_GPIO_MODE_ALTERNATE);
  if (pin_ < 8) {
    LL_GPIO_SetAFPin_0_7(ll_port_, ll_pin_, static_cast<uint32_t>(af));
  } else {
    LL_GPIO_SetAFPin_8_15(ll_port_, ll_pin_, static_cast<uint32_t>(af));
  }
}

void Gpio::Pin::SetMode(OutputMode mode) {
  switch (mode) {
    case OutputMode::OpenDrain:
      return LL_GPIO_SetPinOutputType(ll_port_, ll_pin_,
                                      LL_GPIO_OUTPUT_OPENDRAIN);
    case OutputMode::PushPull:
      return LL_GPIO_SetPinOutputType(ll_port_, ll_pin_,
                                      LL_GPIO_OUTPUT_PUSHPULL);
  }
}

void Gpio::Pin::SetPullup(Pullup pullup) {
  switch (pullup) {
    case Pullup::PullUp:
      LL_GPIO_SetPinPull(ll_port_, ll_pin_, LL_GPIO_PULL_UP);
      break;
    case Pullup::PullDown:
      LL_GPIO_SetPinPull(ll_port_, ll_pin_, LL_GPIO_PULL_DOWN);
      break;
    case Pullup::None:
      LL_GPIO_SetPinPull(ll_port_, ll_pin_, LL_GPIO_PULL_NO);
      break;
  }
}

void Gpio::Pin::SetSpeed(Speed speed) {
  switch (speed) {
    case Speed::Low:
      return LL_GPIO_SetPinSpeed(ll_port_, ll_pin_, LL_GPIO_SPEED_FREQ_LOW);
    case Speed::Medium:
      return LL_GPIO_SetPinSpeed(ll_port_, ll_pin_, LL_GPIO_SPEED_FREQ_MEDIUM);
    case Speed::High:
      return LL_GPIO_SetPinSpeed(ll_port_, ll_pin_, LL_GPIO_SPEED_FREQ_HIGH);
    case Speed::VeryHigh:
      return LL_GPIO_SetPinSpeed(ll_port_, ll_pin_,
                                 LL_GPIO_SPEED_FREQ_VERY_HIGH);
  }
}

void Gpio::Pin::High() { LL_GPIO_SetOutputPin(ll_port_, ll_pin_); }

void Gpio::Pin::Low() { LL_GPIO_ResetOutputPin(ll_port_, ll_pin_); }

}  // namespace drivers
}  // namespace stm32g474