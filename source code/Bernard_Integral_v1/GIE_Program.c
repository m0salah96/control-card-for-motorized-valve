/*************************************************/
/****By:mohamed salah*****************************/
/****GIE_interface.H   ***************************/
/****2/7/2022 9:35pm Home*************************/ 
#include "STD_types.h"
#include "Bit_math.h"
#include "GIE_Private.h"
#include "GIE_Interface.h"




void GIE_Enable(void){
	
	SetBit(SREG,7);
	
}

void GIE_Disable(void){
	
		ClearBit(SREG,7);
	
}
