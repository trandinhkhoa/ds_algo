#include "palindromPermutation.h"
#include <vector>
#include <algorithm>

namespace {

const int ASCII_size = 128;
const int UTF_8_size = 128;
// const int UTF_16_size = ???;

}

// Note: tolower, isalpha only work on ASCII (e.g. a-z, A-Z). TODO: make it work with Unicode chars (e.g. â Â)
// bool cracking::arraysAndStrings::isPermutationOfPalindrome(std::string& iStr) {

//   std::vector<bool> hash(ASCII_size, true);

//   std::transform(iStr.begin(), iStr.end(), iStr.begin(),
//                 [](unsigned char c){ return std::tolower(c);} );

//   for (int i = 0; i < iStr.size(); i++) {
//     if (std::isalpha(iStr[i])) {
//       hash[iStr[i]] = !hash[iStr[i]];
//     }
//   }

//   int aNumberOfUniqueChar = 0;
//   for (int i = 0; i < hash.size(); i++) {
//     if (!hash[i]) {
//       aNumberOfUniqueChar++;
//       if (aNumberOfUniqueChar > 1) {
//         return false;
//       }
//     }
//   }

//   return true;
// }

// **Method 2**:
// Note:
// - (int)var vs int(var) = same. both actually call static_cast<int>(var)
// https://en.cppreference.com/w/cpp/language/explicit_cast
// - non-class types (including fundamental types, array types, reference types, pointer types, and enum types) do not have constructors.
// - another way to cast to int: +var
// alphatbet = 26 lettter -> 32-bit bit vector -> uint32_t
// test case "TactiCYa" return true if uint16_t, uint8_t is used (i and Y fall on to the same position in the bitVector) -> WRONG
// - may Only work in case of ASCII letters. unicode -> the amount of characters maybe more than 64 (uint64_t) -> try a real bit vector: std:: bitset

// [](param) {body} https://en.cppreference.com/w/cpp/language/lambda
bool cracking::arraysAndStrings::isPermutationOfPalindrome(std::string& iStr) {

  uint32_t bitVector = 0;

  std::transform(iStr.begin(), iStr.end(), iStr.begin(),
                [](unsigned char c){ return std::tolower(c);} );

  for (int i = 0; i < iStr.size(); i++) {
    if (std::isalpha(iStr[i])) {
      int mask = 1;
      mask = mask << static_cast<int>(iStr[i]-int('a'));
      bitVector = bitVector ^ mask;
    }
  }

  return !(bitVector & (bitVector - 1));
}