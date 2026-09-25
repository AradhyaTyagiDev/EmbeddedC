#include <stdio.h>
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include "driver/gpio.h"
#include "esp_log.h"

#define FLAME_SENSOR_GPIO    GPIO_NUM_1
#define RELAY_GPIO           GPIO_NUM_2

// Most flame sensors: LOW = flame detected
#define FLAME_DETECTED_LEVEL 0

// Most relay modules: LOW = relay ON
#define RELAY_ON_LEVEL       0
#define RELAY_OFF_LEVEL      1

static const char *TAG = "FIRE_FAN";

void app_main(void)
{
    // -----------------------------
    // Configure Flame Sensor GPIO
    // -----------------------------
    gpio_config_t flame_config = {
        .pin_bit_mask = (1ULL << FLAME_SENSOR_GPIO),
        .mode = GPIO_MODE_INPUT,
        .pull_up_en = GPIO_PULLUP_ENABLE,
        .pull_down_en = GPIO_PULLDOWN_DISABLE,
        .intr_type = GPIO_INTR_DISABLE
    };

    gpio_config(&flame_config);

    // -----------------------------
    // Configure Relay GPIO
    // -----------------------------
    gpio_config_t relay_config = {
        .pin_bit_mask = (1ULL << RELAY_GPIO),
        .mode = GPIO_MODE_OUTPUT,
        .pull_up_en = GPIO_PULLUP_DISABLE,
        .pull_down_en = GPIO_PULLDOWN_DISABLE,
        .intr_type = GPIO_INTR_DISABLE
    };

    gpio_config(&relay_config);

    // Make sure motor is OFF at startup
    gpio_set_level(RELAY_GPIO, RELAY_OFF_LEVEL);

    ESP_LOGI(TAG, "Fire detection system started");
    ESP_LOGI(TAG, "Flame Sensor GPIO = GPIO1");
    ESP_LOGI(TAG, "Relay GPIO = GPIO2");

    while (1)
    {
        int flame_state = gpio_get_level(FLAME_SENSOR_GPIO);

        if (flame_state == FLAME_DETECTED_LEVEL)
        {
            // FIRE DETECTED
            gpio_set_level(RELAY_GPIO, RELAY_ON_LEVEL);

            ESP_LOGI(TAG, "🔥 FIRE DETECTED -> FAN ON");
        }
        else
        {
            // NO FIRE
            gpio_set_level(RELAY_GPIO, RELAY_OFF_LEVEL);

            ESP_LOGI(TAG, "✅ NO FIRE -> FAN OFF");
        }

        vTaskDelay(pdMS_TO_TICKS(200));
    }
}