#ifndef BATTLE_H
#define BATTLE_H

#include <iostream>
#include <chrono>
#include <thread>
#include "../characterFiles/character.h"
#include "../characterFiles/enemy.h"
#include "../characterFiles/hero.h"
#include "../screen.h"

using namespace std;

extern int battlecount;
extern bool sideQuestchoice;
extern int sideQuestCounter;

class BattleScreen : public Screen {
public:
    BattleScreen(enemy& e) : Screen("battle"), e(e){}

    void display() override;
    void choice() override;


private:
    enemy& e;

    void battle();
    void heroTurn();
    void enemyTurn();
    void attackMenu();
    void printStatus();
    void textDisplay(const string& message);
    void restoreHealth();
};

#endif