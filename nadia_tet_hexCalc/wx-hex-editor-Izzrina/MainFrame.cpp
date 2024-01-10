#include "MainFrame.hpp"

#include <wx/wx.h>
#include <iostream>
#include <iomanip>


MainFrame::MainFrame(const wxString& title): wxFrame(nullptr, wxID_ANY, title) {


  wxBoxSizer *mainSizer = new wxBoxSizer(wxVERTICAL);

  wxStaticText *labelText = new wxStaticText( this, wxID_ANY, "Text:", wxDefaultPosition, wxDefaultSize, 0 );
  mainSizer->Add(labelText,  1,  wxEXPAND |  wxALL,  10);

  textField = new wxTextCtrl(this,  wxID_ANY,  "",  wxDefaultPosition,  wxDefaultSize, wxTE_MULTILINE);
  textField->Bind(wxEVT_TEXT, &MainFrame::onTextFieldChanged, this);

  mainSizer->Add(textField,  7,  wxEXPAND |  wxALL,  10);

  wxStaticText *labelHex = new wxStaticText( this, wxID_ANY, "Hexadecimal:", wxDefaultPosition, wxDefaultSize, 0 );
  mainSizer->Add(labelHex,  1,  wxEXPAND |  wxALL,  10);

  hexField = new wxTextCtrl(this,  wxID_ANY,  "",  wxDefaultPosition,  wxDefaultSize, wxTE_MULTILINE);
  hexField->Bind(wxEVT_TEXT, &MainFrame::onHexFieldChanged, this);

  wxTextValidator hexValidator(wxFILTER_INCLUDE_CHAR_LIST);
  hexValidator.SetCharIncludes("0123456789abcdefABCDEF"); // Erlaubte Zeichen: Zahlen (0-9) und die Buchstaben a-f oder A-F (hexadezimal)
  hexField->SetValidator(hexValidator);

  mainSizer->Add(hexField,  7,  wxEXPAND |  wxALL,  10);

  wxButton *clearButton = new wxButton(this,  wxID_ANY,  "CLEAR",  wxDefaultPosition,  wxDefaultSize,  1);
  clearButton->Bind(wxEVT_BUTTON, &MainFrame::onClearButton, this);
  mainSizer->Add(clearButton,  1, wxEXPAND |  wxALL,  10);

  wxBoxSizer * buttonSizer = new wxBoxSizer(wxHORIZONTAL);

  wxButton *importTextFileButton = new wxButton(this,  wxID_ANY,  "Import Text File",  wxDefaultPosition,  wxDefaultSize,  1);
  importTextFileButton->Bind(wxEVT_BUTTON, &MainFrame::onImportTextFileButton, this);
  buttonSizer->Add(importTextFileButton,  1,  wxALL,  5);

  wxButton *importHexFileButton = new wxButton(this,  wxID_ANY,  "Import Hex File",  wxDefaultPosition,  wxDefaultSize,  1);
  importHexFileButton->Bind(wxEVT_BUTTON, &MainFrame::onImportHexFileButton, this);
  buttonSizer->Add(importHexFileButton,  1,  wxALL,  5);

  wxButton *exportTextFileButton = new wxButton(this,  wxID_ANY,  "Export Text File",  wxDefaultPosition,  wxDefaultSize,  1);
  exportTextFileButton->Bind(wxEVT_BUTTON, &MainFrame::onExportTextFileButton, this);
  buttonSizer->Add(exportTextFileButton,  1,  wxALL,  5);

  wxButton *exportHexFileButton = new wxButton(this,  wxID_ANY,  "Export Hex File",  wxDefaultPosition,  wxDefaultSize,  1);
  exportHexFileButton->Bind(wxEVT_BUTTON, &MainFrame::onExportHexFileButton, this);
  buttonSizer->Add(exportHexFileButton,  1,  wxALL,  5);

  mainSizer->Add(buttonSizer,  1,  wxEXPAND | wxALL,  10);

  this->SetSizer(mainSizer);

  };

/**
 * Converts a std::string into a wxString consisting of hexadecimal values.
 * Each character in the input string is replaced by its two-digit hexadecimal representation.
 *
 * @param input The input string to be converted.
 * @return The converted wxString containing the hexadecimal values.
 */
  wxString MainFrame::textToHex(const std::string& input)
  {
    wxString output = "";
    for (char ch : input) {
      output.Append(wxString::Format("%02X", static_cast<int>(ch)));
    }
    return output;
  }

/**
 * Converts a wxString consisting of hexadecimal values into a wxString containing the corresponding ASCII characters.
 * The hexadecimal values in the input string are converted into ASCII characters in pairs and appended to the output string.
 * The conversion only takes place if the length of the input string is even, to ensure that the hexadecimal values are paired.
 *
 * @param input The input string containing the hexadecimal values.
 * @return The converted wxString containing the ASCII characters.
 */
  wxString MainFrame::hexToText(wxString input)
  {
    wxString output = "";
    wxString hexValue;

    if(input.length() %2 == 0){

      for (size_t i = 0; i < input.length(); i += 2)
      {
          hexValue = input.Mid(i, 2);
          long asciiValue;
          hexValue.ToLong(&asciiValue, 16);
          output.Append(static_cast<wxChar>(asciiValue));
      }
    }
    return output;
  }

  /**
 * @brief Event handler for the text field change event.
 *
 * This function is called when the text field's content is changed.
 * It retrieves the value from the text field and converts it to a hex string.
 * The resulting hex string is then set as the value of the hex field.
 *
 * @param evt The event object containing information about the event.
 */

  void MainFrame::onTextFieldChanged(wxCommandEvent& evt)
  {
    if (textField->HasFocus()) {
      std::string textInput = std::string(textField->GetValue().mb_str(wxConvUTF8));
      hexField->SetValue(textToHex(textInput));
    }
  }

   /**
 * @brief Event handler for the hex field change event.
 *
 * This function is called when the hex field's content is changed.
 * It retrieves the value from the hex field and converts it to a text string.
 * The resulting text string is then set as the value of the text field.
 *
 * @param evt The event object containing information about the event.
 */
  void MainFrame::onHexFieldChanged(wxCommandEvent& evt) {
    if (hexField->HasFocus()) {
      wxString hexInput = hexField->GetValue();
      textField->SetValue(hexToText(hexInput));
    }
   }

/**
 * @brief Event handler for the clear button event.
 *
 * This function is called when the clear button is clicked.
 * It clears the contents of both the text field and the hex field.
 *
 * @param evt The event object containing information about the event.
 */
  void MainFrame::onClearButton(wxCommandEvent& evt)
  {
    textField->Clear();
    hexField->Clear();
  }

  /**
 * @brief Event handler for the import text file button event.
 *
 * This function is called when the import text file button is clicked.
 * It opens a file dialog to allow the user to select a text file to import.
 * The selected file is then loaded into the text field.
 *
 * @param evt The event object containing information about the event.
 */
  void MainFrame::onImportTextFileButton(wxCommandEvent& evt)
  {

    std::string filename = "text.txt";

    wxFileDialog openFileDialog(this, _("Open XYZ file"), "", "",
                       "Alle Dateien (*.*)|*.*", wxFD_OPEN|wxFD_FILE_MUST_EXIST);
    if (openFileDialog.ShowModal() == wxID_CANCEL){
        return;
    }

    filename = std::string(openFileDialog.GetPath().mb_str(wxConvUTF8));

    textField->SetFocus();
    textField->LoadFile(filename);
  }

/**
 * @brief Event handler for the import hex file button event.
 *
 * This function is called when the import hex file button is clicked.
 * It opens a file dialog to allow the user to select a file containing hexadecimal values to import.
 * The selected file is then loaded into the hex field.
 *
 * @param evt The event object containing information about the event.
 */
  void MainFrame::onImportHexFileButton(wxCommandEvent& evt)
  {

    std::string filename = "hex.txt";

    wxFileDialog openFileDialog(this, _("Open XYZ file"), "", "",
                       "Alle Dateien (*.*)|*.*", wxFD_OPEN|wxFD_FILE_MUST_EXIST);
    if (openFileDialog.ShowModal() == wxID_CANCEL){
        return;
    }

    filename = std::string(openFileDialog.GetPath().mb_str(wxConvUTF8));

    hexField->SetFocus();
    hexField->LoadFile(filename);
  }

  /**
 * @brief Event handler for the export text file button event.
 *
 * This function is called when the export text file button is clicked.
 * It opens a file dialog to allow the user to specify the file name and location to save the text.
 * The contents of the text field are then saved to the selected file.
 *
 * @param evt The event object containing information about the event.
 */
  void MainFrame::onExportTextFileButton(wxCommandEvent& evt)
  {

    std::string filename = "text.txt";

    wxFileDialog fileDialog(this, "Text speichern", wxEmptyString, wxEmptyString,
                                "Textdateien (*.txt)|*.txt", wxFD_SAVE | wxFD_OVERWRITE_PROMPT);

    if (fileDialog.ShowModal() == wxID_CANCEL){
        return;  // Abbruch, wenn der Dialog geschlossen wird
    }
    filename = fileDialog.GetPath();

    textField->SaveFile(filename);
  }

  /**
 * @brief Event handler for the export hex file button event.
 *
 * This function is called when the export hex file button is clicked.
 * It opens a file dialog to allow the user to specify the file name and location to save the hex data.
 * The contents of the hex field are then saved to the selected file.
 *
 * @param evt The event object containing information about the event.
 */
  void MainFrame::onExportHexFileButton(wxCommandEvent& evt)
  {

    std::string filename = "hex.txt";

    wxFileDialog fileDialog(this, "Text speichern", wxEmptyString, wxEmptyString,
                                "Textdateien (*.txt)|*.txt", wxFD_SAVE | wxFD_OVERWRITE_PROMPT);

    if (fileDialog.ShowModal() == wxID_CANCEL){
        return;  // Abbruch, wenn der Dialog geschlossen wird
    }
    filename = fileDialog.GetPath();

    hexField->SaveFile(filename);
  }

