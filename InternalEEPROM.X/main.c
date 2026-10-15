


#include <xc.h>
#include "eeprom.h"

void display(char *ssd){
     for(int i=0; i<4; i++){
        
        PORTA = PORTA & 0XF0; 
        
        PORTD = ssd[i];
        
        PORTA = (PORTA & 0XF0) | 1<<i;
        for(int delay=200; delay--;);
    }
}

void main(void) {
    TRISD = 0X00;
    PORTD = 0X00;
    
    TRISA = TRISA & 0XF0;
    PORTA = PORTA & 0XF0;
    
    unsigned char digit[] = {0XE7,0X21,0XCB,0X6B,0X2D,0X6E,0XEE,0X23,0XEF,0X6F};
    char ssd[4];
    unsigned int num=0;
    unsigned char low_byte;
    unsigned char high_byte;
    unsigned int delay=0;
    
    TRISC = TRISC | 0X0F;
    while(1){
        ssd[0]=digit[num/1000];
        ssd[1]=digit[(num/100)%10];
        ssd[2]=digit[(num/10)%10];
        ssd[3]=digit[num%10];
        display(ssd);
        
        if(RC0 == 0){
            low_byte = num & 0XFF;
            high_byte = (num >> 8) & 0XFF;
            
            write_internal_eeprom(0, low_byte);
            write_internal_eeprom(1, high_byte);
            
            
            while(RC0 == 0){
                display(ssd);
            }
        }
        
        if(RC1 == 0){
            low_byte = read_internal_eeprom(0);
            high_byte = read_internal_eeprom(1);
            
            num = low_byte | ((unsigned int)high_byte << 8);
            
            
            while(RC1 == 0){
                display(ssd);
            }
        }
        
        if(delay++==100){
                
            num++;
            if(num>=9999){
                num=0;
            }
            delay=0;
        }
    }
    return;
}