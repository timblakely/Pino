#ifndef BLDC_FIRMWARE_PLATFORM_STM32G4_PERIPHERALS_CAN_CAN_H_
#define BLDC_FIRMWARE_PLATFORM_STM32G4_PERIPHERALS_CAN_CAN_H_

#include "bldc/firmware/platform/stm32g4/peripherals/can/frame.h"
#include "bldc/firmware/platform/stm32g4/peripherals/can/peripheral.h"
#include "bldc/firmware/platform/stm32g4/peripherals/can/tx_buffer.h"
#include "bldc/firmware/platform/stm32g4/peripherals/gpio.h"
#include "third_party/sg14/inplace_function_wrapper.h"

namespace platform {
namespace stm32g4 {

namespace can {

struct ExtendedFilter;
struct StandardFilter;
struct Peripheral;
struct TxEvent;
struct RxBuffer;

}  // namespace can

class Can {
 public:
  using ReceiveCallback = stdext::Callback<void()>;

  enum class Instance : uint32_t {
    // Note: these are the actual addresses in memory of each peripheral.
    Fdcan1 = 0x4000'6400UL,
    Fdcan2 = 0x4000'6800UL,
    Fdcan3 = 0x4000'6C00UL,
  };

  Can(Gpio::Pin tx, Gpio::Pin rx);

  void Init(Can::Instance instance);

  template <typename FrameType, bool BitrateSwitching = true,
            bool StoreEvent = true>
  void SendFrame(FrameType& frame) {
    const auto idx = peripheral_->TxPut();
    auto buffer = &(tx_buffer_[idx]);
    static_cast<FrameType::Header&>(buffer->header_)
        .template Apply<BitrateSwitching, StoreEvent>(123);
    frame.CopyToSRAM(buffer->data_);
    peripheral_->TransmitBuffer(idx);
  }

  template <typename T>
  void SetHandler(ReceiveCallback callback);

 private:
  Instance instance_;

  Gpio::Pin tx_;
  Gpio::Pin rx_;

  can::Peripheral* peripheral_;

  can::StandardFilter* standard_filters_;
  can::ExtendedFilter* extended_filters_;
  can::RxBuffer* rx_fifo0_;
  can::RxBuffer* rx_fifo1_;
  can::TxEvent* tx_event_fifo_;
  can::TxBuffer* tx_buffer_;

  static constexpr uint8_t kMaxNumReceiveHandlers = 10;
  static inline std::array<ReceiveCallback, kMaxNumReceiveHandlers> handlers = {
      {}};
};

}  // namespace stm32g4
}  // namespace platform

#endif  // BLDC_FIRMWARE_PLATFORM_STM32G4_PERIPHERALS_CAN_CAN_H_
