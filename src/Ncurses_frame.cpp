#include "../include/Ncurses_frame.hpp"

Ncurses_frame::Ncurses_frame(int h, int w, int x, int y)
{
  xy.first = w;
  xy.second = h;
  row_col.first = x;
  row_col.second =y;
  window = newwin(h, w, x, y);
}

Ncurses_frame::~Ncurses_frame()
{
  delwin(window);
}

Ncurses_frame::refresh()
{
  wrefresh(window);
}

Ncurses_frame::add(char c, int x, int y)
{
  mwaddch(window, x, y, c);
}
