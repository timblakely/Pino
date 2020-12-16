// Needed for forward declaration of typedef.
// clang-format off
#include "third_party/stm32cubeg4/stm32g4xx_ll_gpio.h"
#include "bldc/firmware/platform/stm32g4/peripherals/gpio.h"
// clang-format on

#include "bldc/firmware/platform/stm32g4/peripherals/rcc.h"
#include "pstd/constexpr_map.h"

namespace platform {
namespace stm32g4 {

// Getting around the anonymous struct issue.
struct Gpio::Pin::GPIO_TypeDefI : GPIO_TypeDef {};

Gpio::Pin::Pin(Port port, uint32_t pin)
    : port_(port), pin_(pin), ll_pin_(1U << pin) {
  // Have to use GPIOx_BASE here, since the actual GPIOx is a reinterpret_cast,
  // which isn't allowed in constexpr.
  static const auto port_map = pstd::ConstexprMap<Port, std::intptr_t>({
      {Port::A, GPIOA_BASE},
      {Port::B, GPIOB_BASE},
      {Port::C, GPIOC_BASE},
      {Port::D, GPIOD_BASE},
      {Port::E, GPIOE_BASE},
  });
  ll_port_ = reinterpret_cast<GPIO_TypeDefI*>(port_map.at(port));
}

Gpio::Pin::Pin(Pin& other) : Pin(other.port_, other.pin_) {}

Gpio::Pin::Pin(Pin&& other) {
  port_ = other.port_;
  ll_port_ = other.ll_port_;
  pin_ = other.pin_;
  ll_pin_ = other.ll_pin_;
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
  static const auto mode_map = pstd::ConstexprMap<OutputMode, std::intptr_t>({
      {OutputMode::OpenDrain, LL_GPIO_OUTPUT_OPENDRAIN},
      {OutputMode::PushPull, LL_GPIO_OUTPUT_PUSHPULL},
  });
  LL_GPIO_SetPinOutputType(ll_port_, ll_pin_, mode_map.at(mode));
}

void Gpio::Pin::SetPullup(Pullup pullup) {
  static const auto pull_map = pstd::ConstexprMap<Pullup, uint32_t>({
      {Pullup::None, LL_GPIO_PULL_NO},
      {Pullup::PullUp, LL_GPIO_PULL_UP},
      {Pullup::PullDown, LL_GPIO_PULL_DOWN},
  });
  LL_GPIO_SetPinPull(ll_port_, ll_pin_, pull_map.at(pullup));
}

void Gpio::Pin::SetSpeed(Speed speed) {
  static const auto speed_map = pstd::ConstexprMap<Speed, uint32_t>({
      {Speed::Low, LL_GPIO_SPEED_FREQ_LOW},
      {Speed::Medium, LL_GPIO_SPEED_FREQ_MEDIUM},
      {Speed::High, LL_GPIO_SPEED_FREQ_HIGH},
      {Speed::VeryHigh, LL_GPIO_SPEED_FREQ_VERY_HIGH},
  });
  return LL_GPIO_SetPinSpeed(ll_port_, ll_pin_, speed_map.at(speed));
}

void Gpio::Pin::High() { LL_GPIO_SetOutputPin(ll_port_, ll_pin_); }

void Gpio::Pin::Low() { LL_GPIO_ResetOutputPin(ll_port_, ll_pin_); }

}  // namespace stm32g4
}  // namespace platform