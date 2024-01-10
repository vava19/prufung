#include <iostream>
#include <string>
using namespace std;

int main() {
   
   cout << "THis is program to calculate your the Kredit posibility" << endl;

      string name;
        cout << "Enter your Name: " << endl;
    // cin >> name;   // cin erlaubt nur 1 word --> wenn detect leer verzehnis --> Bug !!
    getline(cin, name);  // erlaubt Vorname, Nachname etc..zu schreiben  --> string of text egal ob int oder char oder string ist = string ergebniss

   int age;  // double age
    cout << "Enter your age please: " << endl;
    cin >> age;
    
    double salary;
    cout << "Enter your salary"<<endl;
    cin >> salary;
    
    bool allowed = false;
    if (salary > 2000 && age < 55) 
    {
        allowed = true;
    } 
    else
    {
        allowed = false;
    }
 

cout << "you are " << age << " years old." << endl;
cout << "and your name is: " << name << " ....." << endl;
cout << "your salary is " << salary << endl;
cout << "You are " << (allowed ? "allowed" : "not allowed bombo") << " to apply for credit" << endl;


    

    return 0;
}
