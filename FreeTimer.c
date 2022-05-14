#include "FreeTimer.h"
#include "FSMmanager.h"
#include "keypad.h"
#include "ports_init.h"
#include "lcd_functions.h"
#include "delays.h"
#include "tm4c123gh6pm.h"

char arr[4] = {'0','0','0','0'};
char k;

int i = 0,j,r = 0, t = 0,fl;

void FreeTimer_Enter()  
{
     CurrentState = FreeTimer;
			LCD4bits_Cmd(0x01);
			LCD_WriteString("00:00");
			LCD4bits_Cmd(0x0C);		
}

void FreeTimer_Loop()
{
	
	systick_delay_msec(500);
	
	if(i == 4)
	{
		myStates.FreeTimer.Output();
		return;
	}
	
	if(i == 2)Cursor_Left(4);
	
	else if(i == 3) Cursor_Left(5);
	
	else Cursor_Left(i+1);
	
	k = get_keypad_input();
	 if(k == 'x'){
		 
		 LCD4bits_Cmd(0x01);
		if(i == 1){
			 myStates.Timer.Enter((arr[3]-48)*10 + arr[2]-48 , (arr[1]-48)*10 + arr[0]-48);
				return;
		}
		else if(i == 2){
			 myStates.Timer.Enter((arr[3]-48)*10 + arr[2]-48 , (arr[0]-48)*10 + arr[1]-48);
				return;
		}
		else if(i == 3){
			 myStates.Timer.Enter((arr[3]-48)*10 + arr[0]-48 , (arr[1]-48)*10 + arr[2]-48);
				return;
		} 
	 }

	arr[i] = k;
	
	for(j=0; j<i+1; j++){
		if(i == 2 && r == 0){
			
			LCD4bits_Data(arr[j]);
			Cursor_Right(1);
			r++;
			
		}
		else if( i == 3 && t == 0){
			LCD4bits_Data(arr[j]);
			LCD4bits_Data(arr[j+1]);
			Cursor_Right(1);
			t++;
			j++;
		}
		else LCD4bits_Data(arr[j]);
		
	}
	
	i++;
	    
}


void FreeTimer_Output()
{
			while(!(Switch2_input() == 0));
			LCD4bits_Cmd(0x01);
     myStates.Timer.Enter((arr[0]-48)*10 + arr[1]-48 , (arr[2]-48)*10 + arr[3]-48);
}

void FreeTimer_Init()
{
     myStates.FreeTimer.Enter  = FreeTimer_Enter;
     myStates.FreeTimer.Loop   = FreeTimer_Loop;
     myStates.FreeTimer.Output = FreeTimer_Output;
     loop[FreeTimer] = myStates.FreeTimer.Loop;

}
