#include <utility>

class Block
{
public:
  enum class Block_type{apple, multiplier, wall};
  explicit Block(int x = 0, int y = 0, Block_type type = Block_type::apple);
  std::pair<int,int> getLocation(void);
  Block_type getType(void);

private:
  Block_type type;
  std::pair<int, int> location;
};
