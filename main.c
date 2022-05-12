#include <stdio.h>

void State_A_Enter()
{
     printf("State_A_Entered\n");
}


void State_A_loop()
{
     printf("State_B_looping\n");
}


void State_A_output()
{
     printf("State_B_output\n");
}

typedef void (*f_pointer_void_void)(void);


int main()
{
    
    f_pointer_void_void p  = State_A_Enter;
    (*p) ();
    p = State_A_loop;
    (*p) ();
    
    

    return 0;
}
