/*
 * LED3.c
 * LED ���� 4bit�� on, off �ϴ� ���α׷� ����
 * Created: 2018-03-22 ���� 8:36:10
 * Author: KHJ
 */

 #include <mega128.h>
 #define LED_On_Off PORTC
 void Delay(unsigned char); 
 void main(void) {
 DDRC = 0xff; 
    while(1) {
        Delay(10); 
        LED_On_Off = 0x0f; 
        Delay(10); 
        LED_On_Off = 0xff; 
        }
}
void Delay(unsigned char count) { 
    unsigned int i, j; 
    for(i = 0; i < count; i++) {
        j = 50000;
        while(--j);
        }
}