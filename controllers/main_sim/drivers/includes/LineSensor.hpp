#include <webots/Supervisor.hpp>
#include <webots/DistanceSensor.hpp>
#include <string>
#include <cstdint>

#ifndef __LINE_SENSOR_H__
#define __LINE_SENSOR_H__

using namespace webots;

class LineSensor {
private:
    DistanceSensor* sensorElementLeft;
    DistanceSensor* sensorElementCenter;
    DistanceSensor* sensorElementRight;
public:
    LineSensor(
        Supervisor* supervisor,
        std::string sensorNameLeft,
        std::string sensorNameCenter,
        std::string sensorNameRight,
        int timeStep
    );
    ~LineSensor();
    static LineSensor* _instance;
    static LineSensor* getInstance(
        Supervisor* supervisor,
        std::string sensorNameLeft,
        std::string sensorNameCenter,
        std::string sensorNameRight,
        int timeStep
    );
    void getLineValue(int* left, int* center, int* right);
};

#endif
