#ifndef SIMPLE_CALCULATOR_HPP
#define SIMPLE_CALCULATOR_HPP

class SimpleCalculator {
public:
  double calculate(double number, char next_operator);
  void reset();
private:
  double current_ = 0;
  char operator_ = 0;
};

#endif  // SIMPLE_CALCULATOR_HPP
