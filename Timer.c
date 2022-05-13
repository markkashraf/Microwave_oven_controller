#include "Timer.h"
#include "FSMmanager.h"

void Timer_Enter(int minutes ,int seconds)
{
    myStates.Timer.minutes = minutes;
    myStates.Timer.seconds = seconds;
    CurrentState = Timer;
    
}


void Timer_Loop()
{
    printf("Timer_looping\n");
}


void Timer_Output()
{
     printf("Timer_output\n");
}

void Timer_Init()
{
     myStates.Timer.Enter  = Timer_Enter;
     myStates.Timer.Loop   = Timer_Loop;
     myStates.Timer.Output = Timer_Output;
     loop[Timer] = myStates.Timer.Loop;

}
