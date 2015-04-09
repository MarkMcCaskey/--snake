#include <SDL/SDL.h>

#include "Renderer.hpp"

class SDL : Renderer
{
    SDL();
    SDL(Uint32 flags = 0);
    ~SDL();

    void fill_rect(int x, int y, int w, int h);
    void update();
};
