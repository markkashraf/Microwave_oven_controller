#include "Popcorn.h"
#include "FSMmanager.h"

void Popcorn_Enter()
{
     CurrentState = Popcorn;
	  LCD4bits_Cmd(lcd_clear);      //LCD clears
     
	 LCD_WriteString("Popcorn      (1min) ");


void Popcorn_Loop()
{
   if (GPIO_PORTF_DATA_R & 0x10 == 0)
		        myStates.Timer.Enter(1,1)	
}


void Popcorn_Output()
{

}

void Popcorn_Init()
{
     myStates.Popcorn.Enter  = Popcorn_Enter;
     myStates.Popcorn.Loop   = Popcorn_Loop;
     myStates.Popcorn.Output = Popcorn_Output;
     loop[Popcorn] = myStates.Popcorn.Loop;

}
