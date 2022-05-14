#include "Idle.h"
#include "FSMmanager.h"
#include "keypad.h"
#include "ports_init.h"
#include "lcd_functions.h"
#include "delays.h"
char x;;
void Idle_Enter()
{
		
    CurrentState = Idle;
		myStates.Idle.Output();
		x = get_keypad_input();
		
		if(x == 'A')myStates.Popcorn.Enter();
		else if(x == 'B' || x == 'C')myStates.BeefChicken.Enter(x);
		else if (x == 'D')myStates.FreeTimer.Enter();
		else{
			
			LCD4bits_Cmd(0x01);
			LCD_WriteString("Err");
		
		} 
		

}


void Idle_Loop()
{
		
}


void Idle_Output()
{
		LCD4bits_Cmd(0x01);
		LCD_WriteString("Ready for input");
}

void Idle_Init()
{
     myStates.Idle.Enter  = Idle_Enter;
     myStates.Idle.Loop   = Idle_Loop;
     myStates.Idle.Output = Idle_Output;
     loop[Idle] = myStates.Idle.Loop;
}
