#include <stdint.h>

#include "third_party/stm32cubeg4/system_stm32g4xx.h"

int main() {
  while (true) {
    asm("nop");
  }
}