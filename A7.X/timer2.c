/*
 * File:   timer2.c
 * Author: lenovo
 *
 * Created on 6 October, 2026, 4:37 PM
 */


#include <xc.h>
#include "timers.h"

void init_timer2(){
//    T2OUTPS3 = 0;
//    T2OUTPS2 = 0;
//    T2OUTPS1 = 0;
//    T2OUTPS0 = 0;
    
    
//    T2CKPS1 = 0;
//    T2CKPS0 = 0;
    
//    TMR2ON = 1;
    
    PR2 = 249;           //set the period match value
    
    T2CON = 0X04;       //configure T2CON with post, pre scale and TMR2ON  
    TMR2IF = 0;
    TMR2IE = 1;
    
    
    
}
