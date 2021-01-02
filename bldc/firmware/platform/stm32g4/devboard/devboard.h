#ifndef BLDC_FIRMWARE_PLATFORM_STM32G4_DEVBOARD_DEVBOARD_H_
#define BLDC_FIRMWARE_PLATFORM_STM32G4_DEVBOARD_DEVBOARD_H_

#include "bldc/firmware/platform/drv8323rs/drv8323rs.h"
#include "bldc/firmware/platform/stm32g4/g4_platform.h"
#include "bldc/firmware/platform/stm32g4/peripherals/spi.h"
#include "bldc/firmware/stm32g474/led.h"

namespace platform {
namespace stm32g4 {

class Devboard : public G4Platform {
 public:
  Devboard();
  virtual void Init() override;

 protected:
 private:
  void OnFatal();
  Led* red_;
  Led* green_;
  Led* blue_;

  Spi spi1_;
  Ma702 ma702_;
  Spi spi3_;
  drv8323rs::Drv drv_;
};

}  // namespace stm32g4
}  // namespace platform
#endif  // BLDC_FIRMWARE_PLATFORM_STM32G4_DEVBOARD_DEVBOARD_H_
