#include <SDL2/SDL.h>
#include "Snake.hpp"

class Board
{
public:
    Board();
    ~Board();

    void draw_entities();

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
};
