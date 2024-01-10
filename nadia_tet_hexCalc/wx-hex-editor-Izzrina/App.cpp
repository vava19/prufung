#include "App.hpp"

#include <wx/wx.h>

#include "MainFrame.hpp"

bool App::OnInit() {
  MainFrame* mainframe = new MainFrame("Nadine's little HEXEditor");
  mainframe->SetClientSize(800, 600);
  mainframe->Center();
  mainframe->Show();
  mainframe->SetMinSize(wxSize(700,400));
  return true;
}

wxIMPLEMENT_APP(App);
