/*
 * File:   isr.c
 * Author: lenovo
 *
 * Created on 5 October, 2026, 4:36 PM
 */


#include <xc.h>
#include "sleep.h"

extern volatile unsigned char sec_count = 0;
void __interrupt() isr(){
    
    
    static unsigned int count;
    if(TMR0IF){
        TMR0 = TMR0 + 8;
        if(count++ == 5000){
            RB1 = !RB1;
            count = 0;
            
            sec_count++;
        }
        TMR0IF = 0;
    }
    
    if(INT0IF){
        INT0IF = 0;
        sec_count = 0;
        
    }
}
