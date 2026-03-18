#include "screen.h"
#include <iostream>
using namespace std;

//constructor
Screen::Screen(std::string n) {
    name = n;
    nextScreen = nullptr;
}

Screen::~Screen() {}

void Screen::display() {
    cout << endl << name <<endl;
    cout << "Press Enter...";
}

