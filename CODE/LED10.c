/*
 * LED6.c
 * 
 * Created: 2018-03-27 ���� 8:50:36
 * Author: KHJ
 */
 #include <mega128.h>
 #define LED_On_Off PORTC
 void Delay(unsigned char);
 void main() {
    int i;
    int led[8] = {0xfe, 0xfd, 0xfb, 0xf7, 0xef, 0xdf, 0xbf, 0x7f};
    DDRC = 0xff;
    LED_On_Off = 0xff;
    while(1) {
        for(i = 0; i < 8; i++) {
            LED_On_Off = led[i];
            Delay(10);
        }
        for(i = 6; i > 0; i--) {
            LED_On_Off = led[i];
            Delay(10);
        }
    }
 }
void Delay(unsigned char count) {
    unsigned int i, j;
    for(i = 0; i < count; i++) {
        j = 50000;
        while(--j);
    }
 }
 


