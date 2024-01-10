#pragma once

#include <memory>
#include <string>
#include <fstream>
#include <wx/wx.h>
#include <wx/dataview.h>
#include <wx/filedlg.h>
#include "unit.hpp"


namespace mg{ // mythical game

class MythicalGame: public wxFrame {
public:
    MythicalGame(const wxString& title);

private:
    wxPanel* panel_ = nullptr;

    // std::shared_ptr<DrakeBurner> drake_burner_ = std::make_shared<DrakeBurner>("DrakeBurner1");
    // std::shared_ptr<DwarvishFighter> dwarvish_fighter_ = std::make_shared<DwarvishFighter>("DwarvishFighter1");
    // std::shared_ptr<ElvishArcher> elvish_archer_ = std::make_shared<ElvishArcher>("ElvishArcher1");
    // std::shared_ptr<Unit> current_unit_;

//without smart pointers:  --> raw pointers
//ovdje su objekt od classe kreirani -> jer argument je "name"
DrakeBurner* drake_burner_ = new DrakeBurner("DrakeBurner1");
DwarvishFighter* dwarvish_fighter_ = new DwarvishFighter("DwarvishFighter1");
ElvishArcher* elvish_archer_ = new ElvishArcher("ElvishArcher1");
Unit* current_unit_;



    
    wxArrayString items_;  //zasto ne moze sa  pointr. "*"
    wxListBox* listbox_units_ = nullptr;
    
    wxCheckBox* checkbox_ = nullptr;
    
    wxStaticText* title_;
    wxStaticText* hp_;
    wxStaticText* moves_;
    wxStaticText* weapons_;
    
    wxDataViewListCtrl* listctrl_weapons_ = nullptr; // control for displaying tabular data in a list format with multiple columns
    
    wxStaticBitmap* image_bitmap_ = nullptr; // for displaying static images
    

    void OnListboxClicked(wxCommandEvent& event);
    void OnCheckboxToggle(wxCommandEvent& event);

    void OnMenuAbout(wxCommandEvent& event);
    void OnMenuSaveAs(wxCommandEvent& event);
    void OnMenuQuit(wxCommandEvent& event);
};

} // namespace mg