
#include <stdio.h>
#include <stdlib.h>

typedef enum { WAITING_EVENT, WAITING_ACK, SHUTING_DOWN };//testado
typedef enum { MOVE, I_AM_READY,RESEND, TIMEOUT,TIMEOUT_2,ACK,QUIT,ERROR };//tevento
 typedef void(*pfun)(void*);
 void print_error(void *);
 void print_resend(void *);
 void print_quit(void *);
 void print_ack(void *);
typedef struct 
{
	int proximoEstado;
	pfun action;
}cell;

class fsm
{
	public:
		void run(int tevento, void* userData);
	private:
		const cell tabla[3][8] =
		{//			MOVE									I_AM_READY				RESEND						   TIMEOUT					 TIMEOUT_2						 ACK					  QUIT									   ERROR
		{ { SHUTING_DOWN , &print_error },{ SHUTING_DOWN , &print_error },{ SHUTING_DOWN,&print_error},{ WAITING_ACK, &print_resend },{ SHUTING_DOWN ,&print_error },{ WAITING_EVENT, NULL } ,{ SHUTING_DOWN ,&print_error } ,{ SHUTING_DOWN ,&print_error }},	//wait ev
		{ {WAITING_EVENT,&print_ack},{ WAITING_EVENT, &print_ack },{ WAITING_EVENT,&print_ack },{ SHUTING_DOWN ,&print_error },{ SHUTING_DOWN ,&print_error }, { SHUTING_DOWN ,&print_error }, { SHUTING_DOWN ,&print_error }  ,{ SHUTING_DOWN ,&print_error }},	//wait ack
		{ {ERROR, &print_error},{ ERROR, &print_error },{ ERROR,&print_error },{ ERROR, &print_error },{ ERROR, &print_error }, { ERROR, &print_error }, { ERROR, &print_error }  ,{ ERROR, &print_error }}	//shutdown
		};
		int estado;
};