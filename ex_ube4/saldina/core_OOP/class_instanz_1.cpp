// you can direct add in list with {} more elements
// this example works perfect, but what if we have created more objects, how to print them
// with function inClass, or "outClass"  or "operatorOverloding"
/*
std::list contains a pointer to the next and previous elements.
std::vector: Uses a dynamic array to store elements. Elements are stored in contiguous memory locations.
*/

#include <iostream>
#include <string>
#include <list>
#include <vector>

class YoutubeChannel{
    public:
    std::string name{};
    std::string ownerName{};
    int subscribeCount{};
  std::vector<std::string>publishedVideos;

};



int main() 
{
   YoutubeChannel myChannel{"it", "alvin", 2000, {"all about class", "inheritance", "struct"}};

  std::cout << myChannel.name << '\n';
   std::cout << myChannel.ownerName << '\n';
    std::cout << myChannel.subscribeCount << '\n';
      std::cout << '\n';
    for(std::string perVideo : myChannel.publishedVideos)
    {
        std::cout << "Videos: " << '\n';
        std::cout << perVideo << '\n';
    }

   return 0;
}