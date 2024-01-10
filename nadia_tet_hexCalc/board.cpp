#include "board.hpp"

#include <sstream>
#include <string>
#include <functional>


Board::Board(wxFrame *parent)
: wxPanel(parent, wxID_ANY, wxDefaultPosition,
          wxDefaultSize, wxBORDER_NONE) {


  this->SetBackgroundColour(wxColor(0, 0, 0));
  this->SetMinSize(wxSize(360, 660));

  timer = new wxTimer(this);
  isFallingFinished = false;
  isStarted = false;
  isPaused = false;
  numLinesRemoved = 0;
  curX = 0;
  curY = 0;

  ClearBoard();

  Connect ( wxEVT_PAINT, wxPaintEventHandler ( Board::OnPaint ) );

  Connect ( wxEVT_KEY_DOWN, wxKeyEventHandler ( Board::OnKeyDown ) );
  Connect ( wxEVT_TIMER, wxCommandEventHandler ( Board::OnTimer ) );
  }

          void Board::start() {
            if (isPaused)
              return;

            isStarted = true;
            isFallingFinished = false;
            numLinesRemoved = 0;
            ClearBoard();
            Piece.SetRandomShape();
            NewPiece();
            Piece.SetRandomShape();
            if (nextPieceCallback) {
                nextPieceCallback(Piece);
              }
            cycle_duration = 600;
            timer->Start(cycle_duration);
          }


          void Board::pause() {
            if (!isStarted)
              return;

            isPaused = !isPaused;
            if (isPaused) {
              timer->Stop();
            } else {
              timer->Start(cycle_duration);
            }
            Refresh();
          }

          void Board::reset() {
            timer->Stop();
            cycle_duration = 600;
            numLinesRemoved = 0;
            gameOver = false;
            isPaused = false;
            isStarted = true;
            isFallingFinished = false;
            numLinesRemoved = 0;
            ClearBoard();
            Piece.SetRandomShape();
            NewPiece();
            Piece.SetRandomShape();
            if (nextPieceCallback) {
                nextPieceCallback(Piece);
              }

            timer->Start(cycle_duration);
          }


          void Board::OnPaint(wxPaintEvent& event) {
            wxPaintDC dc(this);

            wxSize size = GetClientSize();

            int boardTop = size.GetHeight() - height * SquareHeight();

            // Draw background gridlines
            dc.SetPen(wxPen(wxColour(50, 50, 50), 1));
            for (int i = 0; i <= height; ++i) {
              dc.DrawLine(0, boardTop + i * SquareHeight(), width * SquareWidth(), boardTop + i * SquareHeight());
            }
            for (int i = 0; i <= width; ++i) {
              dc.DrawLine(i * SquareWidth(), boardTop, i * SquareWidth(), boardTop + height * SquareHeight());
            }

            for (int i = 0; i < height; ++i) {
              for (int j = 0; j < width; ++j) {
                Tetrominoe shape = ShapeAt(j, height - i - 1);
                if (shape != Tetrominoe::none )
                  DrawSquare(dc, 0 + j * SquareWidth(),
                             boardTop + i * SquareHeight(), shape);
              }
            }

            if (curPiece.GetShape() != Tetrominoe::none ) {
              for (int i = 0; i < 4; ++i) {
                int x = curX + curPiece.x(i);
                int y = curY - curPiece.y(i);
                DrawSquare(dc, 0 + x * SquareWidth(),
                           boardTop + ( height - y - 1) * SquareHeight(),
                           curPiece.GetShape());
              }
            }

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
              dc.SetTextForeground(wxColour(255, 255, 255));
              dc.SetTextBackground(wxColour(0, 0, 0));
              dc.SetFont( wxFont( 63, wxFONTFAMILY_TELETYPE, wxFONTSTYLE_NORMAL, wxFONTWEIGHT_BOLD, false, wxT("Tlwg Mono") ) );

              int textWidth, textHeight;
              dc.GetTextExtent(text, &textWidth, &textHeight);

              int x = 60;  // X-Position des Textes
              int y = 150; // Y-Position des Textes

              dc.DrawText(text, x, y);
            }
          }


          void Board::OnKeyDown(wxKeyEvent& event)
          {
            if (!isStarted || curPiece.GetShape() == Tetrominoe::none ) {
              event.Skip();
              return;
            }

            int keycode = event.GetKeyCode();

            if (keycode == 'p' || keycode == 'P') {
              pause();
              return;
            }

            if (isPaused)
              return;

            switch (keycode) {
              case WXK_LEFT:
                TryMove(curPiece, curX - 1, curY);
                break;
              case WXK_RIGHT:
                TryMove(curPiece, curX + 1, curY);
                break;
              case WXK_DOWN:
                TryMove(curPiece, curX, curY - 1);
                break;
              case WXK_SHIFT:
                TryMove(curPiece.RotateLeft(), curX, curY);
                break;
              case WXK_UP:
                TryMove(curPiece.RotateRight(), curX, curY);
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
              default:
                event.Skip();
            }

          }

          void Board::OnTimer(wxCommandEvent& event)
          {
            if (isFallingFinished) {

              isFallingFinished = false;
              NewPiece();
            } else {
              OneLineDown();
            }
          }

          void Board::ClearBoard() {
            for ( int i = 0; i < height * width; ++i )
              board[i] = Tetrominoe::none;
          }

          void Board::DropDown() {
            int newY = curY;
            while (newY > 0) {
              if (!TryMove(curPiece, curX, newY - 1))
                break;
              --newY;
            }
            PieceDropped();
          }

          void Board::OneLineDown()
          {
            if (!TryMove(curPiece, curX, curY - 1))
              PieceDropped();
          }

          void Board::PieceDropped()
          {
            for (int i = 0; i < 4; ++i) {
              int x = curX + curPiece.x(i);
              int y = curY - curPiece.y(i);
              ShapeAt(x, y) = curPiece.GetShape();
            }

            RemoveFullLines();

            if (!isFallingFinished)
            {
              NewPiece();
            }
          }

          void Board::setLineDeletedCallback(std::function<void(int)> callback) {
            lineDeletedCallback = callback;
          }


          void Board::RemoveFullLines() {
            int numFullLines = 0;

            for (int i = height - 1; i >= 0; --i) {
              bool lineIsFull = true;

              for (int j = 0; j < width; ++j) {
                if (ShapeAt(j, i) == Tetrominoe::none ) {
                  lineIsFull = false;
                  break;
                }
              }

              if (lineIsFull) {
                ++numFullLines;
                ++numLinesRemoved;
                if (numLinesRemoved >= 5 && numLinesRemoved % 5 == 0 && cycle_duration > 100){
                  cycle_duration -= 50;
                  timer->Stop();
                  timer->Start(cycle_duration);
                }
                for (int k = i; k < height - 1; ++k) {
                  for (int j = 0; j < width; ++j)
                    ShapeAt(j, k) = ShapeAt(j, k + 1);
                }
              }
            }

            if (numFullLines > 0) {
              if (lineDeletedCallback) {
                lineDeletedCallback(numFullLines);
              }
//               std::ostringstream ss;
//               ss << numLinesRemoved << " line";
//               if (numLinesRemoved > 1) ss << "s";
//               status_bar_->SetStatusText(ss.str().c_str());

              isFallingFinished = true;
              curPiece.SetShape( Tetrominoe::none );
              Refresh();
            }
          }

          void Board::NewPiece()
          {
            curPiece = Piece;
            Piece.SetRandomShape();
            if (nextPieceCallback) {
                nextPieceCallback(Piece);
              }
            curX = width / 2 + 1;
            curY = height - 1 + curPiece.MinY();

            if (!TryMove(curPiece, curX, curY)) {
              curPiece.SetShape( Tetrominoe::none );
              timer->Stop();
              isStarted = false;
              gameOver = true;
              Refresh();
            }
          }

          bool Board::TryMove(const Shape& newPiece, int newX, int newY)
          {
            for (int i = 0; i < 4; ++i) {
              int x = newX + newPiece.x(i);
              int y = newY - newPiece.y(i);
              if (x < 0 || x >= width || y < 0 || y >= height )
                return false;
              if (ShapeAt(x, y) != Tetrominoe::none )
                return false;
            }

            curPiece = newPiece;
            curX = newX;
            curY = newY;
            Refresh();
            return true;
          }

          void Board::DrawSquare(wxPaintDC& dc, int x, int y, Tetrominoe shape)
          {

            static wxColour colors[] = {
              wxColour(0, 0, 0),          // Black
              wxColour(255, 49, 0),    // Red
              wxColour(0, 153, 25),    // Green
              wxColour(0, 0, 153),    // Blue
              wxColour(235, 234, 2),    // Yellow
              wxColour(170, 0, 204),    // Magenta
              wxColour(0, 191, 230),    // Cyan
              wxColour(255, 154, 50)       // Orange
            };

            static wxColour light[] = {
              wxColour(0, 0, 0),          // Black
              wxColour(251, 117, 118),    // Light red
              wxColour(127, 239, 127),    // Light green
              wxColour(107, 107, 255),    // Light blue
              wxColour(246, 248, 139),    // Light yellow
              wxColour(226, 118, 255),    // Light magenta
              wxColour(180, 252, 248),    // Light cyan
              wxColour(243, 154, 72)       // Light orange
            };

            static wxColour dark[] = {
              wxColour(0, 0, 0),          // Black
              wxColour(194, 14, 13),      // Dark red
              wxColour(45, 173, 28),      // Dark green
              wxColour(4, 4, 186),      // Dark blue
              wxColour(245, 219, 18),     // Dark yellow
              wxColour(148, 18, 188),     // Dark magenta
              wxColour(71, 160, 204),     // Dark cyan
              wxColour(203, 95, 7)        // Dark orange
            };


            wxPen pen(light[int(shape)],3);
            pen.SetCap(wxCAP_PROJECTING);
            dc.SetPen(pen);

            dc.DrawLine(x, y + SquareHeight() - 3, x, y);
            dc.DrawLine(x, y, x + SquareWidth() - 3, y);

            wxPen darkpen(dark[int(shape)],3);
            darkpen.SetCap(wxCAP_PROJECTING);
            dc.SetPen(darkpen);

            dc.DrawLine(x + 3, y + SquareHeight() - 3,
                        x + SquareWidth() - 3, y + SquareHeight() - 3);
            dc.DrawLine(x + SquareWidth() - 3,
                        y + SquareHeight() - 3, x + SquareWidth() - 3, y + 3);

            dc.SetPen(*wxTRANSPARENT_PEN);
            dc.SetBrush(wxBrush(colors[int(shape)]));
            dc.DrawRectangle(x + 3, y + 3, SquareWidth() - 8,
                             SquareHeight() - 8);
          }
