/*
 * File:   main.c
 * Author: DELL
 *
 * Created on August 17, 2024, 12:17 PM
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



#include <xc.h>

void main(void) {
    
    unsigned char segment[] = {0x3f,0x06,0x5b,0x4f,0x66,0x6d,0x7c,0x77,0x6f},i=0;
    TRISC = 0x00;
    while(1){
        for(i =0; i <= 10; i++){
            PORTC = segment[i];
            __delay_ms(1000);
        } 
        
    }
    
    return;
}
