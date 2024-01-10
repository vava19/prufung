[![Review Assignment Due Date](https://classroom.github.com/assets/deadline-readme-button-24ddc0f5d75046c5622901739e7c5dd533143b0c8e959d652212380cedb1ea36.svg)](https://classroom.github.com/a/mQAmY-d1)
# Wx Calculator

After finishing the below tasks, run the following commands to see if your code
is correct.

```shell
mkdir build && cd build
cmake ..
make -j4
make test
```

As an alternative to `make test` (or `ctest`) you can run the individual
`test_*` executables.

## Tasks

It is your duty to extend the current calculator and its user interface to
contain new functionality.

1. declare and implement functions to calculate `sin`, `cos`,
   [`ln`](https://en.cppreference.com/w/c/numeric/math/log) and `sqrt`
   to the calculator's backend (`simple_calculator.?pp`)
2. add test cases to `simple_calculator_test.cpp`
3. add the new functionality to the calculator's user interface (`calc_ui.?pp`)

Note that you are free with regard to how or where you add the buttons to the
existing user interface.

## Points

* 10 points for handling git w/out help
* 10 points if the code compiles w/out errors
* 20 points for the new unit tests (5 points per functionality properly tested)
* 20 points for the new backend functionality
* 20 points for adding the buttons to the UI without breaking existing
     functionality
* 20 points for adding click handlers to the new buttons so the
     functionality can be used from the UI without bugs
