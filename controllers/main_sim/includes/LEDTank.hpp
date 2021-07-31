#ifndef __LEDTank__
#define __LEDTank__

#include "includes/Controller.hpp"

#define _STATE_INITIAL 0x00000000
#define STATE_FORWARD ((unsigned long)1)
#define STATE_INIT ((unsigned long)2)
#define STATE_STOP ((unsigned long)3)
#define STATE_LEFT ((unsigned long)4)
#define STATE_RIGHT ((unsigned long)5)
#define STATE_BACKWARD ((unsigned long)6)
class PreController;

class LEDTank{
public:
    LEDTank(Controller *controller);
    void execState();
    void doTransition(unsigned long event);
    bool clockForward();
    unsigned long _state;

 private:
    Controller *controller;
    unsigned long _beforeState;
    unsigned long state;
    float distance;
    float angle;
    float rangeDistance;
};
#endif
