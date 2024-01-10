#include <iostream>
#include <string>
using namespace std;

int main() {
   
    string grussung = " hello liebe, ich grusse euch";
    size_t search;
    search =grussung.find("euch", 0);

    cout << search << endl;  // gib als Ergebnis index nummer --> 25

    

    return 0;
}
