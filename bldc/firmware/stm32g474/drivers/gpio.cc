#include "bldc/firmware/stm32g474/drivers/gpio.h"

#include "bldc/firmware/stm32g474/drivers/rcc.h"

namespace gpio {
#include "third_party/stm32cubeg4/stm32g4xx_ll_gpio.h"
}  // namespace gpio

namespace stm32g474 {
namespace drivers {

void Gpio::ConfigurePin(GpioPort port, uint8_t pin, GpioMode mode,
                        GpioPullup pullup) {
  Rcc::Enable(port);
}

}  // namespace drivers
}  // namespace stm32g474