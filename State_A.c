#include "State_A.h"
#include "FSMmanager.h"
void State_A_Enter()
{
    CurretState = State_B;
     printf("State_A_Entered\n");
}


void State_A_Loop()
{
     printf("State_A_looping\n");
}


void State_A_Output()
{
     printf("State_A_output\n");
}

void State_A_Init()
{
     myStates.State_A.Enter  = State_A_Enter;
     myStates.State_A.Loop   = State_A_Loop;
     myStates.State_A.Output = State_A_Output;
     loop[State_A] = myStates.State_A.Loop;
}
