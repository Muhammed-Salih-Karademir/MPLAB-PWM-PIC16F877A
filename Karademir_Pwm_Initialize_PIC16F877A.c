/* Muhammed Salih KARADEMIR */

#include "Karademir_Pwm_Initialize_PIC16F877A.h"

#define TMR2PRESCALE 4 //Prescale
long PWM_freq = 5000;

void PWM_Initialize(void);
int PWM_Duty(unsigned int duty);

void main() { 

    
    PWM_Initialize();
    PWM_Duty(200); //setting duty cycle
    __delay_ms(50); //delay
    while (1); // </editor-fold>

}
void PWM_Initialize(void){ 
 
    PR2 = (_XTAL_FREQ/(PWM_freq*4*TMR2PRESCALE)) - 1; //Setting the PR2 formulae using Datasheet // Makes the PWM work in 5KHZ
    ccp1_ptr->CCP1M3=1; ccp1_ptr->CCP1M2=1;//Configure the CCP1 module    
    t2con_ptr->T2CKPS0=1; t2con_ptr->T2CKPS1=0; t2con_ptr->TMR2ON=1;//Configure the Timer module    
    tris_c_ptr->TRISC2=0; //make port pin on C2 as output
}
int PWM_Duty(unsigned int duty){

    if(duty<1023){
  
    duty = ((float)duty/1023)*(_XTAL_FREQ/(PWM_freq*TMR2PRESCALE)); // On reducing //duty = (((float)duty/1023)*(1/PWM_freq)) / ((1/_XTAL_FREQ) * TMR2PRESCALE);
    ccp1_ptr->CCP1X = duty & 1; //Store the 1st bit
    ccp1_ptr->CCP1Y = duty & 2; //Store the 0th bit
    CCPR1L = duty>>2;// Store the remining 8 bit
  }
}

/* Muhammed Salih KARADEMIR */