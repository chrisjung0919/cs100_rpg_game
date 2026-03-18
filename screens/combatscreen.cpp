#include <iostream>
#include <string>
#include <vector>
#include <cctype>
#include "combatscreen.h"

using namespace std;

static const vector<string> ART_COWBOY = {
    "     _______     ",
    "    /  ___  \\    ",
    "   / _/   \\_ \\   ",
    "  | | o   o | |  ",
    "  | |   ^   | |  ",
    "   \\_\\_____/_/   ",
    "      |   |      ",
    "     /|   |\\     ",
    "    / |   | \\    ",
};

static const vector<string> ART_SCIENTIST = {
    "    _________    ",
    "   | [_____] |   ",
    "   |  o   o  |   ",
    "   |    -    |   ",
    "    \\_______/    ",
    "    /|  |  |\\    ",
    "   / |  |  | \\   ",
    "  /__|__|__|__\\  ",
    " /___________\\   ",
};

static const vector<string> ART_ARCHER = {
    "      _____      ",
    "     /o   o\\     ",
    "     \\  ^  /     ",
    "      \\___/      ",
    "     ---|---     ",
    "      / | \\      ",
    "     /  |  \\     ",
    "    /   |   \\    ",
    "   /    |    \\   ",
};

static const vector<string> ART_SCORPION = {
    "   _( )_( )_     ",
    "  / o     o \\    ",
    " |   _____   |   ",
    " |  |=====|  |   ",
    "  \\_|_____|_/    ",
    "  |   |||   |    ",
    " /|  _|||_  |\\   ",
    "/ | / ||| \\ | \\  ",
    "   >--+++--<     ",
};

static const vector<string> ART_BANDIT = {
    "   __########    ",
    "  /  # # # #\\    ",
    " | (o)   (o) |   ",
    " |    ---    |   ",
    "  \\__________/   ",
    "   /|      |\\    ",
    "  / |      | \\   ",
    " /  |      |  \\  ",
    "/   |      |   \\ ",
};

static const vector<string> ART_LIZARD = {
    "  __   ___   __  ",
    " /  \\_/ ^ \\_/  \\ ",
    "| (o)       (o) |",
    "|    \\_____/    |",
    " \\____|   |____/ ",
    "      |   |      ",
    "     /|   |\\     ",
    "    / |   | \\    ",
    "   /__|___|__\\   ",
};

static const vector<string> ART_FINALBOSS = {
    " /\\__________/\\  ",
    "(  o          o )",
    "(    =^.  .^=   )",
    " \\___| \\/ |___/ ",
    "  __|  /\\  |__   ",
    " /   \\/  \\/   \\  ",
    "|   /  ||  \\   | ",
    "|  / __||__ \\  | ",
    "|_/    ||    \\_| ",
};

static string fixWidth(const string& s, size_t n) {
    if (s.size() >= n) return s.substr(0, n);
    return s + string(n - s.size(), ' ');
}

static string hpBar(int hp, int maxHp, int width = 14) {
    if (maxHp <= 0) maxHp = 1;
    int filled = hp * width / maxHp;
    string bar = "[";
    for (int i = 0; i < width; i++) bar += (i < filled ? '#' : '-');
    bar += "]";
    return bar;
}

static string expBar(int exp, int maxExp, int width = 12) {
    if (maxExp <= 0) maxExp = 1;
    int filled = exp * width / maxExp;
    string bar = "[";
    for (int i = 0; i < width; i++) bar += (i < filled ? '=' : '-');
    bar += "]";
    return bar;
}

static const vector<string>& getHeroArt(HeroType h) {
    switch (h) {
        case HeroType::COWBOY:    return ART_COWBOY;
        case HeroType::SCIENTIST: return ART_SCIENTIST;
        case HeroType::ARCHER:    return ART_ARCHER;
    }
    return ART_COWBOY;
}

static const vector<string>& getEnemyArt(EnemyType e) {
    switch (e) {
        case EnemyType::SCORPION:  return ART_SCORPION;
        case EnemyType::BANDIT:    return ART_BANDIT;
        case EnemyType::LIZARD:    return ART_LIZARD;
        case EnemyType::FINALBOSS: return ART_FINALBOSS;
    }
    return ART_SCORPION;
}

static string heroAbilityLabel(HeroType h) {
    switch (h) {
        case HeroType::COWBOY:    return "Quick Shot";
        case HeroType::SCIENTIST: return "Toxic Vial";
        case HeroType::ARCHER:    return "Piercing Shot";
    }
    return "Ability";
}

static void display(HeroType       heroType,
                    const HeroStats&  hero,
                    EnemyType      enemyType,
                    const EnemyStats& enemy,
                    bool isBoss) {

    const int W   = 68;
    const string BORDER_TOP = "+" + string(W, '=') + "+";
    const string BORDER_MID = "+" + string(W, '-') + "+";
    const string BORDER_BOT = "+" + string(W, '=') + "+";

    const int ART_W   = 18;
    const int GAP     = W - 2 - ART_W * 2;

    cout << "\n" << BORDER_TOP << "\n";
    {
        string title = isBoss ? "* FINAL BOSS BATTLE *" : "* BATTLE *";
        int lpad = (W - (int)title.size()) / 2;
        int rpad = W - lpad - (int)title.size();
        cout << "|" << string(lpad,' ') << title << string(rpad,' ') << "|\n";
    }
    cout << BORDER_MID << "\n";

    {
        string eName = enemy.name + "  LVL " + to_string(enemy.level);
        string hName = hero.name  + "  LVL " + to_string(hero.level);

        int leftW  = W / 2 - 1;
        int rightW = W - leftW - 2;
        cout << "| " << fixWidth(eName, leftW)
             << " " << fixWidth(hName, rightW) << " |\n";
    }
    cout << BORDER_MID << "\n";

    const auto& eArt = getEnemyArt(enemyType);
    const auto& hArt = getHeroArt(heroType);
    int artLines = 9;

    for (int i = 0; i < artLines; i++) {
        string eLine = (i < (int)eArt.size()) ? eArt[i] : "";
        string hLine = (i < (int)hArt.size()) ? hArt[i] : "";
        eLine = fixWidth(eLine, ART_W);
        hLine = fixWidth(hLine, ART_W);
        string gap   = string(GAP, ' ');

        cout << "| " << eLine << string(GAP,' ') << hLine << " |\n";
    }

    cout << BORDER_MID << "\n";
    {
        int halfW = W / 2 - 1;

        string eHp = "HP: " + hpBar(enemy.hp, enemy.maxHp) +
                     " " + to_string(enemy.hp) + "/" + to_string(enemy.maxHp);
        string hHp = "HP: " + hpBar(hero.hp, hero.maxHp) +
                     " " + to_string(hero.hp) + "/" + to_string(hero.maxHp);
        cout << "| " << fixWidth(eHp, halfW)
             << " " << fixWidth(hHp, W - halfW - 2) << " |\n";

        string eSt  = "STATUS: " + enemy.status;
        string hExp = "EXP: " + expBar(hero.exp, hero.maxExp) +
                      " " + to_string(hero.exp) + "/" + to_string(hero.maxExp);
        cout << "| " << fixWidth(eSt, halfW)
             << " " << fixWidth(hExp, W - halfW - 2) << " |\n";

        if (isBoss) {
            string phase = "PHASE: " + to_string(enemy.phase) +
                           "/" + to_string(enemy.totalPhases);
            string hSt  = "STATUS: Determined";
            cout << "| " << fixWidth(phase, halfW)
                 << " " << fixWidth(hSt, W - halfW - 2) << " |\n";
        }
    }

    cout << BORDER_MID << "\n";
    cout << "| COMBAT LOG:                                                        |\n";
    cout << "|                                                                    |\n";
    cout << "|                                                                    |\n";

    cout << BORDER_MID << "\n";
    string ability = heroAbilityLabel(heroType);

    if (isBoss) {
        cout << "| ! CRITICAL MOMENT - Choose wisely:                                |\n";
        cout << "|                                                                    |\n";
        cout << "|  [A]  Desperate Strike    - High risk, high reward (40-60 dmg)    |\n";
        string bLine = "|  [B]  Ultimate " + fixWidth(ability, 14) +
                       " - Powerful attack (50-70 dmg)      |";
        cout << bLine << "\n";
        cout << "|  [C]  Last Health Potion  - Restore 50 HP, lose turn              |\n";
        cout << "|  [D]  Defensive Stance    - Reduce next damage by 50%             |\n";
    } else {
        cout << "| YOUR TURN - Choose an action:                                      |\n";
        cout << "|                                                                    |\n";
        cout << "|  [A]  Attack              - Basic attack (damage: 15-20)          |\n";
        string bLine = "|  [B]  " + fixWidth(ability, 22) +
                       " - Special ability (damage: 25-30)  |";
        cout << bLine << "\n";
        cout << "|  [C]  Use Item            - Open inventory                        |\n";
        cout << "|  [D]  Run Away            - Attempt to flee (50% chance)          |\n";
    }

    cout << BORDER_BOT << "\n";
    cout << "Enter your choice [A/B/C/D]: ";
}

char runCombatScreen(HeroType       heroType,
                     const HeroStats&  hero,
                     EnemyType      enemyType,
                     const EnemyStats& enemy,
                     bool isBoss) {
    while (true) {
        display(heroType, hero, enemyType, enemy, isBoss);

        char input;
        cin >> input;
        cin.ignore();
        input = toupper(input);

        if (input == 'A' || input == 'B' ||
            input == 'C' || input == 'D') {
            return input;
        }

        cout << "\n  Invalid input. Please press [A], [B], [C], or [D].\n";
        cout << "  Press Enter to try again...";
        cin.get();
    }
}