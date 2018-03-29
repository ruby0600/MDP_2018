/*
 * SWITCH7.c
 * SW14�� ������ ��(falling edge)���� PORT C�� ����� LED�� �������� ����Ʈ �ϸ�
�������� �ϴ� ���α׷��� �ۼ��϶�.
 * Created: 2018-03-29 ���� 7:12:59
 * Author: KHJ
 */

 #include <mega128.h>
 #define LED_On_Off PORTC
 #define Sw_Input PINE
 void main(void) {
    unsigned char SWpass, SWpre, led;
    DDRC = 0xff;
    DDRE = 0x00;
    led = 0xfe;
    LED_On_Off = led;
    SWpass = Sw_Input & 0x20;
    while(1) {
        SWpre = Sw_Input & 0x10;
        if(SWpass != 0 && SWpre == 0) {
            led = (led << 1) | 0x01;
            if(led == 0xff) led = 0xfe;
            LED_On_Off = led;
        }
        SWpass = SWpre;
    }
 }