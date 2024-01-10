
#include <fstream>
#include <iostream>

int main() {
    std::ifstream inputFile("input.txt");
    if (inputFile.is_open()) {
        std::string line;
        while (getline(inputFile, line)) {
            std::cout << line << std::endl;
        }
        inputFile.close();
    } else {
        std::cerr << "Unable to open input file." << std::endl;
    }

    return 0;
}
