#include <msp430.h>
#include "stateMachines.h"
#include "led.h"
#include "switches.h"
#include "buzzer.h"

char toggle_red(){
  static char state = 0;

  switch(state){
  case 0:
    red_on = 1;
    state = 1;
    break;
  case 1:
    red_on = 0;
    state = 0;
    break;
  }
  return 1;
}

char toggle_green(){
  char changed = 0;
  if(red_on){
    green_on ^= 1;
    changed = 1;
  }
  return changed;
}

char state1(){ // red light make a small sound
  char changed = 0;
  static enum {R = 0, G = 1} color = G;
  switch(color){
  case R: changed = toggle_red(); color = G; break;
  case G: changed = toggle_green(); color = R; break;
  }
  leds_changed = 1;
  led_update();
  return 1;
}

char state2(){ // green light on make bigger sound
  green_on = 1;
  buzzer_set_period(0);
  leds_changed = 1;
  led_update();
  return 1;
}

char state3(){ // leds at same time sound when leds are off
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
  leds_changed = 1;
  led_update();
  return 1;
}



char state4(){ // everything turns on simultaniously
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
  leds_changed = 1;
  led_update();
  return 1;
}


void state_advance(){
  char changed = 0;
  
  switch(switch_state_changed){

    case 1:
      
      changed = state1();
      break;
      
    case 2:
      
      changed = state2();
      break;

    case 3:

      changed = state3();
      break;

    case 4:

      changed = state4();
      break;

  }
}

