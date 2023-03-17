/***********************************************/
/****By:mohamed salah***************************/
/****DIO_PROGRAM.C   ***************************/
/****24/6/2022 9:35pm Portsaid East**************/

#ifndef DIO_PROGRAM_C_
#define DIO_PROGRAM_C_

#include "STD_types.h"
#include "Bit_math.h"
#include "DIO_private.h"
#include "DIO_configuration.h"
#include "DIO_interface.h"



/*********************************/
void DIO_Void_Init(void){
	
	DDRA = DIO_u8_DIR_PORTA;
	DDRB = DIO_u8_DIR_PORTB;
	DDRC = DIO_u8_DIR_PORTC;
	DDRD = DIO_u8_DIR_PORTD;
	
}
/*************************************/
void DIO_Void_SetPin(u8 DIO_U8_PORT , u8 DIO_U8_Pin) {

switch(DIO_U8_PORT){
case DIO_U8_PORTA:
  SetBit(PORTA,DIO_U8_Pin);
  break;
case DIO_U8_PORTB:
SetBit(PORTB,DIO_U8_Pin);
break;
case DIO_U8_PORTC:
SetBit(PORTC,DIO_U8_Pin);
break;	
case DIO_U8_PORTD:
SetBit(PORTD,DIO_U8_Pin);
break;		
}

}
/*************************************/
void DIO_Void_ClearPin(u8 DIO_U8_PORT , u8 DIO_U8_Pin) {

	switch(DIO_U8_PORT){
		case DIO_U8_PORTA:
		ClearBit(PORTA,DIO_U8_Pin);
		break;
		case DIO_U8_PORTB:
		ClearBit(PORTB,DIO_U8_Pin);
		break;
		case DIO_U8_PORTC:
		ClearBit(PORTC,DIO_U8_Pin);
		break;
		case DIO_U8_PORTD:
		ClearBit(PORTD,DIO_U8_Pin);
		break;
	}

}
/**********************************************/
u8 DIO_VoidGetPinValue(u8 DIO_U8_PORT,u8 DIO_U8_Pin){
	
	
	switch(DIO_U8_PORT){
		case DIO_U8_PORTA:
		return GetBit(PINA,DIO_U8_Pin);
		break;
		case DIO_U8_PORTB:
		return GetBit(PINB,DIO_U8_Pin);
		break;
		case DIO_U8_PORTC:
		return GetBit(PINC,DIO_U8_Pin);
		break;
		case DIO_U8_PORTD:
		return GetBit(PIND,DIO_U8_Pin);
		break;
	
}
}
/**************************************************/
void DIO_VoidSetPortValue(u8 DIO_U8_PORT, u8 DIO_U8_Val){
	
	switch(DIO_U8_PORT){
		case DIO_U8_PORTA:
	    PORTA=DIO_U8_Val;
		break;
		case DIO_U8_PORTB:
	    PORTB=DIO_U8_Val;
		break;
		case DIO_U8_PORTC:
		PORTC=DIO_U8_Val;
		break;
		case DIO_U8_PORTD:
		PORTD=DIO_U8_Val;
		break;
	
	
	}
}


#endif
