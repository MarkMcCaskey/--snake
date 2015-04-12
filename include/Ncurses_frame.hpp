#include <ncurses.h>

class Ncurses_frame
{
public:
  WINDOW* getWindow();
  void refresh();
  void add(char c, int x, int y);
private:
  WINDOW* window;
  std::pair<int,int> xy;
  std::pair<int,int> row_and_col;
};
