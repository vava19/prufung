#include "app.hpp"
#include "mythical_game.hpp"
#include <wx/wx.h>

bool App::OnInit() {
    mg::MythicalGame* game = new mg::MythicalGame(wxT("Mythical Game Units"));
    game->SetClientSize(1020,480);
    game->Center();
    game->Show();
    return true;
}

wxIMPLEMENT_APP(App);