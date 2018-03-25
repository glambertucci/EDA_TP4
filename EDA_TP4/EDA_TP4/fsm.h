
#include <stdio.h>
#include <stdlib.h>

typedef enum {INIT, WAITING_EVENT, WAITING_ACK, SHUTING_DOWN };//testado
typedef enum { MOVE, I_AM_READY, TIMEOUT,TIMEOUT_2,ACK,QUIT,ERROR };//tevento
 typedef void(*pfun)(void);
 void print_error(void );
 void print_resend(void );
 void print_quit(void );
 void print_ack(void );
void print_ack_r(void);
void print_move(void);
void print_t1(void);
void nothing(void);
typedef struct 
{
	int proximoEstado;
	pfun action;
}cell;

class fsm
{
	
	private:
		const cell tabla[4][7] =
		{//			MOVE					I_AM_READY							TIMEOUT						 TIMEOUT_2						 ACK							  QUIT									   ERROR
		{ { SHUTING_DOWN, &print_error },{ WAITING_ACK , &print_ack_r },	{ INIT, &nothing },			{ SHUTING_DOWN, &print_error },	{ SHUTING_DOWN, &print_error } ,	{ SHUTING_DOWN, &print_quit } ,		{ SHUTING_DOWN ,&print_error } },	//init
		{ { WAITING_ACK , &print_move },{ SHUTING_DOWN ,&print_error }	,{ SHUTING_DOWN, &print_error },{ SHUTING_DOWN ,&print_error },	{ WAITING_EVENT, &print_ack } ,	{ SHUTING_DOWN ,&print_error } ,{ SHUTING_DOWN ,&print_error }},	//wait ev
		{ { SHUTING_DOWN,&print_error},{ SHUTING_DOWN, &print_error },	{ WAITING_ACK ,&print_t1 },		{ SHUTING_DOWN ,&print_error },		{ WAITING_EVENT ,&print_ack }, { SHUTING_DOWN ,&print_error }  ,{ SHUTING_DOWN ,&print_error }},	//wait ack
		{ { SHUTING_DOWN, &print_error},{ SHUTING_DOWN, &print_error },		{ SHUTING_DOWN, &print_error }	,{ SHUTING_DOWN, &print_error },{ SHUTING_DOWN, &print_error },	{ SHUTING_DOWN, &print_error }  ,{ SHUTING_DOWN, &print_error }}	//shutdown
		};
		int estado;

	public:
		int get_state(void);
		void run(int tevento, void* userData);
		fsm();

};
