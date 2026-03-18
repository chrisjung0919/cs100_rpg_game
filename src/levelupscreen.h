#pragma once

// LevelUpScreen (UML attrs: newLevel, hpIncrease, atkIncrease, defIncrease)
// Methods: display(), applyStatIncreases(), continueGame()
void runLevelUpScreen(int newLevel,
                      int oldHp,  int hpIncrease,
                      int oldAtk, int atkIncrease,
                      int oldDef, int defIncrease);
