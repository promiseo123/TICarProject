/*
 * Main module for testing the PWM Code for the K64F
 * 
 * Authors:  Hieu Ngo, Promise Omiponle
 * Created:  3/21/2023
 * Modified: Carson Clarke-Magrab <ctc7359@rit.edu> 
 * LJBeato
 * 2021
 */

#include "msp.h"
#include "uart.h"
#include "TimerA.h"


/**
 * Waits for a delay (in milliseconds)
 * 
 * del - The delay in milliseconds
 */
void delay(int n)
{
	int i, j;
	for (j = 0; j < n; j++)
	for (i = 750; i > 0; i--); /* delay 1 ms */
}

int main(void) {
	// Initialize UART and PWM
	// INSERT CODE HERE
	int forward = 0;
	int phase = 0;
	uart0_init();
	//TIMER_A0_PWM_Init(SystemCoreClock/10000, 0,1);
	//TIMER_A0_PWM_Init(SystemCoreClock/10000, 0,2);
	TIMER_A2_PWM_Init(SystemCoreClock/50, 0.05,1);



	// Print welcome over serial
	uart0_put("Running... \n\r");
	
	// Part 1 - UNCOMMENT THIS
	// Generate 20% duty cycle at 10kHz
	// INSERT CODE HERE
//	TIMER_A0_PWM_DutyCycle(0,1);
	//TIMER_A0_PWM_DutyCycle(0,4);
	//delay(10);	
	
	// Part 2 - UNCOMMENT THIS
	for(;;)  //loop forever
	{
		uint16_t dc = 0;
		uint16_t freq = 10000; // Frequency = 10 kHz 
		uint16_t dir = 0;
		char c = 48;
		int i=0;
		
		// 0 to 100% duty cycle in forward direction
		for (i=0; i<50; i=i+10) {
		    // INSERT CODE HERE
			TIMER_A2_PWM_DutyCycle(i*0.01,1);
			delay(100);
		}

		// 100% down to 0% duty cycle in the forward direction
		for (i=50; i>=0; i=i-5) {
		    // INSERT CODE HERE
			TIMER_A2_PWM_DutyCycle(i*0.01,1);
			delay(100);
		}
	}
//NOTE: Step 17 - This is full step low torque
	
	// C o n fig u re the S ig na l M u ltip le x e r for G P IO P ins
//	P4->SEL0 &= ~BIT1;
//	P4->SEL1 &= ~BIT1;
//	P4->SEL0 &= ~BIT2;
//	P4->SEL1 &= ~BIT2;
//	P4->SEL0 &= ~BIT3;
//	P4->SEL1 &= ~BIT3;
//	P4->SEL0 &= ~BIT4;
//	P4->SEL1 &= ~BIT4;
//	// C o n fig u re the G P IO P ins for O u tpu t
//	P4->DIR |= BIT1;
//	P4->DIR |= BIT2;
//	P4->DIR |= BIT3;
//	P4->DIR |= BIT4;
//	
//	while (1){
//	// T urn off all coils , S et G P IO pin s to 0
//	P4->OUT &= ~BIT1;
//	P4->OUT &= ~BIT2;
//	P4->OUT &= ~BIT3;
//	P4->OUT &= ~BIT4;
//	// S et one pin h igh at a tim e
//		if( forward ){
//			if( phase == 0){ P4->OUT |= BIT1/* tu rn on coil A */; phase++;} // A , 1 a
//			else if( phase == 1){ P4->OUT |= BIT2/* turn on coil B */; phase++ ;} // B ,2 a
//			else if ( phase == 2) { P4->OUT |= BIT3/* turn on c oil C */; phase++;} // C ,1 b
//			else { P4->OUT |= BIT4/* turn on co il D */; phase =0 ;} // D ,2 b
//		}
//		else {// re ve rs e
//			if ( phase == 0) { P4->OUT |= BIT4/* turn on coil D */; phase++;} // D ,2 b
//			else if ( phase == 1) { P4->OUT |= BIT3/* turn on coil C */; phase++ ;} // C ,1 b
//			else if ( phase == 2) { P4->OUT |= BIT2/* turn on coil B */; phase++ ;} // B ,2 a
//			else { P4->OUT |= BIT1/* turn on co il A */; phase =0 ;} // A ,1 a
//		}
//	// N ote - you n ee d to w rite your ow n d ela y fu n ctio n
//		delay (10); // sm a lle r va lu es = fa ster sp ee d
//	}
	return 0;
}

