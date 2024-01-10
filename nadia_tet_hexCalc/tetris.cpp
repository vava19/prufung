#include "tetris.hpp"
#include "shape.hpp"

MainFrame* mainFrame = nullptr;
StartFrame *startFrame = nullptr;

StartFrame::StartFrame(const wxString& title,  MainFrame* mainFrame)
: wxFrame(NULL, wxID_ANY, title, wxDefaultPosition, wxSize(300, 200)), mainFrame(mainFrame) {
  wxPanel* panel = new wxPanel(this, wxID_ANY);

  panel->SetBackgroundColour(wxColor(75, 75, 75));

  wxStaticText *logo = new wxStaticText( panel, wxID_ANY, wxT("TETRIS"), wxPoint(150,150), wxSize(500, 200), wxTE_CENTER | wxALIGN_CENTER_HORIZONTAL);
  logo->Wrap( -1 );
  logo->SetFont( wxFont( 95, wxFONTFAMILY_TELETYPE, wxFONTSTYLE_NORMAL, wxFONTWEIGHT_BOLD, false, wxT("Tlwg Mono") ) );
  logo->SetForegroundColour(wxColor(255, 255, 255));

  wxButton* startButton = new wxButton(panel, wxID_ANY, wxT("Start Game"), wxPoint(250, 500), wxSize(300, 100), 0);
  startButton->SetBackgroundColour(wxColor(0,0,0));
  startButton->SetFont( wxFont( 30, wxFONTFAMILY_TELETYPE, wxFONTSTYLE_NORMAL, wxFONTWEIGHT_BOLD, false, wxT("Tlwg Mono") ) );
  startButton->SetForegroundColour(wxColor(255, 255, 255));
  startButton->Bind(wxEVT_BUTTON, &StartFrame::OnStartButtonClicked, this);
}

void StartFrame::OnStartButtonClicked(wxCommandEvent& event) {
  // Close the start frame
  Close();
  mainFrame = new MainFrame(wxT("Tetris"));
  mainFrame->SetClientSize(800, 930);
  mainFrame->Centre();
  mainFrame->Show(true);
}

MainFrame::MainFrame(const wxString& title)
: wxFrame(NULL, wxID_ANY, title, wxDefaultPosition, wxSize(360, 760),
          wxDEFAULT_FRAME_STYLE ^ wxRESIZE_BORDER) {

  wxStatusBar *sb = CreateStatusBar();
  sb->SetStatusText("0 lines");

  //this->SetBackgroundColour(wxColor(35, 71, 144));
  this->SetBackgroundColour(wxColor(75, 75, 75));

  Connect ( wxEVT_PAINT, wxPaintEventHandler ( MainFrame::OnPaint));

  wxStaticText *label = new wxStaticText( this, wxID_ANY, wxT("TETRIS"), wxPoint(0,0), wxSize(500, 100), wxTE_CENTER | wxALIGN_CENTER_HORIZONTAL);
  label->Wrap( -1 );
  label->SetFont( wxFont( 63, wxFONTFAMILY_TELETYPE, wxFONTSTYLE_NORMAL, wxFONTWEIGHT_BOLD, false, wxT("Tlwg Mono") ) );
  label->SetForegroundColour(wxColor(255, 255, 255));

  board = new Board(this);
  board->SetMinSize(wxSize(360, 660));
  board->SetClientSize(wxSize(360, 660));
  board->SetPosition(wxPoint(70, 130));
  board->SetFocus();
   board->setNextPieceCallback([&] (const Shape& nextPiece){
    piece = nextPiece;
    Refresh();
  });
  board->start();
  board->setLineDeletedCallback([&](int numLinesDeleted) {
    deletedLines += numLinesDeleted;
    wxString linesString = "";
    linesString << deletedLines;
    linesText->SetValue(linesString);
    calculateScore(numLinesDeleted);
    wxString scoreString = "";
    scoreString << score;
    scoreText->SetValue(scoreString);
    SetLevel();
    wxString levelString = "";
    levelString << level;
    levelText->SetValue(levelString);

  });


  wxStaticText *nextlabel = new wxStaticText(this, wxID_ANY, wxT("Next"), wxPoint(500, 30), wxSize(200, 70), wxTE_LEFT);
  nextlabel->Wrap( -1 );
  nextlabel->SetFont( wxFont( 30, wxFONTFAMILY_TELETYPE, wxFONTSTYLE_NORMAL, wxFONTWEIGHT_BOLD, false, wxT("Tlwg Mono") ) );
  nextlabel->SetForegroundColour(wxColor(255, 255, 255));

  //   nextPanel = new wxPanel(this, wxID_ANY, wxPoint(510, 90), wxSize(180, 180), 0);
  //   nextPanel->SetBackgroundColour(wxColor(0, 0, 0));


  wxStaticText *scorelabel = new wxStaticText(this, wxID_ANY, wxT("Score"), wxPoint(500, 290), wxSize(200, 70), wxTE_LEFT);
  scorelabel->Wrap( -1 );
  scorelabel->SetFont( wxFont( 30, wxFONTFAMILY_TELETYPE, wxFONTSTYLE_NORMAL, wxFONTWEIGHT_BOLD, false, wxT("Tlwg Mono") ) );
  scorelabel->SetForegroundColour(wxColor(255, 255, 255));

  scoreText = new wxTextCtrl(this, wxID_ANY, "0", wxPoint(510, 350), wxSize(220, 50), wxTE_RIGHT | wxTE_READONLY);
  scoreText->SetBackgroundColour(wxColor(0,0,0));
  scoreText->SetFont( wxFont( 20, wxFONTFAMILY_TELETYPE, wxFONTSTYLE_NORMAL, wxFONTWEIGHT_BOLD, false, wxT("Tlwg Mono") ) );
  scoreText->SetForegroundColour(wxColor(255, 255, 255));

  wxStaticText *linesLabel = new wxStaticText(this, wxID_ANY, wxT("Lines"), wxPoint(500, 430), wxSize(200, 70), wxTE_LEFT );
  linesLabel->Wrap( -1 );
  linesLabel->SetFont( wxFont( 30, wxFONTFAMILY_TELETYPE, wxFONTSTYLE_NORMAL, wxFONTWEIGHT_BOLD, false, wxT("Tlwg Mono") ) );
  linesLabel->SetForegroundColour(wxColor(255, 255, 255));

  linesText = new wxTextCtrl(this, wxID_ANY, "0", wxPoint(510, 490), wxSize(220, 50), wxTE_RIGHT | wxTE_READONLY);
  linesText->SetBackgroundColour(wxColor(0,0,0));
  linesText->SetFont( wxFont( 20, wxFONTFAMILY_TELETYPE, wxFONTSTYLE_NORMAL, wxFONTWEIGHT_BOLD, false, wxT("Tlwg Mono") ) );
  linesText->SetForegroundColour(wxColor(255, 255, 255));

  wxStaticText *levelLabel = new wxStaticText(this, wxID_ANY, wxT("Level"), wxPoint(500, 570), wxSize(200, 70), wxTE_LEFT );
  levelLabel->Wrap( -1 );
  levelLabel->SetFont( wxFont( 30, wxFONTFAMILY_TELETYPE, wxFONTSTYLE_NORMAL, wxFONTWEIGHT_BOLD, false, wxT("Tlwg Mono") ) );
  levelLabel->SetForegroundColour(wxColor(255, 255, 255));

  levelText = new wxTextCtrl(this, wxID_ANY, "0", wxPoint(510, 630), wxSize(220, 50), wxTE_RIGHT | wxTE_READONLY);
  levelText->SetBackgroundColour(wxColor(0,0,0));
  levelText->SetFont( wxFont( 20, wxFONTFAMILY_TELETYPE, wxFONTSTYLE_NORMAL, wxFONTWEIGHT_BOLD, false, wxT("Tlwg Mono") ) );
  levelText->SetForegroundColour(wxColor(255, 255, 255));

  wxButton *quitButton = new wxButton(this, wxID_ANY, "Restart", wxPoint(520, 720), wxSize(200, 70), 0);
  quitButton->SetBackgroundColour(wxColor(0,0,0));
  quitButton->SetFont( wxFont( 25, wxFONTFAMILY_TELETYPE, wxFONTSTYLE_NORMAL, wxFONTWEIGHT_BOLD, false, wxT("Tlwg Mono") ) );
  quitButton->SetForegroundColour(wxColor(255, 255, 255));

  quitButton->Bind(wxEVT_BUTTON, &MainFrame::OnRestartButton, this);

          }

          void MainFrame::OnPaint(wxPaintEvent& event){

            wxPaintDC dc(this);
            //     wxSize size = GetClientSize();

            // Frame around board
            wxPen greyPen(wxColor(150, 150, 150), 10); // Weißer Stift, 30 Pixel breit
            dc.SetPen(greyPen);
            dc.DrawRectangle(wxPoint(60, 120), wxSize(380,680));
            //Frame around next piece
            dc.DrawRectangle(wxPoint(500, 80), wxSize(200,200));

            dc.DrawRectangle(wxPoint(500, 340), wxSize(240,70));

            dc.DrawRectangle(wxPoint(500, 480), wxSize(240,70));

            dc.DrawRectangle(wxPoint(500, 620), wxSize(240,70));

            dc.SetPen(*wxTRANSPARENT_PEN);
            dc.SetBrush(wxBrush(wxColor(0,0,0)));

            dc.DrawRectangle(wxPoint(510, 90), wxSize(180, 180));

            int x = 590;  // X-Position
            int y = 140;  // Y-Position
            Tetrominoe shape = piece.GetShape();

            if (shape == Tetrominoe::Z) {
              x = 600;  // X-Position
              y = 165;  // Y-Position
            } else if (shape == Tetrominoe::S) {
                x = 580;  // X-Position
                y = 165;  // Y-Position
            } else if (shape == Tetrominoe::I) {
              x = 590;  // X-Position
              y = 145;  // Y-Position
            } else if (shape == Tetrominoe::T) {
              x = 590;  // X-Position
              y = 155;  // Y-Position
            } else if (shape == Tetrominoe::O) {
              x = 575;  // X-Position
              y = 145;  // Y-Position
            } else if (shape == Tetrominoe::L) {
              x = 605;  // X-Position
              y = 165;  // Y-Position
            } else if (shape == Tetrominoe::J) {
              x = 575;  // X-Position
              y = 165;  // Y-Position
            }

            for (int i = 0; i < 4; ++i) {
              int tetrominoX = x + piece.x(i)*30;
              int tetrominoY = y + piece.y(i)*30;

              DrawSquare(dc, tetrominoX,
                         tetrominoY,
                         piece.GetShape());
            }
            //     DrawSquare(dc, x,
            //                y,
            //                piece.GetShape());

          }

          void MainFrame::calculateScore(int lines){
            switch (lines) {
              case 1:
                score += (40 *(level+1));
                break;
              case 2:
                score += (100 * (level +1));
                break;
              case 3:
                score += (300 * (level +1));
                break;
              case 4:
                score += (1200 * (level +1));
                break;
            }
          }

          void MainFrame::SetLevel(){
            if (deletedLines >= 5 && deletedLines < 10)
            {
              level = 1;
            }
            if (deletedLines >= 10 && deletedLines < 15)
            {
              level = 2;
            }
            if (deletedLines >= 15 && deletedLines < 20)
            {
              level = 3;
            }
            if (deletedLines >= 20 && deletedLines < 25)
            {
              level = 4;
            }
            if (deletedLines >= 25 && deletedLines < 30)
            {
              level = 5;
            }
            if (deletedLines >= 30 && deletedLines < 35)
            {
              level = 6;
            }
            if (deletedLines >= 35 && deletedLines < 40)
            {
              level = 7;
            }
            if (deletedLines >= 40 && deletedLines < 45)
            {
              level = 8;
            }
            if (deletedLines >= 45 && deletedLines < 50)
            {
              level = 9;
            }
            if (deletedLines >= 50)
            {
              level = 10;
            }
          }

          void MainFrame::OnRestartButton(wxCommandEvent& event)
          {
            deletedLines = 0;
            score = 0;
            level = 0;
            linesText->SetValue("0");
            scoreText->SetValue("0");
            levelText->SetValue("0");
            board->reset();
            board->SetFocus();
          }

          void MainFrame::DrawSquare(wxPaintDC& dc, int x, int y, Tetrominoe shape)
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

            dc.DrawLine(x, y + 30 - 3, x, y);
            dc.DrawLine(x, y, x + 30 - 3, y);

            wxPen darkpen(dark[int(shape)],3);
            darkpen.SetCap(wxCAP_PROJECTING);
            dc.SetPen(darkpen);

            dc.DrawLine(x + 3, y + 30 - 3,
                        x + 30 - 3, y + 30 - 3);
            dc.DrawLine(x + 30 - 3,
                        y + 30 - 3, x + 30 - 3, y + 3);

            dc.SetPen(*wxTRANSPARENT_PEN);
            dc.SetBrush(wxBrush(colors[int(shape)]));
            dc.DrawRectangle(x + 3, y + 3, 30 - 8,
                             30 - 8);
          }


          IMPLEMENT_APP(Tetris)

          bool Tetris::OnInit()
          {
            srand(static_cast<unsigned int>(time(NULL)));
            //mainFrame = new MainFrame(wxT("Tetris"));
            startFrame = new StartFrame(wxT("Tetris"), mainFrame);
            startFrame->SetClientSize(800, 930);
            startFrame->Centre();
            startFrame->Show(true);

            return true;
          }


