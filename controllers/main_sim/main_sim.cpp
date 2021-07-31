#include <iostream>
#ifdef SIM_USE
#include <webots/Supervisor.hpp>
#include <webots/DistanceSensor.hpp>
#include "includes/Event.hpp"
#include "includes/Controller.hpp"
#include "includes/LEDTank.hpp"
#else
#include <sys/time.h>
#include <time.h>
#include "wiringPi.h"
#include "Event.h"
#include "Controller.h"
#include "LEDTank.h"
#endif

using namespace webots;

#ifdef SIM_USE
/**
 * sim用main
 */
int main(int argc, char **argv) {
  Controller *controller;
  LEDTank *lEDTank;
  Event *event;

  controller = Controller::getInstance();
  lEDTank = new LEDTank(controller);
  event = new Event(controller);

  #ifdef EXPERIMENTAL_USE
    printf("Experimental use mode; w:↑, a:←, s:↓, d:→\n");
  #endif
  while (controller->clockForward()) {
    if(event->updateEvent() < 0 || controller->timeUp(COMPETITION_TIME)){
        printf("STOP\n");
        controller->changeDriveMode(STOP, 0);
        controller->clockForward();
        break;
     }
    lEDTank->execState();
    lEDTank->doTransition(event->getEvent());
  };
  controller->stopSimuration();
  delete lEDTank;
  delete event;
  return 0;
}

#else
/**
 * 実機用main
 */
int main(void){
  struct timeval now;
  struct timeval old;

  Controller *controller;
  Event *event;

  LEDTank *lEDTank;

  if( wiringPiSetupGpio() < 0){ //initialize failed
    return 1;
  }

#ifdef EXPERIMENTAL_USE
    printf("Experimental use mode; w:↑, a:←, s:↓, d:→\n");
#endif

  controller = Controller::getInstance();
  lEDTank = new LEDTank(controller);
  event = new Event(controller);
  gettimeofday(&now, NULL);
  gettimeofday(&old, NULL);

  while(true){
    while((now.tv_sec - old.tv_sec) + (now.tv_usec - old.tv_usec)*1.0E-6  < 0.05F){
      gettimeofday(&now, NULL);
    }
    old = now;
    if(event->updateEvent() < 0){
        printf("STOP\n");
        controller->changeDriveMode(STOP, 0);
        break;
     }



#ifdef EXPERIMENTAL_USE
    lEDTank->execState_for_experiment();
    lEDTank->doTransition_for_experiment(event->getEvent());

#else
    lEDTank->execState();
    lEDTank->doTransition(event->getEvent());

#endif
  }
  gettimeofday(&now, NULL);
  gettimeofday(&old, NULL);

  while((now.tv_sec - old.tv_sec) + (now.tv_usec - old.tv_usec)*1.0E-6  < 0.05F){
    gettimeofday(&now, NULL);
  }
  getch();
  delete lEDTank;
  delete event;
}
#endif
