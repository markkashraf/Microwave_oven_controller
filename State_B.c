#include "State_B.h"
#include "FSMmanager.h"

void State_B_Enter(int x)
{
     CurretState = State_B;
     printf("State_B_Entered and the enter Parameter is %i \n", x);
}


void State_B_Loop()
{
     printf("State_B_looping\n");
}


void State_B_Output()
{
     printf("State_B_output\n");
}

void State_B_Init()
{
     myStates.State_B.Enter  = State_B_Enter;
     myStates.State_B.Loop   = State_B_Loop;
     myStates.State_B.Output = State_B_Output;
     loop[State_B] = myStates.State_B.Loop;

}
