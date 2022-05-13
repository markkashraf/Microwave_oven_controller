#include "FSMmanager.h"
#include "State_A.h"
#include "State_B.h"
#include <stdlib.h>
#define NOfStates 2


States myStates = 
{
    {State_A_Enter , State_A_Loop, State_A_Output},
    {State_B_Enter , State_B_Loop, State_B_Output}
};


f_pointer_void_void* loop;


void FSM_int(){

    
    loop = (f_pointer_void_void *) calloc(NOfStates, sizeof(f_pointer_void_void));

    loop[0] =myStates.State_A.Loop;
    loop[1] = myStates.State_B.Loop;    


};



StatesEnum CurretState;
