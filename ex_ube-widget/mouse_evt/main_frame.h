#pragma once
#include <wx/wx.h>
//#include "main_frame.h"

class MainFrame : public wxFrame
{
    public:
    MainFrame(const wxString& title);

    private:
        void OnAnyButtonClicked(wxCommandEvent &evt);  //immer void
        void OnMouseLeftEvent(wxMouseEvent &evt);
        void OnMouseRightEvent(wxMouseEvent &evt);
        void OnMousePosition(wxMouseEvent &evt);

       

};





