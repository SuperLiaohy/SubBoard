//
// Created by Administrator on 24-10-3.
//

#include "OwnTask.h"

void HAL_FDCAN_RxFifo0Callback(FDCAN_HandleTypeDef* hfdcan, uint32_t RxFifo0ITs) {
    UNUSED(RxFifo0ITs);
    if (hfdcan == can1_plus.hcan) {
        can_receive(&can1_plus);
			if(can1_plus.rx_header.Identifier == test_moto.feed_back.rx_id) {
				m3508_read_pdata(&test_moto, can1_plus.rx_data);
				return;
			}
        for (int i = 0; i < 4; ++i) {
            if (can1_plus.rx_header.Identifier == lk_motor_board[i].feed_back.rx_id) {
                lk_motor_board_read_pdata(&lk_motor_board[i], can1_plus.rx_data);
                break;
            }
        }
    } else if (hfdcan == can2_plus.hcan) {
        can_receive(&can2_plus);
        for (int i = 0; i < 4; ++i) {
            if (can2_plus.rx_header.Identifier == m3508[i].feed_back.rx_id) {
                m3508_read_pdata(&m3508[i], can2_plus.rx_data);
                break;
            }
        }
    }
}
