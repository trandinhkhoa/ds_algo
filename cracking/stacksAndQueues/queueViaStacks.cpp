#include "queueViaStacks.h"

namespace cracking {
namespace stacksAndQueues {


void QueueViaStacks::add(int i) {
  stackForNew.push(i);
}

int QueueViaStacks::remove() {
  if (empty()) {
    throw std::runtime_error("Empty");
  }

  int returnValue = peek();
  stackForOld.pop();
  return returnValue;
}

int QueueViaStacks::peek() {
  if (empty()) {
    throw std::runtime_error("Empty");
  }

  if (stackForOld.empty()) {
    while (!stackForNew.empty()) {
      stackForOld.push(stackForNew.top());
      stackForNew.pop();
    }
  }
  int returnValue = stackForOld.top();
  return returnValue;
}

bool QueueViaStacks::empty() {
  return stackForNew.empty() && stackForOld.empty();
}



}
}
