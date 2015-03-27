#include <vector>
#include <utility>

class Snake
{
public:
    enum class Direction {up, down, left, right};
    
    explicit Snake(int x = 0, int y = 0, Direction d = Direction::down);
    void move(int dt);

private:
    const int kBps{1};
    const int kInitialSize{4};
    std::vector<std::pair<int, int>> blocks;
    Direction dir;

    void rotate();
};
