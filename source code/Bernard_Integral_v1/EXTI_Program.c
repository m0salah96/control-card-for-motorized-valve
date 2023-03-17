/***********************************************/
/****By:mohamed salah***************************/
/****EXTI_PROGRAM.H   ***************************/
/***1/7/2022 13:06 pm HOME**************/ 

#include "STD_types.h"
#include "Bit_math.h"
#include "EXTI_Private.h"
#include "EXTI_Config.h"
#include "EXTI_Interface.h"


void EXTI0_Init(void){
	#if EXTI0_u8_ISC ==EXTI0_u8_LOW_Level
	ClearBit(MCUCR,ISC00);  
	ClearBit(MCUCR,ISC01);
	#elif EXTI0_u8_ISC ==EXTI0_u8_RISING
	SetBit(MCUCR,ISC00);  
	ClearBit(MCUCR,ISC01);	
    #elif EXTI0_u8_ISC ==EXTI0_u8_FALLING
	ClearBit(MCUCR,ISC00);  
	SetBit(MCUCR,ISC01);	
    #elif EXTI0_u8_ISC ==EXTI0_u8_ANY_CHANGE
	SetBit(MCUCR,ISC00);  
	SetBit(MCUCR,ISC01);
    #endif
    EXTI0_ClearFlag() ;
}
void EXTI0_Enable(void){
	SetBit(GICR,INT0);
}
void EXTI0_Disable(void){
	ClearBit(GICR,INT0);
	
}
void EXTI0_ClearFlag(void){
	
	SetBit(GIFR,INTF0);
}
/********************************************/
void EXTI1_Init(void){
	#if EXTI1_u8_ISC ==EXTI1_u8_LOW_Level
	ClearBit(MCUCR,ISC10);  
	ClearBit(MCUCR,ISC11);
	#elif EXTI1_u8_ISC ==EXTI1_u8_RISING
	SetBit(MCUCR,ISC10);  
	ClearBit(MCUCR,ISC11);	
    #elif EXTI1_u8_ISC ==EXTI1_u8_FALLING
	ClearBit(MCUCR,ISC10);  
	SetBit(MCUCR,ISC11);	
    #elif EXTI1_u8_ISC ==EXTI1_u8_ANY_CHANGE
	SetBit(MCUCR,IS10);  
	SetBit(MCUCR,ISC11);
    #endif
    EXTI1_ClearFlag() ;
}
void EXTI1_Enable(void){
	SetBit(GICR,INT1);
}
void EXTI1_Disable(void){
	ClearBit(GICR,INT1);
	
}
void EXTI1_ClearFlag(void){
	
	SetBit(GIFR,INTF1);
}
/********************************************/
void EXTI2_Init(void){
	#if EXTI0_u8_ISC ==EXTI0_u8_RISING
	SetBit(MCUCSR,ISC2);  
    #elif EXTI0_u8_ISC ==EXTI0_u8_FALLING
	ClearBit(MCUCSR,ISC2);  	
    #endif
    EXTI2_ClearFlag() ;
}
void EXTI2_Enable(void){
	SetBit(GICR,INT2);
}
void EXTI2_Disable(void){
	ClearBit(GICR,INT2);
	
}
void EXTI2_ClearFlag(void){
	
	SetBit(GIFR,INTF2);
}
/********************************************/
