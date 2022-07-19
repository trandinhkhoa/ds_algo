#include <iostream>
#include <gtest/gtest.h>
#include "adder.h"
#include "bubbleSort.h"

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
  std::vector<int> array(helper::generateArray(10));
  bubbleSort(array);
  helper::printArray(array);
  EXPECT_TRUE(helper::isArraySortedAscending(array));
}