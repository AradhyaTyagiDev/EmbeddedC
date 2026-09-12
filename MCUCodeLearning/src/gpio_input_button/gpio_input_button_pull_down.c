#include <stdio.h>
#include <stdint.h>
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include "driver/gpio.h"

#define BUTTON_PIN GPIO_NUM_10

bool configButtonInput() {
    gpio_config_t io_conf = {
        .pin_bit_mask = (1ULL << BUTTON_PIN),
        .mode = GPIO_MODE_INPUT,
        .pull_up_en = GPIO_PULLUP_DISABLE,
        .pull_down_en = GPIO_PULLDOWN_ENABLE,
        .intr_type = GPIO_INTR_DISABLE,
    };
    
    esp_err_t configState = gpio_config(&io_conf);

    if ( configState != ESP_OK) {
        printf("GPIO configuration failed %s\n", esp_err_to_name(configState));
        return false;
    }

    return true;
}

bool getButtonState() {
    int level = gpio_get_level(BUTTON_PIN);
    return (level == 1); // Button pressed when level is High
}