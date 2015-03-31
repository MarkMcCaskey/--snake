#include "../include/Block.hpp"

Block::Block(int x, int y, Block_type type)
{
  location {x,y};
  this.type = type;
}

Block::getLocation(void){ return location; }
Block::getType(void){ return type; }
