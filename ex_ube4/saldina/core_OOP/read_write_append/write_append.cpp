// just for write & append

#include <iostream>
#include <fstream>
//using namespace std;


int main()
{
    std::fstream myFile;  //fstream -> is datatype from lib.fstream
    myFile.open("some.txt", std::ios::out);  // write
    if(myFile.is_open()) { //method boolean
        myFile << "Halelu\n"; //ne ide cout jer ne pisemo u console
        myFile << "second line\n";
        myFile.close();
    }

    myFile.open("some.txt", std::ios::app);  // append
    if(myFile.is_open()) {
        myFile << "MAch mal\n";
        myFile << "wxWidget\n";
        myFile.close();
    }

}

