//  getters_setters.cpp


#include <iostream>
using namespace std;


class Movies {

    private:
    string rating;



    public:
    string title;
    string director;
   // double duration;
    // string ganre;


    // constructor 1
    Movies(string aTitle, string aDirector, string aRating) {    //  ,
        title = aTitle;
        director = aDirector;
        setRating(aRating);
        // rating = aRating;

    }

    void setRating(string privateRating) {
            // rating = privateRating;  // eandert direkt private var: rating
            if(privateRating == "untermassig" || privateRating == "massig" || privateRating == "gut" || privateRating == "sehr gut") {
                rating = privateRating;
            } else {
                rating = "not korrekt";
            }
    }

    string getRating() {

          return rating;
    }

};


int main() 
{
    Movies movies1("Reacher", "Spielberg", "bezveze");  // insert
      cout << movies1.getRating() << endl;

    movies1.setRating("gut");   // edit -set#  privat durch public func.
    movies1.title = "Superman";     // public
    //movies.rating = "nikakakv";   --> geht nedd, weil nicht public ist.

    //cout << movies1.title << endl;
    //cout << movies1.rating;

    cout << movies1.getRating();

}

