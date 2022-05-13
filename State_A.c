#include"State_A.h"
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
