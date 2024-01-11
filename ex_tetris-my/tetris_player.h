// tetris_player.h
#ifndef TETRIS_PLAYER_H
#define TETRIS_PLAYER_H

#include "shape.h"
#include <string>

namespace tet {

class TetrisPlayer {
public:
    TetrisPlayer(const std::string& playerName);

    void MoveLeft();
    void MoveRight();
    void Rotate();
    void MoveDown();

    void Update();  // Placeholder for game logic update

    // Getters for player information
    std::string GetPlayerName() const { return playerName; }
    int GetScore() const { return score; }

protected:
    void HandleCollision();  // Placeholder for collision handling

    // Additional game-related functions can be added here

private:
    std::string playerName;
    int score;
    Shape currentShape;
};

}  // namespace tet

#endif
