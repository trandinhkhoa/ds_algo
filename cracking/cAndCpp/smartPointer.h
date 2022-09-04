// // Focus on the concept firsts, then worry about the exact implementation. How should SmartPointer look?
// // Think about tracking the number of references. What will this tell us?
// // What are all the different methods/operators we might want to override?

namespace cracking {

namespace cAndCpp {

template<class T>
class Pointer {
  unsigned int* _countPtr;
public:
  T* _ptr;

  Pointer() {
    _countPtr = new unsigned int(0);
    _ptr = nullptr;
  }

  Pointer(T* iPtr) {
    _ptr = iPtr;
    _countPtr = new unsigned int(1);
  }

  Pointer(Pointer& iPtr) {
    _countPtr = iPtr._countPtr;
    _ptr = iPtr._ptr;
    (*_countPtr)++;
  }

  Pointer& operator=(const Pointer& iPtr) {
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

  ~Pointer() {
    if (*_countPtr > 0) {
      (*_countPtr)--;
    }

    if (*_countPtr == 0) {
      free(_ptr);
      free(_countPtr);
    }
  }
};

}

}