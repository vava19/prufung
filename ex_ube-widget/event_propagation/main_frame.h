#pragma once
#include <wx/wx.h>
//#include "main_frame.h"

class MainFrame : public wxFrame
{
    public:
    MainFrame(const wxString& title);

    private:
        void OnAnyButtonClicked(wxCommandEvent &evt);  //immer void
        void OnButton1Clicked(wxCommandEvent &evt);
        void OnButton2Clicked(wxCommandEvent &evt);
        void OnClose(wxCloseEvent &evt);


};





