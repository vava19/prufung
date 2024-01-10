#include "app.hpp"
#include <wx/wx.h>
#include "mythical_game.hpp"

wxIMPLEMENT_APP(App);

bool App::OnInit()
{
    mg::MythicalGame*frame = new mg::MythicalGame("Mytical Game Units");
    frame->SetClientSize(900, 700);
    frame->Show(true);
    frame->Center();
    return true;
}