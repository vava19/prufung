// int notes[5];   --> array decleration
// pay attention on 2 for loops- regular loop für WRITING IN in deklerierte array (int i = 0; i<5; i++)
// int notes[] = {5,6,2,4,3}
//   herausfischen for loop (int &note : notes) {}

#include <iostream>
#include <vector>
using namespace std;

class Student {
public:
    string name;
    string major;
    double gpa;
    

    Student(string aName, string aMajor, double aGpa) : name(aName), major(aMajor), gpa(aGpa) {}

    bool hasHonors() {
        return gpa > 3.5;
    }
};

int main() {
    // Create an array of students
    Student students[] = {
        {"Mihael", "Software engineer", 3.7},
        {"Fabi", "Data Specialist", 2.7},
        {"Alvin", "Network engineer", 2.6}
    };

    // Loop through each student
    for ( Student& student : students) {    // wie kann ich herausfischen aus 'array', ween weiß nichr wie viel elemente
        cout << student.name << endl;

        // Check if the student has honors
        if (student.hasHonors()) {
            cout << "Congratulations, you got 1000 euros" << endl;
        } else {
            cout << "No money for you" << endl;
        }

        cout << endl; // Add a separator between students
    }

    return 0;
}
