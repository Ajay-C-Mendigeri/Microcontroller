/*
 * File:   main.c
 * Author: lenovo
 *
 * Created on 6 October, 2026, 4:36 PM
 */


#include <xc.h>
#include "timers.h"

void init_config(){
    TRISB = 0X00;
    PORTB = 0X00;
    
//    TRISB0 = 0;
//    TRISB1 = 0;
//    TRISB2 = 0;
    
    
    RB0 = 0;
    RB1 = 0;
    RB2 = 0;
    
    
    init_timer0();
    init_timer1();
    init_timer2();
    
    GIE = 1;
    PEIE = 1;
    
}
void main(void) {
    init_config();
    while(1){
        ;
    }
    return;
}
