#ifndef BLDC_FIRMWARE_PLATFORM_STM32G4_PERIPHERALS_CAN_FDCAN_H_
#define BLDC_FIRMWARE_PLATFORM_STM32G4_PERIPHERALS_CAN_FDCAN_H_

namespace platform {
namespace stm32g4 {

namespace impl {

static constexpr uint32_t kMRAMAddress = 0x4000'A400U;
static constexpr uint32_t kMRAMBankSize = 0x350U /* 212*4=848 bytes */;

struct Fdcan {
#define ETL_BFF_DEFINITION_FILE \
  "bldc/firmware/platform/stm32g4/peripherals/can/fdcan.inl"
#include "third_party/etl/biffield/generate.h"
#undef ETL_BFF_DEFINITION_FILE

  void InitMode();
  void EnableQueueMode();
  void EnableLoopbackMode();
  void Start();

  void Transmit();

  // TODO(blakely): Actually make these configurable?
  void Initialize();
  void SetBitTiming();
  void SetClockDivider();

  uint8_t TxPut();
  uint8_t TxGet();

 private:
  using CCCR = CCCR_value_t;
  using CKDIV = CKDIV_value_t;
  using NBTP = NBTP_value_t;
  using TEST = TEST_value_t;
  using TXBC = TXBC_value_t;
};

}  // namespace impl

}  // namespace stm32g4
}  // namespace platform

#endif  // BLDC_FIRMWARE_PLATFORM_STM32G4_PERIPHERALS_CAN_FDCAN_H_
