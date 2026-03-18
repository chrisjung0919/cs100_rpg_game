#include <iostream>
#include <cstdlib>
#include "character.h"
#include "enemy.h"
#include "hero.h"

using std::string;
using std::vector;


ability::ability():name("none"){}
ability::ability(const string& n):name(n){
    if (n == "")  {
        throw invalid_argument("invalid constructor");
}
}

void ability::use(enemy& attacker, hero& target ) {
    cout << attacker.getName() << " uses " << name << " on " << target.getName() << endl;
    attacker.attack(randDmg(target), target);
}

int ability::randDmg(const hero& target) const{
    int maxDmg = 0;
    if (target.getMaxHealth()< 10)    {
        maxDmg = 1;
    }

    else {
        maxDmg = target.getMaxHealth()/10;
    }

    int dmg = 1+ rand() % (maxDmg);
    return dmg;
}

string ability::getAbilityName() const {
    return name;
}

enemy::enemy() : experienceDrop(1), currencyDrop(1){}
enemy::enemy(string name) : character(name), experienceDrop(1), currencyDrop(1) {}
enemy::enemy(const hero& target):experienceDrop(1 + rand() % target.getLvl()),currencyDrop( 1 + rand()% target.getMaxHealth()) {
    int level = target.getLvl() / 5;
    if (level == 0)    {
        level = 1; 
    }
    setLvl(level * 5);
}

int enemy::getExpDrop() const{
    return experienceDrop;
}

int enemy::getCurrencyDrop() const{
    return currencyDrop;
}

void enemy::addAbility (const ability& a){
    abilities.push_back(a);
}

void enemy::takeTurn (hero& target){
    if(abilities.empty())    {
        cout << getName() << " has no abilities!\n";
        return;
    }
    if (isStunned) {
        cout << getName() << " is stunned and cannot take a turn!\n";
        setStun(false);
        return;
    }
    int idx = rand() % abilities.size();
    abilities[idx].use(*this,target);
}

void enemy::setStun(bool stun) {
    isStunned = stun;
}

bool enemy::getStun() const{
    return isStunned;
}

scorpion::scorpion() : enemy("scorpion")    {
    addAbility(ability ("sting"));
    addAbility(ability("sweeping tail"));
    addAbility(ability("clamp"));
    addAbility(ability("strike"));
}

bandit::bandit(): enemy("bandit"){
    addAbility(ability("backstab"));
    addAbility(ability("kick"));
    addAbility(ability("shoot"));
    addAbility(ability("slam"));
}

lizard::lizard() : enemy("lizard"){
    addAbility(ability("bite"));
    addAbility(ability("tail swipe"));
    addAbility(ability("acid spit"));
    addAbility(ability("bash"));
}

finalBoss::finalBoss() : enemy("final boss"){
    addAbility(ability("venom spit"));
    addAbility(ability("coiling crush"));
    addAbility(ability("lunging fang"));
    addAbility(ability("slithering strike"));
}
