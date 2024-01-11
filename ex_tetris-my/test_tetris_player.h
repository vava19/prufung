#include <catch_amalgamated.hpp>
#include "tetris_player.h"

using namespace tet;

TEST_CASE("TetrisPlayer initializes with correct player name and score", "[TetrisPlayer]") {
    std::string playerName = "Player1";
    TetrisPlayer player(playerName);

    REQUIRE(player.GetPlayerName() == playerName);
    REQUIRE(player.GetScore() == 0);
}

TEST_CASE("MoveLeft moves the current shape to the left", "[TetrisPlayer]") {
    TetrisPlayer player("Player1");
    player.MoveLeft();

    // Add assertions to check if the shape has moved to the left
}

TEST_CASE("MoveRight moves the current shape to the right", "[TetrisPlayer]") {
    TetrisPlayer player("Player1");
    player.MoveRight();

    // Add assertions to check if the shape has moved to the right
}

TEST_CASE("Rotate rotates the current shape", "[TetrisPlayer]") {
    TetrisPlayer player("Player1");
    player.Rotate();

    // Add assertions to check if the shape has rotated
}

TEST_CASE("MoveDown moves the current shape down", "[TetrisPlayer]") {
    TetrisPlayer player("Player1");
    player.MoveDown();

    // Add assertions to check if the shape has moved down
}

TEST_CASE("Update updates the game logic", "[TetrisPlayer]") {
    TetrisPlayer player("Player1");
    player.Update();

    // Add assertions to check if the game logic has been updated correctly
}

TEST_CASE("HandleCollision handles collisions correctly", "[TetrisPlayer]") {
    TetrisPlayer player("Player1");
    player.HandleCollision();

    // Add assertions to check if collisions are handled correctly
}

// Add more test cases as needed