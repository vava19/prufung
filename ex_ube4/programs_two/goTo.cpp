
// goto ähnicle benehmung wie  do while loop
#include <iostream>
#include <cmath>


int main() 
{
    double x{};
  tryAgain:
    std::cout<< "Enter a non-negative number: ";
    std::cin>> x;

   if(x < 0.0)
      goto tryAgain;
    
    std::cout << "The square root of: " << x << " is " << sqrt(x) << '\n';
    return 0;
}