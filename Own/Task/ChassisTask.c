//
// Created by Administrator on 25-2-14.
//
#include "OwnTask.h"

void ChassisTask(void const* argument) {
    while (1) {
        /*
         * todo: 用户这里得根据接收到的数据帧解析后进行转发
         */
        // 瓴控电机必须要发送才能有回报帧
        can_send_data(&can1_plus, LK_FOC.TX_LOW_ID,0,0,0,0);
        can_send_data(&can2_plus, M3508_FOC.TX_LOW_ID,0,0,0,0);
        osDelay(1);
    }
}