#include <exception>

#include "../include/Board.hpp"

using namespace std;

Board::Board() : kBoardWidth{25}, kBoardHeight{25}
{
    Board(25, 25);
}

Board::Board(int w, int h) : kBoardWidth{w}, kBoardHeight{h}
{
    if (SDL_Init(SDL_INIT_VIDEO) < 0)
        throw std::exception{};

    for (int i = 0; i < w; i++)
    {
        vector<BlockType> temp{};
        for (int j = 0; j < h; j++)
            temp.push_back(BlockType::empty);
        grid.push_back(std::move(temp));
    }
}


Board::~Board()
{
    SDL_Quit();
}

vector<vector<Board::BlockType>> Board::getGrid()
{
    return this->grid;
}
