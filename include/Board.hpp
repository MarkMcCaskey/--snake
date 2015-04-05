#include <vector>
#include <SDL2/SDL.h>

#include "Snake.hpp"

class Board
{
public:
    enum class BlockType{empty, apple, multiplier, wall};
    const int kBoardHeight;
    const int kBoardWidth;
    std::vector<std::vector<BlockType>> grid;

    Board();
    Board(int w, int h);
    ~Board();

    void draw_entities();
    std::vector<std::vector<BlockType>> getGrid();

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
