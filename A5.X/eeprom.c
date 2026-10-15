/*
 * File:   eeprom.c
 * Author: lenovo
 *
 * Created on 28 September, 2026, 4:03 PM
 */


#include <xc.h>


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
}

unsigned char read_internal_eeprom(unsigned char data){
    EEADR = address;
    EEPGD=0;
    CFGS=0;
    RD=1;
    return EEDATA;
    
}
