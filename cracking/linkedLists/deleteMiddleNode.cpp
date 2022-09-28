#include "deleteMiddleNode.h"
#include <iostream>

void cracking::linkedLists::deleteMiddleNode(cracking::linkedLists::deleteMiddleNodeHelper::Node* iToBeDeleted) {
  cracking::linkedLists::deleteMiddleNodeHelper::Node* aCopyPtr = iToBeDeleted->next;
  iToBeDeleted->data = iToBeDeleted->next->data;
  iToBeDeleted->next = iToBeDeleted->next->next;
  free(aCopyPtr);
}