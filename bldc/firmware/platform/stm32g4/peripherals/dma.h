#ifndef BLDC_FIRMWARE_PLATFORM_STM32G4_PERIPHERALS_DMA_H_
#define BLDC_FIRMWARE_PLATFORM_STM32G4_PERIPHERALS_DMA_H_

namespace platform {
namespace stm32g4 {

class Dma {
 private:
  // Workaround for the STM libraries using typedef'd anonymous structs.
  struct DMA_TypeDefI;

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

  enum class TransferSize {
    Byte,
    HalfWord,
    Word,
  };

  class Stream {
   public:
    void Configure(Mode mode, Increment inc_src, Increment inc_dest,
                   TransferSize transfer_size);
    void Reconfigure();
    void Start(const uint32_t* source, const uint32_t* dest, uint32_t size);

   private:
    Stream(DMA_TypeDefI* dma, uint32_t channel);

    uint32_t src_address_;
    uint32_t dest_address_;

    DMA_TypeDefI* dma_;
    uint32_t src_transfer_size_;
    uint32_t dest_transfer_size_;
    uint32_t chan_;
    uint32_t mode_;
    uint32_t src_increment_;
    uint32_t dest_increment_;
    friend class Dma;
  };

  explicit Dma(Instance instance);
  void Init();

  Stream CreateStream(Channel channel, Request request,
                      Priority priority = Priority::High);

  void PeripheralRequest(Channel channel, Request request,
                         Priority priority = Priority::High);
  // TODO(blakely): Support multiple transfer sizes.
  void Configure(Channel channel, Mode mode, Increment inc_src,
                 Increment inc_dest, TransferSize transfer_size,
                 const uint32_t* source, const uint32_t* dest, uint32_t size);

 private:
  DMA_TypeDefI* dma_;
  Instance instance_;
  // TODO(blakely): Templatize for consteval.
  inline static uint32_t LLChannel(Channel channel);
  inline static uint32_t LLRequest(Request Request);
  inline static uint32_t LLPriority(Priority priority);
  inline static uint32_t LLMode(Mode mode);
  inline static uint32_t LLPSize(TransferSize size);
  inline static uint32_t LLMSize(TransferSize size);
  inline static uint32_t LLPIncrement(Increment increment);
  inline static uint32_t LLMIncrement(Increment increment);
};

}  // namespace stm32g4
}  // namespace platform

#endif  // BLDC_FIRMWARE_PLATFORM_STM32G4_PERIPHERALS_DMA_H_
