#include <iostream>

using namespace std;

int main() 
{
    int luckyNumbs[] = {2, 5, 6, 23, 11, 1, 56, 64, 7, 4, 1, 2, 1, 8, 8};

    luckyNumbs[3] = 100;
    cout << luckyNumbs[3];

    int limitedArray[10];  // wir konnen 10 nummer eingeben -- begrenzt

    limitedArray[5] = 102;
    limitedArray[0] = 50;
       limitedArray[10] = 205;

    return 0;

}