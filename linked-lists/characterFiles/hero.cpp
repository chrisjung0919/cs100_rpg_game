#include "hero.h"
#include "enemy.h"
#include <iostream>
#include <string>
#include <vector>
#include <stdexcept>

// constructors
hero::hero():character(), currency(0), potion(1) {}
hero::hero(std::string name, int hp, int maxhp, int dmg, int lvl, int exp, int expCap, int currency, int potion):character(name,hp,maxhp,dmg,lvl,exp,expCap),currency(currency),potion(potion){}

cowboy::cowboy():hero("Cowboy", 100, 100, 25, 1, 0, 10, 0, 1) {}
scientist::scientist():hero("Scientist", 90, 90, 25 , 1, 0, 10, 0, 1) {}
archer::archer():hero("Archer", 80, 80, 25, 1, 0, 10, 0, 1) {}
// getters
int hero::getCurrency() const {return currency;}
int hero::getPotion()   const {return potion;}
bool hero::getAbilityUsed() const {return abilityUsed;}
bool hero::getCritHit() const {return critHit;}
// setters
void hero::setCurrency(int C) {
    if (C < 0) {
        throw std::invalid_argument("Invalid param");
    }
    currency = C;
}
void hero::setPotion(int P) {
    if (P < 0) {
        throw std::invalid_argument("Invalid param");
    }
    potion = P;
}
void hero::setAbilityUsed(bool isUsed) {abilityUsed = isUsed;}
void hero::setCritHit(bool isCrit) {critHit = isCrit;}

void hero::rest() {
    std::cout << "You take a rest and recover 30 HP." << std::endl;
    if (getHealth() == getMaxHealth()) {
        std::cout << "Health is full" << std::endl;
    } else if (getHealth() + 30 > getMaxHealth()) {
        setHealth(getMaxHealth());
    } else {
        setHealth(getHealth() + 30);
    }
}

void hero::expIncrease(enemy& enemy) {
    setExp(getExp() + enemy.getExpDrop());
}

void hero::currencyIncrease(enemy& enemy) {
    setCurrency(getCurrency() + enemy.getCurrencyDrop());
}

void cowboy::ability(enemy& enemy) {
    if (getAbilityUsed()) {
        std::cout << "Ability has already been used." << std::endl;
        return;
    }
    std::cout << "Cowboy ability activated!" << std::endl;
    originalHealth = getHealth();
    setHealth(getHealth() + 50);
    std::cout << "Health increased from " << originalHealth << " to " << getHealth() << std::endl;
    setAbilityUsed(true);
    std::cout << "The enemy is stunned!" << std::endl;
    enemy.setStun(true);
}

void scientist::ability(enemy& enemy) {
    if (getAbilityUsed()) {
        std::cout << "Ability has already been used." << std::endl;
        return;
    }
    std::cout << "Scientist ability activated!" << std::endl;
    int originalDMG = getDMG();
    setDMG(getDMG() + 20);
    std::cout << "Damage increased from " << originalDMG << " to " << getDMG() << std::endl;
    setAbilityUsed(true);
    enemy.setStun(true);
}

void archer::ability(enemy& enemy) {
    if (getAbilityUsed()) {
        std::cout << "Ability has already been used." << std::endl;
        return;
    }
    std::cout << "Archer ability activated!" << std::endl;
    std::cout << "Next attack will be a critical hit!" << std::endl;
    setCritHit(true);
    setAbilityUsed(true);
    enemy.setStun(true);
}

void hero::attack(int dmgDealt, character& receiver) {
    if (dmgDealt <= 0) {
        throw std::invalid_argument("attack:invalid param");
    }
    if (getCritHit()) {
        dmgDealt *= 2;
        std::cout << "Critical hit! Damage doubled to " << dmgDealt << std::endl;
        setCritHit(false);
    }
    int remainingHealth = receiver.getHealth() - dmgDealt;
    if (remainingHealth <=0 )   {
        remainingHealth = 0;
        std::cout << "Congrats on defeating the enemy :) \n";
    }
    receiver.setHealth(remainingHealth);
    std::cout << getName() << " dealt " << std::to_string(dmgDealt) << " dmg to " << receiver.getName() << std::endl;
}

void hero::usePotion() {
    int originalHealth = getHealth();
    if (getPotion() <= 0) {
        std::cout << "No potions left!" << std::endl;
        return;
    } else if (getHealth() == getMaxHealth()) {
        std::cout << "Health is already full!" << std::endl;
        return;
    } else if (getHealth() + 50 > getMaxHealth()) {
        std::cout << "Health is already full!" << std::endl;
        return;
    } else {
        setHealth(getHealth() + 50);
    }
    setPotion(getPotion() - 1);
    std::cout << "Used a potion! Health increased from " << originalHealth << " to " << getHealth() << ". Potions left: " << getPotion() << std::endl;
}

void hero::checkLvlUp() {
    while (getExp() >= getExpCap()){
        setLvl(getLvl() + 1);
        setExp(getExp() - getExpCap());
        setExpCap(getExpCap() * 2);
        setMaxHealth(getMaxHealth() + 10);
        setDMG(getDMG() + 5);
    }
}
