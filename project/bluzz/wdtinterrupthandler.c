#include <msp430.h>

#include "stateMachines.h"

char switch_state_changed = 0;

void

__interrupt_vec(WDT_VECTOR) WDT(){	/* 250 interrupts/sec */
  /*  static char s1Count = 0;
  static char s2Count = 0;

  if(switch_state_changed == 1){
    if(++s1Count == 125){
      state_advance();
      s1Count = 0;
    }
  }
  else if(switch_state_changed == 2){
    if( (++s2Count  % 25) == 0) buzzer_advanced();
    if(s2Count == 250){
      state_advance();
      s2Count = 0;
    }
  }
  else{
    state_advanced();
  }
*/
  
  static char blink_count = 0;

  if (++blink_count == 125) {

    state_advance();

    blink_count = 0;

  }
// call stateMachines to change blink count and dim
  
}
