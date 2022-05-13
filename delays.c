#include "tm4c123gh6pm.h"


//extra delay functions

void delay_micro(int n){
      int i,j;
      for(i=0;i<n;i++)
      for(j=0;j<3;j++)

}

//systick delay functions
void SysTick_Wait(unsigned long delay) // delay = number of ticks
{
      NVIC_ST_CTRL_R = 0X00;
      NVIC_ST_RELOAD_R = delay - 1;
      NVIC_ST_CURRENT_R = 0;
      NVIC_ST_CTRL_R = 0X05; // ENABLE TIMER AND CLK SRC
      while((NVIC_ST_CTRL_R&0x00010000)==0) 
      {
      //wait for count flag
      }
}

void SysTick_Wait1ms()
{
      SysTick_Wait(16000);
}
void systick_delay_msec(int t) //delay by milli seconds.
{
      int i; 
      for(i=0; i<t; i++)
            {
            SysTick_Wait1ms();
            }
}
