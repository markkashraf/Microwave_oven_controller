#include "Timer.h"
#include "FSMmanager.h"

void Timer_Enter(int minutes ,int seconds)
{
CurrentState = Timer;
int i , j;

for(i = minutes; i>=0; i--)
{
    
for(j = seconds; j>=0; j--)
{
    
    LCD4bits_Data((i/10)+'0');// Send second digit in minutes

    LCD4bits_Data((i%10)+'0'); // Send first digit in minutes

    LCD4bits_Data(':');

    LCD4bits_Data((j/10)+'0'); // Send second digit in seconds

    LCD4bits_Data((j%10)+'0'); // Send first digit in seconds

    systick_delay_msec(1000); //wait 1 sec
    
    LCD4bits_Cmd(lcd_clear); // clear screen

    }
    seconds = 59; //after first second all minutes are 60 seconds

    }
    
   
    
}


void Timer_Loop()
{
    printf("Timer_looping\n");
}


void Timer_Output()
{
     printf("Timer_output\n");
}

void Timer_Init()
{
     myStates.Timer.Enter  = Timer_Enter;
     myStates.Timer.Loop   = Timer_Loop;
     myStates.Timer.Output = Timer_Output;
     loop[Timer] = myStates.Timer.Loop;

}
