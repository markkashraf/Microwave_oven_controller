#include "Idle.h"
#include "FSMmanager.h"
void Idle_Enter()
{
    CurrentState = Idle;

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
