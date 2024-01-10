
// struct agregate initialization
// prednost {} init-a... schau "instantiation"
// + const struct
#include <iostream>

struct Rectangle
{
    double length {};
    double width {};
};

int main()
{
     const Rectangle unit1 { 1.0, 1.0 };
       const Rectangle unit2 { 1.0};
    const Rectangle unit3 { }; // value-initialize all members

        std::cout << unit1.length << '\n';  
        std::cout << unit2.length << '\n'; 
        std::cout << unit3.length << '\n'; 
    return 0;
}