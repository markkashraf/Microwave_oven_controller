#include "Pause.h"
#include "FSMmanager.h"

void Pause_Enter(int parameter)
{
    myStates.Pause .parameter = parameter;
    CurrentState = Pause;
   
    //Make LEDs Blink   
}


void Pause_Loop()
{
   while(1)
   {
    //Wait until the pause button or the start button is pressed and return its value in this function.
   
   
   
   }
   
}


void Pause_Output()
{
     printf("Pause_output\n");
}

void Pause_Init()
{
     myStates.Pause.Enter  = Pause_Enter;
     myStates.Pause.Loop   = Pause_Loop;
     myStates.Pause.Output = Pause_Output;
     loop[Pause] = myStates.Pause.Loop;

}
