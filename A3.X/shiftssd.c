/*
 * File:   shiftssd.c
 * Author: lenovo
 *
 * Created on 22 September, 2026, 4:15 PM
 */


#include <xc.h>
void display(char *ssd){
    for(int i=0; i<4; i++){
        PORTD = ssd[i];
        PORTA = (PORTA & 0XF0) | 1<<i;
        for(int delay=1000; delay--;);
    }
}

void main(void) {
    PORTD=0X00;
    TRISD=0X00;
    TRISA = TRISA & 0XF0;
    PORTA = PORTA & 0XF0;
    int i=0;
    char ssd[4];
    int delay=0;
    unsigned char digit[]={0XE7,0X21,0XCB,0X6B,0X2D,0X6E,0XEE,0X23,0XEF,0X6F,0x00,0x00};
    while(1){
        ssd[0]=digit[i];
        ssd[1]=digit[(i+1)%12];
        ssd[2]=digit[(i+2)%12];
        ssd[3]=digit[(i+3)%12];
        display(ssd);
        if(delay++==200){
            i++;
            if(i==12){
                i=0;
            }
            delay=0;
        }
    }
    return;
}
