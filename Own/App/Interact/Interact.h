//
// Created by Administrator on 25-2-14.
//

#ifndef SUBBOARD_INTERACT_H
#define SUBBOARD_INTERACT_H

#include "Uart/SuperUart.h"

typedef struct {
    uint8_t sof;
    uint16_t data_length;
    uint8_t crc8;
} __attribute__((packed)) frame_header;

/*
 * todo: 修改这里状态的数据结构
 */
typedef struct {
    uint8_t map_back_over : 1;
    uint8_t lock : 1;
    uint8_t none : 6;
} __attribute__((packed)) tx_status;
typedef struct {
    tx_status s;
    /*
     * todo: 添加自己自定义的发送数据
     */
    float data[8];
} __attribute__((packed)) custom_tx_frame;
typedef struct {
    frame_header frame_head;
    uint16_t cmd_id;
    uint8_t data[64 - sizeof(frame_header) - sizeof(uint16_t) - sizeof(uint16_t)];
    uint16_t crc16;
} __attribute__((packed)) trans_frame;


/*
 * todo: 修改这里状态的数据结构
 */
typedef struct {
    uint8_t enable_map_back : 1;
    uint8_t lock : 1;
    uint8_t none : 6;
} __attribute__((packed)) rx_status;
typedef struct {
    rx_status s;
    /*
     * todo: 添加自己自定义的接收数据
     */
    float data[8];
} __attribute__((packed)) custom_rx_frame;
typedef struct {
    frame_header frame_head;
    uint16_t cmd_id;
    uint8_t data[64 - sizeof(frame_header) - sizeof(uint16_t) - sizeof(uint16_t)];
    uint16_t crc16;
    uint8_t none[68];
} __attribute__((packed)) receive_frame;

typedef enum {
    NONE,
    GOT,
} interact_status;

typedef struct {
    custom_rx_frame custom_frame_rx;
    receive_frame rx_frame;

    custom_tx_frame custom_frame_tx;
    trans_frame tx_frame;

    SuperUart uartPlus;
    interact_status status;
} Interact;

void interact_init(Interact* self, UART_HandleTypeDef* huart);
void interact_write(Interact* self);
void interact_get_feedback(Interact* self);
void interact_send(Interact* self);
void interact_start_receive(Interact* self);

#endif //SUBBOARD_INTERACT_H
