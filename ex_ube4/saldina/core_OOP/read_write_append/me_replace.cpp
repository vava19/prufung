#include <iostream>
#include <algorithm>
#include <string>

int main() {
    std::string text = "this is is mein man und dein Onkel";

    std::replace(text.begin(), text.end(), ' ', '_');

    // Print the modified string
    std::cout << text << std::endl;

    return 0;
}
