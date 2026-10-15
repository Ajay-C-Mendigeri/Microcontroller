/*
 * File:   external.c
 * Author: lenovo
 *
 * Created on 30 September, 2026, 10:20 PM
 */


#include <xc.h>
#include "header.h"

void init_external_int0(void){
    INT0IE = 1;     //enabling the external interrupt0
    
    INT0IF = 0;
    TRISB0 = 1;
}
