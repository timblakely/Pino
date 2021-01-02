#ifndef BLDC_FIRMWARE_PLATFORM_MA702_MA702_H_
#define BLDC_FIRMWARE_PLATFORM_MA702_MA702_H_

#include "bldc/firmware/platform/stm32g4/peripherals/spi.h"

namespace platform {
namespace ma702 {

class Ma702 {
 public:
  enum class Register : uint8_t {
    ZLow = 0x0,
    ZHigh = 0x1,
    BiasCurrentTrimming = 0x2,
    EnableTrimming = 0x3,
    AbzConfig1 = 0x4,
    AbzConfig2 = 0x5,
    MagFieldThreshold = 0x6,
    RotationDirection = 0x9,
    MagFieldStatus = 0x1B,
  };

  explicit Ma702(stm32g4::Spi* spi);

  void Init();

  uint16_t BlockingReadRegister(Register reg);
  uint16_t Update();
  uint16_t Angle() { return angle_; }

 private:
  stm32g4::Spi* spi_;
  constexpr static uint16_t kReadAngle = (0b000 << 13);
  constexpr static uint16_t kReadRegister = (0b010 << 13);
  constexpr static uint16_t kWriteRegister = (0b100 << 13);
  uint16_t angle_ = 0;
};

}  // namespace ma702
}  // namespace platform

#endif  // BLDC_FIRMWARE_PLATFORM_MA702_MA702_H_
