#include "zeroMatrix.h"
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

void setRowZero(std::vector<std::vector<uint32_t>>& iMatrix, unsigned int row, unsigned int width) {
  for (int i = 0; i < width; i++) {
    iMatrix[row][i] = 0;
  }
}

void setColumnZero(std::vector<std::vector<uint32_t>>& iMatrix, unsigned int column, unsigned int height) {
  for (int i = 0; i < height; i++) {
    iMatrix[i][column] = 0;
  }
}

}

void cracking::arraysAndStrings::zeroMatrix(std::vector<std::vector<uint32_t>>& iMatrix, unsigned int height, unsigned int width) {
  std::vector<Coordinate> zeroMarks;
  for (int i = 0; i < height; i++) {
    for (int j = 0; j < width; j++) {
      if (iMatrix[i][j] == 0) {
        zeroMarks.push_back(Coordinate(i, j));
      }
    }
  }

  for (int i = 0; i < zeroMarks.size(); i++) {
    setRowZero(iMatrix, zeroMarks[i].y, width);
    setColumnZero(iMatrix, zeroMarks[i].x, height);
  }
}

void cracking::arraysAndStrings::zeroMatrix_2(std::vector<std::vector<uint32_t>>& iMatrix, unsigned int height, unsigned int width) {
  std::vector<Coordinate> zeroMarks;
  bool firstRowHasZero = false;
  bool firstColumnHasZero = false;
  for (int i = 0; i < height; i++) {
    for (int j = 0; j < width; j++) {
      if (iMatrix[i][j] == 0) {
        // column j contains zero
        iMatrix[0][j] = 0;
        // row i contains zero
        iMatrix[i][0] = 0;
        if (i == 0) {
          firstRowHasZero = true;
        }
        if (j == 0) {
          firstColumnHasZero = true;
        }
      }
    }
  }

  // zero on firstRow/firstColumn can be because it starts with 0, OR the Row contain a Zero, OR the column has a zero
  // not touching first row, column because they are used for marking
  for (int i = 1; i < width; i++) {
    if (iMatrix[0][i] == 0) {
      setColumnZero(iMatrix, i, height);
    }
  }
  for (int i = 1; i < height; i++) {
    if (iMatrix[i][0] == 0) {
      setRowZero(iMatrix, i, height);
    }
  }

  if (firstRowHasZero) {
      setRowZero(iMatrix, 0, width);
  }
  if (firstColumnHasZero) {
      setColumnZero(iMatrix, 0, height);
  }
}
