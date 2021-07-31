#include "includes/Controller.hpp"
#include "drivers/includes/ColorSensor.hpp"
#include "includes/CommonDefine.hpp"
#include <webots/Supervisor.hpp>

using namespace webots;

Controller* Controller::_instance = 0;

Controller* Controller::getInstance() {
    if (_instance == 0) {
        _instance = new Controller();
    }

    return _instance;
}

Controller::Controller() {
    this->supervisor = new Supervisor();
    // 測距センサ初期化
    this->rangeSensor = RangeSensor::getInstance(supervisor, "RangeSensor", TIME_STEP);
    // カラーセンサ初期化
    this->colorSensor = ColorSensor::getInstance(supervisor, "cam", TIME_STEP);
    // ラインセンサ初期化
    this->lineSensor = LineSensor::getInstance(
        supervisor,
        "LineSensorLeft",
        "LineSensorCenter",
        "LineSensorRight",
        TIME_STEP
    );
    // Positionセンサ初期化
    position = Position::getInstance(supervisor, "positionSensorL", "positionSensorR");
    // モータドライバ初期化
    twinWheelDriver = TwinWheelDriver::getInstance(supervisor, "motorL", "motorR");
}

Controller::~Controller(void) {
}

void Controller::positionReset(void) {
    position->reset();
}

void Controller::getPosition(float* distance, float* angle) {
    position->getPosition(distance, angle);
}

void Controller::changeDriveMode(Mode mode, int pwmDuty) {
    this->twinWheelDriver->changeDriveMode(mode, pwmDuty);
}

bool Controller::clockForward() {
    return this->supervisor->step(TIME_STEP) != -1;
}

void Controller::stopSimuration() {
    this->supervisor->simulationSetMode(supervisor->SIMULATION_MODE_PAUSE);
}

bool Controller::timeUp(double limitTime) {
    return this->supervisor->getTime() >= limitTime;
}

float Controller::getRange() {
    return this->rangeSensor->getRange();
}

ColorSensor::ColorValue Controller::getColorValue() {
    return this->colorSensor->getColorValue();
}

void Controller::getLineValue(int* left, int* center, int* right) {
    this->lineSensor->getLineValue(left, center, right);
}
