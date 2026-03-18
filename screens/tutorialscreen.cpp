#include <iostream>
#include <cctype>
#include "tutorialscreen.h"

using namespace std;

void displayTutorialScreen() {
    cout << "+--------------------------------------------------------------+\n";
    cout << "|  \u25a0  TUTORIAL                                                  |\n";
    cout << "+--------------------------------------------------------------+\n";
    cout << "\n";
    cout << "  BASIC CONTROLS\n";
    cout << "  __________\n";
    cout << "\n";
    cout << "  Throughout the game, you'll make choices using letter keys:\n";
    cout << "\n";
    cout << "  * Press [A], [B], [C], etc. to select story choices\n";
    cout << "  * Press [I] to open your inventory at any time\n";
    cout << "  * Press [S] to view your character status\n";
    cout << "  * Press [Q] to quit to main menu\n";
    cout << "  * Press [ENTER] to confirm selections\n";
    cout << "\n";
    cout << "  COMBAT BASICS\n";
    cout << "  __________\n";
    cout << "\n";
    cout << "  When you encounter enemies, you'll enter turn-based combat:\n";
    cout << "\n";
    cout << "  * Choose to Attack, use Abilities, use Items, or Run\n";
    cout << "  * Each action takes one turn\n";
    cout << "  * Defeating enemies gives you EXP and rewards\n";
    cout << "  * Running away is always an option (but not guaranteed!)\n";
    cout << "\n";
    cout << "  LEVELING UP\n";
    cout << "  __________\n";
    cout << "\n";
    cout << "  * Gain experience by defeating enemies\n";
    cout << "  * Level up to increase your HP, Attack, and Defense\n";
    cout << "  * Higher levels unlock stronger abilities\n";
    cout << "\n";
    cout << "+--------------------------------------------------------------+\n";
    cout << "| [B] Back to Main Menu    |    [E] Start Game                 |\n";
    cout << "+--------------------------------------------------------------+\n";
    cout << "Enter your choice: ";
}

bool runTutorialScreen() {
    bool inTutorial = true;
    bool startGame  = false;

    while (inTutorial) {
        displayTutorialScreen();

        char input;
        cin >> input;
        cin.ignore();

        input = toupper(input);

        if (input == 'B') {
            inTutorial = false;
        } else if (input == 'E') {
            inTutorial = false;
            startGame  = true;
        } else {
            cout << "\n  Invalid choice. Press [B] to go back or [E] to start.\n";
            cout << "\nPress Enter to continue...";
            cin.get();
        }
    }

    return startGame;
}