/*
 * File:   nutnhan.c
 * Author: DELL
 *
 * Created on August 18, 2024, 10:48 AM
 */

// CONFIG
#define _XTAL_FREQ 200000000
#pragma config FOSC = HS        // Oscillator Selection bits (HS oscillator)
#pragma config WDTE = OFF       // Watchdog Timer Enable bit (WDT disabled)
#pragma config PWRTE = OFF      // Power-up Timer Enable bit (PWRT disabled)
#pragma config BOREN = OFF      // Brown-out Reset Enable bit (BOR disabled)
#pragma config LVP = ON         // Low-Voltage (Single-Supply) In-Circuit Serial Programming Enable bit (RB3/PGM pin has PGM function; low-voltage programming enabled)
#pragma config CPD = OFF        // Data EEPROM Memory Code Protection bit (Data EEPROM code protection off)
#pragma config WRT = OFF        // Flash Program Memory Write Enable bits (Write protection off; all program memory may be written to by EECON control)
#pragma config CP = OFF         // Flash Program Memory Code Protection bit (Code protection off)

// #pragma config statements should precede project file includes.
// Use project enums instead of #define for ON and OFF.
#include <xc.h>

void main(void) {
    
    TRISB0 = 1; // C?u hình chân B0 là input ??c t? chân này 
    TRISB1 = 0; // C?u hình chân B1 là output xu?t ra t? chân này 
    
    while(1){
        if(PORTBbits.RB0 == 1){ // ??c chân RB0 = 5v sáng 
            PORTBbits.RB1 = 1;
        }
        else{
            PORTBbits.RB1 = 0;
        }
    }
    
    return; 
}
