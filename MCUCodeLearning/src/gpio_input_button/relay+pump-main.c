// #include <stdio.h>
// #include "freertos/FreeRTOS.h"
// #include "freertos/task.h"
// #include "driver/gpio.h"

// #define RELAY_GPIO GPIO_NUM_2

// // Most relay modules are ACTIVE LOW
// #define RELAY_ON  0
// #define RELAY_OFF 1

// void app_main(void)
// {
//     // Configure relay GPIO as output
//     gpio_config_t relay_config = {
//         .pin_bit_mask = (1ULL << RELAY_GPIO),
//         .mode = GPIO_MODE_OUTPUT,
//         .pull_up_en = GPIO_PULLUP_DISABLE,
//         .pull_down_en = GPIO_PULLDOWN_DISABLE,
//         .intr_type = GPIO_INTR_DISABLE
//     };

//     gpio_config(&relay_config);

//     // Start with relay OFF
//     gpio_set_level(RELAY_GPIO, RELAY_OFF);

//     printf("\n");
//     printf("=============================\n");
//     printf(" ESP32-C3 Relay Test\n");
//     printf("=============================\n");

//     while (1)
//     {
//         // Relay ON
//         printf("Relay ON\n");
//         gpio_set_level(RELAY_GPIO, RELAY_ON);

//         vTaskDelay(pdMS_TO_TICKS(5000));

//         // Relay OFF
//         printf("Relay OFF\n");
//         gpio_set_level(RELAY_GPIO, RELAY_OFF);

//         vTaskDelay(pdMS_TO_TICKS(5000));
//     }
// }