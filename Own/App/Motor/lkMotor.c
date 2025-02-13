//
// Created by Administrator on 24-10-22.
//

#include "lkMotor.h"

#if USING_LKMOTOR == 1

void lk_motor_board_init(lkMotorBoard* self, uint16_t tx_id, uint8_t rx_id) {
    self->tx_id           = tx_id;
    self->feed_back.rx_id = rx_id;
}

void lk_motor_board_read_pdata(lkMotorBoard* self, uint8_t* data) {
    self->feed_back.Data.lastPosition = self->feed_back.Data.position;

    self->feed_back.RawData.temperature = data[1];
    self->feed_back.RawData.current     = *(int16_t*)(&data[2]);
    self->feed_back.RawData.speed       = *(int16_t*)(&data[4]);
    self->feed_back.RawData.position    = *(int16_t*)(&data[6]);

    self->feed_back.Data.position    = self->feed_back.RawData.position * 360.0 / self->feed_back.precision_range;
    self->feed_back.Data.speed       = self->feed_back.RawData.speed;
    self->feed_back.Data.current     = self->feed_back.RawData.current * 32.f / 2000.f;
    self->feed_back.Data.temperature = self->feed_back.RawData.temperature;

    float dPos = self->feed_back.Data.position - self->feed_back.Data.lastPosition;
    if (dPos > 180) {
        dPos = dPos - 360;
    } else if (dPos < -180) {
        dPos = dPos + 360;
    }
    self->feed_back.totalPosition += dPos;
}

#endif //USING_LKMOTOR
