#include "../include/ncurses.hpp"

int graphics_and_input( void )
{
  char input = '';
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
	  //logic here
	  break;
	case KEY_LEFT:
	  //logic here
	  break;
	case KEY_DOWN:
	  //logic here
	  break;
	case KEY_UP:
	  //logic here
	  break;
	}
      refresh();
    }
  return EXIT_SUCCESS;
}

void set_up( void )
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

void end( void )
{
  endwin();
  
  //clean up everything that was set up
}
