/*
       with OPERATOR  OVERLOADING -- statt print function  --
*/

#include <iostream>
#include <string>
#include <list>

struct YoutubeChannel {

    std::string channelName_;
    int subscribers_;

    YoutubeChannel(const std::string& channelName, int subscribers)
    :channelName_(channelName), subscribers_(subscribers){}; 

};


    struct Collection {  
          
        std::list<YoutubeChannel>myChannels;
          
           //operator overloading
          void operator += (YoutubeChannel& channel)   // only one params. because func. inside struct, before we did this task mit  setFunction()
          {
            this->myChannels.push_back(channel);
          }           

    };





      std::ostream& operator << (std::ostream& COUT, const Collection& collection) {
                for(const YoutubeChannel& YtCnannel : collection.myChannels) 
                    COUT << YtCnannel << std::endl;
                return COUT;
      }






int main()
    {   
        YoutubeChannel yt1 {"codingUggly", 30000};
        YoutubeChannel yt2 {"veryFunny", 80000};
      //  std::cout << yt1 <<  yt2;

        Collection collection1;
        //collection1.printChannels();

        collection1 += yt1;
        collection1 += yt2;

        std::cout << collection1;

        return 0;

    }


