#include <iostream>
#include <string>
#include "deathScreen.h"


using namespace std;

// ── showFinalStats()  (UML method) ───────────────────────────
static void showFinalStats() {
    cout << "  FINAL STATS:\n";
    cout << "  ------------\n";
    cout << "  Final Level     : " << currentHero->getLvl()    << "\n";
    cout << "  Enemies Defeated: " << battlecount << "\n";
    cout << "  Gold Earned     : " << currentHero->getCurrency()      << "\n";
}


// ── display()  (UML method) ───────────────────────────────────
void deathScreen::display() {
    cout << "\n";
    cout << "+============================================================+\n";
    cout << "|                                                            |\n";
    cout << "|                  *** GAME  OVER ***                       |\n";
    cout << "|                                                            |\n";
    cout << "+============================================================+\n";
    cout << "\n";
    cout << "  " << "you have fought long and hard but you have fell victim to the terrible tyrants of the land" << "\n";
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
    showFinalStats();
    cout << "+------------------------------------------------------------+\n";
    cout << "\n";
    cout << "  Press [R] to rechoose hero    [Q] main menu\n";
    deathScreen::choice();
}

void deathScreen::choice() {
    char input;
    cin >> input;
    cin.ignore();
    input = toupper(input);

    switch(input) {
        case 'R': redoNodes("classSelect"); break;  // restart from class select
        case 'Q': redoNodes("mainMenu");    break;
        default:
            cout << "Invalid choice, try again.\n";
            choice();
    }
}