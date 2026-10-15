# 1 "main.c"
# 1 "<built-in>" 1
# 1 "<built-in>" 3
# 295 "<built-in>" 3
# 1 "<command line>" 1
# 1 "<built-in>" 2
# 1 "C:\\Program Files\\Microchip\\xc8\\v4.00\\pic\\include/language_support.h" 1 3
# 2 "<built-in>" 2
# 1 "main.c" 2
# 11 "main.c"
void main(void) {
    unsigned char *trisb=(unsigned char *)0xF93;
    unsigned char *portb=(unsigned char *)0xF81;
   *trisb=0x00;
   *portb=0x00;
   while(1){
       for(int i=0; i<9; i++){
       *portb=0xFF << (8 - i);
       for(unsigned int delay=50000; delay--;);



       }
   }
    return;
}
