#include <ncurses.h>
#include <cstdlib>
#include <utility>

int graphics_and_input(void);
void set_up(void);
void end(void);

//update these values later
const int kScreenHeight {50};
const int kScreenWidth {50};

class Frame
{
public:
  WINDOW* getWindow();
  void refresh(void);
  void add(char c, int x, int y);
private:
  WINDOW* window;
  int height;
  int width;
  std::pair<int,int> row_and_col;
};
