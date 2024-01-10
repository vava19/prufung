// kad je sa "const"  moramo return  drugu variable from func , a ne "y"

#include <iostream>

int addOne(const int& y) // y is a reference (holding memory address of x), ali kad koristimo u funkciji dalje -- onda je wert von X
{
    //++y; // this modifies the  original x object   ---> compiler fehler 
    double result{};
    result = (y +3) * 4;
   // return y + 1;  // --> this geht, NO Fehler, NO modification
   return result;
}

int main()
{
    int x { 5 };

    std::cout << "value = " << x << '\n';

    int new_x = addOne(x);
      std::cout << new_x << '\n';

    std::cout << "value = " << x << '\n'; // x has not been modified

    return 0;
}