/*
 * File:   lcd.c
 * Author: DELL
 *
 * Created on August 18, 2024, 9:40 AM
 */
// CONFIG
#pragma config FOSC = HS        // Oscillator Selection bits (HS oscillator)
#pragma config WDTE = OFF       // Watchdog Timer Enable bit (WDT disabled)
#pragma config PWRTE = OFF      // Power-up Timer Enable bit (PWRT disabled)
#pragma config BOREN = OFF      // Brown-out Reset Enable bit (BOR disabled)
#pragma config LVP = ON         // Low-Voltage (Single-Supply) In-Circuit Serial Programming Enable bit (RB3/PGM pin has PGM function; low-voltage programming enabled)
#pragma config CPD = OFF        // Data EEPROM Memory Code Protection bit (Data EEPROM code protection off)
#pragma config WRT = OFF        // Flash Program Memory Write Enable bits (Write protection off; all program memory may be written to by EECON control)
#pragma config CP = OFF         // Flash Program Memory Code Protection bit (Code protection off)
#define _XTAL_FREQ 20000000
#include <string.h>
#include <xc.h>
#define RS PORTDbits.RD0
#define RW PORTDbits.RD1
#define EN PORTDbits.RD2

#include <xc.h>
#include <string.h>

void lcd_data(unsigned char data) // hàm dùng ?? g?i d? d? li?u hi?n th? 
{
    PORTC = data; // Gán giá tr? c?a data (d? li?u c?n hi?n th?) cho c?ng C (PORTC
    RS = 1;       // ??t chân RS lên m?c cao , d? li?u ?ang ???c g?i ??n 
    RW = 0;       // M?c th?p , ch? ?? ghi d? li?u 
    EN = 1;       // Kích ho?t b?t ??u quá trình truy?n d? li?u 
    __delay_ms(5);
    EN = 0;
}

void lcd_command(unsigned char cmd)  // hàm dùng ?? g?i l?nh ?i?u khi?n ??n LCd
{
    PORTC = cmd;    // Gán l?nh ?i?u khi?n cho c?ng C 
    RS = 0;         // L?nh ?i?u khi?n ?ang ???c g?i ??n 
    RW = 0;         // Ch? ?? ghi l?nh 
    EN = 1;         
    __delay_ms(5);
    EN = 0;
}

void lcd_string(const unsigned char *str)
{
    while(*str)
    {
        lcd_data(*str++); // G?i hàm data ?? hi?n th? 
    }
}

void lcd_initialise()
{
    lcd_command(0x38);  // G?i l?nh 0x38 ?? ??t ch? ?? ho?t ??ng c?a LCD (8-bit, 2 dòng, font 5x8)
    lcd_command(0x06);  //  G?i l?nh 0x06 ?? ??t ch? ?? nh?p d? li?u, con tr? t?ng d?n và không d?ch chuy?n màn hình.
    lcd_command(0x0C);  // G?i l?nh 0x0C ?? b?t màn hình, t?t con tr? và t?t nh?p nháy
    lcd_command(0x01);  // G?i l?nh 0x01 ?? xóa toàn b? n?i dung trên màn hình LCD.
    __delay_ms(2);      // 
}

void main(void) {
    TRISC = 0x00; 
    TRISD = 0x00; 
    
    lcd_initialise();
    
    while(1)
    {
        lcd_command(0x83);    
        lcd_string("XuanHoai");
        
        lcd_command(0xC3);    
        lcd_string("ILOVEYOU");  
    }
}