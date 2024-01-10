
#include <iostream>
using namespace std;


int main()
{
    int myArr[5];
    int i = 0;
    int limit = 5;

    do {
        cout << "Enter any integer from 1-20: " << endl;
        cin >> myArr[i];
        i++;


    }while(i < limit);

    cout << "Hier sind Nummern, die du eingegeben bist: " << endl;
    for(int i = 0; i < limit; i++) {
        cout << myArr[i];
    }

}

