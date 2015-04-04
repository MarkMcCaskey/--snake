#include <SDL2/SDL.h>

#include "Snake.hpp"

class Board
{
public:
    enum class Block_type{apple, multiplier, wall};
    static const int kBoardHeight{25};
    static const int kBoardWidth{25};

    Board();
    ~Board();

    void draw_entities();
    Block_type** getGrid();

private:
    /**
     For now -- may later use some interface where
     entities are extended from some interface(s)
     and the player/ai entities are plugged into
     a vector of player/ai slots.

     The reason for this will be to automate how
     actions and state are managed by ai vs players,
     efficiently decoupling players and ai.
    */
    Snake player;
    SDL_Window* window;
    Block_type grid[kBoardHeight][kBoardWidth];
};
