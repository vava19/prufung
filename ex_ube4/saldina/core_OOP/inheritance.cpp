
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
};

class CookingChannel: public YouTubeChannel{

public:
         CookingChannel(string name, string ownerName) : YouTubeChannel(name, ownerName){}; // just invoke construc. of base class
         void practiceCooking() {
            cout << OwnerName <<"Practicing cooking" << '\n';
         }

private:

};

class SingingChannel: public YouTubeChannel{

public:
         SingingChannel(string name, string ownerName) : YouTubeChannel(name, ownerName){}; // just invoke construc. of base class
         void practiceSinging() {
            cout << OwnerName <<"Practicing Singing bro......!!? " << '\n';
         }

private:

};


int main()
{
     CookingChannel alvinCook{"Lass es schmeck", "Alvin"};
     alvinCook.GetInfo();
     alvinCook.Subscribe();
     alvinCook.practiceCooking();

     CookingChannel maredaCook{"schemcker lecker", "mareda"};
     maredaCook.practiceCooking();

    SingingChannel dinoSing{"cheers singer", "dino"};
    dinoSing.practiceSinging();
}