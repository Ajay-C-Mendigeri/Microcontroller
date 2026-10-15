/*
 * File:   main.c
 * Author: lenovo
 *
 * Created on 30 September, 2026, 5:09 PM
 */


#include <xc.h>
#include"header.h"

void init_config(void){
    init_external_int0();
    
    GIE=1;
    PEIE=1;
    TRISB=0X00;
    PORTB=0X00;
    
}




void main(void) {
    
    int count=0;
    init_config();
    TRISB0=1;
   
    for(count=0; count<10; count++){
        PORTB = ~PORTB;
//        __delay_ms(500);
    }
    
    PORTB = 0X00;
    INT0IF = 0;
    SLEEP();
    
    while(1){
        
    }
    return;
}
