#include <mega128.h>
unsigned char led = 0Xfe;
unsigned int count;
char FNDc[10] = {0x3f,0x06,0x5b,0x4f,0x66,0x6d,0x7d,0x07,0x7f,0x6f};
void FND();
void main(void) {
    DDRB = 0xff;
    DDRF = 0xff;
    DDRC = 0xff;
    PORTC = led;
    ETIMSK = 0x04;
    TCCR3A = 0x00;
    TCCR3B = 0x06;
    TCCR3C = 0x00;
    TCNT3H = 0xff;
    TCNT3L = 0xf0;
    SREG = 0x80;
    while(1) {
        FND();
    }
}
interrupt [TIM3_OVF] void timer(void) {
    led <<= 1;
    led |= 0x01;
    if(led == 0xff) {
        led = 0xfe;
    }
    PORTC = led;
    count++;
    TCNT3H = 0xff;
    TCNT3L = 0xf0;
}
void FND() {
    unsigned char st,nd,rd,th;
    th = (count/1000)%10;
    rd = (count/100)%10;
    nd = (count/10)%10;
    st = count%10;
    PORTA = 0x00;
    PORTA = 0b00000001;
    PORTB = FNDc[st];
    PORTA = 0x00;
    PORTA = 0b00000010;
    PORTB = FNDc[nd];
    PORTA = 0x00;
    PORTA = 0b00000100;
    PORTB = FNDc[rd];
    PORTA = 0x00;
    PORTA = 0b00001000;
    PORTB = FNDc[th];
}