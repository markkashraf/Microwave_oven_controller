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



void State_B_Enter(int x)
{
     printf("State_B_Entered and the enter Parameter is %i \n", x);
}


void State_B_Loop()
{
     printf("State_B_looping\n");
}


void State_B_Output()
{
     printf("State_B_output\n");
}



typedef void (*f_pointer_void_void)(void);
typedef void (*f_pointer_void_int)(int);


typedef struct StateNoParameters
{
    f_pointer_void_void Enter;
    f_pointer_void_void Loop;
    f_pointer_void_void Output;
} StateNoParameters;

typedef struct StateOneEnterParameter
{
    f_pointer_void_int Enter;
    f_pointer_void_void Loop;
    f_pointer_void_void Output;
} StateOneEnterParameter;
 
 


int main()
{
    
    
    StateNoParameters  State_A = {State_A_Enter , State_A_Loop, State_A_Output};
    State_A.Enter();
    
    StateOneEnterParameter  State_B = {State_B_Enter , State_B_Loop, State_B_Output};
    State_B.Enter(5);
    
    

    return 0;
}
