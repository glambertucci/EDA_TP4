#include <curses.h>
#include "terminal.h"

void print_terminal(int id, const char * msg)
{
		switch (id)
		{
		case EVENT_IN:
			move(7, 40);
			color_set(2, NULL);
			printw(": %s", msg);
			color_set(3, NULL);
			break;
		case LAST_EVENT:
			move(8, 40);
			color_set(2, NULL);
			printw(": %s", msg);
			color_set(3, NULL);
			break;
		case ACTION:
			move(9, 40);
			color_set(2, NULL);
			printw(": %s", msg);
			color_set(3, NULL);
			break;
		case STATE :
			color_set(2, NULL);
			move(10, 40);
			printw(": %s", msg);
			color_set(3, NULL);
			break;
		default:;
		}
	
}
void print_menu(void)
{
	printw("Programa de simulacion de cliente de Worms");
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

void print_no_key()
{
	color_set(2, NULL);
	move(10, 80);
	printw("TECLA NO RECONOCIDA");
	color_set(3, NULL);

}