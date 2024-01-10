//object_function_in_class.cpp

#include <iostream>
using namespace std;

class Student {
  public:
    string name;
    string major;
    double gpa;

    Student (string aName, string aMajor, double aGpa ) {
        name = aName;
        major = aMajor;
        gpa = aGpa;

    }

    bool hasHonors() {
         if(gpa > 3.5) {

            return true;
         }
         return false;
    }
};



int main() 
{
    Student student1 ("Mihael", "Software engineer", 3.7);
    Student student2 ("Fabi", "Data Specialist", 2.7);
    Student student3 ("Alvin", "Network engineer", 2.6);

    cout << student1.name << endl;
    // cout << student1.hasHonors() <<endl;
    // cout << student2.hasHonors() <<endl;

    bool r1 = student1.hasHonors();
    bool r2 = student2.hasHonors();
     

     if(r1 == true) {
        cout << "congratualtion you got 1000 euros" << endl;
     } else {
        cout << "no money" << endl;
     }
   
 

}