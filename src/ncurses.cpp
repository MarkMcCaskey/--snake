#include <ncurses.h>
#include <cstdlib>

int graphics_loop()
{
  //set up
  initscr();
  clear();
  noecho();
  cbreak();

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

  //end
  endwin();

  return EXIT_SUCCESS;
}
