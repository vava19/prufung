#pragma once
#include <wx/wx.h>


class MainFrame: public wxFrame {
public:
     MainFrame(const wxString& title);

private:
     void CreateControls();
     void BindEventHadnlers();

     void OnClickButtonAdd(wxCommandEvent& evt); 
     void OnEnterInput(wxCommandEvent& evt);
     void OnListKeyDown(wxKeyEvent& evt);
     void OnClearButtonClicked(wxCommandEvent& evt);


     //helper
     void AddTaskFormInput(); //setter
     void DeleteSelectedTask();
     // void MoveSelectedTask(int offset);
     // void SwapTasks(int i, int j);
     

     wxPanel* panel;
     wxStaticText* headLineText;
     wxTextCtrl* inputField;
     wxButton* addButton;
     wxCheckListBox* checkListBox;
     wxButton* clearButton;

};








