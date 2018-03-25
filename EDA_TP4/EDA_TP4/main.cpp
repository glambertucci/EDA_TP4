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

	init_color();
	color_set(3, NULL);
	print_menu();
	fsm s;
	int i;
	print_terminal(STATE, "Init.");
	do
	{
		i = getch();
		if (i != ERR)
		{
			if (toupper(i) >= 'A' && toupper(i) <= 'G')
			{
				s.run(toupper(i)-'A', (void *) "hola");
			}
		}

	} while (toupper(i) != 'Q' & (s.get_state() != SHUTING_DOWN));
	printf("Program Closed, press enter to finish");
	getchar();

	return 0;
}

