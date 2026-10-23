/*
 * File:   main.c
 * Author: ajith
 *
 * Created on October 14, 2026, 5:20 PM
 */
#include <xc.h>
#include "main.h"
#include "digital_keypad.h"
#include "timer2.h"

unsigned char duty_cycle = 20;

void init_config(void){
    TRISB = 0x00;
    PORTB = 0x00;
    RB1 = 1;
    init_digital_keypad();
    init_timer2();
    GIE = 1;
    PEIE = 1;
}
void main(void) {
    init_config();
    unsigned char key = 0x00;
    unsigned long delay = 0;
    while(1){
        key = read_digital_keypad(LEVEL);
        if(delay++ == 1000){
            delay = 0;
            if(key == SWITCH1){
                if(duty_cycle < 100)
                    duty_cycle++;
            }
            else if(key == SWITCH2){
                if(duty_cycle > 0)
                    duty_cycle--;
            }
        }
    }
    return;
}
