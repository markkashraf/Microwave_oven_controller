#include <stdio.h>
#include "FSMmanager.h"




int main()
{


     
   FSM_int();
    
    CurretState = State_B;

    myStates.State_B.Enter(4);
    
    loop[CurretState]();


}