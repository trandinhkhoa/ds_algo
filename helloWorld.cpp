#include <iostream>
#include <gtest/gtest.h>
#include "adder.h"
#include "sort.h"
#include "cracking/arraysAndStrings/isUnique.h"
#include "cracking/arraysAndStrings/checkPermutation.h"
#include "cracking/arraysAndStrings/urlify.h"
#include "cracking/arraysAndStrings/palindromPermutation.h"
#include "cracking/arraysAndStrings/oneAway.h"
#include "cracking/arraysAndStrings/stringCompression.h"

namespace helper {
void printArray(std::vector<int>& array) {
  // TODO: be able to std::cout << printArray
  std::cout << "Array = " << std::endl;
  for (int i = 0; i < array.size(); i++) {
    std::cout << array[i] << "\t";
  }
  std::cout << std::endl;
}

std::vector<int> generateArray(int length) {
  std::vector<int> generatedArray;
  // range 0 - 99
  int range = 100;
  // TODO: why srand is needed
  // srand(time(0));

  for (int i = 0; i < length; i++) {
    generatedArray.push_back(rand() % range);
  }
  return generatedArray;
}

bool isArraySortedAscending(std::vector<int>& array) {
  bool isSorted = true;
  for (int i = 0; i < array.size() - 1; i++) {
    if (array[i] > array[i+1]) {
      return false;
    }
  }
  return isSorted;
}
}

TEST(sampleTest, sampleTestcase) {
  EXPECT_EQ(adder(3,4), 7);
}

TEST(BubbleSortTest, BubbleSortTest_basic) {
  std::vector<int> array(helper::generateArray(100));
  bubbleSort(array);
  EXPECT_TRUE(helper::isArraySortedAscending(array));
}

TEST(BubbleSortTest, BubbleSortTest_oddSizedArray) {
  std::vector<int> array(helper::generateArray(101));
  bubbleSort(array);
  EXPECT_TRUE(helper::isArraySortedAscending(array));
}

TEST(MergeSortTest, MergeSortTest_basic) {
  // TODO: profile/add benchmarks for mergeSort, bubbleSort, etc.
  std::vector<int> array(helper::generateArray(100));
  mergeSort(array);
  EXPECT_TRUE(helper::isArraySortedAscending(array));
}

TEST(MergeSortTest, MergeSortTest_oddSizedArray) {
  std::vector<int> array(helper::generateArray(101));
  bubbleSort(array);
  EXPECT_TRUE(helper::isArraySortedAscending(array));
}

// TODO: test sorts with array.size = 1

TEST(QuickSortTest, QuickSortTest_basic) {
  std::vector<int> array(helper::generateArray(100));
  quickSort(array, 0, array.size() - 1);
  EXPECT_TRUE(helper::isArraySortedAscending(array));
}

TEST(QuickSortTest, QuickSortTest_oddSizedArray) {
  std::vector<int> array(helper::generateArray(101));
  quickSort(array, 0, array.size() - 1);
  EXPECT_TRUE(helper::isArraySortedAscending(array));
}

// Cracking the Coding Interview
// Chapter 1 Array and Strings

TEST(IsUniqueTest, IsUniqueTest_basic) {
  std::string aInputString = "qwertyuiopasdfghjklzxcvbnm1234567890-=[]~\\;',./";
  bool aResult = cracking::arraysAndStrings::hasAllUniqueCharacter(aInputString);
  EXPECT_TRUE(aResult);
}

TEST(IsUniqueTest, IsUniqueTest_shouldBeFalse) {
  std::string aInputString = "qwertyuiopasdfghjklzxcvbnm1234567890-=[[]]~\\;',./";
  bool aResult = cracking::arraysAndStrings::hasAllUniqueCharacter(aInputString);
  EXPECT_FALSE(aResult);
}

TEST(CheckPermutationTest, CheckPermutationTest_basic) {
  std::string aInputStringA = "acebde";
  std::string aInputStringB = "eabcde";
  bool aResult = cracking::arraysAndStrings::isPermutation(aInputStringA, aInputStringB);
  EXPECT_TRUE(aResult);
}

TEST(CheckPermutationTest, CheckPermutationTest_shouldBeFalse) {
  std::string aInputStringA = "acebda";
  std::string aInputStringB = "eabcde";
  bool aResult = cracking::arraysAndStrings::isPermutation(aInputStringA, aInputStringB);
  EXPECT_FALSE(aResult);
}

TEST(URLifyTest, URLifyTest_immutableString) {
  const std::string aInputStringA = "Mr John Smith                 ";
  std::string aResult = cracking::arraysAndStrings::urlify(aInputStringA, 13);
  EXPECT_EQ(aResult, "Mr\%20John\%20Smith");
}

TEST(URLifyTest, URLifyTest_inPlace) {
  std::string aInputStringA = "Mr John Smith           ";
  cracking::arraysAndStrings::urlify(aInputStringA, 13);
  EXPECT_EQ(aInputStringA, "Mr\%20John\%20Smith");
}

TEST(PalindromePermutationTest, PalindromPermutationTest_basic) {
  // tacycat
  std::string aInputStringA = "Tact Coa";
  bool aResult = cracking::arraysAndStrings::isPermutationOfPalindrome(aInputStringA);
  EXPECT_TRUE(aResult);
}

TEST(PalindromePermutationTest, PalindromPermutationTest_shouldReturnFalse) {
  std::string aInputStringA = "TactiCYa";
  bool aResult = cracking::arraysAndStrings::isPermutationOfPalindrome(aInputStringA);
  EXPECT_FALSE(aResult);
}

TEST(OneAwayTest, OneAwayTest_removeMiddle) {
  std::string aInputStringA = "pale";
  std::string aInputStringB = "ple";
  bool aResult = cracking::arraysAndStrings::oneAway(aInputStringA, aInputStringB);
  EXPECT_TRUE(aResult);
}

TEST(OneAwayTest, OneAwayTest_insertEnd) {
  std::string aInputStringA = "pale";
  std::string aInputStringB = "pales";
  bool aResult = cracking::arraysAndStrings::oneAway(aInputStringA, aInputStringB);
  EXPECT_TRUE(aResult);
}

TEST(OneAwayTest, OneAwayTest_modify) {
  std::string aInputStringA = "pale";
  std::string aInputStringB = "bale";
  bool aResult = cracking::arraysAndStrings::oneAway(aInputStringA, aInputStringB);
  EXPECT_TRUE(aResult);
}

TEST(OneAwayTest, OneAwayTest_shouldReturnFalse) {
  std::string aInputStringA = "pale";
  std::string aInputStringB = "bae";
  bool aResult = cracking::arraysAndStrings::oneAway(aInputStringA, aInputStringB);
  EXPECT_FALSE(aResult);
}

TEST(StringCompressionTest, StringCompressionTest_basic) {
  std::string aInputString = "aabcccccccccccaaaeeeeeeeeeeeeee";
  std::string aResult = cracking::arraysAndStrings::stringCompression(aInputString);
  EXPECT_EQ(aResult, "a2b1c11a3e14");
}

TEST(StringCompressionTest, StringCompressionTest_shouldNotCompress_1) {
  std::string aInputString = "abcde";
  std::string aResult = cracking::arraysAndStrings::stringCompression(aInputString);
  EXPECT_EQ(aResult, "abcde");
}

TEST(StringCompressionTest, StringCompressionTest_shouldNotCompress_2) {
  std::string aInputString = "aabbccdd";
  std::string aResult = cracking::arraysAndStrings::stringCompression(aInputString);
  EXPECT_EQ(aResult, "aabbccdd");
}