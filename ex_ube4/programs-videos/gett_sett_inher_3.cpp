//  gett_sett_inher_3.cpp   --> wollen demonstrierern:
//  getter, setter ,   inharitance


#include <iostream>
using namespace std;



class Phone{
    private:
    string brand;

    public:
    string model;
    int ram;
    double camera; 

    //constructor 1:
    Phone(string aBrand, string aModel, int aRam, double aCamera) : model(aModel), ram(aRam), camera(aCamera) {  // just deleted brand(aBrand) from init
        setBrand(aBrand);
    }

    void setBrand(string privBrand) {
        if(brand == "iphone" || brand == "samsung" || brand == "nokia") {

            brand = privBrand;
        } else {
            cout << "you enter non - existing Brand! " << endl;
        }
    }

    string getBrend() {
        return brand;
    }

};

class Iphone : public Phone {


};



int main() 
{
    Phone phone1 ("iphone", "A9", 32, 6.0);

    //cout << phone1.brand <<endl;
    //cout << (phone1.brand = "samsung");   // ako stavim zagradu ide sa "cout"

    phone1.setBrand("shaomi");
        cout << phone1.getBrend() <<endl;



       // Iphone iphone1("samsung", "a7", 64, 7.2);


 


}