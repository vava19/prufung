/*
   function inside class,  variables private
*/

#include <iostream>
#include <string>
#include <list>   // moze list ili vector
#include <vector>

class YoutubeChannel{
    public:

    //constructor trebaa jer variable private, inace ne treba
    YoutubeChannel( std::string name,std::string ownerName, int subscribeCount, std::vector<std::string> publishedVideos)
    :name_{name}, ownerName_{ownerName}, subscribeCount_{subscribeCount}, publishedVideos_{publishedVideos} {}

  void printYtChannels()  // func. unutar classe --> ne tebaju getters
  {
     std::cout << name_ << '\n';
   std::cout << ownerName_ << '\n';
    std::cout << subscribeCount_ << '\n';
    std::cout << '\n';
    std::cout << "Videos: " << '\n';
    for(std::string perVideo : publishedVideos_)
    {
        std::cout << perVideo << '\n';
    }
  }
  private:
    std::string name_{};
    std::string ownerName_{};
    int subscribeCount_{};
  std::vector<std::string>publishedVideos_;



};


int main() 
{
   YoutubeChannel myChannel{"it", "alvin", 2000, {"all about class", "inheritance", "struct"}};
  myChannel.printYtChannels();
    

   return 0;
}