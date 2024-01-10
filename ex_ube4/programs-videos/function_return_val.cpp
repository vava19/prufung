//  function mit return value

// Aufgabe: Wir wollen die die Leistung oder den Energieverbrauch in einem physikalischen System berechnen. 
// Es gibt basis und exponente. Basis kommt von Benutzer. exponent von program...basis hoch exponent = kwh ess muss in double datatype berechnent werden.


#include <iostream>
#include <cmath>
using namespace std;


// function signature   or  decleration
double cube(double value);

int main() 
{
    double basis;
    cout << "please enter basis von verbrauchter Strom für dieses Monat: " <<endl;
    cin >> basis;

    double ergebnis = cube(basis);
    cout << "Du hast verbraucht :" << ergebnis <<" kWh" << endl;
}

// funktion
double cube(double value) {

    int exponent = 3;
    double result = pow(value, exponent);
     return result;
     cout << "Hello";  // alles was komt nach return wird nicht zeigen
}