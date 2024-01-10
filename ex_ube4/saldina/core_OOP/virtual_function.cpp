/*
  run time polymorphism
 virtual function will execute the most derived function in this case  of this function: 
      void makeSound() {
        std::cout << " Guitar playing\n";

        if there is no derived version, than will execute base class function
    }
*/

#include <iostream>


class Instrument {
    public:
    virtual void makeSound() {      // probaj sa i bez virtual-> znaci hejj ako ima ista funkcija u derived class tu execute
        std::cout << " Instrument  playing\n";      // ako nema onda koristi ovu iz parent
    }
};

class Guitar: public Instrument {
    public:
    void makeSound() {
        std::cout << " Guitar playing\n";
    }
};


int main()
{
    Instrument *i1 = new Guitar();
    i1->makeSound(); 

}