/*13/1/2023 */
/*PROJECT:BERNARD INTEGRAL VALVE */
#define F_CPU 16000000UL
#include <avr/delay.h>
#include "STD_types.h"
#include "Bit_math.h"
#include "Bernard_Private.h"
#include "bernard_Configuration.h"
#include "Bernard_Interface.h"
#include "DIO_interface.h"
#include "LCD_interface.h"
#include "bernard_Configuration.h"

/************************************************/
u8 v_opening_f=0;
u8 v_closing_f=0;
valve_mode v_mode = REMOTE;
valve_position v_position = UNDEFINED; 
remote_command r_command = R_UNDEFINED;	
local_command  l_command = L_UNDEFINED;
/*****************valve mode********************/
void get_valve_mode(void){
	
	
       if(DIO_VoidGetPinValue(L_S_HANDWHEEL_PORT,L_S_HANDWHEEL)==0){
	       
	       v_mode=H_WHEEL;
       DIO_Void_ClearPin(AVAIL_FBK_PORT,AVAIL_FBK); }
	          
        else if(DIO_VoidGetPinValue(L_S_CLOSE_TORQUE_PORT,L_S_CLOSE_TORQUE)==1){
	    	
	    	v_mode=C_TORQUE;
        DIO_Void_ClearPin(AVAIL_FBK_PORT,AVAIL_FBK); }
		
		else if(DIO_VoidGetPinValue(L_S_OPEN_TORQUE_PORT,L_S_OPEN_TORQUE)==1){
			
			v_mode=O_TORQUE;
		DIO_Void_ClearPin(AVAIL_FBK_PORT,AVAIL_FBK); }

		else if(DIO_VoidGetPinValue(L_S_THERMAL_PORT,L_S_THERMAL)==1){
			
			v_mode=TH_FAULT;
			DIO_Void_ClearPin(AVAIL_FBK_PORT,AVAIL_FBK); }
	
	else if(DIO_VoidGetPinValue(L_C_REMOTE_PORT,L_C_REMOTE)==0){
		
		v_mode=REMOTE;
		DIO_Void_SetPin(AVAIL_FBK_PORT,AVAIL_FBK);
	}else if (DIO_VoidGetPinValue(L_C_LOCAL_PORT,L_C_LOCAL)==0)
	{
		v_mode=LOCAL;
		DIO_Void_ClearPin(AVAIL_FBK_PORT,AVAIL_FBK);
	}else if (DIO_VoidGetPinValue(L_C_OFF_PORT,L_C_OFF)==0)
	{
		v_mode=OFF; 
		DIO_Void_ClearPin(AVAIL_FBK_PORT,AVAIL_FBK);
	}else{
		v_mode=STOP;
		DIO_Void_ClearPin(AVAIL_FBK_PORT,AVAIL_FBK);
	}
	
}	
	
	
/**********valve position****/
	

void get_valve_position(void){
	if (DIO_VoidGetPinValue(L_S_OPENED_PORT,L_S_OPENED)==1 && DIO_VoidGetPinValue(L_S_CLOSED_PORT,L_S_CLOSED)==1)
	{  
		v_position = UNDEFINED;
		
	}else if (DIO_VoidGetPinValue(L_S_OPENED_PORT,L_S_OPENED)==1)
	{
		v_position = OPENED;
	}else if(DIO_VoidGetPinValue(L_S_CLOSED_PORT,L_S_CLOSED)==1){
		
		v_position =CLOSED;
	}else{
		
     v_position= TRAVEL;

	}
	
}
/**************remote command**********************/

void get_remote_command(void){
	if (DIO_VoidGetPinValue(R_OPEN_COMMAND_PORT,R_OPEN_COMMAND)==0)
	{
		r_command = R_OPEN;	
	}else if (DIO_VoidGetPinValue(R_CLOSE_COMMAND_PORT,R_CLOSE_COMMAND)==0)
	{
		r_command = R_CLOSE;
	}else{
		r_command =R_UNDEFINED;
	}
	
}

/****local command ******/

void get_local_command(void){
	
		if (DIO_VoidGetPinValue(L_C_OPEN_PORT,L_C_OPEN)==0)
		{
			l_command = L_OPEN;
		}else if (DIO_VoidGetPinValue(L_C_CLOSE_PORT,L_C_CLOSE)==0)
		{
			l_command = L_CLOSE;
		}else{
			l_command=L_UNDEFINED;
		}
	
	
	
}
/****LCD Initialization***/	

void valve_LCD_init(void){
	LCD_voidClearScreen();
	LCD_voidSetCursor(0,6);
	LCD_voidSendString("PSEP");
	_delay_ms(700);
	LCD_voidClearScreen();
	LCD_voidSetCursor(0,0);
	LCD_voidSendString("Status:");
	LCD_voidSetCursor(1,0);
	LCD_voidSendString("Position:");	
}


/****valve DI initialization***/


void valve_DI_init(void){
	
	DIO_Void_SetPin(R_CLOSE_COMMAND_PORT,R_CLOSE_COMMAND);
	DIO_Void_SetPin(R_OPEN_COMMAND_PORT,R_OPEN_COMMAND);
	DIO_Void_SetPin(L_C_REMOTE_PORT,L_C_REMOTE);
	DIO_Void_SetPin(L_C_OFF_PORT,L_C_OFF);
	DIO_Void_SetPin(L_C_LOCAL_PORT,L_C_LOCAL);
	DIO_Void_SetPin(L_C_OPEN_PORT,L_C_OPEN);
	DIO_Void_SetPin(L_C_CLOSE_PORT,L_C_CLOSE);
	DIO_Void_SetPin(L_S_THERMAL_PORT,L_S_THERMAL);
	DIO_Void_SetPin(L_S_HANDWHEEL_PORT,L_S_HANDWHEEL);
	DIO_Void_SetPin(L_S_CLOSED_PORT,L_S_CLOSED);
	DIO_Void_SetPin(L_S_OPENED_PORT,L_S_OPENED);
	DIO_Void_SetPin(L_S_CLOSE_TORQUE_PORT,L_S_CLOSE_TORQUE);
	DIO_Void_SetPin(L_S_OPEN_TORQUE_PORT,L_S_OPEN_TORQUE);	
}

/*****valve driver initialization****/

void valve_drivers_init(void){	
	DIO_Void_Init();
	LCD_Void_Init();
	valve_DI_init();
}
/******print VALVE position*********/

void print_position(void){
	
	switch(v_position){
		case CLOSED:
		LCD_voidSetCursor(1,9);
		LCD_voidSendString("Closed");
		break;
		case OPENED:
		LCD_voidSetCursor(1,9);
		LCD_voidSendString("Opened");
		break;
		case TRAVEL:
		LCD_voidSetCursor(1,9);
		LCD_voidSendString("Travel");
		break;
		case UNDEFINED :
		LCD_voidSetCursor(1,9);
		LCD_voidSendString("Undefi");
	}	
}

/******print VALVE mode******/

void print_mode(void){
	switch(v_mode){
		case LOCAL:
		LCD_voidSetCursor(0,9);
		LCD_voidSendString("LOCAL  ");
		break;
		case REMOTE:
		LCD_voidSetCursor(0,9);
		LCD_voidSendString("REMOTE ");
		break;
		case OFF:
		LCD_voidSetCursor(0,9);
		LCD_voidSendString("OFF    ");
		break;
		case STOP :
		LCD_voidSetCursor(0,9);
		LCD_voidSendString("STOP   ");
		break;
		case H_WHEEL :
		LCD_voidSetCursor(0,9);
		LCD_voidSendString("H_WHEEL");
		break;
		case TH_FAULT :
		LCD_voidSetCursor(0,9);
		LCD_voidSendString("THERMAL");
		break;
		case O_TORQUE :
		LCD_voidSetCursor(0,9);
		LCD_voidSendString("O_TRQUE");
		break;
		case C_TORQUE :
		LCD_voidSetCursor(0,9);
		LCD_voidSendString("C_TRQUE");
		}
	
}

/******UPDATE REMOTE FBK**********/
void remote_fbk_update(void){
	switch(v_position){
		case CLOSED:
        DIO_Void_SetPin(CLOSED_FBK_PORT,CLOSED_FBK);
		DIO_Void_ClearPin(OPENED_FBK_PORT,OPENED_FBK);
		break;
		case OPENED:
        DIO_Void_SetPin(OPENED_FBK_PORT,OPENED_FBK);
		DIO_Void_ClearPin(CLOSED_FBK_PORT,CLOSED_FBK);
		break;
		case TRAVEL:
        DIO_Void_ClearPin(OPENED_FBK_PORT,OPENED_FBK);
        DIO_Void_ClearPin(CLOSED_FBK_PORT,CLOSED_FBK);
		break;
		case UNDEFINED :
        DIO_Void_ClearPin(OPENED_FBK_PORT,OPENED_FBK);
        DIO_Void_ClearPin(CLOSED_FBK_PORT,CLOSED_FBK);
	
	}
}
/******OPEN VALVE RELAY ****************/
void open_valve(void){

		DIO_Void_SetPin(MOTOR_OPEN_PORT,MOTOR_OPEN);

	}                 
	
/**************CLOSE VLAVE RELAY***************/	

void close_valve(void){
	
	DIO_Void_SetPin(MOTOR_CLOSE_PORT,MOTOR_CLOSE);
	
}
/**********************STOP VALVE*****************/
void stop_valve(void){
	
	DIO_Void_ClearPin(MOTOR_CLOSE_PORT,MOTOR_CLOSE);
	DIO_Void_ClearPin(MOTOR_OPEN_PORT,MOTOR_OPEN);
}


/*******************INITIALIZE VALVE********************/
void valve_initialization(){
	
valve_drivers_init();
valve_DI_init();
valve_LCD_init();
get_valve_mode();
print_mode();
get_valve_position();
print_position();	
remote_fbk_update();
	
}
/****************VALVE OPERATION***************/
void valve_operation(void){

      while (v_mode==REMOTE)
         {
             	get_valve_mode();
             	print_mode();
             	get_valve_position();
             	print_position();
			    remote_fbk_update();
             	get_remote_command();
             	if (r_command==R_OPEN && v_position!=OPENED && v_closing_f!=1)  /*updated 28/2 10:00pm*/
             	{
             		open_valve();
					 v_opening_f=1;
             	}
				if (v_opening_f==1 && (v_position==OPENED||r_command==R_CLOSE))/*updated 5/3 10:00pm*/
             	{
             		stop_valve();
					 v_opening_f=0;
             	}
             		
             
                 if (r_command==R_CLOSE && v_position!=CLOSED && v_opening_f!=1)  /*updated 28/2 10:00pm*/
                 {
             	    	close_valve();
						 v_closing_f=1;
                 }
				 
				  if (v_closing_f==1 &&( v_position==CLOSED||r_command==R_OPEN))/*updated 5/3 10:00pm*/
                 {
             		stop_valve();
                   v_closing_f=0;
				 }
                  if (v_mode!=REMOTE)
                  {
             		 stop_valve();
					  v_closing_f=0;
					  v_opening_f=0;
                  }
             
         	
         }
          while (v_mode==LOCAL)
           {    
			    
		         get_valve_mode();
               	print_mode();
               	get_valve_position();
               	print_position();
				remote_fbk_update();
               	get_local_command();
				  
               	if (l_command==L_OPEN && v_position!=OPENED && v_closing_f!=1) /*updated 5/3 10:00pm*/
               	{
               		open_valve();
					v_opening_f=1;
               	}
			    if (v_opening_f==1 && (v_position==OPENED||l_command==L_CLOSE))/*updated 5/3 10:00pm*/
               	{
               		stop_valve();
					   v_opening_f=0;
               	}
               	
               	if (l_command==L_CLOSE && v_position!=CLOSED && v_opening_f!=1)/*updated 5/3 10:00pm*/
               	{
					close_valve();   
               		v_closing_f=1;
               	}
				    if (v_closing_f==1 && (v_position==CLOSED||l_command==L_OPEN))/*updated 5/3 10:00pm*/
               	{
               		stop_valve();
               	    v_closing_f=0;
				   }
               	
               	  if (v_mode!=LOCAL)
               	  {
               		  stop_valve();
					  v_closing_f=0;
					  v_opening_f=0;
               	  }
               
         
         }
         
         while (v_mode==OFF)
           {
         	      stop_valve();
         	      get_valve_mode();
         	      print_mode();
         	      get_valve_position();
         	      print_position();
				  remote_fbk_update();
         	
           }
		   
           while (v_mode==STOP)
          {
         	       stop_valve();
         	       get_valve_mode();
         	       print_mode();
         	       get_valve_position();
         	       print_position();
         	       remote_fbk_update();
           }
			
	       while (v_mode==H_WHEEL)
	       {
		       stop_valve();
		       get_valve_mode();
		       print_mode();
		       get_valve_position();
		       print_position();
		       remote_fbk_update();
	       }		
 	       while (v_mode==TH_FAULT)
 	       {
	 	       stop_valve();
	 	       get_valve_mode();
	 	       print_mode();
	 	       get_valve_position();
	 	       print_position();
	 	       remote_fbk_update();
 	       } 
 	       while (v_mode==O_TORQUE)
 	       {
	 	       stop_valve();
	 	       get_valve_mode();
	 	       print_mode();
	 	       get_valve_position();
	 	       print_position();
	 	       remote_fbk_update();
 	       } 
	       while (v_mode==C_TORQUE)
	       {
		       stop_valve();
		       get_valve_mode();
		       print_mode();
		       get_valve_position();
		       print_position();
		       remote_fbk_update();
	       }  
  
  }