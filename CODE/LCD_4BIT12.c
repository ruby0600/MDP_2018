#include <mega128.h>
#include <delay.h>
#asm
.equ __lcd_port = 0x12 ; // PORTD
#endasm
#include <lcd.h>
typedef unsigned char chr;
chr intercount, pos , hnd, hst, mnd, mst, snd, sst, cursorflag, flagcount;
unsigned long count;
chr font_0st[8] = {0x00,0x09,0x09,0x15,0x15,0x15,0x01,0x00};
chr font_0nd[8] = {0x00,0x1b,0x0f,0x0b,0x0f,0x13,0x03,0x00};
void LCDc();
void chr_input(chr *ch, chr add) {
    chr i, a;
    a = (add << 3) | 0x40;
    for (i = 0; i < 8; i++) lcd_write_byte(a++,*ch++);
}
void main() {
    DDRD = 0xff;
    DDRB = 0xff;
    TCCR0 = 0x27;
    TIMSK = 0x01;
    EICRB = 0x0a;
    EIMSK = 0x30;
    SREG = 0x80;
    lcd_init(16);
    lcd_clear();
    chr_input(font_0st,0);
    chr_input(font_0nd,1);
    lcd_gotoxy(6,0);
    lcd_putchar(0);
    lcd_gotoxy(9,0);                       
    lcd_putchar(1);
    LCDc();
    _lcd_write_data(0x0f);
    while(1) {
        if(cursorflag == 1) {
            delay_ms(10);
            if(flagcount == 300){              
            cursorflag = 0;
            _lcd_ready();
            _lcd_write_data(0x0c);
            flagcount++;
        }
    }
}
interrupt [TIM0_OVF] void timer0(void) {
    intercount++;
    if(intercount == 30) {
        delay_ms(10);
        delay_us(480);
        count++;
        intercount = 0;
        PORTB.4 = count%2;
        LCDc();
        if(count >= 172800) {
            count = (count % 172800) - 43200;
        }
    }    
}
interrupt [EXT_INT4] void ext_inter4(void) {
    if(cursorflag == 0) {
        _lcd_ready();
        _lcd_write_data(0x0e);
        cursorflag = 1;
    } else if (cursorflag == 1) {
        pos++;
        if(pos == 2 || pos == 5) {
            pos++;
        }
        if(pos == 8) {
            pos = 0;
        }
    }
}          
interrupt [EXT_INT5] void ext_inter5(void) {
    switch(pos) {
        case 0: count += 2;

        break;
        case 1: count += 20;

        break;
        case 3: count += 120;

        break;
        case 4: count += 1200;
                           
        break;
        case 6: count += 7200;

        break;
        case 7: count += 72000;

        break;
    }
    LCDc();
}
void LCDc() {
    sst = (count/2) % 10;
    snd = (count/20) % 6;
    mst = (count/120) % 10;
    mnd = (count/1200) % 6;
    hst = (count/7200) % 10;
    hnd = (count/72000) % 3;
    lcd_gotoxy(4,1);
    lcd_putchar(hnd+'0');
    lcd_putchar(hst+'0');
    lcd_putchar(':');
    lcd_putchar(mnd+'0');
    lcd_putchar(mst+'0');
    lcd_putchar(':');
    lcd_putchar(snd+'0');
    lcd_putchar(sst+'0');
    lcd_gotoxy(11 - pos,1);
}