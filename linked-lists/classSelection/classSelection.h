#ifndef CLASSSELECTION_H
#define CLASSSELECTION_H

#include "../screen.h"
#include "../characterFiles/hero.h"

// global hero pointer — accessible everywhere like screens[]
extern hero* currentHero;

enum class HeroClass { NONE, COWBOY, SCIENTIST, ARCHER };

class ClassSelectionScreen : public Screen {
public:
    ClassSelectionScreen() : Screen("classSelect") {}
    void display() override;
    void choice() override;

};

#endif