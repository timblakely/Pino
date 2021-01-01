#ifndef BLDC_FIRMWARE_PLATFORM_STM32G4_PERIPHERALS_DMA_H_
#define BLDC_FIRMWARE_PLATFORM_STM32G4_PERIPHERALS_DMA_H_

namespace platform {
namespace stm32g4 {

class Dma {
 public:
  enum class Instance {
    Dma1,
    Dma2,
  };

  enum class Channel {
    Ch1,
    Ch2,
    Ch3,
    Ch4,
    Ch5,
    Ch6,
    Ch7,
    Ch8,
  };

  enum class Request {
    // TODO(blakely): complete.
    Tim5Ch1,
    Tim5Ch4,
  };

  enum class Priority {
    VeryHigh,
    High,
    Medium,
    Low,
  };

  enum class Mode {
    Normal,
    Circular,
  };

  enum class Increment {
    No,
    Yes,
  };

  enum class Size {
    Byte,
    HalfWord,
    Word,
  };

  explicit Dma(Instance instance);
  void Init();
  void PeripheralRequest(Channel channel, Request request,
                         Priority priority = Priority::High);
  // TODO(blakely): Support multiple transfer sizes.
  void Configure(Channel channel, Mode mode, Increment inc_src,
                 Increment inc_dest, Size transfer_size, uint32_t* source,
                 uint32_t* dest, uint32_t size);

 private:
  Instance instance_;
  // TODO(blakely): Templatize for consteval.
  inline static uint32_t LLChannel(Channel channel);
  inline static uint32_t LLRequest(Request Request);
  inline static uint32_t LLPriority(Priority priority);
  inline static uint32_t LLMode(Mode mode);
  inline static uint32_t LLPSize(Size size);
  inline static uint32_t LLMSize(Size size);
  inline static uint32_t LLPIncrement(Increment increment);
  inline static uint32_t LLMIncrement(Increment increment);
  // Workaround for the STM libraries using typedef'd anonymous structs.
  struct DMA_TypeDefI;
  DMA_TypeDefI* ll_dma_;
};

}  // namespace stm32g4
}  // namespace platform

#endif  // BLDC_FIRMWARE_PLATFORM_STM32G4_PERIPHERALS_DMA_H_
