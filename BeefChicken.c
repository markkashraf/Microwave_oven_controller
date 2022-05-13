#include "BeefChicken.h"
#include "FSMmanager.h"

void BeefChicken_Enter(int parameter)
{
    CurrentState = BeefChicken;
    myStates.BeefChicken.parameter = parameter;
    
}


void BeefChicken_Loop()
{
    printf("BeefChicken_looping\n");
}


void BeefChicken_Output()
{
     printf("BeefChicken_output\n");
}

void BeefChicken_Init()
{
     myStates.BeefChicken.Enter  = BeefChicken_Enter;
     myStates.BeefChicken.Loop   = BeefChicken_Loop;
     myStates.BeefChicken.Output = BeefChicken_Output;
     loop[BeefChicken] = myStates.BeefChicken.Loop;

}
