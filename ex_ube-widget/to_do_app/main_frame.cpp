#include <wx/wx.h>
#include "task.h"
#include "main_frame.h"
#include <vector>
#include <string>

MainFrame::MainFrame(const wxString& title) : wxFrame(nullptr,wxID_ANY, title)
{
   CreateControls();
   BindEventHadnlers();

};


void MainFrame::CreateControls() {

    wxFont headLineFont(wxFontInfo(wxSize(0, 36)).Bold());
    wxFont mainFont(wxFontInfo(wxSize(0, 24)));

    panel = new wxPanel(this);
    panel->SetFont(mainFont);

    headLineText = new wxStaticText(panel, wxID_ANY, "TO-DO List", wxPoint(0,22), wxSize(800, 50), wxALIGN_CENTER_HORIZONTAL);
    headLineText->SetLabel("something else");  // must be string sonst convert:  std::to_string()
    headLineText->SetFont(headLineFont);
    //headLineText->SetBackgroundColour(*wxRED);

    

    inputField = new wxTextCtrl(panel, wxID_ANY, "", wxPoint(100, 80), wxSize(495,35), wxTE_PROCESS_ENTER);
    addButton = new wxButton(panel, wxID_ANY, "Add", wxPoint(600,80), wxSize(100, 35));
    checkListBox = new wxCheckListBox(panel, wxID_ANY, wxPoint(100, 120), wxSize(600, 400));
    clearButton = new wxButton(panel, wxID_ANY, "Clear", wxPoint(100, 525), wxSize(100, 35));

    checkListBox->SetBackgroundColour(*wxLIGHT_GREY);

}

void MainFrame::BindEventHadnlers() {

    addButton->Bind(wxEVT_BUTTON, &MainFrame::OnClickButtonAdd, this);
    inputField->Bind(wxEVT_TEXT_ENTER, &MainFrame::OnEnterInput, this);
    checkListBox->Bind(wxEVT_KEY_DOWN, &MainFrame::OnListKeyDown, this);
    clearButton->Bind(wxEVT_BUTTON, &MainFrame::OnClearButtonClicked, this);

}

void MainFrame::OnClickButtonAdd(wxCommandEvent& evt) {
        AddTaskFormInput();

}

void MainFrame::OnEnterInput(wxCommandEvent& evt) {
        AddTaskFormInput();

}


void MainFrame::AddTaskFormInput() {
        wxString description = inputField->GetValue();  //getter ima return wxString

        if(!description.IsEmpty()) {
            checkListBox->Insert(description, checkListBox->GetCount());  //GetCount()specifies the position at which the new item will be inserted.--end of the list
            inputField->Clear();
        } 
        inputField->SetFocus();

}

void MainFrame::OnListKeyDown(wxKeyEvent& evt){
    switch (evt.GetKeyCode())
        {
        case WXK_DELETE:
            DeleteSelectedTask();
            break;   
        // case WXK_UP:
        //     MoveSelectedTask(-1);
        //     break;
        // case WXK_DOWN:
        //     MoveSelectedTask(1);
            break;
        default:
            break;
        }
}


void MainFrame::DeleteSelectedTask() {
    int selectedIndex = checkListBox->GetSelection();
    if(selectedIndex == wxNOT_FOUND) {
        return;
    }
    checkListBox->Delete(selectedIndex);

}



// void MainFrame::MoveSelectedTask(int offset) {

//     int selectedIndex = checkListBox->GetSelection();

//     if(selectedIndex == wxNOT_FOUND) {
//         return;
//     }
//     int newIndex = selectedIndex + offset;
//     if(newIndex >=0 && newIndex < checkListBox->GetCount()) {
//         SwapTasks(selectedIndex, newIndex);
//         checkListBox->SetSelection(newIndex, true);
//     }

// }


//      void MainFrame::SwapTasks(int i, int j) {     // mogao zvati wxSwap

//      }


 void MainFrame::OnClearButtonClicked(wxCommandEvent& evt) {
    if(checkListBox->IsEmpty()) {
        return;
    }
    wxMessageDialog dialog(this, "Aru you sure you want to delete", "raza",
     wxYES_NO | wxCANCEL);
    int result = dialog.ShowModal();  //display dialog and wait for the user. returns integer 

    if(result == wxID_YES) {
        checkListBox->Clear();
    }
    
 }