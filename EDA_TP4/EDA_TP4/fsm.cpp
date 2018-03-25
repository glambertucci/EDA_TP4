#include "fsm.h"
#include "terminal.h"
void fsm::run(int ev, void* userData)
{
	tabla[estado][ev].action();
	estado = tabla[estado][ev].proximoEstado;
}
fsm::fsm()
{
	estado = INIT;
}

int fsm::get_state(void)
{
	return estado;
}
// void print_error(void *);
void print_t1(void)
{
	print_terminal(ACTION, "Timeout 1, resubiendo datos           ");
	print_terminal(STATE, "Waiting ack                      ");
}
void print_error(void )
{
	print_terminal(ACTION, "Error, cerrando programa              ");
	print_terminal(STATE, "Shuting down                      ");

}
void print_resend(void)
{
	print_terminal(ACTION, "Resending info                   ");
	print_terminal(STATE, "Shuting down                      ");

}
//enum{EVENT_IN,LAST_EVENT,ACTION, STATE};
void print_quit(void )
{
	print_terminal(ACTION, "Quiting, cerrando programa           ");
	print_terminal(STATE, "Shuting down                      ");

}

void print_ack_r(void )
{
	print_terminal(ACTION, "Sending ready                    ");
	print_terminal(STATE, "Waiting Acknowledge                   ");

}
void print_ack(void)
{
	print_terminal(ACTION, "Acknowledged                   ");
	print_terminal(STATE, "Waiting Event                      ");

}
void print_move(void)
{
	print_terminal(ACTION, "Moving                              ");
	print_terminal(STATE, "Waiting Acknowledge                      ");
}
void nothing(void)
{

}
//void print_resend(void *);
//void print_quit(void *);
//void print_ack(void *);