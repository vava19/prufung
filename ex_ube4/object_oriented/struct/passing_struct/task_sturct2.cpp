/*
Question #1

You are running a website, and you are trying to calculate your advertising revenue.
 Write a program that allows you to enter 3 pieces of data:

How many ads were watched.
What percentage of users clicked on an ad.
The average earnings per clicked ad.

Store those 3 values in a struct. Pass that struct to a function that prints 
each of the values. The function should then calculate how much you made for 
that day (multiply the 3 fields together) and prints that value.


            MY STRUCT   -----------------------------
*/

#include <iostream>

struct Advert {
   int  addshown{};
    double rateview{};
    double click_earn{};

};

Advert getAdvert() {
    Advert temp;  // have to make tem instanz
    std::cout << "How many adds were watched? ";
    std::cin >> temp.addshown;
    std::cout << "What percantage of user clicked on a add? ";
    std::cin >> temp.rateview;
    std::cout << "The avg earning per click? ";
    std::cin >> temp.click_earn;

    return temp;  // temp je value of Advert

}

void printAdvert(const Advert& add1) 
{
   std::cout << add1.addshown << '\n';
   std::cout << add1.rateview << '\n';
   std::cout << add1.click_earn << '\n';

   // We need to divide ad.clickThroughRatePercentage by 100 because it's a percent of 100, not a multiplier
   std::cout << "Total earning: " <<
   (add1.addshown * add1.rateview / 100 * add1.click_earn) << '\n';
}


int main() 
{
    Advert add1{getAdvert()};   // ertell neues Instanz, Benutzer wird mit antowrten ertellt
    printAdvert(add1);

   

}

