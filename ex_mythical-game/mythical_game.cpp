#include "mythical_game.hpp"


mg::MythicalGame::MythicalGame(const wxString& title) : 
    wxFrame(nullptr,wxID_ANY,title,wxDefaultPosition,wxDefaultSize) {
        
        //panel
        panel_ = new wxPanel(this,wxID_ANY);
        
        //listbox
        items_.push_back(drake_burner_->type_name());  // took just one att from obj.
        items_.push_back(dwarvish_fighter_->type_name());
        items_.push_back(elvish_archer_->type_name());
        listbox_units_ = new wxListBox(panel_, wxID_ANY, wxPoint(0,0), wxSize(180,452), items_);

        //dataview --u .hpp deklerisan, ovdje definisan
        listctrl_weapons_ = new wxDataViewListCtrl(panel_, wxID_ANY,wxDefaultPosition,wxSize(360,200));
        listctrl_weapons_->AppendTextColumn("Name");
        listctrl_weapons_->AppendTextColumn("Strikes"); //with Append we adding wxDataViewColumn
        listctrl_weapons_->AppendTextColumn("Range");
        listctrl_weapons_->AppendTextColumn("Type");

        int colWidth = 90; 

        for (int i = 0; i < 4; ++i)
        {
            wxDataViewColumn* column = listctrl_weapons_->GetColumn(i); // loop zato sto list,array, vector
            column->SetWidth(colWidth);
        }

        //checkbox
        checkbox_ = new wxCheckBox(panel_, wxID_ANY, wxT("Show stats"), wxPoint(0,455), wxDefaultSize);
        checkbox_->SetValue(true);

        //text
        title_ = new wxStaticText(panel_, wxID_ANY, "");
        hp_ = new wxStaticText(panel_, wxID_ANY, "");
        moves_ = new wxStaticText(panel_, wxID_ANY, "");
        weapons_ = new wxStaticText(panel_, wxID_ANY, "Weapons");

        //text font
        wxFont font_title = title_->GetFont();
        font_title.MakeBold();
        font_title.SetPointSize(17);  
        title_->SetFont(font_title);

        wxFont font_weapons = weapons_->GetFont();
        font_title.MakeBold();
        font_title.SetPointSize(15);  
        weapons_->SetFont(font_title);
        

        /*
        this code loads a PNG image, converts it to a wxBitmap, and displays it using a wxStaticBitmap
        */
        //image                       You don't explicitly call methods on wxPNGHandler directly in this snippet because it's a handler that gets used behind the scenes
        wxImage::AddHandler(new wxPNGHandler);  // For PNG images  --> one-time init. that tells the wxImage system how to handle PNG images
        wxImage image("../images/drake_burner.png", wxBITMAP_TYPE_PNG);
        wxBitmap bitmap(image); // convert to bitmap
        image_bitmap_ = new wxStaticBitmap(panel_, wxID_ANY, bitmap);

        //menu
        wxMenuBar* menu_bar = new wxMenuBar(); 
        wxMenu* menu_file = new wxMenu();
        wxMenu* menu_help = new wxMenu();

        wxMenuItem* menu_item_save_as = new wxMenuItem(menu_file,wxID_ANY,"&Save As...  \tShift+Ctrl+S");
        wxMenuItem* menu_item_quit = new wxMenuItem(menu_file,wxID_ANY,"&Quit   \tCtrl+Q");
        wxMenuItem* menu_item_about = new wxMenuItem(menu_help,wxID_ANY,"&About    \tShift+Ctrl+A");
        
        menu_file->Append(menu_item_save_as);
        menu_file->Append(menu_item_quit);
        menu_help->Append(menu_item_about);
        
        menu_bar->Append(menu_file,"&File");
        menu_bar->Append(menu_help,"&Help");

        SetMenuBar(menu_bar);



        //menu shortcut
        wxAcceleratorEntry entries[3];
        entries[0].Set(wxACCEL_SHIFT | wxACCEL_CTRL, (int) 'S', menu_item_save_as->GetId());
        entries[1].Set(wxACCEL_CTRL, (int) 'Q', menu_item_quit->GetId());
        entries[2].Set(wxACCEL_SHIFT | wxACCEL_CTRL, (int) 'A', menu_item_about->GetId());
        wxAcceleratorTable accel(3, entries);
        this->SetAcceleratorTable(accel);

        //event binding
        checkbox_->Bind(wxEVT_CHECKBOX, &MythicalGame::OnCheckboxToggle, this);
        listbox_units_->Bind(wxEVT_COMMAND_LISTBOX_SELECTED,&MythicalGame::OnListboxClicked,this);

        menu_help->Bind(wxEVT_MENU,&MythicalGame::OnMenuAbout,this,menu_item_about->GetId());
        menu_file->Bind(wxEVT_MENU,&MythicalGame::OnMenuSaveAs,this,menu_item_save_as->GetId());
        menu_file->Bind(wxEVT_MENU,&MythicalGame::OnMenuQuit,this,menu_item_quit->GetId());

        //boxsizers
        wxBoxSizer* horizontal_sizer = new wxBoxSizer(wxHORIZONTAL);
        wxBoxSizer* sizer_left = new wxBoxSizer(wxVERTICAL);
        wxBoxSizer* sizer_middle = new wxBoxSizer(wxVERTICAL);
        wxBoxSizer* sizer_right = new wxBoxSizer(wxVERTICAL);
        
        horizontal_sizer->Add(sizer_left,0,wxEXPAND | wxRIGHT,5);    
        horizontal_sizer->Add(sizer_middle,0,wxEXPAND);
        horizontal_sizer->Add(sizer_right,0,wxEXPAND | wxALL, 5);

        sizer_left->Add(listbox_units_,0,wxEXPAND);
        sizer_left->Add(checkbox_,0,wxEXPAND);

        sizer_middle->Add(title_,0,wxEXPAND);
        sizer_middle->Add(hp_,0,wxEXPAND);
        sizer_middle->Add(moves_,0,wxEXPAND);
        sizer_middle->Add(weapons_,0,wxEXPAND);
        sizer_middle->Add(listctrl_weapons_,1,wxEXPAND);

        sizer_right->Add(image_bitmap_,0,static_cast<int>(wxEXPAND) | static_cast<int>(wxALL), 5);

        panel_->SetSizer(horizontal_sizer);
        panel_->Layout();
}

void mg::MythicalGame::OnCheckboxToggle(wxCommandEvent& event){
    wxSize size = GetSize();
    
    if (event.IsChecked()) {
        title_->Show();
        hp_->Show();
        moves_->Show();
        weapons_->Show();
        listctrl_weapons_->Show();
        SetSize(size.GetWidth() + 360, size.GetHeight());
    } 
    else {
        title_->Hide();
        hp_->Hide();
        moves_->Hide();
        weapons_->Hide();
        listctrl_weapons_->Hide();;
        SetSize(size.GetWidth() - 360, size.GetHeight());
    }
    panel_->Layout();  // update the layout
}

void mg::MythicalGame::OnListboxClicked(wxCommandEvent& event){
    wxImage image;

    switch(event.GetSelection()){       //  Get listbox selection if single-choice
        case 0:
            current_unit_ = drake_burner_;
            image.LoadFile("../images/drake_burner.png", wxBITMAP_TYPE_PNG);
            break;
        case 1:
            current_unit_ = dwarvish_fighter_;
            image.LoadFile("../images/dwarvish_fighter.png", wxBITMAP_TYPE_PNG);
            break;
        case 2:
            current_unit_ = elvish_archer_;
            image.LoadFile("../images/elvish_archer.png", wxBITMAP_TYPE_PNG);
            break;
        default:
            return;
    }   
            //wxString return
    title_->SetLabel(current_unit_->type_name());
    hp_->SetLabel("HP: " + std::to_string(current_unit_->max_health()));
    moves_->SetLabel("Moves: " + std::to_string(current_unit_->moves()));

    listctrl_weapons_->DeleteAllItems();
    for(const auto& w : current_unit_->weapons()){
        wxVector<wxVariant> weapon_data;
        weapon_data.push_back(w.name());
        weapon_data.push_back(std::to_string(w.damage()) + "x" + std::to_string(w.strikes()));
        weapon_data.push_back(w.is_ranged());
        weapon_data.push_back(w.type());
        listctrl_weapons_->AppendItem(weapon_data);
    }

    //set unit image
    image.Rescale(450, 450, wxIMAGE_QUALITY_HIGH);
    wxBitmap bitmap(image);
    image_bitmap_->SetBitmap(bitmap);
}

void mg::MythicalGame::OnMenuSaveAs([[maybe_unused]] wxCommandEvent& event){
    
    std::string suggested_name = "../" + current_unit_->type_name() + ".md";

    wxFileDialog saveFileDialog(panel_, "Save As", "", suggested_name,
                            "Markdown files (*.md)|*.md|All files (*.*)|*.*", 
                            wxFD_SAVE | wxFD_OVERWRITE_PROMPT);

    if (saveFileDialog.ShowModal() == wxID_CANCEL) return;

    std::string file_path = saveFileDialog.GetPath().ToStdString();
    
    std::ofstream md_file(file_path);
    if (!md_file.is_open()) return;

    md_file << "# " + current_unit_->type_name() + "\n";
    md_file << "HP: " + std::to_string(current_unit_->max_health()) + "\n";
    md_file << "Moves: " + std::to_string(current_unit_->moves()) + "\n\n";
    md_file << "## Weapons\n";
    md_file << "| Name | Strikes | Range | Type |\n";
    md_file << "| ---- | ------- | ----- | ---- |\n";

    for(const auto& w : current_unit_->weapons()){
        md_file << "| " + w.name() + " | " + std::to_string(w.damage()) + 
        "x" + std::to_string(w.strikes()) + " | " + w.is_ranged() + " | " + w.type() + " |\n";
    }

    md_file.close();
}

void mg::MythicalGame::OnMenuQuit([[maybe_unused]] wxCommandEvent& event){
    wxExit();
}

void mg::MythicalGame::OnMenuAbout([[maybe_unused]] wxCommandEvent& event){
    wxMessageBox("This is a viewer for creatures in a mythical game.", "About Unit GUI", wxOK | wxICON_INFORMATION); // popup
}
