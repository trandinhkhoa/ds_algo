#include "lastKLines.h"
#include <iostream>
#include <vector>
#include <queue>
#include <deque>
#include <fstream>

namespace {

unsigned int countNumberOfLines(std::ifstream& iFile) {
  std::string aLine;
  unsigned int aLinesCount = 0;
  while (std::getline(iFile, aLine)) {
    aLinesCount++;
  }
  return aLinesCount;
}

}

/****
  STUPID
****/
std::vector<std::string> cracking::cAndCpp::printLastKLines_Stupid(const std::string& iFilePath, const int& K) {
  std::ifstream aFile;
  std::vector<std::string> aOutput;

  aFile.open(iFilePath);
  if (!aFile.is_open()) {
    std::cout << "Cannot open file " << iFilePath << std::endl;
    return aOutput;
  }

  unsigned int aLinesCount = countNumberOfLines(aFile);

  // reset
  aFile.clear();
  aFile.seekg(0);

  if (!aFile.is_open()) {
    std::cout << "Something is wrong. The file is supposed to be still open" << std::endl;
    return aOutput;
  }

  unsigned int aCurrentLine = 1;
  std::string aLine;
  while (std::getline(aFile, aLine)) {
    if ((aCurrentLine > aLinesCount - K) || (aLinesCount < K)){
      aOutput.push_back(aLine);
    }
    aCurrentLine++;
  }

  return aOutput;
}

/****
  QUEUE
****/
std::vector<std::string> cracking::cAndCpp::printLastKLines_usingQueue(const std::string& iFilePath, const int& K) {
  std::ifstream aFile;
  std::vector<std::string> aOutput;

  aFile.open(iFilePath);
  if (!aFile.is_open()) {
    std::cout << "Cannot open file " << iFilePath << std::endl;
    return aOutput;
  }

  std::string aLine;
  std::queue<std::string> aKLines;
  while (std::getline(aFile, aLine)) {
    if (aKLines.size() >= K) {
      aKLines.pop();
    }
    aKLines.push(aLine);
  }

  while (!aKLines.empty())
  {
    aOutput.push_back(aKLines.front());
    aKLines.pop();
  }

  return aOutput;
}

// /****
//   DEQUEUE
// ****/
std::vector<std::string> cracking::cAndCpp::printLastKLines_usingDeque(const std::string& iFilePath, const int& K) {
  std::ifstream aFile;
  std::vector<std::string> aOutput;

  aFile.open(iFilePath);
  if (!aFile.is_open()) {
    std::cout << "Cannot open file " << iFilePath << std::endl;
    return aOutput;
  }

  std::string aLine;
  std::deque<std::string> aKLines;
  while (std::getline(aFile, aLine)) {
    if (aKLines.size() >= K) {
      aKLines.pop_front();
    }
    aKLines.push_back(aLine);
  }

  int aSize = aKLines.size();
  for (int i = 0; i < aSize; i++)
  {
    aOutput.push_back(aKLines[i]);
  }

  return aOutput;
}

// /****
//  Use CIRCULAR ARRAY
// ****/
namespace {

template<class T>
class CircularArray {
  unsigned int begin;
  unsigned int maxSize;
public:
  std::vector<T> vector;

  CircularArray(unsigned int iSize) : maxSize(iSize), begin(0) {}

  unsigned int getBegin() {
    return this->begin;
  }

  void push(T aElem) {
    if (this->vector.size() == this->maxSize) {
      this->vector[begin] = aElem;
      begin = (begin + 1) % this->maxSize ;
    } else {
      this->vector.push_back(aElem);
    }
  }

};

}

std::vector<std::string> cracking::cAndCpp::printLastKLines(const std::string& iFilePath, const int& K) {
  std::ifstream aFile;
  std::vector<std::string> aOutput;

  aFile.open(iFilePath);
  if (!aFile.is_open()) {
    std::cout << "Cannot open file " << iFilePath << std::endl;
    return aOutput;
  }

  std::string aLine;
  CircularArray<std::string> aCircularArray(K);
  while (std::getline(aFile, aLine)) {
    aCircularArray.push(aLine);
  }


  unsigned int index = aCircularArray.getBegin();
  for (int i = 0; i < aCircularArray.vector.size(); i++)
  {
    aOutput.push_back(aCircularArray.vector[index]);
    index++;
    if (index >= aCircularArray.vector.size()) {
      index = 0;
    }
  }

  return aOutput;
}