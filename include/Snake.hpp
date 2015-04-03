#include <queue>
#include <utility>

class Snake
{
public:
    enum class Direction {up, down, left, right};
    
    explicit Snake(int x = 0, int y = 0, Direction d = Direction::down);
    void move(int dt);
    void set_score(int score);
    int get_score(void);
    void increment_score(void);

private:
    const int kBps{1};
    const int kInitialSize{4};
    const int kBlockValue{1};
    std::queue<std::pair<int, int>> blocks;
    Direction dir;
    int score;

    void rotate();
};
