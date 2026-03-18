#include <iostream>
#include "levelupscreen.h"

using namespace std;

static void display(int newLevel,
                    int oldHp,  int hpIncrease,
                    int oldAtk, int atkIncrease,
                    int oldDef, int defIncrease) {
    cout << "\n";
    cout << "+============================================================+\n";
    cout << "|                                                            |\n";
    cout << "|                  * LEVEL UP! *                            |\n";
    cout << "|                                                            |\n";
    cout << "+============================================================+\n";
    cout << "\n";
    cout << "            You reached Level " << newLevel << "!\n";
    cout << "\n";

    cout << "                      *   *   *\n";
    cout << "                   *           *\n";
    cout << "                 *    * * * *    *\n";
    cout << "                *   *    O    *   *\n";
    cout << "                *   *   /|\\   *   *\n";
    cout << "                *   *   / \\   *   *\n";
    cout << "                 *    * * * *    *\n";
    cout << "                   *           *\n";
    cout << "                      *   *   *\n";
    cout << "\n";

    cout << "  STAT INCREASES:\n";
    cout << "  ---------------\n";
    cout << "  HP:      +" << hpIncrease
         << "  (" << oldHp  << " -> " << oldHp  + hpIncrease  << ")\n";
    cout << "  ATTACK:  +" << atkIncrease
         << "  (" << oldAtk << " -> " << oldAtk + atkIncrease << ")\n";
    cout << "  DEFENSE: +" << defIncrease
         << "  (" << oldDef << " -> " << oldDef + defIncrease << ")\n";
    cout << "\n";
    cout << "              You feel stronger!\n";
    cout << "\n";
    cout << "+------------------------------------------------------------+\n";
    cout << "| Press [ENTER] to continue                                  |\n";
    cout << "+------------------------------------------------------------+\n";
}

void runLevelUpScreen(int newLevel,
                      int oldHp,  int hpIncrease,
                      int oldAtk, int atkIncrease,
                      int oldDef, int defIncrease) {
    display(newLevel, oldHp, hpIncrease, oldAtk, atkIncrease, oldDef, defIncrease);
    cin.ignore();   // wait for ENTER, then return to caller (startmenu)
}
