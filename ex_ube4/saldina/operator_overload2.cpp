


#include <iostream>
#include <string>


struct YoutubeChannel {

    std::string channelName_;
    int subscribers_;

    YoutubeChannel(const std::string& channelName, int subscribers)
    :channelName_(channelName), subscribers_(subscribers){};

  

};

//  void printStruct (YoutubeChannel &yt){  // YoutubeChannel& yt
        
//             std::cout << "Channel name:  " <<yt.channelName_ << '\n';
//             std::cout << "Channel name:  " <<yt.subscribers_ << '\n';

//     }

    std::ostream& operator << (std::ostream& COUT, YoutubeChannel& YT1) {
        
            std::cout << "Channel name:  " <<YT1.channelName_ << '\n';
            std::cout << "Channel name:  " <<YT1.subscribers_ << '\n';

            return COUT;
    }

int main()
    {   
        YoutubeChannel yt1 {"codingUggly", 30000};
        // printStruct(yt1);
        YoutubeChannel yt2 {"veryFunny", 80000};
        std::cout << yt1 <<  yt2;

        return 0;

    }





/*
Chaining of Operators:

When you chain multiple << operators, the output of the previous operation becomes the LHS of the next operation.
For example, in std::cout << yt1 << yt2, the result of std::cout << yt1 becomes the LHS for the subsequent << yt2.
Return Type of operator<<:

The operator<< overloads are designed to return a reference to the output stream (std::ostream&).
By returning a reference to the stream, you enable chaining because the result of the expression is the same stream, allowing further operations.



void printStruct(YoutubeChannel& yt) {
    std::cout << "Channel name:  " << yt.channelName_ << '\n';
    std::cout << "Subscribers:  " << yt.subscribers_ << '\n';
}
In this case, you are not chaining. The std::cout is used independently for each << operation.
Since there is no chaining, you don't need to return anything.
Printing Multiple Youtube Channels (With Chaining):

std::ostream& operator<<(std::ostream& COUT, YoutubeChannel& YT1) {
    std::cout << "Channel name:  " << YT1.channelName_ << '\n';
    std::cout << "Subscribers:  " << YT1.subscribers_ << '\n';
    return COUT;
}


*/
