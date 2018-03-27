#pragma once
#include <stdio.h>
#include <stdlib.h>

#include "terminal.h"

enum { INIT,WAITING_RD, WAITING_EVENT, WAITING_ACK, SHUTING_DOWN };//testado
typedef enum { MOVE, I_AM_READY, TIMEOUT, TIMEOUT_2, ACK, QUIT, ERROR };//tevento
enum { EVENT_IN, LAST_EVENT, ACTION, STATE };
typedef void(*pfun)(void* userData);
#define EVENTS_N 7
#define STATES_N 5


typedef struct
{
	int proximoEstado;
	pfun action;
	
}cell;


class fsm
{

private:
	const cell tabla[STATES_N][EVENTS_N] =
	{//			MOVE				        	I_AM_READY						TIMEOUT						 TIMEOUT_2						 ACK							  QUIT							   ERROR
	{ { SHUTING_DOWN, &print_error },{ WAITING_RD , &print_imr }   ,{ INIT, &nothing }            ,{ SHUTING_DOWN, &print_error },{ SHUTING_DOWN, &print_error },{ SHUTING_DOWN, &print_quit } ,{ SHUTING_DOWN ,&print_error }}, //init
	{ { SHUTING_DOWN, &print_error },{ WAITING_ACK , &print_ack_r },{ WAITING_RD, &print_t1_imr } ,{ SHUTING_DOWN, &print_error },{ SHUTING_DOWN, &print_error },{ SHUTING_DOWN, &print_quit } ,{ SHUTING_DOWN ,&print_error }}, //wait rd
	{ { WAITING_ACK , &print_move } ,{ SHUTING_DOWN ,&print_error },{ SHUTING_DOWN, &print_error },{ SHUTING_DOWN ,&print_error },{ WAITING_EVENT, &print_ack } ,{ SHUTING_DOWN ,&print_quit } ,{ SHUTING_DOWN ,&print_error }}, //wait ev
	{ { SHUTING_DOWN,&print_error } ,{ SHUTING_DOWN, &print_error },{ WAITING_ACK ,&print_t1 }    ,{ SHUTING_DOWN ,&print_error },{ WAITING_EVENT ,&print_ack } ,{ SHUTING_DOWN ,&print_quit } ,{ SHUTING_DOWN ,&print_error }}, //wait ack
	{ { SHUTING_DOWN, &print_out }  ,{ SHUTING_DOWN, &print_out }  ,{ SHUTING_DOWN, &print_out }  ,{ SHUTING_DOWN, &print_out }  ,{ SHUTING_DOWN, &print_ackq } ,{ SHUTING_DOWN, &print_out }  ,{ SHUTING_DOWN, &print_out   }}	 //shutdown
	};
	int estado;

public:
	void run(int tevento, void* userData);
	fsm();

};
