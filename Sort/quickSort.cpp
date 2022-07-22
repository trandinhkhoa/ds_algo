#include "sort.h"

namespace {
void swap(int& a, int& b) {
  int temp = a;
  a = b;
  b = temp;
}
}

void quickSort(std::vector<int>& array, int begin, int end) {
  if (begin >= end) {
    return;
  }

  int i = begin - 1;
  // TODO: improve choice of pivot
  int pivot = end;
  for (int j = begin; j <= end; j++) {
    if (array[j] < array[pivot]) {
      i++;
      swap(array[i], array[j]);
    }
  }

  swap(array[i + 1], array[pivot]);
  pivot = i + 1;

  quickSort(array, begin, pivot - 1);
  quickSort(array, pivot + 1, end);
}
