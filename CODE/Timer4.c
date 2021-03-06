/*
 * Timer4.c
 *
 * Created: 2018-05-17 ���� 7:10:42
 * Author: Administrator
 */ 
 #include <mega128.h>
 unsigned long count;
 unsigned int FNDcount;
 void FNDN();
 void delay();
 char FND[10] = {0x3f,0x06,0x5b,0x4f,0x66,0x6d,0x7d,0x07,0x7f,0x6f};
 void main(void) {
    DDRC = 0xff;
    DDRA = 0xff;
    DDRB = 0xff;
    TCNT0 = 0x00;
    TIMSK = 0x01;
    TCCR0 = 0x05;
    SREG = 0x80;
    while(1){
        FNDN();
    }

 }
 interrupt [TIM0_OVF] void TiM_OVF(void)
 {
     count++;
     if(count%10 == 0) {
        FNDN();
        FNDcount++;
     }
 }
 void FNDN() {
    unsigned char st,nd;
    nd = (FNDcount/10)%6;
    st = FNDcount%10;
    PORTA = 0x00;
    PORTA = 0b00000001;
    PORTB = FND[st];
    delay();
    PORTA = 0x00;
    PORTA = 0b00000010;
    PORTB = FND[nd];
    delay();
}
void delay() {
    while(1) {
        if(count%2 == 0) {
            break;
        }
    }
}