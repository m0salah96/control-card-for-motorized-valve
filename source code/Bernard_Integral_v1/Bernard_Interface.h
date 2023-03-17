/*13/1/2023 */
/*PROJECT:BERNARD INTEGRAL VALVE */

#ifndef  BERNARD_INTERFACE_C 
#define   BERNARD_INTERFACE_C

typedef enum {
	REMOTE,
	LOCAL,
	OFF,
	STOP,
	TH_FAULT,
	O_TORQUE,
	C_TORQUE,
	H_WHEEL
	}valve_mode;


typedef enum {
R_OPEN,
R_CLOSE,
R_UNDEFINED
}remote_command;

typedef enum {
	L_OPEN,
	L_CLOSE,
	L_UNDEFINED
}local_command;



typedef enum{
	OPENED,
	CLOSED,
	TRAVEL,
	UNDEFINED
	}valve_position;
	
	
void valve_initialization(void);	
void valve_drivers_init(void);	
void valve_DI_init(void);
void valve_LCD_init(void);	
void get_valve_mode(void);
void print_mode(void);
void get_valve_position(void);
void print_position(void);
void open_valve(void);
void close_valve(void);
void remote_fbk_update(void);

void valve_operation(void);
void get_remote_command(void);
void get_local_command(void);




#endif