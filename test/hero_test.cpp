#include "gtest/gtest.h"
#include "hero.h"
#include "enemy.h"
#include <iostream>


TEST(ConstructorDefault, works) {
    EXPECT_NO_THROW(hero h);
    EXPECT_NO_THROW(cowboy c);
    EXPECT_NO_THROW(scientist s);
    EXPECT_NO_THROW(archer a);
}

TEST(ConstructorParameterized, invalid) {
    EXPECT_THROW(hero h("", -1, -1, -1, -1, -1, -1, -1, -1), std::invalid_argument);
}

TEST(ConstructorParameterized, valid) {
    EXPECT_NO_THROW(hero h("Hero", 100, 100, 10, 1, 0, 10, 0, 1));
}



TEST(Getter, potion) {
    hero h("Hero", 100, 100, 10, 1, 0, 10, 0, 1);
    EXPECT_EQ(h.getPotion(), 1);
}

TEST(Getter, currency) {
    hero h("Hero", 100, 100, 10, 1, 0, 10, 0, 1);
    EXPECT_EQ(h.getCurrency(), 0);
}

TEST(Setter, potion) {
    hero h("Hero", 100, 100, 10, 1, 0, 10, 0, 1);
    h.setPotion(5);
    EXPECT_EQ(h.getPotion(), 5);
}

TEST(Setter, currency) {
    hero h("Hero", 100, 100, 10, 1, 0, 10, 0, 1);
    h.setCurrency(100);
    EXPECT_EQ(h.getCurrency(), 100);
}

TEST(Setter, invalidPotion) {
    hero h("Hero", 100, 100, 10, 1, 0, 10, 0, 1);
    EXPECT_THROW(h.setPotion(-1), std::invalid_argument);
}

TEST(Setter, invalidCurrency) {
    hero h("Hero", 100, 100, 10, 1, 0, 10, 0, 1);
    EXPECT_THROW(h.setCurrency(-1), std::invalid_argument);
}



TEST(Rest, heroDamagedHealthRest) {
    hero h("Hero", 70, 100, 10, 1, 0, 10, 0, 1);
    h.rest();
    EXPECT_EQ(h.getHealth(), 100);
}

TEST(Rest, heroFullHealthRest) {
    hero h("Hero", 100, 100, 10, 1, 0, 10, 0, 1);
    h.rest();
    EXPECT_EQ(h.getHealth(), 100);
}




TEST(expIncrease, hero) {
    hero h("Hero", 100, 100, 10, 1, 0, 10, 0, 1);
    enemy e("lizard");
    h.expIncrease(e);
    EXPECT_EQ(h.getExp(), e.getExpDrop());
}

TEST(currencyIncrease, hero) {
    hero h("Hero", 100, 100, 10, 1, 0, 10, 0, 1);
    enemy e("bandit");
    h.currencyIncrease(e);
    EXPECT_EQ(h.getCurrency(), 1);
}

TEST(Ability, cowboy) {
    cowboy c;
    enemy e("scorpion");
    c.ability(e);
    EXPECT_TRUE(c.getAbilityUsed());
    EXPECT_TRUE(e.getStun());
}

TEST(Ability, scientist) {
    scientist s;
    enemy e("lizard");
    s.ability(e);
    EXPECT_TRUE(s.getAbilityUsed());
    EXPECT_TRUE(e.getStun());
}

TEST(Ability, archer) {
    archer a;
    enemy e("bandit");
    a.ability(e);
    EXPECT_TRUE(a.getAbilityUsed());
    EXPECT_TRUE(e.getStun());
}