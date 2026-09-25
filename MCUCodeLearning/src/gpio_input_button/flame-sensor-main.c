// #include <stdio.h>
// #include "freertos/FreeRTOS.h"
// #include "freertos/task.h"
// #include "driver/gpio.h"
// #include "driver/ledc.h"

// #define FLAME_SENSOR_GPIO    GPIO_NUM_3
// #define BUZZER_GPIO          GPIO_NUM_2

// #define BUZZER_MODE             LEDC_LOW_SPEED_MODE
// #define BUZZER_TIMER            LEDC_TIMER_0
// #define BUZZER_CHANNEL          LEDC_CHANNEL_0

// #define BUZZER_RESOLUTION       LEDC_TIMER_10_BIT

// // 10-bit resolution = 0 to 1023
// // 512 = approximately 50% duty cycle
// #define BUZZER_DUTY             512

// static void buzzer_set_frequency(uint32_t frequency)
// {
//     ledc_set_freq(
//         BUZZER_MODE,
//         BUZZER_TIMER,
//         frequency
//     );

//     ledc_set_duty(
//         BUZZER_MODE,
//         BUZZER_CHANNEL,
//         BUZZER_DUTY
//     );

//     ledc_update_duty(
//         BUZZER_MODE,
//         BUZZER_CHANNEL
//     );
// }

// static void buzzer_off(void)
// {
//     ledc_set_duty(
//         BUZZER_MODE,
//         BUZZER_CHANNEL,
//         0
//     );

//     ledc_update_duty(
//         BUZZER_MODE,
//         BUZZER_CHANNEL
//     );
// }

// void configBuzzer() {
//     //Configure LEDC timer
//     ledc_timer_config_t buzzer_timer = {
//         .speed_mode       = BUZZER_MODE,
//         .duty_resolution  = BUZZER_RESOLUTION,
//         .timer_num        = BUZZER_TIMER,
//         .freq_hz          = 2000,
//         .clk_cfg          = LEDC_AUTO_CLK
//     };

//     ledc_timer_config(&buzzer_timer);

//     //Configure buzzer GPIO
//     ledc_channel_config_t buzzer_channel = {
//         .gpio_num       = BUZZER_GPIO,
//         .speed_mode     = BUZZER_MODE,
//         .channel        = BUZZER_CHANNEL,
//         .intr_type      = LEDC_INTR_DISABLE,
//         .timer_sel      = BUZZER_TIMER,
//         .duty           = 0,
//         .hpoint         = 0
//     };

//     ledc_channel_config(&buzzer_channel);

//     printf("\n");
//     printf("=====================================\n");
//     printf(" ESP32-C3 Passive Buzzer Test\n");
//     printf(" GPIO: 3\n");
//     printf("=====================================\n\n");
// }


// void app_main(void)
// {
//     // Configure flame sensor as input
//     gpio_config_t flame_config = {
//         .pin_bit_mask = (1ULL << FLAME_SENSOR_GPIO),
//         .mode = GPIO_MODE_INPUT,
//         .pull_up_en = GPIO_PULLUP_DISABLE,
//         .pull_down_en = GPIO_PULLDOWN_DISABLE,
//         .intr_type = GPIO_INTR_DISABLE
//     };

//     gpio_config(&flame_config);

//     // Configure buzzer as output
//     configBuzzer();

//     printf("\n");
//     printf("=================================\n");
//     printf(" Flame Sensor Experiment\n");
//     printf(" ESP32-C3 + ESP-IDF\n");
//     printf("=================================\n");

//     while (1)
//     {
//         int flame_state = gpio_get_level(FLAME_SENSOR_GPIO);

//         if (flame_state == 0)
//         {
//             // Flame detected
//             printf("🔥 FLAME DETECTED!\n");
//             buzzer_set_frequency(3000);
//         }
//         else
//         {
//             // No flame
//             printf("No flame\n");

//             buzzer_off();
//         }

//         vTaskDelay(pdMS_TO_TICKS(200));
//     }
// }




