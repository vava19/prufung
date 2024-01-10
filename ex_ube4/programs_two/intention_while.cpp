//#include <iostream>

int main()
{

while (true)
{
  // this loop will execute forever
}

}

// The only way to exit an infinite loop is through a return-statement, a break-statement, an exit-statement, a goto-statement, 
//an exception being thrown, or the user killing the program.


// oder:

#include <iostream>

int main()
{

    while (true) // infinite loop   --> kann do while loop ersetzen !
    {
        std::cout << "Loop again (y/n)? ";
        char c{};
        std::cin >> c;

        if (c == 'n')
            //return 0;
            break;
    }

    return 0;
}


