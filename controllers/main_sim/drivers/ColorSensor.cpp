#include "includes/ColorSensor.hpp"
#include <webots/Supervisor.hpp>
#include <webots/DistanceSensor.hpp>
#include <webots/Camera.hpp>
#include <cstdint>

using namespace webots;
ColorSensor* ColorSensor::_instance = 0;

ColorSensor::ColorSensor(Supervisor* supervisor, std::string sensorName, int timeStep) {
    this->sensorElement = supervisor->getCamera(sensorName);
    this->sensorElement->enable(timeStep);
}

ColorSensor::~ColorSensor() {

}

ColorSensor* ColorSensor::getInstance(Supervisor* supervisor, std::string sensorName, int timeStep) {
    if (_instance == 0) {
        _instance = new ColorSensor(supervisor, sensorName, timeStep);
    }

    return _instance;
}

ColorSensor::ColorValue ColorSensor::getColorValue() {
    const unsigned char *image = this->sensorElement->getImage();
    return (ColorSensor::ColorValue){
        (unsigned int)(this->sensorElement->imageGetRed(image, 0,0,0)) ,
        (unsigned int)(this->sensorElement->imageGetGreen(image, 0,0,0)) ,
        (unsigned int)(this->sensorElement->imageGetBlue(image, 0,0,0)) 
    };
}
