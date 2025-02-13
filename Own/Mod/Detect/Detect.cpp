////
//// Created by lhy on 2024/9/17.
////
//
//#include "Detect.h"
//
//
//
//Detect::~Detect() {
//    detectManager.Unregister(this);
//}
//
//Detect::Detect(const uint32_t maxInterval)
//        : maxInterval(maxInterval),
//          lastReceiveTime(0),
//          isLost(false) {
//    lostFun = nullptr;
//    recoverFun = nullptr;
//    detectManager.Register(this);
//}
//
//void Detect::update() {
//    lastReceiveTime = getSysTime();
//}
//
//void Detect::JudgeLost() {
//    uint32_t presentTime = getSysTime();
//    if (presentTime - lastReceiveTime > maxInterval) {
//        if (!isLost) {
//            if (lostFun != nullptr)
//                lostFun();
//            isLost = 1;
//        }
//    } else {
//        if (isLost) {
//            if (recoverFun != nullptr)
//                recoverFun();
//            isLost = 0;
//        }
//    }
//}
//
//
//
