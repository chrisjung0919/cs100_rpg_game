#pragma once
#include <string>

enum class HeroType  { COWBOY, SCIENTIST, ARCHER };
enum class EnemyType { SCORPION, BANDIT, LIZARD, FINALBOSS };

struct HeroStats {
    std::string name;
    int         level;
    int         hp;
    int         maxHp;
    int         exp;
    int         maxExp;
};

struct EnemyStats {
    std::string name;
    int         level;
    int         hp;
    int         maxHp;
    std::string status;

    int         phase      = 1;
    int         totalPhases= 1;
    int         bossExp    = 0;
    int         bossMaxExp = 0;
};

char runCombatScreen(HeroType       heroType,
                     const HeroStats&  hero,
                     EnemyType      enemyType,
                     const EnemyStats& enemy,
                     bool isBoss = false);