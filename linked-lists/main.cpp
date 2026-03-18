#include <iostream>
#include "screen.h"
#include "tutorialCode/tutorial.h"
#include <chrono>
#include <ctime>
#include <thread> 
#include <fstream>
#include "StoryScreenCode/storyScreen.h"
#include "classSelection/classSelection.h"
#include "battleScreen/battle.h"
#include "victoryScreen/victory.h"
#include "deathScreen/deathScreen.h"

#include <map>


map<string, Screen*> screens;
hero* currentHero = nullptr;


int main(){
    sideQuestchoice = false;
    sideQuestCounter = 0;
    StoryScreen mainScreen("beginning","storyScreens/mainMenu.txt");
        TutorialScreen tutorial;
        ClassSelectionScreen classSelect;
    
    StoryScreen beginning("beginning","storyText/beginning.txt", "storyScreens/image1.txt");
            scorpion enemy1;
            BattleScreen battle(enemy1);
    //sidequest 1 
    StoryScreen side1("side1", "storyText/side1.txt", "storyScreens/image1.txt");

        StoryScreen middle("middle","storyText/middle.txt");
            bandit enemy2;
            BattleScreen battle2(enemy2);

    //sidequest 2
    StoryScreen side2("side2", "storyText/side2.txt", "storyScreens/image1.txt");


        StoryScreen henchman1("beginning","storyText/henchmanFight.txt");
            lizard enemy3;
            BattleScreen battle3(enemy3);

            StoryScreen henchman2("beginning","storyText/henchmanFight2.txt");
                lizard enemy4;
                BattleScreen battle4(enemy4);
        
            StoryScreen end("end","storyText/end.txt");
                finalBoss enemy5;
                BattleScreen battle5(enemy5);
        
        Victory victory;
        deathScreen death;
        StoryScreen credits("credits","storyText/credits.txt");

   

    screens["mainMenu"]  = &mainScreen;
    screens["tutorial"]  = &tutorial;
    screens["classSelect"] = &classSelect;
        screens["beginning"] = &beginning;
            screens["battle"]   = &battle;
        screens["side1"] = &side1;
            screens["middle"]  = &middle;
                screens["battle2"]   = &battle2;
        screens["side2"] = &side2;
            screens["henchman1"] = &henchman1;
                screens["battle3"]   = &battle3;
            screens["henchman2"] = &henchman2;
                screens["battle4"]   = &battle4;
            screens["end"]       = &end;
                screens["battle5"]   = &battle5;

        screens["victory"]       = &victory;
        screens["deathScreen"] = &death;
    screens["credits"]       = &credits;



    beginning.nextScreen = &battle;
    side1.nextScreen = &middle;
    middle.nextScreen = &battle2;
    side2.nextScreen = &henchman1;
    henchman1.nextScreen = &battle3;
    henchman2.nextScreen = &battle4;
    end.nextScreen = &battle5;

    //start at this specific node
    Screen* curr = &mainScreen;
    //escape code to clear each screen
    const string clearScreen = "\x1B[2J\x1B[1;1H";

    cout << clearScreen;
    while (curr != nullptr) {
        cout << clearScreen;
        curr->display();
        curr = curr->nextScreen;
    }

    return 0;
}


