#include <iostream>
#include <array>
#include <vector>

namespace cracking {
namespace stacksAndQueues {

class FixedMultiStack {
public:
  int aNumber;
  std::vector<int> aArray;
  class Stack {
  public:
    int aStackPointer;
    int aStackOrigin;
    int aMaxSize;
    Stack(int iStackOrigin, int iMaxSize) {
      aStackOrigin = iStackOrigin;
      aStackPointer = aStackOrigin - 1;
      aMaxSize = iMaxSize;
    }
    void push(FixedMultiStack* p, int iValue) {
      aStackPointer++;
      p->aArray[aStackPointer] = iValue;
    }
    int pop(FixedMultiStack* p) {
      int returnValue = p->aArray[aStackPointer];
      p->aArray[aStackPointer] = -1;
      aStackPointer--;
      return returnValue;
    }
    int getStackPointer() {
      return aStackPointer;
    }
    int isEmpty() {
      return (aStackPointer - aStackOrigin < 0);
    }
    int isFull() {
      return (aStackPointer - aStackOrigin + 1 >= aMaxSize);
    }
    void print(FixedMultiStack* p) {
      for (int i = aStackOrigin; i < aStackPointer; i++) {
        std::cout << p->aArray[i] << "\t|";
      }
      std::cout << std::endl;
    }
  };
  std::vector<Stack> aStackArray;
  FixedMultiStack(int size) {
    aArray.reserve(size);
    aArray.resize(size, -1);
    Stack aStack_0(0, size/3);
    Stack aStack_1(size/3, size/3);
    Stack aStack_2(2*size/3, size - 2*(size/3));
    aStackArray.push_back(aStack_0);
    aStackArray.push_back(aStack_1);
    aStackArray.push_back(aStack_2);
  }
  void push(int iStackId, int iValue) {
    if (aStackArray[iStackId].isFull()) {
      throw std::runtime_error("Mini Stack Full");
    } else {
      aStackArray[iStackId].push(this, iValue);
    }
  }

  int pop(int iStackId) {
    if (aStackArray[iStackId].isEmpty()) {
      throw std::runtime_error("Mini Stack Empty");
    } else {
      return aStackArray[iStackId].pop(this);
    }
  }

  void print(int iStackId) {
    aStackArray[iStackId].print(this);
  }

  void printAll() {
    for (int i = 0; i < aArray.size(); i++) {
      if (aArray[i] == -1) {
        std::cout << "-";
      } else {
        std::cout << aArray[i];
      }
      if (((i+1) == aStackArray[0].aStackOrigin) || ((i+1) == aStackArray[1].aStackOrigin) || ((i+1) == aStackArray[2].aStackOrigin)) {
        std::cout << "|||";
      } else {
        std::cout << "|";
      }
    }
    std::cout << std::endl;
  }
};

template<std::size_t SIZE>
FixedMultiStack threeInOneFixed(std::array<int, SIZE>& iArray) {
  FixedMultiStack aMultiStack = FixedMultiStack(10);

  return aMultiStack;
}

}
}
