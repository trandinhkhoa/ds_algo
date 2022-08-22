#include "rotateMatrix.h"
#include <vector>
#include <iostream>

namespace {

class Coordinate {
public:
  int y;
  int x;

  Coordinate(int iy,int ix){
    y = iy;
    x = ix;
  };

  void moveRight() {
    x++;
  }
  void moveLeft() {
    x--;
  }
  void moveUp() {
    y--;
  }
  void moveDown() {
    y++;
  }
};

}

void cracking::arraysAndStrings::rotateMatrix(std::vector<std::vector<uint32_t>>& iMatrix) {

  uint16_t N = iMatrix.size();
  int iter = 0;
  for (int iter = 0; iter < (N/2); iter++) {
    Coordinate topLeft(iter, iter);
    Coordinate topRight(iter, N-1-iter);
    Coordinate bottomRight(N-1-iter, N-1-iter);
    Coordinate bottomLeft(N-1-iter, iter);

    for (int i = iter; i < N - 1 - iter; i++ ) {
      uint32_t temp = iMatrix[topLeft.y][topLeft.x];
      iMatrix[topLeft.y][topLeft.x] = iMatrix[bottomLeft.y][bottomLeft.x];
      iMatrix[bottomLeft.y][bottomLeft.x] = iMatrix[bottomRight.y][bottomRight.x];
      iMatrix[bottomRight.y][bottomRight.x] = iMatrix[topRight.y][topRight.x];
      iMatrix[topRight.y][topRight.x] = temp;

      topLeft.moveRight();
      topRight.moveDown();
      bottomRight.moveLeft();
      bottomLeft.moveUp();
    }
  }

}
