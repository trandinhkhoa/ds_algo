#include "stackOfPlates.h"
#include <iostream>

// Lession learned: if the logic seems to be too convoluted (e.g. too many nested if), you probably are on the wrong track.

// Time Complexity:
  // - push/pop O(1),
  // - popAt() O(K) K=N/C is the  number of stacks. N = number of plates, C = capacity => worst still O(N)
namespace cracking {
namespace stacksAndQueues {

StackOfPlates::StackOfPlates(size_t iSingleStackCapacity) {
  if (iSingleStackCapacity == 0) {
    throw std::runtime_error("Capacity of a single stack cannot be 0");
  }
  singleStackCapacity = iSingleStackCapacity;
  listOfStacks.emplace_back();
  stackPointer = listOfStacks.begin();
}

void StackOfPlates::push(int iNewPlate) {
  if (stackPointer->size() == singleStackCapacity) {
    listOfStacks.emplace_back();
    stackPointer++;
  }
  stackPointer->push_back(iNewPlate);
}

void StackOfPlates::leftShift(std::list<std::list<int>>::iterator iCurrentStack) {
  auto end = listOfStacks.end();
  end--;
  if (iCurrentStack == end) {
    if (iCurrentStack->empty()) {
      listOfStacks.pop_back();
      stackPointer = listOfStacks.end();
      stackPointer--;
    }
    return;
  }

  auto nextStack = iCurrentStack;
  nextStack++;

  std::vector<int> buffer;

  iCurrentStack->push_back(nextStack->front());
  nextStack->pop_front();

  leftShift(++iCurrentStack);
}

int StackOfPlates::popAt(int iStackId) {
  std::string errorMsg = "Stack Empty. Stack Id = " + std::to_string(iStackId);

  if (iStackId >= listOfStacks.size()) {
    throw std::runtime_error("Invalid StackId");
  }

  auto iter = listOfStacks.begin();
  for (int i = 0; i < iStackId; i++) {
    iter++;
  }

  if (iter->empty()) {
    throw std::runtime_error(errorMsg);
  }

  int returnValue = iter->back();
  iter->pop_back();

  if (iter->empty()) {
    if (iStackId == listOfStacks.size() - 1) {
      // pop at the end => same as pop()
      if (listOfStacks.size() > 1) {
        stackPointer--;
      listOfStacks.pop_back();
      }
    } else {
      if (listOfStacks.size() > 1) {
        listOfStacks.erase(iter);
      }
    }
  } else if (iStackId != listOfStacks.size() - 1) {
    leftShift(iter);
  }
  return returnValue;
}

int StackOfPlates::pop() {
  std::string errorMsg = "Stack Empty";

  if (stackPointer->empty()) {
    throw std::runtime_error(errorMsg);
  }

  int returnValue = stackPointer->back();
  stackPointer->pop_back();

  if (stackPointer->empty()) {
    if (listOfStacks.size() > 1) {
      stackPointer--;
      listOfStacks.pop_back();
    }
  }
  return returnValue;
}

}
}

