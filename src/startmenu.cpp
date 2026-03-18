#include <iostream>
#include <fstream>
#include <string>
#include <cctype>
#include "tutorialscreen.h"
#include "classselection.h"
#include "victoryscreen.h"
#include "playerdeathscreen.h"

using namespace std;

void creditsStub() { cout << "\nOpening Credits Screen...\n"; }

// ── Reads and prints every line from a text file ──────────────
static void printFile(const string& filename) {
    ifstream file(filename);
    if (!file.is_open()) {
        cout << "[ERROR] Could not open: " << filename << "\n";
        return;
    }
    string line;
    while (getline(file, line)) {
        cout << line << "\n";
    }
    file.close();
}

void displayTitleScreen() {
    printFile("titlescreen.txt");
}

int main() {
    char choice;
    bool running = true;

    while (running) {
        displayTitleScreen();
        cout << "Enter choice: ";
        cin >> choice;
        cin.ignore();

        choice = toupper(choice);

        switch (choice) {
            case 'A': {
                HeroClass selected = runClassSelectionScreen();
                if (selected != HeroClass::NONE) {
                    cout << "\nStarting game...\n";
                    cout << "\nPress Enter to continue...";
                    cin.get();
                }
                continue;
            }

            case 'B': {
                bool wantsToStart = runTutorialScreen();
                if (wantsToStart) {
                    HeroClass selected = runClassSelectionScreen();
                    if (selected != HeroClass::NONE) {
                        cout << "\nStarting game...\n";
                        cout << "\nPress Enter to continue...";
                        cin.get();
                    }
                }
                continue;
            }

            case 'C':
                creditsStub();
                break;

            case 'Q':
                cout << "\nExiting game. Goodbye!\n";
                running = false;
                break;

            default:
                cout << "\nInvalid choice. Please try again.\n";
        }

        if (running) {
            cout << "\nPress Enter to return to menu...";
            cin.get();
        }

        cout << "\n\n";
    }

    return 0;
}