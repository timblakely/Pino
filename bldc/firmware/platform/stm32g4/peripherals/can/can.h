#ifndef BLDC_FIRMWARE_PLATFORM_STM32G4_PERIPHERALS_CAN_CAN_H_
#define BLDC_FIRMWARE_PLATFORM_STM32G4_PERIPHERALS_CAN_CAN_H_
#include "bldc/firmware/platform/stm32g4/peripherals/can/extended_filter.h"
#include "bldc/firmware/platform/stm32g4/peripherals/can/frame.h"
#include "bldc/firmware/platform/stm32g4/peripherals/can/peripheral.h"
#include "bldc/firmware/platform/stm32g4/peripherals/can/rx_buffer.h"
#include "bldc/firmware/platform/stm32g4/peripherals/can/standard_filter.h"
#include "bldc/firmware/platform/stm32g4/peripherals/can/tx_buffer.h"
#include "bldc/firmware/platform/stm32g4/peripherals/gpio.h"
#include "bldc/firmware/platform/stm32g4/peripherals/nvic.h"
#include "third_party/kennytm/utils/traits.hpp"
#include "third_party/sg14/inplace_function_wrapper.h"

// TODO(blakely): Move somewhere better.
namespace utils {

template <typename F>
using first_arg =
    std::decay_t<typename function_traits<F>::template arg<0>::type>;

}  // namespace utils

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
  using ReceiveCallback = stdext::Callback<void(BaseCanFrame&)>;

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

  template <uint32_t FilterSlot, typename Functor>
  void SetHandler(Functor callback) {
    using FrameType = utils::first_arg<Functor>;
    handlers_[next_handler_] = std::make_tuple(
        FrameType::Header::Id, [&callback](BaseCanFrame& frame) {
          callback(static_cast<FrameType&>(frame));
        });
    ++next_handler_;

    if (FrameType::Header::IsFD) {
      extended_filters_[FilterSlot].SetFilter<typename FrameType::Header>();
    } else {
      standard_filters_[FilterSlot].SetFilter<typename FrameType::Header>();
    }

    peripheral_->EnableRxFIFO0Interrupt();
    // Set handler in  NVIC.
    Nvic::SetInterrupt(Interrupt::FDCAN_InterruptLine0, 1, 0, [this]() {
      peripheral_->ClearRX0Interrupt();  //
      const auto buffer_id = peripheral_->Rx0Get();
      FrameType frame;
      frame.CopyFromSRAM(rx_fifo0_[buffer_id].data);
      peripheral_->Rx0Ack(buffer_id);
      // TODO(blakely): Straight iteration is meh here, but don't have a good
      // statically allocated map yet.
      for (const auto& handler : handlers_) {
        if (std::get<0>(handler) == FrameType::Header::Id) {
          std::get<1>(handler)(static_cast<BaseCanFrame&>(frame));
        }
      }
    });
    // Finally, enable it.
    Nvic::EnableInterrupt(Interrupt::FDCAN_InterruptLine0);
  }

 private:
  can::TxBuffer* NextRxFIFO0Buffer();
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
  static uint8_t next_handler_;
  static inline std::array<std::tuple<uint32_t, ReceiveCallback>,
                           kMaxNumReceiveHandlers>
      handlers_ = {{}};
};

}  // namespace stm32g4
}  // namespace platform

#endif  // BLDC_FIRMWARE_PLATFORM_STM32G4_PERIPHERALS_CAN_CAN_H_
