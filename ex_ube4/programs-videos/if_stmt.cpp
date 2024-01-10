#include <iostream>
using namespace std;

int main() 
{
        int age;
    cout << " Wie alt bist du?" << endl;
    cin >> age;

    bool istVolljahrig;
    if (age >=18) {
         istVolljahrig =true;
    } else {
         istVolljahrig = false;
    }

    char isMale;
    cout << "was ist dein Geshclecht (m= man, f= frau)? : " << endl;
    cin >> isMale;

    bool man;
    if(isMale == 'm') {
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
        cout << " Du bist weder Man , noch Volljahrig. Hau ab!!" << endl;
    }

     else{
        cout << "Es tut uns leid, aber du bist zu jung Man. Nur 18+" << endl;

    }   
}


// --------------- einfacher von GPT


// #include <iostream>
// using namespace std;

// int main() 
// {
//     int age;
//     cout << "Wie alt bist du?" << endl;
//     cin >> age;

//     char isMale;
//     cout << "Was ist dein Geschlecht (m=man, f=frau)? : " << endl;
//     cin >> isMale;

//     bool istVolljahrig = age >= 18;
//     bool man = (isMale == 'm');

//     if (istVolljahrig && man) {
//         cout << "Hier sind Filme für 18+." << endl;
//     } else {
//         cout << "Es tut uns leid, aber du bist zu jung oder eine Frau für dieses Ihalt." << endl;
//     }

//     return 0;
// }




