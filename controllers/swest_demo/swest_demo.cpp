// File:          swest_demo.cpp
// Date:
// Description:
// Author:
// Modifications:

// You may need to add webots include files such as
// <webots/DistanceSensor.hpp>, <webots/Motor.hpp>, etc.
// and/or to add some other includes
#include <webots/Robot.hpp>
#include <webots/Motor.hpp>
#include <webots/Keyboard.hpp>

// All the webots classes are defined in the "webots" namespace
using namespace webots;

// This is the main program of your controller.
// It creates an instance of your Robot instance, launches its
// function(s) and destroys it at the end of the execution.
// Note that only one instance of Robot should be created in
// a controller program.
// The arguments of the main function can be specified by the
// "controllerArgs" field of the Robot node
int main(int argc, char **argv) {
  // create the Robot instance.
  Robot *robot = new Robot();
  Motor *motorL = robot->getMotor("motorL");
  motorL->setPosition(INFINITY);
  Motor *motorR = robot->getMotor("motorR");
  motorR->setPosition(INFINITY);
  motorL->setVelocity(0);
  motorR->setVelocity(0);

  Keyboard keyboard = Keyboard();
  keyboard.enable(100);

  // get the time step of the current world.
  int timeStep = (int)robot->getBasicTimeStep();

  // You should insert a getDevice-like function in order to get the
  // instance of a device of the robot. Something like:
  //  Motor *motor = robot->getMotor("motorname");
  //  DistanceSensor *ds = robot->getDistanceSensor("dsname");
  //  ds->enable(timeStep);

  // Main loop:
  // - perform simulation steps until Webots is stopping the controller
  while (robot->step(timeStep) != -1) {
    int key = keyboard.getKey();
    switch(key){
      case 'W':
        motorL->setVelocity(50);
        motorR->setVelocity(50);
        break;
      case 'A':
        motorL->setVelocity(-25);
        motorR->setVelocity(25);
        break;
      case 'S':
        motorL->setVelocity(-50);
        motorR->setVelocity(-50);
        break;
      case 'D':
        motorL->setVelocity(25);
        motorR->setVelocity(-25);
        break;
      case 'E':
        motorL->setVelocity(0);
        motorR->setVelocity(0);
        break;
      default:
      break;
    }
  };

  // Enter here exit cleanup code.

  delete robot;
  return 0;
}
