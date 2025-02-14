//
// Created by lhy on 2024/9/9.
//

#ifndef NONE_PRJ_MOTOR_H
#define NONE_PRJ_MOTOR_H

#include "CAN/SuperCan.h"
#include "Detect/Detect.h"
#include "Pid/DoublePid.h"

typedef struct {
    uint16_t RX_ID;
    uint16_t TX_LOW_ID;
    uint16_t TX_HIGH_ID;
} FOC;

static const FOC LK_FOC    = {0x140, 0x280, 0x280};
static const FOC M3508_FOC = {0x200, 0x200, 0x1FF};
static const FOC GM6020_FOC = {0x204, 0x1FF,0x2FF};
typedef struct {
    uint16_t rx_id;
    uint32_t precision_range;

    struct {
        uint16_t position;
        int16_t speed;
        int16_t current;
        int16_t temperature;
    } RawData;

    struct {
        float position;
        float speed;
        float current;
        float temperature;
        float lastPosition;
    } Data;

    float totalPosition;
} FeedBack;

static void feedback_init(FeedBack* self, uint16_t id, uint32_t precision_range) {
    self->rx_id           = id;
    self->precision_range = precision_range;
};

#endif //NONE_PRJ_MOTOR_H
