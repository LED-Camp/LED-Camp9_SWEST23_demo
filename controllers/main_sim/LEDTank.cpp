#include <stdio.h>
#include "includes/Event.hpp"
#include "includes/LEDTank.hpp"
#include "includes/CommonDefine.hpp"
#include <unistd.h>
#define OUTPUT_ 100

LEDTank::LEDTank(Controller *controller){
  this->state = _STATE_INITIAL;
  this->controller = controller;
  this->distance = 0.0F;
  this->angle = 0.0F;
  this->rangeDistance = 0.0F;
}

#ifdef EXPERIMENTAL_USE
/**
 * 実験用
 */
void LEDTank::execState(){
  controller->getPosition(&distance, &angle);
  switch(this->_state){
  case STATE_FORWARD:
    break;
  case STATE_INIT:
    break;
  case STATE_STOP:
    break;
  case STATE_BACKWARD:
    break;
  case STATE_LEFT:
    break;
  case STATE_RIGHT:
    break;
  default:
    break;
  }
}
#else
/**
 * 本番用
 */
void LEDTank::execState(){
  switch(this->_state){
  case STATE_FORWARD:
    break;
  case STATE_INIT:
    break;
  case STATE_STOP:
    break;
  case STATE_BACKWARD:
    break;
  case STATE_LEFT:
    break;
  case STATE_RIGHT:
    break;
  default:
    break;
  }
}
#endif

#ifdef EXPERIMENTAL_USE
/**
 * 実験用
 */ 
void LEDTank::doTransition(unsigned long event){
  this->_beforeState = this->state;

  switch(this->state){
  case _STATE_INITIAL:
    this->state = STATE_STOP;

    //entry
    controller->positionReset();
    controller->changeDriveMode(STOP, 0);

    printf("STOP\n");

    break;
  case STATE_FORWARD:
    if(((event & E_DOWN) != 0) ){
      this->state = STATE_STOP;
      controller->changeDriveMode(STOP, OUTPUT_);
      printf("STOP\n");
    }
    else if(((event & E_LEFT) != 0) ){
      this->state = STATE_LEFT;
      controller->changeDriveMode(CCW, OUTPUT_);
      printf("LEFT\n");
    }
    else if(((event & E_RIGHT) != 0) ){
      this->state = STATE_RIGHT;
      controller->changeDriveMode(CW, OUTPUT_);
      printf("RIGHT\n");
    }
    break;
  case STATE_BACKWARD:
    if(((event & E_RIGHT) != 0) ){
      this->state = STATE_RIGHT;
      controller->changeDriveMode(CW, OUTPUT_);
      printf("RIGHT\n");
    }
    else if(((event & E_LEFT) != 0) ){
      this->state = STATE_LEFT;
      controller->changeDriveMode(CCW, OUTPUT_);
      printf("LEFT\n");
    }
    else if(((event & E_UP) != 0) ){
      this->state = STATE_STOP;
      controller->changeDriveMode(STOP, OUTPUT_);
      printf("STOP\n");
    }
    break;
  case STATE_LEFT:
    if(((event & E_UP) != 0) ){
      this->state = STATE_FORWARD;
      controller->changeDriveMode(FORWARD, OUTPUT_);
      printf("FORWARD\n");
    }
    if(((event & E_DOWN) != 0) ){
      this->state = STATE_BACKWARD;
      controller->changeDriveMode(BACKWARD, OUTPUT_);
      printf("BACKWARD\n");
    }
    else if(((event & E_RIGHT) != 0) ){
      this->state = STATE_STOP;
      controller->changeDriveMode(STOP, OUTPUT_);
      printf("STOP\n");
    }
    break;
  case STATE_RIGHT:
    if(((event & E_UP) != 0) ){
      this->state = STATE_FORWARD;
      controller->changeDriveMode(FORWARD, OUTPUT_);
      printf("FORWARD\n");
    }
    if(((event & E_DOWN) != 0) ){
      this->state = STATE_BACKWARD;
      controller->changeDriveMode(BACKWARD, OUTPUT_);
      printf("BACKWARD\n");
    }
    else if(((event & E_LEFT) != 0) ){
      this->state = STATE_STOP;
      controller->changeDriveMode(STOP, OUTPUT_);
      printf("STOP\n");
    }
    break;
  case STATE_STOP:
    if(((event & E_UP) != 0) ){
      this->state = STATE_FORWARD;
      controller->changeDriveMode(FORWARD, OUTPUT_);
      printf("FORWARD\n");
    }
    else if(((event & E_DOWN) != 0) ){
      this->state = STATE_BACKWARD;
      controller->changeDriveMode(BACKWARD, OUTPUT_);
      printf("BACKWARD\n");
    }
    else if(((event & E_RIGHT) != 0) ){
      this->state = STATE_RIGHT;
      controller->changeDriveMode(CW, OUTPUT_);
      printf("RIGHT\n");
    }
    else if(((event & E_LEFT) != 0) ){
      this->state = STATE_LEFT;
      controller->changeDriveMode(CCW, OUTPUT_);
      printf("LEFT\n");
    }
    break;
  default:
    break;
  }
}
#else
/**
 * 本番用
 */
void LEDTank::doTransition(unsigned long event){
  this->_beforeState = this->state;

  switch(this->state){
  case _STATE_INITIAL:
    this->state = STATE_STOP;

    //entry
    controller->changeDriveMode(STOP, 0);

    printf("STOP\n");

    break;
  case STATE_FORWARD:
    if(((event & E_DOWN) != 0) ){
      this->state = STATE_STOP;
      controller->changeDriveMode(STOP, OUTPUT_);
      printf("STOP\n");
    }
    else if(((event & E_LEFT) != 0) ){
      this->state = STATE_LEFT;
      controller->changeDriveMode(CCW, OUTPUT_);
      printf("LEFT\n");
    }
    else if(((event & E_RIGHT) != 0) ){
      this->state = STATE_RIGHT;
      controller->changeDriveMode(CW, OUTPUT_);
      printf("RIGHT\n");
    }
    break;
  case STATE_BACKWARD:
    if(((event & E_RIGHT) != 0) ){
      this->state = STATE_RIGHT;
      controller->changeDriveMode(CW, OUTPUT_);
      printf("RIGHT\n");
    }
    else if(((event & E_LEFT) != 0) ){
      this->state = STATE_LEFT;
      controller->changeDriveMode(CCW, OUTPUT_);
      printf("LEFT\n");
    }
    else if(((event & E_UP) != 0) ){
      this->state = STATE_STOP;
      controller->changeDriveMode(STOP, OUTPUT_);
      printf("STOP\n");
    }
    break;
  case STATE_LEFT:
    if(((event & E_UP) != 0) ){
      this->state = STATE_FORWARD;
      controller->changeDriveMode(FORWARD, OUTPUT_);
      printf("FORWARD\n");
    }
    if(((event & E_DOWN) != 0) ){
      this->state = STATE_BACKWARD;
      controller->changeDriveMode(BACKWARD, OUTPUT_);
      printf("BACKWARD\n");
    }
    else if(((event & E_RIGHT) != 0) ){
      this->state = STATE_STOP;
      controller->changeDriveMode(STOP, OUTPUT_);
      printf("STOP\n");
    }
    break;
  case STATE_RIGHT:
    if(((event & E_UP) != 0) ){
      this->state = STATE_FORWARD;
      controller->changeDriveMode(FORWARD, OUTPUT_);
      printf("FORWARD\n");
    }
    if(((event & E_DOWN) != 0) ){
      this->state = STATE_BACKWARD;
      controller->changeDriveMode(BACKWARD, OUTPUT_);
      printf("BACKWARD\n");
    }
    else if(((event & E_LEFT) != 0) ){
      this->state = STATE_STOP;
      controller->changeDriveMode(STOP, OUTPUT_);
      printf("STOP\n");
    }
    break;
  case STATE_STOP:
    if(((event & E_UP) != 0) ){
      this->state = STATE_FORWARD;
      controller->changeDriveMode(FORWARD, OUTPUT_);
      printf("FORWARD\n");
    }
    else if(((event & E_DOWN) != 0) ){
      this->state = STATE_BACKWARD;
      controller->changeDriveMode(BACKWARD, OUTPUT_);
      printf("BACKWARD\n");
    }
    else if(((event & E_RIGHT) != 0) ){
      this->state = STATE_RIGHT;
      controller->changeDriveMode(CW, OUTPUT_);
      printf("RIGHT\n");
    }
    else if(((event & E_LEFT) != 0) ){
      this->state = STATE_LEFT;
      controller->changeDriveMode(CCW, OUTPUT_);
      printf("LEFT\n");
    }
    break;
  default:
    break;
  }
}
#endif
