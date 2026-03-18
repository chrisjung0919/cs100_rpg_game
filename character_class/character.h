#ifndef character_h
#define character_h
#include <iostream>
#include <cstdlib>


using std::string;
using std::cout;
using std::endl;
using std::invalid_argument;


class character {
    string name;
    int    health;
    int    maxHealth;
    int    dmg;
    int    lvl;
    int    exp;
    int    expCap;

public:
//constructor
character();
character(const string& name);
character(const string& ,int ,int,int ,int ,int,int);

//getter
string  getName      () const;
int     getHealth    () const;
int     getMaxHealth () const;
int     getDMG       () const;
int     getLvl       () const;
int     getExp       () const;
int     getExpCap    () const;

//setter
void setName       (const string&);
void setHealth     (int);
void setMaxHealth  (int);
void setDMG        (int);
void setLvl        (int);
void setExp        (int);
void setExpCap     (int);

//extra funcitons
bool isAlive() const;
virtual void attack (int , character &); //need function to end battle
};

#endif