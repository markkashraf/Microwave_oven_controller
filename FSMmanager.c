#include "FSMmanager.h"
#include "Idle.h"
#include "Popcorn.h"
#include "BeefChicken.h"
#include "FreeTimer.h"
#include <stdlib.h>
#define NOfStates 7



f_pointer_void_void* loop;


States myStates;

void FSM_SetUp()
{
    loop = (f_pointer_void_void*)calloc(NOfStates, sizeof(f_pointer_void_void));
    /*we cannot free the memory we allocated for the array as we are using it throughout
    the whole program which is running consciously as we are jumping from a state to another one*/
    Idle_SetUp();
    Popcorn_SetUp();
    BeefChicken_SetUp();
    FreeTimer_SetUp();
    Pause_SetUp();
		Timer_SetUp();
    Locked_SetUp();
};

StatesEnum CurrentState;
