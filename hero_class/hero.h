#ifndef hero_h
#define hero_h

#include "character.h"
#include <string>
#include <vector>

class enemy;

class hero : public character {
    private:
        int currency;
        int potion;
        bool abilityUsed = false;
        bool critHit = false;
    public:
    // constructors
        hero();
        hero(std::string, int, int, int, int, int, int, int, int);
        
    // getters
        int getCurrency() const;
        int getPotion() const;
        bool getAbilityUsed() const;
        bool getCritHit() const;

    // setters
        void setCurrency(int);
        void setPotion(int);
        void setAbilityUsed(bool);
        void setCritHit(bool);

    // extra functions
        void rest();
        void expIncrease(enemy&);
        void currencyIncrease(enemy&);
        virtual void ability(enemy&){}
        virtual void attack(int, character&) override;
        void usePotion();
        void checkLvlUp();
};
        


class cowboy : public hero {
    private:
        int originalHealth = 0;
    public:
        cowboy();
        virtual void ability(enemy&) override;
};

class scientist : public hero {
    public:
        scientist();
        virtual void ability(enemy&) override;
};

class archer : public hero {
    public:
        archer();
        virtual void ability(enemy&) override;
};


#endif
