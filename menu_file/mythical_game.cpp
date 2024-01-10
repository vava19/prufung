#include "mythical_game.hpp"
#include <wx/wx.h>
#include <vector>
#include <string>


namespace mg {

MythicalGame::MythicalGame(const wxString &title) : wxFrame(nullptr, wxID_ANY, title)
{
    CreateControls();
    CreateMenuBar();
    // BindEventHendlers();
}

// ---menu

enum
{
    ID_File = 1,
    ID_Save = 2,
    ID_Quit = 3,
    ID_Help = 4
};

void MythicalGame::CreateMenuBar()
{
    wxMenu *menuFile = new wxMenu;
    menuFile->Append(ID_File, "&Save As...\tShift+Ctrl+S",
                     "Save As...\tShift+Ctrl+S showed in status bar");
    menuFile->AppendSeparator();
    menuFile->Append(wxID_EXIT);

    wxMenu *menuHelp = new wxMenu;
    menuHelp->Append(ID_Help, "&About... \tl+k",
                     "This is a viewer for creatures in a mythical game-tstus Bar message");

    wxMenuBar *menuBar = new wxMenuBar;
    menuBar->Append(menuFile, "&File");
    menuBar->Append(menuHelp, "&Help");

    Bind(wxEVT_MENU, &MythicalGame::OnFileSaved, this, ID_File);
    Bind(wxEVT_MENU, &MythicalGame::OnExitClicked, this, wxID_EXIT);
    Bind(wxEVT_MENU, &MythicalGame::OnAboutClicked, this, ID_Help);

    SetMenuBar(menuBar);
    CreateStatusBar();
    SetStatusText("Welcome to he best game ever-->status Bar message");
};

void MythicalGame::CreateControls()
{
    wxFont headlineFont(wxFontInfo(wxSize(0, 36)).Bold());
    wxFont mainFont(wxFontInfo(wxSize(0, 24)));
    // ---

    panel = new wxPanel(this);
    panel->SetFont(mainFont); // reflect on parent childrens- from panel to *

    // headlineText = new wxStaticText(panel, wxID_ANY, "Mytical Game Units", wxPoint(0, 22), wxSize(900, -1), wxALIGN_CENTER_HORIZONTAL);
    // headlineText->SetFont(headlineFont);

    wxArrayString choices;
    choices.Add("Drake Burner");
    choices.Add("Dwarvish Fighter");
    choices.Add("Elvish Archer");
    list = new wxListBox(panel, wxID_ANY, wxPoint(0, 0), wxSize(-1, 650), choices); // -1 default width, 650 vertikal length
};

// -----------------------  other help  methods  ------------------------------

void MythicalGame::OnFileSaved(wxCommandEvent &event)
{
    wxLogMessage("Selected File is Saved");
}

void MythicalGame::OnAboutClicked(wxCommandEvent &evt)
{
    wxMessageBox("This is a viewer for creatures in a mythical game",
                 "About Unit GUI”", wxOK | wxICON_INFORMATION);
};

void MythicalGame::OnExitClicked(wxCommandEvent &event)
{
    Close(true);
};



}