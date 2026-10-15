/*
 * File:   main.c
 * Author: lenovo
 *
 * Created on 1 October, 2026, 4:48 PM
 */


#include <xc.h>
#include "timer1.h"

void init_config(void){
   
   init_timer1(); 
    GIE = 1;
    PEIE = 1;
    IPEN = 0;
    
    TRISB = 0X00;
    PORTB = 0X00;
}

void main(void){
    init_config();
    while(1){
        ;
    }
    return;
}