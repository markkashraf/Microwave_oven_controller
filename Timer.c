#include "Timer.h"
#include "FSMmanager.h"
#include "lcd_functions.h"
#include "tm4c123gh6pm.h"
#include "delays.h"

int min,sec,flag = 0;


void Timer_Enter(int minutes ,int seconds)
{

    myStates.Timer.minutes = minutes;
    myStates.Timer.seconds = seconds;
		min = minutes;
		sec = seconds;
    CurrentState = Timer;

}


void Timer_Loop()
{

Timer_Output();
sec--;
flag = Systick_RF(1000);
LCD4bits_Cmd(0x01);

if(sec == 0 && min ==0)
{
myStates.Idle.Enter();
return;
}

if(sec == -1)
{
min--;
sec = 59;
}

if(flag)
{
	myStates.Pause.Enter(min,sec);

}

}


void Timer_Output()
{
    LCD4bits_Data((min/10)+'0');// Send second digit in minutes
    LCD4bits_Data((min%10)+'0'); // Send first digit in minutes
    LCD4bits_Data(':');
    LCD4bits_Data((sec/10)+'0'); // Send second digit in seconds
    LCD4bits_Data((sec%10)+'0'); // Send first digit in seconds


}



void Timer_Init()
{
     myStates.Timer.Enter  = Timer_Enter;
     myStates.Timer.Loop   = Timer_Loop;
     myStates.Timer.Output = Timer_Output;
     loop[Timer] = myStates.Timer.Loop;

}
