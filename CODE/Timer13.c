#include <mega128.h>
#include <delay.h>
char seg[10] = {0x3F,0x06,0x5B,0x4F,0x66,0x6D,0x7C,0x27,0x7F,0x67};
int n1 = 0, n10 = 0, num = 0, i = 0;
void main(void) { 
    DDRB = 0xff;
    DDRF = 0xff;
    TIMSK = 0x60;
    TCCR2 = 0x64;
    OCR2 = 100;
    TCNT2 = 0;
    SREG = 0x80; 
    while(1); 
}
interrupt [TIM2_OVF] void timer_int2(void) {
    n1 = num % 10; n10 = num / 10;
    for(i = 0 ; i < 244 ; i++) { 
        PORTF = 0xff;
        PORTB = seg[n1];
        PORTF = 0xfe;
        delay_ms(2);
        PORTF = 0xff;
        PORTB = seg[n10];
        PORTF = 0xfd;
        if(num > 99) num = 0;
        delay_ms(2);
    }
    num++;
}