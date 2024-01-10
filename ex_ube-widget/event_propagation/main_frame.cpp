// ppropagation child to parent 
#include <wx/wx.h>
#include "main_frame.h"


MainFrame::MainFrame(const wxString& title):wxFrame(nullptr,wxID_ANY,title)
{        wxPanel* panel = new wxPanel(this);
       
wxButton* button1 = new wxButton(panel,wxID_ANY, "start", wxPoint(10,10), wxSize(50, 35));
wxButton* button2 = new wxButton(panel,wxID_ANY, "end", wxPoint(90,10), wxSize(50, 35));

                                // when to use --> play same sound when either button clicked
this->Bind(wxEVT_BUTTON, &MainFrame::OnAnyButtonClicked, this); //either Btn clicked - same message-propagation parent
button1->Bind(wxEVT_BUTTON, &MainFrame::OnButton1Clicked, this); 
button2->Bind(wxEVT_BUTTON, &MainFrame::OnButton2Clicked, this); 
this->Bind(wxEVT_CLOSE_WINDOW, &MainFrame::OnClose, this);


CreateStatusBar();
}


void MainFrame::OnClose(wxCloseEvent &evt) {  
       //wxLogStatus("propagation to parent");
      wxMessageBox("window will close"); 
      evt.Skip();  // ne moze bez skipa jer smo zvali "wxEVT_CLOSE_WINDOW" u MainFrame -> nema propagacije
}

void MainFrame::OnAnyButtonClicked(wxCommandEvent &evt) {
       //wxLogStatus("propagation to parent");
      wxMessageBox("ANY ANY button clicked");
}
void MainFrame::OnButton1Clicked(wxCommandEvent &evt) {
       wxLogStatus("Button 1 clicked");
     // evt.Skip();  // tells wxWidget --> propagation should continue on "parent" --> on anyButton
}

void MainFrame::OnButton2Clicked(wxCommandEvent &evt) {
       wxLogStatus("Button 2 clicked");
      evt.Skip();  // tells wxWidget --> propagation should continue on "parent"
}


 


