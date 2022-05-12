#include <stdio.h>

void funMyfun()
{
     printf("Hello World");
}


typedef void (*f_pointer_void_void)(void);

/*This creates a type, named f_pointer_void_void for a pointer to a function that takes a void argument and returns nothing, 
which matches the signature of the functions we will need

*/
int main()
{
    
   f_pointer_void_void p  = funMyfun;
   (*p) ();

    return 0;
}
