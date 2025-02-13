//
// Created by Administrator on 25-2-14.
//

#ifndef SUBBOARD_OWNTASK_H
#define SUBBOARD_OWNTASK_H

#include "FreeRTOS.h"
#include "cmsis_os.h"
#include "stm32h7xx_hal.h"
#include "task.h"

#include "Interact/Interact.h"
#include "Motor/lkMotor.h"
#include "Motor/M3508.h"
#include "RGBLED/RGBLED.h"

extern osThreadId defaultTaskHandle;
extern osThreadId CHASSIS_TASKHandle;
extern osThreadId RECEIVE_TASKHandle;
extern osThreadId DETECT_TASKHandle;
extern osThreadId TRANSMIT_TASKHandle;
extern osThreadId LED_TASKHandle;

extern RgbLed rgb_led;
extern SuperCan can1_plus;
extern SuperCan can2_plus;
extern SuperCan can3_plus;
extern lkMotorBoard lk_motor_board[4];
extern M3508 m3508[4];
extern Interact interact;

void StartDefaultTask(void const* argument);
void ChassisTask(void const* argument);
void ReceiveTask(void const* argument);
void TransmitTask(void const* argument);
void LedTask(void const* argument);
void DetectTask(void const* argument);

#endif //SUBBOARD_OWNTASK_H
