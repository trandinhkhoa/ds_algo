#include <vector>
#include <iostream>

namespace cracking {
namespace stacksAndQueues {


class StackWithMin {
  // NOTE: this class should not be accessible from outside
  // -> already the case
  // NodeWithMin' is a private member of 'cracking::stacksAndQueues::StackWithMin'
  class NodeWithMin {
  public:
    int min;
    int data;
    NodeWithMin(int iData, int iMin): min(iMin), data(iData) {};

    // NOTE: not needed, just to check when copy constructor is called
    NodeWithMin(const NodeWithMin& iCopy) {
      min = iCopy.min;
      data = iCopy.data;
    }
  };
  std::vector<NodeWithMin> aStack;

public:
  void push(int iData);
  int pop();
  int min();
  int size();
  void print();
};

}
}

