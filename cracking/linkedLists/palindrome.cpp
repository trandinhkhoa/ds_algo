#include "palindrome.h"

// time complexity 2N
// space complexity 2N
namespace {

std::list<int> reverse(std::list<int>& iList) {
  std::list<int>::iterator aIterBegin = iList.begin();
  std::list<int>::const_iterator aIter = iList.begin();
  while (aIter != iList.end()) {
    iList.emplace_front(*aIter);
    std::list<int>::const_iterator aIterCopy(aIter);
    aIter++;
  }

  std::list<int> aReversedList(iList.begin(), aIterBegin);
  iList.erase(iList.begin(), aIterBegin);

  return aReversedList;
}

bool isSame(const std::list<int>& iList_1, const std::list<int>& iList_2) {
  if (iList_1.size() != iList_2.size()) {
    return false;
  }
  bool aSame = false;
  std::list<int>::const_iterator aIter_1 = iList_1.begin();
  std::list<int>::const_iterator aIter_2 = iList_2.begin();
   while (aIter_1 != iList_1.end()) {
    if (*aIter_1 != *aIter_2) {
      return false;
    }
    aIter_1++;
    aIter_2++;
  }
  return true;

}

}

namespace cracking {
namespace linkedLists {

bool palindrome(std::list<int>& iList) {
  std::list<int> aReversedList = reverse(iList);
  return isSame(iList, aReversedList);
}

}
}