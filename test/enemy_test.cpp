#include "gtest/gtest.h"
#include "character.h"
#include "enemy.h"
#include "hero.h"
#include <iostream>

using namespace std;

TEST(Constructor_ability_no_Param,works){
   ASSERT_NO_THROW(ability aAbility);
}

TEST(Constructor_ability_no_Param,correctVals){
   ability aAbility;
   EXPECT_EQ(aAbility.getAbilityName(), "none");
}

TEST(Constructor_ability_Param,works){
   ASSERT_NO_THROW(ability aAbility("hi"));
}

TEST(Constructor_ability_Param,correctVals){
   ability aAbility("bite");
   EXPECT_EQ(aAbility.getAbilityName(), "bite");
}

TEST(Constructor_ability_Param,correctVals_2){
   ability aAbility("fang");
   EXPECT_EQ(aAbility.getAbilityName(), "fang");
}

// TEST(use,works)   { //can add more unit test but need to seed
//    hero target;
//    enemy user;
//    ability hit;
//    ASSERT_NO_THROW(hit.use(user,target));
// }

TEST(randDmg,works)   {//can add more unit test but need to seed
   ability hit;
   hero ahero;
   ASSERT_NO_THROW(hit.randDmg(ahero));
}


TEST(Constructor_enemy_no_Param,works){
   ASSERT_NO_THROW(enemy());
}

TEST(Constructor_enemy_no_Param,valid){
   enemy aEnemy;
   EXPECT_EQ(aEnemy.getExpDrop(),1);
}

TEST(Constructor_enemy_no_Param,valid_2){
   enemy aEnemy;
   EXPECT_EQ(aEnemy.getCurrencyDrop(),1);
}

TEST(Constructor_enemy_Param,works){ // need hero to be implemeted
   hero antagonist;
   ASSERT_NO_THROW(enemy(antagonist));
}

TEST(getCurrencyDrop,works){//should i add setters?
   enemy target;
   ASSERT_NO_THROW(target.getCurrencyDrop());
}

TEST(addAbility,works){//should i add allow to access vector?
   enemy target;
   ability A1;
   ASSERT_NO_THROW(target.addAbility(A1));
}

TEST(takeTurn,works){ // need seed to implement
   enemy target;
   hero ahero;
   ASSERT_NO_THROW(target.takeTurn(ahero));
}

TEST(Constructor_scorpion,works){;
   ASSERT_NO_THROW(scorpion aScorpion);
}

TEST(Constructor_scorpion,valid){;
   scorpion aScorpion;
   EXPECT_EQ(aScorpion.getHealth(),100);
}

TEST(Constructor_scorpion,valid_2){;
   scorpion aScorpion;
   EXPECT_EQ(aScorpion.getExp(),0);
}

TEST(Constructor_bandit,works){;
   ASSERT_NO_THROW(bandit aBandit);
}

TEST(Constructor_bandit,valid){;
   bandit aBandit;
   EXPECT_EQ(aBandit.getHealth(),100);
}

TEST(Constructor_bandit,valid_2){;
   bandit aBandit;
   EXPECT_EQ(aBandit.getExp(),0);
}

TEST(Constructor_lizard,works){;
   ASSERT_NO_THROW(lizard aLizard); 
}

TEST(Constructor_lizard_Param,valid){;
   lizard aLizard;
   EXPECT_EQ(aLizard.getHealth(),100);
}

TEST(Constructor_lizard_Param,valid_2){;
   lizard aLizard;
   EXPECT_EQ(aLizard.getExp(),0);
}

TEST(Constructor_finalBoss_Param,works){;
   ASSERT_NO_THROW(finalBoss aFinalBoss);
}

TEST(Constructor_finalBoss_Param,valid){;
   finalBoss aFinalBoss;
   EXPECT_EQ(aFinalBoss.getHealth(),100);
}

TEST(Constructor_finalBoss_Param,valid_2){;
   finalBoss aFinalBoss;
   EXPECT_EQ(aFinalBoss.getExp(),0);
}