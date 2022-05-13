#include "Popcorn.h"
#include "FSMmanager.h"

void Popcorn_Enter()
{
     CurrentState = Popcorn;
     printf("Popcorn_Entered and the enter Parameter is \n");
}


void Popcorn_Loop()
{
     printf("Popcorn_looping\n");
}


void Popcorn_Output()
{
     printf("Popcorn_output\n");
}

void Popcorn_Init()
{
     myStates.Popcorn.Enter  = Popcorn_Enter;
     myStates.Popcorn.Loop   = Popcorn_Loop;
     myStates.Popcorn.Output = Popcorn_Output;
     loop[Popcorn] = myStates.Popcorn.Loop;

}
