#ifndef __EVENT_H__
#define __EVENT_H__

#include <cstdint>
#include <webots/Keyboard.hpp> //キー受け付け; シミュレータ
#include "includes/CommonDefine.hpp"
#include "drivers/includes/ColorSensor.hpp"
#include <string>

class Controller;
using namespace webots;

#define E_UP ((unsigned long)0x00000001)
#define E_DOWN ((unsigned long)0x00000002)
#define E_LEFT ((unsigned long)0x00000004)
#define E_RIGHT ((unsigned long)0x00000008)
#define E_CHANGE_DISTANCE ((unsigned long)0x00000010)
#define E_CHANGE_ANGLE ((unsigned long)0x00000020)
#define E_CHANGE_RANGING ((unsigned long)0x00000040)
#define E_CHANGE_AREA ((unsigned long)0x0000080)
#define E_CHANGE_COLOR ((unsigned long)0x00000100)
#define E_TRUE ((unsigned long)0xFFFFFFFF)
#define E_FALSE ((unsigned long)0x00000000)


//extern int kbhit(void);
//extern char getch(void);

class Event {
 public:
    Event(Controller* controller);
    int updateEvent();
    unsigned long getEvent();

private:
    Controller* controller;
    Keyboard keyboard;
    int oldKey;
    float rangeDistanceOld;
    unsigned long event;
    float distanceOld;
    float angleOld;
    ColorSensor::ColorValue colorOld;
    int lineLeftOld;
    int lineCenterOld;
    int lineRightOld;
};

#endif
