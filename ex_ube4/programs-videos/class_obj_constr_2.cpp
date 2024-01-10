
// class mit constructor

#include <iostream>
using namespace std;


class Book {
   public:
        string title;
        string author;
        int pages;

    Book(string aTitle, string aAuthor, int aPages) { 
        title = aTitle;
        author = aAuthor; 
        pages = aPages;
        
        }

    Book () {
        title = "no title";
        author = "no author";
        pages = 0;

    }


// void printBook() {
//     cout << "Title: " << title << endl;
//     cout << "Author: " << author << endl;
//     cout << "Number of pages: " << pages << endl;   
//         }

 };

int main()
{
   Book book1 ("Alchemy", "Alonso", 252);  //instanz
   Book book2 ("Lord of the Rings", "Tolkein", 700);

//    book1.printBook();   //  when printBook() function part of class
//    book2.printBook();
   cout << endl;
    cout << endl;
   cout << book1.author;


// printBook(book1);     // when printBook() is not a part of class
// printBook(book2);


// return 0;

}


