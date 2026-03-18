#include "../characterFiles/character.h"
#include "../characterFiles/enemy.h"
#include "../characterFiles/hero.h"
#include "../screen.h"

static void levelupDisplay() {
    cout << "\n";
    cout << "+============================================================+\n";
    cout << "|                                                            |\n";
    cout << "|                  * LEVEL UP! *                            |\n";
    cout << "|                                                            |\n";
    cout << "+============================================================+\n";
    cout << "\n";
    cout << "\n";
     cout << " | LVL: "     << currentHero->getLvl();
     cout << " | EXP: "     << currentHero->getExp();

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
    cout << "  MAXHP:      " << currentHero->getMaxHealth();
    cout << "  XP:      " << currentHero->getExp();
    cout << "  CURRENCY:  " << currentHero->getCurrency();
    cout << "\n";
    cout << "              You feel stronger!\n";
    cout << "\n";
    cout << "+------------------------------------------------------------+\n";
    cout << "| Press [ENTER] to continue                                  |\n";
    cout << "+------------------------------------------------------------+\n";
}
