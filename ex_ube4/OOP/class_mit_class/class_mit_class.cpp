#include <iostream>
#include <string>
#include <vector>

class Person {
public:
    Person(std::string name, int age) : name_(name), age_(age) {}

    void displayInfo() const {
        std::cout << "Name: " << name_ << ", Age: " << age_ << std::endl;
    }

private:
    std::string name_;
    int age_;
};

class Team {
public:
    void addMember(const Person &person) {
        teamMembers_.push_back(person);
    }

    void displayTeam() const {
        std::cout << "Team Members:\n";
        for (const auto &member : teamMembers_) {
            member.displayInfo();
        }
    }

private:
    std::vector<Person> teamMembers_;
};

int main() {
    // Create some Person objects
    Person person1("Alice", 25);
    Person person2("Bob", 30);
    Person person3("Charlie", 22);

    // Create a Team and add members
    Team myTeam;
    myTeam.addMember(person1);
    myTeam.addMember(person2);
    myTeam.addMember(person3);

    // Display the team members
    myTeam.displayTeam();

    return 0;
}
