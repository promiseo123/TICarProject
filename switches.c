/* 
Title: Introduction to Board 
Purpose: Set up Switch 1 and Switch 2 to control LED 1 and LED 2 respectively  
Name: Hieu Ngo	  
Date: 01/20/2023

This file prepared by LJBeato
01/11/2021
  
*/
#include "msp.h" 

#include "Common.h"

// Main Program
// 1. Init LEDs
// 2. Init Switch
// 3. init state=0
// 4. If SW1 pressed, light LED1
// 5. if SW2 pressed, cycle next color triplet of RGB,CMY,W
//	First press - RGB
//  Second press - CMY
//  Third press - W
//  Repeat
// 6. If button released
//		Turn off the LED
//
//
void LED1_Init(void)
{
	// configure PortPin for LED1 as port I/O 
	P1->SEL0 &= ~BIT0; 
	P1->SEL1 &= ~BIT0;
	
	
	// make built-in LED1 LED high drive strength
	
	P1->DS |= BIT0; 
	

	// make built-in LED1 out	 
	P1->DIR |= BIT0;
	// turn off LED
	P1->OUT  &= ~BIT0;

}

void LED2_Init(void)
{
	// configure PortPin for LED2 as port I/O 
		P2->SEL0 &= ~BIT0;
		P2->SEL1 &= ~BIT0;
		P2->SEL0 &= ~BIT1;
		P2->SEL1 &= ~BIT1;
		P2->SEL0 &= ~BIT2;
		P2->SEL1 &= ~BIT2;


	// make built-in LED2 LEDs high drive strength
		P2->DS |= BIT0;
		P2->DS |= BIT1;
		P2->DS |= BIT2;
		


	// make built-in LED2 out	 
		P2->DIR |= BIT0;
		P2->DIR |= BIT1;	
		P2->DIR |= BIT2;
	

	// turn off LED
	P2->OUT &= ~BIT0;
	P2->OUT &= ~BIT1;
	P2->OUT &= ~BIT2;
 
}

void Switches_Init(void)
{
	// configure PortPin for Switch 1 and Switch2 as port I/O 
		P1->SEL0 &= ~BIT1;
		P1->SEL1 &= ~BIT1;
		P1->SEL0 &= ~BIT4;
		P1->SEL0 &= ~BIT4;

	// configure as input
		P1->DIR &= ~BIT1;
		P1->REN |= BIT1;
		P1->OUT |= BIT1;
		
		P1->DIR &= ~BIT4;
		P1->REN |= BIT4;
		P1->OUT |= BIT4;

              
}
//--------------Create Delay----------------
// Using an empty loop to create artificial delay 
// Input : Delay duration
// Return : None
void Delay (int Delay_amount)
{
	int i =0; 
		while (i<Delay_amount)
		{
		++i;}
		
}

//------------Switch_Input------------
// Read and return the status of Switch1
// Input: none
// return: TRUE if pressed
//         FALSE if not pressed
BOOLEAN Switch1_Pressed(void)
{
	BOOLEAN retVal = FALSE;
	// check if pressed
		if ((!(P1->IN & BIT1))== FALSE)
		{
			retVal = TRUE;
		}
	return (retVal);              // return TRUE(pressed) or FALSE(not pressed)
}
//------------Switch_Input------------
// Read and return the status of Switch2
// Input: none
// return: TRUE if pressed
//         FALSE if not pressed
BOOLEAN Switch2_Pressed(void)
{
	BOOLEAN retVal = FALSE;
	// check if pressed
	if((!(P1->IN & BIT4)))
	{
		retVal =TRUE;
	}
	return (retVal);              // return TRUE(pressed) or FALSE(not pressed)
	
}


void LED1_Off (void)
{
	P1->OUT &= ~BIT0;

}
void LED1_On (void)
{ P1->OUT |= BIT0;}


BOOLEAN LED1_State(void)
{
	if ((P1->OUT &BIT0) == TRUE)
		return TRUE;
	else
		return FALSE;
	
}

void LED2_On (int colorIndex)
{
	switch (colorIndex){ 
		case 0 :
		{
			P2->OUT &= ~BIT0;				// Turn off all 3 LED
			P2->OUT &= ~BIT1;
			P2->OUT &= ~BIT2;
			break;
		}
		case 1:
		{
			P2->OUT |= BIT0;
			break;
		}
		case 2:
		{
			P2->OUT &= ~BIT0;				//Turn off RED
			P2->OUT |= BIT1;				//Turn on GREEN
			break;
		}
		case 3:
		{
			P2->OUT &= ~BIT1;				//Turn off GREEN
			P2->OUT |= BIT2;				//TURN on BLUE
			break;
		}
		case 4:
		{
			P2->OUT |= BIT1;				// Turn on BLUE	
			P2->OUT |= BIT2;				// Turn on GREEN
			break;
		}
		case 5:
		{
			P2->OUT &= ~BIT1;				//TURN off GREEN			
				P2->OUT |= BIT0;				//TURN on RED
			break;
		}
		case 6:
		{
			P2->OUT &= ~BIT0;				//TURN off RED
				P2->OUT &= ~BIT2;				//TURN off BLUE
				P2->OUT |= BIT0;				//TURN on RED
				P2->OUT |= BIT1;				//TURN on BLUE
			break;
		}
		case 7: 
		{
			P2->OUT |= BIT0;				// Turn on all 3 LED
			P2->OUT |= BIT1;
			P2->OUT |= BIT2;
			break;
		}
		
		
	}
}
/*
int main(void){
	//Initialize any supporting variables
	int counter = 0;  // COunter varible to keep track of LED2 color scheme

	// Initialize buttons and LEDs
	LED1_Init();
	LED2_Init();
	Switches_Init();
	for(;;)
	{

		//Turn on an LED1 (RED) when button 1 is held
		if(Switch1_Pressed() == TRUE)
				// turn on LED1
           P1->OUT &= ~BIT0;
		else
		{
			// turn off LED1
           P1->OUT |= BIT0;
		}
		// now do the same for LED2
		if (Switch2_Pressed() == TRUE)
		{
			if (counter == 0)					//Cycle LED through RED GREEN BLUE when first pressed
			{
				counter =counter+1;		
        P2->OUT |= BIT0;				// Turn on RED
				Delay(1000000);					
				P2->OUT &= ~BIT0;				//Turn off RED
				P2->OUT |= BIT1;				//Turn on GREEN
				Delay(1000000);
				P2->OUT &= ~BIT1;				//Turn off GREEN
				P2->OUT |= BIT2;				//TURN on BLUE
				Delay(1000000);
				P2->OUT &= ~BIT2;				// Turn off BLUE
				counter =1;							// Increase counter for next cycle
			}
			else if (counter ==1)			// Cycle through   CYAN -MAGENTAA-YELLOW
			{
				P2->OUT |= BIT1;				// Turn on BLUE	
				P2->OUT |= BIT2;				// Turn on GREEN
				Delay(1000000);		
				P2->OUT &= ~BIT1;				//TURN off GREEN			
				P2->OUT |= BIT0;				//TURN on RED
				Delay(1000000);
				P2->OUT &= ~BIT0;				//TURN off RED
				P2->OUT &= ~BIT2;				//TURN off BLUE
				P2->OUT |= BIT0;				//TURN on RED
				P2->OUT |= BIT1;				//TURN on BLUE
				Delay(1000000);
				P2->OUT &= ~BIT0;				//TURN off RED
				P2->OUT &= ~BIT1;				//TURN off BLUE
				counter = 2;						// increase counter
				
			}
			else 
			{
				P2->OUT |= BIT0;				// Turn on all 3 LED
				P2->OUT |= BIT1;
				P2->OUT |= BIT2;
				Delay(1000000);
				P2->OUT &= ~BIT0;				// Turn off all 3 LED
				P2->OUT &= ~BIT1;
				P2->OUT &= ~BIT2;
				counter =0;							// Reset counter to start again
			}
				
				
			
		}

		else
		{
			// Turn off LED2
            ;
		}
	}
}
*/
