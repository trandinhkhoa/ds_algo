#include "sort.h"
#include <iostream>

void swap(int& a, int &b) {
  int temp = a;
  a = b;
  b = temp;
}

void bubbleSort(std::vector<int>& array) {
  for (int iteration = 0; iteration < array.size() - 1; iteration++) {
    for (int j = 0; j < array.size() - 1 - iteration; j++) {
      if (array[j] > array[j+1]) {
        swap(array[j], array[j+1]);
      }
    }
  }
}