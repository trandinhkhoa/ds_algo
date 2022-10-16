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

FixedMultiStack threeInOneFixed(int iMaxSize) {
  FixedMultiStack aMultiStack = FixedMultiStack(iMaxSize);

  return aMultiStack;
}

class MultiStack {
public:
  int aNumber;
  std::vector<int> aArray;
  class Stack {
  public:
    int aStackPointer;
    int aStackOrigin;
    int aMaxSize;
    int aSize;
    Stack(int iStackOrigin, int iMaxSize) {
      aStackOrigin = iStackOrigin;
      aStackPointer = aStackOrigin - 1;
      aMaxSize = iMaxSize;
      aSize = 0;
    }
    void push(MultiStack* p, int iValue) {
      // aStackPointer++;
      aStackPointer = p->circularAdd(aStackPointer, 1, p->aMaxSize);
      p->aArray[aStackPointer] = iValue;
      aSize++;
    }
    int pop(MultiStack* p) {
      int returnValue = p->aArray[aStackPointer];
      p->aArray[aStackPointer] = -1;
      // aStackPointer--;
      aStackPointer = p->circularSubtract(aStackPointer, 1, p->aMaxSize);

      aSize--;
      return returnValue;
    }
    int getStackPointer() {
      return aStackPointer;
    }
    int isEmpty() {
      return (aSize == 0);
    }
    int isFull() {
      return (getSize() >= aMaxSize);
    }
    int getSize() {
      return aSize;
    }
    void print(MultiStack* p) {
      for (int i = aStackOrigin; i < aStackPointer; i++) {
        std::cout << p->aArray[i] << "\t|";
      }
      std::cout << std::endl;
    }
  };
  std::vector<Stack> aStackArray;
  int aMaxSize;
  const int STACK_COUNT = 3;

  MultiStack(int size) {
    aMaxSize = size;
    aArray.reserve(aMaxSize);
    aArray.resize(aMaxSize, -1);
    Stack aStack_0(0, aMaxSize/3);
    Stack aStack_1(aMaxSize/3, aMaxSize/3);
    Stack aStack_2(2*aMaxSize/3, aMaxSize - 2*(aMaxSize/3));
    aStackArray.push_back(aStack_0);
    aStackArray.push_back(aStack_1);
    aStackArray.push_back(aStack_2);

  }

  bool isFull() {
    int aRealSize = aStackArray[0].getSize() + aStackArray[1].getSize() + aStackArray[2].getSize();
    if (aRealSize == aMaxSize) {
      return true;
    }
    return false;
  }

  int circularSubtract(int iX, int iY, int iMax) {
    return (iX - iY) < 0 ? ((iMax - 1) - (-(iX - iY)) + 1) : iX - iY;
  }

  int circularAdd(int iX, int iY, int iMax) {
    return (iX + iY) > iMax - 1 ? ((iX + iY) - (iMax - 1) - 1) : iX + iY;
  }

  void shiftBackward(int iStackId) {

    int aIndex = aStackArray[iStackId].aStackOrigin;
    int aCount = 0;
    while (aCount < aStackArray[iStackId].getSize()) {
      int aPreviousIndex = circularSubtract(aIndex, 1, aMaxSize);
      aArray[aPreviousIndex] = aArray[aIndex];
      aIndex = circularAdd(aIndex, 1, aMaxSize);
      aCount++;
    }
    aStackArray[iStackId].aStackOrigin = circularSubtract(aStackArray[iStackId].aStackOrigin, 1, aMaxSize);
    aStackArray[iStackId].aStackPointer = circularSubtract(aStackArray[iStackId].aStackPointer, 1, aMaxSize);
  }

  void shiftForward(int iStackId) {
    bool aNeedToShrink = false;
    if (aStackArray[iStackId].isFull()) {
      shiftForward(circularAdd(iStackId, 1, STACK_COUNT));
    } else {
      aNeedToShrink = true;
    }

    int aIndex = aStackArray[iStackId].aStackPointer;
    int aCount = 0;
    while (aCount < aStackArray[iStackId].getSize()) {
      int aNextIndex = circularAdd(aIndex, 1, aMaxSize);
      aArray[aNextIndex] = aArray[aIndex];
      aIndex = circularSubtract(aIndex, 1, aMaxSize);
      aCount++;
    }

    aStackArray[iStackId].aStackOrigin = circularAdd(aStackArray[iStackId].aStackOrigin, 1, aMaxSize);
    aStackArray[iStackId].aStackPointer = circularAdd(aStackArray[iStackId].aStackPointer, 1, aMaxSize);
    if (aNeedToShrink) {
      aStackArray[iStackId].aMaxSize--;
    }
  }

  void expand(int iStackId) {
    int aPreviousStackId = circularSubtract(iStackId, 1, STACK_COUNT);
    int aNextStackId = circularAdd(iStackId, 1, STACK_COUNT);
    if (aStackArray[aNextStackId].isEmpty()) {
      shiftForward(aNextStackId);
      aStackArray[iStackId].aMaxSize++;
    } else if (!aStackArray[aPreviousStackId].isFull()) {
      shiftBackward(iStackId);
      aStackArray[aPreviousStackId].aMaxSize--;
      aStackArray[iStackId].aMaxSize++;
    } else {
      shiftForward(aNextStackId);
      aStackArray[iStackId].aMaxSize++;
    }
  }

  void push(int iStackId, int iValue) {
    if (isFull()) {
      throw std::runtime_error("Stack Full");
    } else if (aStackArray[iStackId].isFull()) {
      expand(iStackId);
    }
    aStackArray[iStackId].push(this, iValue);
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

MultiStack threeInOne(int iMaxSize) {
  MultiStack aMultiStack = MultiStack(iMaxSize);

  return aMultiStack;
}
}
}
