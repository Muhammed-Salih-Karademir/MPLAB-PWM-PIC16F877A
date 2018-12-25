#pragma config FOSC = HS        // Oscillator Selection bits (HS oscillator)
#pragma config WDTE = OFF       // Watchdog Timer Enable bit (WDT disabled)
#pragma config PWRTE = ON       // Power-up Timer Enable bit (PWRT enabled)
#pragma config BOREN = OFF      // Brown-out Reset Enable bit (BOR disabled)
#pragma config LVP = ON         // Low-Voltage (Single-Supply) In-Circuit Serial Programming Enable bit (RB3/PGM pin has PGM function; low-voltage programming enabled)
#pragma config CPD = OFF        // Data EEPROM Memory Code Protection bit (Data EEPROM code protection off)
#pragma config WRT = OFF        // Flash Program Memory Write Enable bits (Write protection off; all program memory may be written to by EECON control)
#pragma config CP = OFF         // Flash Program Memory Code Protection bit (Code protection off)

#define _XTAL_FREQ 4000000 

#define CCP1CON_ADRESS 0x017
#define T2CON_ADRESS 0x012
#define TRISC_ADRESS 0x087
#define PORTC_ADRESS 0x007

//definition of delay
#pragma intrinsic(_delay)
extern __nonreentrant void _delay(unsigned long);
#define __delay_ms(x) _delay((unsigned long)((x)*(_XTAL_FREQ/4000.0)))



#define PR2 (*(volatile unsigned char*)0x092) // PR2 adress
#define CCPR1L (*(volatile unsigned char*)0x015) //CCPR1L adress

//CCP1CON register setting 
#define CCP1CON (*(extern volatile unsigned char*)CCP1CON_ADRESS)
// bitfield definitions
typedef union{
    struct {
        unsigned CCP1M                  :4;
        unsigned CCP1Y                  :1;
        unsigned CCP1X                  :1;
    };
    struct {
        unsigned CCP1M0                 :1;
        unsigned CCP1M1                 :1;
        unsigned CCP1M2                 :1;
        unsigned CCP1M3                 :1;
    };
} CCP1CONbits_t ;CCP1CONbits_t *ccp1_ptr=CCP1CON_ADRESS;


//T2CON register setting 
#define T2CON (*(extern volatile unsigned char*)T2CON_ADRESS)
// bitfield definitions
typedef union {
    struct {
        unsigned T2CKPS                 :2;
        unsigned TMR2ON                 :1;
        unsigned TOUTPS                 :4;
    };
    struct {
        unsigned T2CKPS0                :1;
        unsigned T2CKPS1                :1;
        unsigned                        :1;
        unsigned TOUTPS0                :1;
        unsigned TOUTPS1                :1;
        unsigned TOUTPS2                :1;
        unsigned TOUTPS3                :1;
    };
} T2CONbits_t ;T2CONbits_t *t2con_ptr=T2CON_ADRESS;

//TRISC register setting 
#define TRISC (*(volatile unsigned char*)TRISC_ADRESS)
// bitfield definitions
typedef union {
    struct {
        unsigned TRISC0                 :1;
        unsigned TRISC1                 :1;
        unsigned TRISC2                 :1;
        unsigned TRISC3                 :1;
        unsigned TRISC4                 :1;
        unsigned TRISC5                 :1;
        unsigned TRISC6                 :1;
        unsigned TRISC7                 :1;
    };
} TRISCbits_t; TRISCbits_t *tris_c_ptr=TRISC_ADRESS;

//TRISC register setting
#define PORTC (*(volatile unsigned char*)PORTC_ADRESS)
// bitfield definitions
typedef union {
    struct {
        unsigned RC0                    :1;
        unsigned RC1                    :1;
        unsigned RC2                    :1;
        unsigned RC3                    :1;
        unsigned RC4                    :1;
        unsigned RC5                    :1;
        unsigned RC6                    :1;
        unsigned RC7                    :1;
    };
} PORTCbits_t; PORTCbits_t *port_c_ptr=PORTC_ADRESS;
//PORTCbits_t *portc_ptr = (port_c_ptr)0x007;



