#ifndef enemy_h
#define enemy_h

#include <iostream>
#include <vector>
#include <cstdlib>
#include "character.h"

using std::string;
using std::vector;
class hero;
class ability;

class enemy: public character {
        string name;
        int experienceDrop;
        int currencyDrop;
        vector<ability> abilities; 
        bool isStunned = false;

    public:
        enemy();
        enemy(string name);
        enemy(const hero&);
        int getExpDrop() const;
        int getCurrencyDrop() const;
        bool getStun() const;
        void setStun(bool);
        void addAbility (const ability&);
        void takeTurn (hero&);
};

class scorpion : public enemy{
    public:
        scorpion();
};

class bandit : public enemy{
    public:
        bandit();
};

class lizard : public enemy{
    public:
        lizard();
};

class finalBoss : public enemy{
    public:
        finalBoss();
};

class ability   {
        string name;

    public:
        ability();
        ability(const string&);
        void use(enemy& , hero& );
        int randDmg(const hero& ) const;
        string getAbilityName() const;
};

#endif