
// comparison function , wird 2 nummern vergleich dann macht boolean und ergebnis
#include <iostream>
using namespace std;


int getMaxNumb(int n1, int n2, int n3) {
    
    int result;
    if(n1 > n2 && n1 > n3) {
        result = n1;
    }
    else if(n2 > n1 && n2 > n3) {
        result = n2;
    }
     else {
        result = 3;
    }   
    return result;

}


int main() 
{

    int num1, num2, num3;
    cout << "enter 2 integers: " << endl;
    cin >> num1;
    cin >> num2;
    cin >> num3;
    int ergebnis = getMaxNumb(num1, num2, num3);

    cout << "Grosser nummer ist: "<< ergebnis << endl;

    return 0;
}