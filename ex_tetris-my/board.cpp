#include "board.h"
#include <wx/wx.h>


tet::Board::Board(wxFrame *parent)     //    Board panel is the Tetris frame, and it is specified using "this" when creating the Board instance.
       : wxPanel(parent, wxID_ANY, wxDefaultPosition,
             wxDefaultSize, wxBORDER_NONE)
{
    timer = new wxTimer(this, 1); ////wxTimer take 2 args. owner & timer_id =wxId_ANY
                            // methods: ->start()  ->stop()

    //infoPanelVisible_ = true;
    m_stsbar = parent->GetStatusBar(); //accessing CreateStatusBar() from tetris.cpp --> getting "0" sto je uneseno
    isFallingFinished = false;
    isStarted = false;
    isPaused = false;
    numLinesRemoved = 0;   // counting score
    curX = 0;
    curY = 0;
    level = "easy";
  



//  wxWindow-derived class (like a panel or frame), you can use Bind directly,
    Bind(wxEVT_PAINT, &Board::OnPaint, this);
    Bind(wxEVT_KEY_DOWN, &Board::OnKeyDown, this);
    Bind(wxEVT_TIMER, &Board::OnTimer, this);


}



void tet::Board::Start()
{                   //def. above as = false
    if (isPaused) // stmt without a value means that the func.start() will exit immediately 
        return;

    isStarted = true;
    isFallingFinished = false;
    numLinesRemoved = 0;
    ClearBoard();

    NewPiece();
    timer->Start(cycleDuration);  
}

void tet::Board::Pause()
{
    if (!isStarted)  //if not started , cannot be paused, reverse from above
        return;
                        // if isPaused was false before this line, it will become true after
    isPaused = !isPaused; // begining isPaused=false
    if (isPaused) {       
        timer->Stop();  // ne moze pauzirati bez -timer -- virtual inline function()
        m_stsbar->SetStatusText(wxT("paused")); //set Text, ne Bar-nemoze
    } else {
        timer->Start(cycleDuration);
         wxString str;
        str.Printf(wxT("%d"), numLinesRemoved);
        m_stsbar->SetStatusText(str);
    }
    Refresh();
}

//added reset

void tet::Board::ResetGame() {
            timer->Stop();
            cycleDuration = 600;
            numLinesRemoved = 0;
           // gameOver = false;
            //isPaused = false;
            isStarted = true;
            isFallingFinished = false;
            numLinesRemoved = 0;
            ClearBoard();
            //Piece.SetRandomShape();
            NewPiece();
            // Piece.SetRandomShape();
            // if (nextPieceCallback) {
            //     nextPieceCallback(Piece);
            //   }

            timer->Start(cycleDuration);
          }



void tet::Board::OnPaint(wxPaintEvent& event)
{
    wxPaintDC dc(this);

    wxSize size = GetClientSize();
    int boardTop = size.GetHeight() - BoardHeight * SquareHeight(); //  Calculates the top position of the board inside the window

/*
draw all the shapes, or remains of the shapes that have been
 dropped to the bottom of the board. All the squares
  are rememberd in the "board" array. We access it using 
  the ShapeAt method -which is public, "board" array of tetrimoneas(bestimte shapes) - IS PRIVATE!
  called whenever window needs to be redrawn
*/
    for (int i = 0; i < BoardHeight; ++i) { //height =22
        for (int j = 0; j < BoardWidth; ++j) { // =10
            Tetrominoes shape = ShapeAt(j, BoardHeight - i - 1);
            if (shape != NoShape)
                DrawSquare(dc, 0 + j * SquareWidth(),
                           boardTop + i * SquareHeight(), shape);
        }
    }

    /*
    iterates through the current piece's squares.
Calc the screen position (x and y) for each square of the falling piece.
Draws a square for each square of the falling piece.
    */
 // drawing of the actual piece that is falling down

    if (curPiece.GetShape() != NoShape) {  //GetShape return "pieceShape", samo bude u .hpp jer je getter
        for (int i = 0; i < 4; ++i) {
            int x = curX + curPiece.x(i);
            int y = curY - curPiece.y(i);
            DrawSquare(dc, 0 + x * SquareWidth(),
                       boardTop + (BoardHeight - y - 1) * SquareHeight(),
                       curPiece.GetShape());
        }
    }


    // Draw the grid lines     ----> added
  dc.SetPen(wxPen(wxColour(200, 200, 200), 1)); // light gray color, 1px thickness
  for (int i = 0; i <= BoardHeight; ++i)
  {
    dc.DrawLine(0, boardTop + i * SquareHeight(),
                BoardWidth * SquareWidth(), boardTop + i * SquareHeight());
  }
  for (int i = 0; i <= BoardWidth; ++i)
  {
    dc.DrawLine(i * SquareWidth(), boardTop,
                i * SquareWidth(), boardTop + BoardHeight * SquareHeight());
  }



//  ----
  // added  ----->
  // Draw the score in the top right corner
  wxFont font(18, wxFONTFAMILY_DEFAULT, wxFONTSTYLE_NORMAL, wxFONTWEIGHT_BOLD);
  dc.SetFont(font);
  wxColour gray(128, 128, 128);
  dc.SetTextForeground(gray);
  dc.DrawText("Score: " + std::to_string(numLinesRemoved), BoardWidth * SquareWidth() - 150, 20);
  dc.DrawText("Level: " + level, BoardWidth * SquareWidth() - 150, 50);

  //add von rabi

  if(gameOver){

              wxString text = "Game\nOver";
              dc.SetTextForeground(wxColour(255, 255, 255));
              dc.SetTextBackground(wxColour(0, 0, 0));
              dc.SetFont( wxFont( 72, wxFONTFAMILY_TELETYPE, wxFONTSTYLE_NORMAL, wxFONTWEIGHT_BOLD, false, wxT("Tlwg Mono") ) );

              int textWidth, textHeight;
              dc.GetTextExtent(text, &textWidth, &textHeight);

              int x = 70;  // X-Position des Textes
              int y = 150; // Y-Position des Textes

              dc.DrawText(text, x, y);
            }
            if(isPaused){

              wxString text = "Pause";
              dc.SetTextForeground(wxColour(165, 123, 0));
              dc.SetTextBackground(wxColour(0, 0, 0));
              dc.SetFont( wxFont( 63, wxFONTFAMILY_TELETYPE, wxFONTSTYLE_NORMAL, wxFONTWEIGHT_BOLD, false, wxT("Tlwg Mono") ) );

              int textWidth, textHeight;
              dc.GetTextExtent(text, &textWidth, &textHeight);

              int x = 60;  // X-Position des Textes
              int y = 150; // Y-Position des Textes

              dc.DrawText(text, x, y);
            }
          

}



// void tet::Board::InfoPanelCall() {

//      wxPaintDC dc(this);

//     wxSize size = GetClientSize();
//     int boardTop = size.GetHeight() - BoardHeight * SquareHeight(); //  Calculates the top position of the board inside the window


//       // Draw the grid lines     ----> added
//   dc.SetPen(wxPen(wxColour(200, 200, 200), 1)); // light gray color, 1px thickness
//   for (int i = 0; i <= BoardHeight; ++i)
//   {
//     dc.DrawLine(0, boardTop + i * SquareHeight(),
//                 BoardWidth * SquareWidth(), boardTop + i * SquareHeight());
//   }
//   for (int i = 0; i <= BoardWidth; ++i)
//   {
//     dc.DrawLine(i * SquareWidth(), boardTop,
//                 i * SquareWidth(), boardTop + BoardHeight * SquareHeight());
        
//   }

// //  ----
//   // added  ----->
//   // Draw the score in the top right corner
//   wxFont font(18, wxFONTFAMILY_DEFAULT, wxFONTSTYLE_NORMAL, wxFONTWEIGHT_BOLD);
//   dc.SetFont(font);
//   wxColour gray(128, 128, 128);
//   dc.SetTextForeground(gray);
//   dc.DrawText("Score: " + std::to_string(numLinesRemoved), BoardWidth * SquareWidth() - 150, 20);

//   dc.DrawText("Level: " + level, BoardWidth * SquareWidth() - 150, 50);




//   return infoPanelVisible_;
// }


void tet::Board::OnKeyDown(wxKeyEvent& event)
{
    if (!isStarted || curPiece.GetShape() == NoShape) {  
        event.Skip();
        return;
    }

    int keycode = event.GetKeyCode();

    if (keycode == 'p' || keycode == 'P') {
	Pause();
        return;
    }

    if (isPaused)
        return;

    // if (keycode == 'h' || keycode == 'H') {
    //     //InfoPanelCall();
    //     //infoPanelVisible_ = !infoPanelVisible_;
    //     Refresh(); // Redraw the window to reflect the visibility change
    //     return;
    // }


    switch (keycode) {
    case WXK_LEFT:
        TryMove(curPiece, curX - 1, curY); //curPiece -can move only peace in movment
        break;
    case WXK_RIGHT:
        TryMove(curPiece, curX + 1, curY);
        break;
    case WXK_DOWN:
        TryMove(curPiece.RotateRight(), curX, curY);
        break;
    case WXK_UP:
        TryMove(curPiece.RotateLeft(), curX, curY);
        break;
    case WXK_SPACE:
        DropDown();
        break;
    case 'd':
        OneLineDown();
        break;
    case 'D':
        OneLineDown();
        break;
    case 's':
        //save();
       // break;
    default:
        event.Skip();
    }

}

void tet::Board::OnTimer(wxTimerEvent& event)
{
    if (isFallingFinished) {
        isFallingFinished = false;
        NewPiece();
    } else {
        OneLineDown();
    }
}

void tet::Board::ClearBoard() // init game board by setting every cell to NoShape
{
    for (int i = 0; i < BoardHeight * BoardWidth; ++i) //width *heigh =total cnt cell of Board 
        board[i] = NoShape;                         // height=22, width=10
}

            // when press "Space" drop falling shape down
void tet::Board::DropDown()
{
    int newY = curY;
    while (newY > 0) {
        if (!TryMove(curPiece, curX, newY - 1))
            break;
        --newY;
    }
    PieceDropped();
}

void tet::Board::OneLineDown()
{
    if (!TryMove(curPiece, curX, curY - 1))
        PieceDropped();
}

/*
iterates over the four blocks of the current piece (curPiece), 
calculates their positions on the board (x and y), and updates the board using the ShapeAt
This line is updating the game board by assigning the shape of the
 current falling piece (curPiece) to a specific cell on the board. -->right
*/
void tet::Board::PieceDropped()
{
    for (int i = 0; i < 4; ++i) {
        int x = curX + curPiece.x(i);
        int y = curY - curPiece.y(i);
        ShapeAt(x, y) = curPiece.GetShape();  //SHapeAt->board.h     = GetShape() return: pieceShape from ->shape.h  | 
    }

    RemoveFullLines();  // to check if we have at least on full line

    if (!isFallingFinished)
        NewPiece();
}

void tet::Board::RemoveFullLines()
{
     int numFullLines = 0;   // local var
       // Iterate through each row from bottom to top
     for (int i = BoardHeight - 1; i >= 0; --i) {
         bool lineIsFull = true;
        // Check if the current row is full
         for (int j = 0; j < BoardWidth; ++j) {
             if (ShapeAt(j, i) == NoShape) {  //j=width   i=height
                 lineIsFull = false;
                 break;
             }
         }
        // If the line is full, remove it and shift the above lines down
         if (lineIsFull) {
             ++numFullLines;
             for (int k = i; k < BoardHeight - 1; ++k) {
                 for (int j = 0; j < BoardWidth; ++j)
                     ShapeAt(j, k) = ShapeAt(j, k + 1);
             }
         }
     }
    // If the row was full, we increase the count and move all rows above down by one
     if (numFullLines > 0) {
         numLinesRemoved += numFullLines;
        linesRemovedChanged();
      // Update the status bar with the new score
         wxString str;
	 str.Printf(wxT("%d"), numLinesRemoved);
         m_stsbar->SetStatusText(str);
        

    // Set the falling state to finished, clear the current piece, and refresh the display
         isFallingFinished = true;
         curPiece.SetShape(NoShape);
         Refresh();
  }
 }

// addded
void tet::Board::linesRemovedChanged() {
    if (numLinesRemoved > 6) {
        //timer->Start(50);
        cycleDuration = 50;
         Refresh();
    }
    else if (numLinesRemoved > 3) {
        //timer->Start(300);
        cycleDuration = 300;
         Refresh();
    }
    else {
        //timer->Start(600);
        cycleDuration = 400; // init duration
         Refresh();
    }

    timer->Start(cycleDuration); 
}


//  creira novi peace   --ovo mozemo display
void tet::Board::NewPiece()
{
    curPiece.SetRandomShape();
    curX = BoardWidth / 2 + 1; //init the starting X-coordinate from the MIDDLE
    curY = BoardHeight - 1 + curPiece.MinY(); // init Y

  // If we can't move the new piece, the game is over
    if (!TryMove(curPiece, curX, curY)) { 
        curPiece.SetShape(NoShape);
        timer->Stop();
        isStarted = false;
        m_stsbar->SetStatusText(wxT("game over"));
        GameOverMessage();
    }
}


// added
   void tet::Board::GameOverMessage() {
      wxMessageBox("Game Over!");
      //evt.Skip();
    }

// Method to try moving the piece to a new location
bool tet::Board::TryMove(const Shape& newPiece, int newX, int newY)
{    // For each square in the piece
    for (int i = 0; i < 4; ++i) {
        int x = newX + newPiece.x(i);
        int y = newY - newPiece.y(i);
      // Check if it's inside the board and not colliding with any other pieces
        if (x < 0 || x >= BoardWidth || y < 0 || y >= BoardHeight)
            return false;
        if (ShapeAt(x, y) != NoShape)
            return false;
    }

// If we passed all checks, update the current piece and position and refresh the board
    curPiece = newPiece;
    curX = newX;
    curY = newY;
    Refresh();
    return true;
}

void tet::Board::DrawSquare(wxPaintDC& dc, int x, int y, Tetrominoes shape)
{
    static wxColour colors[] = { wxColour(0, 0, 0), wxColour(204, 102, 102), 
             wxColour(102, 204, 102), wxColour(102, 102, 204), 
             wxColour(204, 204, 102), wxColour(204, 102, 204), 
             wxColour(102, 204, 204), wxColour(218, 170, 0) };

    static wxColour light[] = { wxColour(0, 0, 0), wxColour(248, 159, 171),
             wxColour(121, 252, 121), wxColour(121, 121, 252), 
             wxColour(252, 252, 121), wxColour(252, 121, 252), 
             wxColour(121, 252, 252), wxColour(252, 198, 0) };

    static wxColour dark[] = { wxColour(0, 0, 0), wxColour(128, 59, 59), 
             wxColour(59, 128, 59), wxColour(59, 59, 128), 
             wxColour(128, 128, 59), wxColour(128, 59, 128), 
             wxColour(59, 128, 128), wxColour(128, 98, 0) };


    wxPen pen(light[int(shape)]); // mislim da je ovo casting shape->int
    pen.SetCap(wxCAP_PROJECTING);
    dc.SetPen(pen);

    dc.DrawLine(x, y + SquareHeight() - 1, x, y);
    dc.DrawLine(x, y, x + SquareWidth() - 1, y);

    wxPen darkpen(dark[int(shape)]);
    darkpen.SetCap(wxCAP_PROJECTING);
    dc.SetPen(darkpen);

    dc.DrawLine(x + 1, y + SquareHeight() - 1,
        x + SquareWidth() - 1, y + SquareHeight() - 1);
    dc.DrawLine(x + SquareWidth() - 1, 
        y + SquareHeight() - 1, x + SquareWidth() - 1, y + 1);

    dc.SetPen(*wxTRANSPARENT_PEN);
    dc.SetBrush(wxBrush(colors[int(shape)])); 
    dc.DrawRectangle(x + 1, y + 1, SquareWidth() - 2, 
        SquareHeight() - 2);
}