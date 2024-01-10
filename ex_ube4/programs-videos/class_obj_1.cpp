// class   struct   --> define ney datytp   (bleuprint)  ->z.B.: define "Book" by giving attributes
// object = instanz
// class immer private, struct immer "public"

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
   printBook(book1);
   cout << endl;
   cout <<  " ________"  << endl;

    cout << endl;
   cout << "Detail of the Book2: " << endl;
   printBook(book2);

}