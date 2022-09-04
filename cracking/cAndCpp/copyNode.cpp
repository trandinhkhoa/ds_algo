#include "copyNode.h"
#include <iostream>
#include <map>


cracking::cAndCpp::copyNodeHelper::Node::Node(int x, Node* ptr1, Node* ptr2) : value(x), _ptr1(ptr1), _ptr2(ptr2) {}

namespace {
// void recurse(const cracking::cAndCpp::copyNodeHelper::Node* iNodePtr,
cracking::cAndCpp::copyNodeHelper::Node* recurse(cracking::cAndCpp::copyNodeHelper::Node* iNodePtr,
            std::map<cracking::cAndCpp::copyNodeHelper::Node*, bool>& iAddressMap) {
  iAddressMap.insert(std::make_pair(iNodePtr, true));

  if ((iNodePtr->_ptr1 == nullptr || (iAddressMap.find(iNodePtr->_ptr1) != iAddressMap.end())) &&
      (iNodePtr->_ptr2 == nullptr || (iAddressMap.find(iNodePtr->_ptr2) != iAddressMap.end()))) {
        std::cout << "dead end" << std::endl;
        cracking::cAndCpp::copyNodeHelper::Node* newNode = new cracking::cAndCpp::copyNodeHelper::Node(0);
        newNode->value = iNodePtr->value;
        newNode->_ptr1 = iNodePtr->_ptr1;
        newNode->_ptr2 = iNodePtr->_ptr2;
        return newNode;
  }

  cracking::cAndCpp::copyNodeHelper::Node* newNode_1;
  if (!(iNodePtr->_ptr1 == nullptr || (iAddressMap.find(iNodePtr->_ptr1) != iAddressMap.end()))) {
    newNode_1 = recurse(iNodePtr->_ptr1, iAddressMap);
  }
  cracking::cAndCpp::copyNodeHelper::Node* newNode_2;
  if (!(iNodePtr->_ptr2 == nullptr || (iAddressMap.find(iNodePtr->_ptr2) != iAddressMap.end()))) {
    newNode_2 = recurse(iNodePtr->_ptr2, iAddressMap);
  }

  cracking::cAndCpp::copyNodeHelper::Node* newNode = new cracking::cAndCpp::copyNodeHelper::Node(0);
  newNode->value = iNodePtr->value;
  newNode->_ptr1 = newNode_1;
  newNode->_ptr2 = newNode_2;
  return newNode;
}

}

// Make a complete copy of the whole structure
cracking::cAndCpp::copyNodeHelper::Node* cracking::cAndCpp::copyNode(copyNodeHelper::Node* root) {
  std::map<cracking::cAndCpp::copyNodeHelper::Node*, bool> aAddressMap;
  cracking::cAndCpp::copyNodeHelper::Node* aCopy;
  aCopy = recurse(root, aAddressMap);

  return aCopy;
}