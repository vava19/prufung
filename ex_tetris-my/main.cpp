//App.cpp

#include "main.h"
#include "tetris.h"


IMPLEMENT_APP(MyApp)
    
bool MyApp::OnInit()
{               //srand init imer hier
    srand(time(NULL));  //  function is later used to generate random integers, specifically in the SetRandomShape() with time give random
    tet::Tetris *tetris = new tet::Tetris(wxT("Tetris"));
    tetris->Centre();
    tetris->Show(true);
    tetris->SetClientSize(580, 780); 

    return true;
}


  
        