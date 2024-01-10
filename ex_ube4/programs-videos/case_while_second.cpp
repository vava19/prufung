// statt do while , wir haben hier while loop

#include <iostream>
using namespace std;

string getDayOfWeek(char dayNum) {

    string dayName;

    switch (dayNum)
    {
    case '1':
        dayName = "Montag";
        break;

    case '2':
        dayName = "Dienstag";
        break;
    
    case '3':
        dayName = "Mittwoch";
        break;

    case '4':
        dayName = "Donnerstag";
        break;
    
    case '5':
        dayName = "Freitag";
        break;

    case '6':
        dayName = "Samstag";
        break;

    case '7':
        dayName = "Sonntag";
        break;
    
    default:
        cout << " You enter Invalid number for day. Enter from the range 1 -7: " << endl;
        break;
    }

return dayName;

}

int main()
{
    char dayNum;
    bool isCorrect;
    int counter = 0;

int index = 1;

while(index <= 3) {
        cout << "Geben Sie eine Zahl von 1 bis 7 ein. Jede Zahl repräsentiert einen Tag in der Woche: ";
        cin >> dayNum;

        // Überprüfe, ob die Eingabe gültig ist
        isCorrect = (dayNum >= '1' && dayNum <= '7');
        
        if (!isCorrect) {
            cout << "Ungültige Eingabe. " <<endl;
        } else {break;}
        index++;

      }

   string umwandler = getDayOfWeek(dayNum);
   cout << "Du hast gewahlt: " << umwandler << endl;

   return 0;
}