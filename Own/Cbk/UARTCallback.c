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
uint32_t cnt_uart2 = 0;
uint32_t cnt_uart3 = 0;
extern uint8_t cmd;
void us_delay(uint32_t us);
void HAL_UARTEx_RxEventCallback(UART_HandleTypeDef* huart, uint16_t Size) {
    UNUSED(Size);
#if USING_UART_IDLE
    if (huart == interact.uartPlus.uart) {
        if (interact.rx_frame.frame_head.sof == 0xA5) {
            // 注意解析是通过memcpy的方式，要保证数据发过来时也是通过memcpy的方式，要不然数据大小端可能不太一样
            interact_get_feedback(&interact);
					++cnt_uart2;
        interact_send(&interact);

            xTaskResumeFromISR(TRANSMIT_TASKHandle);
        }
        // 开启下一次接收放在了USART2_IRQHandler里
    } else if (huart == test.uartPlus.uart) {
			++cnt_uart3;            interact.status = 1-interact.status;

        // 注意解析是通过memcpy的方式，要保证数据发过来时也是通过memcpy的方式，要不然数据大小端可能不太一样
//        interact_get_feedback(&test);
//        interact.status = GOT;
//        xTaskResumeFromISR(TRANSMIT_TASKHandle);
        // 开启下一次接收放在了USART3_IRQHandler里
    }
#endif
}
