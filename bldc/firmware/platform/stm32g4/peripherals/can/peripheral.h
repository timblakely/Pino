#ifndef BLDC_FIRMWARE_PLATFORM_STM32G4_PERIPHERALS_CAN_PERIPHERAL_H_
#define BLDC_FIRMWARE_PLATFORM_STM32G4_PERIPHERALS_CAN_PERIPHERAL_H_

namespace platform {
namespace stm32g4 {

namespace can {

static constexpr uint32_t kMRAMAddress = 0x4000'A400U;
static constexpr uint32_t kMRAMBankSize = 0x350U /* 212*4=848 bytes */;

struct Peripheral {
  Peripheral() = delete;
  Peripheral(Peripheral&) = delete;
  Peripheral(Peripheral&&) = delete;
#define ETL_BFF_DEFINITION_FILE \
  "bldc/firmware/platform/stm32g4/peripherals/can/fdcan_memory.inl"
#include "third_party/etl/biffield/generate.h"
#undef ETL_BFF_DEFINITION_FILE

  void InitMode();
  void EnableQueueMode();
  void EnableLoopbackMode();
  void Start();

  // TODO(blakely): Actually make these configurable?
  void Initialize();
  void SetBitTiming();
  void SetClockDivider();

  void TransmitBuffer(uint8_t idx);

  uint8_t TxPut();
  uint8_t TxGet();

 private:
  using CCCR = CCCR_value_t;
  using CKDIV = CKDIV_value_t;
  using DBTP = DBTP_value_t;
  using NBTP = NBTP_value_t;
  using TEST = TEST_value_t;
  using TXBAR = TXBAR_value_t;
  using TXBC = TXBC_value_t;
};

}  // namespace can

}  // namespace stm32g4
}  // namespace platform

#endif  // BLDC_FIRMWARE_PLATFORM_STM32G4_PERIPHERALS_CAN_PERIPHERAL_H_