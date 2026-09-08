#include <stdint.h>
#include <stdio.h>

#include "freertos/FreeRTOS.h"
#include "freertos/task.h"

#include "driver/gpio.h"

#define LED_PIN GPIO_NUM_10

bool configForLED(void) {
    gpio_config_t io_conf = {
        .pin_bit_mask = (1ULL << LED_PIN),
        .mode = GPIO_MODE_OUTPUT,
        .pull_up_en = GPIO_PULLUP_DISABLE,
        .pull_down_en = GPIO_PULLDOWN_DISABLE,
        .intr_type = GPIO_INTR_DISABLE,
    };

    esp_err_t configState = gpio_config(&io_conf);

    if ( configState != ESP_OK) {
        printf("GPIO configuration failed %s\n", esp_err_to_name(configState));
        return false;
    }

    return true;
}

void led(bool isOn) {
    esp_err_t err = gpio_set_level(LED_PIN, isOn ? 1 : 0);
    if (err != ESP_OK) {
        printf("Failed to set GPIO level %s\n", esp_err_to_name(err));
    } else {
        printf("LED is %s\n", isOn ? "ON" : "OFF");
    }
}
