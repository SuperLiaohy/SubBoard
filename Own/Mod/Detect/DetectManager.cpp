////
//// Created by lhy on 2024/9/17.
////
//
//#include "DetectManager.h"
//
//
//void DetectManager::Register(Detect *detect) {
//    detects.push_back(detect);
//}
//
//void DetectManager::Unregister(Detect *detect) {
//#ifdef USE_HAL_SELF_LIST
//    detects.remove(detect);
//#else
//    detects.erase(std::remove(detects.begin(), detects.end(), detect), detects.end());
//#endif
//}
//
//void DetectManager::JudgeLost() {
//    for (auto detect: detects) {
//        detect->JudgeLost();
//    }
//}
//
//
