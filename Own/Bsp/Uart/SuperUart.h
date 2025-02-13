//
// Created by liaohy on 8/26/24.
//

#ifndef NONE_PRJ_SERIAL_H
#define NONE_PRJ_SERIAL_H

#ifdef __cplusplus
extern "C" {
#endif


#include "usart.h"

#include "stdarg.h"
#include "stdio.h"
#include "string.h"

#ifdef __cplusplus
}
#endif


#define USING_UART_IT 0
#define USING_UART_IDLE 1

typedef struct {
    UART_HandleTypeDef *uart;

    uint8_t* rx_data;
    uint8_t* tx_data;
} SuperUart;

void uart_init(SuperUart *self, UART_HandleTypeDef *uart, uint8_t* rx_data, uint8_t* tx_data);
void uart_block_write(SuperUart *self, uint8_t *data, uint16_t size);
void uart_dma_write(SuperUart *self, uint8_t *data, uint16_t size);
void uart_dma_self_write(SuperUart *self, uint16_t size);
void uart_dma_idle_receive(SuperUart *self, uint16_t size);
void uart_it_idle_receive(SuperUart *self, uint16_t size);



extern SuperUart uartPlus10;

#endif //NONE_PRJ_SERIAL_H
