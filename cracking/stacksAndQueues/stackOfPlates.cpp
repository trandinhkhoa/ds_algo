#include "stackOfPlates.h"
#include <iostream>

// O(1) for all.
// Limitation:
  // too complicated to support popAt O(1). error prone
  //  The value of popAt is implementation specific
  // another simpler implementation is to shift the plate backward everytime popAt finished => popAt O(n) time with n is the capacity of each stack.
  // pop + push still O(1)
namespace cracking {
namespace stacksAndQueues {

StackOfPlates::PushTrackerItem::PushTrackerItem(int iStackId, int iCount){
  this->count = iCount;
  this->stackId = iStackId;
}

StackOfPlates::StackOfPlates(size_t iSingleStackCapacity) {
  singleStackCapacity = iSingleStackCapacity;
  std::vector<int> aStack;
  arrayOfStacks.push_back(aStack);
  popTracker.push_back(0);
}

void StackOfPlates::pushHelper(int iNewPlate, int iStackId) {
  arrayOfStacks.at(iStackId).push_back(iNewPlate);
  if (pushTracker.size() != 0 && pushTracker.back().stackId == iStackId) {
    pushTracker.back().count++;
  } else {
    PushTrackerItem aPushTrackerItem(iStackId, 1);
    pushTracker.push_back(aPushTrackerItem);
  }
}

void StackOfPlates::push(int iNewPlate) {
  int idToPush = popTracker.back();
  // use at to have exception instead of seg fault in case of out of bound
  if (arrayOfStacks.at(idToPush).size() == singleStackCapacity) {
    popTracker.pop_back();
    // pop tracker empty -> there is no pop recently => all existing stack filled
    if (popTracker.empty()) {
      int idOfNewStack = arrayOfStacks.size();

      // create new stack;
      std::vector<int> aStack;
      arrayOfStacks.push_back(aStack);

      popTracker.push_back(idOfNewStack);
      idToPush = idOfNewStack;
    } else {
      idToPush = popTracker.back();
      // popTracker.pop_back();
    }
  }
  pushHelper(iNewPlate, idToPush);
}

int StackOfPlates::popAt(int iStackId) {
  if (arrayOfStacks.at(iStackId).empty()) {
    std::string errorMsg("Stack Empty. Id = " + std::to_string(iStackId));
    throw std::runtime_error(errorMsg);
  } else {
    int returnValue;
    // disregard the pushTracker. pushTracker might not reflect the real amount of plates because of this
    // this is why it is still necessary to check for fullness/emptiness of the stack when pushed/popped
    returnValue = arrayOfStacks.at(iStackId).back();
    arrayOfStacks.at(iStackId).pop_back();
    if (iStackId != popTracker.back()) {
      popTracker.push_back(iStackId);
    }
    return returnValue;
  }
}

int StackOfPlates::pop() {
  if (pushTracker.size() == 0) {
    std::string errorMsg("Stack Empty");
    throw std::runtime_error(errorMsg);
  }
  int returnValue;

  // should check if stack is empty, if empty pop, until non empty
  int stackId = pushTracker.back().stackId;
  if (!arrayOfStacks.at(stackId).empty())
  {
    returnValue = arrayOfStacks.at(stackId).back();
    arrayOfStacks.at(stackId).pop_back();
  } else {
    std::string errorMsg("Stack Empty");
    throw std::runtime_error(errorMsg);
  }

  pushTracker.back().count--;
  if (pushTracker.back().count == 0) {
    pushTracker.pop_back();
  }

  if (stackId != popTracker.back()) {
    popTracker.push_back(stackId);
  }

  return returnValue;
}

}
}

