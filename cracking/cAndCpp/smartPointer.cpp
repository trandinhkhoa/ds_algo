#include "smartPointer.h"
#include <iostream>

// Focus on the concept firsts, then worry about the exact implementation. How should SmartPointer look?
// Think about tracking the number of references. What will this tell us?
// What are all the different methods/operators we might want to override?

// unsigned int cracking::cAndCpp::Pointer::count = 0;
cracking::cAndCpp::Pointer::Pointer() {
  _countPtr = new unsigned int(0);
  _ptr = nullptr;
}

// Note?: int* ptr; what is ptr++
cracking::cAndCpp::Pointer::Pointer(int* iPtr) : _ptr(iPtr) {
  _countPtr = new unsigned int(1);
}

cracking::cAndCpp::Pointer::Pointer(Pointer& iPtr) {
  _countPtr = iPtr._countPtr;
  _ptr = iPtr._ptr;
  (*_countPtr)++;
}

cracking::cAndCpp::Pointer::~Pointer() {
  if (*_countPtr > 0) {
    (*_countPtr)--;
  }

  if (*_countPtr == 0) {
    free(_ptr);
    free(_countPtr);
  }
}

cracking::cAndCpp::Pointer& cracking::cAndCpp::Pointer::operator=(const Pointer& iPtr) {
  if (this == &iPtr) {
    return *this;
  }

  if (*_countPtr > 0) {
    (*_countPtr)--;
  }

  if (*_countPtr == 0) {
    free(_ptr);
    free(_countPtr);
  }

  _ptr = iPtr._ptr;
  _countPtr = iPtr._countPtr;
  (*_countPtr)++;
  return *this;
}