#include <msp430.h>
#include "stateMachines.h"
#include "led.h"
#include "switches.h"
#include "buzzer.h"

static int state_change = 0;

void state_RED(){ // red light make a small sound

  red_on = 1;

  green_on = 0;

  buzzer_set_period(500);

}



void state_GREEN(){ // green light on make bigger sound

  red_on = 0;

  green_on = 1;

  buzzer_set_period(1000);

}



void state_BOTH(){ // leds at same time sound when leds are off

  switch(state_change){

    case 0:

      red_on = 1;

      green_on = 1;

      state_change = 1;

      break;

    case 1:

      red_on = 0;

      green_on = 0;

      state_change = 0;

      buzzer_set_period(2000);

      break;  

  }

}



void state_SIMULTANIOUS(){ // everything turns on simultaniously

  switch(state_change){

    case 0:

      red_on = 1;

      state_change = 1;

      break;

    case 1:

      red_on = 0;

      green_on = 1;

      state_change = 2;

      break;

    case 2:

      red_on = 0;

      green_on = 0;

      buzzer_set_period(3000);

      state_change = 0;

      break;

  }

}
void state_advance(){

  switch(button){

    case 0:

      state_RED();

      break; 

    case 1:

      state_GREEN();

      break;

    case 2:

      state_BOTH();

      break;

    case 3:

      state_SIMULTANIOUS();

      break;

  }

  led_update();

}
