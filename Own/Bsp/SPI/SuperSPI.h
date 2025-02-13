//
// Created by Administrator on 24-10-1.
//

#ifndef DM_42_SUPERSPI_H
#define DM_42_SUPERSPI_H

#ifdef __cplusplus
extern "C" {
#endif

#include "spi.h"

#ifdef __cplusplus
}
#endif

typedef struct {
    SPI_HandleTypeDef *hspi;
} SuperSPI;

void spi_init(SuperSPI *self, SPI_HandleTypeDef *hspi);
void spi_block_write(SuperSPI *self, uint8_t *pdata, uint16_t size);
void spi_dma_write(SuperSPI *self, uint8_t *pdata, uint16_t size);

#endif //DM_42_SUPERSPI_H
