#include "gtest/gtest.h"
#include "character.h"
#include <iostream>

using namespace std;

TEST(Constructor_noParam, works){
   ASSERT_NO_THROW(character aCharacter);
}

TEST(Constructor_noParam, correctVals){
   character aCharacter;
   EXPECT_EQ(aCharacter.getName(), "none");
}

TEST(Constructor_noParam, correctVals_2){
   character aCharacter;
   EXPECT_EQ(aCharacter.getHealth(), 100);
}

TEST(Constructor_Param, works){
   ASSERT_NO_THROW(character aCharacter("hi", 1,1,1,1,1,1));
}

TEST(Constructor_Param, validVals){
    character aCharacter("bye", 1,2,3,4,5,6);
    EXPECT_EQ(aCharacter.getLvl(),4);
}

TEST(Constructor_Param, invalidVals){
   EXPECT_THROW(character aCharacter("sigh", -1,-1,-1,-1,-1,-1),invalid_argument);
}

TEST(getter_works, name){
   character aCharacter;
   ASSERT_NO_THROW(aCharacter.getName());
}

TEST(getter_works, health){
   character aCharacter;
   ASSERT_NO_THROW(aCharacter.getHealth());
}

TEST(getter_works, maxHealth){
   character aCharacter;
   ASSERT_NO_THROW(aCharacter.getMaxHealth());
}
TEST(getter_works, dmg){
   character aCharacter;
   ASSERT_NO_THROW(aCharacter.getDMG());
}

TEST(getter_works, lvl){
   character aCharacter;
   ASSERT_NO_THROW(aCharacter.getLvl());
}

TEST(getter_works, exp){
   character aCharacter;
   ASSERT_NO_THROW(aCharacter.getExp());
}

TEST(getter_works, expCap){
   character aCharacter;
   ASSERT_NO_THROW(aCharacter.getExpCap());
}

TEST(getter_valid, name){
   character aCharacter("bye", 1,2,3,4,5,6);
   EXPECT_EQ(aCharacter.getName(),"bye");
}

TEST(getter_valid, health){
   character aCharacter("bye", 1,2,3,4,5,6);
   EXPECT_EQ(aCharacter.getHealth(),1);
}

TEST(getter_valid, maxHealth){
   character aCharacter("bye", 1,2,3,4,5,6);
   EXPECT_EQ(aCharacter.getMaxHealth(),2);
}

TEST(getter_valid, dmg){
   character aCharacter("bye", 1,2,3,4,5,6);
   EXPECT_EQ(aCharacter.getDMG(),3);
}

TEST(getter_valid, lvl){
   character aCharacter("bye", 1,2,3,4,5,6);
   EXPECT_EQ(aCharacter.getLvl(),4);
}

TEST(getter_valid, exp){
   character aCharacter("bye", 1,2,3,4,5,6);
   EXPECT_EQ(aCharacter.getExp(),5);
}

TEST(getter_valid, expCap){
   character aCharacter("bye", 1,2,3,4,5,6);
   EXPECT_EQ(aCharacter.getExpCap(),6);
}



TEST(getter_valid_2, name){
   character aCharacter("hello", 10,20,30,40,50,60);
   EXPECT_EQ(aCharacter.getName(),"hello");
}

TEST(getter_valid_2, health){
   character aCharacter("hello", 10,20,30,40,50,60);
   ASSERT_EQ(aCharacter.getHealth(),10);
}

TEST(getter_valid_2, max_health){
   character aCharacter("hello", 10,20,30,40,50,60);
   ASSERT_EQ(aCharacter.getMaxHealth(),20);
}

TEST(getter_valid_2, dmg){
   character aCharacter("hello", 10,20,30,40,50,60);
   ASSERT_EQ(aCharacter.getDMG(),30);
}

TEST(getter_valid_2, lvl){
   character aCharacter("hello", 10,20,30,40,50,60);
   ASSERT_EQ(aCharacter.getLvl(),40);
}

TEST(getter_valid_2, exp){
   character aCharacter("hello", 10,20,30,40,50,60);
   ASSERT_EQ(aCharacter.getExp(),50);
}

TEST(getter_valid_2, exp_cap){
   character aCharacter("hello", 10,20,30,40,50,60);
   ASSERT_EQ(aCharacter.getExpCap(),60);
}

TEST(setter_works, name){
   character aCharacter;
   ASSERT_NO_THROW(aCharacter.setName("hi"));
}

TEST(setter_works, health){
   character aCharacter;
   ASSERT_NO_THROW(aCharacter.setHealth(1));
}

TEST(setter_works, maxHealth){
   character aCharacter;
   ASSERT_NO_THROW(aCharacter.setMaxHealth(2));
}

TEST(setter_works, dmg){
   character aCharacter;
   ASSERT_NO_THROW(aCharacter.setDMG(3));
}


TEST(setter_works, lvl){
   character aCharacter;
   ASSERT_NO_THROW(aCharacter.setLvl(4));
}

TEST(setter_works, exp){
   character aCharacter;
   ASSERT_NO_THROW(aCharacter.setExp(5));
}

TEST(setter_works, expCap){
   character aCharacter;
   ASSERT_NO_THROW(aCharacter.setExpCap(6));
}


TEST(setter_valid, name){
   character aCharacter;
   aCharacter.setName("huh");
   EXPECT_EQ(aCharacter.getName(),"huh");
}

TEST(setter_valid, health){
   character aCharacter;
   aCharacter.setHealth(3);
   EXPECT_EQ(aCharacter.getHealth(),3);
}

TEST(setter_valid, maxHealth){
   character aCharacter;
   aCharacter.setMaxHealth(4);
   EXPECT_EQ(aCharacter.getMaxHealth(),4);
}

TEST(setter_valid, dmg){
   character aCharacter;
   aCharacter.setDMG(5);
   EXPECT_EQ(aCharacter.getDMG(),5);
}

TEST(setter_valid, lvl){
   character aCharacter;
   aCharacter.setLvl(6);
   EXPECT_EQ(aCharacter.getLvl(),6);
}

TEST(setter_valid, exp){
   character aCharacter;
   aCharacter.setExp(7);
   EXPECT_EQ(aCharacter.getExp(),7);
}

TEST(setter_valid, expCap){
   character aCharacter;
   aCharacter.setExpCap(8);
   EXPECT_EQ(aCharacter.getExpCap(),8);
}

TEST(setter_invalid, name){
   character aCharacter;
   EXPECT_THROW(aCharacter.setName(""),invalid_argument);
}

TEST(setter_invalid, health){
   character aCharacter;
   EXPECT_THROW(aCharacter.setHealth(-1),invalid_argument);
}

TEST(setter_invalid, maxHealth){
   character aCharacter;
   EXPECT_THROW(aCharacter.setMaxHealth(-1),invalid_argument);
}

TEST(setter_invalid, dmg){
   character aCharacter;
   EXPECT_THROW(aCharacter.setDMG(-1),invalid_argument);
}

TEST(setter_invalid, lvl){
   character aCharacter;
   EXPECT_THROW(aCharacter.setLvl(-1),invalid_argument);
}

TEST(setter_invalid, exp){
   character aCharacter;
   EXPECT_THROW(aCharacter.setExp(-1),invalid_argument);
}

TEST(setter_invalid, expCap){
   character aCharacter;
   EXPECT_THROW(aCharacter.setExpCap(-1),invalid_argument);
}

TEST(isAlive, work){
   character attacker;
   ASSERT_NO_THROW(attacker.isAlive());
}

TEST(isAlive, valid){
   character attacker;
   character reciever;
   attacker.attack(101,reciever);
EXPECT_EQ(reciever.isAlive(),0);
}

TEST(isAlive, valid_2){
   character attacker("bye", 10,20,30,40,50,60);
   character reciever("hello", 1,2,3,4,5,6);
   attacker.attack(30,reciever);
EXPECT_EQ(reciever.isAlive(),0);
}

TEST(attack, work){
   character attacker;
   character reciever;
   ASSERT_NO_THROW(attacker.attack(1,reciever));
}

TEST(attack, invalid){
   character attacker;
   character reciever;
   EXPECT_THROW(attacker.attack(-1,reciever),invalid_argument);
}

TEST(attack, accurate){
   character attacker;
   character reciever;
   attacker.attack(1,reciever);
   EXPECT_EQ(reciever.getHealth(),99);
}

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}