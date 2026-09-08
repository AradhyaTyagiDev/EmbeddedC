#include <stdio.h>
#include <stdint.h>

#include "freertos/FreeRTOS.h"
#include "freertos/task.h"

void setup() {
    vTaskDelay(pdMS_TO_TICKS(5000));
}

void loop() {
    vTaskDelay(pdMS_TO_TICKS(500));
}

int app_main() {
    setup();

    while(1) {
        loop();
    }
    
    return 0;
}

