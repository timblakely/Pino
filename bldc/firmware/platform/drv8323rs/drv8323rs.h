#ifndef BLDC_FIRMWARE_PLATFORM_DRV8323RS_DRV8323RS_H_
#define BLDC_FIRMWARE_PLATFORM_DRV8323RS_DRV8323RS_H_

#include "bldc/firmware/platform/stm32g4/peripherals/gpio.h"
#include "bldc/firmware/platform/stm32g4/peripherals/spi.h"

namespace platform {
namespace drv8323rs {

class Drv {
 public:
  enum class Register : uint8_t {
    FaultStatus1 = 0,
    FaultStatus2 = 1,
    DriverControl = 2,
    GateDriveHigh = 3,
    GateDriveLow = 4,
    OverCurrentControl = 5,
    CurrentSenseAmpControl = 6,
  };

  explicit Drv(stm32g4::Gpio::Pin enable, stm32g4::Spi* spi);

  void Init();

  uint16_t BlockingReadRegister(Register reg);

  void Enable();
  void Disable();

 private:
  stm32g4::Gpio::Pin enable_;
  stm32g4::Spi* spi_;
  constexpr static uint16_t kReadMask = (1U << 15);
  constexpr static uint16_t kWriteMask = (0U << 15);
};

}  // namespace drv8323rs
}  // namespace platform

#endif  // BLDC_FIRMWARE_PLATFORM_DRV8323RS_DRV8323RS_H_
