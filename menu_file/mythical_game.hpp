#pragma once
#include <wx/wx.h>

namespace mg {


class MythicalGame : public wxFrame
{
public:
    MythicalGame(const wxString &title);

private:
    // -- private
    void CreateControls();
    void CreateMenuBar();
    // void BindEventHendlers();
    // void OnAddButtonClicked(wxCommandEvent &evt);

    // ---controls decleration

    // ---END ---

    // -- MenuBar
    void OnFileSaved(wxCommandEvent &evt); // moramo jos dodati --> OnKeySaved
    void OnExitClicked(wxCommandEvent &evt);
    void OnAboutClicked(wxCommandEvent &evt);
    void OnKeySaved(wxCommandEvent &evt); // for Ctrl+shift+s --> save combo - save as vector
    // ---END ---

    // help functions:

    // ---END ---

    wxPanel *panel;
    wxListBox *list;
    // wxMenuBar *menuBar;
    // wxStaticText *headlineText;
    // wxButton *addButton;
    wxCheckListBox *checkListBox;
};

}