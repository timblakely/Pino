#ifndef BLDC_FIRMWARE_STM32G474_MCU_CONFIG_H_
#define BLDC_FIRMWARE_STM32G474_MCU_CONFIG_H_

#include "bldc/firmware/platform/stm32g4/peripherals/nvic.h"

namespace stm32g474 {
void Startup();

void OnFatal(drivers::InterruptCallback &&callback);

void Fatal();

}  // namespace stm32g474

#endif  // BLDC_FIRMWARE_STM32G474_MCU_CONFIG_H_
