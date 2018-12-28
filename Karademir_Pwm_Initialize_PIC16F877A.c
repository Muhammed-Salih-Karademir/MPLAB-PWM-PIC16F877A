/* Muhammed Salih KARADEMIR */

#include "Karademir_Pwm_Initialize_PIC16F877A.h"
#include "Karademir_Timer1_PIC16F877A.h"


long PWM_freq = 5000;
int d_l;

void timer1_Initialize(void);
void PWM_Initialize(void);
int PWM_Duty(unsigned int duty);
void delay_ms(int n);

__interrupt() void ISR(void) // standard ISR routine for interrupts
{
    if(PIE1bits->TMR1IE==1 && PIR1bits->TMR1IF==1){ //timer 1 interrupt overflow detect
        
    d_l=0; //latch disable as soon as interrupt detected
    PIR1bits->TMR1IF=0;//clear overflow flag
    
    }
}
void main(){ 
    
    timer1_Initialize(void);
    PWM_Initialize();
    PWM_Duty(200); //setting duty cycle
    delay_ms(50);//delay
    while (1); // 

}
void PWM_Initialize(void){ 
 
    PR2 = (_XTAL_FREQ/(PWM_freq*4*TMR2PRESCALE)) - 1; //Setting the PR2 formulae using Datasheet // Makes the PWM work in 5KHZ
    ccp1_ptr->CCP1M3=1; ccp1_ptr->CCP1M2=1;//Configure the CCP1 module    
    t2con_ptr->T2CKPS0=1; t2con_ptr->T2CKPS1=0; t2con_ptr->TMR2ON=1;//Configure the Timer module    
    trisc_ptr->TRISC2=0; //make port pin on C2 as output
    
}
int PWM_Duty(unsigned int duty){

    if(duty<1023){
  
    duty = ((float)duty/1023)*(_XTAL_FREQ/(PWM_freq*TMR2PRESCALE)); // On reducing //duty = (((float)duty/1023)*(1/PWM_freq)) / ((1/_XTAL_FREQ) * TMR2PRESCALE);
    ccp1_ptr->CCP1X = duty & 1; //Store the 1st bit
    ccp1_ptr->CCP1Y = duty & 2; //Store the 0th bit
    CCPR1L = duty>>2;// Store the remining 8 bit 
    
  }    
}
void timer1_Initialize(void){
    T1CONbits->T1SYNC=1; //disabled sync since we do not want it
    PIE1bits->TMR1IE=1;//Timer 1 ovf flag enabled
    intconbits->PEIE=1; //Peripheral interrupts enabled
    intconbits->GIE=1; //Global interrupts enabled    
}
void delay_ms(int n){ // milli second delay routine

    int i;
    
    for(i=0;i<=n-1;i++){
        
    d_l=1; //enable delay latch
    TMR1H=0xf8; //ffff - 7D0 = f82f = 1khz time count
    TMR1L=0x2f;
    T1CONbits->TMR1ON=1;// ENable timer 1
    while(d_l>0);  //latch till 1ms interrupt happens
    T1CONbits->TMR1ON=0;// disable timer 1
    
  }    
}


/* Muhammed Salih KARADEMIR */