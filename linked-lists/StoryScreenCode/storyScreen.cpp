#include <iostream>
#include "storyScreen.h"
#include "../screen.h"
#include "../battleScreen/battle.h"
#include <chrono>
#include <ctime>
#include <thread> 
#include <fstream>

using namespace std::this_thread;
using std::chrono::system_clock;
using namespace std;



string StoryScreen::readFromFile(const string& path) {
        ifstream file(path);
        string content;
        string line;
        if (file.is_open()) {
            while (getline(file, line)) {
                content = content + line + "\n";
            }
            file.close();
        } else {
            content = "error opening " + filename;
        }
        
        return content;
    }


void StoryScreen::display() {

    cout << endl << name << endl;
    string folderName = filename.substr(0, 14);

    if (folderName == "storyScreens/m") {
        string text = readFromFile(filename);
        cout << text << endl;
        choice();
    }
    else {
        // print image instantly if one exists
        if (!image.empty()) {
            string img = readFromFile(image);  
            cout << img << endl;
        }

        // print story text slowly
        string text = readFromFile(filename); 
        for (char c : text) {
            cout << c << flush;
            this_thread::sleep_for(chrono::milliseconds(1));
        }

        folderName = filename.substr(0, 13);
        if (folderName == "storyText/sid"){
            cout << "do you except this side quest? y/n " << endl; 
            char input;
            cin >> input;
            input = toupper(input);
            if (input == 'Y'){
                sideQuestchoice = true;
                bandit sideBandit;
                BattleScreen sideQuest(sideBandit);
                cout << "entering battle" << endl;
                screens["sideQuest"] = &sideQuest;

                sideQuest.display(); 

            }
        } 
        else {
            StoryScreen::choice();
        }
    }

}


void StoryScreen::choice(){
    char input;

    string folderName = filename.substr(0, 13);
    if (folderName == "storyText/cre"){
        cout << "[A] main menu         [Q] quit    "<< "\n";
    cin >> input;
    cin.ignore();
    input = toupper(input);

    switch(input){
        case 'A': redoNodes("mainMenu");   break;
        case 'Q': redoNodes(nullptr);   break; // quit
        default:
            cout << "Invalid choice, try again." << endl;
            choice();
        }
        }
else if (folderName == "storyScreens/"){
    cin >> input;
    cin.ignore();
    input = toupper(input);

    switch(input){
        case 'A': redoNodes("classSelect");   break;
        case 'B': redoNodes("tutorial"); break;
        case 'C': redoNodes("credits"); break;
        case 'Q': redoNodes(nullptr);   break; // quit
        default:
            cout << "Invalid choice, try again." << endl;
            choice();
    }
}
else {
    cin.get();
}
}