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

  void EnableRxFIFO0Interrupt();

  void ClearRX0Interrupt();

  inline uint8_t TxPut() { return read_TXFQS().get_TFQPI(); }
  inline uint8_t TxGet() { return read_TXFQS().get_TFGI(); }

  inline uint8_t Rx0Get() { return read_RXF0S().get_F0GI(); }
  inline uint8_t Rx0Put() { return read_RXF0S().get_F0PI(); }
  inline void Rx0Ack(uint8_t idx) {
    update_RXF0A([&idx](RXF0A_value_t v) { return v.with_F0AI(1 << idx); });
  }

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
