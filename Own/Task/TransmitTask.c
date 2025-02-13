//
// Created by Administrator on 25-2-14.
//
#include "OwnTask.h"

void TransmitTask(void const* argument) {
    while (1) {
        vTaskSuspend(NULL);
        /*
         * todo: 实现写自定义的发送数据帧函数
         */
//        interact_write(&interact);
        interact_send(&interact); //send只有发送数据的功能，不包括写数据帧，写数据帧，用户要实现write函数
    }
}