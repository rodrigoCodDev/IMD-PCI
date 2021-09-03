// PIC 16F628A
#include <xc.h>
#define _XTAL_FREQ 20000000

// Definindo configura��es do PIC
#pragma config FOSC = HS // Oscillator Selection bits (INTOSC oscillator: CLKOUT function on RA6/OSC2/CLKOUT pin, I/O function on RA7/OSC1/CLKIN)
#pragma config WDTE = OFF       // Watchdog Timer Enable bit (WDT disabled)
#pragma config PWRTE = OFF      // Power-up Timer Enable bit (PWRT disabled)
#pragma config MCLRE = ON       // RA5/MCLR/VPP Pin Function Select bit (RA5/MCLR/VPP pin function is MCLR)
#pragma config BOREN = OFF      // Brown-out Detect Enable bit (BOD disabled)
#pragma config LVP = OFF        // Low-Voltage Programming Enable bit (RB4/PGM pin has digital I/O function, HV on MCLR must be used for programming)
#pragma config CPD = OFF        // Data EE Memory Code Protection bit (Data memory code protection off)
#pragma config CP = OFF         // Flash Program Memory Code Protection bit (Code protection off)  

// Definindo vari�veis das sa�das para as LEDs
#define verde1 PORTBbits.RB1
#define amarelo1 PORTBbits.RB3
#define vermelho1 PORTBbits.RB4

#define verde2 PORTBbits.RB5
#define amarelo2 PORTBbits.RB0
#define vermelho2 PORTBbits.RB2

void main(void) {
    // Configura os bits RB como sa�da.
    TRISB = 0b00000000;
    
    while(1){
        PORTB = 0;
        
        // a. LEDs acesos por 3 segundos: verde1 (RB1) e vermelho2 (RB2);
        verde1 = 1;
        vermelho2 = 1;
        __delay_ms(7000);
        verde1 = 0;
        
        // b. LEDs acesos por 1 segundo: amarelo1 (RB3) e vermelho2 (RB2);
        amarelo1 = 1;
        __delay_ms(3000);                
        amarelo1 = 0;
        vermelho2 = 0;
        
        // c. LEDs acesos por 3 segundos: vermelho1 (RB4) e verde2 (DS5);
        vermelho1 = 1;
        verde2 = 1;
        __delay_ms(7000);
        verde2 = 0;
        
        // d. LEDs acesos por 1 segundo: vermelho1 (RB4) e amarelo2 (RB0);
        amarelo2 = 1;
        __delay_ms(3000);
        amarelo2 = 0;
        vermelho1 = 0;
    }
    
    return;
}
