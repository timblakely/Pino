#include "bldc/firmware/platform/stm32g4/peripherals/dma.h"

#include "third_party/stm32cubeg4/stm32g4xx_ll_bus.h"
#include "third_party/stm32cubeg4/stm32g4xx_ll_dma.h"

namespace platform {
namespace stm32g4 {

struct Dma::DMA_TypeDefI : public DMA_TypeDef {};

Dma::Dma(Instance instance) : instance_(instance) {
  switch (instance) {
    case Instance::Dma1:
      dma_ = reinterpret_cast<DMA_TypeDefI*>(DMA1);
      break;
    case Instance::Dma2:
      dma_ = reinterpret_cast<DMA_TypeDefI*>(DMA2);
      break;
  }
}

void Dma::Init() {
  LL_AHB1_GRP1_EnableClock(LL_AHB1_GRP1_PERIPH_DMAMUX1);
  switch (instance_) {
    case Instance::Dma1:
      LL_AHB1_GRP1_EnableClock(LL_AHB1_GRP1_PERIPH_DMA1);
      break;
    case Instance::Dma2:
      LL_AHB1_GRP1_EnableClock(LL_AHB1_GRP1_PERIPH_DMA2);
      break;
  }
}

uint32_t Dma::LLChannel(Channel channel) {
  switch (channel) {
    default:
    case Channel::Ch1:
      return LL_DMA_CHANNEL_1;
    case Channel::Ch2:
      return LL_DMA_CHANNEL_2;
    case Channel::Ch3:
      return LL_DMA_CHANNEL_3;
    case Channel::Ch4:
      return LL_DMA_CHANNEL_4;
    case Channel::Ch5:
      return LL_DMA_CHANNEL_5;
    case Channel::Ch6:
      return LL_DMA_CHANNEL_6;
    case Channel::Ch7:
      return LL_DMA_CHANNEL_7;
    case Channel::Ch8:
      return LL_DMA_CHANNEL_8;
  }
}

uint32_t Dma::LLRequest(Request request) {
  switch (request) {
    default:
    case Request::Tim5Ch1:
      return LL_DMAMUX_REQ_TIM5_CH1;
    case Request::Tim5Ch4:
      return LL_DMAMUX_REQ_TIM5_CH4;
  }
}

uint32_t Dma::LLPriority(Priority priority) {
  switch (priority) {
    default:
    case Priority::VeryHigh:
      return LL_DMA_PRIORITY_VERYHIGH;
    case Priority::High:
      return LL_DMA_PRIORITY_HIGH;
    case Priority::Medium:
      return LL_DMA_PRIORITY_MEDIUM;
    case Priority::Low:
      return LL_DMA_PRIORITY_LOW;
  }
}

uint32_t Dma::LLMode(Mode mode) {
  switch (mode) {
    default:
    case Mode::Normal:
      return LL_DMA_MODE_NORMAL;
    case Mode::Circular:
      return LL_DMA_MODE_CIRCULAR;
  }
}

uint32_t Dma::LLPSize(TransferSize size) {
  switch (size) {
    default:
    case TransferSize::Byte:
      return LL_DMA_PDATAALIGN_BYTE;
    case TransferSize::HalfWord:
      return LL_DMA_PDATAALIGN_HALFWORD;
    case TransferSize::Word:
      return LL_DMA_PDATAALIGN_WORD;
  }
}

uint32_t Dma::LLMSize(TransferSize size) {
  switch (size) {
    default:
    case TransferSize::Byte:
      return LL_DMA_MDATAALIGN_BYTE;
    case TransferSize::HalfWord:
      return LL_DMA_MDATAALIGN_HALFWORD;
    case TransferSize::Word:
      return LL_DMA_MDATAALIGN_WORD;
  }
}

uint32_t Dma::LLPIncrement(Increment increment) {
  switch (increment) {
    default:
    case Increment::No:
      return LL_DMA_PERIPH_NOINCREMENT;
    case Increment::Yes:
      return LL_DMA_PERIPH_INCREMENT;
  }
}

uint32_t Dma::LLMIncrement(Increment increment) {
  switch (increment) {
    default:
    case Increment::No:
      return LL_DMA_MEMORY_NOINCREMENT;
    case Increment::Yes:
      return LL_DMA_MEMORY_INCREMENT;
  }
}

Dma::DmaStream::DmaStream(DMA_TypeDefI* dma, uint32_t channel)
    : dma_(dma), chan_(channel) {}

void Dma::DmaStream::Configure(Mode mode, Increment inc_src, Increment inc_dest,
                               TransferSize transfer_size) {
  mode_ = LLMode(mode);
  src_increment_ = LLPIncrement(inc_src);
  dest_increment_ = LLMIncrement(inc_dest);
  src_transfer_size_ = LLPSize(transfer_size);
  dest_transfer_size_ = LLMSize(transfer_size);

  LL_DMA_SetMode(dma_, chan_, LLMode(mode));
  LL_DMA_SetPeriphIncMode(dma_, chan_, LLPIncrement(inc_src));
  LL_DMA_SetPeriphIncMode(dma_, chan_, LLMIncrement(inc_dest));
  LL_DMA_SetPeriphSize(dma_, chan_, LLPSize(transfer_size));
  LL_DMA_SetMemorySize(dma_, chan_, LLMSize(transfer_size));
}

void Dma::DmaStream::Start(const uint32_t* source, const uint32_t* dest, uint32_t size) {
  LL_DMA_ConfigAddresses(dma_, chan_, reinterpret_cast<uint32_t>(source),
                         reinterpret_cast<uint32_t>(dest),
                         LL_DMA_DIRECTION_MEMORY_TO_PERIPH);
  LL_DMA_SetDataLength(dma_, chan_, size);
  LL_DMA_EnableChannel(dma_, chan_);
}

Dma::DmaStream Dma::CreateStream(Channel channel, Request request,
                                 Priority priority) {
  const auto chan = LLChannel(channel);
  LL_DMA_SetPeriphRequest(dma_, chan, LLRequest(request));
  LL_DMA_SetDataTransferDirection(dma_, chan,
                                  LL_DMA_DIRECTION_MEMORY_TO_PERIPH);
  LL_DMA_SetChannelPriorityLevel(dma_, chan, LLPriority(priority));
  return {dma_, chan};
}

void Dma::PeripheralRequest(Channel channel, Request request,
                            Priority priority) {
  const auto ll_chan = LLChannel(channel);
  LL_DMA_SetPeriphRequest(dma_, ll_chan, LLRequest(request));
  LL_DMA_SetDataTransferDirection(dma_, ll_chan,
                                  LL_DMA_DIRECTION_MEMORY_TO_PERIPH);
  LL_DMA_SetChannelPriorityLevel(dma_, ll_chan, LLPriority(priority));
}

void Dma::Configure(Channel channel, Mode mode, Increment inc_src,
                    Increment inc_dest, TransferSize transfer_size,
                    const uint32_t* source, const uint32_t* dest,
                    uint32_t size) {
  const auto ll_chan = LLChannel(channel);
  LL_DMA_SetMode(dma_, ll_chan, LLMode(mode));
  LL_DMA_SetPeriphIncMode(dma_, ll_chan, LLPIncrement(inc_src));
  LL_DMA_SetPeriphIncMode(dma_, ll_chan, LLMIncrement(inc_dest));
  LL_DMA_SetPeriphSize(dma_, ll_chan, LLPSize(transfer_size));
  LL_DMA_SetMemorySize(dma_, ll_chan, LLMSize(transfer_size));

  // TODO(blakely): Does this direction really matter?
  LL_DMA_ConfigAddresses(dma_, ll_chan, reinterpret_cast<uint32_t>(source),
                         reinterpret_cast<uint32_t>(dest),
                         LL_DMA_DIRECTION_MEMORY_TO_PERIPH);
  LL_DMA_SetDataLength(dma_, ll_chan, size);
  LL_DMA_EnableChannel(dma_, ll_chan);
}

}  // namespace stm32g4
}  // namespace platform