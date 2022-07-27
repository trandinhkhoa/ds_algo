#include "urlify.h"

namespace {
int countSpaces(const std::string& iStr, int iTrueLength) {
  int aSpacesCount = 0;
  for (int i = 0; i < iTrueLength; i++) {
    if (iStr[i] == ' ') {
      aSpacesCount++;
    }
  }

  return aSpacesCount;
}

}
// TODO: read move semantic c++ -> return aResult actually does not involve copy
// TODO: read lvalue, rvalue
// TODO: cost of push_back ?
// Space complexity: O(iTrueLength)
std::string cracking::arraysAndStrings::urlify(const std::string& iStr, int iTrueLength) {
  std::string aResult;
  for (int i = 0; i < iTrueLength; i++) {
    if (iStr[i] == ' ') {
      aResult.push_back('\%');
      aResult.push_back('2');
      aResult.push_back('0');
    } else {
      aResult.push_back(iStr[i]);
    }
  }
  return aResult;
}

// Note: c++ std::string does not terminate with '\0' like C string (`str.c_str()`) does
// Because of resize(),
// if iStr does not have enough space, Time complexity is O(3*iTrueLength)
// Space is O(iTrueLength)
// if iStr have enough space (lot of useless spaces at the end), time complexity  is O(2*iTrueLength)
// Space is O(1)
// TODO: resize() complexity ???
void cracking::arraysAndStrings::urlify(std::string& iStr, int iTrueLength) {
  int aSpacesCount = countSpaces(iStr, iTrueLength);
  int aNeededLength = iTrueLength + (2 * aSpacesCount);

  iStr.resize(aNeededLength);
  int aIndex = aNeededLength - 1;

  for (int i = iTrueLength - 1; i >= 0; i--) {
    if (iStr[i] == ' ') {
      iStr[aIndex] = '0';
      iStr[aIndex - 1] = '2';
      iStr[aIndex - 2] = '\%';
      aIndex = aIndex - 3;
    } else {
      iStr[aIndex] = iStr[i];
      aIndex--;
    }
  }
}
