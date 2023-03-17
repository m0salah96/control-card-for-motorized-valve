
#include <avr/io.h>
#define F_CPU 16000000UL
#include <avr/delay.h>
#include "Bit_math.h"
#include "STD_types.h"
#include "Bernard_Interface.h"

int main(void)
{ 
	

	
 valve_initialization();
		

    while (1) 
    {
  valve_operation();						
	}
}

