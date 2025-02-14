//
// Created by Administrator on 25-2-14.
//
#include "Interact/Interact.h"
#include "Motor/lkMotor.h"
#include "Motor/M3508.h"
#include "RGBLED/RGBLED.h"

RgbLed rgb_led;

SuperCan can1_plus;
SuperCan can2_plus;
SuperCan can3_plus;

lkMotorBoard lk_motor_board[4];
M3508 m3508[4];
M3508 test_moto;
Interact interact;
Interact test;