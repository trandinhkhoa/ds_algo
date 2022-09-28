#include <list>

namespace cracking {
namespace linkedLists {

namespace deleteMiddleNodeHelper {

// use my own LinkedList implem because std::list does not allow changing of pointer to the `next` elem
class Node {
public:
int data;
Node* next;
Node(int iData): data(iData) {
  next = nullptr;
};
void append(int iData) {
  Node* aPtr = this;
  while (aPtr->next) {
    aPtr = aPtr->next;
  }
  aPtr->next = new Node(iData);
}

~Node(){
  if (this->next) {
    delete this->next;
  }
}

};

}

void deleteMiddleNode(cracking::linkedLists::deleteMiddleNodeHelper::Node* iToBeDeleted);

}
}