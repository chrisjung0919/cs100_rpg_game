#ifndef VICTORY_H
#define VICTORY_H

#include <iostream>
#include <chrono>
#include <ctime>
#include <thread>
#include <fstream>
#include "../screen.h"
#include "../StoryScreenCode/storyScreen.h"
#include "../characterFiles/character.h"
#include "../characterFiles/enemy.h"
#include "../characterFiles/hero.h"
#include "../screen.h"


using namespace std;

class Victory : public Screen {
public:
    Victory() : Screen("victory") {} 
    void display();

private:
    void choice();
};

#endif