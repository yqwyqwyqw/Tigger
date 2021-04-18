#include "main.h"
#include "stm32f1xx_hal.h"
#include "gpio.h"

#include "74HC595.h"



void HC595_Send_Multi_Byte(uint8_t *data, uint16_t len)
{
	uint8_t i;
	for (i = 0; i < len; i ++ )
	{
		HC595_Send_Byte(data[i]);
	}
	
	HC595_CS();
}

void HC595_Send_Byte(uint8_t byte)
{
	uint8_t  i;
	for (i = 0; i < 8; i ++) 
	{
		if (byte & 0x80){  
			HC595_DS_High();
		}			
		else{                   
			HC595_DS_Low();
		}
		HC595_SHCP_Low();  
		delay(1);         
		HC595_SHCP_High();  
		delay(1);
		
		byte <<= 1;		
	}
}
void HC595_CS(void) 
{

	HC595_STCP_Low(); 
	delay(1); 
	HC595_STCP_High();
	delay(1);
}

void delay(uint16_t t){
	for (; t != 0; t --);
}
