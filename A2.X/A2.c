/*
 * File:   A2.c
 * Author: lenovo
 *
 * Created on 17 September, 2026, 4:11 PM
 */


#include <xc.h>

/*#define SW1 0X0E
#define SW2 0X0D
#define SW3 0X0B
#define SW4 0X07*/

void main(void) 
{
    
    TRISB=0X00;
    PORTB=0X00;
    TRISC=TRISC | 0X0F;
    int flag=0;
    int i=0;
    unsigned long int delay=0;
    
    while(1)
    { 
        if(delay++ == 50000)
        {
            if(RC0==0)
            {
                flag=1;
                i=0;
                PORTB=0X00;
            }
            else if(RC1==0)
            {
                flag=2;
                i=0;
                PORTB=0X00;
            }
            else if(RC2==0)
            {
                flag=3;
                i=0;
                PORTB=0X55;
            }
            else if(RC3==0)
            {
                flag=4;
                i=0;
                PORTB=0X0F;
            }
            
            if(flag == 1)
            {
                if(i<8)
                {
                  PORTB = PORTB | 1<<i;
                }
                else if(i<16)
                {
                 PORTB = PORTB<<1;
                }
                else if(i<24)
                {
                 PORTB = PORTB | (1<<(23-i));
                }
                else if(i<32)
                {
                  PORTB = PORTB & (~(1<<(31-i)));
                }
               else
               {
                i=-1;
               }
               i++;
              
            }
            if(flag == 2)
            {
                 if(i<8)
                 {
                   PORTB = PORTB | 1<<i;
                 }
                 else if(i<16)
                 {
                    PORTB = PORTB<<1;
                 }
                 else
                 {
                   i = -1;
                 }
                 i++;
            }
            if(flag==3)
            {
                PORTB= ~PORTB;
            }
            if(flag==4)
            {
                PORTB= ~PORTB;
            }
            delay = 0;
        }
    }
    return;
}