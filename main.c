#include <stdio.h>

void funMyfun()
{
     printf("Hello World");
}


int main()
{
    
   void (*p) () = funMyfun;
   (*p) ();

    return 0;
}
