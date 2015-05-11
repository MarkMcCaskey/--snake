#include "../include/ncurses.hpp"

int graphics_and_input()
{
  int x = 0;
  int y = 0;
  char input = ' ';
  bool loop = true;
  while( loop )
    {
      input = getch();
      switch( input )
	{
	case 'q':
	case 'Q':
	  loop = false;
	  break;
	case KEY_RIGHT:
	  x++;
	  mvaddch(y,x,'@');
	  break;
	case KEY_LEFT:
	  x--;
	  mvaddch(y,x,'@');
	  break;
	case KEY_DOWN:
	  y++;
	  mvaddch(y,x,'@');
	  break;
	case KEY_UP:
	  y--;
	  mvaddch(y,x,'@');
	  break;
	}
      refresh();
    }
  return EXIT_SUCCESS;
}

void set_up()
{
  initscr();
  clear();
  noecho();
  cbreak();
  keypad(stdscr, TRUE);
  curs_set(0);
  getmaxyx(stdscr,kScreenHeight,kScreenWidth);
  
  //add additional setup code here
}

void end()
{
  endwin();
  
  //clean up everything that was set up
}
