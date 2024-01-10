#include <cmath> // Include the <cmath> header for math functions
#include "simple_calculator.hpp"

double SimpleCalculator::calculate(double number, char next_operator) {
  switch (operator_) {
    case '+':
      current_ += number;
      break;
    case '-':
      current_ -= number;
      break;
    case '*':
      current_ *= number;
      break;
    case '/':
      current_ /= number;
      break;
    case '=':
    case 0:
      current_ = number;
      break;
    case 's': // 's' for sine
      current_ = std::sin(number);
      break;
    case 'c': // 'c' for cosine
      current_ = std::cos(number);
      break;
    case 'l': // 'l' for natural logarithm (ln)
      current_ = std::log(number);
      break;
    case 'q': // 'q' for square root
      current_ = std::sqrt(number);
      break;
  }
  operator_ = next_operator;
  return current_;
}

void SimpleCalculator::reset() {
  current_ = 0;
  operator_ = 0;
}
