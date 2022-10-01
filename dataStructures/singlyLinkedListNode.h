#ifndef SINGLY_LINKED_LIST_NODE_H
#define SINGLY_LINKED_LIST_NODE_H

#include <iostream>

namespace dataStructures {

// TODO: work with <T> instead of <int>
class SinglyLinkedListNode {
public:
int data;
SinglyLinkedListNode* next;
SinglyLinkedListNode(int iData): data(iData) {
  next = nullptr;
};
SinglyLinkedListNode(std::initializer_list<int> iList) {
  next = nullptr;
  std::initializer_list<int>::iterator aIter = iList.begin();
  bool aFirst = true;
  SinglyLinkedListNode* aPtr;
  while (aIter != iList.end()) {
    if (aFirst) {
      this->data = *aIter;
      this->next = nullptr;
      aPtr = this;
      aFirst = false;
    } else {
      aPtr->next = new SinglyLinkedListNode(*aIter);
      aPtr = aPtr->next;
    }
    aIter++;
  }
};
void append(int iData) {
  SinglyLinkedListNode* aPtr = this;
  while (aPtr->next) {
    aPtr = aPtr->next;
  }
  aPtr->next = new SinglyLinkedListNode(iData);
}

void printList(){
  SinglyLinkedListNode* aIter = this;
  while (aIter) {
    std::cout << aIter->data << "\t";
    aIter = aIter->next;
  }
  std::cout << std::endl;
}

~SinglyLinkedListNode(){
  if (this->next) {
    delete this->next;
  }
}

};

}

#endif