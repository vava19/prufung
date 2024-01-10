
/*
 will demonstrate operator overlaod with print function
 maybe there is better way because we can here use simple print() function
*/



#include <iostream>
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

    void operator << (std::ostream& COUT, YoutubeChannel& YT1) {
        
            std::cout << "Channel name:  " <<YT1.channelName_ << '\n';
            std::cout << "Channel name:  " <<YT1.subscribers_ << '\n';
    }

int main()
    {   
        YoutubeChannel yt1 {"codingUggly", 30000};
        printStruct(yt1);
        std::cout << yt1;

        return 0;

    }
