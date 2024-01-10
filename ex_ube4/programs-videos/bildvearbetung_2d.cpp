
// Dieses Beispiel erstellt ein 2D-Array image, das ein zufälliges binäres Bild repräsentiert (mit Pixelwerten von 0 oder 1). 
// Die Funktionen initializeImage und printImage helfen dabei, das Bild zu initialisieren und anzuzeigen.
// Du kannst nun deine eigenen Bildverarbeitungsalgorithmen in der main-Funktion implementieren.


// bedeutet , wir haben leer matrix (width 3, hieght 3) --> mussen ausfullen mir 'random number %' == 0 oder 1

#include <iostream>
#include <cstdlib> // Für die Funktion rand()
#include <ctime>   // Für die Funktion time()

using namespace std;

const int width = 3;
const int height = 3;

void initializeImage(int image[width][height]) {
    // Initialisiere das Bild mit zufälligen Werten (0 oder 1)
    srand(time(0));

    for (int i = 0; i < width; ++i) {
        for (int j = 0; j < height; ++j) {
            image[i][j] = rand() % 2;
        }
    }
}

void printImage(const int image[width][height]) {
    // Ausgabe des Bildes
    for (int i = 0; i < width; ++i) {
        for (int j = 0; j < height; ++j) {
            cout << image[i][j] << " ";
        }
        cout << endl;
    }
}

int main() {
    int image[width][height];

    // Initialisiere und zeige das Bild
    initializeImage(image);
    cout << "Original Image:\n";
    printImage(image);

    // Fügen Sie hier Ihre Bildverarbeitungsalgorithmen ein

    return 0;
}


// initialimage funk. erklarung:

// Hier wird die Funktion srand() verwendet, um den Zufallszahlengenerator zu initialisieren. 
// Der Parameter time(0) sorgt dafür, dass der Generator mit der aktuellen Zeit als Seed initialisiert wird.
// Ohne die Initialisierung von srand(time(0)); würde das 2D-Array image bei jedem Programmstart mit genau den gleichen zufälligen Werten gefüllt. 

// --
// Die Funktion rand() gibt eine zufällige Ganzzahl zurück, und rand() % 2 begrenzt 
// diese Zahl auf den Bereich von 0 bis 1. Das Ergebnis wird dann in das entsprechende Element von image geschrieben.
