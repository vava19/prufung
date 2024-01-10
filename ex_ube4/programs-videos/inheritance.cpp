// inheritance geht es über  Methode(funktionen) in Class
// + Bsp. Overwriting

#include <iostream>
using namespace std;



class Chef {


    public:
    void makeCevapi() {
        cout << "Der Koch macht cevapi" << endl;
    }
    void makeDonner() {
        cout << "Der Koch backt Donner" << endl;
    }
    void makePasta() {
        cout << "Der Koch kocht Pasta" << endl;
    }
};


class AlbanChef : public Chef {

    public:
    void makeTorta() {
        cout << "Der Koch backt Torte" << endl;
    }

    // void makeTorta() { cout << "Der Koch macht Donner mit TZSATZIKI"}  --> unterschied zwischen "overloading" und "overwrite" 
        void makeDonner() {
        cout << "Der Koch backt Donner mit TZSATZIKI" << endl;
    }

};


int main ()
{
    Chef chef1;
    chef1.makeCevapi();

    AlbanChef albanChef1;
    albanChef1.makePasta();

    albanChef1.makeTorta();
    albanChef1.makeDonner();

    return 0;
}