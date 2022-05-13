#include "FreeTimer.h"
#include "FSMmanager.h"

void FreeTimer_Enter()
{
     CurrentState = FreeTimer;
     printf("FreeTimer_Entered and the enter Parameter is \n");
}


void FreeTimer_Loop()
{
     printf("FreeTimer_looping\n");
}


void FreeTimer_Output()
{
     printf("FreeTimer_output\n");
}

void FreeTimer_Init()
{
     myStates.FreeTimer.Enter  = FreeTimer_Enter;
     myStates.FreeTimer.Loop   = FreeTimer_Loop;
     myStates.FreeTimer.Output = FreeTimer_Output;
     loop[FreeTimer] = myStates.FreeTimer.Loop;

}
