/*
 * File:   isr.c
 * Author: lenovo
 *
 * Created on 9 October, 2026, 4:07 PM
 */


#include <xc.h>
#include"header.h"
extern volatile unsigned int count;
extern volatile unsigned char sec;
void __interrupt() isr(){
    
    
    if(TMR0IF==1){
        TMR0 = TMR0 + 8;
        if(count ++== 20000){
            sec++;
            count=0;
        }
        TMR0IF = 0;
    }
}
