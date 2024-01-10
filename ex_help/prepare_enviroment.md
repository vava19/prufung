install VS IDE:
-------------------
if(code --version = true) {break}
else {
    sudo apt-get update
   wget -qO- https://packages.microsoft.com/keys/microsoft.asc | gpg --dearmor > packages.microsoft.gpg
sudo install -o root -g root -m 644 packages.microsoft.gpg /usr/share/keyrings/
echo "deb [signed-by=/usr/share/keyrings/packages.microsoft.gpg] https://packages.microsoft.com/repos/code stable main" | sudo tee /etc/apt/sources.list.d/vscode.list > /dev/null

sudo apt-get install apt-transport-https
sudo apt-get update
sudo apt-get install code

code .

}
*******************************************


install c++ compiler  --> gcc
--------------------
if(gcc --version = true) {break;}
else {
    sudo apt-get update
    sudo apt-get install build-essential
}
--- 2-nd choice
if(clang --version =true) {break;}
else {
    sudo apt-get update
    sudo apt-get install clang

}
----- how to call gcc  or clang:

g++ -o output_program source_file.cpp
clang++ -o output_program source_file.cpp

*******************************************



install wxWidget
---------------------
sudo apt update
sudo apt install libwxgtk3.0-gtk3-dev
wx-config --version


quelle:   https://docs.find-santa.eu/programming/cpp/wx/
    If NOT (import file wxWidget)
*******************************************

install Cmake
------------
if!(cmake --version ) {sudo apt-get install cmake;}

*******************************************


```bash
sudo apt-get install catch2
```
check installation :   dpkg -l | grep catch2




install git
-------------------

if (git --version = true){break;}
else {
    sudo apt install git
}
*******************************************


-- try to clone prof. repoTest


ssh keygen - github
--------------
a) check do you have keygen
 ---   cat ~/.ssh/id_rsa.pub 
 ---    copy --> paste on github settings

b) if NOT THEN
     {
        cd ~/.ssh 
        generate =  sh-keygen -t rsa -b 4096 -C "deine_email@example.com"
    }

c) my git hub --> pasw.

*******************************************
---   https://github.com/vava19
----  https://github.com/vava19/exam

git clone setup  
--> choose:
----------
1. Readme.md
2. CMakeLists.txt
3. catch_amalgamated.hpp
4. catch_amalgamated.cpp
5. License MIT

---> create files:  touch classA.cpp classA.h classB.cpp classB.h app.h app.cpp
---> .gitignore

6. Test class compile, linking (use muster muliti-file)
7. Test wxWidget compile, link (use muster)






lookfor the file location (zB. wxWidgets) :   
    sudo find /usr -name wx.h


what if wxWidgets is red --> does not know /path  ?? --showing error
-----
open or create  in .VsCode:    c_cpp_properties.json
-----
copy paste  in  "  c_cpp_properties.json"  :

{
    "configurations": [
        {
            "name": "Linux",
            "includePath": [
                "${workspaceFolder}/**",
               " /usr/include/wx-3.0/wx/wx.h"
            ],
            "defines": [],
            "compilerPath": "/usr/bin/g++",
            "cStandard": "c11",
            "cppStandard": "c++17",
            "intelliSenseMode": "gcc-x64"
        }
    ],
    "version": 4
}



b) look for widget:
lookfor the file location (zB. wxWidgets) :   
    sudo find /usr -name wx.h


    pw:log:pc:  601#457#202#101#29


    PW git:


    pw:ml:



    pw:gpt


    pw:bulme:ml



    links: