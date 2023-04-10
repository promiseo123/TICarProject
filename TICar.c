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
#include "Common.h"


/**
 * Waits for a delay (in milliseconds)
 * 
 * del - The delay in milliseconds
 */
//void delay(int n)
//{
//	int i, j;
//	for (j = 0; j < n; j++)
//	for (i = 750; i > 0; i--); /* delay 1 ms */
//}

void Motor_Init()
{
	P3->SEL1 &= ~BIT6;
	P3->SEL0 &= ~BIT6;
	P3->OUT  &= ~BIT6;
	P3->SEL0 &= ~BIT7;
	P3->SEL1 &= ~BIT7;
	P3->OUT  &= ~BIT7;	
}

void Motor_Enable()
{
		P3->OUT  |= BIT6;
		P3->OUT  |= BIT7;	
}

int main(void) {
	// Initialize UART and PWM
	// INSERT CODE HERE
	int forward = 0;
	int phase = 0;
	uart0_init();
	Motor_Init();
	Motor_Enable();


	TIMER_A0_PWM_Init(SystemCoreClock/10000, 0,1);
	TIMER_A0_PWM_Init(SystemCoreClock/10000, 0,2);
	TIMER_A0_PWM_Init(SystemCoreClock/10000, 0,3);
	TIMER_A0_PWM_Init(SystemCoreClock/10000, 0,4);
	TIMER_A2_PWM_Init(SystemCoreClock/50, 0.0,1);
	// Print welcome over serial
	uart0_put("Running... \n\r");	
	
		
	TIMER_A0_PWM_DutyCycle(0.3,1);
	TIMER_A0_PWM_DutyCycle(0.3,4);

	
		TIMER_A2_PWM_DutyCycle(0.05,1);
						delay(10000);	
		TIMER_A2_PWM_DutyCycle(0.45,1);
						delay(10000);	
		TIMER_A2_PWM_DutyCycle(0.05,1);
						delay(10000);
		TIMER_A2_PWM_DutyCycle(0.45,1);
						delay(10000);	
		
		
	
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

