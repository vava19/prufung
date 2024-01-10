#include <wx/wx.h>
#include "app.h"
#include "main_frame.h"

wxIMPLEMENT_APP(App);

//  ovo je main()
bool App::OnInit()
{
  MainFrame* mainframe = new MainFrame("widgets");
  mainframe->Show();
  mainframe->SetClientSize(800, 600);
  mainframe->Center();

  return true;
}