#include <iostream>
#include <cctype>
#include "classselection.h"

using namespace std;

static string heroClasses[3] = { "COWBOY", "SCIENTIST", "ARCHER" };

static void printStatBar(int filled, int total) {
    cout << "[";
    for (int i = 0; i < total; i++) {
        cout << (i < filled ? "#" : "-");
    }
    cout << "]";
}

void displayClassSelectionScreen() {
    cout << "+--------------------------------------------------------------+\n";
    cout << "|                     CHOOSE YOUR HERO                        |\n";
    cout << "+--------------------------------------------------------------+\n";
    cout << "\n";
    cout << "  [A] COWBOY            [B] SCIENTIST         [C] ARCHER\n";
    cout << "\n";

    cout << "  +----------------+   +----------------+   +----------------+\n";
    cout << "  |                |   |                |   |                |\n";
    cout << "  |  __________    |   |    _______     |   |  \\             |\n";
    cout << "  | /          \\   |   |    |     |     |   |   \\            |\n";
    cout << "  | |  ______  |   |   | ___|     |___  |   |   (--------->  |\n";
    cout << "  | |  |____|  |   |   | |___________|  |   |   /            |\n";
    cout << "  |  \\_________|   |   |    |     |     |   |  /             |\n";
    cout << "  | /____________\\ |   |    |_____|     |   | /              |\n";
    cout << "  |                |   |                |   |                |\n";
    cout << "  +----------------+   +----------------+   +----------------+\n";
    cout << "\n";

    cout << "  HP:  "; printStatBar(8, 10); cout << " 80    ";
    cout << "HP:  "; printStatBar(6, 10); cout << " 60    ";
    cout << "HP:  "; printStatBar(7, 10); cout << " 70\n";

    cout << "  ATK: "; printStatBar(8, 10); cout << " 80    ";
    cout << "ATK: "; printStatBar(4, 10); cout << " 40    ";
    cout << "ATK: "; printStatBar(6, 10); cout << " 60\n";

    cout << "  SPD: "; printStatBar(4, 10); cout << " 40    ";
    cout << "SPD: "; printStatBar(8, 10); cout << " 80    ";
    cout << "SPD: "; printStatBar(7, 10); cout << " 70\n";

    cout << "\n";
    cout << "  \"Quick draw and      \"Master of strange    \"Precision and\n";
    cout << "   high damage\"         potions & science\"    range attacks\"\n";
    cout << "\n";
    cout << "  Ability: Quick Shot   Ability: Toxic Vial   Ability: Piercing Shot\n";
    cout << "\n";
    cout << "+--------------------------------------------------------------+\n";
    cout << "| Select your class [A/B/C] or [Q] to return to main menu     |\n";
    cout << "+--------------------------------------------------------------+\n";
    cout << "Enter your choice: ";
}

HeroClass runClassSelectionScreen() {
    HeroClass chosen = HeroClass::NONE;
    bool inScreen = true;

    while (inScreen) {
        displayClassSelectionScreen();

        char input;
        cin >> input;
        cin.ignore();

        input = toupper(input);

        switch (input) {
            case 'A':
                chosen = HeroClass::COWBOY;
                cout << "\n  You chose: COWBOY - Quick draw and high damage!\n";
                inScreen = false;
                break;
            case 'B':
                chosen = HeroClass::SCIENTIST;
                cout << "\n  You chose: SCIENTIST - Master of strange potions & science!\n";
                inScreen = false;
                break;
            case 'C':
                chosen = HeroClass::ARCHER;
                cout << "\n  You chose: ARCHER - Precision and range attacks!\n";
                inScreen = false;
                break;
            case 'Q':
                inScreen = false;
                break;
            default:
                cout << "\n  Invalid choice. Press [A], [B], [C], or [Q].\n";
                cout << "Press Enter to continue...";
                cin.get();
        }
    }

    return chosen;
}