#include <iostream>
int add(int, int, int);

int main()
{
    std::cout << "3 + 4 + 5 = " << add(3, 4, 5) << '\n';
    return 0;
}

int add(int x, int y, int z)
{
    return x + y + z;
}

//  Compiles and links. Function declarations do not need to specify the names
//  of the parameters (even though we generally prefer to include them

