#include "returnKthToLast.h"
#include <iostream>

int cracking::linkedLists::returnKthToLast(const std::list<int>& iList, const unsigned int& k){
  if (k > iList.size()) {
    return INT32_MIN;
  }
  std::list<int>::const_iterator aFirstIter;
  std::list<int>::const_iterator aSecondIter;
  aFirstIter = iList.begin();
  for (int i = 0; i < k; i++) {
    aFirstIter++;
  }

  aSecondIter = iList.begin();
  while (aFirstIter != iList.end()) {
    aFirstIter++;
    aSecondIter++;
  }
  return *aSecondIter;
}