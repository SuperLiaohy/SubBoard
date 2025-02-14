//
// Created by Administrator on 25-2-14.
//
#include "OwnTask.h"

void LedTask(void const* argument) {
    uint8_t red = 0;
    uint8_t green = 0;
    uint8_t blue = 0;
    while (1) {
				if(interact.status){
					red = 255;
					green =0;
					blue =0;
				} else {
					red = 0;
					green =255;
					blue =0;
				}
//        red++;
//        green += 5;
//        blue += 10;
        rgb_os_load(&rgb_led, red, green, blue);
        osDelay(100);
    }
}