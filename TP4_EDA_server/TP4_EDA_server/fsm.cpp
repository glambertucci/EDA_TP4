#include "fsm.h"

void fsm::run(int ev, void* userData)
{
	((data_t *)userData)->last_ev = ((data_t *)userData)->ev;
	((data_t *)userData)->ev = ev;
	tabla[estado][ev].action(userData);
	estado = tabla[estado][ev].proximoEstado;
}
fsm::fsm()
{
	estado = INIT;
}


void print_t1(void* userData)
{
	print_last_ev(userData);
	print_ev(userData);
	print_terminal(ACTION, "Timeout 1,Resending pckg      ");
	print_terminal(STATE, "Waiting ack                    ");
}
void print_t1_imr(void* userData)
{
	print_last_ev(userData);
	print_ev(userData);
	print_terminal(ACTION, "Timeout 1, resubiendo datos   ");
	print_terminal(STATE, "Waiting I am ready                    ");
}
void print_error(void* userData)
{
	print_ev(userData);
	print_terminal(ACTION, "Error, cerrando programa      ");
	print_terminal(STATE, "Shuting down                   ");

}


void print_quit(void* userData)
{
	print_ev(userData);
	print_last_ev(userData);
	print_terminal(ACTION, "Sending quit                  ");
	print_terminal(STATE, "Waiting Acknowledge            ");

}

void print_ack_r(void* userData)
{
	print_ev(userData);
	print_terminal(ACTION, "Sending ready                 ");
	print_terminal(LAST_EVENT, "init");
	print_terminal(STATE, "Waiting Acknowledge            ");

}
void print_ack(void* userData)
{
	print_ev(userData);
	print_terminal(ACTION, "Acknowledged                  ");
	print_terminal(STATE, "Waiting Event                  ");
	print_last_ev(userData);
}
void print_ackq(void* userData)
{
	print_terminal(ACTION, "Acknowledged                  ");
	print_terminal(STATE, "Shuting down                   ");
}
void print_move(void* userData)
{
	print_last_ev(userData);
	print_terminal(ACTION, "Moving                        ");
	print_terminal(STATE, "Waiting Acknowledge            ");
	print_ev(userData);
}
void print_out(void* userData)
{
	print_terminal(EVENT_IN, "                           ");
	print_terminal(LAST_EVENT, "                           ");
	print_terminal(ACTION, "                           ");
	print_terminal(STATE, "Conection closed            ");
}
void print_imr(void* userData)
{
	
	print_terminal(ACTION, "I am ready sent               ");
	print_terminal(STATE, "Waiting I am ready             ");
	print_ev(userData);
}
void nothing(void* userData){}
