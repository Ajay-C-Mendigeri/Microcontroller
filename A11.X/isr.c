/*
 * File:   isr.c
 * Author: lenovo
 *
 * Created on 22 October, 2026, 4:37 PM
 */


#include <xc.h>
extern volatile unsigned int period;
extern volatile unsigned int duty_cycle;
extern volatile unsigned int flag;

void __interrupt() isr(){
   static unsigned char itr=0;
   static unsigned int timer_count=0;
    if(TMR0IF){
        TMR0 = TMR0 + 8;
        
        if(itr++<duty_cycle){
            RB0=1;
        }
        else if(itr<period){
            RB0=0;
        }
        else{
            itr=0;
        }
        
        if(flag){
            timer_count++;
            if(timer_count>=100000){
                duty_cycle=10;
                flag=0;
                timer_count=0;
            }
        }
        else{
            timer_count=0;
        }
        
    }
}
