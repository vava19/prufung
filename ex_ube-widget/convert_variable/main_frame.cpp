#include <wx/wx.h>
#include "main_frame.h"
#include <wx/spinctrl.h>

MainFrame::MainFrame(const wxString& title):wxFrame(nullptr,wxID_ANY,title)
{        wxPanel* panel = new wxPanel(this);
             
        int intValue = 42;  // Replace this with your integer value
        wxString labelText = wxString::Format("Value: %d", intValue);
        wxStaticText* staticText = new wxStaticText(panel, wxID_ANY, labelText, wxPoint(10, 10));

        wxStaticText* staticText_two = new wxStaticText(panel, wxID_ANY, "Static text two", wxPoint(200, 20));

}

