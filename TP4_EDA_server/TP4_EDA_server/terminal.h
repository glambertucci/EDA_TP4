#pragma once
#pragma once

void print_terminal(int id, const char * msg);
void print_menu(void);
void  print_ev(void * data);
void  print_last_ev(void * data);
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

void init_color(void);
typedef struct
{
	int last_ev;
	int ev;
	int quit_flag = false;
}data_t;
