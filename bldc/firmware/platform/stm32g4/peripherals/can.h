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

  // Endian register
  struct ENDNRegister {
    uint32_t EVT;
    operator uint32_t() { return reinterpret_cast<uint32_t>(EVT); }
  };
  ENDNRegister ENDN;

  // DO NOT USE CURRENTLY BROKEN HACKHACKHACK
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

  DBTPRegister DBTP;
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
