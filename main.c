#include <stdint.h>
#include <stdbool.h>
#include "msp.h"

uint16_t var = 0;
uint32_t max = 0;

void PWM_Init(void){
	P2->DIR |= (BIT0 | BIT1 | BIT2);		// Enable RBG LED and TA02 as output
	P5->DIR |= BIT6;
	P3->DIR |= BIT7;
	P2->OUT &= ~(BIT0 | BIT1 | BIT2);
	P5->SEL1 &= ~BIT6;
	P5->SEL0 |= BIT6;

	__disable_irq();
	P1->DIR |= (BIT4 | BIT1);					// P1.1 (SW1) and P1.4 (SW2) as input
	P1->REN |= (BIT4 | BIT1);					// Resistor enable
	P1->OUT |= (BIT1 | BIT4);
	P1->IES |= (BIT1 | BIT4);
	P1->IFG &= ~(BIT1 | BIT4);
	P1->IE |= (BIT1 | BIT4);
	
	NVIC_SetPriority(PORT1_IRQn,2);
	NVIC_EnableIRQ(PORT1_IRQn);
	
	CS->KEY = CS_KEY_VAL;
	CS->CTL0 = 0;
	CS->CTL0 = CS_CTL0_DCOEN | CS_CTL0_DCORSEL_2;
	
	CS->CTL1 = CS_CTL1_SELS_3 | CS_CTL1_SELM_3;
	CS->KEY = 0;
	
//	TIMER_A2->CCTL[1] = TIMER_A_CCTLN_OUTMOD_3 | TIMER_A_CCTLN_CCIE;
//	TIMER_A2->CTL = TIMER_A_CTL_TASSEL_2 | TIMER_A_CTL_MC_1;
//	TIMER_A2->CCR[0] = 65000;
//	TIMER_A2->CCR[1] = 57060;
	
	TIMER_A0->CCTL[2] = TIMER_A_CCTLN_OUTMOD_3 | TIMER_A_CCTLN_CCIE;
	TIMER_A0->CTL = TIMER_A_CTL_TASSEL_2 | TIMER_A_CTL_MC_1;
	TIMER_A0->CCR[0] = 65000;
	TIMER_A0->CCR[2] = 57060;
	
	PMAP->KEYID = 0x2D52;     /* unlock PMAP */    
	P3MAP->PMAP_REGISTER7 = PMAP_TA0CCR2A;  /* 23, map P3.7 to TA0.2 */      
	P3->SEL0 |= BIT7;    
	P3->SEL1 &= ~BIT7;    
	PMAP->CTL = 1;            /* lock PMAP */    
	PMAP->KEYID = 0;
	
	__enable_irq();
}


void delay(uint32_t time){
	uint32_t n;
	for (n = 0; n < time; n++);
}

void PORT1_IRQHandler(void){
	if ((P1->IFG & BIT1) == BIT1){
		P1->IFG &= ~BIT1;
		P2->OUT = (P2->OUT & 0xF8) | 0x01; //Turn Red
		while ((P1->IN & BIT1) != BIT1){ 
			while (TIMER_A0->CCR[2] < 60000) {											// While not at max duty cycle
				TIMER_A0->CCR[2] += (TIMER_A0->CCR[2]/1500);
				delay(5000);
			}
		}
		TIMER_A0->CCR[2] = 57060;
	}
	
	if ((P1->IFG & BIT4) == BIT4){
		P1->IFG &= ~BIT4;
		P2->OUT = (P2->OUT & 0xF8) | 0x02; //Turn Green
		while ((P1->IN & BIT4) != BIT4){
			while (TIMER_A0->CCR[2] > 54000){
				TIMER_A0->CCR[2] -= (TIMER_A0->CCR[2]/1500);
				delay(5000); 
			}
		}
		TIMER_A0->CCR[2] = 57060;
	}
}


int main (void) {
	//uint32_t high = 1;
	WDT_A->CTL = WDT_A_CTL_PW | WDT_A_CTL_HOLD;
	PWM_Init();
	
	while(1){
			
	}
}