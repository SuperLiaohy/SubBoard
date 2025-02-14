//
// Created by Administrator on 25-2-14.
//
#include "OwnTask.h"


void delayMicroseconds(uint32_t us)
{
#if defined(DWT_BASE) && !defined(DWT_DELAY_DISABLED)
  int32_t start  = dwt_getCycles();
  int32_t cycles = us * (SystemCoreClock / 1000000);

  while ((int32_t)dwt_getCycles() - start < cycles);
#endif
}
void TransmitTask(void const* argument) {
    interact.tx_frame.frame_head.sof = 0xE5;
    interact.tx_frame.frame_head.data_length = 50;
    interact.tx_frame.frame_head.crc8 = 0x21;
    interact.tx_frame.cmd_id = 0x0006;
    uint8_t a = 66;
    memset(interact.tx_frame.data, a, sizeof(interact.tx_frame.data));
    //    memcpy(test.tx_frame.data, &test.custom_frame_tx, sizeof(test.custom_frame_tx));
    interact.tx_frame.crc16 = 0xE099;
    while (1) {
        vTaskSuspend(NULL);
        /*
         * todo: 实现写自定义的发送数据帧函数
         */

        //send只有发送数据的功能，不包括写数据帧，写数据帧，用户要实现write函数
    }
}