
#include <iostream>
#include <vector>
#include <string>


struct YoutubeChannel {

    std::string channelName_;
    int subscribers_;

    YoutubeChannel(const std::string& channelName, int subscribers)
    :channelName_(channelName), subscribers_(subscribers){};

  

};

 void printStruct (YoutubeChannel &yt){  // YoutubeChannel& yt
        
            std::cout << "Channel name:  " <<yt.channelName_ << '\n';
            std::cout << "Channel name:  " <<yt.subscribers_ << '\n';

    }

int main()
    {   
        YoutubeChannel yt1 {"codingUggly", 30000};
        // YoutubeChannel yt1  = YoutubeChannel ("codingUggly", 30000);
       // YoutubeChannel yt1{"codingUggly", 30000}
        printStruct(yt1);

        return 0;

    }
