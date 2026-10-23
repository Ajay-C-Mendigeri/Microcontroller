#include "header.h"

extern unsigned int time;       // from the isr for the led blinking
extern unsigned int count0;     // this is for the underscore in the clcd

void init_config(void){
    init_timer0();
    init_clcd();
    init_matrix_keypad();

    TRISB0=0x00;        // this is for the first led only
    PORTBbits.RB0=1;    // only using the 0th led
    
    GIE = 1;            // global interrupt enable
    PEIE = 1;           // pheripheral interrupt enable
}

void main(void) {
    init_config();   
    
    unsigned char key;
    unsigned char str[9];
    unsigned char password[]="00000000";
    
    unsigned int i=0;
    unsigned int count=0;
    unsigned int tries=5;
    unsigned int wrong_flag=1;
    unsigned int time_divisor;
    
    clcd_print("Enter Password: ",LINE1(0));
    while(1){
        
		if(tries == 0){       // if all tries get exhausted                                          
			clcd_print("System Locked! ", LINE1(0));
			clcd_print("Reset & try", LINE2(0));
			PORTBbits.RB0 = 1;
			while(1);
		}
          
        time_divisor = 1;
		wrong_flag = 0;
		time = 100000 / time_divisor;
        
        count = 0;
        while(count < 8){
            key = read_switches(STATE_CHANGE);
            
            // when a button is pressed
            if(key != ALL_RELEASED){
                if(key == MK_SW1){
                    str[count] = '0';
                    clcd_putch('*',LINE2(count));
                        
                    if(password[count] != '0'){
                        time_divisor*2;
						time = 100000 / time_divisor;
                        wrong_flag = 1;
                    }
                    count++;
                }
                else if(key == MK_SW2){
                    str[count] = '1';
                    clcd_putch('*',LINE2(count));
                        
                    if(password[count] != '1'){
                        time_divisor*2;
						time = 100000 / time_divisor;
                        wrong_flag = 1;
                    }
                    count++;
                }
            }
            else{
                if(count0 < 10000){
                    clcd_putch('_',LINE2(count));
                }
                else{
                    clcd_putch(' ',LINE2(count));
                }
            }
        }
        str[8]='\0';

           
        if(wrong_flag == 0){
            clcd_print("   Successful   ", LINE1(0));
            clcd_print(" Access Granted ", LINE2(0));
            PORTBbits.RB0 = 0;
            while(1);
        }
        else{
            tries--;

            clcd_print("                ", LINE2(0));
            clcd_print("Tries left",LINE2(2));
			clcd_putch((tries + 0x30), LINE2(0));
                
            __delay_ms(1500);

            clcd_print("Enter Password", LINE1(0));
            clcd_print("                ", LINE2(0));
        }
    }
    return;
}