/*
 * File:   timer2.c
 * Author: ajith
 *
 * Created on October 15, 2026, 5:04 PM
 */


#include <xc.h>

void init_timer2(){
    //timer2 period 
    PR2 = 250;
    TMR2IE = 1;
    TMR2IF = 0;
    //turn on timer2
    TMR2ON = 1;
}