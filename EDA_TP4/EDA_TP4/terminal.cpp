#include <curses.h>
#include "terminal.h"

void print_terminal(int id, const char * msg)
{
	WINDOW * winTest = NULL;
	winTest = initscr();
	if (winTest != NULL)
	{
		start_color();
		nodelay(winTest, TRUE);
		noecho();

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
		immedok(winTest, TRUE);
		color_set(3, NULL);
		printw("Programa de simulacion de cliente de Worms");
		move(2, 0);
		printw("Cuando el usuario presione las teclas de Eventos de abajo el simulador \nEntiende que se genero un nuevo evento y responde ante el \nRealizando una accion y cambiando el estado");
		move(4, 0);
		printw("Eventos:");
		move(6, 0);
		printw("READY    = Q");
		move(7, 0);
		printw("ACK      = W");
		move(8, 0);
		printw("MOVE     = E");
		move(9, 0);
		printw("ERROR    = R");
		move(10, 0);
		printw("TIMEOUT  = A");
		move(11, 0);
		printw("TIMEOUT2 = S");
		move(12, 0);
		printw("QUIT     = D");
		move(13, 0);
		move(6, 15);
		printw("| Status de la FSM");
		move(7, 15);
		printw("| Evento Recibido");
		move(8, 15);
		printw("| Ultimo Evento Recibido");
		move(9, 15);
		printw("| Accion Ejecutada");
		move(10, 15);
		printw("| Estado Actual");
		switch (id)
		{
		case EVENT_IN:
			move(7, 40);
			printw(": %s", msg);
			break;
		case LAST_EVENT:
			move(8, 40);
			printw(": %s", msg);
			break;
		case ACTION:
			move(9, 40);
			printw(": %s", msg);
			break;
		case STATE :
			move(10, 40);
			printw(":  %s", msg);
			break;
		default:;
		}
	}
}
