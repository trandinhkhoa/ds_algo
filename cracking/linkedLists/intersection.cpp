#include "intersection.h"
#include <iostream>

namespace {

void moveForward(std::list<int*>::iterator& iIter, int distance) {
  for (int i = 0; i < distance; i++) {
   iIter++;
  }
}


}
namespace cracking {
namespace linkedLists {

int* intersection(std::list<int*>& iList_1, std::list<int*>& iList_2) {
  // using a linkedlist implem with only the node's data + next ptr, you would have to traverse to the end to get the size.
  // But once you reach the end, you can also find out whether the lists are intersect or not (same end)

  std::list<int*>::iterator aIter_1 = iList_1.begin();
  std::list<int*>::iterator aIter_2 = iList_2.begin();

  int aSizeDiff = iList_1.size() - iList_2.size();
  if (aSizeDiff < 0) {
    moveForward(aIter_2, -aSizeDiff);
  } else if (aSizeDiff > 0) {
    moveForward(aIter_1, aSizeDiff);
  }

  int* aIntersection = nullptr;
  while (aIter_1 != iList_1.end()) {
    if (*aIter_1 == *aIter_2) {
      aIntersection = *aIter_1;
      break;
    }
    aIter_1++;
    aIter_2++;
  }

  return aIntersection;
}

}
}