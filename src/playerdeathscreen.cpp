#include <iostream>
#include <string>
#include "playerdeathscreen.h"

using namespace std;

// ── showFinalStats()  (UML method) ───────────────────────────
static void showFinalStats(int finalLevel, int enemiesDefeated,
                           int itemsCollected, int goldEarned) {
    cout << "  FINAL STATS:\n";
    cout << "  ------------\n";
    cout << "  Final Level     : " << finalLevel      << "\n";
    cout << "  Enemies Defeated: " << enemiesDefeated << "\n";
    cout << "  Items Collected : " << itemsCollected  << "\n";
    cout << "  Gold Earned     : " << goldEarned      << "\n";
}

// ── display()  (UML method) ───────────────────────────────────
static void display(int finalLevel, int enemiesDefeated,
                    int itemsCollected, int goldEarned,
                    const string& deathMessage) {
    cout << "\n";
    cout << "+============================================================+\n";
    cout << "|                                                            |\n";
    cout << "|                  *** GAME  OVER ***                       |\n";
    cout << "|                                                            |\n";
    cout << "+============================================================+\n";
    cout << "\n";
    cout << "  " << deathMessage << "\n";
    cout << "\n";

    // ── defeated character ASCII art ──────────────────────────
    cout << "                        ___\n";
    cout << "                       /   \\\n";
    cout << "                      | X X |\n";
    cout << "                      |  ~  |\n";
    cout << "                       \\___/\n";
    cout << "                         |\n";
    cout << "                        /|\\\n";
    cout << "                       / | \\\n";
    cout << "\n";
    cout << "              Your journey ends here...\n";
    cout << "\n";
    cout << "+------------------------------------------------------------+\n";
    showFinalStats(finalLevel, enemiesDefeated, itemsCollected, goldEarned);
    cout << "+------------------------------------------------------------+\n";
    cout << "\n";
    cout << "  Press [ENTER] to return to main menu...\n";
}

// ── handleInput() / retry()  (UML methods) ───────────────────
void runPlayerDeathScreen(int finalLevel, int enemiesDefeated,
                          int itemsCollected, int goldEarned,
                          const string& deathMessage) {
    display(finalLevel, enemiesDefeated, itemsCollected,
            goldEarned, deathMessage);
    cin.ignore();   // wait for ENTER, then return to caller (startmenu)
}