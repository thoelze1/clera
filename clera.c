#include <stdio.h>
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
	int c = 0, line = 1;
	char *glass[3] = {LINE10, EMPTY4, LINE10};
	char *sand[2][6]
		= {	{FILL3,  FILL2,  FILL1, FILL7,  FILL6,  FILL5},
			{EMPTY3, EMPTY2, EMPTY1, EMPTY7, EMPTY6, EMPTY5} };
	char *str[2][9]
		= {	{LINE10, FILL1,  FILL2,  FILL3,  FILL4,  FILL5,  FILL6,  FILL7,  LINE10},
			{LINE10, EMPTY1, EMPTY2, EMPTY3, EMPTY4, EMPTY5, EMPTY6, EMPTY7, LINE10} };
	
	/**	= {	{FILL9,  FILL8,  FILL7,  FILL6,  FILL5,  FILL4,  FILL3,  FILL2,  FILL1 },
			{EMPTY9, EMPTY8, EMPTY7, EMPTY6, EMPTY5, EMPTY4, EMPTY3, EMPTY2, EMPTY1} }; */

	//printf("%s\n", T30STR1);
	//sleep(2);
		
	/* Init ncurses mode */
	initscr ();
	
	/* Hide cursor */
	curs_set (0);
	my_mvaddstr (LINES/2 + HEIGHT/2 - 0, COLS/2 - WIDTH/2, glass[0]);
	my_mvaddstr (LINES/2 + HEIGHT/2 - 4, COLS/2 - WIDTH/2, glass[1]);
	my_mvaddstr (LINES/2 + HEIGHT/2 - 8, COLS/2 - WIDTH/2, glass[2]);
	refresh();
	while (c < 1000) {
		/*if((c%9)==0) {
			c+=1;
		} else if((c%9)==4) {
			c+=1;
		} else if((c%9)==8) {
			c+=2;
		} else {
			//mvprintw (LINES/2 + HEIGHT/2 - (c%9), COLS/2 - WIDTH/2, str[1-(c>>2)%2][c%9], c++);
			my_mvaddstr(LINES/2 + HEIGHT/2 - (c%9), COLS/2 - WIDTH/2, str[1-(c>>2)%2][c%9]);
			c++;
			refresh();
			usleep(40000);
		}*/
			line = ((c%6)<3)? 0: 4;
			my_mvaddstr(HEIGHT + line + (c%3), COLS/2 - WIDTH/2, sand[(c%6)/3][c%6]);
			c++;
			refresh();
			usleep(400000);
	}
	
	/* End ncurses mode */
	endwin();

	return 0;
}
