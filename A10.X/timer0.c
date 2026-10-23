/*
 * File:   timer0.c
 * Author: lenovo
 *
 * Created on 19 October, 2026, 4:22 PM
 */


#include <xc.h>
#include "header.h"

void init_timer0(){
    //configura the timer0
    T0CS = 0;   //internal clock source
    PSA = 1;    //assigning prescaler
    T0PS2 = 0;
    T0PS1 = 0;
    T0PS0 = 1;  //1:4 prescale
    TMR0 = 6;
    TMR0IF = 0;
    TMR0IE = 1;
}