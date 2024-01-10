
#include <iostream>
#include <vector>
#include <string>


struct YoutubeChannel {

    std::string channelName_;
    int subscribers_;

    YoutubeChannel(const std::string& channelName, int subscribers)
    :channelName_(channelName), subscribers_(subscribers){};

   void printStruct (){  // YoutubeChannel& yt
        
            std::cout << "Channel name:  " <<channelName_ << '\n';
            std::cout << "Channel name:  " <<subscribers_ << '\n';

    }

};

int main()
    {   
        YoutubeChannel yt1 {"codingUggly", 30000};
        // YoutubeChannel yt1  = YoutubeChannel ("codingUggly", 30000);
       // YoutubeChannel yt1{"codingUggly", 30000}
        yt1.printStruct();

        return 0;

    }








//   CLASS


// #include <iostream>
// #include <vector>
// #include <string>


// class YoutubeChannel {

//     public:
//     YoutubeChannel(const std::string& channelName, int subscribers):channelName_(channelName), subscribers_(subscribers){};
    
//     private:

//     std::string channelName_{};
//     int subscribers_{};

// };

// int main()
//     {
//         //YoutubeChannel yt1  = YoutubeChannel ("codingUggly", 30000);
//         YoutubeChannel yt1{"codingUggly", 30000};

//         return 0;


//     }