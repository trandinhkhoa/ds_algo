#include <vector>
#include <list>

namespace cracking {
namespace stacksAndQueues {

class StackOfPlates {
  size_t singleStackCapacity;
  // list is fine https://en.cppreference.com/w/cpp/container/stack
  std::list<std::list<int>>::iterator stackPointer;
  void leftShift(std::list<std::list<int>>::iterator iStackId);
public:
  StackOfPlates(size_t iSingleStackCapacity);
  int pop();

  void push(int iNewPlate);

  int popAt(int iStackId);

  std::list<std::list<int>> listOfStacks;
};


}
}
