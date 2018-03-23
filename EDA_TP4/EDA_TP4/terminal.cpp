#include <curses.h>
#include "terminal.h"

void print_terminal(int id, const char * msg)
{


		
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
