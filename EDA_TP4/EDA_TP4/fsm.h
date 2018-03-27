
#include <stdio.h>
#include <stdlib.h>
#include "terminal.h"
enum {WAITNG_IMR, WAITING_EVENT, WAITING_ACK, SHUTING_DOWN };//testado
enum { MOVE, I_AM_READY, TIMEOUT, TIMEOUT_2, ACK, QUIT, ERROR };//tevento
enum { EVENT_IN, LAST_EVENT, ACTION, STATE };

typedef void(*pfun)(void* userData);
#define EVENTS_N 7
#define STATES_N 4

typedef struct 
{
	int proximoEstado;
	pfun action;
}cell;


class fsm
{
	
	private:
		const cell tabla[STATES_N][EVENTS_N] =
		{//			MOVE					          I_AM_READY						TIMEOUT				 TIMEOUT_2					          	 ACK						  QUIT							   ERROR
		{ { SHUTING_DOWN, &print_error },{ WAITING_ACK , &print_ack_r } ,{ SHUTING_DOWN, &print_error },{ SHUTING_DOWN, &print_error },	{ SHUTING_DOWN, &print_error } ,{ SHUTING_DOWN, &print_quit } ,{ SHUTING_DOWN ,&print_error }},	//init
		{ { WAITING_ACK , &print_move } ,{ SHUTING_DOWN ,&print_error }	,{ SHUTING_DOWN, &print_error },{ SHUTING_DOWN ,&print_error },	{ WAITING_EVENT, &print_ack }  ,{ SHUTING_DOWN ,&print_quit } ,{ SHUTING_DOWN ,&print_error }},	//wait ev
		{ { SHUTING_DOWN,&print_error}  ,{ SHUTING_DOWN, &print_error } ,{ WAITING_ACK ,&print_t1 }    ,{ SHUTING_DOWN ,&print_error },	{ WAITING_EVENT ,&print_ack }  ,{ SHUTING_DOWN ,&print_quit } ,{ SHUTING_DOWN ,&print_error }},	//wait ack
		{ { SHUTING_DOWN, &print_out }  ,{ SHUTING_DOWN, &print_out }   ,{ SHUTING_DOWN, &print_out }  ,{ SHUTING_DOWN, &print_out }  , { SHUTING_DOWN, &print_ackq }  ,{ SHUTING_DOWN, &print_out }  ,{ SHUTING_DOWN, &print_out   }}	//shutdown
		};
		int estado;

	public:
		void run(int tevento, void* userData);
		fsm();
		
};
