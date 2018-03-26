#pragma once
#pragma once
#include "fsm.h"
void print_terminal(int id, const char * msg);
void print_menu(void);
void  print_ev(void * data);
void  print_last_ev(void * data);
void init_color(void);
typedef struct
{
	int last_ev;
	int ev;
	int quit_flag = false;
}data_t;
