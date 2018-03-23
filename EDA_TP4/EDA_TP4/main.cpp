#include "terminal.h"
#include "fsm.h"
#include <curses.h>
#include <stdio.h>
int main(void)
{
	WINDOW * winTest = NULL;
	winTest = initscr();
	nodelay(winTest, TRUE);
	noecho();
	immedok(winTest, TRUE);
	//QUE VAYA EN UNA FUNCION
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
	//hasta aca
	print_terminal(ACTION,"Anti guido");
	print_terminal(EVENT_IN, "Quiero helado");
	getchar();
	return 0;
}

