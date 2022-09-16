#include <iostream>

namespace dataStructures {

// a,b,c => 1 -> 2 -> 3
// Cons:
// if c change the head (adding 0 -> 1), then a,b will still refer to the old head
// Solution: a,b,c should refer to the list, not the head
// a,b,c => (1 -> 2 -> 3)

// what should `head` be in default constructor ?
// head should be a pointer, otherwise I cant know whether a valid head exist
template<class T>
class LinkedList {
public:
  class WrappedNode {
  public:
    T value;
    WrappedNode* next;
    WrappedNode() = default;
    WrappedNode(T iValue) {
      value = iValue;
      next = nullptr;
    }
  };

  WrappedNode* begin() {
    return head;
  };

  void append(T iValue) {
    if (!head) {
      head = new WrappedNode(iValue);
    } else {
      WrappedNode* last = head;
      while (last->next) {
        last = last->next;
      }
      last->next = new WrappedNode(iValue);
    }
  }

  ~LinkedList() {
    WrappedNode* iter = head;
    while (iter)
    {
      WrappedNode* tmp = iter;
      tmp = tmp->next;
      delete iter;
      iter = tmp;
    }

    head = nullptr;
  }

private:
  WrappedNode* head = nullptr;
};

}