#include "../include/Board.hpp"

using namespace std;

Board::Board() : kBoardWidth{25}, kBoardHeight{25}
{
    Board(25, 25);
}

Board::Board(int w, int h) : kBoardWidth{w}, kBoardHeight{h}
{
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
}

vector<vector<Board::BlockType>> Board::getGrid()
{
    return this->grid;
}
