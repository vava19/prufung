#include <fstream>
#include <cerrno>

int main() {
    std::ofstream outputFile("output.txt");
    if (outputFile.is_open()) {
        outputFile << "Hello, world!" << std::endl;
        outputFile.close();
    } else {
        std::cerr << "Unable to open output file." << std::endl;
    }

    return 0;
}
