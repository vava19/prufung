

#include <iostream>
using namespace std;

// int main() {
//     string comment;
//     cout << "Write your comment heir : " << endl;

//      getline(cin,comment);

//         if ( comment.length() >= 20) {
//             cout << " comment reached maximum" << endl;
//         }  

//     return 0;
// }


int main() {    
    string comment;
   

do {
       cout << "Write your comment heir : " << endl;
       getline(cin,comment);

        if (comment.length() >= 20) {
            cout << " comment reached maximum" << endl;
            break;
            }
} while (true);
     
    return 0;
}
