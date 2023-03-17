/***********************************************/
/****By:eng mohamed salah***************************/
/****Bernard_Config.h   ***************************/
/****30/6/2022 1:53 pm Home**************/

#ifndef Bernard_CONFIG_H_
#define Bernard_CONFIG_H_

/**********************************/
/*Local control*/
#define  L_C_Port  
#define  L_C_REMOTE     DIO_U8_Pin0
#define  L_C_LOCAL      DIO_U8_Pin1               
#define  L_C_OFF        DIO_U8_Pin2 
#define  L_C_OPEN       DIO_U8_Pin3 
#define  L_C_CLOSE      DIO_U8_Pin4
 
#define  L_C_REMOTE_PORT    DIO_U8_PORTA
#define  L_C_LOCAL_PORT     DIO_U8_PORTA
#define  L_C_OFF_PORT      DIO_U8_PORTA
#define  L_C_OPEN_PORT      DIO_U8_PORTA
#define  L_C_CLOSE_PORT     DIO_U8_PORTA
/**********************************/
/*Valve status*/
  
#define  L_S_THERMAL      DIO_U8_Pin0
#define  L_S_HANDWHEEL    DIO_U8_Pin1
#define  L_S_CLOSED       DIO_U8_Pin2
#define  L_S_OPENED       DIO_U8_Pin3
#define  L_S_CLOSE_TORQUE DIO_U8_Pin4
#define  L_S_OPEN_TORQUE  DIO_U8_Pin5

#define  L_S_THERMAL_PORT       DIO_U8_PORTC
#define  L_S_HANDWHEEL_PORT     DIO_U8_PORTC
#define  L_S_CLOSED_PORT        DIO_U8_PORTC
#define  L_S_OPENED_PORT        DIO_U8_PORTC
#define  L_S_CLOSE_TORQUE_PORT  DIO_U8_PORTC
#define  L_S_OPEN_TORQUE_PORT   DIO_U8_PORTC
/***********************************/
/*Remote control*/
#define  R_OPEN_COMMAND              DIO_U8_Pin5
#define  R_CLOSE_COMMAND             DIO_U8_Pin6
#define  R_OPEN_COMMAND_PORT               DIO_U8_PORTD
#define  R_CLOSE_COMMAND_PORT              DIO_U8_PORTD  
             
/**********************************/
/*Remote FBK*/
#define  CLOSED_FBK     DIO_U8_Pin0
#define  OPENED_FBK     DIO_U8_Pin1
#define  AVAIL_FBK      DIO_U8_Pin2
#define  CLOSED_FBK_PORT     DIO_U8_PORTD
#define  OPENED_FBK_PORT     DIO_U8_PORTD
#define  AVAIL_FBK_PORT      DIO_U8_PORTD
/************************************/
/*Motor control*/
#define  MOTOR_OPEN            DIO_U8_Pin3
#define  MOTOR_CLOSE           DIO_U8_Pin4
#define  MOTOR_OPEN_PORT         DIO_U8_PORTD
#define  MOTOR_CLOSE_PORT      DIO_U8_PORTD


#endif