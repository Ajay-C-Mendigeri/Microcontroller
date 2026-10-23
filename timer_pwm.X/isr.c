/*
 * File:   isr.c
 * Author: ajith
 *
 * Created on October 15, 2026, 5:08 PM
 */


#include <xc.h>
#include "main.h"
extern unsigned char duty_cycle;
void __interrupt() isr(){
    static unsigned char timer_cycle;
    if(TMR2IF){
        TMR2IF = 0;
        
        if(timer_cycle++ < duty_cycle)
            RB0 = 1;
        else
            RB0 = 0;
        if(timer_cycle == PERIOD)
            timer_cycle = 0;
    }
}