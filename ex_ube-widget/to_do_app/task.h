#pragma once
//#include <wx/wx.h>
#include <iostream>
#include <vector>
#include <string>


struct Task {
    std::string description;
    bool done;
};


void SaveTaskToFile(const std::vector<Task>& tasks, std::string& filename);  // setter
std::vector<Task> LoadTasksToFile(const std::string& filename);              // getter



