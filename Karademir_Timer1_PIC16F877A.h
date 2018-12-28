#define PIE1_ADRESS   0x08C
#define PIR1_ADRESS   0x00C
#define T1CON_ADRESS  0x010
#define TMR1H_ADRESS  0x00F
#define TMR1L_ADRESS  0x00E
#define TRISB_ADRESS  0x086
#define PORTB_ADRESS  0x006
// Register: TMR1H
#define TMR1H (*(volatile unsigned char*)TMR1H_ADRESS)
#define TMR1L (*(volatile unsigned char*)TMR1L_ADRESS)

#define PIE1 (*(volatile unsigned char*)PIE1_ADRESS)

// bitfield definitions
typedef union {
    struct {
        unsigned TMR1IE                 :1;
        unsigned TMR2IE                 :1;
        unsigned CCP1IE                 :1;
        unsigned SSPIE                  :1;
        unsigned TXIE                   :1;
        unsigned RCIE                   :1;
        unsigned ADIE                   :1;
        unsigned PSPIE                  :1;
    };
} PIE1bits_t,*PIE1bits_ptr;
PIE1bits_t *PIE1bits =(PIE1bits_ptr)PIE1_ADRESS;


#define PIR1 (*(volatile unsigned char*)PIR1_ADRESS)
// bitfield definitions
typedef union {
    struct {
        unsigned TMR1IF                 :1;
        unsigned TMR2IF                 :1;
        unsigned CCP1IF                 :1;
        unsigned SSPIF                  :1;
        unsigned TXIF                   :1;
        unsigned RCIF                   :1;
        unsigned ADIF                   :1;
        unsigned PSPIF                  :1;
    };
} PIR1bits_t,*PIR1bits_ptr;
PIR1bits_t *PIR1bits=(PIR1bits_ptr)PIR1_ADRESS;

#define T1CON  (*(volatile unsigned char*)T1CON_ADRESS)

typedef union {
    struct {
        unsigned TMR1ON                 :1;
        unsigned TMR1CS                 :1;
        unsigned nT1SYNC                :1;
        unsigned T1OSCEN                :1;
        unsigned T1CKPS                 :2;
    };
    struct {
        unsigned                        :2;
        unsigned T1SYNC                 :1;
        unsigned                        :1;
        unsigned T1CKPS0                :1;
        unsigned T1CKPS1                :1;
    };
    struct {
        unsigned                        :2;
        unsigned T1INSYNC               :1;
    };
} T1CONbits_t,*T1CONbits_ptr;
T1CONbits_t *T1CONbits =(T1CONbits_ptr)T1CON_ADRESS;

#define INTCON (*(volatile unsigned char*)INTCON_ADRESS)

// bitfield definitions
typedef union {
    struct {
        unsigned RBIF                   :1;
        unsigned INTF                   :1;
        unsigned TMR0IF                 :1;
        unsigned RBIE                   :1;
        unsigned INTE                   :1;
        unsigned TMR0IE                 :1;
        unsigned PEIE                   :1;
        unsigned GIE                    :1;
    };
    struct {
        unsigned                        :2;
        unsigned T0IF                   :1;
        unsigned                        :2;
        unsigned T0IE                   :1;
    };
} INTCONbits_t,*INTCONbits_ptr;
INTCONbits_t *intconbits =(INTCONbits_ptr)INTCON_ADRESS;