////
//// Created by lhy on 2024/9/17.
////
//
//#ifndef NEW_PRJ_DETECT_H
//#define NEW_PRJ_DETECT_H
//
//#ifdef __cplusplus
//extern "C" {
//#endif
//#include "stdint.h"
//#include "stm32h7xx_hal.h"
//#ifdef __cplusplus
//}
//#endif
//
///*
// * 本来我打算不耦合的，使用虚函数解耦的，但是发现这样的话，都通过虚函数调用，会增加一定的时间开销
// * 所以我在这里用了stm32的HAL库，直接调用HAL_GetTick()函数，这样就不用通过虚函数调用了
// * 但是这样耦合了stm32的库很不好，所以我打算在后面的版本中，想办法改进
// */
//#include "DetectManager.h"
//
//class DetectManager;
//
//typedef void (*Fun)();
//
//class Detect {
//public:
//    Detect(uint32_t maxInterval);
//
//    ~Detect();
//
//    static DetectManager detectManager;
//
//    void init(Fun lostFun, Fun recoverFun) {
//        this->lostFun = lostFun;
//        this->recoverFun = recoverFun;
//    }
//
//    void update();
//
//    void JudgeLost();
//
//    uint8_t isLost; //标记是否已丢失
//
//    Fun lostFun;//掉线处理函数
//    Fun recoverFun;//恢复连接处理函数
//protected:
//    uint32_t maxInterval; //收到数据的最大间隔时间，超过则认为断开
//    uint32_t lastReceiveTime; //记录到的上次收到数据的时间
//
//    static uint32_t getSysTime() {
//        return HAL_GetTick();
//    }
//
//};
//
//#endif //NEW_PRJ_DETECT_H
