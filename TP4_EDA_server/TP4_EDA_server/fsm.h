#pragma once
#include <stdio.h>
#include <stdlib.h>
#include "terminal.h"
typedef enum { INIT,WAITING_RD, WAITING_EVENT, WAITING_ACK, SHUTING_DOWN };//testado

typedef void(*pfun)(void* userData);

void print_error(void* userData);
void print_quit(void* userData);
void print_ack(void* userData);
void print_ack_r(void* userData);
void print_move(void* userData);
void print_t1(void* userData);
void nothing(void* userData);
void print_out(void* userData);
void print_ackq(void* userData);
void print_imr(void* userData);
void print_t1_imr(void* userData);
typedef struct
{
	int proximoEstado;
	pfun action;
}cell;


class fsm
{

private:
	const cell tabla[5][7] =
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
