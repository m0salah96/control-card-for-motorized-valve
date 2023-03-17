/***********************************************/
/****By:mohamed salah***************************/
/****DIO_PRIVATE.H   ***************************/
/****24/6/2022 9:35pm Portsaid East**************/ 



#ifndef BIT_MATH_H_
#define BIT_MATH_H_

#define  SetBit(Val_8_Bit,Bit_Num)      Val_8_Bit=Val_8_Bit|(1<<Bit_Num)
#define  ClearBit(Val_8_Bit,Bit_Num)    Val_8_Bit=Val_8_Bit&~(1<<Bit_Num)
#define  GetBit(Val_8_Bit,Bit_Num)      ((Val_8_Bit>>Bit_Num)&1)
#define  ToggleBit(Val_8_Bit,Bit_Num)   Val_8_Bit=Val_8_Bit^(1<<Bit_Num)
#define  ClearPort(Val_8_Bit)           Val_8_Bit=Val_8_Bit&0b00000000
#define  ConcPort(B7,B6,B5,B4,B3,B2,B1,B0)     (B7<<7)|(B6<<6)|(B5<<5)|(B4<<4)|(B3<<3)|(B2<<2)|(B1<<1)|(B0<<0)  
          
#endif