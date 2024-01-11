// main_frame.cpp
// controls() binders()
#include "tetris.h"
#include "board.h"
using namespace tet; 

tet::Tetris::Tetris(const wxString& title)
       : wxFrame(NULL, wxID_ANY, title )    //, wxDefaultPosition,     wxSize(180, 380))
{

    CreateControls();
    BindEventHandlers();


}

  void tet::Tetris::CreateControls() {

     sb = CreateStatusBar();
  sb->SetStatusText(wxT("0"));
  board = new Board(this);  //tetris parent of board is wxframe-> "this"   a board is = panel
  board->SetFocus();                //  means that it will receive keyboard input events - interaction
  board->Start();  // call

 stopBtn = new wxButton(this, wxID_ANY, "Start-Stop ", wxPoint(10, 10), wxSize(100, 35));
 resetBtn = new wxButton(this,wxID_ANY, "Reset", wxPoint(10, 75), wxSize(100, 35));
 quitButton = new wxButton(this, wxID_ANY, "Quit", wxPoint(10, 140), wxSize(100, 35));

    // sizers 

    horizontal_sizer = new wxBoxSizer(wxHORIZONTAL);
    left_column = new wxBoxSizer(wxVERTICAL);
     middle_column = new wxBoxSizer(wxVERTICAL);
    //right_column = new wxBoxSizer(wxVERTICAL);

    horizontal_sizer->Add(left_column,4, wxEXPAND | wxALL, 10);
    horizontal_sizer->Add(middle_column, 1, wxALL, 10);
   // horizontal_sizer->Add(right_column, 1);

    left_column->Add(board,6, wxEXPAND);
    left_column->Add(sb,0); //ratio 0S
    middle_column->Add(stopBtn, 1, wxALIGN_CENTER | wxTOP, 15);
    middle_column->Add(resetBtn, 1, wxALIGN_CENTER | wxBOTTOM, 20);
    middle_column->Add(quitButton, 1, wxALIGN_CENTER | wxBOTTOM, 20);

// Set background color for each column
    // left_column->GetContainingWindow()->SetBackgroundColour(wxColour(200, 255, 192));
    // middle_column->GetContainingWindow()->SetBackgroundColour(wxColour(0, 255, 0));


   SetSizer(horizontal_sizer);
   horizontal_sizer->Layout();



    /*    Sizer END   -------  */

  }


      void tet::Tetris::BindEventHandlers() {

         stopBtn->Bind(wxEVT_BUTTON, &Tetris::OnStopButtonClick, this);
         resetBtn->Bind(wxEVT_BUTTON, &Tetris::OnStartButtonClick, this);
         quitButton->Bind(wxEVT_BUTTON, &Tetris::MessageWarning, this);  // wxCommandEvent& event   MessageWarning

      }



  //start , stop  -->public func
void tet::Tetris::OnStopButtonClick(wxCommandEvent& event)
{

    if (board)
        board->Pause();
        //this->SetFocus();
         event.Skip(); // without skip after use, block * other keys

}

    void tet::Tetris::OnStartButtonClick(wxCommandEvent& event) {

            // board->Start();
            board->ResetGame();
            //event.Skip();
            board->SetFocus();
            
    }


// void tet::Tetris::OnButtonExit([[maybe_unused]] wxCloseEvent& event){
//     //wxExit();
//     wxExit();
//     timer->Stop();
//     board->ClearBoard();
//     event.Skip();
// }



void tet::Tetris::MessageWarning(wxCommandEvent& event) {
    
    wxMessageDialog dialog(this, "Aru you sure you want to exit", "exiting",
     wxYES_NO | wxCANCEL);
    int result = dialog.ShowModal();  //display dialog and wait for the user. returns integer 

    if(result == wxID_YES) {
          board->ClearBoard();
        //    timer->Stop();
          wxExit();
          //event.Skip();
    }
    else
        return;
    
    
    
}
