#ifndef STORYSCREEN_H
#define STORYSCREEN_H

#include <iostream>
#include <chrono>
#include <thread>
#include <fstream>
#include "../screen.h"

using namespace std;


class StoryScreen : public Screen {
public:
    string filename;
    string image;

    
    StoryScreen(string n, string f) : Screen(n), filename(f), image("") {}
    StoryScreen(string n, string f, string img) : Screen(n), filename(f), image(img) {}

    void display() override;
    void textDisplay();


    void choice() override;

private:
    string readFromFile(const string& path);
};

#endif