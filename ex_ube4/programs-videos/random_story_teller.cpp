// random story teller should wahl und erzahl eine von 3 Geschihte, aber in diesem fall verwende ich nur eine Story
#include <iostream>

using namespace std;


int main() {

string name, color, hobby;

cout << "Enter your name: "<< name << endl;
getline(cin, name);
cout << "Enter your favorite color: " << color << endl;
getline(cin,color);
cout << "Enter your hobby: " << hobby  << endl;
getline(cin, hobby);


// story 1:

cout << "Dear " << name << ". I have to say that you will be happy and rich man" << endl;
cout << "even if you love no color " << color << " is still your favorite color " << endl;
cout << "your favorite hobby is " << hobby << " This is one happy story.Thnaks i hajd mars" << endl; 



}


