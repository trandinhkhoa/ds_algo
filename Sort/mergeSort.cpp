#include "bubbleSort.h"
#include <iostream>

void merge(std::vector<int>& array, int begin, int middle, int end) {
  std::vector<int> temp;

  int i = begin;
  int j = middle + 1;

  while ((i <= middle) && (j <= end)) {
    if (array[i] > array[j]) {
      temp.push_back(array[j]);
      j++;
    } else {
      temp.push_back(array[i]);
      i++;
    }
  }

  // TODO: maybe this copy paste can be done in a smarter way ??
  if (i > middle) {
    // copy paste rest of right array
    for (int k = j; k <= end; k++) {
      temp.push_back(array[k]);
    }
  }
  else {
    // copy paste rest of left array
    for (int k = i; k <= middle; k++) {
      temp.push_back(array[k]);
    }
  }

  // copy paste temp into array
  int h = 0;
  for (int k = begin; k <= end; k++) {
    array[k] = temp[h];
    h++;
  }
}

void mergeSortHelper(std::vector<int>& array, int begin, int end) {
  if (begin >= end) {
    return;
  }
  int middle = (begin + end) / 2;
  mergeSortHelper(array, begin, middle);
  mergeSortHelper(array, middle + 1, end);

  merge(array, begin, middle, end);
}

// TODO: put mergeSort, bubbleSort, etc. in a namespace to not be confused with the one from stdlib.h
void mergeSort(std::vector<int>& array) {
  mergeSortHelper(array, 0, array.size() - 1);
}