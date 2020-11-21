#include "third_party/stm32cubeg4/stm32g474xx.h"

const uint32_t VECT_TAB_OFFSET = 0x00;

void SystemInit(void) {
  /* FPU settings ------------------------------------------------------------*/
  SCB->CPACR |= ((3UL << (10 * 2)) |
                 (3UL << (11 * 2))); /* set CP10 and CP11 Full Access */
  // Vector table in flash for now.
  SCB->VTOR = FLASH_BASE |
              VECT_TAB_OFFSET; /* Vector Table Relocation in Internal FLASH */
}