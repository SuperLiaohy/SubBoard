//
// Created by Administrator on 25-2-14.
//

#include "Interact.h"

void interact_init(Interact *self, UART_HandleTypeDef *huart) {
    //初始化can
    uart_init(&self->uartPlus, huart, (uint8_t*)(&self->rx_frame), (uint8_t*)(&self->tx_frame));
    self->status = NONE;
}
void interact_write(Interact* self) {
    /*
     * todo: 拓展函数参数，然后写入custom_frame_tx
     */
//    custom_frame_tx修改
    memcpy(self->tx_frame.data, &self->custom_frame_tx, sizeof(self->custom_frame_tx));
}
void interact_get_feedback(Interact* self) {
    /*
     * todo: 修改custom_frame_rx的数据结构
     */
    memcpy(&self->custom_frame_rx, self->rx_frame.data, sizeof(self->custom_frame_rx));
}
void interact_send(Interact* self) {
    uart_dma_self_send(&self->uartPlus, sizeof(self->tx_frame));
}
void interact_start_receive(Interact* self) {
    uart_dma_idle_receive(&self->uartPlus, sizeof(self->rx_frame));
}

