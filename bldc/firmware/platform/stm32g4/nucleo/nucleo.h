#ifndef BLDC_FIRMWARE_PLATFORM_STM32G4_NUCLEO_NUCLEO_H_
#define BLDC_FIRMWARE_PLATFORM_STM32G4_NUCLEO_NUCLEO_H_

#include "bldc/firmware/platform/stm32g4/g4_platform.h"
#include "bldc/firmware/stm32g474/led.h"

namespace platform {
namespace stm32g4 {

class Nucleo : public G4Platform {
 public:
  Nucleo();
  virtual void Init() override;

 private:
  void OnFatal();
  Led* user_led_;
};

}  // namespace stm32g4
}  // namespace platform
#endif  // BLDC_FIRMWARE_PLATFORM_STM32G4_NUCLEO_NUCLEO_H_
