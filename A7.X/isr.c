/*
 * File:   isr.c
 * Author: lenovo
 *
 * Created on 6 October, 2026, 4:36 PM
 */


#include <xc.h>
#include "timers.h"

void __interrupt() isr(){
    static unsigned int count0=0;
    static unsigned int count1=0;
    static unsigned int count2=0;

    if(TMR0IF){
        TMR0 = TMR0+8;
        if(count0++ == 5000){
           RB0 = !RB0;
            
            count0 = 0;
        }
        TMR0IF=0;
    }
    
    if(TMR1IF){
        TMR1 = TMR1+3038;
        if(count1++ == 20){
           RB1 = !RB1;
           
            count1 = 0;
        }
        TMR1IF=0;
    }
    
    if(TMR2IF){
        
        if(count2++ == 20000){
           RB2 = !RB2;
            
            count2 = 0;
        }
        TMR2IF=0;
    }

}

