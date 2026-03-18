#ifndef SCREEN_H
#define SCREEN_H
#include <iostream>
#include <string>
#include <map>

class Screen;
class hero;

extern std::map<std::string, Screen*> screens;
extern hero* currentHero; 

class Screen {
    public:
        std::string name;
        Screen* nextScreen;
        
        Screen(std::string n);
        virtual ~Screen();
        
        virtual void display() = 0;
        virtual void choice() {};

    protected: //private but not specified to just this class
    void redoNodes(const std::string& screenName) {
        if (screens.count(screenName))
            nextScreen = screens[screenName];
        else
            std::cout << "Error: screen '" << screenName << "' not found\n";
    }

    void redoNodes(nullptr_t) {
        nextScreen = nullptr;
    }

};


#endif