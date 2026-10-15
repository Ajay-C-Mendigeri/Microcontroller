/*
 * File:   timer0.c
 * Author: lenovo
 *
 * Created on 9 October, 2026, 4:07 PM
 */


#include <xc.h>
#include "header.h"
void init_timer0(){
    T0CS = 0;
    PSA = 1;
    
    TMR0 = 6;
    TMR0IF = 0;
    TMR0IE = 1;
}