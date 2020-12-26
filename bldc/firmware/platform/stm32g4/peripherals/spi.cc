#include "bldc/firmware/platform/stm32g4/peripherals/spi.h"

namespace platform {
namespace stm32g4 {

Spi::Spi(Gpio::Pin chip_select, Gpio::Pin clock, Gpio::Pin mosi, Gpio::Pin miso)
    : cs_(chip_select), clk_(clock), mosi_(mosi), miso_(miso) {}

void Spi::Init(Instance instance) {
  Gpio::AlternateFunction af;
  // TODO(blakely): This doesn't map directly, since SPI2/3 are also on AF5 :(
  switch (instance) {
    case Instance::Spi3:
      af = Gpio::AlternateFunction::AF6;
      break;
  }
  cs_.Configure(Gpio::OutputMode::PushPull, Gpio::Pullup::None, af);
  clk_.Configure(Gpio::OutputMode::PushPull, Gpio::Pullup::None, af);
  mosi_.Configure(Gpio::OutputMode::PushPull, Gpio::Pullup::None, af);
  miso_.Configure(Gpio::OutputMode::PushPull, Gpio::Pullup::None, af);
}  // namespace stm32g4

}  // namespace stm32g4
}  // namespace platform