// 1. ohne konstruktor  --> oder  DEFAULT Konstruktor
#include <iostream>
#include <string>

using namespace std;

class Person {
public:
    // Attributes of the class
    string name;
    int age;

    // Function to display information about the person
    void displayInfo() {
        cout << "Name: " << name << ", Age: " << age << endl;
    }
};

int main() {
    // Objects of the class
    Person person1;
    Person person2;

    // Initializing attributes separately
    person1.name = "Alice";
    person1.age = 25;

    person2.name = "Bob";
    person2.age = 30;

    // Displaying information about the persons
    cout << "Information about person1:" << endl;
    person1.displayInfo();  // this is for *
    // person1.name;

    cout << "\nInformation about person2:" << endl;
    person2.displayInfo();

    return 0;
}






// 2.  *******************************************
// mit konstruktor


#include <iostream>
#include <string>
using namespace std;

class Person {
public:
    // Attribute der Klasse
    string name;
    int age;

    // Konstruktor
    Person(string n, int a) : name(n), age(a) {}

    // Funktion, um Informationen über die Person auszugeben
    void displayInfo() {
        cout << "Name: " << name << ", Age: " << age << endl;
    }
};

int main() {
    // erstell Objekt + passing direkt vlaue to the Constructor
    Person person1("Alice", 25);
    Person person2("Bob", 30);

    // Informationen über die Personen ausgeben
    cout << "Information about person1:" << endl;
    person1.displayInfo();             // --> performing one of the class method on objekt

    cout << "\nInformation about person2:" << endl;
    person2.displayInfo();

    return 0;
}



//  3. ******+++++ 3hd example where is used function, Anruf ist anderes:
//  printBook(book1);


#include <iostream>
using namespace std;


class Book {
   public:
        string title;
        string author;
        int pages;

};

void printBook(const Book& book) {
    cout << "Title: " << book.title << endl;
    cout << "Author: " << book.author << endl;
    cout << "Number of pages: " << book.pages << endl;

}

int main()
{
   Book book1;  //instanz
   book1.title = "Alchemy";
   book1.author = "Alonso";
   book1.pages = 252;


   Book book2;
   book2.title = "Lord of the Rings";
   book2.author = "Tolkein";
   book2.pages = 700;

   //cout <<  book2.title;
   cout << "Detail of the Book1: " << endl;
   printBook(book1); // -->  passing objekt to the function
   cout << endl;
   cout <<  " ________"  << endl;

    cout << endl;
   cout << "Detail of the Book2: " << endl;
   printBook(book2);

}