////
//// Created by liaohy on 9/5/24.
////
//
//#ifndef NONE_PRJ_PID_H
//#define NONE_PRJ_PID_H
//
//struct pid_cfg {
//    float p;
//    float i;
//    float d;
//    float maxI;
//    float maxOut;
//    float dead_zone;
//
//    constexpr pid_cfg(float p, float i, float d, float maxI, float maxOut, float dead_zone = 0)
//        : p(p), i(i), d(d), maxI(maxI), maxOut(maxOut), dead_zone(dead_zone) {}
//
//    constexpr pid_cfg(const pid_cfg& cfg) = default;
//};
//
//class PID {
//public:
//    PID() = default;
//
//    PID(float p, float i, float d, float maxI, float maxOut, float dead_zone = 0)
//            : para{p, i, d},
//              item{0, 0, 0, 0},
//              Max{maxI, maxOut},
//              output(0),
//              dead_zone(dead_zone),
//              target(0) {}
//    PID(const pid_cfg &cfg)
//            : para{cfg.p, cfg.i, cfg.d},
//              item{0, 0, 0, 0},
//              Max{cfg.maxI, cfg.maxOut},
//              output(0),
//              dead_zone(cfg.dead_zone),
//              target(0) {}
//
//    struct {
//        float p;
//        float i;
//        float d;
//    } para{};
//
//    struct {
//        float p;
//        float p_last;
//        float i;
//        float d;
//    } item{};
//
//    struct {
//        float i;
//        float output;
//    } Max;
//
//    float output;
//    float dead_zone;
//    float target;
//
//    virtual float update(float _target, float input);
//
//    float update(float input) {
//        return update(target, input);
//    }
//
//    void set(float p, float i, float d, float maxI, float maxOut) {
//        this->para.p = p;
//        this->para.i = i;
//        this->para.d = d;
//        this->Max.i = maxI;
//        this->Max.output = maxOut;
//    }
//
//    void clear() {
//        item.p = 0;
//        item.p_last = 0;
//        item.i = 0;
//        output = 0;
//    }
//
//};
//
//
//#endif //NONE_PRJ_PID_H
