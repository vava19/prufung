#include <iostream>
using namespace std;

class Rectangle {
private:
    double length;
    double width;

public:
   // Konstruktor
//    Rectangle(double len, double wid) : length(len), width(wid) {}    //  -->  neue Version
Rectangle(double len, double wid) {                                  // --> old version + begrenzung
    setLength(len);
    setWidth(wid);
}

// Rectangle(double len, double wid) : length(0), width(0) {        // init werts
//     setLength(len);
//     setWidth(wid);
// }


   Rectangle() {

   }

    // Getter für die Länge
    double getLength() const {
        return length;
    }
    // Getter für die Breite
    double getWidth() const {
        return width;
    }

    // Setter für die Länge
    void setLength(double len) {
        if (len > 0) {
            length = len;
        } else {
            cout << "Ungültige Länge. Die Länge muss größer als 0 sein." << endl;
        }
    }


    // Setter für die Breite
    void setWidth(double wid) {
        if (wid > 0) {
            width = wid;
        } else {
            cout << "Ungültige Breite. Die Breite muss größer als 0 sein." << endl;
        }
    }

    // Berechnung des Flächeninhalts
    double calculateArea() const {
        return length * width;
    }
};

int main() {
    // Ein Rechteck erstellen
    Rectangle rectangle(-4.0, 2.0);

    // Informationen abrufen
    cout << "Länge: " << rectangle.getLength() << endl;
    cout << "Breite: " << rectangle.getWidth() << endl;
    cout << "Flächeninhalt: " << rectangle.calculateArea() << endl;

    // Länge und Breite ändern
    rectangle.setLength(7.0);
    rectangle.setWidth(4.0);

    // Neue Informationen abrufen
    cout << "Neue Länge: " << rectangle.getLength() << endl;
    cout << "Neue Breite: " << rectangle.getWidth() << endl;
    cout << "Neuer Flächeninhalt: " << rectangle.calculateArea() << endl;

    return 0;
}
