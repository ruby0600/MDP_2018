//0410 17:22:20

#include <mega128.h>
#include <delay.h>
#define FND PORTB
#define LED PORTC
 void main() {
    char num[10]= {0x3f,0x06,0x5b,0x4f,0x66,0x6d,0x7d,0x07,0x7f,0x6f};
    unsigned short down = 0;
    unsigned char one,two,three,four;
    DDRF = 0xf0;
    DDRB = 0xff;
    FND = 0x00;
    LED = 0xff;
    while(1) {
        for(;down != 9999; down++) {
            four = (down/1000)%10;
            three = (down/100)%10;
            two = (down/10)%10;
            one = down%10;
            PORTF = 0b11100000;
            FND = num[four];
            delay_ms(10);
            PORTF = 0b11110000;
            PORTF = 0b11010000;
            FND = num[three];
            delay_ms(10);
            PORTF = 0b11110000; 
            PORTF = 0b10110000;
            FND = num[two];
            delay_ms(10);
            PORTF = 0b11110000;
            PORTF = 0b01110000;
            FND = num[one];
            delay_ms(10);
            PORTF = 0b11110000;
        }
        down = 0;
    }
 }    