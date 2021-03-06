//0410 17:35:50

#include <mega128.h>
#include <delay.h>
#define FND PORTB   //FND
#define LED PORTC   //LEDs
 void main() {
    char num[10]= {0x3f,0x06,0x5b,0x4f,0x66,0x6d,0x7d,0x07,0x7f,0x6f}; //0~9 숫자 지정
    unsigned int up = 0;
    unsigned char one,two,three,four;   //각 자리수 숫자 저장
    DDRF = 0xf0;                        //FND자리 출력설정
    DDRB = 0xff;                        //FND출력설정
    DDRC = 0xff;                        //LED출력설정
    FND = 0x00;                         //FND초기값(ALL OFF)
    LED = 0xff;                         //LED초기값(ALL OFF)
    while(1) {
        for(;up != 9999; up++) {
            four = (up/1000)%10;        //4번째 자리 숫자 저장
            three = (up/100)%10;        //3번째 자리 숫자 저장
            two = (up/10)%10;           //2번째 자리 숫자 저장
            one = up%10;                //1번째 자리 숫자 저장
            PORTF = 0b11100000;         //4번째 자리 숫자 출력
            FND = num[four];
            delay_ms(20);
            PORTF = 0b11110000;
            PORTF = 0b11010000;         //3번째 자리 숫자 출력
            FND = num[three];
            delay_ms(20);
            PORTF = 0b11110000; 
            PORTF = 0b10110000;         //2번째 자리 숫자 출력
            FND = num[two];
            delay_ms(20);
            PORTF = 0b11110000;
            PORTF = 0b01110000;         //1번째 자리 숫자 출력
            FND = num[one];
            delay_ms(20);
            PORTF = 0b11110000;
            
            if(up >= 1000) {
                if((two % 2) == 0) {    //2번째 자리 숫자가 짝수 일때 On
                    LED = 0xff;    
                }
                else {                  //2번째 자리 숫자가 짝수 일때 Off
                    LED = 0x00;
                }
            }
        }
        up = 0;                         //9999까지 세면 다시 처음으로
    }
 }    