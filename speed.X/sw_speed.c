
#include <xc.h>

void display(char *ssd)
{
    for(int i = 0; i < 4; i++)
    {
        PORTA = PORTA & 0xF0;
        PORTD = ssd[i];

        PORTA = (PORTA & 0xF0) | (1 << i);

        for(int delay = 200; delay--;);
    }
}

void main(void)
{
    TRISD = 0x00;
    PORTD = 0x00;

    TRISC = TRISC | 0x0F;     // RC0-RC3 as inputs

    TRISA = TRISA & 0xF0;     // RA0-RA3 as outputs
    PORTA = PORTA & 0xF0;

    unsigned char digit[] =
    {
        0xE7, 0x21, 0xCB, 0x6B, 0x2D,
        0x6E, 0xEE, 0x23, 0xEF, 0x6F
    };

    char ssd[4];

    unsigned int num = 0;

    // Higher value = slower display
    // Lower value = faster display
    unsigned int value = 1000;

    unsigned int delay = 0;

    while(1)
    {
        // Display number
        ssd[0] = digit[num / 1000];
        ssd[1] = digit[(num / 100) % 10];
        ssd[2] = digit[(num / 10) % 10];
        ssd[3] = digit[num % 10];

        display(ssd);

        // SW1 pressed -> INCREASE SPEED
        if(RC0 == 0)
        {
            if(value > 100)
            {
                value -= 100;
            }

            // Wait until switch is released
            while(RC0 == 0)
            {
                display(ssd);
            }
        }

        // SW2 pressed -> DECREASE SPEED
        if(RC1 == 0)
        {
            if(value < 3000)
            {
                value += 100;
            }

            // Wait until switch is released
            while(RC1 == 0)
            {
                display(ssd);
            }
        }

        // Number counting speed
        if(delay++ >= value)
        {
            num++;

            if(num >= 9999)
            {
                num = 0;
            }

            delay = 0;
        }
    }
}
