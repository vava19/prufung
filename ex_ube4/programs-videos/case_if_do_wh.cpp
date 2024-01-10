// case is special if stmt
// why is switch stmt more efficient than 'if stmt' because : propadanje
// if stmt mora provjeriti svaki stmtm, switch propada jer ima value + break-- kein Bearbeitung
//   dayNum  nur bestimmte value (presakce ostalo iznad)      break; --> no weiter unter bearbeitung (preskace ostalo ispod)

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

 do {
        cout << "Geben Sie eine Zahl von 1 bis 7 ein. Jede Zahl repräsentiert einen Tag in der Woche: ";
        cin >> dayNum;

        // Überprüfe, ob die Eingabe gültig ist
        isCorrect = (dayNum >= '1' && dayNum <= '7');
        
        if (!isCorrect) {
            cout << "Ungültige Eingabe. ";
        }
         // in case user made mistake more than 3 time, will break do-while loop. and reach "default" from swich-case
         // this is second condition
        counter++;
        if(counter > 3) {cout << "bro i think you are AI, get out " << endl; break;}

    } while (!isCorrect);


   string umwandler = getDayOfWeek(dayNum);
   cout << "Du hast gewahlt: " << umwandler << endl;

   return 0;
}