#include "stringCompression.h"

// Time O(iStr.size())
// Note:
// What += does in the background ???
// Complexity of += for string ??? (mutable string vs immutable string)
// += actually call push_back (at least that's how it is for gcc)
// C++ strings are mutable so the performance considerations of concatenation are less of a concern.
// The entire reason StringBuilder exists is to cover the inefficiency of Java's immutable basic String type. In other words StringBuilder is patchwork, so we should be glad we don't need such a class in C++.
std::string cracking::arraysAndStrings::stringCompression(const std::string& iStr) {
  if (iStr.empty()) {
    return "";
  }

  char aCurrentChar = iStr[0];
  int aCurrentCharCount = 1;

  std::string aCompressedStr = "";
  for (int i = 1; i < iStr.size(); i++) {
    if (iStr[i] != aCurrentChar) {
      aCompressedStr += aCurrentChar + std::to_string(aCurrentCharCount);
      aCurrentChar = iStr[i];
      aCurrentCharCount = 1;
    } else {
      aCurrentCharCount++;
    }
  }

  aCompressedStr += aCurrentChar + std::to_string(aCurrentCharCount);

  if (aCompressedStr.size() >= iStr.size()) {
    return iStr;
  } else {
    return aCompressedStr;
  }
}
