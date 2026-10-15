#include<xc.h>
#include"digitalkeypad.h"

void init_digital_keypad(void){
    TRISC = TRISC | 0X0F;
}

unsigned char read_digital_keypad(unsigned char trigger){
    static unsigned char once =1;
    
    if(trigger == LEVEL){
        return PORTC & 0X0F;
    }
    
    else if(trigger == EDGE){
        if((PORTC & 0X0F)!= ALL_RELEASED && (once ==1)){
            once = 0;
            return PORTC & 0X0F;
        }
        else if((PORTC & 0X0F)==ALL_RELEASED){
            once = 1;
        }
        return ALL_RELEASED;
    }
}