#include <stdio.h>
#include "FSMmanager.h"
#include "keypad.h"
#include "ports_init.h"
#include "lcd_functions.h"

int main()
{	
	int PassWord[4] = {4, 6, 9, 0}; //Set the Password
	LCD4bits_Init(); 		// Initialize LCD
	PortF_init(); 			// Initialize PortF
	PortC_init();			// Initialize PortC
	PortE_init();			// Initialize PortE
	PortA_init();			// Initialize PortA
	
	LCD4bits_Cmd(0x0C); 		//display on , cursor off
		    
	FSM_SetUp(); 			// Setting up the States
	
	CurrentState = Locked; 		// Set the First State to be the Locked State
		
        myStates.Locked.Enter(PassWord); //Enter the Password State and pass the Correct Password to it.
     
    while (1)
    {
	    loop[CurrentState](); 	//Enter the Loop Function of the Current State.
    } 


}
