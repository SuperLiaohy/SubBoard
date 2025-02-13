//
// Created by Administrator on 24-10-1.
//

#include "RGBLED.h"

#define WS2812_LowLevel    0xC0     // 0码
#define WS2812_HighLevel   0xF0     // 1码


void rgb_init(RgbLed *self, SPI_HandleTypeDef *hspi) {
    spi_init(&self->spiPlus, hspi);
    self->red = 0;
    self->green = 0;
    self->blue = 0;
}

void rgb_os_load(RgbLed *self, uint8_t red, uint8_t green, uint8_t blue) {
    uint8_t res = 0;
    for (int i = 0; i < 8; i++) {
        self->tx_buf[7 - i] = (((green >> i) & 0x01) ? WS2812_HighLevel : WS2812_LowLevel) >> 1;
        self->tx_buf[15 - i] = (((red >> i) & 0x01) ? WS2812_HighLevel : WS2812_LowLevel) >> 1;
        self->tx_buf[23 - i] = (((blue >> i) & 0x01) ? WS2812_HighLevel : WS2812_LowLevel) >> 1;
    }

    spi_block_write(&self->spiPlus, &res, 0);
    osDelay(1);
    spi_block_write(&self->spiPlus, self->tx_buf, 24);

    for (int i = 0; i < 100; ++i) {
        spi_block_write(&self->spiPlus, &res, 1);
    }
}
void rgb_hal_load(RgbLed *self, uint8_t red, uint8_t green, uint8_t blue) {
    uint8_t res = 0;
    for (int i = 0; i < 8; i++) {
        self->tx_buf[7 - i] = (((green >> i) & 0x01) ? WS2812_HighLevel : WS2812_LowLevel) >> 1;
        self->tx_buf[15 - i] = (((red >> i) & 0x01) ? WS2812_HighLevel : WS2812_LowLevel) >> 1;
        self->tx_buf[23 - i] = (((blue >> i) & 0x01) ? WS2812_HighLevel : WS2812_LowLevel) >> 1;
    }

    spi_block_write(&self->spiPlus, &res, 0);
    HAL_Delay(1);
    spi_block_write(&self->spiPlus, self->tx_buf, 24);

    for (int i = 0; i < 100; ++i) {
        spi_block_write(&self->spiPlus, &res, 1);
    }
}

