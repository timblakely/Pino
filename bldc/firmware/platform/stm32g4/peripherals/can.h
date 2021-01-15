#ifndef BLDC_FIRMWARE_PLATFORM_STM32G4_PERIPHERALS_CAN_H_
#define BLDC_FIRMWARE_PLATFORM_STM32G4_PERIPHERALS_CAN_H_

#include "bldc/firmware/platform/stm32g4/peripherals/gpio.h"

namespace platform {
namespace stm32g4 {

class Can {
 public:
  enum class Instance : uint32_t {
    // Note: these are the actual addresses in memory of each peripheral.
    Fdcan1 = 0x4000'6400UL,
    Fdcan2 = 0x4000'6800UL,
    Fdcan3 = 0x4000'6C00UL,
  };

  Can(Gpio::Pin tx, Gpio::Pin rx);

  void Init(Can::Instance instance);

  void TransmitData(uint8_t* t, uint8_t size);

 private:
  Instance instance_;

  Gpio::Pin tx_;
  Gpio::Pin rx_;

  // Registers
  struct Periph {
#define ETL_BFF_DEFINITION_FILE \
  "bldc/firmware/platform/stm32g4/peripherals/can_registers.inl"
#include "third_party/etl/biffield/generate.h"
#undef ETL_BFF_DEFINITION_FILE

    uint8_t tx_put() { return read_TXFQS().get_TFQPI(); }
    uint8_t tx_get() { return read_TXFQS().get_TFGI(); }
  };
  static_assert(sizeof(Periph) == 0x104);
  Periph* can_;

  // Memory configuration

  struct StandardFilter {
#define ETL_BFF_DEFINITION_FILE \
  "bldc/firmware/platform/stm32g4/peripherals/can_standard_filter_memory.inl"
#include "third_party/etl/biffield/generate.h"
#undef ETL_BFF_DEFINITION_FILE
  };
  static_assert(sizeof(StandardFilter) == 1 * 4);
  StandardFilter* standard_filters_;
  static constexpr uint32_t kStandardFilterMemOffset = 0x0;
  static_assert(kStandardFilterMemOffset == 0x0000);

  struct ExtendedFilter {
#define ETL_BFF_DEFINITION_FILE \
  "bldc/firmware/platform/stm32g4/peripherals/can_extended_filter_memory.inl"
#include "third_party/etl/biffield/generate.h"
#undef ETL_BFF_DEFINITION_FILE
  };
  static_assert(sizeof(ExtendedFilter) == 2 * 4);
  ExtendedFilter* extended_filters_;
  static constexpr uint32_t kExtendedFilterMemOffset =
      kStandardFilterMemOffset + sizeof(StandardFilter) * 28;
  static_assert(kExtendedFilterMemOffset == 0x0070);

  struct RxBuffer {
#define ETL_BFF_DEFINITION_FILE \
  "bldc/firmware/platform/stm32g4/peripherals/can_rx_buffer_memory.inl"
#include "third_party/etl/biffield/generate.h"
#undef ETL_BFF_DEFINITION_FILE
    uint32_t data[16];
  };
  static_assert(sizeof(RxBuffer) == 18 * 4);
  RxBuffer* rx_fifo0_;
  static constexpr uint32_t kRxFIFO0MemOffset =
      kExtendedFilterMemOffset + sizeof(ExtendedFilter) * 8;
  static_assert(kRxFIFO0MemOffset == 0x00B0);

  RxBuffer* rx_fifo1_;
  static constexpr uint32_t kRxFIFO1MemOffset =
      kRxFIFO0MemOffset + sizeof(RxBuffer) * 3;
  static_assert(kRxFIFO1MemOffset == 0x0188);

  struct TxEvent {
#define ETL_BFF_DEFINITION_FILE \
  "bldc/firmware/platform/stm32g4/peripherals/can_tx_event_memory.inl"
#include "third_party/etl/biffield/generate.h"
#undef ETL_BFF_DEFINITION_FILE
  };
  static_assert(sizeof(TxEvent) == 2 * 4);
  TxEvent* tx_event_fifo_;
  static constexpr uint32_t kTxEventFifoMemOffset =
      kRxFIFO1MemOffset + sizeof(RxBuffer) * 3;
  static_assert(kTxEventFifoMemOffset == 0x0260);

  struct TxBuffer {
#define ETL_BFF_DEFINITION_FILE \
  "bldc/firmware/platform/stm32g4/peripherals/can_tx_buffer_memory.inl"
#include "third_party/etl/biffield/generate.h"
#undef ETL_BFF_DEFINITION_FILE
    uint32_t data[16];
  };
  static_assert(sizeof(TxBuffer) == 18 * 4);
  TxBuffer* tx_buffer_;
  static constexpr uint32_t kTxBufferMemOffset =
      kTxEventFifoMemOffset + sizeof(TxEvent) * 3;
  static_assert(kTxBufferMemOffset == 0x0278);
  // Final memory accounting

  static constexpr uint32_t kMRAMAddress = 0x4000'A400U;
  static constexpr uint32_t kMRAMBankSize = 0x350U /* 212*4=848 bytes */;
  static_assert(kMRAMBankSize ==
                (sizeof(StandardFilter) * 28 + sizeof(ExtendedFilter) * 8 +
                 sizeof(RxBuffer) * 3 + sizeof(RxBuffer) * 3 +
                 sizeof(TxEvent) * 3 + sizeof(TxBuffer) * 3));
};

}  // namespace stm32g4
}  // namespace platform

#endif  // BLDC_FIRMWARE_PLATFORM_STM32G4_PERIPHERALS_CAN_H_
