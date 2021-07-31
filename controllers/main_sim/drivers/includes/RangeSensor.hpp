#include <webots/Supervisor.hpp>
#include <webots/DistanceSensor.hpp>
#include <cstdint>

#ifndef __RANGE_SENSOR__
#define __RANGE_SENSOR__

using namespace webots;

class RangeSensor {
private:
    DistanceSensor* sensorElement;
public:
    RangeSensor(Supervisor* supervisor, std::string sensorName, int timeStep);
    ~RangeSensor();
    static RangeSensor* _instance;
    static RangeSensor* getInstance(Supervisor* supervisor, std::string sensorName, int timeStep);
    float getRange();
};

#endif //__RANGE_SENSOR__
