#include "Pause.h"
#include "FSMmanager.h"

void Pause_Enter(int parameter)
{
    myStates.Pause .parameter = parameter;
    CurrentState = Pause;
    
}


void Pause_Loop()
{
     
    printf("Pause_looping\n");
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
