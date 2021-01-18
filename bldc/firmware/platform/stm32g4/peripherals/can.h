#ifndef BLDC_FIRMWARE_PLATFORM_STM32G4_PERIPHERALS_CAN_H_
#define BLDC_FIRMWARE_PLATFORM_STM32G4_PERIPHERALS_CAN_H_

#include "bldc/firmware/platform/stm32g4/peripherals/gpio.h"

namespace platform {
namespace stm32g4 {

namespace impl {

#define PSL_INL inline

static constexpr uint32_t kMRAMAddress = 0x4000'A400U;
static constexpr uint32_t kMRAMBankSize = 0x350U /* 212*4=848 bytes */;

// Registers
struct Fdcan {
#define ETL_BFF_DEFINITION_FILE \
  "bldc/firmware/platform/stm32g4/peripherals/can_registers.inl"
#include "third_party/etl/biffield/generate.h"
#undef ETL_BFF_DEFINITION_FILE

  PSL_INL void InitMode();
  PSL_INL void EnableQueueMode();
  PSL_INL void EnableLoopbackMode();
  PSL_INL void Start();

  PSL_INL void Transmit();

  // TODO(blakely): Actually make these configurable?
  PSL_INL void Initialize();
  PSL_INL void SetBitTiming();
  PSL_INL void SetClockDivider();

  PSL_INL uint8_t TxPut();
  PSL_INL uint8_t TxGet();

 private:
  using CCCR = CCCR_value_t;
  using CKDIV = CKDIV_value_t;
  using NBTP = NBTP_value_t;
  using TEST = TEST_value_t;
  using TXBC = TXBC_value_t;
};

// Memory configuration
struct StandardFilter {
#define ETL_BFF_DEFINITION_FILE \
  "bldc/firmware/platform/stm32g4/peripherals/can_standard_filter_memory.inl"
#include "third_party/etl/biffield/generate.h"
#undef ETL_BFF_DEFINITION_FILE
};

struct ExtendedFilter {
#define ETL_BFF_DEFINITION_FILE \
  "bldc/firmware/platform/stm32g4/peripherals/can_extended_filter_memory.inl"
#include "third_party/etl/biffield/generate.h"
#undef ETL_BFF_DEFINITION_FILE
};

struct RxBuffer {
#define ETL_BFF_DEFINITION_FILE \
  "bldc/firmware/platform/stm32g4/peripherals/can_rx_buffer_memory.inl"
#include "third_party/etl/biffield/generate.h"
#undef ETL_BFF_DEFINITION_FILE
  uint32_t data[16];
};

struct TxEvent {
#define ETL_BFF_DEFINITION_FILE \
  "bldc/firmware/platform/stm32g4/peripherals/can_tx_event_memory.inl"
#include "third_party/etl/biffield/generate.h"
#undef ETL_BFF_DEFINITION_FILE
};

struct TxBuffer {
#define ETL_BFF_DEFINITION_FILE \
  "bldc/firmware/platform/stm32g4/peripherals/can_tx_buffer_memory.inl"
#include "third_party/etl/biffield/generate.h"
#undef ETL_BFF_DEFINITION_FILE
  uint32_t data[16];
};

}  // namespace impl

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

  impl::Fdcan* peripheral_;

  impl::StandardFilter* standard_filters_;
  impl::ExtendedFilter* extended_filters_;
  impl::RxBuffer* rx_fifo0_;
  impl::RxBuffer* rx_fifo1_;
  impl::TxEvent* tx_event_fifo_;
  impl::TxBuffer* tx_buffer_;
};

}  // namespace stm32g4
}  // namespace platform

#endif  // BLDC_FIRMWARE_PLATFORM_STM32G4_PERIPHERALS_CAN_H_
