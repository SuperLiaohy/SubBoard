//
// Created by Administrator on 24-10-3.
//

#include "CAN/SuperCan.h"


#ifdef __cplusplus
extern "C" {
#endif
#include "FreeRTOS.h"
#include "cmsis_os.h"

#ifdef __cplusplus
}
#endif


extern float yaw;
float relative_position = 0;
float GM6020pos = 0;
float lkMotorSpeed = 0;
float dmMotorSpeed = 0;
float dmMotorPos = 0;
float a =0;
void HAL_FDCAN_RxFifo0Callback(FDCAN_HandleTypeDef *hfdcan, uint32_t RxFifo0ITs) {
    UNUSED(RxFifo0ITs);

}
