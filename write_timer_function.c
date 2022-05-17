// this was an initial implementation and was modified in Freetimer.c


void Enter_time(void){
		char x,y,z,c;
	LCD_WriteString("00:00");
	LCD4bits_Cmd(0x0C);    //display on , cursor off\
	//variables to store the input characters from keypad
	x=0;
	y=0;
	z=0;
	c=0;
	systick_delay_msec(350);
	Cursor_left(1);
	x = get_keypad_input();
	LCD4bits_Data(x);
	
	Cursor_left(2);
	systick_delay_msec(350);
	
	y = get_keypad_input();
	LCD4bits_Data(x);
	LCD4bits_Data(y);
	
	Cursor_left(4);
	systick_delay_msec(350);
	
	z = get_keypad_input();
	LCD4bits_Data(x);
	Cursor_Right(1);
	systick_delay_msec(50);
	LCD4bits_Data(y);
	LCD4bits_Data(z);
	
	Cursor_left(5);
	systick_delay_msec(350);
	c = get_keypad_input();
	LCD4bits_Data(x);
	LCD4bits_Data(y);
	
	Cursor_Right(1);
	systick_delay_msec(50);
	LCD4bits_Data(z);
	LCD4bits_Data(c);
