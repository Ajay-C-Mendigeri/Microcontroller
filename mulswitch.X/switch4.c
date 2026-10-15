/*
 * File:   switch4.c
 * Author: lenovo
 *
 * Created on 16 September, 2026, 5:18 PM
 */


#include <xc.h>
#include"digitalkeypad.h"

void main(void) {
    init_digital_keypad();
    
    TRISB = 0X00;
    PORTB = 0X00;
    while(1){
        unsigned char key = read_digital_keypad(LEVEL);
         
        if(key == SW1){
            PORTB = 0XFF;
            for(unsigned int delay = 50000; delay--;);
            PORTB = 0X00;
            for(unsigned int delay = 50000; delay--;);
        }
    }
    return;
}
