#include "stackMin.h"
#include <iostream>

namespace cracking {
namespace stacksAndQueues {

void StackWithMin::push(int iData) {
  int min;
  if (aStack.size() > 0) {
    NodeWithMin aPeek = aStack.at(aStack.size()-1);
    min = aPeek.min;
  }
  min = (iData < min) ? iData : min;

  NodeWithMin aNodeWithMin(iData, min);
  // NOTE: copy constructor of NodeWithMin is used here
  aStack.push_back(aNodeWithMin);
}

int StackWithMin::pop() {

  NodeWithMin aPeek = aStack[aStack.size()-1];
  aStack.pop_back();
  return aPeek.data;
}

int StackWithMin::min() {
  NodeWithMin aPeek = aStack[aStack.size()-1];
  return aPeek.min;
}

void StackWithMin::print() {
  for (int i = 0; i < aStack.size(); i++) {
    std::cout << aStack[i].data << "| ";
  }
  std::cout << std::endl;
}

int StackWithMin::size() {
  return aStack.size();
}

}
}
