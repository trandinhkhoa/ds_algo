#include "loopDetection.h"
#include <iostream>

namespace cracking {
namespace linkedLists {

dataStructures::SinglyLinkedListNode* loopDetection(dataStructures::SinglyLinkedListNode& aHead) {
  dataStructures::SinglyLinkedListNode* aIter = &aHead;

  dataStructures::SinglyLinkedListNode* aSlow = &aHead;
  dataStructures::SinglyLinkedListNode* aFast = &aHead;
  dataStructures::SinglyLinkedListNode* aLoopStart = nullptr;
  while (true) {
    aSlow = aSlow->next;

    if (aFast->next != nullptr) {
      aFast = aFast->next;
    } else {
      break;
    }
    if (aFast->next != nullptr) {
      aFast = aFast->next;
    } else {
      break;
    }

    if (aSlow == aFast) {
      dataStructures::SinglyLinkedListNode* aCollisionPoint = aSlow;
      dataStructures::SinglyLinkedListNode* aIter_1 = &aHead;
      dataStructures::SinglyLinkedListNode* aIter_2 = aCollisionPoint;

      while (aIter_1 != aIter_2) {
        aIter_1 = aIter_1->next;
        aIter_2 = aIter_2->next;
      }
      aLoopStart = aIter_1;
      break;
    }
  }

  return aLoopStart;
}

}
}