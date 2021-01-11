#ifndef BLDC_FIRMWARE_PLATFORM_STM32G4_PERIPHERALS_CAN_H_
#define BLDC_FIRMWARE_PLATFORM_STM32G4_PERIPHERALS_CAN_H_

namespace platform {
namespace stm32g4 {

namespace internal {

struct CanInstance {
  struct CRELRegister {
    uint8_t DAY : 8;
    uint8_t MON : 8;
    uint8_t YEAR : 4;
    uint8_t SUBSTEP : 4;
    uint8_t STEP : 4;
    uint8_t REL : 4;
  };
  // Core release register
  CRELRegister CREL;

  struct ENDNRegister {
    uint32_t EVT;
    operator uint32_t() { return reinterpret_cast<uint32_t>(EVT); }
  };
  // Endian register
  ENDNRegister ENDN;

  struct DBTPRegister {
    enum class TransceiverDelayCompensation : bool {
      Disable = 0,
      Enable = 1,
    };

    uint8_t DSJW : 4;
    uint8_t DTSEG2 : 4;
    uint8_t DTSEG1 : 5;
    unsigned : 3;  // Reserved
    uint8_t DBRP : 5;
    unsigned : 2;  // Reserved
    TransceiverDelayCompensation TDC : 1;
  };
  // Data bit timing and prescalar
  DBTPRegister DBTP;

  struct TESTRegister {
    enum class LoopbackMode : bool {
      Disabled = 0,
      Enabled = 1,
    };

    enum class TransmitPin : uint8_t {
      Default = 0b00U,      // Normal operation; updated at end of CAN bit time.
      SamplePoint = 0b01U,  // Updated at sample point.
      Dominant = 0b10U,     // Dominant (0) level at ping FDCANx_TX
      Recessive = 0b11U,    // Recessive
    };

    enum class ReceivePin : uint8_t {
      Dominant = 0b0U,
      Recessive = 0b1U,
    };

    unsigned : 4;  // Reserved
    LoopbackMode LBCK : 1;
    TransmitPin TX : 2;
    ReceivePin RX : 1;
  };
  // Test mode. Must be enabled by setting bit `CCCR[TEST]` to 1.
  TESTRegister TEST;
};

}  // namespace internal

class Can {
 public:
  enum class Instance : uint32_t {
    // Note: these are the actual addresses in memory of each peripheral.
    Fdcan1 = 0x40006400UL,
    Fdcan2 = 0x40006800UL,
    Fdcan3 = 0x40006C00UL,
  };

  Can(Can::Instance instance);

  void Init();

 private:
  internal::CanInstance *can_;
};

}  // namespace stm32g4
}  // namespace platform

#endif  // BLDC_FIRMWARE_PLATFORM_STM32G4_PERIPHERALS_CAN_H_
