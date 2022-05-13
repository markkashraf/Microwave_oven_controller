//RS and EN are connected to PB0 and PB2 respectively
//data4-7 of lcd are connected to PB4-7
//rows (input) are connected to PE0-3
//columns (output) are connected to PC4-7
//PA2-4 are initialized to be used later with buzzer and push button

#include "tm4c123gh6pm.h"


void Leds_init(void){
	SYSCTL_RCGCGPIO_R |= 0X20;
	while((SYSCTL_PRGPIO_R &= 0X20) == 0);
	GPIO_PORTF_LOCK_R = 0x4C4F434B;
	GPIO_PORTF_CR_R |= 0x0E;
	GPIO_PORTF_AMSEL_R &= ~0x0E;
	GPIO_PORTF_PCTL_R &= ~0x0000FFF0;
	GPIO_PORTF_AFSEL_R &= ~0x0E;
	GPIO_PORTF_DIR_R |= 0x0E;
	GPIO_PORTF_DEN_R |= 0x0E;
	GPIO_PORTF_DATA_R &= ~0x0E;	
}

void SW1_Init(void)
{
	SYSCTL_RCGCGPIO_R |= 0x20;
	while((SYSCTL_PRGPIO_R&0X20)==0);
	GPIO_PORTF_LOCK_R = GPIO_LOCK_KEY;
	GPIO_PORTF_AMSEL_R &=~ 0X10;
	GPIO_PORTF_CR_R |=0X10;
	GPIO_PORTF_PCTL_R &=~0X000F0000;
	GPIO_PORTF_AFSEL_R &=~0X10;
	GPIO_PORTF_DIR_R &=~ 0X10;
	GPIO_PORTF_DEN_R |= 0X10;
	GPIO_PORTF_PUR_R |= 0x10;
}
void SW2_Init(void)
{
	SYSCTL_RCGCGPIO_R |= 0x20;
	while((SYSCTL_PRGPIO_R&0X20)==0);
	GPIO_PORTF_LOCK_R = GPIO_LOCK_KEY;
	GPIO_PORTF_AMSEL_R &=~ 0X01;
	GPIO_PORTF_CR_R |=0X01;
	GPIO_PORTF_PCTL_R &=~0X0000000F;
	GPIO_PORTF_AFSEL_R &=~0X01;
	GPIO_PORTF_DIR_R &=~ 0X01;
	GPIO_PORTF_DEN_R |= 0X01;
	GPIO_PORTF_PUR_R |= 0x01;
}

void PortA_init(void){         
	SYSCTL_RCGCGPIO_R |= 0x01;
	while((SYSCTL_PRGPIO_R &= 0x01) == 0);
	GPIO_PORTA_AMSEL_R &= ~0x1C;  
	GPIO_PORTA_PCTL_R &= ~0x000FFF00;
	GPIO_PORTA_AFSEL_R &= ~0x1C;
	GPIO_PORTA_DIR_R |= 0x1C;
	GPIO_PORTA_DEN_R |= 0x1C;
	GPIO_PORTA_DATA_R &= ~0x1C;	
}

void PortB_init(void){        
	SYSCTL_RCGCGPIO_R |= 0x02;
	while((SYSCTL_PRGPIO_R &= 0x02) == 0);
	GPIO_PORTB_AMSEL_R &= ~0xFF;
	GPIO_PORTB_PCTL_R &= ~0xFFFFFFFF;
	GPIO_PORTB_AFSEL_R &= ~0xFF;
	GPIO_PORTB_DIR_R |= 0xFF;
	GPIO_PORTB_DEN_R |= 0xFF;
	GPIO_PORTB_DATA_R &= ~0xFF;	
}

void PortC_init(void){        // columns
	SYSCTL_RCGCGPIO_R |= 0x04;
	while((SYSCTL_PRGPIO_R &= 0x04) == 0);
	GPIO_PORTC_AMSEL_R &= ~0xF0;
	GPIO_PORTC_PCTL_R &= ~0xFFFF0000;
	GPIO_PORTC_AFSEL_R &= ~0xF0;
	GPIO_PORTC_DIR_R |= 0xF0;
	GPIO_PORTC_DEN_R |= 0xF0;
	GPIO_PORTC_DATA_R &= ~0xF0;	
	 
	
	
}

void PortE_init(void){       // rows
	SYSCTL_RCGCGPIO_R |= 0x10;
	while((SYSCTL_PRGPIO_R &= 0x010) == 0);
	GPIO_PORTE_AMSEL_R &= ~0x0F;
	GPIO_PORTE_PCTL_R &= ~0x0000FFFF;
	GPIO_PORTE_CR_R |= 0x0F;
	GPIO_PORTE_AFSEL_R &= ~0x0F;
	GPIO_PORTE_DIR_R &= ~0x0F;    
	GPIO_PORTE_DEN_R |= 0x0F;
	GPIO_PORTE_PDR_R |= 0x0F;
	GPIO_PORTE_DATA_R &= ~0x0F;	
}
