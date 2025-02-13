//
// Created by lhy on 2024/9/9.
//

#include "M3508.h"

#if USING_M3508 == 1

void m3508_init(M3508* self, uint16_t tx_id, uint16_t rx_id, float gain) {
    self->tx_id           = tx_id;
    self->feed_back.rx_id = rx_id;
    self->gain            = gain;
}

void m3508_read_pdata(M3508* self, uint8_t* data) {
    self->feed_back.Data.lastPosition = self->feed_back.Data.position;

    self->feed_back.RawData.position    = (int16_t)(((data[0] << 8) | data[1]));
    self->feed_back.RawData.speed       = (int16_t)((data[2] << 8) | data[3]);
    self->feed_back.RawData.current     = (int16_t)((data[4] << 8) | data[5]);
    self->feed_back.RawData.temperature = (data[6]);

    self->feed_back.Data.position    = (float)(self->feed_back.RawData.position) * 360.0f / self->feed_back.precision_range;
    self->feed_back.Data.speed       = self->feed_back.RawData.speed;
    self->feed_back.Data.current     = self->feed_back.RawData.current;
    self->feed_back.Data.temperature = self->feed_back.RawData.temperature;

    float dPos = self->feed_back.Data.position - self->feed_back.Data.lastPosition;
    if (dPos > 180) {
        dPos = dPos - 360;
    } else if (dPos < -180) {
        dPos = dPos + 360;
    }
    self->feed_back.totalPosition += (dPos / self->gain);
}

#endif //USING_M3508
