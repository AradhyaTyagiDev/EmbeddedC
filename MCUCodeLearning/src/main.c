#include <stdio.h>
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include "04_pointer/pointer.h"

#define BASE_ADDRESS (volatile uint32_t *) 0x3fc8deacU
#define REG_VAL (*(volatile uint32_t *) (BASE_ADDRESS + 0x1U))

#define REG8  (*(volatile uint8_t  *)0x3fc8deacU)
#define REG16 (*(volatile uint16_t *)0x3fc8deacU)
#define REG32 (*(volatile uint32_t *)0x3fc8deacU)
#define REG64 (*(volatile uint64_t *)0x3fc8deacU)

void app_main() {
    while (1) {

 



        vTaskDelay(pdMS_TO_TICKS(5000));
    }
}