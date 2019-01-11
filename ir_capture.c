#include <stdint.h>
#include <msp.h>

void inputCaptureInit(void){
	__disable_irq();
	P6->DIR &= ~BIT6;   //Set P6.6 Dir to input
	P6->SEL0 |= BIT6;
	P6->SEL1 &= ~BIT6;
	
	TIMER_A2->CCTL[3] = TIMER_A_CCTLN_CM_3 | TIMER_A_CCTLN_CCIS_0 | TIMER_A_CCTLN_CAP | TIMER_A_CCTLN_SCS |TIMER_A_CCTLN_CCIE;
	TIMER_A0->CTL = TIMER_A_CTL_TASSEL_2 | TIMER_A_CTL_MC_2;
	
	NVIC_SetPriority(TA2_N_IRQn,2);
	NVIC_EnableIRQ(TA2_N_IRQn);
	__enable_irq();
}

void TA2_N_IRQHandler(void){
	int c;
}

int main(void){
	
	WDT_A->CTL = WDT_A_CTL_PW | WDT_A_CTL_HOLD;
	
	inputCaptureInit();
}
