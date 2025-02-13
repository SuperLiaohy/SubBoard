/*
 * @Author: SuperLiaohy liaohy123@outlook.com
 * @LastEditors: SuperLiaohy liaohy123@outlook.com
 * @LastEditTime: 2024-11-24 15:21:52
 * @FilePath: /DM/Own/App/Motor/lkMotor.h
 * @Description: 
 * Copyright (c) 2024 by ${git_name} email: ${git_email}, All Rights Reserved.
 */

#ifndef DM_42_LKMOTOR_H
#define DM_42_LKMOTOR_H

#define USING_LKMOTOR 1
#if USING_LKMOTOR == 1

    #include "FeedBack.h"
    #ifdef __cplusplus
extern "C" {
    #endif

    #include "string.h"

    #ifdef __cplusplus
}
    #endif

typedef struct {
    FeedBack feed_back;

    uint16_t tx_id;

    //    PID pid;

    //    Detect detect;

} lkMotorBoard;

void lk_motor_board_init(lkMotorBoard* self, uint16_t tx_id, uint16_t rx_id, uint32_t precision_range);
void lk_motor_board_read_pdata(lkMotorBoard* self, uint8_t* data);

extern lkMotorBoard test_motor;

#endif //USING_LKMOTOR
#endif //DM_42_LKMOTOR_H
