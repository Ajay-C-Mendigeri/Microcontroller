/*
 * File:   edgetri.c
 * Author: lenovo
 *
 * Created on 16 September, 2026, 4:08 PM
 */


#include <xc.h>

void main(void) 
{
    TRISB = 0X00;
    PORTB = 0X00;
    TRISC = TRISC | 0X0F;
    int flag = 1;
    while(1)
    {
        if(RC0 == 0 && flag == 1)
        {
            RB0 = !RB0;
            flag = 0; 
        }
        else if(RC0 == 1 && flag==0)
        {
            flag = 1;
        }
    }
    return;
}
