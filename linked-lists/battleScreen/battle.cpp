#include "battle.h"
#include <iostream>
#include "lvlup.cpp"
using namespace std;

int battlecount = 0;
bool sideQuestchoice = false;
int sideQuestCounter = 0;

static void slowPrint(const string& msg) {
    for (char c : msg) {
        cout << c << flush;
        this_thread::sleep_for(chrono::milliseconds(70));
    }
    cout << "\n";
    cin.get();
}

void printBattleDisplay (){
        cout << "+--------------------------------------------------------------+\n";
        cout << "|                  BATTLE IS COMMENCING            |\n";
        cout << "           XX                             XXXX     " << endl;
        cout << "            XXXXXXXXX              XXXXXXXXXX      " << endl;
        cout << "            X       XX           XXX   X   X       " << endl;
        cout << "            XX       XXXX     XXXX        XX       " << endl;
        cout << "            XXX         XX  XXX         XXXX       " << endl;
        cout << "              XXXX        XXX         XX           " << endl;
        cout << "                 XXXX   XXX         XXX            " << endl;
        cout << "                     XXX          XXX              " << endl;
        cout << "                    XX          XXXXX              " << endl;
        cout << "                  XXX         XX     XX            " << endl;
        cout << "     XX         XX          XXX       XXXX         " << endl;
        cout << "      XXX    XXXX        XXX  XXXXX      X    XXXX " << endl;
        cout << "       XXXXXXX        XXXX        XXXX   XXXXXX    " << endl;
        cout << "         XXXX      XXXX              XXX XXXXX     " << endl;
        cout << "      XXXXXXXXXXXXX                    XXXXXXXXXXX " << endl;
        cout << "   XXXXXXXXXX XXX                     XXX XXXXXXXXX" << endl;
        cout << " XXXXXXXXXXX    XXXX                XXX     XXXXXX " << endl;
        cout << "XXXXXXXX           X                          XXX  " << endl;
        cout << "+--------------------------------------------------------------+\n";

    }

void BattleScreen::battle() {
    if (!sideQuestchoice){battlecount++;}
    while (currentHero->isAlive() && e.isAlive()) {
        cout << "\x1B[2J\x1B[1;1H";

        printBattleDisplay();

        heroTurn();
        if (!e.isAlive()) break;

        
        // check if enemy is stunned
        if (e.getStun()) {
            cout << e.getName() + " is stunned and skips their turn!" << endl;
            e.takeTurn(*currentHero);
        } else {
            enemyTurn();
        }
        slowPrint("Press enter to continue " );
    }

    if (currentHero->isAlive()) {
        cout << "\n+--------------------------------------------------------------+\n";
        textDisplay("  Nice job! You defeated " + e.getName() + "!");
        cout << "  +" << e.getExpDrop()      << " EXP\n";
        cout << "  +" << e.getCurrencyDrop() << " currency\n";
        currentHero->currencyIncrease(e);
        currentHero->expIncrease(e);
        currentHero->checkLvlUp();
        levelupDisplay();
        restoreHealth();
        cin.get();
    } else {
        cout << "\n+--------------------------------------------------------------+\n";
        textDisplay("  You were defeated by " + e.getName() + "...");
        cout << "+--------------------------------------------------------------+\n";
        restoreHealth();
        cout << "  Press Enter to continue...\n";
        cin.get();

        redoNodes("deathScreen");
        return;
    }
    //rudimentary but checks what battle it is since each battle has a different ending
    if(!sideQuestchoice){
        if(battlecount == 1)
                redoNodes("side1"); 
        if(battlecount == 2)
                redoNodes("side2"); 
        if(battlecount == 3)
                redoNodes("henchman2"); 
        if(battlecount == 4)
                redoNodes("end");
        if(battlecount == 5) 
                redoNodes("victory");
    }
    else {
        sideQuestCounter++;
        if (sideQuestCounter == 1){redoNodes("middle");}
        else if (sideQuestCounter ==2 ){redoNodes("henchman1");}
        else {return;}
    }
    currentHero->setAbilityUsed(false);
    sideQuestchoice = false;
}

void BattleScreen::display() {

        battle();

}


void BattleScreen::printStatus() {
    if (!currentHero) return;
    //return text to the position where the display is
    cout << "\n";
    cout << "  " << currentHero->getName()
         << " | HP: "      << currentHero->getHealth()
         << "/"            << currentHero->getMaxHealth()
         << " | Potions: " << currentHero->getPotion()
         << " | LVL: "     << currentHero->getLvl()
         << " | EXP: "     << currentHero->getExp()
         << "/"            << currentHero->getExpCap() 
         << " | CURRENCY: " << currentHero->getCurrency()
         << "\n";


    cout << "  " << e.getName()
         << " | HP: "      << e.getHealth()
         << "/"            << e.getMaxHealth() << "\n";
    cout << "+--------------------------------------------------------------+\n";
}


void BattleScreen::restoreHealth() {
    if (!currentHero) return;
    currentHero->setHealth(currentHero->getMaxHealth());
    cout << "  You have been restored to full health.\n";
}

void BattleScreen::heroTurn() {
    
    attackMenu();
}

void BattleScreen::attackMenu() {

    if (!currentHero) { 
        cout << "  Error: no hero found!\n";
        return;
    }

    cout << "\n  What will you do?\n";
    cout << "  [A] Attack\n";
    cout << "  [B] Use Ability";
    if (currentHero->getAbilityUsed()) cout << " (already used)";
    cout << "\n";
    cout << "  [C] Use Potion";
    if (currentHero->getPotion() <= 0) cout << " (none left)";
    cout << "\n";
    cout << "  Choose: ";

    char input;
    cin >> input;
    cin.ignore();
    input = toupper(input);

    switch(input) {
        case 'A':
            currentHero->attack(currentHero->getDMG(), e);
            break;
        case 'B':
            if (currentHero->getAbilityUsed()) {
                cout << "  Ability already used!\n";
                attackMenu();
                return;
            }
            currentHero->ability(e);
            break;
        case 'C':
            if (currentHero->getPotion() <= 0) {
                cout << "  No potions left!\n";
                attackMenu();
                return;
            }
            currentHero->usePotion();
            break;
        default:
            cout << "  Invalid choice, try again.\n";
            attackMenu();
            return;
    }
    printStatus();
}

void BattleScreen::enemyTurn() {
    cout << "\n  " << e.getName() << "'s turn...\n";
    e.takeTurn(*currentHero);
    printStatus();
}

void BattleScreen::textDisplay(const string& message) {
    cout << "\n  >> ";
    slowPrint(message);
}

void BattleScreen::choice() {
    // handled inside battle() loop
}


