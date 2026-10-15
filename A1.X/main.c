#include <xc.h>

void main(void)
{
    TRISB = 0x00;
    PORTB = 0x00;
    
    int i = 0;
    int delay = 0;
    
    while(1)
    {

        
        if(delay++ == 20000)
        {
            if(i<8)
            {
                PORTB = PORTB | 1<<i;
            }
            else if(i<16)
            {
                PORTB = PORTB<<1;
            }
            else if(i<24)
            {
                PORTB = PORTB | (1<<(23-i));
            }
            else if(i<32)
            {
                PORTB = PORTB & (~(1<<(31-i)));
            }
            else
            {
                i=-1;
            }
            i++;
            
            delay = 0;
        }
    }
    return;
}