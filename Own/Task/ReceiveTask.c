//
// Created by Administrator on 25-2-14.
//

#include "OwnTask.h"
uint32_t cnt_t;
void ReceiveTask(void const* argument) {
    test.tx_frame.frame_head.sof = 0xA5;
    test.tx_frame.frame_head.data_length = 60;
    test.tx_frame.frame_head.crc8 = 0x20;
    test.tx_frame.cmd_id = 0x0007;
	uint8_t a = 6;  
  memset(test.tx_frame.data, a, sizeof(test.tx_frame.data));
//    memcpy(test.tx_frame.data, &test.custom_frame_tx, sizeof(test.custom_frame_tx));
    test.tx_frame.crc16 = 0xF099;
	
    while (1) {
        uint32_t now = xTaskGetTickCount();
				memset(test.tx_frame.data, ++a, sizeof(test.tx_frame.data));
        interact_send(&test);
			++cnt_t;
        osDelayUntil(&now,1);
    }
}
