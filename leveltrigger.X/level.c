/*
 * File:   level.c
 * Author: lenovo
 *
 * Created on 16 September, 2026, 3:58 PM
 */


#include <xc.h>


void main(void) {
    TRISB=0X00;
    PORTB=0X00;
    TRISC= TRISC | 0X0F;
    while(1){
        if(RC0==0){
            RB0=!RB0;
        }
    }
    return;
}
