/*
 * File:   eeprom.c
 * Author: Haris
 *
 * Created on 23 September, 2026, 6:14 PM
 */


#include <xc.h>
#include "eeprom.h"

void write_internal_eeprom(unsigned char address, unsigned char data){
    EEADR=address;
    EEDATA=data;
    
    EEPGD=0;
    CFGS=0;
    WREN=1;
    GIE=0;
    
    EECON2=0X55;
    EECON2=0XAA;
    
    WR=1;
    GIE=1;
    
    while(EEIF != 1);
    
    EEIF=0;
    WREN=0;
}


unsigned char read_internal_eeprom(unsigned char address){
    EEADR = address;
    EEPGD = 0;   
    CFGS = 0;
    RD = 1;
    return EEDATA;
}