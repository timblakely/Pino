#include "bldc/firmware/platform/stm32g4/peripherals/can/can.h"

#include <cstring>

#include "bldc/firmware/platform/stm32g4/peripherals/can/extended_filter.h"
#include "bldc/firmware/platform/stm32g4/peripherals/can/fdcan.h"
#include "bldc/firmware/platform/stm32g4/peripherals/can/rx_buffer.h"
#include "bldc/firmware/platform/stm32g4/peripherals/can/standard_filter.h"
#include "bldc/firmware/platform/stm32g4/peripherals/can/tx_buffer.h"
#include "bldc/firmware/platform/stm32g4/peripherals/can/tx_event.h"
#include "third_party/stm32cubeg4/stm32g4xx_ll_bus.h"
#include "third_party/stm32cubeg4/stm32g4xx_ll_rcc.h"

namespace platform {
namespace stm32g4 {

namespace impl {

// Ensure memory addresses are at expected locations.
static_assert(sizeof(Fdcan) == 0x104);
static_assert(sizeof(StandardFilter) == 1 * 4);
static constexpr uint32_t kStandardFilterMemOffset = 0x0;
static_assert(kStandardFilterMemOffset == 0x0000);
static_assert(sizeof(ExtendedFilter) == 2 * 4);
static constexpr uint32_t kExtendedFilterMemOffset =
    kStandardFilterMemOffset + sizeof(StandardFilter) * 28;
static_assert(kExtendedFilterMemOffset == 0x0070);
static_assert(sizeof(RxBuffer) == 18 * 4);
static constexpr uint32_t kRxFIFO0MemOffset =
    kExtendedFilterMemOffset + sizeof(ExtendedFilter) * 8;
static_assert(kRxFIFO0MemOffset == 0x00B0);
static constexpr uint32_t kRxFIFO1MemOffset =
    kRxFIFO0MemOffset + sizeof(RxBuffer) * 3;
static_assert(kRxFIFO1MemOffset == 0x0188);
static_assert(sizeof(TxEvent) == 2 * 4);
static constexpr uint32_t kTxEventFifoMemOffset =
    kRxFIFO1MemOffset + sizeof(RxBuffer) * 3;
static_assert(kTxEventFifoMemOffset == 0x0260);
static_assert(sizeof(TxBuffer) == 18 * 4);
static constexpr uint32_t kTxBufferMemOffset =
    kTxEventFifoMemOffset + sizeof(TxEvent) * 3;
static_assert(kTxBufferMemOffset == 0x0278);

// Final memory accounting
static_assert(kMRAMBankSize ==
              (sizeof(StandardFilter) * 28 + sizeof(ExtendedFilter) * 8 +
               sizeof(RxBuffer) * 3 + sizeof(RxBuffer) * 3 +
               sizeof(TxEvent) * 3 + sizeof(TxBuffer) * 3));

}  // namespace impl

using impl::ExtendedFilter;
using impl::Fdcan;
using impl::kExtendedFilterMemOffset;
using impl::kMRAMAddress;
using impl::kMRAMBankSize;
using impl::kRxFIFO0MemOffset;
using impl::kRxFIFO1MemOffset;
using impl::kTxBufferMemOffset;
using impl::kTxEventFifoMemOffset;
using impl::RxBuffer;
using impl::StandardFilter;
using impl::TxBuffer;
using impl::TxEvent;

Can::Can(Gpio::Pin tx, Gpio::Pin rx) : tx_(tx), rx_(rx) {}

void Can::Init(Can::Instance instance) {
  instance_ = instance;
  peripheral_ = reinterpret_cast<impl::Fdcan*>(instance);
  switch (instance) {
    case Instance::Fdcan1:
      standard_filters_ = reinterpret_cast<StandardFilter*>(kMRAMAddress);
      break;
    case Instance::Fdcan2:
      standard_filters_ =
          reinterpret_cast<StandardFilter*>(kMRAMAddress + kMRAMBankSize);
      break;
    case Instance::Fdcan3:
      standard_filters_ =
          reinterpret_cast<StandardFilter*>(kMRAMAddress + kMRAMBankSize * 2);
      break;
  }
  uint8_t* base_addr = reinterpret_cast<uint8_t*>(standard_filters_);
  extended_filters_ =
      reinterpret_cast<ExtendedFilter*>(base_addr + kExtendedFilterMemOffset);
  rx_fifo0_ = reinterpret_cast<RxBuffer*>(base_addr + kRxFIFO0MemOffset);
  rx_fifo1_ = reinterpret_cast<RxBuffer*>(base_addr + kRxFIFO1MemOffset);
  tx_event_fifo_ =
      reinterpret_cast<TxEvent*>(base_addr + kTxEventFifoMemOffset);
  tx_buffer_ = reinterpret_cast<TxBuffer*>(base_addr + kTxBufferMemOffset);

  // TODO(blakely): Assumes FDCAN1 on PA11/PA12 for RX/TX respectively.

  rx_.Configure(Gpio::OutputMode::PushPull, Gpio::Pullup::None,
                Gpio::AlternateFunction::AF9);
  tx_.Configure(Gpio::OutputMode::PushPull, Gpio::Pullup::None,
                Gpio::AlternateFunction::AF9);

  // TODO(blakely): We have to set bit 20 directly since the LL drivers
  // helpfully ignore any configuration of it >:(
  RCC->PLLCFGR = (RCC->PLLCFGR & 0xFFEFFFFF) | (1U << 20);
  // Make sure we set thre right clock source: PLL is currently used.
  LL_RCC_SetFDCANClockSource(LL_RCC_FDCAN_CLKSOURCE_PLL);
  // Enable the clock.
  LL_APB1_GRP1_EnableClock(LL_APB1_GRP1_PERIPH_FDCAN);

  // Zero out the memory. Note: Must be done *after* enabling the FDCAN clock!
  memset(reinterpret_cast<void*>(kMRAMAddress), 0, kMRAMBankSize * 3);

  // TODO(blakely): Set SynSeg, BS1, and BS2
  // Baud = 1 / bit_time = t_ss + t_bs1 + t_bs2
  // Controlled by FDCAN_NBTP.NBRP, FDCAN_NBTP.NTSEG1, and FDCAN_NBTP.NTSEG2

  // TODO(blakely): Do we need to read FDCAN_ENDN?

  // Init and control configuration.
  peripheral_->InitMode();
  peripheral_->Initialize();
  peripheral_->SetBitTiming();
  peripheral_->EnableQueueMode();
  peripheral_->EnableLoopbackMode();
  // TODO(blakely): Set DBTP. 8.01MBit is 2/2/2
  peripheral_->SetClockDivider();

  // TODO(blakely): Configure this though an enum to Init()

  standard_filters_[0].SetFilter(StandardFilter::FilterType::dual_id,
                                 StandardFilter::Action::store_fifo0, 13, 37);
  peripheral_->Start();
}

void Can::TransmitData(uint8_t* data, uint8_t size) {
  const auto idx = peripheral_->TxPut();
  auto buffer = &(tx_buffer_[idx]);
  buffer->WriteStandardDataFrame(13, data, TxBuffer::FrameSize::can3);
  peripheral_->TransmitBuffer(idx);
}

}  // namespace stm32g4
}  // namespace platform