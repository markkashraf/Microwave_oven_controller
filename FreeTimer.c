#include "FreeTimer.h"
#include "FSMmanager.h"
#include "keypad.h"
#include "ports_init.h"
#include "lcd_functions.h"
#include "delays.h"
#include "tm4c123gh6pm.h"

char arr[4];
char k;

int i,j,r,t,p;

void FreeTimer_Enter()  
{
     CurrentState = FreeTimer;
			i = 0, r = 0, t = 0,p = 0;
			for(p = 0; p<4; p++)arr[p] = '0';
			myStates.FreeTimer.Output();		
}

void FreeTimer_Loop()
{
	
	systick_delay_msec(500);
	
	if(i == 2)Cursor_Left(4);
	
	else if(i == 3) Cursor_Left(5);
	
	else Cursor_Left(i+1);
	
	k = get_keypad_input();
		//if start button is pressed
	 if(k == 'x')
		 {
		 
			LCD4bits_Cmd(0x01);
		 //only one number is currently displayed
			if(i == 1){
				 myStates.Timer.Enter((arr[3]-48)*10 + arr[2]-48 , (arr[1]-48)*10 + arr[0]-48);
					return;
			}
			//two numbers are currently displayed
			else if(i == 2){
				 myStates.Timer.Enter((arr[3]-48)*10 + arr[2]-48 , (arr[0]-48)*10 + arr[1]-48);
					return;
			}
			//three numbers are currently displayed
			else if(i == 3){
				 myStates.Timer.Enter((arr[3]-48)*10 + arr[0]-48 , (arr[1]-48)*10 + arr[2]-48);
					return;
			}
			//four numbers are currently displayed
			else if(i == 4){
				myStates.Timer.Enter((arr[0]-48)*10 + arr[1]-48 , (arr[2]-48)*10 + arr[3]-48);
				return;
				}
		 }
	 
	 //if pause button is pressed
	 else if(k == 'z')
	{
		 myStates.Idle.Enter();
		 return;
	 }
	 
	 //if an illegal button is pressed
	 else if(k > 57 || k < 48)
   {
		 LCD4bits_Cmd(0x01);
		 LCD_WriteString("Err");
		 systick_delay_msec(1500);
		 myStates.FreeTimer.Enter();
		 return;
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
			LCD4bits_Cmd(0x01);
			LCD_WriteString("Cooking time?");
			LCD4bits_Cmd(0xC0);
			LCD_WriteString("00:00");
			LCD4bits_Cmd(0x0C);
}

void FreeTimer_Init()
{
     myStates.FreeTimer.Enter  = FreeTimer_Enter;
     myStates.FreeTimer.Loop   = FreeTimer_Loop;
     myStates.FreeTimer.Output = FreeTimer_Output;
     loop[FreeTimer] = myStates.FreeTimer.Loop;

}
