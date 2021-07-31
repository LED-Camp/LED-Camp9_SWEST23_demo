#include "includes/RangeSensor.hpp"
#include <webots/Supervisor.hpp>
#include <webots/DistanceSensor.hpp>
#include <cstdint>

using namespace webots;

RangeSensor* RangeSensor::_instance = 0;

RangeSensor::RangeSensor(Supervisor* supervisor, std::string sensorName, int timeStep){
    this->sensorElement = supervisor->getDistanceSensor(sensorName);
    this->sensorElement->enable(timeStep);
}

RangeSensor::~RangeSensor(){
}

RangeSensor* RangeSensor::getInstance(Supervisor* supervisor, std::string sensorName, int timeStep){
  if(_instance == 0){
    _instance = new RangeSensor(supervisor, sensorName, timeStep);
  }
  return _instance;
}

float RangeSensor::getRange(){
    return this->sensorElement->getValue(); // cm
}
