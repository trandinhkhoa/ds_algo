#include "reverseString.h"
#include <iostream>

void cracking::cAndCpp::reverseString(char* iStr) {
  if (!iStr) {
    std::cout << "String pointer is null" << std::endl;
    return;
  }
  unsigned int aIndex = 0;
  char aTemp;
  char* end = iStr;
  while (*end != '\0') {
    end++;
  }
  char* iteratorBegin = iStr;
  char* iteratorEnd = end - 1;

  while (iteratorBegin < iteratorEnd) {
    aTemp = *iteratorBegin;
    *iteratorBegin = *iteratorEnd;
    *iteratorEnd = aTemp;
    iteratorBegin++;
    iteratorEnd--;
  }
}