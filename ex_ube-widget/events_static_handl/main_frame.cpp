#include <wx/wx.h>
#include "main_frame.h"


MainFrame::MainFrame(const wxString& title):wxFrame(nullptr,wxID_ANY,title)
{        wxPanel* panel = new wxPanel(this);
       
wxButton* button = new wxButton(panel,wxID_ANY, "start", wxPoint(10,10), wxSize(50, 35));
wxSlider* slider = new wxSlider(panel,wxID_ANY,0, 0, 100, wxPoint(80,10), wxSize(200,-1));
wxTextCtrl* textctrl = new wxTextCtrl(panel, wxID_ANY, "", wxPoint(300, 60), wxSize(200, -1));



// Bind method comes from EVT_HANDLER  -> which every control inherit from
// we are using event hadler für class methods
button->Bind(wxEVT_BUTTON, &MainFrame::OnButtonClicked, this);
slider->Bind(wxEVT_SLIDER, &MainFrame::OnSliderChanged, this);
textctrl->Bind(wxEVT_TEXT, &MainFrame::OnTextChanged, this);

CreateStatusBar();
}

void MainFrame::OnButtonClicked(wxCommandEvent &evt) {
      wxLogStatus("Button clicked");
}
  void MainFrame:: OnSliderChanged(wxCommandEvent &evt) {
    wxString str = wxString::Format("Slider value: %d", evt.GetInt());
      wxLogStatus(str);
  }
  // void MainFrame:: OnTextChanged(wxCommandEvent &evt) {
  //       wxString str = wxString::Format("Text value: %s", evt.GetString());
  //         wxLogStatus(str);
  // }


void MainFrame::OnTextChanged(wxCommandEvent& evt) {
    wxString str = wxString::Format("Text value: %s", evt.GetString());
    wxLogStatus(str);

    wxString asciiValues = ConvertToAscii(evt.GetString());
    wxLogStatus("ASCII Values: %s", asciiValues);
}

wxString MainFrame::ConvertToAscii(const wxString& input) {  //wxString is array - iterate
    wxString asciiValues;
    for (size_t i = 0; i < input.length(); ++i) {
        int ascii = input[i];
        asciiValues += wxString::Format("%d ", ascii);
    }
    return asciiValues;
}
