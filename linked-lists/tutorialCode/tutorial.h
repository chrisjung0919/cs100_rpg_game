#ifndef TUTORIAL_H
#define TUTORIAL_H

#include <iostream>
#include <chrono>
#include <ctime>
#include <thread>
#include <fstream>
#include "../screen.h"

using namespace std;

class TutorialScreen : public Screen {
public:
    TutorialScreen() : Screen("tutorial") {} 
    void display();

private:
    void choice();
};

#endif