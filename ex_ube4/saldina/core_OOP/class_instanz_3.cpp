/*
 funkcija print izvan classe
 difference is that here we have to use "getters" to print private variable with 
   printFunction() which is outside of class !!
*/

#include <iostream>
#include <string>
#include <list>   // moze list ili vector
#include <vector>

class YoutubeChannel{
    public:
      YoutubeChannel( std::string name,std::string ownerName, int subscribeCount, std::vector<std::string> publishedVideos)
    :name_{name}, ownerName_{ownerName}, subscribeCount_{subscribeCount}, publishedVideos_{publishedVideos} {}

//getters
        std::string getName() const {return name_;}
      std::string getOwnerName()const{return ownerName_;}
      int getsubscribeCount()const{return subscribeCount_;}
    std::vector<std::string>  getPublishedVideo() const{return publishedVideos_;}


  private:
    std::string name_{};
    std::string ownerName_{};
    int subscribeCount_{};
  std::vector<std::string>publishedVideos_;
};


  void printYtChannels(const YoutubeChannel& channel)
  {
     std::cout << channel.getName() << '\n';
   std::cout << channel.getOwnerName() << '\n';
    std::cout << channel.getsubscribeCount() << '\n';
      std::cout << '\n';
    for(std::string perVideo : channel.getPublishedVideo())
    {
        std::cout << "Videos: " << '\n';
        std::cout << perVideo << '\n';
    }
  }


int main() 
{
   YoutubeChannel myChannel{"it", "alvin", 2000, {"all about class", "inheritance", "struct"}};
//   myChannel.printYtChannels();
printYtChannels(myChannel);
    

   return 0;
}