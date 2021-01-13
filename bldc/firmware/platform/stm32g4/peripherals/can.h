#ifndef BLDC_FIRMWARE_PLATFORM_STM32G4_PERIPHERALS_CAN_H_
#define BLDC_FIRMWARE_PLATFORM_STM32G4_PERIPHERALS_CAN_H_

#include "bldc/firmware/platform/stm32g4/peripherals/gpio.h"

namespace platform {
namespace stm32g4 {

namespace registers {

// // Core release
// struct CREL {
//   uint8_t DAY : 8;
//   uint8_t MON : 8;
//   uint8_t YEAR : 4;
//   uint8_t SUBSTEP : 4;
//   uint8_t STEP : 4;
//   uint8_t REL : 4;
// };

// // Endian
// struct ENDN {
//   uint32_t EVT;
//   operator uint32_t() { return reinterpret_cast<uint32_t>(EVT); }
// };

// // Data bit timing and prescalar
// struct DBTP {
//   enum class TransceiverDelayCompensation : bool {
//     Disable = 0,
//     Enable = 1,
//   };

//   uint8_t DSJW : 4;
//   uint8_t DTSEG2 : 4;
//   uint8_t DTSEG1 : 5;
//   // Reserved
//   unsigned : 3;
//   uint8_t DBRP : 5;
//   // Reserved
//   unsigned : 2;
//   TransceiverDelayCompensation TDC : 1;
// };

// // Test mode. Must be enabled by setting bit `CCCR[TEST]` to 1.
// struct TEST {
//   enum class LoopbackMode : bool {
//     Disabled = 0,
//     Enabled = 1,
//   };

//   enum class TransmitPin : uint8_t {
//     Default = 0b00U,      // Normal operation; updated at end of CAN bit
//     time. SamplePoint = 0b01U,  // Updated at sample point. Dominant = 0b10U,
//     // Dominant (0) level at ping FDCANx_TX Recessive = 0b11U,    //
//     Recessive
//   };

//   enum class ReceivePin : uint8_t {
//     Dominant = 0b0U,
//     Recessive = 0b1U,
//   };

//   // Reserved
//   unsigned : 4;
//   LoopbackMode LBCK : 1;
//   TransmitPin TX : 2;
//   ReceivePin RX : 1;
// };

// // RAM watchdog
// struct RWD {
//   uint8_t WDC : 8;
//   uint8_t WDV : 8;
// };

// // CC control.
// struct CCCR {
//   enum class InitMode : bool {
//     Disabled = 0b0U,
//     Enabled = 0b1U,
//   };

//   enum class ConfigMode : bool {
//     ReadOnly = 0b0U,
//     ReadWrite = 0b1U,
//   };

//   enum class RestrictedMode : bool {
//     Disabled = 0b0U,
//     Enabled = 0b1U,
//   };

//   enum class ClockStopAck : bool {
//     NoAck = 0b0U,
//     Ack = 0b1U,
//   };

//   enum class ClockStopRequest : bool {
//     No = 0b0U,
//     Yes = 0b1U,
//   };

//   enum class BusMonitoringMode : bool {
//     Normal = 0b0U,
//     Monitoring = 0b1U,
//   };

//   enum class AutomaticRetransmission : bool {
//     Enabled = 0b0U,
//     Disabled = 0b1U,
//   };

//   enum class TestMode : bool {
//     Disabled = 0b0U,
//     Enabled = 0b1U,
//   };

//   enum class FDMode : bool {
//     Disabled = 0b0U,
//     Enabled = 0b1U,
//   };

//   enum class FDBitrateSwitching : bool {
//     Disabled = 0b0U,
//     Enabled = 0b1U,
//   };

//   enum class ProtocolExceptionHandling : bool {
//     Enabled = 0b0U,
//     Disabled = 0b1U,
//   };

//   enum class EdgeFiltering : bool {
//     Disabled = 0b0U,
//     Enabled = 0b1U,
//   };

//   enum class TransmitPause : bool {
//     Disabled = 0b0U,
//     Enabled = 0b1U,
//   };

//   enum class ISOMode : bool {
//     ISO11898_1 = 0b0U,
//     Bosch = 0b1U,
//   };

//   union {
//     struct {
//       // Initialization
//       InitMode INIT : 1;
//       // Configuration change enable
//       ConfigMode CCE : 1;
//       // ASM restricted operation mode
//       RestrictedMode ASM : 1;
//       // Clock stop acknowledge
//       ClockStopAck CSA : 1;
//       // Clock stop request
//       ClockStopRequest CSR : 1;
//       // Bus monitoring mode
//       BusMonitoringMode MON : 1;
//       // Disable automatic retransmission
//       // AutomaticRetransmission DAR : 1;
//       bool DAR : 1;
//       // Test mode
//       TestMode TEST : 1;
//       // FD mode
//       FDMode FDOE : 1;
//       // FD bit rate switching
//       FDBitrateSwitching BSRE : 1;
//       // Reserved
//       unsigned : 2;
//       // Protocol exception handling
//       ProtocolExceptionHandling PXHD : 1;
//       // Edge filtering during bus integration
//       EdgeFiltering EFBI : 1;
//       // Pause before starting next transmission
//       TransmitPause TXP : 1;
//       // Non-ISO mode
//       ISOMode NISO : 1;
//     };
//     uint32_t storage_;
//   };
// };

// // Nominal bit timing and prescalar
// struct NBTP {
//   // Nominal time segment after sample point.
//   uint8_t NTSEG2 : 7;
//   // Reserved
//   unsigned : 1;
//   // Nominal time before sample point
//   uint8_t NTSEG1 : 8;
//   // Bit rate prescalar
//   uint16_t NBRP : 9;
//   // Nominal resynchronization jump width
//   uint8_t NSJW : 7;
// };

}  // namespace registers

class Can {
 public:
  enum class Instance : uint32_t {
    // Note: these are the actual addresses in memory of each peripheral.
    Fdcan1 = 0x40006400UL,
    Fdcan2 = 0x40006800UL,
    Fdcan3 = 0x40006C00UL,
  };

  Can(Gpio::Pin tx, Gpio::Pin rx);

  void Init(Can::Instance instance);

 private:
  inline void ConfigureMRAM();

  struct CanInstance {
// // Core release
// registers::CREL CREL;
// uint32_t r1;  // Reserved
// // Endian
// registers::ENDN ENDN;
// // Data bit timing and prescalar
// registers::DBTP DBTP;
// // Test mode. Must be enabled by setting bit `CCCR[TEST]` to 1.
// registers::TEST TEST;
// // RAM watchdog
// registers::RWD RWD;
// // CC control.
// registers::CCCR CCCR;
// // Nominal bit timing and prescalar
// registers::NBTP NBTP;
#define ETL_BFF_DEFINITION_FILE \
  "bldc/firmware/platform/stm32g4/peripherals/can_registers.inl"
#include "third_party/etl/biffield/generate.h"
#undef ETL_BFF_DEFINITION_FILE
  };

  CanInstance* can_;

  Gpio::Pin tx_;
  Gpio::Pin rx_;

  static constexpr uint32_t kMRAMAddress = 0x4000'A400U;
};

}  // namespace stm32g4
}  // namespace platform

#endif  // BLDC_FIRMWARE_PLATFORM_STM32G4_PERIPHERALS_CAN_H_
