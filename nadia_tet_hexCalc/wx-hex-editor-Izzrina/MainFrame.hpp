#ifndef MAINFRAME_HPP
#define MAINFRAME_HPP

#include <wx/wx.h>
#include <iostream>
#include <iomanip>


class MainFrame : public wxFrame {

  public:

      MainFrame(const wxString& title);

  private:

    wxTextCtrl *textField;
    wxTextCtrl *hexField;

    /*Converts a std::string into a wxString consisting of hexadecimal values. Each character in the input string is replaced by its two-digit hexadecimal representation.*/
    wxString textToHex(const std::string& input);

    /*Converts a wxString consisting of hexadecimal values into a wxString containing the corresponding ASCII characters*/
    wxString hexToText(wxString input);

    /*It retrieves the value from the text field and converts it to a hex string. The resulting hex string is then set as the value of the hex field.*/
    void onTextFieldChanged(wxCommandEvent& evt);

    /*It retrieves the value from the hex field and converts it to a text string. The resulting text string is then set as the value of the text field*/
    void onHexFieldChanged(wxCommandEvent& evt);

    /*Clears the contents of both the text field and the hex field*/
    void onClearButton(wxCommandEvent& evt);

    /*Opens a file dialog to allow the user to select a text file to import. The selected file is then loaded into the text field.*/
    void onImportTextFileButton(wxCommandEvent& evt);

    /*Opens a file dialog to allow the user to select a file containing hexadecimal values to import. The selected file is then loaded into the hex field.*/
    void onImportHexFileButton(wxCommandEvent& evt);

    /*Opens a file dialog to allow the user to specify the file name and location to save the text. The contents of the text field are then saved to the selected file.*/
    void onExportTextFileButton(wxCommandEvent& evt);

    /*Opens a file dialog to allow the user to specify the file name and location to save the text. The contents of the hex field are then saved to the selected file.*/
    void onExportHexFileButton(wxCommandEvent& evt);
};

#endif

