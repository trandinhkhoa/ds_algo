#include "checkPermutation.h"
#include <iostream>
#include <vector>
#include <algorithm>

namespace {

const int ASCII_size = 128;
const int UTF_8_size = 128;
// const int UTF_16_size = ???;

}

// pros: simple
// cons:  copying + sorting string may takes time + extra space
// time complexity is O((A+B)+(AlogA+BlogB)+(A)) = O(A+B)
// space complexity is O(A+B)
// bool cracking::arraysAndStrings::isPermutation(const std::string& iStrA, const std::string& iStrB) {
//   std::string aCopyA = iStrA;
//   std::string aCopyB = iStrB;
//   std::sort(aCopyA.begin(), aCopyA.end());
//   std::sort(aCopyB.begin(), aCopyB.end());
//   return (aCopyA == aCopyB);
// }

// time complexity is O(A+B)
// space complexity is O(1). It takes up extra space but that amount is almost constant
bool cracking::arraysAndStrings::isPermutation(const std::string& iStrA, const std::string& iStrB) {
  if (iStrA.size() != iStrB.size()) {
    return false;
  }

  std::vector<int> lettersCount(ASCII_size, 0);

  for (int i = 0; i < iStrA.size(); i++) {
    lettersCount[int(iStrA[i])]++;
  }

  for (int i = 0; i < iStrB.size(); i++) {
    lettersCount[int(iStrB[i])]--;
    if (lettersCount[int(iStrB[i])] < 0) {
      return false;
    }
  }

  return true;

}