#include <stack>

namespace cracking {
namespace stacksAndQueues {

class QueueViaStacks {
  // just an adapter containing either list/deque/vector https://en.cppreference.com/w/cpp/container/stack
  std::stack<int> stackForNew;
  std::stack<int> stackForOld;
  size_t size = 0;
public:
  void add(int i);
  int remove();
  int peek();
  bool empty();
};


}
}
