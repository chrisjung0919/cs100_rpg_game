#include <iostream>
#include "victoryscreen.h"

using namespace std;

extern void displayTitleScreen();
extern int main();

static void showFinalStats(int finalLevel, int enemiesDefeated,
                           int itemsCollected, int goldEarned) {
    cout << "  FINAL STATS:\n";
    cout << "  ------------\n";
    cout << "  Final Level     : " << finalLevel      << "\n";
    cout << "  Enemies Defeated: " << enemiesDefeated << "\n";
    cout << "  Items Collected : " << itemsCollected  << "\n";
    cout << "  Gold Earned     : " << goldEarned      << "\n";
}

static void display(int finalLevel, int enemiesDefeated,
                    int itemsCollected, int goldEarned) {
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
    showFinalStats(finalLevel, enemiesDefeated, itemsCollected, goldEarned);
    cout << "+------------------------------------------------------------+\n";
    cout << "\n";
    cout << "  Press [ENTER] to return to main menu...\n";
}

void runVictoryScreen(int finalLevel, int enemiesDefeated,
                      int itemsCollected, int goldEarned) {
    display(finalLevel, enemiesDefeated, itemsCollected, goldEarned);
    cin.get();


    main();
}