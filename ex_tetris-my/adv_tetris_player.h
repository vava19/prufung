// advanced_tetris_player.h
#ifndef ADVANCED_TETRIS_PLAYER_H
#define ADVANCED_TETRIS_PLAYER_H

#include "tetris_player.h"

namespace tet {

class AdvancedTetrisPlayer : public TetrisPlayer {
public:
    AdvancedTetrisPlayer(const std::string& playerName);

    void UseSpecialAbility();  // Additional feature not present in the base class

    // Override the Update function for additional functionality
    void Update() override;

private:
    // Additional data or functions specific to the advanced player
};

}  // namespace tet

#endif
