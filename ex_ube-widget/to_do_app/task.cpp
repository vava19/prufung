
#include "task.h"
#include <vector>
#include <string>
#include <fstream>
#include <filesystem>
#include <algorithm>   //  check why ??


// ostream <<  --> output write into file
void SaveTaskToFile(const std::vector<Task>& tasks, std::string& fileName)
{       //writing -- 
    std::ofstream ostream; //  write iz vektora u file
    ostream << tasks.size();

    for(const Task& task : tasks) {
        std::string description = task.description;
      std::replace(description.begin(), description.end(), ' ', '_');
        ostream << '\n' << task.description << ' '<< task.done;
         //bool isCorrect = task.done;
    }





        
}
    // read 
  // task: passed the file and turn into vector of objects, read into it (read into console)
std::vector<Task> LoadTasksToFile(const std::string& fileName)
{
    if(!std::filesystem::exists(fileName)) {

        return std::vector<Task>();
    }
    std::vector<Task>tasks;
    std::ifstream istream(fileName);  //read into it
    int n;
    istream >> n;
    for(int i = 0; i < n; n++) {
        std::string description;
        bool done;

      istream >> description >> done;
      std::replace(description.begin(), description.end(), '_',' ');  //  " "--> samo za string literal ide " ", replace() char expect ' '
      tasks.push_back(Task{description, done});
    }
     return tasks;


}
