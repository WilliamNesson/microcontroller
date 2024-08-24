/*
 * File:   ngat.c
 * Author: DELL
 *
 * Created on August 18, 2024, 1:42 PM
 */

// CONFIG
#define _XTAL_FREQ 20000000
#pragma config FOSC = HS        // Oscillator Selection bits (HS oscillator)
#pragma config WDTE = OFF       // Watchdog Timer Enable bit (WDT disabled)
#pragma config PWRTE = OFF      // Power-up Timer Enable bit (PWRT disabled)
#pragma config BOREN = OFF      // Brown-out Reset Enable bit (BOR disabled)
#pragma config LVP = ON         // Low-Voltage (Single-Supply) In-Circuit Serial Programming Enable bit (RB3/PGM pin has PGM function; low-voltage programming enabled)
#pragma config CPD = OFF        // Data EEPROM Memory Code Protection bit (Data EEPROM code protection off)
#pragma config WRT = OFF        // Flash Program Memory Write Enable bits (Write protection off; all program memory may be written to by EECON control)
#pragma config CP = OFF         // Flash Program Memory Code Protection bit (Code protection off)
#include <xc.h>


void __interrupt() external() {
    if(INTCONbits.INTF == 1) {
        PORTBbits.RB1 = ~PORTBbits.RB1;
        INTCONbits.INTF = 0;
    }
}



void main(void) {
    INTCONbits.GIE = 1;      // K�ch ho?t ng?t to�n c?c
    INTCONbits.INTE = 1;     // K�ch ho?t ng?t ngo�i INT0
    INTCONbits.INTF = 0;     // X�a c? ng?t INT0 n?u c�

    OPTION_REGbits.INTEDG = 1; // K�ch ho?t ng?t INT0 tr�n c?nh l�n
    TRISBbits.TRISB0 = 1;    // C?u h�nh RB0 l�m ??u v�o (cho INT0)
    TRISBbits.TRISB1 = 0;    // C?u h�nh RB1 l�m ??u ra (cho LED)
    
    PORTBbits.RB1 = 0;       // ??t gi� tr? ban ??u cho RB1 (LED t?t)
    
    while(1){
        // V�ng l?p ch�nh kh�ng l�m g�, ch? ng?t x?y ra
    }
}