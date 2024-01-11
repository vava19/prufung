#ifndef BOARD_H
#define BOARD_H

#include "shape.h"
#include <wx/wx.h>

namespace tet {
class Board : public wxPanel
{
                            // ako ne stavimo - NE ide jer "this" smo definisali u  tetris
public:                         // just for clarity , and maybe reuse in another class or frame
    Board(wxFrame *parent);  //       board instance is now a child window (or panel) of the Tetris game window (wxFrame). This hierarchy allows the Board class to interact with the Tetris game window, share resources, and receive events from its parent window, such as keyboard input.
    void Start();
    void Pause();
    void linesRemovedChanged();
    void ClearBoard(); 
    void ResetGame();

    //added

    //void InfoPanelCall();  //     { return infoPanelVisible_; }   ovo je definic. ane cijelo sa return
      wxTimer *timer = nullptr;
      
   
                                // wxButton* button1;
                                // void OnButton1Clicked(wxCommandEvent &evt);
  //void OnButtonExit(wxCloseEvent& event);
protected:
    void OnPaint(wxPaintEvent& event);
    void OnKeyDown(wxKeyEvent& event);
    void OnTimer(wxTimerEvent& event);


private:
    //enum { BoardWidth = 10, BoardHeight = 22 };
      // Board dimensions
    //bool infoPanelVisible_;

    static const int BoardWidth = 12;
    static const int BoardHeight = 22;

    Tetrominoes & ShapeAt(int x, int y) { return board[(y * BoardWidth) + x]; }
    // onda je ovo dekleracija
    int SquareWidth() { return GetClientSize().GetWidth() / BoardWidth; }
    int SquareHeight() { return GetClientSize().GetHeight() / BoardHeight; }  //  returns the height of a single square on the board.
    // void ClearBoard();                                      //  dividing the total height of the client area by the number of rows on the board (BoardHeight)
    void DropDown();
    void OneLineDown();
    void PieceDropped();
    void RemoveFullLines();
    void NewPiece();
    bool TryMove(const Shape& newPiece, int newX, int newY);
    void DrawSquare(wxPaintDC &dc, int x, int y, Tetrominoes shape);
    //
    // --> added
    //void UpdateLevel();
     void GameOverMessage(); // CommandEvent &evt
     void MessageWarning(wxCommandEvent& event);
    

  

    // wxTimer *timer;
    bool isStarted;
    bool isPaused;
    bool isFallingFinished;
    Shape curPiece;  //created object of class
    int curX;  //detrmine actual pos. of falling "shape"
    int curY;
    int numLinesRemoved;
    Tetrominoes board[BoardWidth * BoardHeight];
    wxStatusBar *m_stsbar;
    int cycleDuration = 400;
    wxString level;
    bool gameOver = false;
    


    //   wxButton* stopBtn;
    //  void OnStopButtonClick(wxCommandEvent& event);
};


} // namespace tet

#endif