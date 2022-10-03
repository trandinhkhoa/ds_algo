#include "sumLists.h"

namespace cracking {
namespace linkedLists {

std::list<uint16_t> sumLists(const std::list<uint16_t>& iList_1, const std::list<uint16_t>& iList_2) {
  std::list<uint16_t> aSumList;
  std::list<uint16_t>::const_iterator aIter_1 = iList_1.begin();
  std::list<uint16_t>::const_iterator aIter_2 = iList_2.begin();
  uint16_t aCarry = 0;

  while ((aIter_1 != iList_1.end()) || (aIter_2 != iList_2.end())) {
    uint16_t aOperand_1 = (aIter_1 != iList_1.end()) ? *aIter_1 : 0;
    uint16_t aOperand_2 = (aIter_2 != iList_2.end()) ? *aIter_2 : 0;
    uint16_t aSum = aOperand_1 + aOperand_2 + aCarry;
    if (aSum >= 10) {
      aSum = aSum - 10;
      aCarry = 1;
    } else {
      aCarry = 0;
    }
    aSumList.emplace_back(aSum);
    if (aIter_1 != iList_1.end()) {
      aIter_1++;
    }
    if (aIter_2 != iList_2.end()) {
      aIter_2++;
    }
  }

  if (aCarry == 1) {
    aSumList.emplace_back(aCarry);
  }

  return aSumList;
}

namespace {
void padWithZero(std::list<uint16_t>& iList, uint16_t iTargetSize) {
  while (iList.size() < iTargetSize) {
    iList.emplace_front(0);
  }
}

uint16_t sumDigits(std::list<uint16_t>::iterator& iIter_1,
                  std::list<uint16_t>::iterator& iIter_2,
                  const std::list<uint16_t>::iterator& iEnd_1,
                  std::list<uint16_t>& iSumList) {
  if (iIter_1 == iEnd_1) {
    return 0;
  }

  std::list<uint16_t>::iterator aIterCopy_1(iIter_1);
  std::list<uint16_t>::iterator aIterCopy_2(iIter_2);
  aIterCopy_1++;
  aIterCopy_2++;

  uint16_t aCarry = sumDigits(aIterCopy_1, aIterCopy_2, iEnd_1, iSumList);

  uint16_t aSum = *iIter_1 + *iIter_2 + aCarry;
  if (aSum >= 10) {
    aSum = aSum - 10;
    aCarry = 1;
  } else {
    aCarry = 0;
  }
  iSumList.emplace_front(aSum);

  return aCarry;
}

}
std::list<uint16_t> sumListsReverse(std::list<uint16_t>& iList_1, std::list<uint16_t>& iList_2) {
  if (iList_1.size() < iList_2.size()) {
    padWithZero(iList_1, iList_2.size());
  } else if (iList_2.size() < iList_1.size()) {
    padWithZero(iList_2, iList_1.size());
  }

  std::list<uint16_t> aSumList;
  std::list<uint16_t>::iterator aIter_1 = iList_1.begin();
  std::list<uint16_t>::iterator aIter_2 = iList_2.begin();
  uint16_t aCarry = sumDigits(aIter_1, aIter_2, iList_1.end(), aSumList);
  if (aCarry > 0) {
    aSumList.emplace_front(1);
  }
  return aSumList;

}

}
}