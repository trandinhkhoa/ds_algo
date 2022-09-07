#include "stringRotation.h"

bool cracking::arraysAndStrings::isStringRotation(std::string& str_1, std::string& str_2) {
  if (str_1.size() != str_2.size()) {
    return false;
  }

  if ((str_1.size() == 0 ) && (str_2.size() == 0)) {
    return true;
  }

  for (int i = 0; i < str_1.size(); i++) {
    std::string str_1_rotated = str_1.substr(i, str_1.size() - i) + str_1.substr(0, i);
    if (str_1_rotated == str_2) {
      return true;
    }
  }
  return false;
}

bool cracking::arraysAndStrings::isStringRotation_2(std::string& str_1, std::string& str_2) {
  if (str_1.size() != str_2.size()) {
    return false;
  }

  std::string str_1str_1 = str_1 + str_1;

  if (str_1str_1.find(str_2) != std::string::npos) {
    return true;
  }
  else {
    return false;
  }
}
