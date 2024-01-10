#ifndef SHAPE_HPP
#define SHAPE_HPP

enum class Tetrominoe {
  none,
  Z,
  S,
  I,
  T,
  O,
  L,
  J,
};

class Shape
{
public:
    Shape() { SetShape( Tetrominoe::none ); }
    void SetShape( Tetrominoe shape);
    void SetRandomShape();

    Tetrominoe GetShape() const { return pieceShape; }
    int x(int index) const { return coords[index][0]; }
    int y(int index) const { return coords[index][1]; }

    int MinX() const;
    int MaxX() const;
    int MinY() const;
    int MaxY() const;

    Shape RotateLeft() const;
    Shape RotateRight() const;

private:
    void SetX(int index, int x) { coords[index][0] = x; }
    void SetY(int index, int y) { coords[index][1] = y; }
    Tetrominoe pieceShape;
    int coords[4][2];
};

#endif  // SHAPE_HPP
