[![Review Assignment Due Date](https://classroom.github.com/assets/deadline-readme-button-24ddc0f5d75046c5622901739e7c5dd533143b0c8e959d652212380cedb1ea36.svg)](https://classroom.github.com/a/-ClAcNUx)

# Tetris

Simplified implementation of the Tetris game based on
https://zetcode.com/gui/wxwidgets/thetetrisgame/.

```shell
mkdir build && cd build
cmake ..
make -j4
```

Start the game with `tetris`.

## Improvements

It is your task to improve this current implementation. Pick the improvements
that will make the game most fun for you to play. Some ideas include

- fix bugs (eg. status bar after break)
- improve readability
- implement levels
- adjust the [randomizer](https://tetris.wiki/Category:Randomizers)
- add scoring (eg.
  [Nintendo style](https://tetris.fandom.com/wiki/Scoring#Original_Nintendo_Scoring_System))
- display the upcoming Tetrominoe in status bar
- improve the look of the game including
  - better display of scores
  - actually display the next Tetrominoe
  - paint vertial lines of different colors to assist the player
- hot seat two player mode
- make it a [TetriNET](https://en.wikipedia.org/wiki/TetriNET) client
- ... go wild

I did the following improvment in tettris game

---

1. added grid to help players in better view of the game
2. added score and level in the top right corner
3. change the level of the game : easy, medium and hard ... depends how manyy score is reached
   score table easy : 6 points
   medium: 9 points
   hard above 12 points
