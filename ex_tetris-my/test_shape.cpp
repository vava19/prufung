#include <catch_amalgamated.hpp>
#include "../shape.h"

using namespace tet;

TEST_CASE("SetShape sets the correct shape", "[Shape]") {
    Shape shape;
    shape.SetShape(Tetrominoes::LShape);
    REQUIRE(shape.GetPieceShape() == Tetrominoes::LShape);
}

TEST_CASE("SetRandomShape sets a random shape", "[Shape]") {
    Shape shape;
    shape.SetRandomShape();
    REQUIRE(shape.GetPieceShape() != Tetrominoes::NoShape);
}

TEST_CASE("MinX returns the minimum x-coordinate", "[Shape]") {
    Shape shape;
    shape.SetShape(Tetrominoes::TShape);
    REQUIRE(shape.MinX() == -1);
}

TEST_CASE("MaxX returns the maximum x-coordinate", "[Shape]") {
    Shape shape;
    shape.SetShape(Tetrominoes::TShape);
    REQUIRE(shape.MaxX() == 1);
}

TEST_CASE("MinY returns the minimum y-coordinate", "[Shape]") {
    Shape shape;
    shape.SetShape(Tetrominoes::TShape);
    REQUIRE(shape.MinY() == -1);
}

TEST_CASE("MaxY returns the maximum y-coordinate", "[Shape]") {
    Shape shape;
    shape.SetShape(Tetrominoes::TShape);
    REQUIRE(shape.MaxY() == 0);
}

TEST_CASE("RotateLeft rotates the shape to the left", "[Shape]") {
    Shape shape;
    shape.SetShape(Tetrominoes::TShape);
    Shape rotatedShape = shape.RotateLeft();
    REQUIRE(rotatedShape.GetX(0) == 0);
    REQUIRE(rotatedShape.GetY(0) == -1);
    // Add more assertions for the other coordinates
}

TEST_CASE("RotateRight rotates the shape to the right", "[Shape]") {
    Shape shape;
    shape.SetShape(Tetrominoes::TShape);
    Shape rotatedShape = shape.RotateRight();
    REQUIRE(rotatedShape.GetX(0) == 0);
    REQUIRE(rotatedShape.GetY(0) == 1);
    // Add more assertions for the other coordinates
}