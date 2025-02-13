//
// Created by liaohy on 9/5/24.
//

#ifndef NONE_PRJ_SUPERCAN_H
#define NONE_PRJ_SUPERCAN_H


#ifdef __cplusplus
extern "C" {
#endif

#include "fdcan.h"

#ifdef __cplusplus
}
#endif


typedef enum {
    RANGE,
    MASK,
    LIST,
} filter_mode;

typedef struct {
    FDCAN_HandleTypeDef *hcan;

    FDCAN_TxHeaderTypeDef tx_header;
    FDCAN_RxHeaderTypeDef rx_header;

    uint8_t tx_data[8];
    uint8_t rx_data[8];
} SuperCan;

void can_init(SuperCan *self, FDCAN_HandleTypeDef *hcan);
void can_filter_config(SuperCan *self, uint16_t filter_number, filter_mode filterMode, uint32_t reg_1, uint32_t reg_2);
void can_start(SuperCan *self);
void can_send_pdata(SuperCan *self, uint32_t id, uint8_t *data);
void can_send_data(SuperCan *self, uint32_t id, int16_t data1, int16_t data2, int16_t data3, int16_t data4);
void can_receive(SuperCan *self);
void can_receive_data(SuperCan *self, uint8_t *data);

extern SuperCan canPlus1;
extern SuperCan canPlus2;
extern SuperCan canPlus3;

#endif //NONE_PRJ_SUPERCAN_H
