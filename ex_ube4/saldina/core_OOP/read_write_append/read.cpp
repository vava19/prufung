// just to read but from file in the console = to znaci read
// read" podrazumjeva prikazivanje na console
#include <iostream>
#include <fstream>
#include <string>  // trea za ".getline()"
//using namespace std;


int main()
{
    std::fstream secondFile;
    secondFile.open("some.txt", std::ios::in); // read
    if(secondFile.is_open()) {
        std::string line;
        while(getline(secondFile, line))
        {
            std::cout << line << std::endl;  //za console ide "cout"
        }
      secondFile.close();
    }
   

}

