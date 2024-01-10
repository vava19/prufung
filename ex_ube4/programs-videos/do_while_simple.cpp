

#include <iostream>
using namespace std;

int main()
{
    int index = 1;
    do {
        cout << index << ". ";
        cout << "  Enter your name: " << endl;
        index++;
    } while(index <= 5);

    return 0;
}