// #include <stdio.h>
// #include <stdint.h>

// #include "freertos/FreeRTOS.h"
// #include "freertos/task.h"

// #include "driver/ledc.h"
// #include "esp_err.h"

// #define SERVO_GPIO          5

// #define SERVO_FREQUENCY     50
// #define SERVO_TIMER         LEDC_TIMER_0
// #define SERVO_CHANNEL       LEDC_CHANNEL_0

// #define SERVO_RESOLUTION    LEDC_TIMER_14_BIT

// #define PWM_MAX_DUTY        ((1 << 14) - 1)

// #define SERVO_MIN_US        1000
// #define SERVO_CENTER_US     1500
// #define SERVO_MAX_US        2000


// static void servo_init(void)
// {
//     // Configure LEDC timer
//     ledc_timer_config_t timer_config = {
//         .speed_mode       = LEDC_LOW_SPEED_MODE,
//         .duty_resolution  = SERVO_RESOLUTION,
//         .timer_num        = SERVO_TIMER,
//         .freq_hz          = SERVO_FREQUENCY,
//         .clk_cfg          = LEDC_AUTO_CLK
//     };

//     ESP_ERROR_CHECK(ledc_timer_config(&timer_config));


//     // Configure LEDC channel
//     ledc_channel_config_t channel_config = {
//         .gpio_num          = SERVO_GPIO,       // <-- CORRECT
//         .speed_mode        = LEDC_LOW_SPEED_MODE,
//         .channel            = SERVO_CHANNEL,
//         .intr_type          = LEDC_INTR_DISABLE,
//         .timer_sel          = SERVO_TIMER,
//         .duty               = 0,
//         .hpoint             = 0
//     };

//     ESP_ERROR_CHECK(ledc_channel_config(&channel_config));
// }


// static void servo_set_pulse_us(uint32_t pulse_us)
// {
//     // 50 Hz = 20 ms = 20,000 us period

//     uint32_t duty =
//         ((uint64_t)pulse_us * PWM_MAX_DUTY) / 20000;

//     ESP_ERROR_CHECK(
//         ledc_set_duty(
//             LEDC_LOW_SPEED_MODE,
//             SERVO_CHANNEL,
//             duty
//         )
//     );

//     ESP_ERROR_CHECK(
//         ledc_update_duty(
//             LEDC_LOW_SPEED_MODE,
//             SERVO_CHANNEL
//         )
//     );

//     printf("Pulse: %lu us | Duty: %lu\n",
//            (unsigned long)pulse_us,
//            (unsigned long)duty);
// }

// void app_main(void)
// {
//     printf("\n");
//     printf("=================================\n");
//     printf(" ESP32-C3 SG90 Continuous Sweep\n");
//     printf("=================================\n");

//     servo_init();

//     while (1)
//     {
//         // 0° -> 180°
//         for (int pulse = 1000; pulse <= 2000; pulse += 10)
//         {
//             servo_set_pulse_us(pulse);

//             // Speed control
//             vTaskDelay(pdMS_TO_TICKS(5));
//         }

//         // 180° -> 0°
//         for (int pulse = 2000; pulse >= 1000; pulse -= 10)
//         {
//             servo_set_pulse_us(pulse);

//             // Speed control
//             vTaskDelay(pdMS_TO_TICKS(5));
//         }
//     }
// }