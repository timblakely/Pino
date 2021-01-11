#ifndef BLDC_FIRMWARE_PLATFORM_STM32G4_PERIPHERALS_CAN_H_
#define BLDC_FIRMWARE_PLATFORM_STM32G4_PERIPHERALS_CAN_H_

namespace platform {
namespace stm32g4 {

struct DBTP {
  enum class TransceiverDelayCompensation : bool {
    Disable = 0,
    Enable = 1,
  };
  uint8_t DSJW : 4;
  uint8_t DTSEG2 : 4;
  uint8_t DTSEG1 : 5;
  unsigned : 3;  // Reserved
  uint8_t DBRP : 5;
  unsigned : 2;  // Reserved
  TransceiverDelayCompensation TDC : 1;
};

class Can {
 public:
  Can();
  void Init();
};

}  // namespace stm32g4
}  // namespace platform

#endif  // BLDC_FIRMWARE_PLATFORM_STM32G4_PERIPHERALS_CAN_H_
