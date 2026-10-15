/*
 * File:   main.c
 * Author: lenovo
 *
 * Created on 9 September, 2026, 3:52 PM
 */


//#include <xc.h>

void main(void) {
    unsigned char *trisb=(unsigned char *)0xF93;
    unsigned char *portb=(unsigned char *)0xF81;
   *trisb=0x00;
   *portb=0x00;
   while(1){
       for(int i=0; i<9; i++){
       *portb=0xFF << (8 - i);
       for(unsigned int delay=50000; delay--;);
       
       //*portb=0x00;
       //for(unsigned int delay=50000; delay--;);
       }
   }
    return;
}
