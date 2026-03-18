#include "classSelection.h"
#include <iostream>
using namespace std;

void printStatBar(int filled, int total) {
    cout << "[";
    for (int i = 0; i < total; i++)
        cout << (i < filled ? "#" : "-");
    cout << "]";
}

void ClassSelectionScreen::display() {
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
    cout << "  | |  |____|  |   |   | |_________|    |   |   /            |\n";
    cout << "  |  \\_________|   |   |    |     |     |   |  /             |\n";
    cout << "  | /____________\\ |   |    |_____|     |   | /              |\n";
    cout << "  |                |   |                |   |                |\n";
    cout << "  +----------------+   +----------------+   +----------------+\n";
    cout << "\n";

    cout << "  HP:  "; printStatBar(10, 10); cout << " 100   ";
    cout << "HP:  "; printStatBar(9, 10);  cout << " 90    ";
    cout << "HP:  "; printStatBar(8, 10);  cout << " 80\n";

    cout << "  ATK: "; printStatBar(5, 10); cout << " 10    ";
    cout << "ATK: "; printStatBar(10, 10); cout << " 20    ";
    cout << "ATK: "; printStatBar(8, 10); cout << " 30\n";

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

    choice();
}

void ClassSelectionScreen::choice() {
    char input;
    cin >> input;
    cin.ignore();
    input = toupper(input);

    // clean up previous hero if re-selecting
    delete currentHero;
    currentHero = nullptr;

    switch(input) {
        case 'A':
            currentHero = new cowboy();
            cout << "\n  You chose: COWBOY - Quick draw and high damage!\n";
            cout << "  Press Enter to begin...\n";
            cin.get();
            redoNodes("beginning");
            break;
        case 'B':
            currentHero = new scientist();
            cout << "\n  You chose: SCIENTIST - Master of strange potions & science!\n";
            cout << "  Press Enter to begin...\n";
            cin.get();
            redoNodes("beginning");
            break;
        case 'C':
            currentHero = new archer();
            cout << "\n  You chose: ARCHER - Precision and range attacks!\n";
            cout << "  Press Enter to begin...\n";
            cin.get();
            redoNodes("beginning");
            break;
        case 'Q':
            redoNodes("mainMenu");
            break;
        default:
            cout << "\n  Invalid choice, try again.\n";
            choice();
    }
}