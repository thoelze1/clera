#include <ncurses.h>
#include <unistd.h>
#include "clera.h"

int my_mvaddstr(int y, int x, char *str)
{
    for ( ; x < 0; ++x, ++str)
        if (*str == '\0')  return ERR;
    for ( ; *str != '\0'; ++str, ++x)
        if (mvaddch(y, x, *str) == ERR)  return ERR;
    return OK;
}

int main(int argc, char *argv[])
{
	int c = 0;
	char *str[2][9]
		= {	{FILL1,  FILL2,  FILL3,  FILL4,  FILL5,  FILL6,  FILL7,  FILL8,  FILL9 },
			{EMPTY1, EMPTY2, EMPTY3, EMPTY4, EMPTY5, EMPTY6, EMPTY7, EMPTY8, EMPTY9} };
	
	/**	= {	{FILL9,  FILL8,  FILL7,  FILL6,  FILL5,  FILL4,  FILL3,  FILL2,  FILL1 },
			{EMPTY9, EMPTY8, EMPTY7, EMPTY6, EMPTY5, EMPTY4, EMPTY3, EMPTY2, EMPTY1} }; */
	
	/* Init ncurses mode */
	initscr ();

	/* Hide cursor */
	curs_set (0);
	while (c < 1000) {
		mvprintw (LINES/2 + HEIGHT/2 - (c%9), COLS/2 - WIDTH/2, str[1-(c>>2)%2][c%9], c++);
		refresh ();
		usleep(40000);
	}
	
	/* End ncurses mode */
	endwin();

	return 0;
}
