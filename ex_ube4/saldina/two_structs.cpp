/*
      we can also make this instad print function  -- with OPERATOR  OVERLOADING
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


    std::ostream& operator << (std::ostream& COUT, YoutubeChannel& YT1) {
        
            std::cout << "Channel name:  " <<YT1.channelName_ << '\n';
            std::cout << "Channel name:  " <<YT1.subscribers_ << '\n';

            return COUT;
    }


    struct Collection {  // konstruktor je default , samo setter
        void setmyChannel(YoutubeChannel& channel) { 
        myChannels.push_back(channel);     
       }
            // print func. statt operaotr overloading
      void printChannels() {
        for(const auto& channel : myChannels) {
                    std::cout << "Name: " << channel.channelName_ << '\n';
                    std::cout << "Numb of szúbscribers: " << channel.subscribers_ << '\n';
        }
      }

        std::list<YoutubeChannel>myChannels;
    };


int main()
    {   
        YoutubeChannel yt1 {"codingUggly", 30000};
        // printStruct(yt1);
        YoutubeChannel yt2 {"veryFunny", 80000};
      //  std::cout << yt1 <<  yt2;

        Collection collection1;
        collection1.setmyChannel(yt1);
        collection1.setmyChannel(yt2);

        collection1.printChannels();

        return 0;

    }


