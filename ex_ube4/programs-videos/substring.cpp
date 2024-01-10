#include <iostream>
#include <string>
using namespace std;

int main() {
   
   string phrase = "Oto Rino Larin";
   string substring;
   substring = phrase.substr(3,5);  // starting from index 3, nimmt 5 indexes in ergebniss  
   cout << substring;

    //ergebnis: Rino

    return 0;
}
