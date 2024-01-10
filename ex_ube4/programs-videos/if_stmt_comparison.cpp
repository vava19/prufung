//   comparison function  take 2 value make them bool (true oder flase) than compare
#include <iostream>
using namespace std;


void genderAgeCheck(int age, char sex)  {

  bool istVolljahrig;
    if (age >=18) {
         istVolljahrig =true;
    } else {
         istVolljahrig = false;
    }


         bool man;
    if(sex == 'm') {
        man = true;
    } else {
        man = false;
    }

    //bool istVolljahrig =true;
    if(istVolljahrig && man) {
        cout << "Hier sind Filmen für 18+ Manner: " << endl;
    }
    else if(istVolljahrig && !man) {   //!man erstazt  -->  man == false
        cout << " Du bist Volljahrig aber Frau, schau bitte kategorie für Frauen" << endl;
    }
     else if(!istVolljahrig && !man) {   //!man erstazt  -->  man == false
        cout << " Du bist weder Man , noch Volljahrig. Hau ab Mädel!!" << endl;
    }

     else{
        cout << "Es tut uns leid, aber du bist  junger Man. Nur 18+  Männer" << endl;

    }   
};




int main() 
{
        int age;
    cout << " Wie alt bist du?" << endl;
    cin >> age;

   
    char sex;
    cout << "was ist dein Geshclecht (m= man, f= frau)? : " << endl;
    cin >> sex;

    genderAgeCheck(age, sex);


    
     
    
}
