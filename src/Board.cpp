#include <exception>

#include "../include/Board.hpp"

Board::Board()
{
    if (SDL_Init(SDL_INIT_VIDEO) < 0)
        throw std::exception{};
}

Board::~Board()
{
    SDL_Quit();
}
