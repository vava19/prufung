// In diesem Beispiel wird ein 2D-Array von Strukturen (Color) erstellt, 
// um die RGB-Farbwerte der Pixel zu repräsentieren. Die Funktion initializePixels füllt das Array mit zufälligen Farbwerten, und printPixels gibt die Farbwerte der Pixel aus. 

#include <iostream>
#include <cstdlib> // für rand()
#include <ctime>   // für time()

const int width = 3;
const int height = 3;

struct Color {  //struct
    int red;
    int green;
    int blue;
};

void initializePixels(Color pixelArray[width][height]) {   // Color is struct als datatype  (red, green, blue) -> bedeutet jeder (width,height) hat red,green,blue
    // Initialisiere die Pixel mit zufälligen Farbwerten
    srand(static_cast<unsigned>(time(0)));    // ganzahligtyp nummer und nihct negativ

    for (int i = 0; i < width; ++i) {
        for (int j = 0; j < height; ++j) {
            pixelArray[i][j].red = rand() % 256;    // Zufälliger Wert zwischen 0 und 255
            pixelArray[i][j].green = rand() % 256;
            pixelArray[i][j].blue = rand() % 256;
        }
    }
}

void printPixels(const Color pixelArray[width][height]) {
    // Gibt die Farbwerte der Pixel aus
    for (int i = 0; i < width; ++i) {
        for (int j = 0; j < height; ++j) {
            std::cout << "(" << pixelArray[i][j].red << ", "
                      << pixelArray[i][j].green << ", "
                      << pixelArray[i][j].blue << ") ";
        }
        std::cout << std::endl;
    }
}

int main() {
    Color pixelArray[width][height];

    // Initialisiere und drucke die Pixel
    initializePixels(pixelArray);
    printPixels(pixelArray);

    return 0;
}
