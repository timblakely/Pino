#include "bldc/firmware/stm32g474/drivers/gpio.h"

#include "bldc/firmware/stm32g474/drivers/gpio_ll.h"
#include "bldc/firmware/stm32g474/drivers/rcc.h"
#include "third_party/mapbox/eternal/eternal.hpp"

namespace stm32g474 {
namespace drivers {

void Gpio::ConfigurePin(GpioPort port, uint32_t pin, GpioMode mode,
                        GpioPullup pullup) {
  Rcc::Enable(port);
  const auto ll_port = reinterpret_cast<GPIO_TypeDef*>(kLLPortMap.at(port));
  const auto ll_pin = kLLPinMap.at(pin);
  gpio::LL_GPIO_SetPinMode(ll_port, ll_pin, 123);
}

}  // namespace drivers
}  // namespace stm32g474