  

#ifndef led_included

#define  led_included



#include <msp430.h>



#define LED_RED BIT0               // P1.0

#define LED_GREEN BIT6             // P1.6

#define LEDS (BIT0 | BIT6)


// these are boolean flags

extern unsigned char leds_changed, green_on;
extern unsigned char red_on;

void led_init();
void led_update();


#endif
