////
//// Created by liaohy on 9/5/24.
////
//
//#include "pid.h"
//
//
//float PID::update(float _target, float input) {
//    if (this->target != _target) {
//        this->target = _target;
////			item.i = 0;
//    }
//
//    item.p = target - input;
//    item.i += item.p;
//    float sum = item.i * para.i;
//    if (sum > Max.i) {
//        sum = Max.i;
//    } else if (sum < -Max.i) {
//        sum = -Max.i;
//    }
//
//    item.d = item.p - item.p_last;
//
//    item.p_last = item.p;
//    auto temp = para.p * item.p + sum + para.d * item.d;
//    if (temp > Max.output) {
//        output = Max.output;
//    } else if (temp < -Max.output) {
//        output = -Max.output;
//    } else {
//        output = temp;
//    }
//    return output;
//}
//
//
