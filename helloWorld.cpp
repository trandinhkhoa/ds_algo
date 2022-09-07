#include <iostream>
#include <fstream>
#include <memory>
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
#include "cracking/arraysAndStrings/zeroMatrix.h"
#include "cracking/arraysAndStrings/stringRotation.h"
#include "cracking/cAndCpp/lastKLines.h"
#include "cracking/cAndCpp/reverseString.h"
#include "cracking/cAndCpp/copyNode.h"
#include "cracking/cAndCpp/smartPointer.h"

namespace helper {

template<class T>
void printArray(const std::vector<T>& iArray, const std::string iDelimeter = "\t") {
  // TODO: be able to std::cout << printArray
  std::cout << "Array Size = " << iArray.size() << std::endl;
  for (int i = 0; i < iArray.size(); i++) {
    std::cout << iArray[i] << iDelimeter;
  }
  std::cout << std::endl;
}

template<class T>
bool compareArray(const std::vector<T>& iArray1, const std::vector<T>& iArray2) {
  if (iArray1.size() != iArray2.size()) {
    return false;
  }

  for (int i = 0; i < iArray1.size(); i++) {
    if (iArray1[i] != iArray2[i]) {
      return false;
    }
  }

  return true;
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

bool compareMatrix(const std::vector<std::vector<uint32_t>>& iMatrix1,
                  const unsigned int height_1, const unsigned int width_1,
                  const std::vector<std::vector<uint32_t>>& iMatrix2,
                  const unsigned int height_2, const unsigned int width_2) {
  if (width_1 != width_2 || height_1 != height_2) {
    return false;
  }
  for (int i = 0; i < height_1; i++) {
    for (int j = 0; j < width_1; j++) {
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
  EXPECT_FALSE(helper::compareMatrix(aMatrix, aMatrix.size(), aMatrix.size(),
                                    aExpectedMatrix_1, aExpectedMatrix_1.size(), aExpectedMatrix_1.size()));
  aExpectedMatrix_1[0][0] = aOldValue;
  EXPECT_TRUE(helper::compareMatrix(aMatrix, aMatrix.size(), aMatrix.size(),
                                    aExpectedMatrix_1, aExpectedMatrix_1.size(), aExpectedMatrix_1.size()));
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
  EXPECT_FALSE(helper::compareMatrix(aMatrix, aMatrix.size(), aMatrix.size(),
                                    aExpectedMatrix_1, aExpectedMatrix_1.size(), aExpectedMatrix_1.size()));
  aExpectedMatrix_1[0][0] = aOldValue;
  EXPECT_TRUE(helper::compareMatrix(aMatrix, aMatrix.size(), aMatrix.size(),
                                    aExpectedMatrix_1, aExpectedMatrix_1.size(), aExpectedMatrix_1.size()));
}

TEST(RotateMatrixTest, RotateMatrixTest_basic) {
  std::ifstream aFile;
  std::string aFilePath = "./crackingTestInputs/arraysAndStrings/RotateMatrixInput.txt";
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

TEST(ZeroMatrixTest, ZeroMatrixTest_basic) {
  std::vector<std::vector<uint32_t>> aMatrix = {
    {1, 3, 4, 1, 4},
    {1, 0, 4, 1, 4},
    {1, 3, 0, 0, 4},
    {1, 3, 4, 0, 4},
    {1, 3, 0, 1, 4},
    {0, 3, 0, 1, 4},
  };

  std::vector<std::vector<uint32_t>> aExpectMatrix = {
    {0, 0, 0, 0, 4},
    {0, 0, 0, 0, 0},
    {0, 0, 0, 0, 0},
    {0, 0, 0, 0, 0},
    {0, 0, 0, 0, 0},
    {0, 0, 0, 0, 0},
  };

  cracking::arraysAndStrings::zeroMatrix_2(aMatrix, 6, 5);
  EXPECT_TRUE(helper::compareMatrix(aMatrix, 6, 5,
                                    aExpectMatrix, 6, 5));
}

TEST(ZeroMatrixTest, ZeroMatrixTest_basic_2) {
  std::vector<std::vector<uint32_t>> aMatrix = {
    {1, 3, 4, 1, 4},
    {1, 0, 4, 1, 4},
    {1, 3, 9, 8, 4},
    {1, 3, 4, 7, 4},
    {1, 3, 8, 0, 4},
    {2, 3, 9, 1, 4},
  };
  std::vector<std::vector<uint32_t>> aExpectedMatrix = {
    {1, 0, 4, 0, 4},
    {0, 0, 0, 0, 0},
    {1, 0, 9, 0, 4},
    {1, 0, 4, 0, 4},
    {0, 0, 0, 0, 0},
    {2, 0, 9, 0, 4},
  };

  cracking::arraysAndStrings::zeroMatrix_2(aMatrix, 6, 5);
  EXPECT_TRUE(helper::compareMatrix(aMatrix, 6, 5,
                                    aExpectedMatrix, 6, 5));
}

TEST(ZeroMatrixTest, ZeroMatrixTest_basic_3) {
  std::vector<std::vector<uint32_t>> aMatrix = {
    {0, 3, 4, 1, 0},
    {1, 2, 4, 1, 4},
    {1, 3, 9, 8, 4},
    {1, 3, 4, 7, 4},
    {1, 3, 8, 9, 4},
    {0, 3, 9, 1, 0},
  };
  std::vector<std::vector<uint32_t>> aExpectedMatrix = {
    {0, 0, 0, 0, 0},
    {0, 2, 4, 1, 0},
    {0, 3, 9, 8, 0},
    {0, 3, 4, 7, 0},
    {0, 3, 8, 9, 0},
    {0, 0, 0, 0, 0},
  };

  cracking::arraysAndStrings::zeroMatrix_2(aMatrix, 6, 5);
  EXPECT_TRUE(helper::compareMatrix(aMatrix, 6, 5,
                                    aExpectedMatrix, 6, 5));
}

TEST(ZeroMatrixTest, ZeroMatrixTest_basic_4) {
  std::vector<std::vector<uint32_t>> aMatrix = {
    {1, 3, 4, 1, 0},
    {1, 0, 4, 1, 4},
    {1, 3, 0, 0, 4},
    {1, 3, 4, 9, 4},
    {1, 3, 0, 1, 4},
    {1, 3, 0, 1, 4},
  };
  std::vector<std::vector<uint32_t>> aExpectedMatrix = {
    {0, 0, 0, 0, 0},
    {0, 0, 0, 0, 0},
    {0, 0, 0, 0, 0},
    {1, 0, 0, 0, 0},
    {0, 0, 0, 0, 0},
    {0, 0, 0, 0, 0},
  };

  cracking::arraysAndStrings::zeroMatrix_2(aMatrix, 6, 5);
  EXPECT_TRUE(helper::compareMatrix(aMatrix, 6, 5,
                                    aExpectedMatrix, 6, 5));
}

TEST(StringRotationTest, StringRotationTest_basic_1) {
  std::string str_1 = "erbottlewat";
  std::string str_2 = "waterbottle";
  EXPECT_TRUE(cracking::arraysAndStrings::isStringRotation(str_1, str_2));
  EXPECT_TRUE(cracking::arraysAndStrings::isStringRotation_2(str_1, str_2));
}

TEST(StringRotationTest, StringRotationTest_basic_2) {
  std::string str_1 = "racecar";
  std::string str_2 = "racecar";
  EXPECT_TRUE(cracking::arraysAndStrings::isStringRotation(str_1, str_2));
  EXPECT_TRUE(cracking::arraysAndStrings::isStringRotation_2(str_1, str_2));
}

TEST(StringRotationTest, StringRotationTest_basic_3) {
  std::string str_1 = "";
  std::string str_2 = "";
  EXPECT_TRUE(cracking::arraysAndStrings::isStringRotation(str_1, str_2));
  EXPECT_TRUE(cracking::arraysAndStrings::isStringRotation_2(str_1, str_2));
}

TEST(StringRotationTest, StringRotationTest_basic_4) {
  std::string str_1 = "a";
  std::string str_2 = "a";
  EXPECT_TRUE(cracking::arraysAndStrings::isStringRotation(str_1, str_2));
  EXPECT_TRUE(cracking::arraysAndStrings::isStringRotation_2(str_1, str_2));
}

TEST(StringRotationTest, StringRotationTest_basic_5) {
  std::string str_1 = "abcd";
  std::string str_2 = "adcb";
  EXPECT_FALSE(cracking::arraysAndStrings::isStringRotation(str_1, str_2));
  EXPECT_FALSE(cracking::arraysAndStrings::isStringRotation_2(str_1, str_2));
}

TEST(LastKLinesTesst, LastKLines_moreThanK) {
  const std::string aFilePath = "./crackingTestInputs/cAndCpp/lastKLines/lastKLines_moreThanK.txt";
  const int K = 3;
  std::vector<std::string> aOutput = cracking::cAndCpp::printLastKLines(aFilePath, K);

  std::vector<std::string> aExpectedOutput;
  aExpectedOutput.push_back("\"Line 5 -- Neque porro quisquam est qui dolorem ipsum quia dolor sit amet, consectetur, adipisci velit...\"");
  aExpectedOutput.push_back("\"Line 6 -- Neque porro quisquam est qui dolorem ipsum quia dolor sit amet, consectetur, adipisci velit...\"");
  aExpectedOutput.push_back("\"Line 7 -- Neque porro quisquam est qui dolorem ipsum quia dolor sit amet, consectetur, adipisci velit...\"");
  EXPECT_TRUE(helper::compareArray(aOutput, aExpectedOutput));
}

TEST(LastKLinesTesst, LastKLines_lessThanK) {
  const std::string aFilePath = "./crackingTestInputs/cAndCpp/lastKLines/lastKLines_lessThanK.txt";
  const int K = 3;
  std::vector<std::string> aOutput = cracking::cAndCpp::printLastKLines(aFilePath, K);

  std::vector<std::string> aExpectedOutput;
  aExpectedOutput.push_back("\"Line 1 -- Neque porro quisquam est qui dolorem ipsum quia dolor sit amet, consectetur, adipisci velit...\"");
  aExpectedOutput.push_back("\"Line 2 -- Neque porro quisquam est qui dolorem ipsum quia dolor sit amet, consectetur, adipisci velit...\"");
  EXPECT_TRUE(helper::compareArray(aOutput, aExpectedOutput));
}

TEST(LastKLinesTesst, LastKLines_nothing) {
  const std::string aFilePath = "./crackingTestInputs/cAndCpp/lastKLines/lastKLines_nothing.txt";
  const int K = 3;
  std::vector<std::string> aOutput = cracking::cAndCpp::printLastKLines(aFilePath, K);
  EXPECT_EQ(aOutput.size(), 0);
}

TEST(ReverseStringTest, ReverseStringTest_nullPointer) {
  char* aStr = NULL;
  cracking::cAndCpp::reverseString(aStr);
}

TEST(ReverseStringTest, ReverseStringTest_lengthOdd) {
  // https://stackoverflow.com/questions/4083239/proper-way-to-initialize-a-string-in-c
  char aStr[] = "PokeMon";
  cracking::cAndCpp::reverseString(aStr);
  std::string aOutputStr(aStr);
  EXPECT_EQ(aOutputStr, "noMekoP");
}

TEST(ReverseStringTest, ReverseStringTest_lengthEven) {
  char aStr[] = "PokeMo";
  cracking::cAndCpp::reverseString(aStr);
  std::string aOutputStr(aStr);
  EXPECT_EQ(aOutputStr, "oMekoP");
}

TEST(ReverseStringTest, ReverseStringTest_lengthZero) {
  char aStr[] = "";
  cracking::cAndCpp::reverseString(aStr);
  std::string aOutputStr(aStr);
  EXPECT_EQ(aOutputStr, "");
}

TEST(ReverseStringTest, ReverseStringTest_lengthOne) {
  char aStr[] = "P";
  cracking::cAndCpp::reverseString(aStr);
  std::string aOutputStr(aStr);
  EXPECT_EQ(aOutputStr, "P");
}

TEST(CopyNodeTest, CopyNodeTest_basic) {
  cracking::cAndCpp::copyNodeHelper::Node node_1(1);
  cracking::cAndCpp::copyNodeHelper::Node node_2(20);
  cracking::cAndCpp::copyNodeHelper::Node node_3(300);
  cracking::cAndCpp::copyNodeHelper::Node node_4(4000);
  node_1._ptr1 = &node_4;
  node_1._ptr2 = &node_2;
  node_2._ptr2 = &node_3;
  node_3._ptr2 = &node_1;
  cracking::cAndCpp::copyNodeHelper::Node* root = &node_1;
  cracking::cAndCpp::copyNodeHelper::Node* aCopy = cracking::cAndCpp::copyNode(root);
  // std::cout << "HELLO aCopy." << aCopy->value << std::endl;
  // std::cout << "HELLO aCopy." << aCopy->_ptr2->value << std::endl;
  // std::cout << "HELLO aCopy._ptr2@ << " << aCopy->_ptr2 << std::endl;
  // std::cout << "HELLO node_2@ << " << &node_2 << std::endl;
  // std::cout << "HELLO aCopy." << aCopy->_ptr2->_ptr2->value << std::endl;
  EXPECT_EQ(aCopy->value, 1);
  EXPECT_EQ(aCopy->_ptr1->value, 4000);
  EXPECT_EQ(aCopy->_ptr2->value, 20);
  EXPECT_FALSE(aCopy->_ptr2 == &node_2);
  EXPECT_EQ(aCopy->_ptr2->_ptr2->value, 300);
  EXPECT_FALSE(aCopy->_ptr2->_ptr2 == &node_3);
}

//on MacOS: test for leak: leaks -atExit -- ./build/HelloWorld | grep LEAK:
TEST(SmartPointerTest, SmartPointerTest_basic) {
  // std::shared_ptr<int> aPtr(new int(3));
  cracking::cAndCpp::Pointer<int> aPtr1(new int(10));
  EXPECT_EQ(*aPtr1._ptr, 10);
  cracking::cAndCpp::Pointer<int> aPtr2(aPtr1);
  EXPECT_EQ(*aPtr2._ptr, 10);
  cracking::cAndCpp::Pointer<int> aPtr3(aPtr2);
  EXPECT_EQ(*aPtr3._ptr, 10);
  cracking::cAndCpp::Pointer<int> aPtr4(aPtr3);
  EXPECT_EQ(*aPtr4._ptr, 10);
  cracking::cAndCpp::Pointer<int> aPtr5 = aPtr1;
  EXPECT_EQ(*aPtr5._ptr, 10);
  {
    cracking::cAndCpp::Pointer<int> aPtr6(new int(60));
    EXPECT_EQ(*aPtr6._ptr, 60);
    aPtr5 = aPtr6;
    EXPECT_EQ(*aPtr5._ptr, 60);
  }
  EXPECT_EQ(*aPtr5._ptr, 60);
}

TEST(SmartPointerTest, SmartPointerTest_copyIntoTheOnlyRef_shouldNotLeak) {
  cracking::cAndCpp::Pointer<int> aPtr1(new int(10));
  cracking::cAndCpp::Pointer<int> aPtr6(new int(60));
  EXPECT_EQ(*aPtr6._ptr, 60);
  aPtr1 = aPtr6;
  EXPECT_EQ(*aPtr1._ptr, 60);
}

TEST(SmartPointerTest, SmartPointerTest_sourcePtrOutOfScope_shouldBeValid) {
  cracking::cAndCpp::Pointer<int> aPtr1(new int(10));
  {
    cracking::cAndCpp::Pointer<int> aPtr6(new int(60));
    EXPECT_EQ(*aPtr6._ptr, 60);
    aPtr1 = aPtr6;
  }
  EXPECT_EQ(*aPtr1._ptr, 60);
}

TEST(SmartPointerTest, SmartPointerTest_assignToUnInitPtr_shouldBeValid_shouldNotLeak) {
  cracking::cAndCpp::Pointer<int> aPtr1;
  {
    cracking::cAndCpp::Pointer<int> aPtr6(new int(60));
    EXPECT_EQ(*aPtr6._ptr, 60);
    aPtr1 = aPtr6;
  }
  EXPECT_EQ(*aPtr1._ptr, 60);
}

TEST(SmartPointerTest, SmartPointerTest_selfAssign) {
  cracking::cAndCpp::Pointer<int> aPtr6(new int(60));
  EXPECT_EQ(*aPtr6._ptr, 60);
  aPtr6 = aPtr6;
  EXPECT_EQ(*aPtr6._ptr, 60);
}