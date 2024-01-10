// mit funktion signature
#include <iostream>
using namespace std;


void greeting(string vorname, int alt);  // function signature   or  decleration

int main()
{
    greeting("Dino", 36);
    greeting("Alvin", 34);
    greeting("Irnes", 31);

    return 0;

}


void greeting(string vorname, int alt) {

    cout << "Hi Mr. " << vorname << ". Wie geht es Ihnen?" << endl;
    cout << "Du bist : " << alt << "alt" << endl;
    cout << "_______________________________________" << endl;
};