//
// Created by Administrator on 24-10-1.
//

#ifndef DM_42_RGBLED_H
#define DM_42_RGBLED_H

#ifdef __cplusplus
extern "C" {
#endif

#include "cmsis_os.h"

#ifdef __cplusplus
}
#endif

#include "SPI/SuperSPI.h"
/*
 * RGBLED使用的时SPI6
 * 而SPI6使用的是BDMA
 * 其BDMA只能在RAM3中
 * 所以使用SPI DMA传输的数据必须要在RAM3中
 */
typedef struct {
    uint8_t red;
    uint8_t green;
    uint8_t blue;

    SuperSPI spiPlus;
    uint8_t tx_buf[24];
} RgbLed;

void rgb_init(RgbLed *self, SPI_HandleTypeDef *hspi);
void rgb_os_load(RgbLed *self, uint8_t red, uint8_t green, uint8_t blue);
void rgb_hal_load(RgbLed *self, uint8_t red, uint8_t green, uint8_t blue);



#endif //DM_42_RGBLED_H
