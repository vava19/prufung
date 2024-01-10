//   Even though it looks like #define MY_NAME “Alex” is defined inside function foo, the preprocessor won’t notice, as it doesn’t understand C++ concepts like functions.

#include <iostream>

void foo()
{
#define MY_NAME "Alex"
}

int main()
{
	std::cout << "My name is: " << MY_NAME << '\n';

	return 0;
}