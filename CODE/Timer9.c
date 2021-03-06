#include <mega128.h>
#include <delay.h>
char seg_part[10]= {0x3f,0x06,0x5b,0x4f,0x66,0x6d,0x7d,0x07,0x7f,0x6f};
int sec = 0, min = 0, count =0, msec;
int run = 0;
void FND();
void main(void) {
    DDRB = 0xff;
    DDRF = 0xff;
    SREG = 0x80;
    TIMSK = 0x01;
    TCCR0 = 0b00000100;
    TCNT0 = 6;
    EIMSK = 0b00110000;
    EICRB = 0b00001010;
    while(1) {
        FND();
    }
}
void FND(void) { 
    unsigned char nd, st, mnd,mst,sst,snd;
    nd = sec / 10; 
    st = sec % 10; 
    mnd = min / 10;
    mst = min % 10;
    snd = msec / 10;
    sst = msec % 10;  
    PORTF = 0b11101111; 
    PORTB = seg_part[mnd]; 
    delay_us(1000);
    PORTF = 0xff;
    PORTF = 0b11011111; 
    PORTB = seg_part[mst]; 
    delay_us(1000);
    PORTF = 0xff;
    PORTF = 0b10111111; 
    PORTB = seg_part[nd]; 
    delay_us(1000);
    PORTF = 0xff;
    PORTF = 0b01111111; 
    PORTB = seg_part[st]; 
    delay_us(1000);
    PORTF = 0xff;
    PORTF = 0b11111110; 
    PORTB = seg_part[snd]; 
    delay_us(1000);
    PORTF = 0xff;
    PORTF = 0b11111101; 
    PORTB = seg_part[sst]; 
    delay_us(1000);
    PORTF = 0xff;
}
interrupt [TIM0_OVF] void time0(void) {
    if(run == 1) {
        count++;
        if(count == 10) {
            msec++;
            if(msec == 100) { 
                sec++;
                if(sec == 100) {
                    sec = 0;
                    min++;
                    if(min == 60) min = 0;
                }
                msec = 0;
            }
            count = 0;
        }
    }
}
interrupt [EXT_INT4] void stop(void) { 
    run ^= 1;
}
interrupt [EXT_INT5] void reset(void) { 
    sec = 0;
    min = 0;
    msec = 0;
}