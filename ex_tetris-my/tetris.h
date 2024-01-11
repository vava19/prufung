// main_frame.h
#pragma once
#include <wx/wx.h>
#include "board.h"

namespace tet {
class Tetris : public wxFrame
{
public:
    Tetris(const wxString& title); //struct + other controls(), vars dekl.

private:

    void CreateControls();
    void BindEventHandlers();
    void OnStopButtonClick(wxCommandEvent& event);
    void OnStartButtonClick(wxCommandEvent& event);
   // void OnButtonExit(wxCloseEvent& event);
    void MessageWarning(wxCommandEvent& event);

    
    // vars.
     Board* board;
    wxStatusBar *sb;
    wxButton* stopBtn;
    wxButton* resetBtn;
    wxButton* quitButton;
     //wxTimer* timer;  


       // sizers 
    wxBoxSizer* horizontal_sizer; 
    wxBoxSizer* left_column;
    wxBoxSizer* middle_column; 
    wxBoxSizer* right_column;



};

} // namespace tet