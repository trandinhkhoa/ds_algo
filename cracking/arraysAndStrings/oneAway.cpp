#include "oneAway.h"

bool cracking::arraysAndStrings::oneAway(const std::string& iStrA, const std::string& iStrB) {
  int aDiffInSize = iStrA.size() - iStrB.size();
  if ((aDiffInSize > 1) || (aDiffInSize < -1)) {
    return false;
  }

  if ((aDiffInSize == 1) || (aDiffInSize == -1)) {
    int i = 0;
    int j = 0;

    const std::string& aShorterString = (aDiffInSize == 1) ? iStrB : iStrA;
    const std::string& aLongerString = (aDiffInSize == 1) ? iStrA : iStrB;

    int aDiffCount = 0;
    while ((i < aShorterString.size()) && (j < aLongerString.size())) {
      if (aShorterString[i] != aLongerString[j]) {
        if ((aDiffCount > 0) || (aShorterString[i] != aLongerString[++j])) {
          return false;
        } else {
          aDiffCount++;
        }
      }
      i++;
      j++;
    }
    return true;
  }

  int aDiffCount = 0;
  for (int i = 0; i < iStrA.size(); i++) {
    if (iStrA[i] != iStrB[i]) {
      if (aDiffCount > 0) {
        return false;
      }
      aDiffCount++;
    }
  }

  return true;
}
