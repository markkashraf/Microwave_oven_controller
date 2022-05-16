#include "Locked.h"
#include "FSMmanager.h"
#include "keypad.h"
#include "ports_init.h"
#include "lcd_functions.h"
#include "delays.h"



void Locked_Enter(int* arry)
{

}


void Locked_Loop()
{
		
    

}


void Locked_Output()
{
}

void Locked_Init()
{
     myStates.Locked.Enter  = Locked_Enter;
     myStates.Locked.Loop   = Locked_Loop;
     myStates.Locked.Output = Locked_Output;
     loop[Locked] = myStates.Locked.Loop;
}

