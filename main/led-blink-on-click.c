#include <stdio.h>
#include "driver/gpio.h"
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"

#define led_pin 2
#define btn_pin 5

void app_main(void) {
    gpio_reset_pin(led_pin);
    gpio_reset_pin(btn_pin);

    gpio_set_direction(led_pin, GPIO_MODE_OUTPUT);
    // good practice: set pull mode before direction
    gpio_set_pull_mode(btn_pin, GPIO_PULLUP_ONLY);
    gpio_set_direction(btn_pin, GPIO_MODE_INPUT);

    while (1) {
        int currStatus = gpio_get_level(btn_pin);

        if (currStatus == false) {
            gpio_set_level(led_pin, true);
            printf("\n0");
        } else {
            gpio_set_level(led_pin, false);
            printf("\n1");
        }

        vTaskDelay(10 / portTICK_PERIOD_MS);
    }
}