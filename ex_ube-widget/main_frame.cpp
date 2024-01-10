#include <wx/wx.h>
#include "main_frame.h"
#include <wx/spinctrl.h>

MainFrame::MainFrame(const wxString& title):wxFrame(nullptr,wxID_ANY,title)
{        wxPanel* panel = new wxPanel(this);
        wxButton* button = new wxButton(panel, wxID_ANY, "button", wxPoint(10,50), wxSize(100, 35));
        wxCheckBox* checkbox1 = new wxCheckBox(panel,wxID_ANY, "checkbox", wxPoint(140, 50));
        wxStaticText* staticText = new wxStaticText(panel, wxID_ANY, "Drake Burner", wxPoint(260, 50), wxSize(300,70), wxALIGN_CENTRE_HORIZONTAL);
         staticText->SetBackgroundColour(*wxLIGHT_GREY);
        wxTextCtrl* inputText = new wxTextCtrl(panel, wxID_ANY,"input-editable", wxPoint(20, 130), wxSize(150,-1));
        wxSlider* slider = new wxSlider(panel, wxID_ANY, 35, 0, 100, wxPoint(220, 130), wxSize(150, 35), wxSL_VALUE_LABEL);
        wxGauge* gauge = new wxGauge(panel, wxID_ANY, 100, wxPoint(400,130), wxSize(200,-1));
        gauge->SetValue(60);

        // ovo je dropdown list
        wxArrayString fighters;
        fighters.Add("Drake Burner");
        fighters.Add("dwarvish_fighter");
        fighters.Add("Elvisch Acher");
        wxChoice* choice = new wxChoice(panel, wxID_ANY, wxPoint(20, 180), wxSize(160,-1), fighters);
        choice->Select(0);
        wxSpinCtrl* spinctrl = new wxSpinCtrl(panel,wxID_ANY,"", wxPoint(200,180), wxSize(160, -1));
          spinctrl->SetBackgroundColour(*wxLIGHT_GREY);
        wxListBox* listbox = new wxListBox(panel, wxID_ANY, wxPoint(380,180), wxSize(160, 120), fighters);
        listbox->SetBackgroundColour(*wxLIGHT_GREY);
        // mihi used .push_back() on wxListBox, and here .Add()
        wxRadioBox* radioBox = new wxRadioBox(panel, wxID_ANY,"Radio Buttons:", wxPoint(20,280),wxDefaultSize, fighters, 1);








}

