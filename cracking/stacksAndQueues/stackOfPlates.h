#include <vector>

namespace cracking {
namespace stacksAndQueues {

class StackOfPlates {
  class PushTrackerItem {
  public:
    int stackId;
    int count;
    PushTrackerItem(int iStackId, int iCount);
  };

  std::vector<std::vector<int>> arrayOfStacks;
  std::vector<PushTrackerItem> pushTracker;
  std::vector<int> popTracker;
  size_t singleStackCapacity;

public:
  StackOfPlates(size_t iSingleStackCapacity);
  int pop();

  void pushHelper(int iNewPlate, int StackId);

  void push(int iNewPlate);

  void pushAt(int iNewPlate, int stackId);
  int popAt(int stackId);
};

}
}
