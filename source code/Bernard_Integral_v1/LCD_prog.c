/*****************************************/
/*	Author : mohamed salah				 */
/*	Date   : 7-12-2022   		   		 */
/*	Version: 0.1				         */
/*****************************************/


#include "STD_types.h"
#include "Bit_math.h"
#define  F_CPU 16000000UL
#include <util/delay.h>
#include "DIO_interface.h"
#include "LCD_private.h"
#include "LCD_config.h"
#include "LCD_interface.h"





#if LCD_U8_Mode == LCD_8Bit_mode

void LCD_Void_Init(void){
	_delay_ms(35);
	LCD_voidSendCommand(0b00111000);
	_delay_ms(1);
	LCD_voidSendCommand(0b00001100);
	_delay_ms(1);
	LCD_voidSendCommand(0b00000001);
	_delay_ms(2);
	LCD_voidSendCommand(0b00000110);
	
	
}   
    
	
void LCD_voidSendData(u8 Local_u8Data){
	
		// RS - > high
	DIO_Void_SetPin(LCD_u8_RS_PORT , LCD_u8_RS_PIN) ;
	
	// R/W - > low 
    DIO_Void_ClearPin(LCD_u8_RW_PORT , LCD_u8_RW_PIN) ;
	
	// write command
	DIO_VoidSetPortValue(LCD_u8_Data_PORT , u8 Local_u8Data)
	
	// enable pulse
	DIO_Void_SetPin(LCD_u8_E_PORT , LCD_u8_E_PIN) ;
	_delay_ms(1);
	DIO_Void_ClearPin(LCD_u8_E_PORT , LCD_u8_E_PIN) ;
	_delay_ms(1);	
	
	
}

void LCD_voidSendCommand(u8 Local_u8Data){
	
		// RS - > low
	DIO_Void_ClearPin(LCD_u8_RS_PORT , LCD_u8_RS_PIN) ;
	
	// R/W - > low 
	DIO_Void_ClearPin(LCD_u8_RW_PORT , LCD_u8_RW_PIN) ;
	
	// write command
	DIO_VoidSetPortValue(LCD_u8_Data_PORT, Local_u8Command);
	
	// enable pulse
	DIO_Void_SetPin(LCD_u8_E_PORT , LCD_u8_E_PIN) ;
	_delay_ms(1);
	DIO_Void_ClearPin(LCD_u8_E_PORT , LCD_u8_E_PIN) ;
	_delay_ms(1);
	
	
}

void LCD_voidClearScreen(void){
	
	LCD_voidSendCommand(0b00000001);
	
}

void LCD_voidSetCursor(u8 Local_u8Row , u8 Local_u8Column)
{
	u8 Local_u8Address;
	switch(Local_u8Row)
	{
		case 0: 
			Local_u8Address = 0x80 + Local_u8Column;
			break;
		case 1:
			Local_u8Address = 0x80 + 0x40 + Local_u8Column;
			break;
	}
	
	LCD_voidSendCommand(Local_u8Address);
	_delay_ms(1);
}





#elif LCD_U8_Mode == LCD_4Bit_mode

	
void LCD_Void_Init(void)

{	_delay_ms(20);
	LCD_voidSendCommand(0x33);
	LCD_voidSendCommand(0x32);	/* Send for 4 bit initialization of LCD  */
	LCD_voidSendCommand(0x28);	/* 2 line, 5*7 matrix in 4-bit mode */
	LCD_voidSendCommand(0x0c);	/* Display on cursor off */
	LCD_voidSendCommand(0x06);	/* Increment cursor (shift cursor to right) */
	LCD_voidSendCommand(0x01);	/* Clear display screen */

}

void LCD_voidSendData(u8 Local_u8Data)
{
	u8 Local_u8Temp;
	// RS - > low
	DIO_Void_SetPin(LCD_u8_RS_PORT , LCD_u8_RS_PIN) ;
	
	// R/W - > low 
	DIO_Void_ClearPin(LCD_u8_RW_PORT , LCD_u8_RW_PIN) ;
	
	// send high nibble
	Local_u8Temp = Local_u8Data & 0b11110000;
	DIO_VoidSetPortValue(LCD_u8_Data_PORT, Local_u8Temp);
	
	// enable pulse
    DIO_Void_SetPin(LCD_u8_E_PORT , LCD_u8_E_PIN );
	_delay_ms(1);
	DIO_Void_ClearPin(LCD_u8_E_PORT , LCD_u8_E_PIN) ;
	_delay_ms(1);
	
	// send low nibble
	Local_u8Temp = Local_u8Data << 4;
	DIO_VoidSetPortValue(LCD_u8_Data_PORT , Local_u8Temp);
	
	// enable pulse
	DIO_Void_SetPin(LCD_u8_E_PORT , LCD_u8_E_PIN) ;
	_delay_ms(1);
	DIO_Void_ClearPin(LCD_u8_E_PORT , LCD_u8_E_PIN) ;
	_delay_ms(1);
}


void LCD_voidSendCommand(u8 Local_u8Command)
{
	u8 Local_u8Temp;
	// RS - > low
	DIO_Void_ClearPin(LCD_u8_RS_PORT , LCD_u8_RS_PIN) ;
	
	// R/W - > low 
	DIO_Void_ClearPin(LCD_u8_RW_PORT , LCD_u8_RW_PIN) ;
	
	// send high nibble
	Local_u8Temp = Local_u8Command & 0b11110000;
	DIO_VoidSetPortValue(LCD_u8_Data_PORT , Local_u8Temp);
	
	// enable pulse
	DIO_Void_SetPin(LCD_u8_E_PORT , LCD_u8_E_PIN) ;
	_delay_ms(1);
	DIO_Void_ClearPin(LCD_u8_E_PORT , LCD_u8_E_PIN) ;
	_delay_ms(1);
	
	// send low nibble
	Local_u8Temp = Local_u8Command << 4;
	DIO_VoidSetPortValue(LCD_u8_Data_PORT, Local_u8Temp);
	
	// enable pulse
	DIO_Void_SetPin(LCD_u8_E_PORT , LCD_u8_E_PIN) ;
	_delay_ms(1);
	DIO_Void_ClearPin(LCD_u8_E_PORT , LCD_u8_E_PIN) ;
	_delay_ms(1);
}



void LCD_voidClearScreen(void)
{
	LCD_voidSendCommand(0b00000001);
}

void LCD_voidSendString(u8* Local_u8Data)///how 
{
	u8 Local_u8Index = 0;
	while(Local_u8Data[Local_u8Index] != '\0')
	{
		LCD_voidSendData(Local_u8Data[Local_u8Index]);
		Local_u8Index++;
	}
}

void LCD_Display_Number(u16 Local_u32Data){
	
	u8 Arr_String [6];


	itoa(Local_u32Data,Arr_String,10);
	
   LCD_voidSendString(Arr_String);
	
}


void LCD_voidSetCursor(u8 Local_u8Row , u8 Local_u8Column)
{
	u8 Local_u8Address=0x00;
	switch(Local_u8Row)
	{
		case 0: 
			Local_u8Address = 0x80 + Local_u8Column;
			break;
		case 1:
			Local_u8Address = 0x80 + 0x40 + Local_u8Column;
			break;
	}
	
	LCD_voidSendCommand(Local_u8Address);
	_delay_ms(1);
}




#endif
