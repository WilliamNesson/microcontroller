/*
 * File:   banphim.c
 * Author: DELL
 *
 * Created on August 18, 2024, 11:23 AM
 */


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

#define C1 PORTBbits.RB0
#define C2 PORTBbits.RB1
#define C3 PORTBbits.RB2
#define R1 PORTBbits.RB4
#define R2 PORTBbits.RB5
#define R3 PORTBbits.RB6
#define R4 PORTBbits.RB7








void lcd_data(unsigned char data) // h�m d�ng ?? g?i d? d? li?u hi?n th? 
{
    PORTC = data; // G�n gi� tr? c?a data (d? li?u c?n hi?n th?) cho c?ng C (PORTC
    RS = 1;       // ??t ch�n RS l�n m?c cao , d? li?u ?ang ???c g?i ??n 
    RW = 0;       // M?c th?p , ch? ?? ghi d? li?u 
    EN = 1;       // K�ch ho?t b?t ??u qu� tr�nh truy?n d? li?u 
    __delay_ms(5);
    EN = 0;
}

void lcd_command(unsigned char cmd)  // h�m d�ng ?? g?i l?nh ?i?u khi?n ??n LCd
{
    PORTC = cmd;    // G�n l?nh ?i?u khi?n cho c?ng C 
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
        lcd_data(*str++); // G?i h�m data ?? hi?n th? 
    }
}

void lcd_initialise()
{
    lcd_command(0x38);  // G?i l?nh 0x38 ?? ??t ch? ?? ho?t ??ng c?a LCD (8-bit, 2 d�ng, font 5x8)
    lcd_command(0x06);  //  G?i l?nh 0x06 ?? ??t ch? ?? nh?p d? li?u, con tr? t?ng d?n v� kh�ng d?ch chuy?n m�n h�nh.
    lcd_command(0x0C);  // G?i l?nh 0x0C ?? b?t m�n h�nh, t?t con tr? v� t?t nh?p nh�y
    lcd_command(0x01);  // G?i l?nh 0x01 ?? x�a to�n b? n?i dung tr�n m�n h�nh LCD.
    __delay_ms(2);      // 
}

void keypad(){
    
    C1 = 1; C2 = 0; C3 = 0;
    if(R1 == 1){
        lcd_data('1');
        while(R1 == 1);
    }
    if(R2 == 1){
        lcd_data('4');
        while(R2 == 1);
    }
    if(R3 == 1){
        lcd_data('7');
        while(R3 == 1);
    }
    if(R4 == 1){
        lcd_data('*');
        while(R4 == 1);
    }
    
    C1 = 0; C2 = 1; C3 = 0;
    if(R1 == 1){
        lcd_data('2');
        while(R1 == 1);
    }
    if(R2 == 1){
        lcd_data('5');
        while(R2 == 1);
    }
    if(R3 == 1){
        lcd_data('8');
        while(R3 == 1);
    }
    if(R4 == 1){
        lcd_data('0');
        while(R4 == 1);
    }
    
    C1 = 0; C2 = 0; C3 = 1;
    if(R1 == 1){
        lcd_data('3');
        while(R1 == 1);
    }
    if(R2 == 1){
        lcd_data('6');
        while(R2 == 1);
    }
    if(R3 == 1){
        lcd_data('9');
        while(R3 == 1);
    }
    if(R4 == 1){
        lcd_data('#');
        while(R4 == 1);
    }
}


void main(void) {
    TRISC = 0x00;   // Cai dat port C = 0 la dau ra 
    TRISD = 0x00;   // Cai dat cac cong port D = 0 la dau ra 
    TRISB = 0xF0;   // RB0 - RB3 la dau ra ; RB4-RB7 la dau vao
    
    lcd_initialise();  // khoi tao lcd 
    lcd_command(0x80);      
    lcd_string("KEYPAD:");
    lcd_command(0xC0);
    
    while(1)
    {
        keypad();  
    }
}
