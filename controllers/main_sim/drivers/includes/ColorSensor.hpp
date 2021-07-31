#include <webots/Supervisor.hpp>
#include <webots/DistanceSensor.hpp>
#include <webots/Camera.hpp>
#include <cstdint>

#ifndef __COLOER_SENSOR__
#define __COLOER_SENSOR__

using namespace webots;

class ColorSensor {
private:
    Camera* sensorElement;
public:
    ColorSensor(Supervisor* supervisor, std::string sensorName, int timeStep);
    ~ColorSensor();
    static ColorSensor* _instance;
    static ColorSensor* getInstance(Supervisor* supervisor, std::string sensorName, int timeStep);
    void Initialize();
    typedef struct {unsigned int red, green, blue;} ColorValue;
    ColorSensor::ColorValue getColorValue();
};


#endif //__COLOR_SENSOR__
