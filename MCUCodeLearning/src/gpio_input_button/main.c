#include <stdio.h>
#include <stdint.h>

#include "freertos/FreeRTOS.h"
#include "freertos/task.h"

#include "gpio_input_button.h"

void setup() {
    vTaskDelay(pdMS_TO_TICKS(1000));

    bool status = configButtonInput();

    if (status) { 
        printf("Button input configured successfully.\n");
    } else {
        printf("Failed to configure button input.\n");
    }   

    vTaskDelay(pdMS_TO_TICKS(1000));
}

void loop() {
    vTaskDelay(pdMS_TO_TICKS(500));
    
    bool buttonPressed = getButtonState();
    if (buttonPressed) {
        printf("Button is pressed.\n");
    } else {
        printf("Button is not pressed.\n");
    }
}

int app_main() {
    setup();

    while(1) {
        loop();
    }
    
    return 0;
}

