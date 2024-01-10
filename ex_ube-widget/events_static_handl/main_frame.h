#pragma once
#include <wx/wx.h>
//#include "main_frame.h"

class MainFrame : public wxFrame
{
    public:
    MainFrame(const wxString& title);

    private:
        void OnButtonClicked(wxCommandEvent &evt);  //immer void
        void OnSliderChanged(wxCommandEvent &evt);
        void OnTextChanged(wxCommandEvent &evt);
        wxString ConvertToAscii(const wxString& input);

};





