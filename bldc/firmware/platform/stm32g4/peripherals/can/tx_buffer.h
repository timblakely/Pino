#ifndef BLDC_FIRMWARE_PLATFORM_STM32G4_PERIPHERALS_CAN_TX_BUFFER_MEMORY_H_
#define BLDC_FIRMWARE_PLATFORM_STM32G4_PERIPHERALS_CAN_TX_BUFFER_MEMORY_H_

#include <array>

namespace platform {
namespace stm32g4 {

namespace can {

struct TxHeader {
#define ETL_BFF_DEFINITION_FILE \
  "bldc/firmware/platform/stm32g4/peripherals/can/tx_buffer_memory.inl"
#include "third_party/etl/biffield/generate.h"
#undef ETL_BFF_DEFINITION_FILE
 protected:
  using T0 = T0_value_t;
  using T1 = T1_value_t;
  using FrameSize = T1::DLC_t;
};

struct TxBuffer {
  TxHeader header_;
  uint32_t data_[16];
};

}  // namespace can

}  // namespace stm32g4
}  // namespace platform

#endif  // BLDC_FIRMWARE_PLATFORM_STM32G4_PERIPHERALS_CAN_TX_BUFFER_MEMORY_H_
