/*
 * File:   switch.c
 * Author: lenovo
 *
 * Created on 10 September, 2026, 5:02 PM
 */


#include <xc.h>

void main(void) {
    TRISB=0X00;
    PORTB=0X00;
    TRISC= TRISC | 0X0F;
    while(1){
        if((PORTC & 0X0F)!=0X0F){
            PORTB = 0XFF;
        }
        else{
            PORTB =0X00;
        }
    }
    return;
}
