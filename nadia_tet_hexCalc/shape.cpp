#include <stdlib.h>
#include <algorithm>
#include <random>
#include <vector>
#include "shape.hpp"

using namespace std;

void Shape::SetShape(Tetrominoe shape) {
  static const int coordsTable[8][4][2] = {
    { { 0, 0 },   { 0, 0 },   { 0, 0 },   { 0, 0 } },
    { { 0, -1 },  { 0, 0 },   { -1, 0 },  { -1, 1 } },
    { { 0, -1 },  { 0, 0 },   { 1, 0 },   { 1, 1 } },
    { { 0, -1 },  { 0, 0 },   { 0, 1 },   { 0, 2 } },
    { { -1, 0 },  { 0, 0 },   { 1, 0 },   { 0, 1 } },
    { { 0, 0 },   { 1, 0 },   { 0, 1 },   { 1, 1 } },
    { { -1, -1 }, { 0, -1 },  { 0, 0 },   { 0, 1 } },
    { { 1, -1 },  { 0, -1 },  { 0, 0 },   { 0, 1 } }
  };

  for (int i = 0; i < 4 ; i++) {
    for (int j = 0; j < 2; ++j)
      coords[i][j] = coordsTable[static_cast<int>(shape)][i][j];
  }
  pieceShape = shape;
}


void Shape::SetRandomShape() {
    static std::vector<int> numbers {1, 2, 3, 4, 5, 6, 7};
    static std::vector<int> remainingNumbers = numbers;

    if (remainingNumbers.empty()) {
        // Alle Zahlen wurden einmal verwendet, Array neu mischen
        std::random_device rd;
        std::mt19937 generator(rd());
        std::shuffle(numbers.begin(), numbers.end(), generator);
        remainingNumbers = numbers;
    }

    int nextNumber = remainingNumbers.back();
    remainingNumbers.pop_back();

    SetShape(Tetrominoe(nextNumber));
}

int Shape::MinX() const
{
  int m = coords[0][0];
  for (int i=0; i<4; i++) {
      m = min(m, coords[i][0]);
  }
  return m;
}

int Shape::MaxX() const
{
  int m = coords[0][0];
  for (int i=0; i<4; i++) {
      m = max(m, coords[i][0]);
  }
  return m;
}

int Shape::MinY() const
{
  int m = coords[0][1];
  for (int i=0; i<4; i++) {
      m = min(m, coords[i][1]);
  }
  return m;
}

int Shape::MaxY() const
{
  int m = coords[0][1];
  for (int i=0; i<4; i++) {
      m = max(m, coords[i][1]);
  }
  return m;
}

Shape Shape::RotateLeft() const {
  if (pieceShape == Tetrominoe::O)
    return *this;

  Shape result;
  result.pieceShape = pieceShape;
  for (int i = 0; i < 4; ++i) {
    result.SetX(i, y(i));
    result.SetY(i, -x(i));
  }
  return result;
}

Shape Shape::RotateRight() const {
  if (pieceShape == Tetrominoe::O)
    return *this;

  Shape result;
  result.pieceShape = pieceShape;
  for (int i = 0; i < 4; ++i) {
    result.SetX(i, -y(i));
    result.SetY(i, x(i));
  }
  return result;
}
