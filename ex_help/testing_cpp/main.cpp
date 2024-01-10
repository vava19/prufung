#include <iostream>
// #include "add.cpp"   //-->    Do not #include “add.cpp” from main.cpp. This will cause the preprocessor 
                            //  to insert the contents of add.cpp directly into main.cpp instead of treating them as separate files.

#include "add.h"
#include "getInteger.h"

//int add(int, int);
//int getInteger();

int main()
{   
    int x{ getInteger() };   // 2 times called function für insert
	int y{ getInteger() };
    std::cout << "The sum of x and y is: " << add(x, y) << '\n';
    return 0;
}
