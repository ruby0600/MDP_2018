/*
 * LED12.c
 * 
 * Created: 2018-03-27 ���� 5:12:49
 * Author: KHJ
 */
#include <mega128.h>
#define LED_On_Off PORTC
void Delay(unsigned char);
void main(void) {
    unsigned char led = 0xfe;
    DDRC = 0xff;
    while(1) {
        do
          {
                LED_On_Off = led;
                Delay(5);
                led <<= 1;
                led |= 0x01; 
          }
        while (led != 0x7f);
        do
          {
                LED_On_Off = led;
                Delay(5);
                led >>= 1;
                led |= 0x80;
          }
        while (led != 0xfe);
    }
}
void Delay(unsigned char count) {
 unsigned int i, j;
 for(i = 0; i < count; i++) {
    j = 50000;
    while(--j);
    }
 }