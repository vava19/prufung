#include <stdlib.h>
#include <algorithm>
#include "shape.h"

using namespace std;

namespace tet {

void Shape::SetShape(Tetrominoes shape)
{
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
            coords[i][j] = coordsTable[shape][i][j];
    }
    pieceShape = shape;
}


void Shape::SetRandomShape()
{
  int x = rand() % 7 + 1; //used rand() from main.cpp
  SetShape(Tetrominoes(x));
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
  int m = coords[0][0]; // init 0 out von 4, 0=x
  for (int i=0; i<4; i++) {
      m = max(m, coords[i][0]);
  }
  return m;
}

int Shape::MinY() const
{                       // od 4 elem which one is minY
  int m = coords[0][1];  // 1= y
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

Shape Shape::RotateLeft() const
{
    if (pieceShape == SquareShape)
        return *this;  // return  orginal shape unchanged

    Shape result;  // X and Y coordinates of its blocks are effectively swapped and negated
    result.pieceShape = pieceShape;  // calss shape hold "tetromonius pieceshape"
    for (int i = 0; i < 4; ++i) {
        result.SetX(i, y(i));  // private setter function -> shape.h
        result.SetY(i, -x(i));  //i = index
    }
    return result;
}

Shape Shape::RotateRight() const  // ide sa "-y"
{
    if (pieceShape == SquareShape)
        return *this;

    Shape result;
    result.pieceShape = pieceShape;
    for (int i = 0; i < 4; ++i) {
        result.SetX(i, -y(i));
        result.SetY(i, x(i));
    }
    return result;
}

} // namespace tet