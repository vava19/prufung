
// hier ist Bsp, wie ist genua pow() intgrierte <Funktion gebaut   --> pow(3,3)

#include <iostream>
using namespace std;


int pow(int base, int exp) {
    int result = 1;
    for(int i = 1; i <= exp; i++) {
        result *= base;   //result = result * base
    }
    return result;
}



int main()
{      
    int base;
    cout << "Enter base: "  << endl;
    cin >> base;

    int exponent;
    cout << "Enter expoenent: " << endl;
    cin >> exponent; 

   int ergebnis = pow(base, exponent);
   cout << base << " ^ " << exponent << " = " << ergebnis;
}