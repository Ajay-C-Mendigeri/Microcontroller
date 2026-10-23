/*
 * File:   main.c
 * Author: lenovo
 *
 * Created on 22 October, 2026, 4:07 PM
 */


#include <xc.h>
#include"digital.h"
#include"timer0.h"


volatile unsigned int duty_cycle=10;
volatile unsigned int flag=0;
volatile unsigned int period=100;
int delay=0;

unsigned char read_digital_keypad(unsigned char detection_type)
{
	static unsigned char once = 1;

	if (detection_type == EDGE)
	{
		if (((KEY_PORT & INPUT_PINS) != ALL_RELEASED) && once)
		{
			once = 0;

			return (KEY_PORT & INPUT_PINS);
		}
		else if ((KEY_PORT & INPUT_PINS) == ALL_RELEASED)
		{
			once = 1;
		}
	}
	else if (detection_type == LEVEL)
	{
		return (KEY_PORT & INPUT_PINS);
	}

	return 0xFF;
}

void init_config(void){
    TRISB = 0X00;
    PORTB = 0X00;
    RB0 = 1;
    
    init_timer0();
    GIE = 1;
    PEIE = 1;
    
}

void main(void) {
    init_config();
    while(1){
        int key = read_digital_keypad(EDGE);
//        if(delay++==200){
//            delay=0;
//            if(key==SW1){
//                if(duty_cycle<10){
//                    duty_cycle++;
//                }
//                
//            }
//        }
        if(key==SW1){
            duty_cycle=100;
            flag=1;
        }
    }
    return;
}
