
#include <stdio.h>
#include "freertos/FreeRTOS.h"

#include "gpio.h"

void setup() {
    bool status = configForLED();
    if (!status) {
        printf("Failed to configure LED\n");
        return;
    }
}

void loop() {
    led(true);
    vTaskDelay(pdMS_TO_TICKS(5000));
    led(false);
    vTaskDelay(pdMS_TO_TICKS(500));
}

int app_main() {
    vTaskDelay(pdMS_TO_TICKS(1000));
    setup();

    vTaskDelay(pdMS_TO_TICKS(1000));

    while(1) {
        loop();
    }
    
    return 0;
}
