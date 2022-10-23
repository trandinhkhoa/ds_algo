#include "sortStack.h"

// space O(N)
// time O(2*N*N + N) = O(N^2)
// TODO: quickSort + mergeSort using more buffers
// TODO: time can be O(N*N +N) not (2N^2+N)
namespace cracking {
namespace stacksAndQueues {


void sortStack(std::vector<int>& iStack) {
  int count = iStack.size();
  int totalLoop = iStack.size();

  std::vector<int> bufferStack;
  for (int j = 0; j < totalLoop; j++) {
    int min = iStack.back();
    for (int i = 0; i < count; i++) {
      if (iStack.back() < min) {
        min = iStack.back();
      }
      bufferStack.push_back(iStack.back());
      iStack.pop_back();
    }

    bool found = false;
    for (int i = 0; i < count; i++) {
      if (min == bufferStack.back() && !found) {
        bufferStack.pop_back();
        found = true;
      } else {
        iStack.push_back(bufferStack.back());
        bufferStack.pop_back();
      }
    }
    bufferStack.push_back(min);
    count--;
  }

  while (!bufferStack.empty()) {
    iStack.push_back(bufferStack.back());
    bufferStack.pop_back();
  }
}


}
}

