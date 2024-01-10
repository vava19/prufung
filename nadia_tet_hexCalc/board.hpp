#ifndef BOARD_HPP
#define BOARD_HPP

#include "shape.hpp"
#include <wx/wx.h>
#include <functional>

class Board : public wxPanel {

public:
  Board(wxFrame *parent);
  void start();
  void pause();
  void reset();
  void linesRemovedChanged(int numLines);
  void setLineDeletedCallback(std::function<void(int)> callback);
  void setNextPieceCallback(const std::function<void(const Shape&)>& callback) {
    nextPieceCallback = callback;
  }
private:

  void OnPaint(wxPaintEvent& event);
  void OnKeyDown(wxKeyEvent& event);
  void OnTimer(wxCommandEvent& event);

  static const int width = 12;  // tetrinet style :)
  static const int height = 22;

  Tetrominoe & ShapeAt(int x, int y) { return board[(y * width ) + x]; }

  int SquareWidth() { return GetClientSize().GetWidth() / width; }
  int SquareHeight() { return GetClientSize().GetHeight() / height; }
  void ClearBoard();
  void DropDown();
  void OneLineDown();
  void PieceDropped();
  void RemoveFullLines();
  void NewPiece();
  bool TryMove(const Shape& newPiece, int newX, int newY);
  void DrawSquare(wxPaintDC &dc, int x, int y, Tetrominoe shape);
  void SetScore(int num);
  bool gameOver = false;

  int cycle_duration = 600;
  wxTimer *timer;
  bool isStarted;
  bool isPaused;
  bool isFallingFinished;
  Shape Piece;
  Shape curPiece;
  int curX;
  int curY;
  int numLinesRemoved;
  Tetrominoe board[width * height];

  std::function<void(int)> lineDeletedCallback;
  std::function<void(const Shape&)> nextPieceCallback;

};

#endif  // BOARD_HPP
