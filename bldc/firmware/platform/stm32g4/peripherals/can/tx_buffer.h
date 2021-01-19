#ifndef BLDC_FIRMWARE_PLATFORM_STM32G4_PERIPHERALS_CAN_TX_BUFFER_MEMORY_H_
#define BLDC_FIRMWARE_PLATFORM_STM32G4_PERIPHERALS_CAN_TX_BUFFER_MEMORY_H_

namespace platform {
namespace stm32g4 {

namespace impl {

struct TxBuffer {
#define ETL_BFF_DEFINITION_FILE \
  "bldc/firmware/platform/stm32g4/peripherals/can/tx_buffer_memory.inl"
#include "third_party/etl/biffield/generate.h"
#undef ETL_BFF_DEFINITION_FILE

 private:
  using T0 = T0_value_t;
  using T1 = T1_value_t;

 public:
  using FrameSize = T1::DLC_t;
  uint32_t data_[16];

  // TODO(blakely): templatize
  void WriteStandardDataFrame(uint8_t id, uint8_t* data, FrameSize size);
};

}  // namespace impl

}  // namespace stm32g4
}  // namespace platform

#endif  // BLDC_FIRMWARE_PLATFORM_STM32G4_PERIPHERALS_CAN_TX_BUFFER_MEMORY_H_
