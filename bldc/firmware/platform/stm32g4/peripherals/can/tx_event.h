#ifndef BLDC_FIRMWARE_PLATFORM_STM32G4_PERIPHERALS_CAN_TX_EVENT_MEMORY_H_
#define BLDC_FIRMWARE_PLATFORM_STM32G4_PERIPHERALS_CAN_TX_EVENT_MEMORY_H_

namespace platform {
namespace stm32g4 {

namespace can {

struct TxEvent {
#define ETL_BFF_DEFINITION_FILE \
  "bldc/firmware/platform/stm32g4/peripherals/can/tx_event_memory.inl"
#include "third_party/etl/biffield/generate.h"
#undef ETL_BFF_DEFINITION_FILE
};

}  // namespace can

}  // namespace stm32g4
}  // namespace platform

#endif // BLDC_FIRMWARE_PLATFORM_STM32G4_PERIPHERALS_CAN_TX_EVENT_MEMORY_H_
