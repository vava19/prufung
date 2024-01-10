
#include <iostream>
using namespace std;


int main()
{

   //int myarr[] = {4, 6, 8, 3, 2};
    int numberGrid[3][2] = {   //  number von Zeilen (Row-horizontalno) und Spalten(column-vertikalno)
        {1, 2},
        {3, 4},
        {5, 6}

    };

    cout << numberGrid[1][1] <<endl;


 //sein nicht verwirend obere array ist gleich wie untere, nicht nur formatiert:

 int twoDarray[3][2] = {  {1, 2}, {3, 4}, {5, 6} };  // schwer zu erkennen, welche ist Zeile , welche ist Spalte

 cout << twoDarray[2][0];


 // how to iterate through entire 2d array ?
 //  mit nested for loop
// ------
cout << endl;
for(int i = 0; i < 3; i++) {
    for(int j = 0; j < 2; j++) {
        cout << twoDarray[i][j];
    }
    cout << endl;
}
  return 0;
}





// wo kannn man 2d array  wervenden:

// Bildverarbeitung:
// int image[width][height];

// Spieldesign:
// char gameBoard[rows][columns];

// Tabellenkalkulation:
// double spreadsheet[rows][columns];

// Computergrafik:
// Color pixelArray[width][height];

// Schachbrett:
// char chessBoard[8][8];
