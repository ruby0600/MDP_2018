/*
 * LED4.c
 * port C�� ����Ǿ� �ִ� LED�� ���������� on / off ��Ű�� ���α׷��� �ۼ��϶�. ��,
PC0���� PC7�� ����Ǿ� �ִ� LED�� ���������� ON/OFF��Ű�� PC7�� LED�� ON��
�Ŀ��� �ٽ� PC0�� LED���� ON�� �ǵ��� �Ѵ�. �� PORT 0�� �� ON, PORT 1�� ��
OFF
 * Created: 2018-03-22 ���� 8:45:36
 * Author: KHJ
 */
 #include <mega128.h>
 #define LED_On_Off PORTC
 void Delay(unsigned char);
 void main(void) {
    unsigned char led = 0xfe;
    DDRC = 0xff;
    while(1){
        LED_On_Off = led;
        Delay(5);
        led <<= 1;
        led |= 0x01;
        if(led == 0xff) led = 0xfe;
        }
 }
 void Delay(unsigned char count) {
    unsigned int i,j;
    for(i = 0;i < count; i++) {
        j = 50000;
        while(--j);
        }
 } 