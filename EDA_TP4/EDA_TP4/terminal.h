#pragma once

void print_terminal(int id, const char * msg);
//recibe un identificador de donde se imprime, y que imprimir USA UN ENUM
typedef enum { MOVE, I_AM_READY, TIMEOUT, TIMEOUT_2, ACK, QUIT, ERROR };//tevento
enum { EVENT_IN, LAST_EVENT, ACTION, STATE };

void print_menu(void);
void  print_ev(void * data);
void  print_last_ev(void * data);
void print_no_key();

void init_color(void);

typedef struct
{
	int last_ev;
	int ev;
}data_t;
