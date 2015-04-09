#include "../include/Snake.hpp"

Snake::Snake(int x, int y, Direction d)
{
    dir = d;

    // Pushes pairs (coordinates) into a vector.
    // Coordinates are viewed as cartesian coordinates
    // as opposed to SDL coordinates.
    blocks.push({x, y});
    for (int i = 1; i < kInitialSize; i++)
    {
        switch (d)
        {
            case Direction::down:
                blocks.push({x, y-i});
		break;
            case Direction::up:
                blocks.push({x, y+i});
		break;
            case Direction::right:
                blocks.push({x+1, y});
		break;
            case Direction::left:
                blocks.push({x-1, y});
		break;
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
            blocks.push(std::move(blocks.front()));
            blocks.pop();
            blocks.back().second -= 1;
            break;
        case Direction::up:
            blocks.push(std::move(blocks.front()));
            blocks.pop();
            blocks.back().second += 1;
            break;
        case Direction::right:
            blocks.push(std::move(blocks.front()));
            blocks.pop();
            blocks.back().first += 1;
            break;
        case Direction::left:
            blocks.push(std::move(blocks.front()));
            blocks.pop();
            blocks.back().first -= 1;
            break;
    }
}

void Snake::set_score(int new_score)
{
    score = new_score;
}

int Snake::get_score()
{
    return score;
}

void Snake::increment_score()
{
    score += kBlockValue;
}
