#include <iostream>

using namespace std;

int main () 
{
    double num1, num2;

    cout << "Enter first number: " << endl;
    cin >> num1;

    cout << "Enter second number: " << endl;
    cin >> num2;

 char operation;
    cout << "Enter operation which you want to perform(+ - * /):" << endl;
   cin >> operation;

 switch (operation)
 {

    case '+':
    cout <<  num1 + num2 << endl;
    break; 

    case '-':
    cout << num1 - num2 << endl;
    break;

    case '*':
    cout << num1 * num2 << endl;
    break;

    case '/':
    cout << num1 / num2 << endl;
    break;

    default:
    cout << "invalit input" << endl;

 }
    return 0;

}