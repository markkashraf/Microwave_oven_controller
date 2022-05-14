#include "Popcorn.h"
#include "FSMmanager.h"

void Popcorn_Enter()
{
     CurrentState = Popcorn;
     Popcorn_Output();
     myStates.Timer.Enter(1,0);
}
         

void Popcorn_Loop()
{
}


void Popcorn_Output()
{
     LCD4bits_Cmd(lcd_clear);      //LCD clears
     LCD_WriteString("Popcorn ");
}

void Popcorn_Init()
{
     myStates.Popcorn.Enter  = Popcorn_Enter;
     myStates.Popcorn.Loop   = Popcorn_Loop;
     myStates.Popcorn.Output = Popcorn_Output;
     loop[Popcorn] = myStates.Popcorn.Loop;

}
