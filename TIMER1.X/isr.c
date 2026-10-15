/*
 * File:   isr.c
 * Author: lenovo
 *
 * Created on 1 October, 2026, 4:47 PM
 */


#include <xc.h>

void __interrupt() isr(){
    static unsigned int count;
    if(TMR1IF){
        TMR1 = TMR1 + 8;
        if(count++== 25){
            RB0 = !RB0;
            count=0;
        }
        TMR1IF = 0;
    }
}
