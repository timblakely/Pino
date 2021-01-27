#ifndef BLDC_FIRMWARE_PLATFORM_STM32G4_PERIPHERALS_TIMER_PERIPHERAL_H_
#define BLDC_FIRMWARE_PLATFORM_STM32G4_PERIPHERALS_TIMER_PERIPHERAL_H_

namespace platform {
namespace stm32g4 {

namespace timer {

// clang-format off
struct AdvancedPeripheral {
  AdvancedPeripheral() = delete;
  AdvancedPeripheral(AdvancedPeripheral&) = delete;
  AdvancedPeripheral(AdvancedPeripheral&&) = delete;
#define ETL_BFF_DEFINITION_FILE                                  \
  "bldc/firmware/platform/stm32g4/peripherals/timer/timer_adv_memory.inl"
#include "third_party/etl/biffield/generate.h"
#undef ETL_BFF_DEFINITION_FILE
};

struct GPAPeripheral {
  GPAPeripheral() = delete;
  GPAPeripheral(GPAPeripheral&) = delete;
  GPAPeripheral(GPAPeripheral&&) = delete;
#define ETL_BFF_DEFINITION_FILE                                  \
  "bldc/firmware/platform/stm32g4/peripherals/timer/timer_gp_a_memory.inl"
#include "third_party/etl/biffield/generate.h"
#undef ETL_BFF_DEFINITION_FILE

  using CR1 = CR1_value_t;
  using SMCR = SMCR_value_t;
  using PSC = PSC_value_t;
  using ARR = ARR_value_t;
  
  inline void InternalClock() {
    update_SMCR([](SMCR v) {
      return v.with_SMS(SMCR::SMS_t::disabled).with_SMS_3(0);
    });
  }

  inline void ConfigureTimer(uint16_t prescalar, uint16_t auto_reset) {
   update_PSC([&prescalar](PSC v) {
     return v.with_PSC(prescalar);
   });
   update_ARR([&auto_reset](ARR v) {
     return v.with_ARR(auto_reset);
   });
  }
};

struct GPBPeripheral {
  GPBPeripheral() = delete;
  GPBPeripheral(GPBPeripheral&) = delete;
  GPBPeripheral(GPBPeripheral&&) = delete;
#define ETL_BFF_DEFINITION_FILE                                  \
  "bldc/firmware/platform/stm32g4/peripherals/timer/timer_gp_b_memory.inl"
#include "third_party/etl/biffield/generate.h"
#undef ETL_BFF_DEFINITION_FILE
};

struct BasicPeripheral {
  BasicPeripheral() = delete;
  BasicPeripheral(BasicPeripheral&) = delete;
  BasicPeripheral(BasicPeripheral&&) = delete;
#define ETL_BFF_DEFINITION_FILE                                  \
  "bldc/firmware/platform/stm32g4/peripherals/timer/timer_basic_memory.inl"
#include "third_party/etl/biffield/generate.h"
#undef ETL_BFF_DEFINITION_FILE
};
// clang-format on

}  // namespace timer

}  // namespace stm32g4
}  // namespace platform

#endif  // BLDC_FIRMWARE_PLATFORM_STM32G4_PERIPHERALS_TIMER_PERIPHERAL_H_
