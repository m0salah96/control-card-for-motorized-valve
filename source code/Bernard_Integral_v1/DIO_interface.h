/***********************************************/
/****By:mohamed salah***************************/
/****DIO_INTERFACE.H   ***************************/
/****24/6/2022 9:35pm Portsaid East**************/ 

#ifndef DIO_INTERFACE_H_
#define DIO_INTERFACE_H_


#define DIO_u8_HIGH 1
#define DIO_u8_LOW  0

void DIO_Void_Init(void);


// DIO_U8_PORT ( DIO_U8_PORTA or DIO_U8_PORTB OR DIO_U8_PORTC OR DIO_U8_PORTD )

/* DIO_U8_Pin  (DIO_U8_Pin0 or DIO_U8_Pin1 or DIO_U8_Pin2 or DIO_U8_Pin3 or DIO_U8_Pin4 or
                DIO_U8_Pin5  or DIO_U8_Pin6 or DIO_U8_Pin7 ) */

void DIO_Void_SetPin(u8 DIO_U8_PORT , u8 DIO_U8_Pin) ;
void DIO_Void_ClearPin(u8 DIO_U8_PORT , u8 DIO_U8_Pin) ;
u8 DIO_VoidGetPinValue(u8 DIO_U8_PORT,u8 DIO_U8_Pin);
void DIO_VoidSetPortValue(u8 DIO_u8Port , u8 DIO_u8Val);


#define DIO_U8_PORTA 5
#define DIO_U8_PORTB 6
#define DIO_U8_PORTC 7
#define DIO_U8_PORTD 8

#define DIO_U8_Pin0  0
#define DIO_U8_Pin1  1
#define DIO_U8_Pin2  2
#define DIO_U8_Pin3  3
#define DIO_U8_Pin4  4
#define DIO_U8_Pin5  5
#define DIO_U8_Pin6  6
#define DIO_U8_Pin7  7




#endif