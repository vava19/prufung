
//  To use our max<T> function template, we can make a function call with the following syntax:
//  max<actual_type>(arg1, arg2); // actual_type is some actual type, like int or double


#include <iostream>

template <typename T>   
T max(T x, T y)  // the generated function max<int>(int, int)
{
    return (x < y) ? y : x;   // return bigger Number
}

int main()
{
    std::cout << max<int>(3, 6) << '\n';
    std::cout << max<double>(2.477, 3.232) << '\n';
    std::cout << max<bool>(1, 0) << '\n';
    std::cout << max<char>('a', 'l') << '\n';

    return 0;
}
