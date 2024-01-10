	
		#include "simple_calculator.hpp"

#define CATCH_CONFIG_MAIN
#include "catch_amalgamated.hpp"


TEST_CASE("Simple Calculator works correctly", "[calculator]") {
  SimpleCalculator calc;

  SECTION("Addition", "[plus]") {
    REQUIRE(calc.calculate(5, '+') == 5);
    REQUIRE(calc.calculate(5, '+') == 10);
    REQUIRE(calc.calculate(1, '+') == 11);
    REQUIRE(calc.calculate(0, '+') == 11);
    REQUIRE(calc.calculate(4, '+') == 15);
  }

  SECTION("Substraction", "[minus]") {
    REQUIRE(calc.calculate(100, '-') == 100);
    REQUIRE(calc.calculate(5, '-') == 95);
    REQUIRE(calc.calculate(100, '-') == -5);
  }

  SECTION("Multiplication", "[times]") {
    REQUIRE(calc.calculate(100, '*') == 100);
    REQUIRE(calc.calculate(5, '*') == 500);
    REQUIRE(calc.calculate(-1.5, '=') == -750);
    REQUIRE(calc.calculate(0, '=') == 0);
  }

  SECTION("Division", "[divide]") {
    REQUIRE(calc.calculate(100, '/') == 100);
    REQUIRE(calc.calculate(10, '/') == 10);
    REQUIRE(calc.calculate(-2.5, '=') == -4);
  }

  SECTION("Combination", "[all]") {
    REQUIRE(calc.calculate(100, '+') == 100);
    REQUIRE(calc.calculate(100, '-') == 200);
    REQUIRE(calc.calculate(40, '/') == 160);
    REQUIRE(calc.calculate(4, '*') == 40);
    REQUIRE(calc.calculate(2, '=') == 80);
  }

  SECTION("Trigonometric functions", "[trig]") {
    REQUIRE(calc.calculate(0, 's') == 0);
    REQUIRE(calc.calculate(0, 'c') == 1);
  }

  SECTION("Logarithm function", "[log]") {
    REQUIRE(calc.calculate(1, 'l') == 0);
    REQUIRE(calc.calculate(10, 'l') == Approx(2.30259).epsilon(0.00001));
  }

  SECTION("Square root function", "[sqrt]") {
    REQUIRE(calc.calculate(4, 'q') == 2);
    REQUIRE(calc.calculate(16, 'q') == 4);
  }
}


TEST_CASE("Simple Calculator can be reset", "[reset]") {
  SimpleCalculator calc;

  REQUIRE(calc.calculate(100, '+') == 100);
  REQUIRE(calc.calculate(100, '-') == 200);
  REQUIRE(calc.calculate(40, '/') == 160);
  REQUIRE(calc.calculate(4, '*') == 40);
  REQUIRE(calc.calculate(2, '=') == 80);
  calc.reset();
  REQUIRE(calc.calculate(2, '=') == 2);
}
