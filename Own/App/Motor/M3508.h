//
// Created by lhy on 2024/9/9.
//

#ifndef NONE_PRJ_M3508_H
#define NONE_PRJ_M3508_H

#define USING_M3508 1
#if USING_M3508 == 1

    #include "FeedBack.h"

typedef struct {
    uint16_t tx_id;

    FeedBack feed_back;

    float gain;

    //    PID pid;

    //    Detect detect;
} M3508;

void m3508_init(M3508* self, uint16_t tx_id, uint16_t rx_id, uint32_t precision_range, float gain);
void m3508_read_pdata(M3508* self, uint8_t* data);

#endif //USING_M3508
#endif //NONE_PRJ_M3508_H
