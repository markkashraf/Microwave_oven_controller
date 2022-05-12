#include <stdio.h>


void State_A_Enter()
{
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

typedef void (*f_pointer_void_void)(void);


typedef struct StateStruct
{
    f_pointer_void_void Enter;
    f_pointer_void_void Loop;
    f_pointer_void_void Output;
} StateStruct;
 




int main()
{
    
    
    StateStruct  State_A = {State_A_Enter , State_A_Loop, State_A_Output};
    State_A.Enter();
    
    

    return 0;
}
