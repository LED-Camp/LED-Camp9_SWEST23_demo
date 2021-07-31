#include "includes/Position.hpp"
#include <stdio.h>
#include "includes/UserDefine.hpp"
#include "../includes/CommonDefine.hpp"
using namespace webots;

static float referPositionL;
static float referPositionR;

/*******************************************/
Position* Position::_instance = 0;

Position* Position::getInstance(Supervisor* supervisor, std::string psNameL, std::string psNameR) {
    if (_instance == 0) {
        _instance = new Position(supervisor, psNameL, psNameR);
    }

    return _instance;
}



Position::Position(Supervisor* supervisor, std::string psNameL, std::string psNameR) {
    this->positionSensorL = supervisor->getPositionSensor(psNameL);
    positionSensorL->enable(TIME_STEP);
    this->positionSensorR = supervisor->getPositionSensor(psNameR);
    positionSensorR->enable(TIME_STEP);
}

void Position::reset(void) {
    referPositionL  = positionSensorL->getValue();
    referPositionR  = positionSensorR->getValue();
}

void Position::getPosition(float* distance, float* angle) {
    float l;
    float r;
    float radNowL;
    float radNowR;
    float distanceTemp;

    radNowL = positionSensorL->getValue();
    radNowR = positionSensorR->getValue();
    l = (radNowL - referPositionL) * RADIUS;
    r = (radNowR - referPositionR) * RADIUS;

    distanceTemp = (l + r) / 2.0;
    *angle = (( l - r ) / TREAD) * 180.0 / PI;
    *distance = distanceTemp;
}
