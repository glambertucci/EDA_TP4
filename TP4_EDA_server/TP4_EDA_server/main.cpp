
/*
	TP4 eda FSM
	Alumnos:
	Lambertucci Guido 58009
	Hrubisiuk Agustin  58311
	Carricart Francisco 
*/

#include "terminal.h"
#include "fsm.h"
#include <curses.h>
#include <ctype.h>
#include <stdio.h>

int main(void)
{
	WINDOW * winTest = NULL;
	winTest = initscr();
	nodelay(winTest, TRUE);
	noecho();
	immedok(winTest, TRUE);
	data_t user;
	data_t  * puser = &user;
	puser->ev = I_AM_READY;
	init_color();
	color_set(3, NULL);
	print_menu();
	fsm s;
	int i;
	print_terminal(STATE, "Send Ready please.");

	do
	{
		i = getch();
		if (i != ERR)
		{
			if (toupper(i) >= 'A' && toupper(i) <= 'G')
			{
				s.run(toupper(i) - 'A', (void *)puser);
			}
		}

	} while (toupper(i) != 'Q');
	printf("Program Closed, press enter to finish");
	getchar();

	return 0;
}

