#include <iostream>
using namespace std;


int main()
{
    int secretNum =8;
    int guess;
    int cnt = 1;
    do {
        cout << "Guess the number: " << endl;
        cin >> guess;
        cnt++;

        if(cnt > 5) {
            cout << "you tried to many times";
            break;}
        else if(secretNum == guess) {
            cout << "you won";

        };


    } while(secretNum != guess) ;

    return 0;
}