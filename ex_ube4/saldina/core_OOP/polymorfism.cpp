
#include <iostream>
#include <list>
using namespace std;

class YouTubeChannel {
private:
	string Name;
	int SubscribersCount;
	list<string> PublishedVideoTitles;

    protected:
	    string OwnerName;
        int contentQuality;

public:
	YouTubeChannel(string name, string ownerName) {
		Name = name;
		OwnerName = ownerName;
		SubscribersCount = 0;
	}
	void GetInfo() {
		cout << "Name: " << Name << endl;
		cout << "OwnerName: " << OwnerName << endl;
		cout << "SubscribersCount: " << SubscribersCount << endl;
		cout << "Videos: " << endl;
		for (string videoTitle : PublishedVideoTitles) {
			cout << videoTitle << endl;
		}
	}
	void Subscribe() {
		SubscribersCount++;
	}
	void Unsubscribe() {
		if (SubscribersCount > 0)
			SubscribersCount--;
	}
	void PublishVideo(string title) {
		PublishedVideoTitles.push_back(title);
	}

    std::string checkAnalytics()const 
    {
        return (contentQuality < 3) ? "bad quality":"good quality";
    }
};





class CookingChannel: public YouTubeChannel{

public:
         CookingChannel(string name, string ownerName) : YouTubeChannel(name, ownerName){}; // just invoke construc. of base class
         void practiceCooking() {
            cout << OwnerName <<"Practicing cooking" << '\n';
            contentQuality++;
         }

private:

};

class SingingChannel: public YouTubeChannel{

public:
         SingingChannel(string name, string ownerName) : YouTubeChannel(name, ownerName){}; // just invoke construc. of base class
         void practiceSinging() {
            cout << OwnerName <<"Practicing Singing bro......!!? " << '\n';
            contentQuality++;
         }

private:

};


int main()
{
     CookingChannel alvinCook{"Lass es schmeck", "Alvin"};
     alvinCook.GetInfo();
     alvinCook.Subscribe();
     alvinCook.practiceCooking();
     alvinCook.practiceCooking();
     alvinCook.practiceCooking();
     alvinCook.practiceCooking();
     alvinCook.practiceCooking();

     CookingChannel maredaCook{"schemcker lecker", "mareda"};
     maredaCook.practiceCooking();

    SingingChannel dinoSing{"cheers singer", "dino"};
    dinoSing.practiceSinging();
    dinoSing.practiceSinging();

     YouTubeChannel *yt1 = &alvinCook;
     YouTubeChannel *yt2 = &dinoSing;

     yt1->checkAnalytics();
     yt2->checkAnalytics();
   
}