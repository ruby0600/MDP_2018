/*
 * Timer2.c
 *
 * Created: 2018-05-17 ���� 6:39:43
 * Author: Administrator
 */ 
 #include <mega128.h>
 unsigned char count;
 void main(void) {
    DDRC = 0xff;
    TCNT0 = 0x00;
    TIMSK = 0x01;
    TCCR0 = 0x07;
    SREG = 0x80;
    while(1);
 }
 interrupt [TIM0_OVF] void TiM_OVF(void)
 {
     count++;
     if(count == 50) {
        PORTC.7 ^= 1;
        count = 0;
     }
 }