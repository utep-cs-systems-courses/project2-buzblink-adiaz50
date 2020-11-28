#include <msp430.h>

#include "stateMachines.h"

char switch_state_changed = 0;

void

__interrupt_vec(WDT_VECTOR) WDT(){	/* 250 interrupts/sec */
  
  static char blink_count = 0;

  if (++blink_count == 125) {

    state_advance();

    blink_count = 0;

  }
// call stateMachines to change blink count and dim
  
}
