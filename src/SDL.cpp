#include <exception>

#include "../include/SDL.hpp"

SDL::SDL()
{
    if (SDL_Init(SDL_INIT_VIDEO) < 0)
        throw std::exception();
}

SDL::~SDL()
{
    SDL_Quit();
}
