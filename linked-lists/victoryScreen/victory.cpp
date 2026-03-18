#include "victory.h"
#include "../battleScreen/battle.h"
#include <iostream>


static void showFinalStats() {
    cout << "  FINAL STATS:\n";
    cout << "  ------------\n";
    cout << "  Final Level     : " << currentHero->getLvl()    << "\n";
    cout << "  Enemies Defeated: " << battlecount << "\n";
    cout << "  Gold Earned     : " << currentHero->getCurrency()      << "\n";
}

void Victory::display() {
    cout << "\n";
    cout << "+============================================================+\n";
    cout << "|                                                            |\n";
    cout << "|               *** VICTORY!  VICTORY! ***                  |\n";
    cout << "|                                                            |\n";
    cout << "+============================================================+\n";
    cout << "\n";
    cout << "            You defeated the final boss!\n";
    cout << "\n";
    cout << "              * * * * * * * * * * * * *\n";
    cout << "            *                           *\n";
    cout << "           *           \\O/               *\n";
    cout << "           *            |                *\n";
    cout << "           *           / \\               *\n";
    cout << "            *                           *\n";
    cout << "              * * * * * * * * * * * * *\n";
    cout << "\n";
    cout << "                The realm is saved!\n";
    cout << "\n";
    cout << "+------------------------------------------------------------+\n";
    showFinalStats();
    cout << "+------------------------------------------------------------+\n";
    cout << "\n";
    Victory::choice();
}

void Victory::choice() {
    redoNodes("credits");
}