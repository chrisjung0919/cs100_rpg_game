#include "character.h"
#include <iostream>
#include <cstdlib>

using std::string;
using std::cout;
using std::endl;
using std::invalid_argument;

//constructors
character::character():name("none"),health(100),maxHealth(100),dmg(1),lvl(1),exp(0),expCap(10){}
character::character(const string& n):name(n),health(100),maxHealth(100),dmg(1),lvl(1),exp(0),expCap(10){
    if (n == "")  {
        throw invalid_argument("invalid constructor");
    }
}
character::character(const string& n,int h, int m,int d,int l,int e,int c):name(n),health(h),maxHealth(m),dmg(d),lvl(l),exp(e),expCap(c){
    if (n == "" || h < 0 || m < 0 || d <0 || l<0 || e<0 || c<0)  {
        throw invalid_argument("invalid constructor");
    }
}

//getters
string character::getName()     const{return name;}
int    character::getHealth()   const{return health;}
int    character::getMaxHealth()const{return maxHealth;}
int    character::getDMG()      const{return dmg;}
int    character::getLvl()      const{return lvl;}
int    character::getExp()      const{return exp;}
int    character::getExpCap()   const{return expCap;}

//setter
void character::setName    (const string& n) {
    if (n == "") {
        throw std::invalid_argument("setName:passes invalid string");
    }
    name = n;
}
void character::setHealth  (int h)    {
    if (h < 0) {
        throw std::invalid_argument("setHealth:invalid param");
    }
    health = h;
}
void character::setMaxHealth  (int h)    {
    if (h < 0) {
        throw std::invalid_argument("setHealth:invalid param");
    }
    maxHealth = h;
}
void character::setDMG     (int d)    {
    if (d <= 0) {
        throw std::invalid_argument("setDMG:invalid param");
    }
    dmg = d;
}
void character::setLvl     (int l)    {
    if (l <= 0) {
        throw std::invalid_argument("setLvl:invalid param");
    }
    lvl = l;
}
void character::setExp     (int e)    {
    if (e < 0) {
        throw std::invalid_argument("setExp:invalid param");
    }
    exp = e;
}
void character::setExpCap  (int c)    {
    if (c <= 0) {
        throw std::invalid_argument("setExpCap:invalid param");
    }
    expCap = c;
}

//extra funcitons
bool character::isAlive()  const{
    return (health > 0);
}

void character::attack (int dmgDealt, character & receiver) {
    if (dmgDealt <= 0) {
        throw std::invalid_argument("attack:invalid param");
    }

    int remainingHealth = receiver.getHealth() - dmgDealt;
    if (remainingHealth <=0 )   {
        remainingHealth = 0;
        cout << "Congrats on defeating the enemy :) \n";  //have to end battle here and idk if we want to include cout inside functions
    }
    receiver.setHealth(remainingHealth);
    cout << name << " dealt " << dmgDealt << " dmg to " << receiver.getName() << endl;
}


