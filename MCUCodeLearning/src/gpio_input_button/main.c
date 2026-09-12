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
    ///Remove Delay and print statement for real debugging with Logic Analyser
    vTaskDelay(pdMS_TO_TICKS(50));
    
    bool buttonPressed = getButtonState();
    if (buttonPressed) {
        printf("BUTTON PRESSED.\n");
    } else {
        printf("BUTTON RELEASED.\n");
    }
}

int app_main() {
    setup();

    while(1) {
        loop();
    }
    
    return 0;
}