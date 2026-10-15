/*
 * File:   timer0.c
 * Author: lenovo
 *
 * Created on 5 October, 2026, 4:37 PM
 */


#include <xc.h>
#include "sleep.h"  

void init_timer0(){
    T0CS = 0;
    PSA = 0;
    T0PS2 = 0;
    T0PS1 = 0;
    T0PS0 = 1;
    TMR0 = 6;
    TMR0IF = 0;
    TMR0IE = 1;
}
