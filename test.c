#include <stdint.h>
#include <stdbool.h>
#include "msp.h"

#define DCOTUNE 0x485

void PWM_Init(void){
	P2->DIR |= (BIT0 | BIT1 | BIT2 | BIT5);		// Enable RBG LED and TA02 as output
	P2->OUT &= ~(BIT0 | BIT1 | BIT2);
	P2->SEL0 |= BIT5;

	P1->DIR |= BIT4 | BIT1;					// P1.1 (SW1) and P1.4 (SW2) as input
	P1->REN |= BIT4 | BIT1;					// Resistor enable
	P1->OUT |= BIT1 | BIT4;


	
	CS->KEY = CS_KEY_VAL;
	CS->CTL0 = 0;
	CS->CTL0 = CS_CTL0_DCOEN | CS_CTL0_DCORSEL2 | DCOTUNE;
	
	CS->CTL1 = CS_CTL1_SELS_3 | CS_CTL1_SELM_3;
	CS->KEY = 0;
	
	TIMER_A0->CCTL[2] = TIMER_A_CCTLN_OUTMOD_3 | TIMER_A_CCTLN_CCIE;
	TIMER_A0->CTL = TIMER_A_CTL_TASSEL_2 | TIMER_A_CTL_MC_2;
	TIMER_A0->CCR[0] = 40000;
	TIMER_A0->CCR[2] = 400;
}

void delay(uint32_t time){
	uint32_t n;
	for (n = 0; n < time; n++);
}

void accelerate (void){
	while ((P1->IN & 0x12) == 0x10) {
		while ((P1->IN & 0x12) == 0x10 && TIMER_A0->CCR[2] < TIMER_A0->CCR[0]/2) {																											// While not at max duty cycle
			TIMER_A0->CCR[2] += TIMER_A0->CCR[0]/2000;
			delay(0x3FFF);
		}
	}
	TIMER_A0->CCR[2] = 400;
}

void reverse (void){
	while ((P1->IN & 0x12) == 0x02) {
		CS->KEY = CS_KEY_VAL;
		CS->CTL0 = CS_CTL0_DCOEN | CS_CTL0_DCORSEL1 | DCOTUNE;
		CS->KEY = 0;
		
		TIMER_A0->CCR[2] = 6000;
		while((P1->IN & 0x12) == 0x02 && TIMER_A0->CCR[2] > 0){
			TIMER_A0->CCR[2] -= TIMER_A0->CCR[0]/2000;
			delay(0x3FFF); 
		}
	}
		CS->KEY = CS_KEY_VAL;
		CS->CTL0 = CS_CTL0_DCOEN | CS_CTL0_DCORSEL2 | DCOTUNE;
		CS->KEY = 0;
		TIMER_A0->CCR[2] = 400;
}

int main (void) {
	//uint32_t high = 1;
	WDT_A->CTL = WDT_A_CTL_PW | WDT_A_CTL_HOLD;
	PWM_Init();
	
	while(1){
		switch (P1->IN & 0x12){
			case 0x10:			
									P2->OUT = (P2->OUT & 0xF8) | 0x01; //Turn Red 
									TIMER_A0->CCR[2] = 1800;
									accelerate();
									break;
									//SW1 (1.1) pressed
			case 0x02:
									P2->OUT = (P2->OUT & 0xF8) | 0x02; //Turn Green
									reverse();
									break;
									//SW2 (1.4) pressed
			case 0x00:
									TIMER_A0->CCR[2] = 4000;
									P2->OUT = (P2->OUT & 0xF8) | 0x04; //Turn Blue 
									break;
									//SW1 & SW2 Pressed
		}			


	}
}