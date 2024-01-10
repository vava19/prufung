// ovo je main_frame.h  --> wxFrame
#ifndef CALC_UI_HPP
#define CALC_UI_HPP

#include <wx/wx.h>

#include "simple_calculator.hpp"

class CalculatorUI : public wxFrame {
public:
  CalculatorUI(const wxString& title);
private:

  SimpleCalculator calculator_; // pravi instanzu 
  bool has_used_operator_;

  wxTextCtrl* display_;

  wxButton* button_0_;
  wxButton* button_1_;
  wxButton* button_2_;
  wxButton* button_3_;
  wxButton* button_4_;
  wxButton* button_5_;
  wxButton* button_6_;
  wxButton* button_7_;
  wxButton* button_8_;
  wxButton* button_9_;

  wxButton* button_add_;
  wxButton* button_substract_;
  wxButton* button_multiply_;
  wxButton* button_divide_;
  wxButton* button_clear_;
  //  -----added
  wxButton* button_sin;
  wxButton* button_cos;
  wxButton* button_ln;
  wxButton* button_sqrt;

  wxButton* button_solve_;

  void on_number_clicked(wxCommandEvent& evt);
  void on_clear_clicked(wxCommandEvent& evt);
  void on_operation_clicked(wxCommandEvent& evt);
  void on_function_clicked(wxCommandEvent& evt);
};

#endif  // CALC_UI_HPP
