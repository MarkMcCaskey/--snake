#include "../include/Snake.hpp"

Snake::Snake(int x, int y, Direction d)
{
    dir = d;

    // Pushes pairs (coordinates) into a vector.
    // Coordinates are viewed as cartesian coordinates
    // as opposed to SDL coordinates.
    blocks.push_back({x, y});
    for (int i = 1; i < kInitialSize; i++)
    {
        switch (d)
        {
            case Direction::down:
                blocks.push_back({x, y-i});
            case Direction::up:
                blocks.push_back({x, y+i});
            case Direction::right:
                blocks.push_back({x+1, y});
            case Direction::left:
                blocks.push_back({x-1, y});
        }
    }
}

/**
 * Moves the snake in its directional state.
 */
void Snake::move(int dt)
{
    int rotations_needed = (dt / kBps);
    for (int i = 0; i < rotations_needed; i++)
        rotate();
}

void Snake::rotate()
{
    
}

void Snake::set_score(int new_score)
{
  score = new_score;
}

int Snake::get_score(void)
{
  return score;
}

void increment_score(void)
{
  score+=kBlockValue;
}
