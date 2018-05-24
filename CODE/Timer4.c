/*
 * Timer4.c
 *
 * Created: 2018-05-17 ���� 7:10:42
 * Author: Administrator
 */ 
 #include <mega128.h>
 unsigned char count;
 unsigned int FNDcount;
 void FNDN();
 char FND[10] = {0x3F,0x06,0x5B,0x4F,0x66,0x6D,0x7D,0x07,0x7F,0x6F};
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
     if(count == 30) {
        FNDN();
        count = 0;
        FNDcount++;
     }
 }
 void FNDN() {
    unsigned char st,nd,rd,th,hour_st,hour_nd;
    hour_nd = (FNDcount/36000)%2;
    hour_st = (FNDcount/3600)%10;
    th = (FNDcount/600)%6;
    rd = (FNDcount/60)%10;
    nd = (FNDcount/10)%6;
    st = FNDcount%10;
    PORTA = 0b00000001;
    PORTB = FND[st];
    PORTA = 0x00;
    PORTA = 0b00000010;
    PORTB = FND[nd];
    PORTA = 0x00;
    PORTA = 0b00000100;
    PORTB = FND[rd];
    PORTA = 0x00;
    PORTA = 0b00001000;
    PORTB = FND[th];
    PORTA = 0x00;
    PORTA = 0b00010000;
    PORTB = FND[hour_st];
    PORTA = 0x00;
    PORTA = 0b00100000;
    PORTB = FND[hour_nd];
    PORTA = 0x00;
}