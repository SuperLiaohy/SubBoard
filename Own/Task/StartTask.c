//
// Created by Administrator on 25-2-14.
//
#include "OwnTask.h"
/*
 * 优先级最高的任务，用于初始化所有设备，初始化完成后删除自己，然后执行其他任务
 */
void StartDefaultTask(void const* argument) {
    /*
     * 外设的初始化
     */
    // 初始化CAN
    can_init(&can1_plus, &hfdcan1);
    can_init(&can2_plus, &hfdcan2);
    can_init(&can3_plus, &hfdcan3);

    // 配置can的滤波器 这里统一不滤波
    can_filter_config(&can1_plus, 0, MASK, 0, 0);
    can_filter_config(&can2_plus, 1, MASK, 0, 0);

    // 启动can
    can_start(&can1_plus);  // 瓴控电机在can1上
    can_start(&can2_plus);  // M3508电机在can2上

    // 初始化rgb灯
    rgb_init(&rgb_led, &hspi6);

    // 初始化电机参数
    // lk_motor_board 参数1为电机编号，参数2为电机的can发送id，参数3为电机的can接收id，参数4为电机的电机的can返回角度数据的精度
    lk_motor_board_init(&lk_motor_board[0], 1, LK_FOC.RX_ID + 1, 65536/4); // 65536/4 应该是这个数，不太记得了
    lk_motor_board_init(&lk_motor_board[1], 2, LK_FOC.RX_ID + 2, 65536/4);
    lk_motor_board_init(&lk_motor_board[2], 3, LK_FOC.RX_ID + 3, 65536/4);
    lk_motor_board_init(&lk_motor_board[3], 4, LK_FOC.RX_ID + 4, 65536/4);
    // M3508 参数1为电机编号，参数2为电机的can发送id，参数3为电机的can接收id，参数4为电机的电机的can返回角度数据的精度，参数5为电机的电机的减速比
    m3508_init(&m3508[0], 1, M3508_FOC.RX_ID + 1, 8192,19.2f);
    m3508_init(&m3508[1], 2, M3508_FOC.RX_ID + 2, 8192,19.2f);
    m3508_init(&m3508[2], 3, M3508_FOC.RX_ID + 3, 8192,19.2f);
    m3508_init(&m3508[3], 4, M3508_FOC.RX_ID + 4, 8192,19.2f);

    // 初始化用户交互系统
    interact_init(&interact, &huart2);

    /*
     * 这里可以加入信号量或者事件集进行等待，
     * 等待接收到大疆的3508电机数据再删除自身（通过再can回调里使用信号量或者事件集来判断）。
     * 保障数据安全执行
     * 如果想要等待瓴控电机数据，必选要先给瓴控电机发送数据，这样瓴控电机才会返回数据，can才能接收到数据
     */

    vTaskDelete(NULL);
}