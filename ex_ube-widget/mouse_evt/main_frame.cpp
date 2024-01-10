// ppropagation child to parent 
#include <wx/wx.h>
#include "main_frame.h"


MainFrame::MainFrame(const wxString& title):wxFrame(nullptr,wxID_ANY,title)
{        wxPanel* panel = new wxPanel(this);
       
       wxButton* button = new wxButton(panel, wxID_ANY, "Button", wxPoint(50,50), wxSize(60, 35));
//nema elemena Bind mit, nur panel
panel->Bind(wxEVT_LEFT_DOWN, &MainFrame::OnMouseLeftEvent, this);
panel->Bind(wxEVT_RIGHT_DOWN, &MainFrame::OnMouseRightEvent, this);
panel->Bind(wxEVT_MOTION, &MainFrame::OnMousePosition, this);
button->Bind(wxEVT_MOTION,&MainFrame::OnMousePosition, this);



CreateStatusBar();
}

void MainFrame::OnMouseLeftEvent(wxMouseEvent &evt) {
      wxLogStatus("Mouse Event left click detected");
}

void MainFrame::OnMouseRightEvent(wxMouseEvent &evt) {
      wxLogStatus("Mouse Event right click detected");
}


void MainFrame::OnMousePosition(wxMouseEvent &evt) {
                              //wxGetMousePosition()  --> creen coords.
     wxPoint mousePos = evt.GetPosition();  //in diesem Fall mouse bevegung == event
     wxString message = wxString::Format("Mouse event: x=%d y=%d)", mousePos.x, mousePos.y); 
      wxLogStatus(message);
}