//
// Created by liaohy on 8/26/24.
//

#include "SuperUart.h"

void uart_init(SuperUart *self, UART_HandleTypeDef *uart, uint8_t* rx_data, uint8_t* tx_data) {
    self->uart = uart;
    self->rx_data = rx_data;
    self->tx_data = tx_data;
}

void uart_block_write(SuperUart *self, uint8_t *data, uint16_t size) {
    HAL_UART_Transmit(self->uart, data, size, HAL_MAX_DELAY);
}

void uart_dma_write(SuperUart *self, uint8_t *data, uint16_t size) {
    HAL_UART_Transmit_DMA(self->uart, data, size);
}

void uart_dma_self_write(SuperUart *self, uint16_t size) {
    HAL_UART_Transmit_DMA(self->uart, self->tx_data, size);
}

void uart_dma_idle_receive(SuperUart *self, uint16_t size) {
    HAL_UARTEx_ReceiveToIdle_DMA(self->uart, self->rx_data, size);
    __HAL_DMA_DISABLE_IT(self->uart->hdmarx, DMA_IT_HT);
}

void uart_it_idle_receive(SuperUart *self, uint16_t size){
    HAL_UART_Receive_IT(self->uart, self->rx_data, size);
}
