#include "Idle.h"
#include "FSMmanager.h"
#include "keypad.h"
#include "ports_init.h"
#include "lcd_functions.h"
void Idle_Enter()
{
    CurrentState = Idle;
		LCD4bits_Cmd(0x01);
		LCD_WriteString("Ready for input");

}


void Idle_Loop()
{
		
}


void Idle_Output()
{
		
}

void Idle_Init()
{
     myStates.Idle.Enter  = Idle_Enter;
     myStates.Idle.Loop   = Idle_Loop;
     myStates.Idle.Output = Idle_Output;
     loop[Idle] = myStates.Idle.Loop;
}
