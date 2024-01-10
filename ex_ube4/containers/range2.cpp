#include <iostream>
#include <string>
#include <vector>

int main()
{
    using namespace std::literals; // for s suffix for std::string literals
    std::vector words{ "peter"s, "likes"s, "frozen"s, "yogurt"s }; // std::vector<std::string>

    for (auto word : words)
        std::cout << word << ' ';

    std::cout << '\n';

    return 0;
}