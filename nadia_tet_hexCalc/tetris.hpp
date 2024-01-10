#ifndef TETRIS_HPP
#define TETRIS_HPP

#include <wx/wx.h>

#include "board.hpp"


class MainFrame : public wxFrame {
public:

  MainFrame(const wxString& title);
  Board *board;

  Tetrominoe & ShapeAt(int x, int y);

private:

  void OnPaint(wxPaintEvent& event);
  void DrawSquare(wxPaintDC& dc, int x, int y, Tetrominoe shape);
  void calculateScore(int lines);
  void SetLevel();

  void OnRestartButton(wxCommandEvent& event);

  wxPanel *nextPanel;
  wxTextCtrl *scoreText;
  wxTextCtrl *linesText;
  wxTextCtrl *levelText;


  Shape piece;
  int deletedLines = 0;
  int score = 0;
  int level = 0;
};


class StartFrame : public wxFrame {

public:
  StartFrame(const wxString& title,  MainFrame* mainFrame);

private:
  MainFrame* mainFrame;
  void OnStartButtonClicked(wxCommandEvent& event);

};



class Tetris : public wxApp
{
public:
  virtual bool OnInit();
  void RestartMainFrame();
};

#endif  // TETRIS_HPP
