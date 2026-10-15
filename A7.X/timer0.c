/*
 * File:   timer0.c
 * Author: lenovo
 *
 * Created on 6 October, 2026, 4:36 PM
 */


#include <xc.h>
#include "timers.h"

void init_timer0(){
    T0CS = 0;
    PSA = 0;
    T0PS2 = 0;
    T0PS1 = 0;
    T0PS0 = 1;
    TMR0ON = 1;
    
    TMR0 = 6;
    TMR0IF = 0;
    TMR0IE = 1;
}
