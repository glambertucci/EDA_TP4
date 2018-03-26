#include <curses.h>
#include "terminal.h"

void print_terminal(int id, const char * msg)
{
	switch (id)
	{
	case EVENT_IN:
		move(7, 40);
		color_set(1, NULL);
		printw(": %s", msg);
		color_set(3, NULL);
		break;
	case LAST_EVENT:
		move(8, 40);
		color_set(1, NULL);
		printw(": %s", msg);
		color_set(3, NULL);
		break;
	case ACTION:
		move(9, 40);
		color_set(1, NULL);
		printw(": %s", msg);
		color_set(3, NULL);
		break;
	case STATE:
		color_set(1, NULL);
		move(10, 40);
		printw(": %s", msg);
		color_set(3, NULL);
		break;
	default:;
	}

}
void print_menu(void)
{
	printw("Programa de simulacion de Servidor de Worms");
	move(2, 0);
	printw("Cuando el usuario presione las teclas de Eventos de abajo el simulador \nEntiende que se genero un nuevo evento y responde ante el \nRealizando una accion y cambiando el estado");
	move(4, 0);
	printw("Eventos:");
	move(6, 0);
	printw("MOVE        = A");
	move(7, 0);
	printw("READY       = B");
	move(8, 0);
	printw("TIMEOUT     = C");
	move(9, 0);
	printw("TIMEOUT2    = D");
	move(10, 0);
	printw("ACKNOWLEDGE = E");
	move(11, 0);
	printw("QUIT        = F");
	move(12, 0);
	printw("ERROR       = G");

	move(6, 16);
	printw("| Status de la FSM");
	move(7, 16);
	printw("| Evento Recibido");
	move(8, 16);
	printw("| Ultimo Evento Recibido");
	move(9, 16);
	printw("| Accion Ejecutada");
	move(10, 16);
	printw("| Estado Actual");
}

void init_color(void)
{
	start_color();
	init_pair(1, COLOR_BLUE, COLOR_BLACK);
	init_pair(2, COLOR_RED, COLOR_BLACK);
	init_pair(3, COLOR_GREEN, COLOR_BLACK);
	init_pair(4, COLOR_YELLOW, COLOR_BLACK);
	init_pair(5, COLOR_MAGENTA, COLOR_BLACK);
	init_pair(6, COLOR_CYAN, COLOR_WHITE);
	init_pair(7, COLOR_GREEN, COLOR_BLUE);
	init_pair(8, COLOR_BLUE, COLOR_GREEN);
	init_pair(9, COLOR_RED, COLOR_BLACK);
	init_pair(10, COLOR_GREEN, COLOR_YELLOW);

}

void  print_last_ev(void * data)
{
	move(8, 40);
	color_set(1, NULL);
	switch (((data_t*)data)->last_ev)
	{
	case MOVE:
		printw(": Move          "); break;
	case I_AM_READY:
		printw(": I am ready    "); break;
	case TIMEOUT:
		printw(": Timeout       "); break;
	case TIMEOUT_2:
		printw(": Timeout 2     "); break;
	case ACK:
		printw(": Acknowledge   "); break;
	case QUIT:
		printw(": Quit          "); break;
	case ERROR:
		printw(": Error         "); break;
	default:;


	}
	color_set(3, NULL);
}

void  print_ev(void * data)
{
	move(7, 40);
	color_set(1, NULL);
	switch (((data_t*)data)->ev)
	{
	case MOVE:
		printw(": Move          "); break;
	case I_AM_READY:
		printw(": I am ready    "); break;
	case TIMEOUT:
		printw(": Timeout       "); break;
	case TIMEOUT_2:
		printw(": Timeout 2     "); break;
	case ACK:
		printw(": Acknowledge   "); break;
	case QUIT:
		printw(": Quit          "); break;
	case ERROR:
		printw(": Error         "); break;
	default:;


	}
	color_set(3, NULL);
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
	print_terminal(LAST_EVENT, "I am ready");
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
	if ((((data_t *)userData)->quit_flag == true))
	{
		print_terminal(ACTION, "Acknowledged                  ");
		print_terminal(STATE, "Shuting down                   ");
		((data_t *)userData)->quit_flag = false;
	}
	else
	{
		print_terminal(EVENT_IN, "                           ");
		print_terminal(LAST_EVENT, "                           ");
		print_terminal(ACTION, "                           ");
		print_terminal(STATE, "Conection closed            ");
	}
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
void nothing(void* userData) {}
