#include <wx/wx.h>
#include "app.h"
#include "main_frame.h"


wxIMPLEMENT_APP(App);

bool App::OnInit() {
    MainFrame* mainframe = new MainFrame("to-do App");
           
            mainframe->SetClientSize(800, 600);
            mainframe->Center();
            mainframe->Show();
        
        return true;
}


