#include <msp430.h>
#include "stateMachines.h"
#include "led.h"
#include "switches.h"
#include "buzzer.h"

char state1(){ // red light make a small sound

  red_on = 1;
  green_on = 0;
  buzzer_set_period(500);

}



void state2(){ // green light on make bigger sound

  red_on = 0
  green_on = 1;
  buzzer_set_period(1000);

}



void state3(){ // leds at same time sound when leds are off
  static short state_change = 0;
  
  switch(state_change){

    case 0:

      red_on = 1;

      green_on = 1;

      state_change++;

      break;

    case 1:

      red_on = 0;

      green_on = 0;

      state_change = 0;

      buzzer_set_period(2000);

      break;  

  }

}



void state4(){ // everything turns on simultaniously
  static short change = 0;
  
  switch(change){

    case 0:

      red_on = 1;

      change++;

      break;

    case 1:

      red_on = 0;

      green_on = 1;

      change++;

      break;

    case 2:

      red_on = 0;

      green_on = 0;

      buzzer_set_period(3000);

      change = 0;

      break;
  }
}

void state_advance(){

  switch(switch_state_changed){

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
  
  leds_changed = 1;
  led_update();
}
