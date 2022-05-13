#include <stdio.h>
#include "FSMmanager.h"




int main()
{
     
   FSM_int();
   CurrentState = Idle;

    myStates.Idle.Enter();
     
    while (1) loop[CurrentState]();


}
