//
// Created by Administrator on 24-10-3.
//

#include "OwnTask.h"


void HAL_UART_RxCpltCallback(UART_HandleTypeDef* huart) {
    UNUSED(huart);
#if USING_UART_IT

    auto& serial = liaohy::serial;

    if (huart == serial.uart) {
        //    liaohy::serial.println("Hello, World!");
        serial.tx_buffer = serial.rx_buffer->read(reinterpret_cast<uint16_t&>(serial.len));
        serial.print();
        //    uint8_t ch[15] = {0};
        //    HAL_UART_Receive_IT(&huart1, (uint8_t *) ch, 15);

        serial.read_it(15);
        //        HAL_UART_Receive_IT(serial.uart, serial.rx_buffer->next(15)->data, 15);
    }

#endif
}

int16_t x, y;
static uint8_t cnt = 0;
extern uint8_t cmd;
void HAL_UARTEx_RxEventCallback(UART_HandleTypeDef* huart, uint16_t Size) {
    UNUSED(Size);
#if USING_UART_IDLE
//    BaseType_t xHigherPriorityTaskWoken = pdFALSE;
//    if (huart == interact.remote_control.uartPlus.uart) {
//        interact.remote_control.update();
//        if (cnt++ > 5) {
//            xEventGroupSetBitsFromISR(osEventGroup, REMOTE_CONTROL_START_EVENT, &xHigherPriorityTaskWoken);
//            portYIELD_FROM_ISR(xHigherPriorityTaskWoken);
//        }
//    } else if (huart == interact.image_trans.uartPlus.uart) {
//
//        interact.image_trans.update();
//			xHigherPriorityTaskWoken = pdTRUE;
//				portYIELD_FROM_ISR(xHigherPriorityTaskWoken);
//    }
#endif
}
