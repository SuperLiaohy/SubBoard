//
// Created by Administrator on 25-2-14.
//
#include "OwnTask.h"

void LedTask(void const* argument) {
    uint8_t red = 0;
    uint8_t green = 0;
    uint8_t blue = 0;
    while (1) {
        red++;
        green += 5;
        blue += 10;
        rgb_os_load(&rgb_led, red, green, blue);
        osDelay(1);
    }
}