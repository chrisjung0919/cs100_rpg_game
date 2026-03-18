#ifndef DEATHSCREEN_H
#define DEATHSCREEN_H

#include <iostream>
#include <chrono>
#include <ctime>
#include <thread>
#include <fstream>
#include "../screen.h"
#include "../battleScreen/battle.h"



using namespace std;

class deathScreen : public Screen {
public:
    deathScreen() : Screen("death screen") {} 
    void display();

private:
    void choice();
};

#endif