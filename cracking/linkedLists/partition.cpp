#include "partition.h"
#include <list>
#include <iostream>

namespace cracking {
namespace linkedLists {

dataStructures::SinglyLinkedListNode* partition(dataStructures::SinglyLinkedListNode* aHeadPtr, const unsigned int& iPartitionValue) {
  dataStructures::SinglyLinkedListNode* aPartition_1 = nullptr;
  dataStructures::SinglyLinkedListNode* aPartition_1_Iter = nullptr;
  dataStructures::SinglyLinkedListNode* aPartition_2 = nullptr;
  dataStructures::SinglyLinkedListNode* aPartition_2_Iter = nullptr;
  dataStructures::SinglyLinkedListNode* aIter = aHeadPtr;
  while (aIter) {
    if (aIter->data >= iPartitionValue) {
      if (!aPartition_2) {
        aPartition_2 = aIter;
        aPartition_2_Iter = aIter;
      } else {
        aPartition_2_Iter->next = aIter;
        aPartition_2_Iter = aPartition_2_Iter->next;
      }
    } else {
      if (!aPartition_1) {
        aPartition_1 = aIter;
        aPartition_1_Iter = aIter;
      } else {
        aPartition_1_Iter->next = aIter;
        aPartition_1_Iter = aPartition_1_Iter->next;
      }
    }
    aIter = aIter->next;
  }

  aPartition_2_Iter->next = nullptr;
  if (!aPartition_1) {
    return aPartition_2;
  }

  aPartition_1_Iter->next = aPartition_2;
  return aPartition_1;
}

}
}