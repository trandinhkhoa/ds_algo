#include <iostream>
#include <fstream>
#include <gtest/gtest.h>
#include "adder.h"
#include "sort.h"
#include "cracking/arraysAndStrings/isUnique.h"
#include "cracking/arraysAndStrings/checkPermutation.h"
#include "cracking/arraysAndStrings/urlify.h"
#include "cracking/arraysAndStrings/palindromPermutation.h"
#include "cracking/arraysAndStrings/oneAway.h"
#include "cracking/arraysAndStrings/stringCompression.h"
#include "cracking/arraysAndStrings/rotateMatrix.h"

namespace helper {
void printArray(std::vector<int>& array) {
  // TODO: be able to std::cout << printArray
  std::cout << "Array = " << std::endl;
  for (int i = 0; i < array.size(); i++) {
    std::cout << array[i] << "\t";
  }
  std::cout << std::endl;
}

void printMatrix(const std::vector<std::vector<uint32_t>>& iMatrix, bool ascii_art) {
  std::cout << "Matrix = " << std::endl;
  for (int i = 0; i < iMatrix.size(); i++) {
    for (int j = 0; j < iMatrix[i].size(); j++) {
      if (ascii_art) {
        std::cout << static_cast<char>(iMatrix[i][j]) << " ";
      } else {
        std::cout << iMatrix[i][j] << " ";
      }
    }
    std::cout << std::endl;
  }
}

bool compareMatrix(const std::vector<std::vector<uint32_t>>& iMatrix1, const std::vector<std::vector<uint32_t>>& iMatrix2) {
  for (int i = 0; i < iMatrix1.size(); i++) {
    for (int j = 0; j < iMatrix1.size(); j++) {
      if (iMatrix1[i][j] != iMatrix2[i][j]) {
        return false;
      }
    }
  }
  return true;
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

//  Given an image represented by an NxN matrix, where each pixel in the image is 4 bytes, write a method to rotate the image by 90 degrees. Can you do this in place?
TEST(RotateMatrixTest, RotateMatrixTest_even_size) {
  std::vector<std::vector<uint32_t>> aMatrix = {
    {11, 12, 13, 14},
    {21, 22, 23, 24},
    {31, 32, 33, 34},
    {41, 42, 43, 44}
  };

  std::vector<std::vector<uint32_t>> aExpectedMatrix_1 = {
    {41, 31, 21, 11},
    {42, 32, 22, 12},
    {43, 33, 23, 13},
    {44, 34, 24, 14}
  };
  cracking::arraysAndStrings::rotateMatrix(aMatrix);

  u_int32_t aOldValue = aExpectedMatrix_1[0][0];
  aExpectedMatrix_1[0][0] = -1;
  EXPECT_FALSE(helper::compareMatrix(aMatrix, aExpectedMatrix_1));
  aExpectedMatrix_1[0][0] = aOldValue;
  EXPECT_TRUE(helper::compareMatrix(aMatrix, aExpectedMatrix_1));
}

TEST(RotateMatrixTest, RotateMatrixTest_odd_size) {
  std::vector<std::vector<uint32_t>> aMatrix = {
    {11, 12, 13, 14, 15},
    {21, 22, 23, 24, 25},
    {31, 32, 33, 34, 35},
    {41, 42, 43, 44, 45},
    {51, 52, 53, 54, 55}
  };

  std::vector<std::vector<uint32_t>> aExpectedMatrix_1 = {
    {51, 41, 31, 21, 11},
    {52, 42, 32, 22, 12},
    {53, 43, 33, 23, 13},
    {54, 44, 34, 24, 14},
    {55, 45, 35, 25, 15},
  };


  cracking::arraysAndStrings::rotateMatrix(aMatrix);

  u_int32_t aOldValue = aExpectedMatrix_1[0][0];
  aExpectedMatrix_1[0][0] = -1;
  EXPECT_FALSE(helper::compareMatrix(aMatrix, aExpectedMatrix_1));
  aExpectedMatrix_1[0][0] = aOldValue;
  EXPECT_TRUE(helper::compareMatrix(aMatrix, aExpectedMatrix_1));
}

TEST(RotateMatrixTest, RotateMatrixTest_basic) {
  std::ifstream aFile;
  std::string aFilePath = "./RotateMatrixInput.txt";
  aFile.open(aFilePath);
  std::string aline;
  std::vector<std::vector<uint32_t>> aMatrix;
  if (aFile.is_open()) {
    while (std::getline(aFile, aline)) {
      std::vector<uint32_t> aRow(aline.begin(), aline.end());
      // or
      // aRow.assign(aline.begin(), aline.end());
      aMatrix.push_back(aRow);
    }
    aFile.close();
  } else {
    std::cout << "Unable to open the file" << aFilePath << std::endl;
  }

  for (int i = 0; i < aMatrix.size(); i++) {
    for (int j = 0; j < aMatrix[i].size(); j++) {
      std::cout << static_cast<char>(aMatrix[i][j]) << " ";
    }
    std::cout << std::endl;
  }

  std::cout << "After" << std::endl;
  cracking::arraysAndStrings::rotateMatrix(aMatrix);
  helper::printMatrix(aMatrix, true);
}