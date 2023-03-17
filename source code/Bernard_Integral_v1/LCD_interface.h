/*****************************************/
/*	Date   : 7-12-2022   		   		 */
/*	Version: 0.1				         */
/*	File   : LCD_interface.h		     */
/*****************************************/



#ifndef _LCD_INTERFACE_H_
#define _LCD_INTERFACE_H_


void LCD_Void_Init(void);

void LCD_voidSendData(u8 Local_u8Data);

void LCD_Display_Number(u16 Local_u32Data);

void LCD_voidSendCommand(u8 Local_u8Data);

void LCD_voidClearScreen(void);

void LCD_voidSetCursor(u8 Local_u8Row, u8 Local_u8Column);

void LCD_voidSendString (u8* Local_u8Data);   










#endif