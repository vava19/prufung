#include "calc_ui.hpp"

#include <cstdlib>
#include <iostream>
#include <string>

#include <wx/wx.h>
#include <wx/spinctrl.h>


CalculatorUI::CalculatorUI(const wxString& title)
  : wxFrame(nullptr, wxID_ANY, title) {
  wxPanel* panel = new wxPanel(this);

  wxBoxSizer* vertical_sizer = new wxBoxSizer(wxVERTICAL);
  wxBoxSizer* row_1 = new wxBoxSizer(wxHORIZONTAL);
  wxBoxSizer* row_2 =new wxBoxSizer(wxHORIZONTAL);
  wxBoxSizer* row_3 =new wxBoxSizer(wxHORIZONTAL);
  wxBoxSizer* row_4 =new wxBoxSizer(wxHORIZONTAL);
  wxBoxSizer* row_5 =new wxBoxSizer(wxHORIZONTAL);
  vertical_sizer->Add(row_1, 1, wxEXPAND);
  vertical_sizer->Add(row_2, 1, wxEXPAND);
  vertical_sizer->Add(row_3, 1, wxEXPAND);
  vertical_sizer->Add(row_4, 1, wxEXPAND);
  vertical_sizer->Add(row_5, 1, wxEXPAND);

  display_ = new wxTextCtrl(panel, wxID_ANY, wxEmptyString,
                            wxDefaultPosition, wxDefaultSize,
                            wxTE_READONLY|wxTE_RIGHT);
  row_1->Add(display_, 1, wxEXPAND);

  button_0_ = new wxButton(panel, wxID_ANY, "0");
  button_1_ = new wxButton(panel, wxID_ANY, "1");
  button_2_ = new wxButton(panel, wxID_ANY, "2");
  button_3_ = new wxButton(panel, wxID_ANY, "3");
  button_4_ = new wxButton(panel, wxID_ANY, "4");
  button_5_ = new wxButton(panel, wxID_ANY, "5");
  button_6_ = new wxButton(panel, wxID_ANY, "6");
  button_7_ = new wxButton(panel, wxID_ANY, "7");
  button_8_ = new wxButton(panel, wxID_ANY, "8");
  button_9_ = new wxButton(panel, wxID_ANY, "9");
  button_add_= new wxButton(panel, wxID_ANY, "+");
  button_substract_= new wxButton(panel, wxID_ANY, "-");
  button_multiply_= new wxButton(panel, wxID_ANY, "*");
  button_divide_= new wxButton(panel, wxID_ANY, "/");
  button_clear_ = new wxButton(panel, wxID_ANY, "AC");
  button_solve_ = new wxButton(panel, wxID_ANY, "=");

  // added buttons
  button_sin = new wxButton(panel, wxID_ANY, "sin");
  button_cos = new wxButton(panel, wxID_ANY, "cos");
  button_ln = new wxButton(panel, wxID_ANY, "ln");
  button_sqrt = new wxButton(panel, wxID_ANY, "sqrt");

//   ----

  row_2->Add(button_7_, 1, wxEXPAND);
  row_2->Add(button_8_, 1, wxEXPAND);
  row_2->Add(button_9_, 1, wxEXPAND);
  row_2->Add(button_divide_, 1, wxEXPAND);

  row_3->Add(button_4_, 1, wxEXPAND);
  row_3->Add(button_5_, 1, wxEXPAND);
  row_3->Add(button_6_, 1, wxEXPAND);
  row_3->Add(button_multiply_, 1, wxEXPAND);

  row_4->Add(button_1_, 1, wxEXPAND);
  row_4->Add(button_2_, 1, wxEXPAND);
  row_4->Add(button_3_, 1, wxEXPAND);
  row_4->Add(button_substract_, 1, wxEXPAND);

  row_5->Add(button_clear_, 1, wxEXPAND);
  row_5->Add(button_0_, 1, wxEXPAND);
  row_5->Add(button_solve_, 1, wxEXPAND);
  row_5->Add(button_add_, 1, wxEXPAND);

// added 1
  row_2->Add(button_sin, 1, wxEXPAND);
  row_3->Add(button_cos, 1, wxEXPAND);
  row_4->Add(button_ln, 1, wxEXPAND);
  row_5->Add(button_sqrt, 1, wxEXPAND);

  panel->SetSizer(vertical_sizer); // vertical_sizer dem panel als Sizer zugewiesen.
  this->SetMinSize(wxSize(row_2->GetMinSize().GetWidth(), 
                          vertical_sizer->GetMinSize().GetHeight() + 30));  // nasty

  panel->Layout(); // um das Layout der Controls auf einem Fenster oder Panel zu aktualisieren

  button_0_->Bind(wxEVT_BUTTON, &CalculatorUI::on_number_clicked, this);
  button_1_->Bind(wxEVT_BUTTON, &CalculatorUI::on_number_clicked, this);
  button_2_->Bind(wxEVT_BUTTON, &CalculatorUI::on_number_clicked, this);
  button_3_->Bind(wxEVT_BUTTON, &CalculatorUI::on_number_clicked, this);
  button_4_->Bind(wxEVT_BUTTON, &CalculatorUI::on_number_clicked, this);
  button_5_->Bind(wxEVT_BUTTON, &CalculatorUI::on_number_clicked, this);
  button_6_->Bind(wxEVT_BUTTON, &CalculatorUI::on_number_clicked, this);
  button_7_->Bind(wxEVT_BUTTON, &CalculatorUI::on_number_clicked, this);
  button_8_->Bind(wxEVT_BUTTON, &CalculatorUI::on_number_clicked, this);
  button_9_->Bind(wxEVT_BUTTON, &CalculatorUI::on_number_clicked, this);


  

  button_clear_->Bind(wxEVT_BUTTON, &CalculatorUI::on_clear_clicked,
                      this);
  button_add_->Bind(wxEVT_BUTTON, &CalculatorUI::on_operation_clicked, this);
  button_substract_->Bind(wxEVT_BUTTON, &CalculatorUI::on_operation_clicked, this);
  button_multiply_->Bind(wxEVT_BUTTON, &CalculatorUI::on_operation_clicked, this);
  button_divide_->Bind(wxEVT_BUTTON, &CalculatorUI::on_operation_clicked, this);
  button_solve_->Bind(wxEVT_BUTTON, &CalculatorUI::on_operation_clicked, this);
  // added bind
   button_sin->Bind(wxEVT_BUTTON, &CalculatorUI::on_function_clicked, this);
  button_cos->Bind(wxEVT_BUTTON, &CalculatorUI::on_function_clicked, this);
  button_ln->Bind(wxEVT_BUTTON, &CalculatorUI::on_function_clicked, this);
  button_sqrt->Bind(wxEVT_BUTTON, &CalculatorUI::on_function_clicked, this);
  
  
  }

void CalculatorUI::on_number_clicked (wxCommandEvent& evt) {
  if (has_used_operator_) display_->Clear();
  wxButton* b = static_cast<wxButton*>(evt.GetEventObject());
  std::string s(b->GetLabel().c_str());
  display_->AppendText(s);
  has_used_operator_ = false;
}

void CalculatorUI::on_operation_clicked(wxCommandEvent& evt) {
  double display_value = atof(display_->GetValue().c_str());
  wxButton* b = static_cast<wxButton*>(evt.GetEventObject());
  char op = b->GetLabel().c_str()[0];
  double result(calculator_.calculate(display_value, op));
  display_->SetValue(std::to_string(result));
  has_used_operator_ = true;
}


void CalculatorUI::on_clear_clicked(wxCommandEvent& evt) {
  calculator_.reset();
  display_->Clear();
}



void CalculatorUI::on_function_clicked(wxCommandEvent& evt) {
  double display_value = atof(display_->GetValue().c_str());
  wxButton* b = static_cast<wxButton*>(evt.GetEventObject());
  std::string label = std::string(b->GetLabel());
  
  // Perform the corresponding calculation based on the button label
  if (label == "sin") {
    display_value = std::sin(display_value);
  } else if (label == "cos") {
    display_value = std::cos(display_value);
  } else if (label == "ln") {
    display_value = std::log(display_value);
  } else if (label == "sqrt") {
    display_value = std::sqrt(display_value);
  }

  display_->SetValue(std::to_string(display_value));
  has_used_operator_ = true;
}