#include "isUnique.h"
#include <iostream>
#include <vector>

namespace {

const int ASCII_size = 128;
const int UTF_8_size = 128;
// const int UTF_16_size = ???;

}

bool cracking::arraysAndStrings::hasAllUniqueCharacter(std::string& iStr) {
  std::vector<bool> hashTable(ASCII_size, false);

  if (iStr.size() > ASCII_size) {
    return false;
  }

  for (int i = 0; i < iStr.size(); i++) {
    if (hashTable[int(iStr[i])]) {
      return false;
    }
    hashTable[int(iStr[i])] = true;
  }
  return true;
}

// TODO: brute force
// TODO: no additional data structure