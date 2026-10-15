/*
 * File:   isr.c
 * Author: lenovo
 *
 * Created on 30 September, 2026, 10:05 PM
 */


#include <xc.h>

void __interrupt() isr(){
    if(INT0IF){
        PORTB = ~PORTB;
        INT0IF=0;
    }
}
