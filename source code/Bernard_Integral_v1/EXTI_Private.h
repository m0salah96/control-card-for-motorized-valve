/***********************************************/
/****By:mohamed salah***************************/
/****EXTI_CONFIG.H   ***************************/
/***1/7/2022 13:06 pm HOME**************/ 

#ifndef EXTI_PRIVATE_H_
#define EXTI_PRIVATE_H_

#define GICR *((volatile u8*)0x5B)//general interrupt control register "prepheral interrupt enable"
#define INT0   6
#define INT1   7
#define INT2   5

#define MCUCR *((volatile u8*)0x55) //configuration of En0,1
#define ISC00    0
#define ISC01    1
#define ISC10    2
#define ISC11    3

#define MCUCSR *((volatile u8*)0x54) //configuration of En 2
#define ISC2   0

#define GIFR *((volatile u8*)0x5A)//general interrupt flag register 
#define INTF1   6
#define INTF0   7
#define INTF2   5

//configuration

#define EXTI0_u8_LOW_Level  10
#define EXTI0_u8_RISING     20
#define EXTI0_u8_FALLING    30
#define EXTI0_u8_ANY_CHANGE 40

#define EXTI1_u8_LOW_Level  50
#define EXTI1_u8_RISING     60
#define EXTI1_u8_FALLING    70
#define EXTI1_u8_ANY_CHANGE 80


#define EXTI2_u8_LOW_Level  90
#define EXTI2_u8_RISING     100
#define EXTI2_u8_FALLING    110
#define EXTI2_u8_ANY_CHANGE 120






#endif
