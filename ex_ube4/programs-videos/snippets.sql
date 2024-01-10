
-- gettin Zeit:

#include <iostream>
#include <ctime>

int main() {
    std::tm currentDate;
    std::time_t now = std::time(0);
    currentDate = *std::localtime(&now);

    std::cout << "Current Date: " << currentDate.tm_mday << '/'
              << (currentDate.tm_mon + 1) << '/' << (currentDate.tm_year + 1900)
              << std::endl;

    return 0;
}




--  Namespace (::):
--      Zweck: Namespaces dienen dazu, den Code zu organisieren und Namenskonflikte zu vermeiden. 

namespace Math {
    double add(double a, double b) {
        return a + b;
    }
}

int main() {
    double result = Math::add(2.5, 3.5);
    return 0;
}






---- Vererbung - Inharitance:
class Shape {
public:
    void draw() {
        // Implementierung der Zeichenmethode
    }
};

class Circle : public Shape {
public:
    // Circle erbt die Methode draw von der Klasse Shape
};

int main() {
    Circle myCircle;
    myCircle.draw();  // myCircle kann die draw-Methode verwenden
    return 0;
}




------