
//   https://www.learncpp.com/cpp-tutorial/introduction-to-function-parameters-and-arguments/
// Write a complete program that reads an integer from the user, 
// doubles it using the doubleNumber() function you wrote in the previous quiz question, and then prints the doubled value out to the console.

#include <iostream>

int userInput()
{
    std::cout << "enter numer: " << '\n';
    int num;
    std::cin >>num;
    return num;
}

int doubleNumber(int num)
{
    return num *2;
}

void printDouble(int doubleNum)
{
    std::cout << "Final result is: " << doubleNum << '\n';
}

int main() 
{

    //     int num = userInput();             // Read an integer from the user
    // int doubledValue = doubleNumber(num);   // Double the number
    // printDouble(doubledValue);         // Print the doubled value


      printDouble(doubleNumber((userInput())));  // prvo u zagradi rjesiti -pravilo (sto vise zagrada- prva je unutra) 
                                                // -- od desna na lijevo(od gore na dole)

    return 0;



}