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
  switch(dir)
    {
    case Direction::down:
      blocks.pop_front();
      blocks.push_back({blocks.back().first,blocks.back().second-1});
      break;
    case Direction::up:
      blocks.pop_front();
      blocks.push_back({blocks.back().first,blocks.back().second+1});
      break;
    case Direction::right:
      blocks.pop_front();
      blocks.push_back({blocks.back().first+1,blocks.back().second});
      break;
    case Direction::left:
      blocks.pop_front();
      blocks.push_back({blocks.back().first-1,blocks.back().second});
      break;
    }
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
