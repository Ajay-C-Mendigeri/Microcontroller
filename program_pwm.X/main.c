#include <xc.h>
#include "digital_keypad.h"
#define     PERIOD      100
unsigned char duty_cycle = 20;
void software_pwm(unsigned char duty_cycle){
    static unsigned char program_cycle;
    if(program_cycle++ < duty_cycle)
        RB0 = 1;
    else
        RB0 = 0;
    if(program_cycle == PERIOD)
        program_cycle = 0;
}
void init_config(void){
    TRISB = 0x00;
    PORTB = 0x00;
    RB1 = 1;
    init_digital_keypad();
}
void main(void) {
    init_config();
    unsigned char key = 0x00;
    unsigned long delay = 0;
    while(1){
        //for(int i=0; i<100; i++)
        key = read_digital_keypad(LEVEL);
        if(delay++ == 1000){
            delay = 0;
        if(key == SWITCH1){
            if(duty_cycle < 100)
                duty_cycle++;
        }
        else if(key == SWITCH2){
            if(duty_cycle > 0)
                duty_cycle--;
        }
        }
        software_pwm(duty_cycle);
    }
    return;
}