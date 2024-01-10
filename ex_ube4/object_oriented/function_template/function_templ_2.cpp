// The best way to solve this problem is to rewrite our function template in such a way that 
//our parameters can resolve to different types. Rather than using one template type parameter T, 
//we’ll now use two (T and U):

#include <iostream>

template <typename T, typename U> // We're using two template type parameters named T and U
T max(T x, U y) // x can resolve to type T, and y can resolve to type U
{
    return (x < y) ? y : x; // uh oh, we have a narrowing conversion problem here
}

int main()
{
    std::cout << max(2, 3.5) << '\n';

    return 0;
}


//  Because we’ve defined x with template type T, and y with template type U, x and y can now resolve their types independently. 


//orr   :


template <typename T, typename U>
auto max(T x, U y)
{
    return (x < y) ? y : x;
}