#ifndef BLDC_FIRMWARE_PLATFORM_STM32G4_PERIPHERALS_CAN_CAN_H_
#define BLDC_FIRMWARE_PLATFORM_STM32G4_PERIPHERALS_CAN_CAN_H_

#include "bldc/firmware/platform/stm32g4/peripherals/gpio.h"

namespace platform {
namespace stm32g4 {

namespace impl {

struct ExtendedFilter;
struct StandardFilter;
struct Fdcan;
struct TxBuffer;
struct TxEvent;
struct RxBuffer;

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

#endif  // BLDC_FIRMWARE_PLATFORM_STM32G4_PERIPHERALS_CAN_CAN_H_