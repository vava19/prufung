#include <fstream>
#include <iostream>

int main() {
    std::fstream file("data.txt", std::ios::in | std::ios::out);
    if (file.is_open()) {
        // Use file for both reading and writing
        file << "Hello, world!" << std::endl;
        std::string line;
        while (getline(file, line)) {
            std::cout << line << std::endl;
        }
        file.close();
    } else {
        std::cerr << "Unable to open file." << std::endl;
    }

    return 0;
}
