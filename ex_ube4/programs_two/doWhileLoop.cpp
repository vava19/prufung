
#include <iostream>

int main()
{
    // selection must be declared outside of the do-while-loop, so we can use it later
    int selection{};

    do
    {
        std::cout << "Please make a selection: \n";
        std::cout << "1) Addition\n";
        std::cout << "2) Subtraction\n";
        std::cout << "3) Multiplication\n";
        std::cout << "4) Division\n";
        std::cin >> selection;
    }
    while (selection != 1 && selection != 2 &&
        selection != 3 && selection != 4);

    // do something with selection here
    // such as a switch statement

    std::cout << "You selected option #" << selection << '\n';

    return 0;
}




// kann ersetzt sein mit  " while -- INFINITE --  loop":


#include <iostream>

int main()
{
    // selection must be declared outside of the do-while-loop, so we can use it later
    int selection{};

    while(true)
    {
        std::cout << "Please make a selection: \n";
        std::cout << "1) Addition\n";
        std::cout << "2) Subtraction\n";
        std::cout << "3) Multiplication\n";
        std::cout << "4) Division\n";
        std::cin >> selection;
        
        if (selection == 1 || selection == 2 ||
        selection == 3 || selection == 4) break;
    }


    // do something with selection here
    // such as a switch statement

    std::cout << "You selected option #" << selection << '\n';

    return 0;
}