namespace cracking {

namespace cAndCpp {

class Pointer {
  unsigned int* _countPtr;
public:
  int* _ptr;
  Pointer();
  Pointer(int* iPtr);
  Pointer(Pointer& iPtr);
  Pointer& operator=(const Pointer& iPtr);
  ~Pointer();
};

// void smartPointer();

}

}