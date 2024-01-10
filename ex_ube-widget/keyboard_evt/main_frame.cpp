// ppropagation child to parent 
#include <wx/wx.h>
#include "main_frame.h"


MainFrame::MainFrame(const wxString& title):wxFrame(nullptr,wxID_ANY,title)
{        wxPanel* panel = new wxPanel(this);
      
      panel->Bind(wxEVT_KEY_DOWN, &MainFrame::OnKeyEvent,this);
       
    

CreateStatusBar();
}


void MainFrame::OnKeyEvent(wxKeyEvent& evt) {
      wxChar keyChar = evt.GetUnicodeKey();
      wxLogStatus("Key Event: %c", keyChar);
}
