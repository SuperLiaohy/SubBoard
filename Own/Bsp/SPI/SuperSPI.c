//
// Created by Administrator on 24-10-1.
//

#include "SuperSPI.h"

void spi_init(SuperSPI *self, SPI_HandleTypeDef *hspi) {
    self->hspi = hspi;
}
void spi_block_write(SuperSPI *self, uint8_t *pData, uint16_t Size) {
    HAL_SPI_Transmit(self->hspi, pData, Size, HAL_MAX_DELAY);
}
void spi_dma_write(SuperSPI *self, uint8_t *pData, uint16_t Size) {
    HAL_SPI_Transmit_DMA(self->hspi, pData, Size);
}


