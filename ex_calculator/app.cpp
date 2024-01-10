#include "app.hpp"
#include <wx/wx.h>
#include "calc_ui.hpp"

bool App::OnInit() {
  CalculatorUI* calculator = new CalculatorUI("wxCalculator");
  calculator->SetClientSize(800, 600);
  calculator->Center();
  calculator->Show();
  return true;
}

wxIMPLEMENT_APP(App);
