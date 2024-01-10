/*
   Warum brauchen wir  "class type ?"
   Warum Struct ist nicht genugend ?

 denominator ne smije biti podijeljen sa 0 sonst es ist "Division by Error"
    precoutions:
    1. comment
    2. init mit 1
    3. <cassert>

    Struct hat nicht genuk Zeuge, es ist nicht elegant um dieses Problem 
    zu heandeln.
*/

#include <iostream>
#include <cassert>

struct Fraction
{
   
    int numerator { 0 };
    int denominator { 1 }; // class invariant: should never be 0
};

void printFractionValue(const Fraction &f)
{
     if(f.denominator == 0) {
        std::cerr << "Error: Division by Zero detected. \n";
     }
     
     else{
      std::cout << f.numerator / f.denominator << '\n';
     }
}

int main()
{
    Fraction f { 5, 0 };   // create a Fraction with a zero denominator
    printFractionValue(f); // cause divide by zero error

    return 0;
}