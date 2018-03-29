/*
 * SWITCH3.c
 * 4���� ����ġ SW8, SW14, SW15, SW16�� �Է¿� ���� ������ ���� �����ϴ� ���α�
  ���� �ۼ��Ͻÿ�. (switch case �̿�) ��, switch�� ������ led = on, ������ ������
   led = off �ȴ�.
 * Created: 2018-03-29 ���� 5:17:31
 * Author: KHJ
 */

 #include <mega128.h>
 #define LED_On_Off PORTC
 #define Sw_Input PINE
 void main(void) {
    unsigned char move;
    DDRC = 0xff;
    DDRE = 0x00;
        while(1) {
            move = PINE & 0xf0;
            switch(move) {
                case 0b11100000: LED_On_Off = 0x00;
                           break;
                case 0b11010000: LED_On_Off = 0xff;
                           break;
                case 0b10110000: LED_On_Off = 0b01010101;
                           break;
                case 0b01110000: LED_On_Off = 0b10101010;
                           break;
            }
        }
 }